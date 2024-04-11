/// @author Alexander Rykovanov 2013
/// @email rykovanov.as@gmail.com
/// @brief Remote Computer implementaion.
/// @license GNU LGPL
///
/// Distributed under the GNU LGPL License
/// (See accompanying file LICENSE or copy at
/// http://www.gnu.org/licenses/lgpl.html)
///


#include <opc/ua/client/client.h>
#include <opc/ua/node.h>
#include <opc/ua/subscription.h>

#include <opc/common/logger.h>

#include <iostream>
#include <stdexcept>
#include <thread>
#include <string>



using namespace OpcUa;

class SubClient : public SubscriptionHandler
{
    void DataChange(uint32_t /*handle*/, const Node& node, const Variant& val, AttributeId /*attr*/) override
    {
        val.Type();
        std::cout << "Received DataChange event, value of Node " << node << " is now: " << val.ToString() << std::endl;
    }
};

#define Local 0
#if Local
#define HOST_OPC_UA "opc.tcp://11.11.0.16:4840/"
//#define HOST_OPC_UA "opc.tcp://10.168.2.10:4841/"
//#define HOST_OPC_UA "opc.tcp://localhost:4840/"
#else
#define HOST_OPC_UA "opc.tcp://85.116.124.32:4840/"
#endif


int main(int argc, char ** argv)
{
  auto logger = spdlog::stderr_color_mt("client");
  logger->set_level(spdlog::level::debug);
  logger->error("Error ReadInfo: {}", -1);
  return 0;


  try
    {
      //std::string endpoint = "opc.tcp://192.168.56.101:48030";
      //std::string endpoint = "opc.tcp://user:password@192.168.56.101:48030";
      std::string endpoint = HOST_OPC_UA;
      //std::string endpoint = "opc.tcp://localhost:53530/OPCUA/SimulationServer/";
      //std::string endpoint = "opc.tcp://localhost:48010";

      if (argc > 1)
        { endpoint = argv[1]; }

      logger->info("Connecting to: {}", endpoint);

      OpcUa::UaClient client(logger);
      client.Connect(endpoint);

      //get Root node on server
      OpcUa::Node root = client.GetRootNode();
      logger->info("Root node is: {}", root);

      //get and browse Objects node
      logger->info("Child of objects node are:");
      Node objects = client.GetObjectsNode();

      for (OpcUa::Node node : objects.GetChildren())
        { logger->info("    {}", node); }

      //get a node from standard namespace using objectId
      logger->info("NamespaceArray is:");
      OpcUa::Node nsnode = client.GetNode(ObjectId::Server_NamespaceArray);
      OpcUa::Variant ns = nsnode.GetValue();

      for (std::string d : ns.As<std::vector<std::string>>())
        { logger->info("    {}", d); }

      OpcUa::Node myvar;
      OpcUa::Node myobject;
      OpcUa::Node mymethod;

      //Initialize Node myvar:

      //Get namespace index we are interested in

#if 0
      // From freeOpcUa Server:
      uint32_t idx = client.GetNamespaceIndex("http://examples.freeopcua.github.io");
      ////Get Node using path (BrowsePathToNodeId call)
      //std::vector<std::string> varpath({ std::to_string(idx) + ":NewObject", "MyVariable" });
      //myvar = objects.GetChild(varpath);
      std::vector<std::string> methodpath({ std::to_string(idx) + ":NewObject" });
      myobject = objects.GetChild(methodpath);
      methodpath = { std::to_string(idx) + ":NewObject", "MyMethod" };
      mymethod = objects.GetChild(methodpath);
      std::vector<OpcUa::Variant> arguments;
      arguments.push_back(static_cast<uint8_t>(0));
      myobject.CallMethod(mymethod.GetId(), arguments);

      // Example data from Prosys server:
      //std::vector<std::string> varpath({"Objects", "5:Simulation", "5:Random1"});
      //myvar = root.GetChild(varpath);
#endif

      // Example from any UA server, standard dynamic variable node:
      NodeId nId = NodeId(ObjectId::Server_ServerStatus_CurrentTime);

      std::vector<std::string> varpath{ "Objects", "Server", "ServerStatus", "CurrentTime" };
      myvar = root.GetChild(varpath);

      logger->info("got node: {}", myvar);
      //NamespaceIndex = nId.IsString()
      nId.GetStringIdentifier();

      //Subscription
      SubClient sclt;
      Subscription::SharedPtr sub = client.CreateSubscription(100, sclt);

      Node node2;// = nid2;
      logger->info("Node: {}", node2);



      //Node node2;// = nid2;
      //__FUN__

      //id.GetStringIdentifier();

      uint32_t handle = sub->SubscribeDataChange(myvar);
      logger->info("Got sub handle: {}, sleeping 5 seconds", handle);
      std::this_thread::sleep_for(std::chrono::seconds(1));

      logger->info("Disconnecting");
      client.Disconnect();
      logger->flush();
      return 0;
    }

  catch (const std::exception & exc)
    {
      logger->error("Error: {}", exc.what());
    }

  catch (...)
    {
      logger->error("Unknown error.");
    }

  return -1;
}

