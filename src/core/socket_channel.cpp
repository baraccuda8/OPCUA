/// @author Alexander Rykovanov 2012
/// @email rykovanov.as@gmail.com
/// @brief Opc binary cnnection channel.
/// @license GNU LGPL
///
/// Distributed under the GNU LGPL License
/// (See accompanying file LICENSE or copy at
/// http://www.gnu.org/licenses/lgpl.html)
///

#include <opc/ua/socket_channel.h>
#include <opc/ua/errors.h>


#include <errno.h>
#include <iostream>

#include <stdexcept>
#include <string.h>

#include <sys/types.h>


#ifdef _WIN32
#include <WinSock2.h>
#else
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <unistd.h>
#endif

#define __FUN(__s) \
		std::string( \
			std::string(__s) + \
			std::string(" (") + \
			std::string(__FILE__) + \
			std::string(" : ") + \
			std::string(__FUNCTION__) + \
			std::string(" Line: ") + \
			std::to_string(__LINE__) + \
			std::string(")")\
		)\
	.c_str()


OpcUa::SocketChannel::SocketChannel(int sock)
    : Socket(sock)
{
    int flag = 1;
    setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, (char*)&flag, sizeof(int));

    if (Socket < 0)
    {
        //THROW_ERROR(CannotCreateChannelOnInvalidSocket);
        throw std::exception(__FUN(std::string(CannotCreateChannelOnInvalidSocket.ErrorMessage)));
    }
}

OpcUa::SocketChannel::~SocketChannel()
{
    Stop();
}

void OpcUa::SocketChannel::Stop()
{
#ifdef _WIN32
    closesocket(Socket);
#else
    close(Socket);
#endif
}

std::size_t OpcUa::SocketChannel::Receive(char* data, std::size_t size)
{
    int received = recv(Socket, data, (int)size, MSG_WAITALL);

    if (received < 0)
    {
        //(throw ::Common::CreateError(66, "D:\\OPCUA\\src\\core\\socket_channel.cpp", (*_errno()), "%1% %2%.", "Failed to receive data from host.", ));
        throw std::exception(__FUN(std::string("Failed to receive data from host. ") + strerror(*_errno())));
        //return (std::size_t)received;
    }

    if (received == 0)
    {
        //THROW_OS_ERROR("Connection was closed by host.");
        throw std::exception(__FUN(std::string("Connection was closed by host. ") + strerror(*_errno())));
        //return (std::size_t)received;
    }

    return (std::size_t)size;
}

void OpcUa::SocketChannel::Send(const char* message, std::size_t size)
{
    int sent = send(Socket, message, (int)size, 0);

    if (sent != (int)size)
    {
        //THROW_OS_ERROR("unable to send data to the host. ");
        //throw std::exception(__FUN(std::string("Unable to send data to the host. ") + strerror(*_errno())));
    }
}
