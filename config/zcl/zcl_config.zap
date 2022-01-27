{
  "featureLevel": 63,
  "creator": "zap",
  "keyValuePairs": [
    {
      "key": "Default response policy",
      "value": "always"
    },
    {
      "key": "Manufacturing code",
      "value": "0x1002"
    },
    {
      "key": "Support command discovery",
      "value": "1"
    },
    {
      "key": "commandDiscovery",
      "value": "1"
    },
    {
      "key": "defaultResponsePolicy",
      "value": "always"
    },
    {
      "key": "ideProjectPath",
      "value": "file_3A_2FC_3A_2FUsers_2FIain_2520Macleod_2Fcode_2FSXtend_2FZSERouter_2FZSERouter.slcp"
    },
    {
      "key": "manufacturerCodes",
      "value": "0x1002"
    }
  ],
  "package": [
    {
      "pathRelativity": "relativeToZap",
      "path": "..\\..\\..\\..\\..\\..\\..\\SiliconLabs\\SimplicityStudio\\v5\\developer\\sdks\\gecko_sdk_suite\\v3.3\\app\\zcl\\zcl-zap.json",
      "version": "Zigbee Silabs ZCL data",
      "type": "zcl-properties"
    },
    {
      "pathRelativity": "relativeToZap",
      "path": "..\\..\\..\\..\\..\\..\\..\\SiliconLabs\\SimplicityStudio\\v5\\developer\\sdks\\gecko_sdk_suite\\v3.3\\protocol\\zigbee\\app\\framework\\gen-template\\gen-templates.json",
      "version": "zigbee-v0",
      "type": "gen-templates-json"
    }
  ],
  "endpointTypes": [
    {
      "name": "Primary",
      "deviceTypeName": null,
      "deviceTypeCode": null,
      "deviceTypeProfileId": null,
      "clusters": []
    },
    {
      "name": "Anonymous Endpoint Type",
      "deviceTypeName": "SE-rangeextender",
      "deviceTypeCode": 8,
      "deviceTypeProfileId": 265,
      "clusters": [
        {
          "name": "Basic",
          "code": 0,
          "mfgCode": null,
          "define": "BASIC_CLUSTER",
          "side": "client",
          "enabled": 0,
          "commands": [],
          "attributes": [
            {
              "name": "cluster revision",
              "code": 65533,
              "mfgCode": null,
              "side": "client",
              "included": 1,
              "storageOption": "RAM",
              "singleton": 1,
              "bounded": 0,
              "defaultValue": "3",
              "reportable": 0,
              "minInterval": 1,
              "maxInterval": 65534,
              "reportableChange": 0
            }
          ]
        },
        {
          "name": "Basic",
          "code": 0,
          "mfgCode": null,
          "define": "BASIC_CLUSTER",
          "side": "server",
          "enabled": 1,
          "commands": [],
          "attributes": [
            {
              "name": "ZCL version",
              "code": 0,
              "mfgCode": null,
              "side": "server",
              "included": 1,
              "storageOption": "RAM",
              "singleton": 1,
              "bounded": 0,
              "defaultValue": "0x08",
              "reportable": 0,
              "minInterval": 1,
              "maxInterval": 65534,
              "reportableChange": 0
            },
            {
              "name": "application version",
              "code": 1,
              "mfgCode": null,
              "side": "server",
              "included": 1,
              "storageOption": "RAM",
              "singleton": 0,
              "bounded": 0,
              "defaultValue": "0x00",
              "reportable": 0,
              "minInterval": 1,
              "maxInterval": 65534,
              "reportableChange": 0
            },
            {
              "name": "model identifier",
              "code": 5,
              "mfgCode": null,
              "side": "server",
              "included": 1,
              "storageOption": "RAM",
              "singleton": 1,
              "bounded": 0,
              "defaultValue": "\"RPRo\"",
              "reportable": 0,
              "minInterval": 1,
              "maxInterval": 65534,
              "reportableChange": 0
            },
            {
              "name": "power source",
              "code": 7,
              "mfgCode": null,
              "side": "server",
              "included": 1,
              "storageOption": "RAM",
              "singleton": 1,
              "bounded": 0,
              "defaultValue": "0x00",
              "reportable": 0,
              "minInterval": 1,
              "maxInterval": 65534,
              "reportableChange": 0
            },
            {
              "name": "cluster revision",
              "code": 65533,
              "mfgCode": null,
              "side": "server",
              "included": 1,
              "storageOption": "RAM",
              "singleton": 1,
              "bounded": 0,
              "defaultValue": "3",
              "reportable": 0,
              "minInterval": 1,
              "maxInterval": 65534,
              "reportableChange": 0
            }
          ]
        },
        {
          "name": "Identify",
          "code": 3,
          "mfgCode": null,
          "define": "IDENTIFY_CLUSTER",
          "side": "client",
          "enabled": 0,
          "commands": [
            {
              "name": "Identify",
              "code": 0,
              "mfgCode": null,
              "source": "client",
              "incoming": 0,
              "outgoing": 1
            },
            {
              "name": "IdentifyQuery",
              "code": 1,
              "mfgCode": null,
              "source": "client",
              "incoming": 0,
              "outgoing": 1
            }
          ],
          "attributes": [
            {
              "name": "cluster revision",
              "code": 65533,
              "mfgCode": null,
              "side": "client",
              "included": 1,
              "storageOption": "RAM",
              "singleton": 0,
              "bounded": 0,
              "defaultValue": "2",
              "reportable": 0,
              "minInterval": 1,
              "maxInterval": 65534,
              "reportableChange": 0
            }
          ]
        },
        {
          "name": "Identify",
          "code": 3,
          "mfgCode": null,
          "define": "IDENTIFY_CLUSTER",
          "side": "server",
          "enabled": 1,
          "commands": [
            {
              "name": "IdentifyQueryResponse",
              "code": 0,
              "mfgCode": null,
              "source": "server",
              "incoming": 1,
              "outgoing": 0
            }
          ],
          "attributes": [
            {
              "name": "identify time",
              "code": 0,
              "mfgCode": null,
              "side": "server",
              "included": 1,
              "storageOption": "RAM",
              "singleton": 0,
              "bounded": 0,
              "defaultValue": "0x0000",
              "reportable": 0,
              "minInterval": 1,
              "maxInterval": 65534,
              "reportableChange": 0
            },
            {
              "name": "cluster revision",
              "code": 65533,
              "mfgCode": null,
              "side": "server",
              "included": 1,
              "storageOption": "RAM",
              "singleton": 0,
              "bounded": 0,
              "defaultValue": "2",
              "reportable": 0,
              "minInterval": 1,
              "maxInterval": 65534,
              "reportableChange": 0
            }
          ]
        },
        {
          "name": "Time",
          "code": 10,
          "mfgCode": null,
          "define": "TIME_CLUSTER",
          "side": "client",
          "enabled": 0,
          "commands": [],
          "attributes": [
            {
              "name": "cluster revision",
              "code": 65533,
              "mfgCode": null,
              "side": "client",
              "included": 1,
              "storageOption": "RAM",
              "singleton": 1,
              "bounded": 0,
              "defaultValue": "2",
              "reportable": 0,
              "minInterval": 1,
              "maxInterval": 65534,
              "reportableChange": 0
            }
          ]
        },
        {
          "name": "Time",
          "code": 10,
          "mfgCode": null,
          "define": "TIME_CLUSTER",
          "side": "server",
          "enabled": 1,
          "commands": [],
          "attributes": [
            {
              "name": "time",
              "code": 0,
              "mfgCode": null,
              "side": "server",
              "included": 1,
              "storageOption": "RAM",
              "singleton": 1,
              "bounded": 0,
              "defaultValue": "",
              "reportable": 0,
              "minInterval": 1,
              "maxInterval": 65534,
              "reportableChange": 0
            },
            {
              "name": "time status",
              "code": 1,
              "mfgCode": null,
              "side": "server",
              "included": 1,
              "storageOption": "RAM",
              "singleton": 1,
              "bounded": 0,
              "defaultValue": "0x00",
              "reportable": 0,
              "minInterval": 1,
              "maxInterval": 65534,
              "reportableChange": 0
            },
            {
              "name": "cluster revision",
              "code": 65533,
              "mfgCode": null,
              "side": "server",
              "included": 1,
              "storageOption": "RAM",
              "singleton": 1,
              "bounded": 0,
              "defaultValue": "2",
              "reportable": 0,
              "minInterval": 1,
              "maxInterval": 65534,
              "reportableChange": 0
            }
          ]
        },
        {
          "name": "Keep-Alive",
          "code": 37,
          "mfgCode": null,
          "define": "KEEPALIVE_CLUSTER",
          "side": "client",
          "enabled": 0,
          "commands": [],
          "attributes": [
            {
              "name": "cluster revision",
              "code": 65533,
              "mfgCode": null,
              "side": "client",
              "included": 1,
              "storageOption": "RAM",
              "singleton": 1,
              "bounded": 0,
              "defaultValue": "0x0001",
              "reportable": 0,
              "minInterval": 1,
              "maxInterval": 65534,
              "reportableChange": 0
            }
          ]
        },
        {
          "name": "Keep-Alive",
          "code": 37,
          "mfgCode": null,
          "define": "KEEPALIVE_CLUSTER",
          "side": "server",
          "enabled": 1,
          "commands": [],
          "attributes": [
            {
              "name": "Keep-Alive Base",
              "code": 0,
              "mfgCode": null,
              "side": "server",
              "included": 1,
              "storageOption": "RAM",
              "singleton": 1,
              "bounded": 0,
              "defaultValue": "1",
              "reportable": 0,
              "minInterval": 1,
              "maxInterval": 65534,
              "reportableChange": 0
            },
            {
              "name": "Keep-Alive Jitter",
              "code": 1,
              "mfgCode": null,
              "side": "server",
              "included": 1,
              "storageOption": "RAM",
              "singleton": 1,
              "bounded": 0,
              "defaultValue": "60",
              "reportable": 0,
              "minInterval": 1,
              "maxInterval": 65534,
              "reportableChange": 0
            },
            {
              "name": "cluster revision",
              "code": 65533,
              "mfgCode": null,
              "side": "server",
              "included": 1,
              "storageOption": "RAM",
              "singleton": 1,
              "bounded": 0,
              "defaultValue": "0x0001",
              "reportable": 0,
              "minInterval": 1,
              "maxInterval": 65534,
              "reportableChange": 0
            }
          ]
        },
        {
          "name": "Key Establishment",
          "code": 2048,
          "mfgCode": null,
          "define": "KEY_ESTABLISHMENT_CLUSTER",
          "side": "client",
          "enabled": 1,
          "commands": [
            {
              "name": "InitiateKeyEstablishmentRequest",
              "code": 0,
              "mfgCode": null,
              "source": "client",
              "incoming": 1,
              "outgoing": 1
            },
            {
              "name": "EphemeralDataRequest",
              "code": 1,
              "mfgCode": null,
              "source": "client",
              "incoming": 1,
              "outgoing": 1
            },
            {
              "name": "ConfirmKeyDataRequest",
              "code": 2,
              "mfgCode": null,
              "source": "client",
              "incoming": 1,
              "outgoing": 1
            }
          ],
          "attributes": [
            {
              "name": "key establishment suite (client)",
              "code": 0,
              "mfgCode": null,
              "side": "client",
              "included": 1,
              "storageOption": "RAM",
              "singleton": 1,
              "bounded": 0,
              "defaultValue": "0x0000",
              "reportable": 0,
              "minInterval": 1,
              "maxInterval": 65534,
              "reportableChange": 0
            },
            {
              "name": "cluster revision",
              "code": 65533,
              "mfgCode": null,
              "side": "client",
              "included": 1,
              "storageOption": "RAM",
              "singleton": 1,
              "bounded": 0,
              "defaultValue": "2",
              "reportable": 0,
              "minInterval": 1,
              "maxInterval": 65534,
              "reportableChange": 0
            }
          ]
        },
        {
          "name": "Key Establishment",
          "code": 2048,
          "mfgCode": null,
          "define": "KEY_ESTABLISHMENT_CLUSTER",
          "side": "either",
          "enabled": 0,
          "commands": [
            {
              "name": "TerminateKeyEstablishment",
              "code": 3,
              "mfgCode": null,
              "source": "either",
              "incoming": 1,
              "outgoing": 0
            }
          ],
          "attributes": []
        },
        {
          "name": "Key Establishment",
          "code": 2048,
          "mfgCode": null,
          "define": "KEY_ESTABLISHMENT_CLUSTER",
          "side": "server",
          "enabled": 1,
          "commands": [
            {
              "name": "InitiateKeyEstablishmentResponse",
              "code": 0,
              "mfgCode": null,
              "source": "server",
              "incoming": 1,
              "outgoing": 1
            },
            {
              "name": "EphemeralDataResponse",
              "code": 1,
              "mfgCode": null,
              "source": "server",
              "incoming": 1,
              "outgoing": 1
            },
            {
              "name": "ConfirmKeyDataResponse",
              "code": 2,
              "mfgCode": null,
              "source": "server",
              "incoming": 1,
              "outgoing": 1
            }
          ],
          "attributes": [
            {
              "name": "key establishment suite (server)",
              "code": 0,
              "mfgCode": null,
              "side": "server",
              "included": 1,
              "storageOption": "RAM",
              "singleton": 1,
              "bounded": 0,
              "defaultValue": "0x0000",
              "reportable": 0,
              "minInterval": 1,
              "maxInterval": 65534,
              "reportableChange": 0
            },
            {
              "name": "cluster revision",
              "code": 65533,
              "mfgCode": null,
              "side": "server",
              "included": 1,
              "storageOption": "RAM",
              "singleton": 1,
              "bounded": 0,
              "defaultValue": "2",
              "reportable": 0,
              "minInterval": 1,
              "maxInterval": 65534,
              "reportableChange": 0
            }
          ]
        }
      ]
    }
  ],
  "endpoints": [
    {
      "endpointTypeName": "Anonymous Endpoint Type",
      "endpointTypeIndex": 1,
      "profileId": 265,
      "endpointId": 1,
      "networkId": 0,
      "endpointVersion": 1,
      "deviceIdentifier": 8
    }
  ],
  "log": []
}