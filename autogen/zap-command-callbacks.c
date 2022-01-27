/*******************************************************************************
 * @file  zap-command-callbacks.c
 * @brief This file contains weak implementations for the ZCL cluster callbacks
 * that the user must implement in the current project. Weak implementations are
 * supplied in order to allow the project to compile.
 * When generating this file ZAP uses the info from implementedCommands.json  
 * to determine which ZCL commands have an SDK implementation. 
 * 
 * This file is generated. Do not update the file manually.
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

#include "sl_component_catalog.h"
#ifdef SL_CATALOG_ZIGBEE_ZCL_FRAMEWORK_CORE_PRESENT

#include "af.h"
#include "zap-type.h"

/* The ZCL cluster command callbacks should have a proper (not WEAK) implementation in a
 * separate file in the project, the current file will be overwritten with every subsequent
 * project generation.
 */
WEAK(bool emberAfKeyEstablishmentClusterConfirmKeyDataResponseCallback(/* TYPE WARNING: Smac defaults to */ uint8_t * secureMessageAuthenticationCode )) {
	return EMBER_ZCL_STATUS_UNSUP_COMMAND;
}

WEAK(bool emberAfKeyEstablishmentClusterEphemeralDataResponseCallback(/* TYPE WARNING: EphemeralData defaults to */ uint8_t * ephemeralData )) {
	return EMBER_ZCL_STATUS_UNSUP_COMMAND;
}

WEAK(bool emberAfKeyEstablishmentClusterInitiateKeyEstablishmentResponseCallback(uint16_t requestedKeyEstablishmentSuite , uint8_t ephemeralDataGenerateTime , uint8_t confirmKeyGenerateTime , /* TYPE WARNING: Identity defaults to */ uint8_t * identity )) {
	return EMBER_ZCL_STATUS_UNSUP_COMMAND;
}

WEAK(bool emberAfKeyEstablishmentClusterTerminateKeyEstablishmentCallback(uint8_t statusCode , uint8_t waitTime , uint16_t keyEstablishmentSuite )) {
	return EMBER_ZCL_STATUS_UNSUP_COMMAND;
}


/* For reference purposes below is the list of ZCL cluster command callbacks in this project that have an SDK implementation.
 * The implementation will be visible if the corresonding component gets included in the project. */ 
// bool emberAfKeyEstablishmentClusterConfirmKeyDataRequestCallback(/* TYPE WARNING: Smac defaults to */ uint8_t * secureMessageAuthenticationCode );

// bool emberAfKeyEstablishmentClusterEphemeralDataRequestCallback(/* TYPE WARNING: EphemeralData defaults to */ uint8_t * ephemeralData );

// bool emberAfKeyEstablishmentClusterInitiateKeyEstablishmentRequestCallback(uint16_t keyEstablishmentSuite , uint8_t ephemeralDataGenerateTime , uint8_t confirmKeyGenerateTime , /* TYPE WARNING: Identity defaults to */ uint8_t * identity );



#endif
