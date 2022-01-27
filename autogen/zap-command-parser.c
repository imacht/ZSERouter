/***************************************************************************//**
 * @file  zap-command-parser.c
 * @brief This file contains a set of generated functions that parse the
 * incomming message, and call appropriate command handler.
 * This file is generated. Do not update file manually.
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

#include <stdint.h>

#include "af.h"
#include "zap-type.h"
#include "zap-command-parser.h"

EmberAfStatus emberAfKeyEstablishmentClusterClientCommandParse(EmberAfClusterCommand * cmd);
EmberAfStatus emberAfKeyEstablishmentClusterServerCommandParse(EmberAfClusterCommand * cmd);
extern uint16_t emberAfFindClusterNameIndexWithMfgCode(uint16_t cluster, uint16_t mfgCode);

static EmberAfStatus status(bool wasHandled, bool clusterExists, bool mfgSpecific)
{
  if (wasHandled) {
    return EMBER_ZCL_STATUS_SUCCESS;
  } else if (clusterExists) {
    return EMBER_ZCL_STATUS_UNSUP_COMMAND;
  } else {
    return EMBER_ZCL_STATUS_UNSUPPORTED_CLUSTER;
  }
}


// Main command parsing controller.
EmberAfStatus emberAfClusterSpecificCommandParse(EmberAfClusterCommand * cmd)
{
    EmberAfStatus result = status(false, false, cmd->mfgSpecific);
    if (cmd->direction == (uint8_t) ZCL_DIRECTION_SERVER_TO_CLIENT &&
        emberAfContainsClientWithMfgCode(cmd->apsFrame->destinationEndpoint, cmd->apsFrame->clusterId, cmd->mfgCode))
    {
        switch (cmd->apsFrame->clusterId)
        {
            case ZCL_KEY_ESTABLISHMENT_CLUSTER_ID :
            result = emberAfKeyEstablishmentClusterClientCommandParse(cmd);
            break;
        default:
            // Unrecognized cluster ID, error status will apply.
            if (emberAfFindClusterNameIndexWithMfgCode(cmd->apsFrame->clusterId, cmd->mfgCode) != 0xFFFF) {
                result = status(false, true, cmd->mfgSpecific);
            }
            break;
        }
    }
    else if (cmd->direction == (uint8_t) ZCL_DIRECTION_CLIENT_TO_SERVER &&
             emberAfContainsServerWithMfgCode(cmd->apsFrame->destinationEndpoint, cmd->apsFrame->clusterId, cmd->mfgCode))
    {
        switch (cmd->apsFrame->clusterId)
        {
                case ZCL_KEY_ESTABLISHMENT_CLUSTER_ID :
                    result = emberAfKeyEstablishmentClusterServerCommandParse(cmd);
                    break;
        default:
            // Unrecognized cluster ID, error status will apply.
            if (emberAfFindClusterNameIndexWithMfgCode(cmd->apsFrame->clusterId, cmd->mfgCode) != 0xFFFF) {
                result = status(false, true, cmd->mfgSpecific);
            }
            break;
        }
    }
    return result;
}

// Cluster specific command parsing

EmberAfStatus emberAfKeyEstablishmentClusterClientCommandParse(EmberAfClusterCommand * cmd)
{    
    bool wasHandled = false;
    if (!cmd->mfgSpecific)
    {
        switch (cmd->commandId)
        { 

            case ZCL_CONFIRM_KEY_DATA_RESPONSE_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Command is fixed length
            if (cmd->bufLen < payloadOffset + 0u) {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }                /* TYPE WARNING: Smac defaults to */ uint8_t * secureMessageAuthenticationCode;
secureMessageAuthenticationCode = cmd->buffer + payloadOffset;


            wasHandled = emberAfKeyEstablishmentClusterConfirmKeyDataResponseCallback(secureMessageAuthenticationCode);
            break;
        }
            case ZCL_EPHEMERAL_DATA_RESPONSE_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Command is fixed length
            if (cmd->bufLen < payloadOffset + 0u) {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }                /* TYPE WARNING: EphemeralData defaults to */ uint8_t * ephemeralData;
ephemeralData = cmd->buffer + payloadOffset;


            wasHandled = emberAfKeyEstablishmentClusterEphemeralDataResponseCallback(ephemeralData);
            break;
        }
            case ZCL_INITIATE_KEY_ESTABLISHMENT_RESPONSE_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Command is fixed length
            if (cmd->bufLen < payloadOffset + 4u) {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }                uint16_t requestedKeyEstablishmentSuite;
                uint8_t ephemeralDataGenerateTime;
                uint8_t confirmKeyGenerateTime;
                /* TYPE WARNING: Identity defaults to */ uint8_t * identity;
requestedKeyEstablishmentSuite = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

ephemeralDataGenerateTime = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

confirmKeyGenerateTime = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

identity = cmd->buffer + payloadOffset;


            wasHandled = emberAfKeyEstablishmentClusterInitiateKeyEstablishmentResponseCallback(requestedKeyEstablishmentSuite, ephemeralDataGenerateTime, confirmKeyGenerateTime, identity);
            break;
        }
            case ZCL_TERMINATE_KEY_ESTABLISHMENT_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Command is fixed length
            if (cmd->bufLen < payloadOffset + 4u) {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }                uint8_t statusCode;
                uint8_t waitTime;
                uint16_t keyEstablishmentSuite;
statusCode = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

waitTime = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

keyEstablishmentSuite = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);


            wasHandled = emberAfKeyEstablishmentClusterTerminateKeyEstablishmentCallback(statusCode, waitTime, keyEstablishmentSuite);
            break;
        }
default: {
            // Unrecognized command ID, error status will apply.
            break;

        }
        }
    }
    return status(wasHandled, true, cmd->mfgSpecific);
}

EmberAfStatus emberAfKeyEstablishmentClusterServerCommandParse(EmberAfClusterCommand * cmd)
{    
    bool wasHandled = false;
    if (!cmd->mfgSpecific)
    {
        switch (cmd->commandId)
        { 

            case ZCL_CONFIRM_KEY_DATA_REQUEST_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Command is fixed length
            if (cmd->bufLen < payloadOffset + 0u) {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }                /* TYPE WARNING: Smac defaults to */ uint8_t * secureMessageAuthenticationCode;
secureMessageAuthenticationCode = cmd->buffer + payloadOffset;


            wasHandled = emberAfKeyEstablishmentClusterConfirmKeyDataRequestCallback(secureMessageAuthenticationCode);
            break;
        }
            case ZCL_EPHEMERAL_DATA_REQUEST_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Command is fixed length
            if (cmd->bufLen < payloadOffset + 0u) {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }                /* TYPE WARNING: EphemeralData defaults to */ uint8_t * ephemeralData;
ephemeralData = cmd->buffer + payloadOffset;


            wasHandled = emberAfKeyEstablishmentClusterEphemeralDataRequestCallback(ephemeralData);
            break;
        }
            case ZCL_INITIATE_KEY_ESTABLISHMENT_REQUEST_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Command is fixed length
            if (cmd->bufLen < payloadOffset + 4u) {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }                uint16_t keyEstablishmentSuite;
                uint8_t ephemeralDataGenerateTime;
                uint8_t confirmKeyGenerateTime;
                /* TYPE WARNING: Identity defaults to */ uint8_t * identity;
keyEstablishmentSuite = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 2u;

ephemeralDataGenerateTime = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

confirmKeyGenerateTime = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

identity = cmd->buffer + payloadOffset;


            wasHandled = emberAfKeyEstablishmentClusterInitiateKeyEstablishmentRequestCallback(keyEstablishmentSuite, ephemeralDataGenerateTime, confirmKeyGenerateTime, identity);
            break;
        }
            case ZCL_TERMINATE_KEY_ESTABLISHMENT_COMMAND_ID:
            { 
                uint16_t payloadOffset = cmd->payloadStartIndex;
                // Command is fixed length
            if (cmd->bufLen < payloadOffset + 4u) {
                return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
            }                uint8_t statusCode;
                uint8_t waitTime;
                uint16_t keyEstablishmentSuite;
statusCode = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

waitTime = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
                payloadOffset+= 1u;

keyEstablishmentSuite = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);


            wasHandled = emberAfKeyEstablishmentClusterTerminateKeyEstablishmentCallback(statusCode, waitTime, keyEstablishmentSuite);
            break;
        }
default: {
            // Unrecognized command ID, error status will apply.
            break;

        }
        }
    }
    return status(wasHandled, true, cmd->mfgSpecific);
}


#endif