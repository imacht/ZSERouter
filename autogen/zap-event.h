/***************************************************************************//**
 * @file  zap-event.h
 * @brief Generated file for zcl events using ZAP. Do not update file manually.
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


#ifdef UC_BUILD
#include "sl_component_catalog.h"

#ifdef SL_CATALOG_ZIGBEE_ZCL_FRAMEWORK_CORE_PRESENT
#include "af.h"

#define EMBER_AF_GENERATED_UC_EVENTS_DEF \
sl_zigbee_event_t emberAfKeyEstablishmentClusterServerTickCallbackEvent1; \


#define EMBER_AF_GENERATED_UC_EVENTS_INIT \
extern void emberAfKeyEstablishmentClusterServerTickCallback(uint8_t enpoint); \
sl_zigbee_endpoint_event_init(&emberAfKeyEstablishmentClusterServerTickCallbackEvent1, (void *)emberAfKeyEstablishmentClusterServerTickCallback, 1); \

// sl_zigbee_event_context_t structs used to populate the sli_zigbee_app_event_context table
#define EMBER_AF_GENERATED_UC_EVENT_CONTEXT \
{ 1, 0x800, false, EMBER_AF_LONG_POLL, EMBER_AF_OK_TO_SLEEP, &emberAfKeyEstablishmentClusterServerTickCallbackEvent1 },     \

#endif // SL_CATALOG_ZIGBEE_ZCL_FRAMEWORK_CORE_PRESENT
#endif // UC_BUILD
