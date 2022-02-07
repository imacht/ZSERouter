/***************************************************************************//**
 * @file
 * @brief Callback implementation for ZigbeeMinimal sample application.
 *******************************************************************************
 * # License
 * <b>Copyright 2019 Silicon Laboratories Inc. www.silabs.com</b>
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

// This callback file is created for your convenience. You may add application
// code to this file. If you regenerate this file over a previous version, the
// previous version will be overwritten and any code you have added will be
// lost.

#include "app/framework/include/af.h"
#include "network-find.h"
//#include "update-tc-link-key.h"

#define ROUTER_ENDPOINT (1)

#define ALL_CHANNELS_MASK       0x07FFF800
#define INIT_KE_DELAY_MS        1000
#define BUTTON0         0
#define BUTTON1         1

static sl_zigbee_event_t commissioning_event;
static sl_zigbee_event_t init_ke_event;
#define commissioningEvent (&commissioning_event)
#define initKeEvent (&init_ke_event)

static void find_result(const EmberAfServiceDiscoveryResult *r);


void commissioningEventHandler(SLXU_UC_EVENT)
{
    EmberStatus status;

    slxu_zigbee_event_set_inactive(commissioningEvent);

    // allow joining on all possible channels
    // TODO: might be quicker to search preferred first, investigate?
    status = emberAfSetFormAndJoinChannelMask(0, ALL_CHANNELS_MASK);
    emberAfCorePrintln("------- SetFormAndJoinChannelMask returned : 0x%X", status);
    status = emberAfStartSearchForJoinableNetwork();
    emberAfCorePrintln("------- StartSearchForJoinableNetwork returned : 0x%X", status);
}

void initKeEventHandler(SLXU_UC_EVENT)
{
    EmberStatus status;

    slxu_zigbee_event_set_inactive(initKeEvent);

    status = emberAfInitiateKeyEstablishment(0x0000,1);
    emberAfCorePrintln("------- InitiateKeyEstablishment returned : 0x%X", status);
}

boolean emberAfPluginKeyEstablishmentEventCallback(EmberAfKeyEstablishmentNotifyMessage status,
                                        boolean amInitiator,
                                        EmberNodeId partnerShortId,
                                        int8u delayInSeconds)
{
    EmberStatus stat;

    slxu_zigbee_event_set_inactive(initKeEvent);
    emberAfCorePrintln("------- KE_notification status: 0x%X  partnerID: 0x%X  delay 0x%Xs",
                       status, partnerShortId, delayInSeconds);
    if (LINK_KEY_ESTABLISHED == status)
    {
        emberAfCorePrintln("------- LINK_KEY_ESTABLISHED ------");

        if ((stat = emberAfFindDevicesByProfileAndCluster(EMBER_RX_ON_WHEN_IDLE_BROADCAST_ADDRESS,
                                                          SE_PROFILE_ID,
                                                          //ZCL_SIMPLE_METERING_CLUSTER_ID,
                                                          ZCL_TIME_CLUSTER_ID,
                                                          EMBER_AF_SERVER_CLUSTER_DISCOVERY,
                                                          find_result)))
            emberAfCorePrintln("------- KE_xxxxxxx 0x%Xs",stat    );
    }
    return true;
}

static void find_result(const EmberAfServiceDiscoveryResult *r)
{
    const EmberAfEndpointList* l;
    boolean resp_rcvd = false;
    emberAfCorePrintln("------- Meter Find result = 0x%04X", r);
    switch (r->status) {
        case EMBER_AF_BROADCAST_SERVICE_DISCOVERY_COMPLETE:
            emberAfCorePrintln("------- Meter Find result status = EMBER_AF_BROADCAST_SERVICE_DISCOVERY_COMPLETE");
            break;
        case EMBER_AF_BROADCAST_SERVICE_DISCOVERY_RESPONSE_RECEIVED  :
            emberAfCorePrintln("------- Meter Find result status = EMBER_AF_BROADCAST_SERVICE_DISCOVERY_RESPONSE_RECEIVED");
            resp_rcvd = true;
            break;
        case EMBER_AF_BROADCAST_SERVICE_DISCOVERY_COMPLETE_WITH_RESPONSE  :
            emberAfCorePrintln("------- Meter Find result status = EMBER_AF_BROADCAST_SERVICE_DISCOVERY_COMPLETE_WITH_RESPONSE");
            resp_rcvd = true;
            break;
        case EMBER_AF_BROADCAST_SERVICE_DISCOVERY_COMPLETE_WITH_EMPTY_RESPONSE :
            emberAfCorePrintln("------- Meter Find result status = EMBER_AF_BROADCAST_SERVICE_DISCOVERY_COMPLETE_WITH_EMPTY_RESPONSE");
            resp_rcvd = true;
            break;
        default:
            emberAfCorePrintln("------- UNICAST or unknown result status");
    }
    if (resp_rcvd && r) {
        l = r->responseData;
        emberAfCorePrintln("-------           l = 0x%04X", l);
        emberAfCorePrintln("------- Meter Find result: addr: 0x%02X  count: %d",
                           r->matchAddress, l->count);
        if (l->count && l->list)
            emberAfCorePrintln("------- Meter Find result: list entry: 0x%X", *l->list);
    }
}

void emberAfMainInitCallback(void)
{
    slxu_zigbee_event_init(commissioningEvent, commissioningEventHandler);
    slxu_zigbee_event_init(initKeEvent, initKeEventHandler);
}

/** @brief Stack Status
 *
 * This function is called by the application framework from the stack status
 * handler. The framework will always process the stack status after the
 * callback returns.
 *
 * Respond to network going up with proceeding to KE
 *
 * @param status   Ver.: always
 */
void emberAfStackStatusCallback(EmberStatus status)
{
    if (EMBER_NETWORK_UP == status) {
        slxu_zigbee_event_set_active(initKeEvent);
    }
}

void emberAfRegistrationCallback(boolean success)
{
    char *val_str = success?"Success":"Fail";
    emberAfCorePrintln("------- Registration Complete : %s", val_str);
}


/** @brief Hal Button Isr
 *
 * This callback is called by the framework whenever a button is pressed on the
 * device. This callback is called within ISR context.
 *
 * @param button The button which has changed state, either BUTTON0 or BUTTON1
 * as defined in the appropriate BOARD_HEADER.
 *
 * Use Button0 release to kick off trying to join network
 */
#if defined(SL_CATALOG_SIMPLE_BUTTON_PRESENT) && (EMBER_AF_PLUGIN_IDLE_SLEEP_USE_BUTTONS == 0)
#include "sl_simple_button.h"
#include "sl_simple_button_instances.h"
void sl_button_on_change(const sl_button_t *handle)
{
  if (SL_SIMPLE_BUTTON_INSTANCE(BUTTON0) == handle) {
    if ( sl_button_get_state(handle) == SL_SIMPLE_BUTTON_RELEASED) {
      slxu_zigbee_event_set_active(commissioningEvent);
    }
  }
}
#endif
