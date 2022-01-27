/***************************************************************************//**
 * @file sl_cli_command_table.c
 * @brief Declarations of relevant command structs for cli framework.
 * @version x.y.z
 *******************************************************************************
 * # License
 * <b>Copyright 2018 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 ******************************************************************************/

#include <stdlib.h>

#include "sl_cli_config.h"
#include "sl_cli_command.h"
#include "sl_cli_arguments.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 *****************************   TEMPLATED FILE   ******************************
 ******************************************************************************/

/*******************************************************************************
 * Example syntax (.slcc or .slcp) for populating this file:
 *
 *   template_contribution:
 *     - name: cli_command          # Register a command
 *       value:
 *         name: status             # Name of command
 *         handler: status_command  # Function to be called. Must be defined
 *         help: "Prints status"    # Optional help description
 *         shortcuts:               # Optional shorcut list
 *           - name: st
 *         argument:                # Argument list, if apliccable
 *           - type: uint8          # Variable type
 *             help: "Channel"      # Optional description
 *           - type: string
 *             help: "Text"
 *     - name: cli_group            # Register a group
 *       value:
 *         name: shell              # Group name
 *         help: "Shell commands"   # Optional help description
 *         shortcuts:               # Optional shorcuts
 *           - name: sh
 *     - name: cli_command
 *       value:
 *         name: repeat
 *         handler: repeat_cmd
 *         help: "Repeat commands"
 *         shortcuts:
 *           - name: r
 *           - name: rep
 *         group: shell            # Associate command with group
 *         argument:
 *           - type: string
 *             help: "Text"
 *           - type: additional
 *             help: "More text"
 *
 * For subgroups, an optional unique id can be used to allow a particular name to
 * be used more than once. In the following case, from the command line the
 * following commands are available:
 *
 * >  root_1 shell status
 * >  root_2 shell status
 *
 *     - name: cli_group            # Register a group
 *       value:
 *         name: root_1             # Group name
 *
 *     - name: cli_group            # Register a group
 *       value:
 *         name: root_2             # Group name
 *
 *    - name: cli_group             # Register a group
 *       value:
 *         name: shell              # Group name
 *         id: shell_root_1         # Optional unique id for group
 *         group: root_1            # Add group to root_1 group
 *
 *    - name: cli_group             # Register a group
 *       value:
 *         name: shell              # Group name
 *         id: shell_root_2         # Optional unique id for group
 *         group: root_2            # Add group to root_1 group
 *
 *    - name: cli_command           # Register a command
 *       value:
 *         name: status
 *         handler: status_1
 *         group: shell_root_1      # id of subgroup
 *
 *    - name: cli_command           # Register a command
 *       value:
 *         name: status
 *         handler: status_2
 *         group: shell_root_2      # id of subgroup
 *
 ******************************************************************************/

// Provide function declarations
void emberAfPluginAddressTableAddCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginAddressTableSetCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginAddressTableRemoveCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginAddressTableLookupCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginAddressTablePrintCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginIdleSleepStatusCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginIdleSleepStayAwakeCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginIdleSleepAwakeWhenNotJoinedCommand(sl_cli_command_arg_t *arguments);
void emAfCliInfoCommand(sl_cli_command_arg_t *arguments);
void printAllLibraryStatus(sl_cli_command_arg_t *arguments);
void emAfCliBsendCommand(sl_cli_command_arg_t *arguments);
void sli_zigbee_cli_send_command(sl_cli_command_arg_t *arguments);
void sli_zigbee_zcl_read_cli_command(sl_cli_command_arg_t *arguments);
void sli_zigbee_zcl_write_cli_command(sl_cli_command_arg_t *arguments);
void resetCommand(sl_cli_command_arg_t *arguments);
void emAfCliRawCommand(sl_cli_command_arg_t *arguments);
void sli_zigbee_cli_send_command(sl_cli_command_arg_t *arguments);
void emAfCliSendUsingMulticastBindingCommand(sl_cli_command_arg_t *arguments);
void emAfCliTimesyncCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginCountersPrintCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginCounterPrintCounterTypeCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginCountersSimplePrintCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginCountersClear(sl_cli_command_arg_t *arguments);
void emberAfPluginCountersPrintThresholdsCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginCountersSetThresholdCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginCountersResetThresholds(sl_cli_command_arg_t *arguments);
void emberAfPluginCountersSendRequestCommand(sl_cli_command_arg_t *arguments);
void sli_zigbee_debug_print_enable_stack_type_command(sl_cli_command_arg_t *arguments);
void sli_zigbee_debug_print_enable_core_type_command(sl_cli_command_arg_t *arguments);
void sli_zigbee_debug_print_enable_app_type_command(sl_cli_command_arg_t *arguments);
void sli_zigbee_debug_print_enable_zcl_type_command(sl_cli_command_arg_t *arguments);
void sli_zigbee_debug_print_enable_legacy_af_debug_type_command(sl_cli_command_arg_t *arguments);
void emAfPluginFragmentationSetWindowSizeCommand(sl_cli_command_arg_t *arguments);
void emAfPluginFragmentationArtificialBlockDropCommand(sl_cli_command_arg_t *arguments);
void emAfKeyEstablishmentStartCommand(sl_cli_command_arg_t *arguments);
void emAfKeyEstablishmentInterpanCommand(sl_cli_command_arg_t *arguments);
void findMaskCommand(sl_cli_command_arg_t *arguments);
void findModeCommand(sl_cli_command_arg_t *arguments);
void findPrintCommand(sl_cli_command_arg_t *arguments);
void setRegistrationDelayPeriod(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessStatusCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessSetApsSecurityForClusterCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessSetApsSecurityForClusterCommand(sl_cli_command_arg_t *arguments);
void setOptionsCommand(sl_cli_command_arg_t *arguments);
void setDestinationCommand(sl_cli_command_arg_t *arguments);
void startTestCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessSetRegistrationCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessSetRegistrationCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessKeyEstablishmentSetModeCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessKeyEstablishmentSetModeCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessKeyEstablishmentSetModeCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessKeyEstablishmentSetModeCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessKeyEstablishmentSetModeCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessKeyEstablishmentSetModeCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessKeyEstablishmentSetModeCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessKeyEstablishmentSetModeCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessKeyEstablishmentSetModeCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessCertMangleCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessCertMangleCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessCertMangleCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessCertMangleCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessCertMangleCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessKeyEstablishmentSelectSuiteCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessKeyEstablishmentSetAvailableSuiteCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessKeyEstablishmentKeyMangleCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessPriceSendNewFieldsCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessPriceSendNewFieldsCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessTcKeepaliveSendCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessTcKeepaliveStartStopCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessTcKeepaliveStartStopCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessOtaImageMangleCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessConcentratorStartStopCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessConcentratorStartStopCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessKeyUpdateCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessKeyUpdateCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessKeyUpdateCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessLimitBeaconsOnOffCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessLimitBeaconsOnOffCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessChannelMaskResetClearAllCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessChannelMaskResetClearAllCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessChannelMaskResetClearAllCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessChannelMaskAddOrRemoveCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessChannelMaskAddOrRemoveCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessEnableDisableEndpointCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessEnableDisableEndpointCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessEndpointStatusCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessClusterEndpointIndexCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessRadioOnOffCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessRadioOnOffCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessSetRadioPower(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessAddChildCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessSetNodeDescriptorComplianceRevision(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessSetMaxChildren(sl_cli_command_arg_t *arguments);
void emberAfPluginTestHarnessSetNeighborTableSize(sl_cli_command_arg_t *arguments);
void networkFormCommand(sl_cli_command_arg_t *arguments);
void networkJoinCommand(sl_cli_command_arg_t *arguments);
void networkPermitJoinCommand(sl_cli_command_arg_t *arguments);
void networkLeaveCommand(sl_cli_command_arg_t *arguments);
void networkRejoinCommand(sl_cli_command_arg_t *arguments);
void networkRejoinDiffDeviceTypeCommand(sl_cli_command_arg_t *arguments);
void networkExtendedPanIdCommand(sl_cli_command_arg_t *arguments);
void networkCheckPjoinCommand(sl_cli_command_arg_t *arguments);
void networkPermitJoinCommand(sl_cli_command_arg_t *arguments);
void findJoinableNetworkCommand(sl_cli_command_arg_t *arguments);
void findUnusedPanIdCommand(sl_cli_command_arg_t *arguments);
void networkChangeChannelCommand(sl_cli_command_arg_t *arguments);
void networkSetCommand(sl_cli_command_arg_t *arguments);
void networkInitCommand(sl_cli_command_arg_t *arguments);
void networkIdCommand(sl_cli_command_arg_t *arguments);
void changeKeepAliveModeCommand(sl_cli_command_arg_t *arguments);
void networkChangeChildTimeoutOptionMaskCommand(sl_cli_command_arg_t *arguments);
void networkMultiPhyStartCommand(sl_cli_command_arg_t *arguments);
void networkMultiPhyStopCommand(sl_cli_command_arg_t *arguments);
void keysPrintCommand(sl_cli_command_arg_t *arguments);
void keysClearCommand(sl_cli_command_arg_t *arguments);
void optionBindingTablePrintCommand(sl_cli_command_arg_t *arguments);
void optionBindingTableClearCommand(sl_cli_command_arg_t *arguments);
void optionBindingTableSetCommand(sl_cli_command_arg_t *arguments);
void optionPrintRxCommand(sl_cli_command_arg_t *arguments);
void optionPrintRxCommand(sl_cli_command_arg_t *arguments);
void optionRegisterCommand(sl_cli_command_arg_t *arguments);
void optionDiscoveryTargetCommand(sl_cli_command_arg_t *arguments);
void optionDiscoverCommand(sl_cli_command_arg_t *arguments);
void optionEndDeviceBindCommand(sl_cli_command_arg_t *arguments);
void optionApsRetryCommand(sl_cli_command_arg_t *arguments);
void optionApsRetryCommand(sl_cli_command_arg_t *arguments);
void optionApsRetryCommand(sl_cli_command_arg_t *arguments);
void optionApsSecurityCommand(sl_cli_command_arg_t *arguments);
void optionApsSecurityCommand(sl_cli_command_arg_t *arguments);
void optionSecurityAllowTrustCenterRejoinUsingWellKnownKey(sl_cli_command_arg_t *arguments);
void optionSecurityAllowTrustCenterRejoinUsingWellKnownKeyTimeout(sl_cli_command_arg_t *arguments);
void optionSecuritySetKeyRequestPolicy(sl_cli_command_arg_t *arguments);
void changeKeyCommand(sl_cli_command_arg_t *arguments);
void changeKeyCommand(sl_cli_command_arg_t *arguments);
void optionLinkCommand(sl_cli_command_arg_t *arguments);
void optionInstallCodeCommand(sl_cli_command_arg_t *arguments);
void zdoRouteRequestCommand(sl_cli_command_arg_t *arguments);
void zdoPowerDescriptorRequestCommand(sl_cli_command_arg_t *arguments);
void zdoMgmtLqiCommand(sl_cli_command_arg_t *arguments);
void zdoMgmtBindCommand(sl_cli_command_arg_t *arguments);
void zdoLeaveRequestCommand(sl_cli_command_arg_t *arguments);
void zdoUnbindGroupCommand(sl_cli_command_arg_t *arguments);
void zdoUnbindUnicastCommand(sl_cli_command_arg_t *arguments);
void zdoActiveEpCommand(sl_cli_command_arg_t *arguments);
void zdoBindCommand(sl_cli_command_arg_t *arguments);
void zdoNodeCommand(sl_cli_command_arg_t *arguments);
void zdoMatchCommand(sl_cli_command_arg_t *arguments);
void zdoSimpleCommand(sl_cli_command_arg_t *arguments);
void zdoIeeeAddressRequestCommand(sl_cli_command_arg_t *arguments);
void zdoNwkAddressRequestCommand(sl_cli_command_arg_t *arguments);
void zdoNetworkUpdateScanCommand(sl_cli_command_arg_t *arguments);
void zdoNetworkUpdateSetCommand(sl_cli_command_arg_t *arguments);
void zdoNetworkUpdateScanCommand(sl_cli_command_arg_t *arguments);
void zdoNetworkUpdateChannelCommand(sl_cli_command_arg_t *arguments);
void zdoNetworkUpdateChannelCommand(sl_cli_command_arg_t *arguments);
void zdoAddClusterCommand(sl_cli_command_arg_t *arguments);
void zdoClearClusterCommand(sl_cli_command_arg_t *arguments);
void zdoAddClusterCommand(sl_cli_command_arg_t *arguments);
void zdoClearClusterCommand(sl_cli_command_arg_t *arguments);
void emberAfPrintAttributeTable(sl_cli_command_arg_t *arguments);
void printTimeCommand(sl_cli_command_arg_t *arguments);

// Command structs. Names are in the format : cli_cmd_{command group name}_{command name}
// In order to support hyphen in command and group name, every occurence of it while
// building struct names will be replaced by "_hyphen_"
static const sl_cli_command_info_t cli_cmd_address_hyphen_table_add = \
  SL_CLI_COMMAND(emberAfPluginAddressTableAddCommand,
                 "",
                  "Entry to be added." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_HEX, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_address_hyphen_table_set = \
  SL_CLI_COMMAND(emberAfPluginAddressTableSetCommand,
                 "Set an entry in the address table according to the arguments specified",
                  "" SL_CLI_UNIT_SEPARATOR "" SL_CLI_UNIT_SEPARATOR "" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_HEX, SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_address_hyphen_table_remove = \
  SL_CLI_COMMAND(emberAfPluginAddressTableRemoveCommand,
                 "Remove an entry from the address table.",
                  "Entry to be removed." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_HEX, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_address_hyphen_table_lookup = \
  SL_CLI_COMMAND(emberAfPluginAddressTableLookupCommand,
                 "Lookup an entry in the address table.",
                  "Entry to be looked up." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_HEX, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_address_hyphen_table_print = \
  SL_CLI_COMMAND(emberAfPluginAddressTablePrintCommand,
                 "Prints the address table.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_idle_hyphen_sleep_status = \
  SL_CLI_COMMAND(emberAfPluginIdleSleepStatusCommand,
                 "Display the sleep status",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_idle_hyphen_sleep_force_hyphen_awake = \
  SL_CLI_COMMAND(emberAfPluginIdleSleepStayAwakeCommand,
                 "Set or clear force awake",
                  "" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_idle_hyphen_sleep_awake_hyphen_when_hyphen_not_hyphen_joined = \
  SL_CLI_COMMAND(emberAfPluginIdleSleepAwakeWhenNotJoinedCommand,
                 "Set or clear stay awake when not joined",
                  "" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__info = \
  SL_CLI_COMMAND(emAfCliInfoCommand,
                 "Print infomation about the network state, clusters, and endpoints.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__libs = \
  SL_CLI_COMMAND(printAllLibraryStatus,
                 "Lists which optional libraries of the stack are implemented on this device.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__bsend = \
  SL_CLI_COMMAND(emAfCliBsendCommand,
                 "Send message",
                  "Source endpoint." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__send = \
  SL_CLI_COMMAND(sli_zigbee_cli_send_command,
                 "Send message",
                  "Destination" SL_CLI_UNIT_SEPARATOR "Source endpoint" SL_CLI_UNIT_SEPARATOR "Destination endpoint" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__read = \
  SL_CLI_COMMAND(sli_zigbee_zcl_read_cli_command,
                 "Read message",
                  "endpoint" SL_CLI_UNIT_SEPARATOR "cluster ID" SL_CLI_UNIT_SEPARATOR "attribute ID" SL_CLI_UNIT_SEPARATOR "server?" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__write = \
  SL_CLI_COMMAND(sli_zigbee_zcl_write_cli_command,
                 "Write message",
                  "endpoint" SL_CLI_UNIT_SEPARATOR "cluster ID" SL_CLI_UNIT_SEPARATOR "attribute ID" SL_CLI_UNIT_SEPARATOR "mask" SL_CLI_UNIT_SEPARATOR "data type" SL_CLI_UNIT_SEPARATOR "data byte" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_HEX, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__reset = \
  SL_CLI_COMMAND(resetCommand,
                 "Reset the node",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__raw = \
  SL_CLI_COMMAND(emAfCliRawCommand,
                 "Creates a message by specifying the raw bytes. Use send command to send the message once it has been created. Ex: raw 0x000F {00 0A 00 11 22 33 44 55} sends a message to cluster 15 (0x000F) of length 8 which includes the ZCL header.",
                  "clusterId" SL_CLI_UNIT_SEPARATOR "data" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_HEX, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__send_multicast = \
  SL_CLI_COMMAND(sli_zigbee_cli_send_command,
                 "Send a pre-buffered multicast message to a given group id from a given endpoint.",
                  "groupId" SL_CLI_UNIT_SEPARATOR "src-endpoint" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__send_hyphen_using_hyphen_multicast_hyphen_binding = \
  SL_CLI_COMMAND(emAfCliSendUsingMulticastBindingCommand,
                 "When sending using a binding, specify whether a multicast binding should be used.",
                  "useMulticastBinding" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__timesync = \
  SL_CLI_COMMAND(emAfCliTimesyncCommand,
                 "This sends a read attr for the time of the device specified. It sets a flag so when it gets the response it writes the time to its own time attr.",
                  "Id" SL_CLI_UNIT_SEPARATOR "srcEndpoint" SL_CLI_UNIT_SEPARATOR "destEndpoint" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_counters_print = \
  SL_CLI_COMMAND(emberAfPluginCountersPrintCommand,
                 "Print all counter values and clear them.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_counter_print_hyphen_counter_hyphen_type = \
  SL_CLI_COMMAND(emberAfPluginCounterPrintCounterTypeCommand,
                 "Print value of this particular counter.",
                  "The counter type to print." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_counters_simple_hyphen_print = \
  SL_CLI_COMMAND(emberAfPluginCountersSimplePrintCommand,
                 "Print all counter values.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_counters_clear = \
  SL_CLI_COMMAND(emberAfPluginCountersClear,
                 "Clear all counter values.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_counters_print_hyphen_thresholds = \
  SL_CLI_COMMAND(emberAfPluginCountersPrintThresholdsCommand,
                 "Prints the thresholds of all the counters.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_counters_set_hyphen_threshold = \
  SL_CLI_COMMAND(emberAfPluginCountersSetThresholdCommand,
                 "Set a threshold value for a particular type of counter.",
                  "type of counter" SL_CLI_UNIT_SEPARATOR "Threshold Value" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_counters_reset_hyphen_thresholds = \
  SL_CLI_COMMAND(emberAfPluginCountersResetThresholds,
                 "Resets all thresholds values to 0xFFFF.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_counters_send_hyphen_request = \
  SL_CLI_COMMAND(emberAfPluginCountersSendRequestCommand,
                 "Sends a request for ota counters",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_enable_type_stack = \
  SL_CLI_COMMAND(sli_zigbee_debug_print_enable_stack_type_command,
                 "Enable/disable debug `stack` print type",
                  "enable/disable" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_enable_type_core = \
  SL_CLI_COMMAND(sli_zigbee_debug_print_enable_core_type_command,
                 "Enable/disable debug `core` print type",
                  "enable/disable" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_enable_type_app = \
  SL_CLI_COMMAND(sli_zigbee_debug_print_enable_app_type_command,
                 "Enable/disable debug `app` print type",
                  "enable/disable" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_enable_type_zcl = \
  SL_CLI_COMMAND(sli_zigbee_debug_print_enable_zcl_type_command,
                 "Enable/disable debug `zcl` print type",
                  "enable/disable" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_enable_type_legacy_af_debug = \
  SL_CLI_COMMAND(sli_zigbee_debug_print_enable_legacy_af_debug_type_command,
                 "Enable/disable debug `legacy app framework debug` print type",
                  "enable/disable" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_fragmentation_set_hyphen_rx_hyphen_window_hyphen_size = \
  SL_CLI_COMMAND(emAfPluginFragmentationSetWindowSizeCommand,
                 "Sets the receive window size.  By definition in the Smart Energy profile it must be set to 1 but this allows to be changed.",
                  "The max number of the blocks received before an APS ack is generated." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_fragmentation_artificial_hyphen_block_hyphen_drop = \
  SL_CLI_COMMAND(emAfPluginFragmentationArtificialBlockDropCommand,
                 "Artificially drops the block number defined by the passed argument only once, and then allows it upon a retry.",
                  "The block number to artificially drop to force a retry.  Set to 0xFF to disable." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_key_hyphen_establishment_start = \
  SL_CLI_COMMAND(emAfKeyEstablishmentStartCommand,
                 "Initiates key establishment with the target node ID.",
                  "Target node ID." SL_CLI_UNIT_SEPARATOR "Target nodes endpoint." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_key_hyphen_establishment_interpan = \
  SL_CLI_COMMAND(emAfKeyEstablishmentInterpanCommand,
                 "Initiate key establishment with the target device over interpan.",
                  "The PAN ID that the target is located on." SL_CLI_UNIT_SEPARATOR "The targets EUI64 (big endian)" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_HEX, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_find_mask = \
  SL_CLI_COMMAND(findMaskCommand,
                 "Set a channel mask for a given channel page for find joinable and find unused.",
                  "channel page (0 and 28-31, if sub-GHz support is included)" SL_CLI_UNIT_SEPARATOR "channel mask" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT32, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_find_mode = \
  SL_CLI_COMMAND(findModeCommand,
                 "Set a search mode for find joinable and find unused.",
                  "Bit 0 = enable 2.4GHz, Bit 1 = enable sub-GHz" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_INT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_find_print = \
  SL_CLI_COMMAND(findPrintCommand,
                 "Print network search parameters (mode and channel masks).",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_smart_hyphen_energy_hyphen_registration_set_hyphen_period = \
  SL_CLI_COMMAND(setRegistrationDelayPeriod,
                 "Sets the discovery period (in seconds)",
                  "The discovery period (in seconds)." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT32, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_test_hyphen_harness_status = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessStatusCommand,
                 "Display the current status of the test harness.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_aps_hyphen_sec_hyphen_for_hyphen_cluster_on = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessSetApsSecurityForClusterCommand,
                 "Turns on automatic APS security for the specified cluster.",
                  "The cluster ID to add APS security to automatically." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_aps_hyphen_sec_hyphen_for_hyphen_cluster_off = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessSetApsSecurityForClusterCommand,
                 "Turns off automatic APS security for the previously specified cluster.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_attr_options = \
  SL_CLI_COMMAND(setOptionsCommand,
                 "Set the options for the attributes tests.",
                  "" SL_CLI_UNIT_SEPARATOR "" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_attr_set_hyphen_dest = \
  SL_CLI_COMMAND(setDestinationCommand,
                 "Set the destination for the attributes tests.",
                  "" SL_CLI_UNIT_SEPARATOR "" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_attr_start_hyphen_test = \
  SL_CLI_COMMAND(startTestCommand,
                 "Start the attributes test.",
                  "" SL_CLI_UNIT_SEPARATOR "" SL_CLI_UNIT_SEPARATOR "" SL_CLI_UNIT_SEPARATOR "" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT16, SL_CLI_ARG_INT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_registration_on = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessSetRegistrationCommand,
                 "Turns on automatic SE registration.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_registration_off = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessSetRegistrationCommand,
                 "Turns off automatic SE registration.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_key_hyphen_establishment_normal_hyphen_mode = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessKeyEstablishmentSetModeCommand,
                 "Sets the key establishment mode to normal.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_key_hyphen_establishment_no_hyphen_resources = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessKeyEstablishmentSetModeCommand,
                 "All received KE requests will be responded with no resources.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_key_hyphen_establishment_out_hyphen_of_hyphen_sequence = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessKeyEstablishmentSetModeCommand,
                 "All received KE requests will be responded with no resources.",
                  "The out-of-sequence command ID to send." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_key_hyphen_establishment_timeout = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessKeyEstablishmentSetModeCommand,
                 "Artificially creates a timeout by delaying an outgoing message.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_key_hyphen_establishment_delay_hyphen_cbke = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessKeyEstablishmentSetModeCommand,
                 "Changes the advertised delays by the local device for CBKE.",
                  "Set the actual delay that occurs." SL_CLI_UNIT_SEPARATOR "Sets the advertised delay sent to the partner of key establishment" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_key_hyphen_establishment_default_hyphen_resp = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessKeyEstablishmentSetModeCommand,
                 "Sends a default response error message in response to initate KE.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_key_hyphen_establishment_new_hyphen_key_hyphen_policy = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessKeyEstablishmentSetModeCommand,
                 "Sets the policy of whether the TC allows new KE requests.",
                  "Allows / disallows new key establishment requests." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_key_hyphen_establishment_reset_hyphen_aps_hyphen_fc = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessKeyEstablishmentSetModeCommand,
                 "Forces the local device to reset its outgoing APS FC.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_key_hyphen_establishment_adv_hyphen_aps_hyphen_fc = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessKeyEstablishmentSetModeCommand,
                 "Advances the local devices outgoing APS FC by 4096.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_cert_hyphen_mangle_length = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessCertMangleCommand,
                 "Mangles the length of the certificate",
                  "The positive or negative change in length." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_INT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_cert_hyphen_mangle_issuer = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessCertMangleCommand,
                 "Changes the issuer in the certificate.",
                  "The EUI64 of the issuer (big endian)." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_HEX, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_cert_hyphen_mangle_corrupt = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessCertMangleCommand,
                 "Corrupts a single byte in the cert",
                  "The index of the certificate byte to corrupt" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_cert_hyphen_mangle_change_hyphen_byte = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessCertMangleCommand,
                 "Changes a single byte in the cert",
                  "The index of the certificate byte to change" SL_CLI_UNIT_SEPARATOR "The new value of the certificate byte" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_cert_hyphen_mangle_subject = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessCertMangleCommand,
                 "Changes the subject (EUI64) of the cert",
                  "The EUI64 of the subject (big endian)." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_HEX, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_key_hyphen_establishment_suite = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessKeyEstablishmentSelectSuiteCommand,
                 "Selects between the CBKE 163k1 and 283k1 suites.",
                  "This field holds the type        of key establishment suite. It can be EMBER_AF_CBKE_KEY_ESTABLISHMENT_SUITE_163K1,        EMBER_AF_CBKE_KEY_ESTABLISHMENT_SUITE_283K1, or        EMBER_AF_INVALID_KEY_ESTABLISHMENT_SUITE" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_key_hyphen_establishment_set_hyphen_available_hyphen_suite = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessKeyEstablishmentSetAvailableSuiteCommand,
                 "Selects between the CBKE 163k1 and 283k1 suites.",
                  "This field holds the type        of key establishment suite. It can be EMBER_AF_CBKE_KEY_ESTABLISHMENT_SUITE_163K1,        EMBER_AF_CBKE_KEY_ESTABLISHMENT_SUITE_283K1, or        EMBER_AF_INVALID_KEY_ESTABLISHMENT_SUITE" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_key_hyphen_establishment_key_hyphen_mangle = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessKeyEstablishmentKeyMangleCommand,
                 "Mangles the length of the empheral key.",
                  "The positive or negative change in length." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_INT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_price_send_hyphen_new_hyphen_fields = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessPriceSendNewFieldsCommand,
                 "Controls whether the new SE 1.1 price fields are included.",
                  "Boolean indicating whether to send new fields." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_price_send_hyphen_se10_hyphen_fields = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessPriceSendNewFieldsCommand,
                 "Controls whether the new SE 1.1 price fields are included.",
                  "Boolean indicating whether to send new fields." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_tc_hyphen_keepalive_send = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessTcKeepaliveSendCommand,
                 "Sends a Trust Center Keepalive.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_tc_hyphen_keepalive_start = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessTcKeepaliveStartStopCommand,
                 "Starts the TC keepalive state machine.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_tc_hyphen_keepalive_stop = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessTcKeepaliveStartStopCommand,
                 "Stops the TC keepalive state machine.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_ota_image_hyphen_mangle = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessOtaImageMangleCommand,
                 "Mangles the Simple Storage RAM OTA image.",
                  "The byte index into the OTA image that will be mangled." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_test_hyphen_harness_concentrator_hyphen_start = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessConcentratorStartStopCommand,
                 "Starts the concentrators periodic broadcasts.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_test_hyphen_harness_concentrator_hyphen_stop = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessConcentratorStartStopCommand,
                 "Starts the concentrators periodic broadcasts.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_key_hyphen_update_unicast = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessKeyUpdateCommand,
                 "Changes TC NWK key update mechanism to unicast with APS security.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_key_hyphen_update_broadcast = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessKeyUpdateCommand,
                 "Changes TC NWK key update mechanism to broadcast.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_key_hyphen_update_now = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessKeyUpdateCommand,
                 "Starts a TC NWK key update now",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_limit_hyphen_beacons_on = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessLimitBeaconsOnOffCommand,
                 "Enables a limit to the max number of outgoing beacons.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_limit_hyphen_beacons_off = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessLimitBeaconsOnOffCommand,
                 "Disables a limit to the max number of outgoing beacons.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_channel_hyphen_mask_clear = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessChannelMaskResetClearAllCommand,
                 "Clears the channel mask used by network find.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_channel_hyphen_mask_reset = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessChannelMaskResetClearAllCommand,
                 "Resets the channel mask back to the app default.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_channel_hyphen_mask_all = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessChannelMaskResetClearAllCommand,
                 "Sets the channel mask to all channels",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_channel_hyphen_mask_add = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessChannelMaskAddOrRemoveCommand,
                 "Add a channel to the mask",
                  "The 802.15.4 chanel to add." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_channel_hyphen_mask_remove = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessChannelMaskAddOrRemoveCommand,
                 "Remove a channel from the mask",
                  "The 802.15.4 chanel to remove." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_endpoint_enable = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessEnableDisableEndpointCommand,
                 "Enables the endpont to receive messages and be discovered",
                  "The endpoint number." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_endpoint_disable = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessEnableDisableEndpointCommand,
                 "Disables the endpont to receive messages and be discovered",
                  "The endpoint number." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_endpoint_status = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessEndpointStatusCommand,
                 "Disables the endpont to receive messages and be discovered",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_endpoint_cluster_hyphen_endpoint_hyphen_index = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessClusterEndpointIndexCommand,
                 "Get cluster endpoint index",
                  "The local endpoint of the cluster." SL_CLI_UNIT_SEPARATOR "The cluster whose index is needed." SL_CLI_UNIT_SEPARATOR "0 for client-side attributes or 1 for server-side attributes." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_radio_on = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessRadioOnOffCommand,
                 "Turns on the radio if it was previously turned off",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_radio_off = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessRadioOnOffCommand,
                 "Turns off the radio so that no messages are sent.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_test_hyphen_harness_set_hyphen_radio_hyphen_power = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessSetRadioPower,
                 "Sets the radio power.",
                  "The radio power to set." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_test_hyphen_harness_add_hyphen_child = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessAddChildCommand,
                 "Adds a child to the child table.",
                  "The shortId of the child device." SL_CLI_UNIT_SEPARATOR "The EUI64 of the child (big endian)." SL_CLI_UNIT_SEPARATOR "The node type of the child device." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_HEX, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_test_hyphen_harness_set_hyphen_compliance_hyphen_revision = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessSetNodeDescriptorComplianceRevision,
                 "Setting a compliance revision for a device such that the device can act as pre-R21 or R21+ for testing purposes. The reason for doing this is because the end device may send a node descriptor request and the hub will respond with the node descriptor response which will include the hubs compliance revision. If the compliance revision of the hub is R21+, only then will the TC link key request be made by the end device.",
                  "The compliance version" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_test_hyphen_harness_set_hyphen_max_hyphen_children = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessSetMaxChildren,
                 "Sets the maximum children supported by the local node.",
                  "The maximum number of children to support" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_test_hyphen_harness_set_hyphen_neighbor_hyphen_table_hyphen_size = \
  SL_CLI_COMMAND(emberAfPluginTestHarnessSetNeighborTableSize,
                 "Sets the neighbor table size.",
                  "The size of the neighbor table" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_network_form = \
  SL_CLI_COMMAND(networkFormCommand,
                 "Form a network on a given channel, with a given TX Power and PAN ID.",
                  "The channel on which to form the network." SL_CLI_UNIT_SEPARATOR "One byte signed value indicating the TX Power that the radio should be set to." SL_CLI_UNIT_SEPARATOR "The PAN ID on which to form the network." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_INT8, SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_network_join = \
  SL_CLI_COMMAND(networkJoinCommand,
                 "Join a network on a given channel, with a given TX Power and PAN ID.",
                  "The channel on which to join the network." SL_CLI_UNIT_SEPARATOR "One byte signed value indicating the TX Power that the radio should be set to." SL_CLI_UNIT_SEPARATOR "The PAN ID on which to join the network." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_INT8, SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_network_pjoin = \
  SL_CLI_COMMAND(networkPermitJoinCommand,
                 "Turn permit joining on for the amount of time indicated.",
                  "A single byte indicating how long the device should have permit joining turn on for. A value of 0xff turns permit join indefinitely." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_network_leave = \
  SL_CLI_COMMAND(networkLeaveCommand,
                 "Leave a network.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_network_rejoin = \
  SL_CLI_COMMAND(networkRejoinCommand,
                 "ReJoin a network.",
                  "Boolean network key availability" SL_CLI_UNIT_SEPARATOR "Channel mask." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_INT32, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_network_rejoin_hyphen_diff_hyphen_device_hyphen_type = \
  SL_CLI_COMMAND(networkRejoinDiffDeviceTypeCommand,
                 "Rejoin an existing network in a secure or insecure manner with a different device type.",
                  "Boolean network key availability" SL_CLI_UNIT_SEPARATOR "Channel mask." SL_CLI_UNIT_SEPARATOR "An enumeration indicating the device type to rejoin as.The stack only accepts EMBER_END_DEVICE and EMBER_SLEEPY_END_DEVICE." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_INT32, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_network_extpanid = \
  SL_CLI_COMMAND(networkExtendedPanIdCommand,
                 "Write the extended pan id for the device.",
                  "extpanid" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_HEX, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_network_isopen = \
  SL_CLI_COMMAND(networkCheckPjoinCommand,
                 "Check network pjoin status",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_network_broad_hyphen_pjoin = \
  SL_CLI_COMMAND(networkPermitJoinCommand,
                 "Permit joining on the network for a given number of seconds AND broadcast a ZDO Mgmt Permit Joining request to all routers.",
                  "A single byte indicating how long the device should have permit joining turn on for. A value of 0xff turns permit join indefinitely." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_find_joinable = \
  SL_CLI_COMMAND(findJoinableNetworkCommand,
                 "findJoinableNetwork",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_find_unused = \
  SL_CLI_COMMAND(findUnusedPanIdCommand,
                 "findUnusedPanId",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_network_change_hyphen_channel = \
  SL_CLI_COMMAND(networkChangeChannelCommand,
                 "Attempts to change device over to a different channel given in the channel argument.",
                  "the channel to change to" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_network_set = \
  SL_CLI_COMMAND(networkSetCommand,
                 "Set the network index used by all future CLI commands.  Before executing a CLI command, the framework will switch to this network.  After the command finishes executing, the framework will switch back to the previous network.  The CLI uses the same network index until the device resets or it is changed through this command.",
                  "index" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_network_init = \
  SL_CLI_COMMAND(networkInitCommand,
                 "Initialize a network; this is a test command used for tc-swap-out testing.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_network_id = \
  SL_CLI_COMMAND(networkIdCommand,
                 "Prints the current Node ID, EUI64, and Pan ID.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_network_change_hyphen_keep_hyphen_alive_hyphen_mode = \
  SL_CLI_COMMAND(changeKeepAliveModeCommand,
                 "Switch between different keep alive modes supported by a router.",
                  "keep alive mode" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_network_timeout_hyphen_option_hyphen_mask = \
  SL_CLI_COMMAND(networkChangeChildTimeoutOptionMaskCommand,
                 "Attempts to change child timeout option mask to filter out undesirable values (e.g. no more than 3 days).",
                  "timeout option mask" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_network_multi_hyphen_phy_hyphen_start = \
  SL_CLI_COMMAND(networkMultiPhyStartCommand,
                 "To start multi phy interface other than native and form the network. The stack uses same PanId as native radio network.",
                  "page" SL_CLI_UNIT_SEPARATOR "channel" SL_CLI_UNIT_SEPARATOR "power" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_INT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_network_multi_hyphen_phy_hyphen_stop = \
  SL_CLI_COMMAND(networkMultiPhyStopCommand,
                 "Terminates the multi phy interface",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_keys_print = \
  SL_CLI_COMMAND(keysPrintCommand,
                 "Print all security keys.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_keys_clear = \
  SL_CLI_COMMAND(keysClearCommand,
                 "Clear all security keys.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_binding_hyphen_table_print = \
  SL_CLI_COMMAND(optionBindingTablePrintCommand,
                 "Prints out the binding table to the command line.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_binding_hyphen_table_clear = \
  SL_CLI_COMMAND(optionBindingTableClearCommand,
                 "Clear the binding table.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_binding_hyphen_table_set = \
  SL_CLI_COMMAND(optionBindingTableSetCommand,
                 "set the binding table",
                  "index" SL_CLI_UNIT_SEPARATOR "cluster" SL_CLI_UNIT_SEPARATOR "localEp" SL_CLI_UNIT_SEPARATOR "remoteEp" SL_CLI_UNIT_SEPARATOR "eui64" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_HEX, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_print_hyphen_rx_hyphen_msgs_enable = \
  SL_CLI_COMMAND(optionPrintRxCommand,
                 "Enable printing of Rx messages",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_print_hyphen_rx_hyphen_msgs_disable = \
  SL_CLI_COMMAND(optionPrintRxCommand,
                 "Disable printing of Rx messages",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_option_register = \
  SL_CLI_COMMAND(optionRegisterCommand,
                 "",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_option_target = \
  SL_CLI_COMMAND(optionDiscoveryTargetCommand,
                 "",
                  "targetId" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_option_disc = \
  SL_CLI_COMMAND(optionDiscoverCommand,
                 "",
                  "profileId" SL_CLI_UNIT_SEPARATOR "clusterId" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_option_edb = \
  SL_CLI_COMMAND(optionEndDeviceBindCommand,
                 "",
                  "endpointId" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_apsretry_on = \
  SL_CLI_COMMAND(optionApsRetryCommand,
                 "",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_apsretry_off = \
  SL_CLI_COMMAND(optionApsRetryCommand,
                 "",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_apsretry_default = \
  SL_CLI_COMMAND(optionApsRetryCommand,
                 "",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_aps_on = \
  SL_CLI_COMMAND(optionApsSecurityCommand,
                 "",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_aps_off = \
  SL_CLI_COMMAND(optionApsSecurityCommand,
                 "",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_security_set_hyphen_allow_hyphen_trust_hyphen_center_hyphen_rejoin_hyphen_using_hyphen_well_hyphen_known_hyphen_key = \
  SL_CLI_COMMAND(optionSecurityAllowTrustCenterRejoinUsingWellKnownKey,
                 "",
                  "bool: allow trust center rejoin using well-known key" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_security_set_hyphen_allow_hyphen_trust_hyphen_center_hyphen_rejoin_hyphen_using_hyphen_well_hyphen_known_hyphen_key_hyphen_timeout = \
  SL_CLI_COMMAND(optionSecurityAllowTrustCenterRejoinUsingWellKnownKeyTimeout,
                 "",
                  "timeout" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_security_set_hyphen_key_hyphen_request_hyphen_policy = \
  SL_CLI_COMMAND(optionSecuritySetKeyRequestPolicy,
                 "",
                  "TC link key request policy" SL_CLI_UNIT_SEPARATOR "App link key request policy" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_changekey_link = \
  SL_CLI_COMMAND(changeKeyCommand,
                 "",
                  "key" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_HEX, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_changekey_network = \
  SL_CLI_COMMAND(changeKeyCommand,
                 "",
                  "key" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_HEX, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_option_link = \
  SL_CLI_COMMAND(optionLinkCommand,
                 "",
                  "index" SL_CLI_UNIT_SEPARATOR "eui64" SL_CLI_UNIT_SEPARATOR "key" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_HEX, SL_CLI_ARG_HEX, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_option_install_hyphen_code = \
  SL_CLI_COMMAND(optionInstallCodeCommand,
                 "",
                  "index" SL_CLI_UNIT_SEPARATOR "eui64" SL_CLI_UNIT_SEPARATOR "installCode" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_HEX, SL_CLI_ARG_HEX, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zdo_route = \
  SL_CLI_COMMAND(zdoRouteRequestCommand,
                 "Send a ZDO route request command to the target.",
                  "target" SL_CLI_UNIT_SEPARATOR "index" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zdo_power = \
  SL_CLI_COMMAND(zdoPowerDescriptorRequestCommand,
                 "Send a ZDO Power Descriptor Request to the target device.",
                  "target" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zdo_mgmt_hyphen_lqi = \
  SL_CLI_COMMAND(zdoMgmtLqiCommand,
                 "Send a ZDO MGMT-LQI (LQI Table) Request to the target device.",
                  "target" SL_CLI_UNIT_SEPARATOR "startIndex" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zdo_mgmt_hyphen_bind = \
  SL_CLI_COMMAND(zdoMgmtBindCommand,
                 "Send a ZDO MGMT-Bind (Binding Table) Request to the target device.",
                  "target" SL_CLI_UNIT_SEPARATOR "startIndex" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zdo_leave = \
  SL_CLI_COMMAND(zdoLeaveRequestCommand,
                 "Send a ZDO Management Leave command to the target device.",
                  "target" SL_CLI_UNIT_SEPARATOR "removeChildren" SL_CLI_UNIT_SEPARATOR "rejoin" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_unbind_group = \
  SL_CLI_COMMAND(zdoUnbindGroupCommand,
                 "Sends an unbind request for a multicast binding to the target device.",
                  "target" SL_CLI_UNIT_SEPARATOR "source eui64" SL_CLI_UNIT_SEPARATOR "source endpoint" SL_CLI_UNIT_SEPARATOR "clusterID" SL_CLI_UNIT_SEPARATOR "groupAddress" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_HEX, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_unbind_unicast = \
  SL_CLI_COMMAND(zdoUnbindUnicastCommand,
                 "Sends an unbind request for a unicast binding to the target device.",
                  "target" SL_CLI_UNIT_SEPARATOR "source eui64" SL_CLI_UNIT_SEPARATOR "source endpoint" SL_CLI_UNIT_SEPARATOR "clusterID" SL_CLI_UNIT_SEPARATOR "destinationEUI64" SL_CLI_UNIT_SEPARATOR "destination endpoint" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_HEX, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT16, SL_CLI_ARG_HEX, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zdo_active = \
  SL_CLI_COMMAND(zdoActiveEpCommand,
                 "Send an active endpoint request to the device with the given short id.",
                  "nodeId" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zdo_bind = \
  SL_CLI_COMMAND(zdoBindCommand,
                 "Send a ZDO Bind command to a device specified in the command arguments.",
                  "destination" SL_CLI_UNIT_SEPARATOR "source endpoint" SL_CLI_UNIT_SEPARATOR "destination endpoint" SL_CLI_UNIT_SEPARATOR "clusterID" SL_CLI_UNIT_SEPARATOR "remoteEUI64" SL_CLI_UNIT_SEPARATOR "destEUI64" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT16, SL_CLI_ARG_HEX, SL_CLI_ARG_HEX, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zdo_node = \
  SL_CLI_COMMAND(zdoNodeCommand,
                 "Sends a node descriptor request to a given target device.",
                  "target" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zdo_match = \
  SL_CLI_COMMAND(zdoMatchCommand,
                 "Sends a matchDescriptorsRequest to the given destination with the given profile.",
                  "nodeId" SL_CLI_UNIT_SEPARATOR "profile" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zdo_simple = \
  SL_CLI_COMMAND(zdoSimpleCommand,
                 "Sends out a simple descriptor request for the short address and endpoint specified.",
                  "dest" SL_CLI_UNIT_SEPARATOR "targetEndpoint" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zdo_ieee = \
  SL_CLI_COMMAND(zdoIeeeAddressRequestCommand,
                 "Request an ieee address based on a given node id.",
                  "nodeId" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zdo_nwk = \
  SL_CLI_COMMAND(zdoNwkAddressRequestCommand,
                 "Sends a network address request for the given IEEE address.",
                  "ieee" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_HEX, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_nwk_hyphen_upd_scan_hyphen_chan_hyphen_mask = \
  SL_CLI_COMMAND(zdoNetworkUpdateScanCommand,
                 "Performs an energy scan on given channel mask.",
                  "targetNodeId" SL_CLI_UNIT_SEPARATOR "scanDuration" SL_CLI_UNIT_SEPARATOR "scanCount" SL_CLI_UNIT_SEPARATOR "channelMask" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT32, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_nwk_hyphen_upd_set = \
  SL_CLI_COMMAND(zdoNetworkUpdateSetCommand,
                 "Broadcasts the ID of the new network manager and active channels.",
                  "nwkMgeId" SL_CLI_UNIT_SEPARATOR "channelMask" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT32, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_nwk_hyphen_upd_scan = \
  SL_CLI_COMMAND(zdoNetworkUpdateScanCommand,
                 "Performs an energy scan.",
                  "targetNodeId" SL_CLI_UNIT_SEPARATOR "scanDuration" SL_CLI_UNIT_SEPARATOR "scanCount" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_nwk_hyphen_upd_chanPg = \
  SL_CLI_COMMAND(zdoNetworkUpdateChannelCommand,
                 "Sends an update channel page req. The stack shall send nwk enhanced update req for non-zero page.",
                  "channel" SL_CLI_UNIT_SEPARATOR "page" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_nwk_hyphen_upd_chan = \
  SL_CLI_COMMAND(zdoNetworkUpdateChannelCommand,
                 "Sends an update channel request.",
                  "channel" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_out_hyphen_cl_hyphen_list_add = \
  SL_CLI_COMMAND(zdoAddClusterCommand,
                 "Add clusters to the known client (out) clusters on this device.",
                  "clusterId" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_out_hyphen_cl_hyphen_list_clear = \
  SL_CLI_COMMAND(zdoClearClusterCommand,
                 "Clear the ZDO list of client (out) clusters.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_in_hyphen_cl_hyphen_list_add = \
  SL_CLI_COMMAND(zdoAddClusterCommand,
                 "Add clusters to the known client (in) clusters on this device.",
                  "clusterId" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_in_hyphen_cl_hyphen_list_clear = \
  SL_CLI_COMMAND(zdoClearClusterCommand,
                 "Clear the ZDO list of client (in) clusters.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_print_attr = \
  SL_CLI_COMMAND(emberAfPrintAttributeTable,
                 "Print attribute.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_print_time = \
  SL_CLI_COMMAND(printTimeCommand,
                 "Print time.",
                  "",
                 {SL_CLI_ARG_END, });


// Create group command tables and structs if cli_groups given
// in template. Group name is suffixed with _group_table for tables
// and group commands are cli_cmd_grp_( group name )
static const sl_cli_command_entry_t address_hyphen_table_group_table[] = {
  { "add", &cli_cmd_address_hyphen_table_add, false },
  { "set", &cli_cmd_address_hyphen_table_set, false },
  { "remove", &cli_cmd_address_hyphen_table_remove, false },
  { "lookup", &cli_cmd_address_hyphen_table_lookup, false },
  { "print", &cli_cmd_address_hyphen_table_print, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_address_hyphen_table = \
  SL_CLI_COMMAND_GROUP(address_hyphen_table_group_table, "");

static const sl_cli_command_entry_t idle_hyphen_sleep_group_table[] = {
  { "status", &cli_cmd_idle_hyphen_sleep_status, false },
  { "force-awake", &cli_cmd_idle_hyphen_sleep_force_hyphen_awake, false },
  { "awake-when-not-joined", &cli_cmd_idle_hyphen_sleep_awake_hyphen_when_hyphen_not_hyphen_joined, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_idle_hyphen_sleep = \
  SL_CLI_COMMAND_GROUP(idle_hyphen_sleep_group_table, "Commands to control idling/sleeping of the device");

static const sl_cli_command_entry_t counters_group_table[] = {
  { "print", &cli_cmd_counters_print, false },
  { "simple-print", &cli_cmd_counters_simple_hyphen_print, false },
  { "clear", &cli_cmd_counters_clear, false },
  { "print-thresholds", &cli_cmd_counters_print_hyphen_thresholds, false },
  { "set-threshold", &cli_cmd_counters_set_hyphen_threshold, false },
  { "reset-thresholds", &cli_cmd_counters_reset_hyphen_thresholds, false },
  { "send-request", &cli_cmd_counters_send_hyphen_request, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_counters = \
  SL_CLI_COMMAND_GROUP(counters_group_table, "counters related commands");

static const sl_cli_command_entry_t counter_group_table[] = {
  { "print-counter-type", &cli_cmd_counter_print_hyphen_counter_hyphen_type, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_counter = \
  SL_CLI_COMMAND_GROUP(counter_group_table, "counter related commands");

static const sl_cli_command_entry_t enable_type_group_table[] = {
  { "stack", &cli_cmd_enable_type_stack, false },
  { "core", &cli_cmd_enable_type_core, false },
  { "app", &cli_cmd_enable_type_app, false },
  { "zcl", &cli_cmd_enable_type_zcl, false },
  { "legacy_af_debug", &cli_cmd_enable_type_legacy_af_debug, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_enable_type = \
  SL_CLI_COMMAND_GROUP(enable_type_group_table, "");

static const sl_cli_command_entry_t zigbee_print_group_table[] = {
  { "enable_type", &cli_cmd_grp_enable_type, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_zigbee_print = \
  SL_CLI_COMMAND_GROUP(zigbee_print_group_table, "");

static const sl_cli_command_entry_t fragmentation_group_table[] = {
  { "set-rx-window-size", &cli_cmd_fragmentation_set_hyphen_rx_hyphen_window_hyphen_size, false },
  { "artificial-block-drop", &cli_cmd_fragmentation_artificial_hyphen_block_hyphen_drop, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_fragmentation = \
  SL_CLI_COMMAND_GROUP(fragmentation_group_table, "fragmentation related commands");

static const sl_cli_command_entry_t cert_hyphen_mangle_group_table[] = {
  { "length", &cli_cmd_cert_hyphen_mangle_length, false },
  { "issuer", &cli_cmd_cert_hyphen_mangle_issuer, false },
  { "corrupt", &cli_cmd_cert_hyphen_mangle_corrupt, false },
  { "change-byte", &cli_cmd_cert_hyphen_mangle_change_hyphen_byte, false },
  { "subject", &cli_cmd_cert_hyphen_mangle_subject, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_cert_hyphen_mangle = \
  SL_CLI_COMMAND_GROUP(cert_hyphen_mangle_group_table, "cert-mangle related commands");

static const sl_cli_command_entry_t key_hyphen_establishment_group_table[] = {
  { "start", &cli_cmd_key_hyphen_establishment_start, false },
  { "interpan", &cli_cmd_key_hyphen_establishment_interpan, false },
  { "normal-mode", &cli_cmd_key_hyphen_establishment_normal_hyphen_mode, false },
  { "no-resources", &cli_cmd_key_hyphen_establishment_no_hyphen_resources, false },
  { "out-of-sequence", &cli_cmd_key_hyphen_establishment_out_hyphen_of_hyphen_sequence, false },
  { "timeout", &cli_cmd_key_hyphen_establishment_timeout, false },
  { "delay-cbke", &cli_cmd_key_hyphen_establishment_delay_hyphen_cbke, false },
  { "default-resp", &cli_cmd_key_hyphen_establishment_default_hyphen_resp, false },
  { "new-key-policy", &cli_cmd_key_hyphen_establishment_new_hyphen_key_hyphen_policy, false },
  { "reset-aps-fc", &cli_cmd_key_hyphen_establishment_reset_hyphen_aps_hyphen_fc, false },
  { "adv-aps-fc", &cli_cmd_key_hyphen_establishment_adv_hyphen_aps_hyphen_fc, false },
  { "suite", &cli_cmd_key_hyphen_establishment_suite, false },
  { "set-available-suite", &cli_cmd_key_hyphen_establishment_set_hyphen_available_hyphen_suite, false },
  { "key-mangle", &cli_cmd_key_hyphen_establishment_key_hyphen_mangle, false },
  { "cert-mangle", &cli_cmd_grp_cert_hyphen_mangle, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_key_hyphen_establishment = \
  SL_CLI_COMMAND_GROUP(key_hyphen_establishment_group_table, "key-establishment related commands");

static const sl_cli_command_entry_t find_group_table[] = {
  { "mask", &cli_cmd_find_mask, false },
  { "mode", &cli_cmd_find_mode, false },
  { "print", &cli_cmd_find_print, false },
  { "joinable", &cli_cmd_find_joinable, false },
  { "unused", &cli_cmd_find_unused, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_find = \
  SL_CLI_COMMAND_GROUP(find_group_table, "find related commands");

static const sl_cli_command_entry_t network_group_table[] = {
  { "form", &cli_cmd_network_form, false },
  { "join", &cli_cmd_network_join, false },
  { "pjoin", &cli_cmd_network_pjoin, false },
  { "leave", &cli_cmd_network_leave, false },
  { "rejoin", &cli_cmd_network_rejoin, false },
  { "rejoin-diff-device-type", &cli_cmd_network_rejoin_hyphen_diff_hyphen_device_hyphen_type, false },
  { "extpanid", &cli_cmd_network_extpanid, false },
  { "isopen", &cli_cmd_network_isopen, false },
  { "broad-pjoin", &cli_cmd_network_broad_hyphen_pjoin, false },
  { "change-channel", &cli_cmd_network_change_hyphen_channel, false },
  { "set", &cli_cmd_network_set, false },
  { "init", &cli_cmd_network_init, false },
  { "id", &cli_cmd_network_id, false },
  { "change-keep-alive-mode", &cli_cmd_network_change_hyphen_keep_hyphen_alive_hyphen_mode, false },
  { "timeout-option-mask", &cli_cmd_network_timeout_hyphen_option_hyphen_mask, false },
  { "multi-phy-start", &cli_cmd_network_multi_hyphen_phy_hyphen_start, false },
  { "multi-phy-stop", &cli_cmd_network_multi_hyphen_phy_hyphen_stop, false },
  { "find", &cli_cmd_grp_find, false },
  { "find", &cli_cmd_grp_find, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_network = \
  SL_CLI_COMMAND_GROUP(network_group_table, "network related commands");

static const sl_cli_command_entry_t smart_hyphen_energy_hyphen_registration_group_table[] = {
  { "set-period", &cli_cmd_smart_hyphen_energy_hyphen_registration_set_hyphen_period, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_smart_hyphen_energy_hyphen_registration = \
  SL_CLI_COMMAND_GROUP(smart_hyphen_energy_hyphen_registration_group_table, "smart-energy-registration related commands");

static const sl_cli_command_entry_t aps_hyphen_sec_hyphen_for_hyphen_cluster_group_table[] = {
  { "on", &cli_cmd_aps_hyphen_sec_hyphen_for_hyphen_cluster_on, false },
  { "off", &cli_cmd_aps_hyphen_sec_hyphen_for_hyphen_cluster_off, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_aps_hyphen_sec_hyphen_for_hyphen_cluster = \
  SL_CLI_COMMAND_GROUP(aps_hyphen_sec_hyphen_for_hyphen_cluster_group_table, "aps-sec-for-cluster related commands");

static const sl_cli_command_entry_t attr_group_table[] = {
  { "options", &cli_cmd_attr_options, false },
  { "set-dest", &cli_cmd_attr_set_hyphen_dest, false },
  { "start-test", &cli_cmd_attr_start_hyphen_test, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_attr = \
  SL_CLI_COMMAND_GROUP(attr_group_table, "attr related commands");

static const sl_cli_command_entry_t registration_group_table[] = {
  { "on", &cli_cmd_registration_on, false },
  { "off", &cli_cmd_registration_off, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_registration = \
  SL_CLI_COMMAND_GROUP(registration_group_table, "registration related commands");

static const sl_cli_command_entry_t price_group_table[] = {
  { "send-new-fields", &cli_cmd_price_send_hyphen_new_hyphen_fields, false },
  { "send-se10-fields", &cli_cmd_price_send_hyphen_se10_hyphen_fields, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_price = \
  SL_CLI_COMMAND_GROUP(price_group_table, "price related commands");

static const sl_cli_command_entry_t tc_hyphen_keepalive_group_table[] = {
  { "send", &cli_cmd_tc_hyphen_keepalive_send, false },
  { "start", &cli_cmd_tc_hyphen_keepalive_start, false },
  { "stop", &cli_cmd_tc_hyphen_keepalive_stop, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_tc_hyphen_keepalive = \
  SL_CLI_COMMAND_GROUP(tc_hyphen_keepalive_group_table, "tc-keepalive related commands");

static const sl_cli_command_entry_t ota_group_table[] = {
  { "image-mangle", &cli_cmd_ota_image_hyphen_mangle, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_ota = \
  SL_CLI_COMMAND_GROUP(ota_group_table, "ota related commands");

static const sl_cli_command_entry_t key_hyphen_update_group_table[] = {
  { "unicast", &cli_cmd_key_hyphen_update_unicast, false },
  { "broadcast", &cli_cmd_key_hyphen_update_broadcast, false },
  { "now", &cli_cmd_key_hyphen_update_now, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_key_hyphen_update = \
  SL_CLI_COMMAND_GROUP(key_hyphen_update_group_table, "key-update related commands");

static const sl_cli_command_entry_t limit_hyphen_beacons_group_table[] = {
  { "on", &cli_cmd_limit_hyphen_beacons_on, false },
  { "off", &cli_cmd_limit_hyphen_beacons_off, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_limit_hyphen_beacons = \
  SL_CLI_COMMAND_GROUP(limit_hyphen_beacons_group_table, "limit-beacons related commands");

static const sl_cli_command_entry_t stack_group_table[] = {
  { "limit-beacons", &cli_cmd_grp_limit_hyphen_beacons, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_stack = \
  SL_CLI_COMMAND_GROUP(stack_group_table, "stack related commands");

static const sl_cli_command_entry_t channel_hyphen_mask_group_table[] = {
  { "clear", &cli_cmd_channel_hyphen_mask_clear, false },
  { "reset", &cli_cmd_channel_hyphen_mask_reset, false },
  { "all", &cli_cmd_channel_hyphen_mask_all, false },
  { "add", &cli_cmd_channel_hyphen_mask_add, false },
  { "remove", &cli_cmd_channel_hyphen_mask_remove, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_channel_hyphen_mask = \
  SL_CLI_COMMAND_GROUP(channel_hyphen_mask_group_table, "channel-mask related commands");

static const sl_cli_command_entry_t endpoint_group_table[] = {
  { "enable", &cli_cmd_endpoint_enable, false },
  { "disable", &cli_cmd_endpoint_disable, false },
  { "status", &cli_cmd_endpoint_status, false },
  { "cluster-endpoint-index", &cli_cmd_endpoint_cluster_hyphen_endpoint_hyphen_index, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_endpoint = \
  SL_CLI_COMMAND_GROUP(endpoint_group_table, "endpoint related commands");

static const sl_cli_command_entry_t radio_group_table[] = {
  { "on", &cli_cmd_radio_on, false },
  { "off", &cli_cmd_radio_off, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_radio = \
  SL_CLI_COMMAND_GROUP(radio_group_table, "radio related commands");

static const sl_cli_command_entry_t test_hyphen_harness_group_table[] = {
  { "status", &cli_cmd_test_hyphen_harness_status, false },
  { "concentrator-start", &cli_cmd_test_hyphen_harness_concentrator_hyphen_start, false },
  { "concentrator-stop", &cli_cmd_test_hyphen_harness_concentrator_hyphen_stop, false },
  { "set-radio-power", &cli_cmd_test_hyphen_harness_set_hyphen_radio_hyphen_power, false },
  { "add-child", &cli_cmd_test_hyphen_harness_add_hyphen_child, false },
  { "set-compliance-revision", &cli_cmd_test_hyphen_harness_set_hyphen_compliance_hyphen_revision, false },
  { "set-max-children", &cli_cmd_test_hyphen_harness_set_hyphen_max_hyphen_children, false },
  { "set-neighbor-table-size", &cli_cmd_test_hyphen_harness_set_hyphen_neighbor_hyphen_table_hyphen_size, false },
  { "aps-sec-for-cluster", &cli_cmd_grp_aps_hyphen_sec_hyphen_for_hyphen_cluster, false },
  { "attr", &cli_cmd_grp_attr, false },
  { "registration", &cli_cmd_grp_registration, false },
  { "key-establishment", &cli_cmd_grp_key_hyphen_establishment, false },
  { "price", &cli_cmd_grp_price, false },
  { "tc-keepalive", &cli_cmd_grp_tc_hyphen_keepalive, false },
  { "ota", &cli_cmd_grp_ota, false },
  { "key-update", &cli_cmd_grp_key_hyphen_update, false },
  { "stack", &cli_cmd_grp_stack, false },
  { "channel-mask", &cli_cmd_grp_channel_hyphen_mask, false },
  { "endpoint", &cli_cmd_grp_endpoint, false },
  { "radio", &cli_cmd_grp_radio, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_test_hyphen_harness = \
  SL_CLI_COMMAND_GROUP(test_hyphen_harness_group_table, "test-harness related commands");

static const sl_cli_command_entry_t plugin_group_table[] = {
  { "address-table", &cli_cmd_grp_address_hyphen_table, false },
  { "idle-sleep", &cli_cmd_grp_idle_hyphen_sleep, false },
  { "counters", &cli_cmd_grp_counters, false },
  { "counter", &cli_cmd_grp_counter, false },
  { "fragmentation", &cli_cmd_grp_fragmentation, false },
  { "key-establishment", &cli_cmd_grp_key_hyphen_establishment, false },
  { "smart-energy-registration", &cli_cmd_grp_smart_hyphen_energy_hyphen_registration, false },
  { "test-harness", &cli_cmd_grp_test_hyphen_harness, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_plugin = \
  SL_CLI_COMMAND_GROUP(plugin_group_table, "");

static const sl_cli_command_entry_t keys_group_table[] = {
  { "print", &cli_cmd_keys_print, false },
  { "clear", &cli_cmd_keys_clear, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_keys = \
  SL_CLI_COMMAND_GROUP(keys_group_table, "Security keys related commands.");

static const sl_cli_command_entry_t binding_hyphen_table_group_table[] = {
  { "print", &cli_cmd_binding_hyphen_table_print, false },
  { "clear", &cli_cmd_binding_hyphen_table_clear, false },
  { "set", &cli_cmd_binding_hyphen_table_set, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_binding_hyphen_table = \
  SL_CLI_COMMAND_GROUP(binding_hyphen_table_group_table, "Binding table related commands.");

static const sl_cli_command_entry_t print_hyphen_rx_hyphen_msgs_group_table[] = {
  { "enable", &cli_cmd_print_hyphen_rx_hyphen_msgs_enable, false },
  { "disable", &cli_cmd_print_hyphen_rx_hyphen_msgs_disable, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_print_hyphen_rx_hyphen_msgs = \
  SL_CLI_COMMAND_GROUP(print_hyphen_rx_hyphen_msgs_group_table, "Enable/Disable printing of Rx messages");

static const sl_cli_command_entry_t apsretry_group_table[] = {
  { "on", &cli_cmd_apsretry_on, false },
  { "off", &cli_cmd_apsretry_off, false },
  { "default", &cli_cmd_apsretry_default, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_apsretry = \
  SL_CLI_COMMAND_GROUP(apsretry_group_table, "Security related commands.");

static const sl_cli_command_entry_t aps_group_table[] = {
  { "on", &cli_cmd_aps_on, false },
  { "off", &cli_cmd_aps_off, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_aps = \
  SL_CLI_COMMAND_GROUP(aps_group_table, "Security aps related commands.");

static const sl_cli_command_entry_t security_group_table[] = {
  { "set-allow-trust-center-rejoin-using-well-known-key", &cli_cmd_security_set_hyphen_allow_hyphen_trust_hyphen_center_hyphen_rejoin_hyphen_using_hyphen_well_hyphen_known_hyphen_key, false },
  { "set-allow-trust-center-rejoin-using-well-known-key-timeout", &cli_cmd_security_set_hyphen_allow_hyphen_trust_hyphen_center_hyphen_rejoin_hyphen_using_hyphen_well_hyphen_known_hyphen_key_hyphen_timeout, false },
  { "set-key-request-policy", &cli_cmd_security_set_hyphen_key_hyphen_request_hyphen_policy, false },
  { "aps", &cli_cmd_grp_aps, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_security = \
  SL_CLI_COMMAND_GROUP(security_group_table, "Security related commands.");

static const sl_cli_command_entry_t option_group_table[] = {
  { "register", &cli_cmd_option_register, false },
  { "target", &cli_cmd_option_target, false },
  { "disc", &cli_cmd_option_disc, false },
  { "edb", &cli_cmd_option_edb, false },
  { "link", &cli_cmd_option_link, false },
  { "install-code", &cli_cmd_option_install_hyphen_code, false },
  { "binding-table", &cli_cmd_grp_binding_hyphen_table, false },
  { "print-rx-msgs", &cli_cmd_grp_print_hyphen_rx_hyphen_msgs, false },
  { "apsretry", &cli_cmd_grp_apsretry, false },
  { "security", &cli_cmd_grp_security, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_option = \
  SL_CLI_COMMAND_GROUP(option_group_table, "Option related commands.");

static const sl_cli_command_entry_t changekey_group_table[] = {
  { "link", &cli_cmd_changekey_link, false },
  { "network", &cli_cmd_changekey_network, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_changekey = \
  SL_CLI_COMMAND_GROUP(changekey_group_table, "changekey related commands.");

static const sl_cli_command_entry_t unbind_group_table[] = {
  { "group", &cli_cmd_unbind_group, false },
  { "unicast", &cli_cmd_unbind_unicast, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_unbind = \
  SL_CLI_COMMAND_GROUP(unbind_group_table, "Zdo unbind related commands.");

static const sl_cli_command_entry_t nwk_hyphen_upd_group_table[] = {
  { "scan-chan-mask", &cli_cmd_nwk_hyphen_upd_scan_hyphen_chan_hyphen_mask, false },
  { "set", &cli_cmd_nwk_hyphen_upd_set, false },
  { "scan", &cli_cmd_nwk_hyphen_upd_scan, false },
  { "chanPg", &cli_cmd_nwk_hyphen_upd_chanPg, false },
  { "chan", &cli_cmd_nwk_hyphen_upd_chan, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_nwk_hyphen_upd = \
  SL_CLI_COMMAND_GROUP(nwk_hyphen_upd_group_table, "Zdo nwk-upd related commands.");

static const sl_cli_command_entry_t out_hyphen_cl_hyphen_list_group_table[] = {
  { "add", &cli_cmd_out_hyphen_cl_hyphen_list_add, false },
  { "clear", &cli_cmd_out_hyphen_cl_hyphen_list_clear, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_out_hyphen_cl_hyphen_list = \
  SL_CLI_COMMAND_GROUP(out_hyphen_cl_hyphen_list_group_table, "Zdo out-cl-list related commands.");

static const sl_cli_command_entry_t in_hyphen_cl_hyphen_list_group_table[] = {
  { "add", &cli_cmd_in_hyphen_cl_hyphen_list_add, false },
  { "clear", &cli_cmd_in_hyphen_cl_hyphen_list_clear, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_in_hyphen_cl_hyphen_list = \
  SL_CLI_COMMAND_GROUP(in_hyphen_cl_hyphen_list_group_table, "Zdo in-cl-list related commands.");

static const sl_cli_command_entry_t zdo_group_table[] = {
  { "route", &cli_cmd_zdo_route, false },
  { "power", &cli_cmd_zdo_power, false },
  { "mgmt-lqi", &cli_cmd_zdo_mgmt_hyphen_lqi, false },
  { "mgmt-bind", &cli_cmd_zdo_mgmt_hyphen_bind, false },
  { "leave", &cli_cmd_zdo_leave, false },
  { "active", &cli_cmd_zdo_active, false },
  { "bind", &cli_cmd_zdo_bind, false },
  { "node", &cli_cmd_zdo_node, false },
  { "match", &cli_cmd_zdo_match, false },
  { "simple", &cli_cmd_zdo_simple, false },
  { "ieee", &cli_cmd_zdo_ieee, false },
  { "nwk", &cli_cmd_zdo_nwk, false },
  { "unbind", &cli_cmd_grp_unbind, false },
  { "nwk-upd", &cli_cmd_grp_nwk_hyphen_upd, false },
  { "out-cl-list", &cli_cmd_grp_out_hyphen_cl_hyphen_list, false },
  { "in-cl-list", &cli_cmd_grp_in_hyphen_cl_hyphen_list, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_zdo = \
  SL_CLI_COMMAND_GROUP(zdo_group_table, "Zdo related commands.");

static const sl_cli_command_entry_t print_group_table[] = {
  { "attr", &cli_cmd_print_attr, false },
  { "time", &cli_cmd_print_time, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_print = \
  SL_CLI_COMMAND_GROUP(print_group_table, "print related commands.");

// Create root command table
const sl_cli_command_entry_t sl_cli_default_command_table[] = {
  { "info", &cli_cmd__info, false },
  { "libs", &cli_cmd__libs, false },
  { "bsend", &cli_cmd__bsend, false },
  { "send", &cli_cmd__send, false },
  { "read", &cli_cmd__read, false },
  { "write", &cli_cmd__write, false },
  { "reset", &cli_cmd__reset, false },
  { "raw", &cli_cmd__raw, false },
  { "send_multicast", &cli_cmd__send_multicast, false },
  { "send-using-multicast-binding", &cli_cmd__send_hyphen_using_hyphen_multicast_hyphen_binding, false },
  { "timesync", &cli_cmd__timesync, false },
  { "zigbee_print", &cli_cmd_grp_zigbee_print, false },
  { "network", &cli_cmd_grp_network, false },
  { "plugin", &cli_cmd_grp_plugin, false },
  { "network", &cli_cmd_grp_network, false },
  { "net", &cli_cmd_grp_network, true },
  { "keys", &cli_cmd_grp_keys, false },
  { "option", &cli_cmd_grp_option, false },
  { "opt", &cli_cmd_grp_option, true },
  { "plugin", &cli_cmd_grp_plugin, false },
  { "plug", &cli_cmd_grp_plugin, true },
  { "changekey", &cli_cmd_grp_changekey, false },
  { "changek", &cli_cmd_grp_changekey, true },
  { "zdo", &cli_cmd_grp_zdo, false },
  { "print", &cli_cmd_grp_print, false },
  { NULL, NULL, false },
};


#ifdef __cplusplus
}
#endif
