// GENERATED FILE DO NOT MODIFY
// Generated by: generate-zigbee-logger-files.py -y zigbee_logger.yaml

// This file provides weak definitions when the Zigbee
// Event Logger component is not included.

#include "stack/include/ember.h"

WEAK(void emberAfPluginZigBeeEventLoggerAddBootEvent(uint32_t bootCount, uint16_t resetType))
{
}

WEAK(void emberAfPluginZigBeeEventLoggerAddJoinNetwork(EmberPanId panId, uint8_t channelNumber, uint8_t page, uint8_t *extendedPanId))
{
}

WEAK(void emberAfPluginZigBeeEventLoggerAddTrustCenterRejoin(uint32_t channelMask, EmberRejoinReason reason))
{
}

WEAK(void emberAfPluginZigBeeEventLoggerAddSecureRejoin(uint32_t channelMask, EmberRejoinReason reason))
{
}

WEAK(void emberAfPluginZigBeeEventLoggerAddLeaveWithoutRejoin(EmberNodeId sourceNode, EmberLeaveReason reason))
{
}

WEAK(void emberAfPluginZigBeeEventLoggerAddLeaveWithRejoin(EmberNodeId sourceNode, EmberLeaveReason reason))
{
}

WEAK(void emberAfPluginZigBeeEventLoggerAddTrustCenterLinkKeyChange(void))
{
}

WEAK(void emberAfPluginZigBeeEventLoggerAddNetworkKeySequenceChange(uint8_t sequence))
{
}

WEAK(void emberAfPluginZigBeeEventLoggerAddReset(uint8_t resetCode, uint8_t extendedReason))
{
}

WEAK(void emberAfPluginZigBeeEventLoggerAddChannelChange(uint8_t page, uint8_t channel))
{
}

WEAK(void emberAfPluginZigBeeEventLoggerAddParentChange(EmberNodeId parentNodeId, EmberEUI64 parentEui64))
{
}

WEAK(void emberAfPluginZigBeeEventLoggerAddDutyCycleChange(EmberDutyCycleState state, EmberDutyCycleHectoPct limitThreshold, EmberDutyCycleHectoPct criticalThreshold, EmberDutyCycleHectoPct suspendedLimit))
{
}

WEAK(void emberAfPluginZigBeeEventLoggerAddChildAdded(EmberNodeId childNodeId, EmberEUI64 childEui64))
{
}

WEAK(void emberAfPluginZigBeeEventLoggerAddChildRemoved(EmberNodeId childNodeId, EmberEUI64 childEui64))
{
}

WEAK(void emberAfPluginZigBeeEventLoggerAddChildTimedOut(EmberNodeId childNodeId, EmberEUI64 childEui64))
{
}

WEAK(void emberAfPluginZigBeeEventLoggerAddStackStatus(EmberStatus status))
{
}

WEAK(void emberAfPluginZigBeeEventLoggerAddTimeSync(uint32_t utcTime, uint32_t secondsSinceBoot))
{
}

WEAK(void emberAfPluginZigBeeEventLoggerAddTrustCenterJoinDecision(EmberNodeId nodeId, uint8_t decision))
{
}
