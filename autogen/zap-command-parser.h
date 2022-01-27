/***************************************************************************//**
 * @file  zap-command-parser.h
 * @brief This file contains a set of functions declarations that are called in
 * zap-command-parser.c
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

bool emberAfKeyEstablishmentClusterConfirmKeyDataResponseCallback( /* TYPE WARNING: Smac defaults to */ uint8_t * secureMessageAuthenticationCode );

bool emberAfKeyEstablishmentClusterEphemeralDataResponseCallback( /* TYPE WARNING: EphemeralData defaults to */ uint8_t * ephemeralData );

bool emberAfKeyEstablishmentClusterInitiateKeyEstablishmentResponseCallback( uint16_t requestedKeyEstablishmentSuite ,  uint8_t ephemeralDataGenerateTime ,  uint8_t confirmKeyGenerateTime ,  /* TYPE WARNING: Identity defaults to */ uint8_t * identity );

bool emberAfKeyEstablishmentClusterTerminateKeyEstablishmentCallback( uint8_t statusCode ,  uint8_t waitTime ,  uint16_t keyEstablishmentSuite );

bool emberAfKeyEstablishmentClusterConfirmKeyDataRequestCallback( /* TYPE WARNING: Smac defaults to */ uint8_t * secureMessageAuthenticationCode );

bool emberAfKeyEstablishmentClusterEphemeralDataRequestCallback( /* TYPE WARNING: EphemeralData defaults to */ uint8_t * ephemeralData );

bool emberAfKeyEstablishmentClusterInitiateKeyEstablishmentRequestCallback( uint16_t keyEstablishmentSuite ,  uint8_t ephemeralDataGenerateTime ,  uint8_t confirmKeyGenerateTime ,  /* TYPE WARNING: Identity defaults to */ uint8_t * identity );

bool emberAfKeyEstablishmentClusterTerminateKeyEstablishmentCallback( uint8_t statusCode ,  uint8_t waitTime ,  uint16_t keyEstablishmentSuite );

