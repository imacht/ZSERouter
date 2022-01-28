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
//#include "network-steering.h"
//#include "update-tc-link-key.h"

#define ROUTER_ENDPOINT (1)

#define INIT_KE_DELAY_MS        1000
#define BUTTON0         0
#define BUTTON1         1

static sl_zigbee_event_t commissioning_event;
static sl_zigbee_event_t init_ke_event;
#define commissioningEvent (&commissioning_event)
#define initKeEvent (&init_ke_event)

static bool commissioning = false;


void commissioningEventHandler(SLXU_UC_EVENT)
{
    EmberStatus status;

    slxu_zigbee_event_set_inactive(commissioningEvent);

//    status = emberAfPluginNetworkSteeringStart();
//    emberAfCorePrintln("%p network %p: 0x%X", "Join", "start", status);

    status = emberAfStartSearchForJoinableNetwork();
    emberAfCorePrintln("** StartSearchForJoinableNetwork returned : 0x%X", status);

    commissioning = true;
}

void initKeEventHandler(SLXU_UC_EVENT)
{
    EmberStatus status;

    slxu_zigbee_event_set_inactive(initKeEvent);

    status = emberAfInitiateKeyEstablishment(0x0000,1);
    emberAfCorePrintln("** InitiateKeyEstablishment returned : 0x%X", status);
}

#ifdef UC_BUILD
void emberAfMainInitCallback(void)
{
    slxu_zigbee_event_init(commissioningEvent, commissioningEventHandler);
    slxu_zigbee_event_init(initKeEvent, initKeEventHandler);
}
#endif

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
#ifdef UC_BUILD
void emberAfStackStatusCallback(EmberStatus status)
#else
bool emberAfStackStatusCallback(EmberStatus status)
#endif
{
    if (status == EMBER_NETWORK_UP) {
//        slxu_zigbee_event_set_delay_ms(initKeEvent, INIT_KE_DELAY_MS);
        slxu_zigbee_event_set_active(initKeEvent);
    }
  #ifndef UC_BUILD
  // This value is ignored by the framework.
  return false;
  #endif
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

/** @brief Complete
 *
 * This callback is fired when the Network Steering plugin is complete.
 *
 * @param status On success this will be set to EMBER_SUCCESS to indicate a
 * network was joined successfully. On failure this will be the status code of
 * the last join or scan attempt. Ver.: always
 * @param totalBeacons The total number of 802.15.4 beacons that were heard,
 * including beacons from different devices with the same PAN ID. Ver.: always
 * @param joinAttempts The number of join attempts that were made to get onto
 * an open Zigbee network. Ver.: always
 * @param finalState The finishing state of the network steering process. From
 * this, one is able to tell on which channel mask and with which key the
 * process was complete. Ver.: always
 */
void emberAfPluginNetworkSteeringCompleteCallback(EmberStatus status,
                                                  uint8_t totalBeacons,
                                                  uint8_t joinAttempts,
                                                  uint8_t finalState)
{
  emberAfCorePrintln("%p network %p: 0x%X", "Join", "complete", status);

//  if (status != EMBER_SUCCESS) {
//    commissioning = false;
//  } else {
//    scheduleFindingAndBindingForInitiator();
//  }
}
