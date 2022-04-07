// This file is generated by ZCL Advanced Platform generator. Please don't edit manually.

// The following is brought in by the endianness component, which all
// applications must include
#include "sl_endianness.h"

#ifndef SILABS_AF_ENDPOINT_CONFIG
#define SILABS_AF_ENDPOINT_CONFIG 1

// Default values for the attributes longer than a pointer, in a form of a
// binary blob. All attribute values with size greater than 2 bytes. Excluding 0
// values and externally saved values. Separate block is generated for
// big-endian and little-endian cases.
#define GENERATED_DEFAULTS_COUNT (1)
#if BIGENDIAN_CPU
#define GENERATED_DEFAULTS { \
  6, '"', 'R', 'P', 'R', 'o', '"', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0,DEFAULT value for cluster: Basic, attribute: model identifier, side: server */ \
}
#else //!BIGENDIAN_CPU
#define GENERATED_DEFAULTS { \
  6, '"', 'R', 'P', 'R', 'o', '"', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0,DEFAULT value for cluster: Basic, attribute: model identifier, side: server */ \
}
#endif


// This is an array of EmberAfAttributeMinMaxValue structures.
#define GENERATED_MIN_MAX_DEFAULT_COUNT (0)
#define GENERATED_MIN_MAX_DEFAULTS { \
}

#define GENERATED_ATTRIBUTE_COUNT (9)
// This is an array of EmberAfAttributeMetadata structures.
#define GENERATED_ATTRIBUTES { \
  { 0x0000, ZCL_INT8U_ATTRIBUTE_TYPE, 1, (ATTRIBUTE_MASK_SINGLETON), { (uint8_t*)0x08  } }, /* 0 Cluster: Basic, Attribute: ZCL version, Side: server*/ \
	  { 0x0001, ZCL_INT8U_ATTRIBUTE_TYPE, 1, (0x00), { (uint8_t*)0x00  } }, /* 1 Cluster: Basic, Attribute: application version, Side: server*/ \
	  { 0x0005, ZCL_CHAR_STRING_ATTRIBUTE_TYPE, 33, (ATTRIBUTE_MASK_SINGLETON), { (uint8_t*)&(generatedDefaults[0]) } }, /* 2 Cluster: Basic, Attribute: model identifier, Side: server*/ \
  { 0x0007, ZCL_ENUM8_ATTRIBUTE_TYPE, 1, (ATTRIBUTE_MASK_SINGLETON), { (uint8_t*)0x00  } }, /* 3 Cluster: Basic, Attribute: power source, Side: server*/ \
	  { 0xFFFD, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (ATTRIBUTE_MASK_SINGLETON), { (uint8_t*)3  } }, /* 4 Cluster: Basic, Attribute: cluster revision, Side: server*/ \
	  { 0x0000, ZCL_ENUM16_ATTRIBUTE_TYPE, 2, (ATTRIBUTE_MASK_CLIENT| ATTRIBUTE_MASK_SINGLETON), { (uint8_t*)0x0000  } }, /* 5 Cluster: Key Establishment, Attribute: key establishment suite (client), Side: client*/ \
	  { 0xFFFD, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (ATTRIBUTE_MASK_CLIENT| ATTRIBUTE_MASK_SINGLETON), { (uint8_t*)2  } }, /* 6 Cluster: Key Establishment, Attribute: cluster revision, Side: client*/ \
	  { 0x0000, ZCL_ENUM16_ATTRIBUTE_TYPE, 2, (ATTRIBUTE_MASK_SINGLETON), { (uint8_t*)0x0000  } }, /* 7 Cluster: Key Establishment, Attribute: key establishment suite (server), Side: server*/ \
	  { 0xFFFD, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (ATTRIBUTE_MASK_SINGLETON), { (uint8_t*)2  } } /* 8 Cluster: Key Establishment, Attribute: cluster revision, Side: server*/ \
	}

#define GENERATED_CLUSTER_COUNT (3)
// This is an array of EmberAfCluster structures.
#define GENERATED_CLUSTERS { \
  { 0x0000, (EmberAfAttributeMetadata*)&(generatedAttributes[0]), 5, 38, CLUSTER_MASK_SERVER, NULL }, /* 0, Endpoint Id: 1, Cluster: Basic, Side: server*/ \
  { 0x0800, (EmberAfAttributeMetadata*)&(generatedAttributes[5]), 2, 4, CLUSTER_MASK_CLIENT, NULL }, /* 1, Endpoint Id: 1, Cluster: Key Establishment, Side: client*/ \
  { 0x0800, (EmberAfAttributeMetadata*)&(generatedAttributes[7]), 2, 4, CLUSTER_MASK_SERVER, NULL } /* 2, Endpoint Id: 1, Cluster: Key Establishment, Side: server*/ \
}

#define GENERATED_ENDPOINT_TYPE_COUNT (1)
// This is an array of EmberAfEndpointType structures.
#define GENERATED_ENDPOINT_TYPES { \
  { ((EmberAfCluster*)&(generatedClusters[0])), 3, 46 }, \
}

// Largest attribute size is needed for various buffers
#define ATTRIBUTE_LARGEST (33)

// Total size of singleton attributes
#define ATTRIBUTE_SINGLETONS_SIZE (45)

// Total size of attribute storage
#define ATTRIBUTE_MAX_SIZE (46)

// Number of fixed endpoints
#define FIXED_ENDPOINT_COUNT (1)

// Array of endpoints that are supported, the data inside the array is the
// endpoint number.
#define FIXED_ENDPOINT_ARRAY { \
  1 \
}

// Array of profile ids
#define FIXED_PROFILE_IDS { \
  265 \
}

// Array of device ids
#define FIXED_DEVICE_IDS { \
  8 \
}

// Array of device versions
#define FIXED_DEVICE_VERSIONS { \
  1 \
}

// Array of endpoint types supported on each endpoint
#define FIXED_ENDPOINT_TYPES { \
  0 \
}

// Array of networks supported on each endpoint
#define FIXED_NETWORKS { \
  0 \
}


// Array of EmberAfCommandMetadata structs.
#define ZAP_COMMAND_MASK(mask) COMMAND_MASK_ ## mask
#define EMBER_AF_GENERATED_COMMAND_COUNT  (7)
#define GENERATED_COMMANDS { \
  { 0x0800, 0x00, COMMAND_MASK_INCOMING_SERVER | COMMAND_MASK_OUTGOING_CLIENT }, /* 0, Cluster: Key Establishment, Command: InitiateKeyEstablishmentRequest*/ \
  { 0x0800, 0x00, COMMAND_MASK_INCOMING_CLIENT | COMMAND_MASK_OUTGOING_SERVER }, /* 1, Cluster: Key Establishment, Command: InitiateKeyEstablishmentResponse*/ \
  { 0x0800, 0x01, COMMAND_MASK_INCOMING_SERVER | COMMAND_MASK_OUTGOING_CLIENT }, /* 2, Cluster: Key Establishment, Command: EphemeralDataRequest*/ \
  { 0x0800, 0x01, COMMAND_MASK_INCOMING_CLIENT | COMMAND_MASK_OUTGOING_SERVER }, /* 3, Cluster: Key Establishment, Command: EphemeralDataResponse*/ \
  { 0x0800, 0x02, COMMAND_MASK_INCOMING_SERVER | COMMAND_MASK_OUTGOING_CLIENT }, /* 4, Cluster: Key Establishment, Command: ConfirmKeyDataRequest*/ \
  { 0x0800, 0x02, COMMAND_MASK_INCOMING_CLIENT | COMMAND_MASK_OUTGOING_SERVER }, /* 5, Cluster: Key Establishment, Command: ConfirmKeyDataResponse*/ \
  { 0x0800, 0x03, COMMAND_MASK_INCOMING_CLIENT | COMMAND_MASK_OUTGOING_SERVER }, /* 6, Cluster: Key Establishment, Command: TerminateKeyEstablishment*/ \
}


// Array of EmberAfManufacturerCodeEntry structures for commands.
#define GENERATED_COMMAND_MANUFACTURER_CODE_COUNT (0)
#define GENERATED_COMMAND_MANUFACTURER_CODES { \
  { 0x00, 0x00 }  \
}

// This is an array of EmberAfManufacturerCodeEntry structures for clusters.
#define GENERATED_CLUSTER_MANUFACTURER_CODE_COUNT (0)
#define GENERATED_CLUSTER_MANUFACTURER_CODES { \
  { 0x00, 0x00 }  \
}

// This is an array of EmberAfManufacturerCodeEntry structures for attributes.
#define GENERATED_ATTRIBUTE_MANUFACTURER_CODE_COUNT (0)
#define GENERATED_ATTRIBUTE_MANUFACTURER_CODES { \
  { 0x00, 0x00 } \
}

// Array of EmberAfPluginReportingEntry structures.
#define EMBER_AF_GENERATED_REPORTING_CONFIG_DEFAULTS_TABLE_SIZE (0)	
#define EMBER_AF_GENERATED_REPORTING_CONFIG_DEFAULTS { \
}

#define EMBER_AF_MANUFACTURER_CODE 0x1002
#define EMBER_AF_DEFAULT_RESPONSE_POLICY_ALWAYS

// All Enabled Clusters
#define ZCL_USING_BASIC_CLUSTER_SERVER
#define ZCL_USING_KEY_ESTABLISHMENT_CLUSTER_CLIENT
#define ZCL_USING_KEY_ESTABLISHMENT_CLUSTER_SERVER

// Cluster Counts
#define EMBER_AF_BASIC_CLUSTER_SERVER_ENDPOINT_COUNT (1)
#define EMBER_AF_KEY_ESTABLISHMENT_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_KEY_ESTABLISHMENT_CLUSTER_SERVER_ENDPOINT_COUNT (1)

// All Enabled Cluster Attributes
#define ZCL_USING_BASIC_CLUSTER_VERSION_ATTRIBUTE
#define ZCL_USING_BASIC_CLUSTER_APPLICATION_VERSION_ATTRIBUTE
#define ZCL_USING_BASIC_CLUSTER_MODEL_IDENTIFIER_ATTRIBUTE
#define ZCL_USING_BASIC_CLUSTER_POWER_SOURCE_ATTRIBUTE
#define ZCL_USING_BASIC_CLUSTER_CLUSTER_REVISION_SERVER_ATTRIBUTE
#define ZCL_USING_KEY_ESTABLISHMENT_CLUSTER_KEY_ESTABLISHMENT_SUITE_CLIENT_ATTRIBUTE
#define ZCL_USING_KEY_ESTABLISHMENT_CLUSTER_CLUSTER_REVISION_CLIENT_ATTRIBUTE
#define ZCL_USING_KEY_ESTABLISHMENT_CLUSTER_KEY_ESTABLISHMENT_SUITE_SERVER_ATTRIBUTE
#define ZCL_USING_KEY_ESTABLISHMENT_CLUSTER_CLUSTER_REVISION_SERVER_ATTRIBUTE

#define EMBER_AF_SUPPORT_COMMAND_DISCOVERY


#endif // SILABS_AF_ENDPOINT_CONFIG