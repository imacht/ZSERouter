/*******************************************************************************
 * @file zigbee_af_cluster_funtions.h
 * @brief Cluster action callback definitions
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/
//
// *** Generated file. Do not edit! ***
//

#include "af.h"


void emberAfKeyEstablishmentClusterClientMessageSentCallback (EmberOutgoingMessageType type, uint16_t indexOrDestination, EmberApsFrame * apsFrame, uint16_t msgLen, uint8_t * message, EmberStatus status);
void emberAfKeyEstablishmentClusterClientDefaultResponseCallback (uint8_t endpoint, uint8_t commandId, EmberAfStatus status);
EmberAfStatus emberAfKeyEstablishmentClusterClientPreAttributeChangedCallback (uint8_t endpoint, EmberAfAttributeId attributeId, EmberAfAttributeType attributeType, uint8_t size, uint8_t * value);
void emberAfKeyEstablishmentClusterClientAttributeChangedCallback (uint8_t endpoint, EmberAfAttributeId attributeId);
void emberAfKeyEstablishmentClusterServerInitCallback (uint8_t endpoint);
void emberAfKeyEstablishmentClusterServerMessageSentCallback (EmberOutgoingMessageType type, uint16_t indexOrDestination, EmberApsFrame * apsFrame, uint16_t msgLen, uint8_t * message, EmberStatus status);
void emberAfKeyEstablishmentClusterServerDefaultResponseCallback (uint8_t endpoint, uint8_t commandId, EmberAfStatus status);
EmberAfStatus emberAfKeyEstablishmentClusterServerPreAttributeChangedCallback (uint8_t endpoint, EmberAfAttributeId attributeId, EmberAfAttributeType attributeType, uint8_t size, uint8_t * value);
void emberAfKeyEstablishmentClusterServerAttributeChangedCallback (uint8_t endpoint, EmberAfAttributeId attributeId);

// Array of cluster function (aka cluster action callbacks) stuctures.
// First entry is a dummy, otherwise an empty array would fail IAR builds
#define GENERATED_FUNCTION_STRUCTURES_ARRAY  { \
  {0x8000, 0x00, 0x00}, \
  { 2048, \
  CLUSTER_MASK_CLIENT | CLUSTER_MASK_MESSAGE_SENT_FUNCTION ,\
  (EmberAfGenericClusterFunction)emberAfKeyEstablishmentClusterClientMessageSentCallback, \
  },\
  { 2048, \
  CLUSTER_MASK_CLIENT | CLUSTER_MASK_DEFAULT_RESPONSE_FUNCTION ,\
  (EmberAfGenericClusterFunction)emberAfKeyEstablishmentClusterClientDefaultResponseCallback, \
  },\
  { 2048, \
  CLUSTER_MASK_CLIENT | CLUSTER_MASK_PRE_ATTRIBUTE_CHANGED_FUNCTION ,\
  (EmberAfGenericClusterFunction)emberAfKeyEstablishmentClusterClientPreAttributeChangedCallback, \
  },\
  { 2048, \
  CLUSTER_MASK_CLIENT | CLUSTER_MASK_ATTRIBUTE_CHANGED_FUNCTION ,\
  (EmberAfGenericClusterFunction)emberAfKeyEstablishmentClusterClientAttributeChangedCallback, \
  },\
  { 2048, \
  CLUSTER_MASK_SERVER | CLUSTER_MASK_INIT_FUNCTION ,\
  (EmberAfGenericClusterFunction)emberAfKeyEstablishmentClusterServerInitCallback, \
  },\
  { 2048, \
  CLUSTER_MASK_SERVER ,\
  },\
  { 2048, \
  CLUSTER_MASK_SERVER | CLUSTER_MASK_MESSAGE_SENT_FUNCTION ,\
  (EmberAfGenericClusterFunction)emberAfKeyEstablishmentClusterServerMessageSentCallback, \
  },\
  { 2048, \
  CLUSTER_MASK_SERVER | CLUSTER_MASK_DEFAULT_RESPONSE_FUNCTION ,\
  (EmberAfGenericClusterFunction)emberAfKeyEstablishmentClusterServerDefaultResponseCallback, \
  },\
  { 2048, \
  CLUSTER_MASK_SERVER | CLUSTER_MASK_PRE_ATTRIBUTE_CHANGED_FUNCTION ,\
  (EmberAfGenericClusterFunction)emberAfKeyEstablishmentClusterServerPreAttributeChangedCallback, \
  },\
  { 2048, \
  CLUSTER_MASK_SERVER | CLUSTER_MASK_ATTRIBUTE_CHANGED_FUNCTION ,\
  (EmberAfGenericClusterFunction)emberAfKeyEstablishmentClusterServerAttributeChangedCallback, \
  },\
  }


// The following structure is not used anywhere in the code, its purpose is 
// compile-time detection of duplicate cluster action callbacks.
// Only a single instance of a given callback type (e.g. default_response_function)
// can exist for a given cluster and side (client/server).
// A compilation error in this structure indicates a duplicate "cluster_functions"
// template contribution.
struct unused_structure {
int clust_2048_client_message_sent_function;
int clust_2048_client_default_response_function;
int clust_2048_client_pre_attribute_changed_function;
int clust_2048_client_attribute_changed_function; 
int clust_2048_server_init_function; 
int clust_2048_server_message_sent_function;
int clust_2048_server_default_response_function;
int clust_2048_server_pre_attribute_changed_function;
int clust_2048_server_attribute_changed_function; 
};
