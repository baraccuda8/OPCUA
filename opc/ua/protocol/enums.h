// DO NOT EDIT THIS FILE!
// It is automatically generated from opcfoundation.org schemas.
//

/// @brief Opc Ua Binary.
/// @license GNU LGPL
///
/// Distributed under the GNU LGPL License
/// (See accompanying file LICENSE or copy at
/// http://www.gnu.org/licenses/lgpl.html)
///

#pragma once

#include <cstdint>
#include <vector>
#include <string>

#include <opc/ua/protocol/status_codes.h>

namespace OpcUa
{
	struct DiagnosticInfo;

	enum class OpenFileMode : uint32_t
	{
		Read = 1,
		Write = 2,
		EraseExisiting = 4,
		Append = 8,
	};
	inline OpenFileMode operator|(OpenFileMode a, OpenFileMode b) { return static_cast<OpenFileMode>(static_cast<uint32_t>(a) | static_cast<uint32_t>(b)); }
	inline OpenFileMode operator&(OpenFileMode a, OpenFileMode b) { return static_cast<OpenFileMode>(static_cast<uint32_t>(a) & static_cast<uint32_t>(b)); }


	// A mask specifying the class of the node.
	enum class NodeClass : uint32_t
	{
		Unspecified = 0,
		Object = 1,
		Variable = 2,
		Method = 4,
		ObjectType = 8,
		VariableType = 16,
		ReferenceType = 32,
		DataType = 64,
		View = 128,
	};
	inline NodeClass operator|(NodeClass a, NodeClass b) { return static_cast<NodeClass>(static_cast<uint32_t>(a) | static_cast<uint32_t>(b)); }
	inline NodeClass operator&(NodeClass a, NodeClass b) { return static_cast<NodeClass>(static_cast<uint32_t>(a) & static_cast<uint32_t>(b)); }


	// The types of applications.
	enum class ApplicationType : uint32_t
	{
		Server = 0,
		Client = 1,
		ClientAndServer = 2,
		DiscoveryServer = 3,
	};
	inline ApplicationType operator|(ApplicationType a, ApplicationType b) { return static_cast<ApplicationType>(static_cast<uint32_t>(a) | static_cast<uint32_t>(b)); }
	inline ApplicationType operator&(ApplicationType a, ApplicationType b) { return static_cast<ApplicationType>(static_cast<uint32_t>(a) & static_cast<uint32_t>(b)); }


	// The type of security to use on a message.
	enum class MessageSecurityMode : uint32_t
	{
		Invalid = 0,
		None = 1,
		Sign = 2,
		SignAndEncrypt = 3,
	};
	inline MessageSecurityMode operator|(MessageSecurityMode a, MessageSecurityMode b) { return static_cast<MessageSecurityMode>(static_cast<uint32_t>(a) | static_cast<uint32_t>(b)); }
	inline MessageSecurityMode operator&(MessageSecurityMode a, MessageSecurityMode b) { return static_cast<MessageSecurityMode>(static_cast<uint32_t>(a) & static_cast<uint32_t>(b)); }


	// The possible user token types.
	enum class UserTokenType : uint32_t
	{
		Anonymous = 0,
		UserName = 1,
		Certificate = 2,
		IssuedToken = 3,
	};
	inline UserTokenType operator|(UserTokenType a, UserTokenType b) { return static_cast<UserTokenType>(static_cast<uint32_t>(a) | static_cast<uint32_t>(b)); }
	inline UserTokenType operator&(UserTokenType a, UserTokenType b) { return static_cast<UserTokenType>(static_cast<uint32_t>(a) & static_cast<uint32_t>(b)); }


	// Indicates whether a token if being created or renewed.
	enum class SecurityTokenRequestType : uint32_t
	{
		Issue = 0,
		Renew = 1,
	};
	inline SecurityTokenRequestType operator|(SecurityTokenRequestType a, SecurityTokenRequestType b) { return static_cast<SecurityTokenRequestType>(static_cast<uint32_t>(a) | static_cast<uint32_t>(b)); }
	inline SecurityTokenRequestType operator&(SecurityTokenRequestType a, SecurityTokenRequestType b) { return static_cast<SecurityTokenRequestType>(static_cast<uint32_t>(a) & static_cast<uint32_t>(b)); }


	// The bits used to specify default attributes for a new node.
	enum class NodeAttributesMask : uint32_t
	{
		None = 0,
		AccessLevel = 1,
		ArrayDimensions = 2,
		BrowseName = 4,
		ContainsNoLoops = 8,
		DataType = 16,
		Description = 32,
		DisplayName = 64,
		EventNotifier = 128,
		Executable = 256,
		Historizing = 512,
		InverseName = 1024,
		IsAbstract = 2048,
		MinimumSamplingInterval = 4096,
		NodeClass = 8192,
		NodeId = 16384,
		Symmetric = 32768,
		UserAccessLevel = 65536,
		UserExecutable = 131072,
		UserWriteMask = 262144,
		ValueRank = 524288,
		WriteMask = 1048576,
		Value = 2097152,
		All = 4194303,
		BaseNode = 1335396,
		Object = 1335524,
		ObjectTypeOrDataType = 1337444,
		Variable = 4026999,
		VariableType = 3958902,
		Method = 1466724,
		ReferenceType = 1371236,
		View = 1335532,
	};
	inline NodeAttributesMask operator|(NodeAttributesMask a, NodeAttributesMask b) { return static_cast<NodeAttributesMask>(static_cast<uint32_t>(a) | static_cast<uint32_t>(b)); }
	inline NodeAttributesMask operator&(NodeAttributesMask a, NodeAttributesMask b) { return static_cast<NodeAttributesMask>(static_cast<uint32_t>(a) & static_cast<uint32_t>(b)); }


	// Define bits used to indicate which attributes are writeable.
	enum class AttributeWriteMask : uint32_t
	{
		None = 0,
		AccessLevel = 1,
		ArrayDimensions = 2,
		BrowseName = 4,
		ContainsNoLoops = 8,
		DataType = 16,
		Description = 32,
		DisplayName = 64,
		EventNotifier = 128,
		Executable = 256,
		Historizing = 512,
		InverseName = 1024,
		IsAbstract = 2048,
		MinimumSamplingInterval = 4096,
		NodeClass = 8192,
		NodeId = 16384,
		Symmetric = 32768,
		UserAccessLevel = 65536,
		UserExecutable = 131072,
		UserWriteMask = 262144,
		ValueRank = 524288,
		WriteMask = 1048576,
		ValueForVariableType = 2097152,
	};
	inline AttributeWriteMask operator|(AttributeWriteMask a, AttributeWriteMask b) { return static_cast<AttributeWriteMask>(static_cast<uint32_t>(a) | static_cast<uint32_t>(b)); }
	inline AttributeWriteMask operator&(AttributeWriteMask a, AttributeWriteMask b) { return static_cast<AttributeWriteMask>(static_cast<uint32_t>(a) & static_cast<uint32_t>(b)); }


	// The directions of the references to return.
	enum class BrowseDirection : uint32_t
	{
		Forward = 0,
		Inverse = 1,
		Both = 2,
	};
	inline BrowseDirection operator|(BrowseDirection a, BrowseDirection b) { return static_cast<BrowseDirection>(static_cast<uint32_t>(a) | static_cast<uint32_t>(b)); }
	inline BrowseDirection operator&(BrowseDirection a, BrowseDirection b) { return static_cast<BrowseDirection>(static_cast<uint32_t>(a) & static_cast<uint32_t>(b)); }


	// A bit mask which specifies what should be returned in a browse response.
	enum class BrowseResultMask : uint32_t
	{
		None = 0,
		ReferenceTypeId = 1,
		IsForward = 2,
		NodeClass = 4,
		BrowseName = 8,
		DisplayName = 16,
		TypeDefinition = 32,
		All = 63,
		ReferenceTypeInfo = 3,
		TargetInfo = 60,
	};
	inline BrowseResultMask operator|(BrowseResultMask a, BrowseResultMask b) { return static_cast<BrowseResultMask>(static_cast<uint32_t>(a) | static_cast<uint32_t>(b)); }
	inline BrowseResultMask operator&(BrowseResultMask a, BrowseResultMask b) { return static_cast<BrowseResultMask>(static_cast<uint32_t>(a) & static_cast<uint32_t>(b)); }


	enum class ComplianceLevel : uint32_t
	{
		Untested = 0,
		Partial = 1,
		SelfTested = 2,
		Certified = 3,
	};
	inline ComplianceLevel operator|(ComplianceLevel a, ComplianceLevel b) { return static_cast<ComplianceLevel>(static_cast<uint32_t>(a) | static_cast<uint32_t>(b)); }
	inline ComplianceLevel operator&(ComplianceLevel a, ComplianceLevel b) { return static_cast<ComplianceLevel>(static_cast<uint32_t>(a) & static_cast<uint32_t>(b)); }


	enum class FilterOperator : uint32_t
	{
		Equals = 0,
		IsNull = 1,
		GreaterThan = 2,
		LessThan = 3,
		GreaterThanOrEqual = 4,
		LessThanOrEqual = 5,
		Like = 6,
		Not = 7,
		Between = 8,
		InList = 9,
		And = 10,
		Or = 11,
		Cast = 12,
		InView = 13,
		OfType = 14,
		RelatedTo = 15,
		BitwiseAnd = 16,
		BitwiseOr = 17,
	};
	inline FilterOperator operator|(FilterOperator a, FilterOperator b) { return static_cast<FilterOperator>(static_cast<uint32_t>(a) | static_cast<uint32_t>(b)); }
	inline FilterOperator operator&(FilterOperator a, FilterOperator b) { return static_cast<FilterOperator>(static_cast<uint32_t>(a) & static_cast<uint32_t>(b)); }


	enum class TimestampsToReturn : uint32_t
	{
		Source = 0,
		Server = 1,
		Both = 2,
		Neither = 3,
	};
	inline TimestampsToReturn operator|(TimestampsToReturn a, TimestampsToReturn b) { return static_cast<TimestampsToReturn>(static_cast<uint32_t>(a) | static_cast<uint32_t>(b)); }
	inline TimestampsToReturn operator&(TimestampsToReturn a, TimestampsToReturn b) { return static_cast<TimestampsToReturn>(static_cast<uint32_t>(a) & static_cast<uint32_t>(b)); }


	enum class HistoryUpdateType : uint32_t
	{
		Insert = 1,
		Replace = 2,
		Update = 3,
		Delete = 4,
	};
	inline HistoryUpdateType operator|(HistoryUpdateType a, HistoryUpdateType b) { return static_cast<HistoryUpdateType>(static_cast<uint32_t>(a) | static_cast<uint32_t>(b)); }
	inline HistoryUpdateType operator&(HistoryUpdateType a, HistoryUpdateType b) { return static_cast<HistoryUpdateType>(static_cast<uint32_t>(a) & static_cast<uint32_t>(b)); }


	enum class PerformUpdateType : uint32_t
	{
		Insert = 1,
		Replace = 2,
		Update = 3,
		Remove = 4,
	};
	inline PerformUpdateType operator|(PerformUpdateType a, PerformUpdateType b) { return static_cast<PerformUpdateType>(static_cast<uint32_t>(a) | static_cast<uint32_t>(b)); }
	inline PerformUpdateType operator&(PerformUpdateType a, PerformUpdateType b) { return static_cast<PerformUpdateType>(static_cast<uint32_t>(a) & static_cast<uint32_t>(b)); }


	enum class MonitoringMode : uint32_t
	{
		Disabled = 0,
		Sampling = 1,
		Reporting = 2,
	};
	inline MonitoringMode operator|(MonitoringMode a, MonitoringMode b) { return static_cast<MonitoringMode>(static_cast<uint32_t>(a) | static_cast<uint32_t>(b)); }
	inline MonitoringMode operator&(MonitoringMode a, MonitoringMode b) { return static_cast<MonitoringMode>(static_cast<uint32_t>(a) & static_cast<uint32_t>(b)); }


	enum class DataChangeTrigger : uint32_t
	{
		Status = 0,
		StatusValue = 1,
		StatusValueTimestamp = 2,
	};
	inline DataChangeTrigger operator|(DataChangeTrigger a, DataChangeTrigger b) { return static_cast<DataChangeTrigger>(static_cast<uint32_t>(a) | static_cast<uint32_t>(b)); }
	inline DataChangeTrigger operator&(DataChangeTrigger a, DataChangeTrigger b) { return static_cast<DataChangeTrigger>(static_cast<uint32_t>(a) & static_cast<uint32_t>(b)); }


	enum class DeadbandType : uint32_t
	{
		None = 0,
		Absolute = 1,
		Percent = 2,
	};
	inline DeadbandType operator|(DeadbandType a, DeadbandType b) { return static_cast<DeadbandType>(static_cast<uint32_t>(a) | static_cast<uint32_t>(b)); }
	inline DeadbandType operator&(DeadbandType a, DeadbandType b) { return static_cast<DeadbandType>(static_cast<uint32_t>(a) & static_cast<uint32_t>(b)); }


	// A simple enumerated type used for testing.
	enum class EnumeratedTestType : uint32_t
	{
		Red = 1,
		Yellow = 4,
		Green = 5,
	};
	inline EnumeratedTestType operator|(EnumeratedTestType a, EnumeratedTestType b) { return static_cast<EnumeratedTestType>(static_cast<uint32_t>(a) | static_cast<uint32_t>(b)); }
	inline EnumeratedTestType operator&(EnumeratedTestType a, EnumeratedTestType b) { return static_cast<EnumeratedTestType>(static_cast<uint32_t>(a) & static_cast<uint32_t>(b)); }


	enum class RedundancySupport : uint32_t
	{
		None = 0,
		Cold = 1,
		Warm = 2,
		Hot = 3,
		Transparent = 4,
		HotAndMirrored = 5,
	};
	inline RedundancySupport operator|(RedundancySupport a, RedundancySupport b) { return static_cast<RedundancySupport>(static_cast<uint32_t>(a) | static_cast<uint32_t>(b)); }
	inline RedundancySupport operator&(RedundancySupport a, RedundancySupport b) { return static_cast<RedundancySupport>(static_cast<uint32_t>(a) & static_cast<uint32_t>(b)); }


	enum class ServerState : uint32_t
	{
		Running = 0,
		Failed = 1,
		NoConfiguration = 2,
		Suspended = 3,
		Shutdown = 4,
		Test = 5,
		CommunicationFault = 6,
		Unknown = 7,
	};
	inline ServerState operator|(ServerState a, ServerState b) { return static_cast<ServerState>(static_cast<uint32_t>(a) | static_cast<uint32_t>(b)); }
	inline ServerState operator&(ServerState a, ServerState b) { return static_cast<ServerState>(static_cast<uint32_t>(a) & static_cast<uint32_t>(b)); }


	enum class ModelChangeStructureVerbMask : uint32_t
	{
		NodeAdded = 1,
		NodeDeleted = 2,
		ReferenceAdded = 4,
		ReferenceDeleted = 8,
		DataTypeChanged = 16,
	};
	inline ModelChangeStructureVerbMask operator|(ModelChangeStructureVerbMask a, ModelChangeStructureVerbMask b) { return static_cast<ModelChangeStructureVerbMask>(static_cast<uint32_t>(a) | static_cast<uint32_t>(b)); }
	inline ModelChangeStructureVerbMask operator&(ModelChangeStructureVerbMask a, ModelChangeStructureVerbMask b) { return static_cast<ModelChangeStructureVerbMask>(static_cast<uint32_t>(a) & static_cast<uint32_t>(b)); }


	enum class AxisScaleEnumeration : uint32_t
	{
		Linear = 0,
		Log = 1,
		Ln = 2,
	};
	inline AxisScaleEnumeration operator|(AxisScaleEnumeration a, AxisScaleEnumeration b) { return static_cast<AxisScaleEnumeration>(static_cast<uint32_t>(a) | static_cast<uint32_t>(b)); }
	inline AxisScaleEnumeration operator&(AxisScaleEnumeration a, AxisScaleEnumeration b) { return static_cast<AxisScaleEnumeration>(static_cast<uint32_t>(a) & static_cast<uint32_t>(b)); }


	enum class ExceptionDeviationFormat : uint32_t
	{
		AbsoluteValue = 0,
		PercentOfRange = 1,
		PercentOfValue = 2,
		PercentOfEURange = 3,
		Unknown = 4,
	};
	inline ExceptionDeviationFormat operator|(ExceptionDeviationFormat a, ExceptionDeviationFormat b) { return static_cast<ExceptionDeviationFormat>(static_cast<uint32_t>(a) | static_cast<uint32_t>(b)); }
	inline ExceptionDeviationFormat operator&(ExceptionDeviationFormat a, ExceptionDeviationFormat b) { return static_cast<ExceptionDeviationFormat>(static_cast<uint32_t>(a) & static_cast<uint32_t>(b)); }

} // namespace

