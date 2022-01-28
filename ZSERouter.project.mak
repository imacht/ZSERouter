####################################################################
# Automatically-generated file. Do not edit!                       #
# Makefile Version 9                                               #
####################################################################

BASE_SDK_PATH = C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.3
UNAME:=$(shell uname -s | sed -e 's/^\(CYGWIN\).*/\1/' | sed -e 's/^\(MINGW\).*/\1/')
ifeq ($(UNAME),MINGW)
# Translate "C:/super" into "/C/super" for MinGW make.
SDK_PATH := /$(shell echo $(BASE_SDK_PATH) | sed s/://)
endif
SDK_PATH ?= $(BASE_SDK_PATH)
COPIED_SDK_PATH ?= gecko_sdk_3.3.0

# This uses the explicit build rules below
PROJECT_SOURCE_FILES =

C_SOURCE_FILES   += $(filter %.c, $(PROJECT_SOURCE_FILES))
CXX_SOURCE_FILES += $(filter %.cpp, $(PROJECT_SOURCE_FILES))
CXX_SOURCE_FILES += $(filter %.cc, $(PROJECT_SOURCE_FILES))
ASM_SOURCE_FILES += $(filter %.s, $(PROJECT_SOURCE_FILES))
ASM_SOURCE_FILES += $(filter %.S, $(PROJECT_SOURCE_FILES))
LIB_FILES        += $(filter %.a, $(PROJECT_SOURCE_FILES))

C_DEFS += \
 '-DEFR32MG24B010F1536IM48=1' \
 '-DSL_COMPONENT_CATALOG_PRESENT=1' \
 '-DCORTEXM3=1' \
 '-DCORTEXM3_EFM32_MICRO=1' \
 '-DCORTEXM3_EFR32=1' \
 '-DPHY_RAIL=1' \
 '-DPLATFORM_HEADER="platform-header.h"' \
 '-DMBEDTLS_CONFIG_FILE=<mbedtls_config.h>' \
 '-DMBEDTLS_PSA_CRYPTO_CONFIG_FILE=<psa_crypto_config.h>' \
 '-DSL_RAIL_LIB_MULTIPROTOCOL_SUPPORT=0' \
 '-DSL_RAIL_UTIL_PA_CONFIG_HEADER=<sl_rail_util_pa_config.h>' \
 '-DUSE_NVM3=1' \
 '-DUC_BUILD=1' \
 '-DSL_ZIGBEE_PHY_SELECT_STACK_SUPPORT=1' \
 '-DCONFIGURATION_HEADER="app/framework/util/config.h"'

ASM_DEFS += \
 '-DEFR32MG24B010F1536IM48=1' \
 '-DSL_COMPONENT_CATALOG_PRESENT=1' \
 '-DCORTEXM3=1' \
 '-DCORTEXM3_EFM32_MICRO=1' \
 '-DCORTEXM3_EFR32=1' \
 '-DPHY_RAIL=1' \
 '-DPLATFORM_HEADER="platform-header.h"' \
 '-DMBEDTLS_CONFIG_FILE=<mbedtls_config.h>' \
 '-DMBEDTLS_PSA_CRYPTO_CONFIG_FILE=<psa_crypto_config.h>' \
 '-DSL_RAIL_LIB_MULTIPROTOCOL_SUPPORT=0' \
 '-DSL_RAIL_UTIL_PA_CONFIG_HEADER=<sl_rail_util_pa_config.h>' \
 '-DUSE_NVM3=1' \
 '-DUC_BUILD=1' \
 '-DSL_ZIGBEE_PHY_SELECT_STACK_SUPPORT=1' \
 '-DCONFIGURATION_HEADER="app/framework/util/config.h"'

INCLUDES += \
 -Iconfig \
 -Iautogen \
 -I. \
 -I$(SDK_PATH)/platform/Device/SiliconLabs/EFR32MG24/Include \
 -I$(SDK_PATH)/platform/common/inc \
 -I$(SDK_PATH)/hardware/board/inc \
 -I$(SDK_PATH)/platform/driver/button/inc \
 -I$(SDK_PATH)/platform/service/cli/inc \
 -I$(SDK_PATH)/platform/CMSIS/Include \
 -I$(SDK_PATH)/platform/driver/debug/inc \
 -I$(SDK_PATH)/platform/service/device_init/inc \
 -I$(SDK_PATH)/platform/emdrv/common/inc \
 -I$(SDK_PATH)/platform/emlib/inc \
 -I$(SDK_PATH)/platform/emlib/host/inc \
 -I$(SDK_PATH)/platform/emdrv/gpiointerrupt/inc \
 -I$(SDK_PATH)/platform/service/hfxo_manager/inc \
 -I$(SDK_PATH)/platform/service/iostream/inc \
 -I$(SDK_PATH)/platform/driver/leddrv/inc \
 -I$(SDK_PATH)/platform/service/legacy_hal/inc \
 -I$(SDK_PATH)/platform/service/legacy_printf/inc \
 -I$(SDK_PATH)/util/third_party/crypto/sl_component/sl_mbedtls_support/config \
 -I$(SDK_PATH)/util/third_party/crypto/mbedtls/include \
 -I$(SDK_PATH)/util/third_party/crypto/mbedtls/library \
 -I$(SDK_PATH)/util/third_party/crypto/sl_component/sl_mbedtls_support/inc \
 -I$(SDK_PATH)/hardware/driver/mx25_flash_shutdown/inc/sl_mx25_flash_shutdown_eusart \
 -I$(SDK_PATH)/platform/emdrv/nvm3/inc \
 -I$(SDK_PATH)/platform/peripheral/inc \
 -I$(SDK_PATH)/platform/service/power_manager/inc \
 -I$(SDK_PATH)/util/third_party/printf \
 -I$(SDK_PATH)/util/third_party/printf/inc \
 -I$(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/inc \
 -I$(SDK_PATH)/platform/radio/rail_lib/common \
 -I$(SDK_PATH)/platform/radio/rail_lib/protocol/ble \
 -I$(SDK_PATH)/platform/radio/rail_lib/protocol/ieee802154 \
 -I$(SDK_PATH)/platform/radio/rail_lib/protocol/zwave \
 -I$(SDK_PATH)/platform/radio/rail_lib/chip/efr32/efr32xg2x \
 -I$(SDK_PATH)/platform/radio/rail_lib/plugin/rail_util_ieee802154 \
 -I$(SDK_PATH)/platform/radio/rail_lib/plugin/pa-conversions \
 -I$(SDK_PATH)/platform/radio/rail_lib/plugin/pa-conversions/efr32xg24 \
 -I$(SDK_PATH)/platform/radio/rail_lib/plugin/rail_util_pti \
 -I$(SDK_PATH)/util/third_party/crypto/sl_component/se_manager/inc \
 -I$(SDK_PATH)/util/third_party/crypto/sl_component/se_manager/src \
 -I$(SDK_PATH)/util/silicon_labs/silabs_core/memory_manager \
 -I$(SDK_PATH)/platform/common/toolchain/inc \
 -I$(SDK_PATH)/platform/service/system/inc \
 -I$(SDK_PATH)/platform/service/sleeptimer/inc \
 -I$(SDK_PATH)/platform/emdrv/tempdrv/inc \
 -I$(SDK_PATH)/platform/service/token_manager/inc \
 -I$(SDK_PATH)/platform/service/udelay/inc \
 -I$(SDK_PATH)/protocol/zigbee/app/framework/plugin/address-table \
 -I$(SDK_PATH)/protocol/zigbee/stack/platform/micro \
 -I$(SDK_PATH)/protocol/zigbee/stack/include \
 -I$(SDK_PATH)/protocol/zigbee/app/framework/common \
 -I$(SDK_PATH)/protocol/zigbee/app/em260 \
 -I$(SDK_PATH)/protocol/zigbee/app/util/serial \
 -I$(SDK_PATH)/protocol/zigbee/app/framework/plugin/counters \
 -I$(SDK_PATH)/protocol/zigbee/stack/framework \
 -I$(SDK_PATH)/protocol/zigbee/app/framework/plugin/debug-print \
 -I$(SDK_PATH)/protocol/zigbee/stack/security/ecc \
 -I$(SDK_PATH)/protocol/zigbee/app/util/common \
 -I$(SDK_PATH)/protocol/zigbee/app/framework/plugin/fragmentation \
 -I$(SDK_PATH)/protocol/zigbee/app/framework/plugin/key-establishment \
 -I$(SDK_PATH)/protocol/zigbee/stack/core \
 -I$(SDK_PATH)/protocol/zigbee/app/framework/plugin/network-find \
 -I$(SDK_PATH)/protocol/zigbee/app/framework/plugin/scan-dispatch \
 -I$(SDK_PATH)/platform/radio/rail_lib/plugin \
 -I$(SDK_PATH)/protocol/zigbee \
 -I$(SDK_PATH)/protocol/zigbee/stack \
 -I$(SDK_PATH)/protocol/zigbee/stack/gp \
 -I$(SDK_PATH)/protocol/zigbee/stack/zigbee \
 -I$(SDK_PATH)/platform/radio/mac \
 -I$(SDK_PATH)/util/silicon_labs/silabs_core \
 -I$(SDK_PATH)/protocol/zigbee/stack/mac \
 -I$(SDK_PATH)/protocol/zigbee/app/framework/include \
 -I$(SDK_PATH)/protocol/zigbee/app/framework/util \
 -I$(SDK_PATH)/protocol/zigbee/app/framework/security \
 -I$(SDK_PATH)/protocol/zigbee/app/util/zigbee-framework \
 -I$(SDK_PATH)/protocol/zigbee/app/util/counters \
 -I$(SDK_PATH)/protocol/zigbee/app/framework/cli \
 -I$(SDK_PATH)/protocol/zigbee/app/util/security \
 -I$(SDK_PATH)/protocol/zigbee/app/framework/plugin/ota-storage-common

GROUP_START =-Wl,--start-group
GROUP_END =-Wl,--end-group

PROJECT_LIBS = \
 -lgcc \
 -lc \
 -lm \
 -lnosys \
 $(SDK_PATH)/platform/emdrv/nvm3/lib/libnvm3_CM33_gcc.a \
 $(SDK_PATH)/platform/radio/rail_lib/autogen/librail_release/librail_efr32xg24_gcc_release.a \
 $(SDK_PATH)/protocol/zigbee/build/binding-table-library-cortexm3-gcc-efr32mg24-rail/binding-table-library.a \
 $(SDK_PATH)/protocol/zigbee/build/cbke-163k1-library-cortexm3-gcc-efr32mg24-rail/cbke-163k1-library.a \
 $(SDK_PATH)/protocol/zigbee/build/cbke-283k1-library-cortexm3-gcc-efr32mg24-rail/cbke-283k1-library.a \
 $(SDK_PATH)/protocol/zigbee/build/cbke-library-core-cortexm3-gcc-efr32mg24-rail/cbke-library-core.a \
 $(SDK_PATH)/protocol/zigbee/build/uc-debug-basic-library-cortexm3-gcc-efr32mg24-rail/uc-debug-basic-library.a \
 $(SDK_PATH)/protocol/zigbee/build/ECC/ecc-163k1-library.a \
 $(SDK_PATH)/protocol/zigbee/build/ECC/ecc-283k1-library.a \
 $(SDK_PATH)/protocol/zigbee/build/install-code-library-cortexm3-gcc-efr32mg24-rail/install-code-library.a \
 $(SDK_PATH)/protocol/zigbee/build/multi-network-stub-library-cortexm3-gcc-efr32mg24-rail/multi-network-stub-library.a \
 $(SDK_PATH)/protocol/zigbee/build/multi-pan-stub-library-cortexm3-gcc-efr32mg24-rail/multi-pan-stub-library.a \
 $(SDK_PATH)/protocol/zigbee/build/packet-validate-library-cortexm3-gcc-efr32mg24-rail/packet-validate-library.a \
 $(SDK_PATH)/protocol/zigbee/build/zigbee-pro-stack-cortexm3-gcc-efr32mg24-rail/zigbee-pro-stack.a \
 $(SDK_PATH)/protocol/zigbee/build/security-library-link-keys-cortexm3-gcc-efr32mg24-rail/security-library-link-keys.a \
 $(SDK_PATH)/protocol/zigbee/build/source-route-library-cortexm3-gcc-efr32mg24-rail/source-route-library.a

LIBS += $(GROUP_START) $(PROJECT_LIBS) $(GROUP_END)

LIB_FILES += $(filter %.a, $(PROJECT_LIBS))

C_FLAGS += \
 -mcpu=cortex-m33 \
 -mthumb \
 -mfpu=fpv5-sp-d16 \
 -mfloat-abi=hard \
 -std=c99 \
 -Wall \
 -Wextra \
 -Os \
 -fdata-sections \
 -ffunction-sections \
 -fomit-frame-pointer \
 -fno-builtin \
 -imacros sl_gcc_preinclude.h \
 --specs=nano.specs \
 -Wno-unused-parameter \
 -Wno-missing-field-initializers \
 -Wno-missing-braces \
 -Wno-format \
 -g

CXX_FLAGS += \
 -mcpu=cortex-m33 \
 -mthumb \
 -mfpu=fpv5-sp-d16 \
 -mfloat-abi=hard \
 -std=c++11 \
 -fno-rtti \
 -fno-exceptions \
 -Wall \
 -Wextra \
 -Os \
 -fdata-sections \
 -ffunction-sections \
 -fomit-frame-pointer \
 -fno-builtin \
 -imacros sl_gcc_preinclude.h \
 --specs=nano.specs \
 -Wno-unused-parameter \
 -Wno-missing-field-initializers \
 -Wno-missing-braces \
 -Wno-format \
 -g

ASM_FLAGS += \
 -mcpu=cortex-m33 \
 -mthumb \
 -mfpu=fpv5-sp-d16 \
 -mfloat-abi=hard \
 -imacros sl_gcc_preinclude.h \
 -x assembler-with-cpp

LD_FLAGS += \
 -mcpu=cortex-m33 \
 -mthumb \
 -mfpu=fpv5-sp-d16 \
 -mfloat-abi=hard \
 -T"autogen/linkerfile.ld" \
 --specs=nano.specs \
 -Xlinker -Map=$(OUTPUT_DIR)/$(PROJECTNAME).map \
 -Wl,--gc-sections


####################################################################
# SDK Build Rules                                                  #
####################################################################
$(OUTPUT_DIR)/sdk/hardware/board/src/sl_board_control_gpio.o: $(SDK_PATH)/hardware/board/src/sl_board_control_gpio.c
	@echo 'Building $(SDK_PATH)/hardware/board/src/sl_board_control_gpio.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/hardware/board/src/sl_board_control_gpio.c
CDEPS += $(OUTPUT_DIR)/sdk/hardware/board/src/sl_board_control_gpio.d
OBJS += $(OUTPUT_DIR)/sdk/hardware/board/src/sl_board_control_gpio.o

$(OUTPUT_DIR)/sdk/hardware/board/src/sl_board_init.o: $(SDK_PATH)/hardware/board/src/sl_board_init.c
	@echo 'Building $(SDK_PATH)/hardware/board/src/sl_board_init.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/hardware/board/src/sl_board_init.c
CDEPS += $(OUTPUT_DIR)/sdk/hardware/board/src/sl_board_init.d
OBJS += $(OUTPUT_DIR)/sdk/hardware/board/src/sl_board_init.o

$(OUTPUT_DIR)/sdk/hardware/driver/mx25_flash_shutdown/src/sl_mx25_flash_shutdown_eusart/sl_mx25_flash_shutdown.o: $(SDK_PATH)/hardware/driver/mx25_flash_shutdown/src/sl_mx25_flash_shutdown_eusart/sl_mx25_flash_shutdown.c
	@echo 'Building $(SDK_PATH)/hardware/driver/mx25_flash_shutdown/src/sl_mx25_flash_shutdown_eusart/sl_mx25_flash_shutdown.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/hardware/driver/mx25_flash_shutdown/src/sl_mx25_flash_shutdown_eusart/sl_mx25_flash_shutdown.c
CDEPS += $(OUTPUT_DIR)/sdk/hardware/driver/mx25_flash_shutdown/src/sl_mx25_flash_shutdown_eusart/sl_mx25_flash_shutdown.d
OBJS += $(OUTPUT_DIR)/sdk/hardware/driver/mx25_flash_shutdown/src/sl_mx25_flash_shutdown_eusart/sl_mx25_flash_shutdown.o

$(OUTPUT_DIR)/sdk/platform/common/src/sl_slist.o: $(SDK_PATH)/platform/common/src/sl_slist.c
	@echo 'Building $(SDK_PATH)/platform/common/src/sl_slist.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/common/src/sl_slist.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/common/src/sl_slist.d
OBJS += $(OUTPUT_DIR)/sdk/platform/common/src/sl_slist.o

$(OUTPUT_DIR)/sdk/platform/common/src/sl_string.o: $(SDK_PATH)/platform/common/src/sl_string.c
	@echo 'Building $(SDK_PATH)/platform/common/src/sl_string.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/common/src/sl_string.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/common/src/sl_string.d
OBJS += $(OUTPUT_DIR)/sdk/platform/common/src/sl_string.o

$(OUTPUT_DIR)/sdk/platform/common/toolchain/src/sl_memory.o: $(SDK_PATH)/platform/common/toolchain/src/sl_memory.c
	@echo 'Building $(SDK_PATH)/platform/common/toolchain/src/sl_memory.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/common/toolchain/src/sl_memory.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/common/toolchain/src/sl_memory.d
OBJS += $(OUTPUT_DIR)/sdk/platform/common/toolchain/src/sl_memory.o

$(OUTPUT_DIR)/sdk/platform/Device/SiliconLabs/EFR32MG24/Source/GCC/startup_efr32mg24.o: $(SDK_PATH)/platform/Device/SiliconLabs/EFR32MG24/Source/GCC/startup_efr32mg24.c
	@echo 'Building $(SDK_PATH)/platform/Device/SiliconLabs/EFR32MG24/Source/GCC/startup_efr32mg24.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/Device/SiliconLabs/EFR32MG24/Source/GCC/startup_efr32mg24.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/Device/SiliconLabs/EFR32MG24/Source/GCC/startup_efr32mg24.d
OBJS += $(OUTPUT_DIR)/sdk/platform/Device/SiliconLabs/EFR32MG24/Source/GCC/startup_efr32mg24.o

$(OUTPUT_DIR)/sdk/platform/Device/SiliconLabs/EFR32MG24/Source/system_efr32mg24.o: $(SDK_PATH)/platform/Device/SiliconLabs/EFR32MG24/Source/system_efr32mg24.c
	@echo 'Building $(SDK_PATH)/platform/Device/SiliconLabs/EFR32MG24/Source/system_efr32mg24.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/Device/SiliconLabs/EFR32MG24/Source/system_efr32mg24.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/Device/SiliconLabs/EFR32MG24/Source/system_efr32mg24.d
OBJS += $(OUTPUT_DIR)/sdk/platform/Device/SiliconLabs/EFR32MG24/Source/system_efr32mg24.o

$(OUTPUT_DIR)/sdk/platform/driver/button/src/sl_button.o: $(SDK_PATH)/platform/driver/button/src/sl_button.c
	@echo 'Building $(SDK_PATH)/platform/driver/button/src/sl_button.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/driver/button/src/sl_button.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/driver/button/src/sl_button.d
OBJS += $(OUTPUT_DIR)/sdk/platform/driver/button/src/sl_button.o

$(OUTPUT_DIR)/sdk/platform/driver/button/src/sl_simple_button.o: $(SDK_PATH)/platform/driver/button/src/sl_simple_button.c
	@echo 'Building $(SDK_PATH)/platform/driver/button/src/sl_simple_button.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/driver/button/src/sl_simple_button.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/driver/button/src/sl_simple_button.d
OBJS += $(OUTPUT_DIR)/sdk/platform/driver/button/src/sl_simple_button.o

$(OUTPUT_DIR)/sdk/platform/driver/debug/src/sl_debug_swo.o: $(SDK_PATH)/platform/driver/debug/src/sl_debug_swo.c
	@echo 'Building $(SDK_PATH)/platform/driver/debug/src/sl_debug_swo.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/driver/debug/src/sl_debug_swo.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/driver/debug/src/sl_debug_swo.d
OBJS += $(OUTPUT_DIR)/sdk/platform/driver/debug/src/sl_debug_swo.o

$(OUTPUT_DIR)/sdk/platform/driver/leddrv/src/sl_led.o: $(SDK_PATH)/platform/driver/leddrv/src/sl_led.c
	@echo 'Building $(SDK_PATH)/platform/driver/leddrv/src/sl_led.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/driver/leddrv/src/sl_led.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/driver/leddrv/src/sl_led.d
OBJS += $(OUTPUT_DIR)/sdk/platform/driver/leddrv/src/sl_led.o

$(OUTPUT_DIR)/sdk/platform/driver/leddrv/src/sl_simple_led.o: $(SDK_PATH)/platform/driver/leddrv/src/sl_simple_led.c
	@echo 'Building $(SDK_PATH)/platform/driver/leddrv/src/sl_simple_led.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/driver/leddrv/src/sl_simple_led.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/driver/leddrv/src/sl_simple_led.d
OBJS += $(OUTPUT_DIR)/sdk/platform/driver/leddrv/src/sl_simple_led.o

$(OUTPUT_DIR)/sdk/platform/emdrv/gpiointerrupt/src/gpiointerrupt.o: $(SDK_PATH)/platform/emdrv/gpiointerrupt/src/gpiointerrupt.c
	@echo 'Building $(SDK_PATH)/platform/emdrv/gpiointerrupt/src/gpiointerrupt.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/emdrv/gpiointerrupt/src/gpiointerrupt.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emdrv/gpiointerrupt/src/gpiointerrupt.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emdrv/gpiointerrupt/src/gpiointerrupt.o

$(OUTPUT_DIR)/sdk/platform/emdrv/nvm3/src/nvm3_default_common_linker.o: $(SDK_PATH)/platform/emdrv/nvm3/src/nvm3_default_common_linker.c
	@echo 'Building $(SDK_PATH)/platform/emdrv/nvm3/src/nvm3_default_common_linker.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/emdrv/nvm3/src/nvm3_default_common_linker.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emdrv/nvm3/src/nvm3_default_common_linker.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emdrv/nvm3/src/nvm3_default_common_linker.o

$(OUTPUT_DIR)/sdk/platform/emdrv/nvm3/src/nvm3_hal_flash.o: $(SDK_PATH)/platform/emdrv/nvm3/src/nvm3_hal_flash.c
	@echo 'Building $(SDK_PATH)/platform/emdrv/nvm3/src/nvm3_hal_flash.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/emdrv/nvm3/src/nvm3_hal_flash.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emdrv/nvm3/src/nvm3_hal_flash.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emdrv/nvm3/src/nvm3_hal_flash.o

$(OUTPUT_DIR)/sdk/platform/emdrv/nvm3/src/nvm3_lock.o: $(SDK_PATH)/platform/emdrv/nvm3/src/nvm3_lock.c
	@echo 'Building $(SDK_PATH)/platform/emdrv/nvm3/src/nvm3_lock.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/emdrv/nvm3/src/nvm3_lock.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emdrv/nvm3/src/nvm3_lock.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emdrv/nvm3/src/nvm3_lock.o

$(OUTPUT_DIR)/sdk/platform/emdrv/tempdrv/src/tempdrv.o: $(SDK_PATH)/platform/emdrv/tempdrv/src/tempdrv.c
	@echo 'Building $(SDK_PATH)/platform/emdrv/tempdrv/src/tempdrv.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/emdrv/tempdrv/src/tempdrv.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emdrv/tempdrv/src/tempdrv.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emdrv/tempdrv/src/tempdrv.o

$(OUTPUT_DIR)/sdk/platform/emlib/src/em_assert.o: $(SDK_PATH)/platform/emlib/src/em_assert.c
	@echo 'Building $(SDK_PATH)/platform/emlib/src/em_assert.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/emlib/src/em_assert.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_assert.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_assert.o

$(OUTPUT_DIR)/sdk/platform/emlib/src/em_burtc.o: $(SDK_PATH)/platform/emlib/src/em_burtc.c
	@echo 'Building $(SDK_PATH)/platform/emlib/src/em_burtc.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/emlib/src/em_burtc.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_burtc.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_burtc.o

$(OUTPUT_DIR)/sdk/platform/emlib/src/em_cmu.o: $(SDK_PATH)/platform/emlib/src/em_cmu.c
	@echo 'Building $(SDK_PATH)/platform/emlib/src/em_cmu.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/emlib/src/em_cmu.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_cmu.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_cmu.o

$(OUTPUT_DIR)/sdk/platform/emlib/src/em_core.o: $(SDK_PATH)/platform/emlib/src/em_core.c
	@echo 'Building $(SDK_PATH)/platform/emlib/src/em_core.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/emlib/src/em_core.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_core.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_core.o

$(OUTPUT_DIR)/sdk/platform/emlib/src/em_emu.o: $(SDK_PATH)/platform/emlib/src/em_emu.c
	@echo 'Building $(SDK_PATH)/platform/emlib/src/em_emu.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/emlib/src/em_emu.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_emu.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_emu.o

$(OUTPUT_DIR)/sdk/platform/emlib/src/em_eusart.o: $(SDK_PATH)/platform/emlib/src/em_eusart.c
	@echo 'Building $(SDK_PATH)/platform/emlib/src/em_eusart.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/emlib/src/em_eusart.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_eusart.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_eusart.o

$(OUTPUT_DIR)/sdk/platform/emlib/src/em_gpio.o: $(SDK_PATH)/platform/emlib/src/em_gpio.c
	@echo 'Building $(SDK_PATH)/platform/emlib/src/em_gpio.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/emlib/src/em_gpio.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_gpio.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_gpio.o

$(OUTPUT_DIR)/sdk/platform/emlib/src/em_msc.o: $(SDK_PATH)/platform/emlib/src/em_msc.c
	@echo 'Building $(SDK_PATH)/platform/emlib/src/em_msc.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/emlib/src/em_msc.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_msc.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_msc.o

$(OUTPUT_DIR)/sdk/platform/emlib/src/em_prs.o: $(SDK_PATH)/platform/emlib/src/em_prs.c
	@echo 'Building $(SDK_PATH)/platform/emlib/src/em_prs.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/emlib/src/em_prs.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_prs.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_prs.o

$(OUTPUT_DIR)/sdk/platform/emlib/src/em_rmu.o: $(SDK_PATH)/platform/emlib/src/em_rmu.c
	@echo 'Building $(SDK_PATH)/platform/emlib/src/em_rmu.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/emlib/src/em_rmu.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_rmu.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_rmu.o

$(OUTPUT_DIR)/sdk/platform/emlib/src/em_se.o: $(SDK_PATH)/platform/emlib/src/em_se.c
	@echo 'Building $(SDK_PATH)/platform/emlib/src/em_se.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/emlib/src/em_se.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_se.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_se.o

$(OUTPUT_DIR)/sdk/platform/emlib/src/em_system.o: $(SDK_PATH)/platform/emlib/src/em_system.c
	@echo 'Building $(SDK_PATH)/platform/emlib/src/em_system.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/emlib/src/em_system.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_system.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_system.o

$(OUTPUT_DIR)/sdk/platform/emlib/src/em_usart.o: $(SDK_PATH)/platform/emlib/src/em_usart.c
	@echo 'Building $(SDK_PATH)/platform/emlib/src/em_usart.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/emlib/src/em_usart.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_usart.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_usart.o

$(OUTPUT_DIR)/sdk/platform/emlib/src/em_wdog.o: $(SDK_PATH)/platform/emlib/src/em_wdog.c
	@echo 'Building $(SDK_PATH)/platform/emlib/src/em_wdog.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/emlib/src/em_wdog.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_wdog.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_wdog.o

$(OUTPUT_DIR)/sdk/platform/peripheral/src/peripheral_sysrtc.o: $(SDK_PATH)/platform/peripheral/src/peripheral_sysrtc.c
	@echo 'Building $(SDK_PATH)/platform/peripheral/src/peripheral_sysrtc.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/peripheral/src/peripheral_sysrtc.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/peripheral/src/peripheral_sysrtc.d
OBJS += $(OUTPUT_DIR)/sdk/platform/peripheral/src/peripheral_sysrtc.o

$(OUTPUT_DIR)/sdk/platform/radio/rail_lib/plugin/coexistence/protocol/ieee802154_uc/coexistence-802154.o: $(SDK_PATH)/platform/radio/rail_lib/plugin/coexistence/protocol/ieee802154_uc/coexistence-802154.c
	@echo 'Building $(SDK_PATH)/platform/radio/rail_lib/plugin/coexistence/protocol/ieee802154_uc/coexistence-802154.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/radio/rail_lib/plugin/coexistence/protocol/ieee802154_uc/coexistence-802154.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/radio/rail_lib/plugin/coexistence/protocol/ieee802154_uc/coexistence-802154.d
OBJS += $(OUTPUT_DIR)/sdk/platform/radio/rail_lib/plugin/coexistence/protocol/ieee802154_uc/coexistence-802154.o

$(OUTPUT_DIR)/sdk/platform/radio/rail_lib/plugin/pa-conversions/pa_conversions_efr32.o: $(SDK_PATH)/platform/radio/rail_lib/plugin/pa-conversions/pa_conversions_efr32.c
	@echo 'Building $(SDK_PATH)/platform/radio/rail_lib/plugin/pa-conversions/pa_conversions_efr32.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/radio/rail_lib/plugin/pa-conversions/pa_conversions_efr32.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/radio/rail_lib/plugin/pa-conversions/pa_conversions_efr32.d
OBJS += $(OUTPUT_DIR)/sdk/platform/radio/rail_lib/plugin/pa-conversions/pa_conversions_efr32.o

$(OUTPUT_DIR)/sdk/platform/radio/rail_lib/plugin/pa-conversions/pa_curves_efr32.o: $(SDK_PATH)/platform/radio/rail_lib/plugin/pa-conversions/pa_curves_efr32.c
	@echo 'Building $(SDK_PATH)/platform/radio/rail_lib/plugin/pa-conversions/pa_curves_efr32.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/radio/rail_lib/plugin/pa-conversions/pa_curves_efr32.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/radio/rail_lib/plugin/pa-conversions/pa_curves_efr32.d
OBJS += $(OUTPUT_DIR)/sdk/platform/radio/rail_lib/plugin/pa-conversions/pa_curves_efr32.o

$(OUTPUT_DIR)/sdk/platform/radio/rail_lib/plugin/rail_util_ant_div/sl_rail_util_ant_div.o: $(SDK_PATH)/platform/radio/rail_lib/plugin/rail_util_ant_div/sl_rail_util_ant_div.c
	@echo 'Building $(SDK_PATH)/platform/radio/rail_lib/plugin/rail_util_ant_div/sl_rail_util_ant_div.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/radio/rail_lib/plugin/rail_util_ant_div/sl_rail_util_ant_div.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/radio/rail_lib/plugin/rail_util_ant_div/sl_rail_util_ant_div.d
OBJS += $(OUTPUT_DIR)/sdk/platform/radio/rail_lib/plugin/rail_util_ant_div/sl_rail_util_ant_div.o

$(OUTPUT_DIR)/sdk/platform/radio/rail_lib/plugin/rail_util_pti/sl_rail_util_pti.o: $(SDK_PATH)/platform/radio/rail_lib/plugin/rail_util_pti/sl_rail_util_pti.c
	@echo 'Building $(SDK_PATH)/platform/radio/rail_lib/plugin/rail_util_pti/sl_rail_util_pti.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/radio/rail_lib/plugin/rail_util_pti/sl_rail_util_pti.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/radio/rail_lib/plugin/rail_util_pti/sl_rail_util_pti.d
OBJS += $(OUTPUT_DIR)/sdk/platform/radio/rail_lib/plugin/rail_util_pti/sl_rail_util_pti.o

$(OUTPUT_DIR)/sdk/platform/service/cli/src/sl_cli.o: $(SDK_PATH)/platform/service/cli/src/sl_cli.c
	@echo 'Building $(SDK_PATH)/platform/service/cli/src/sl_cli.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/service/cli/src/sl_cli.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/cli/src/sl_cli.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/cli/src/sl_cli.o

$(OUTPUT_DIR)/sdk/platform/service/cli/src/sl_cli_arguments.o: $(SDK_PATH)/platform/service/cli/src/sl_cli_arguments.c
	@echo 'Building $(SDK_PATH)/platform/service/cli/src/sl_cli_arguments.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/service/cli/src/sl_cli_arguments.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/cli/src/sl_cli_arguments.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/cli/src/sl_cli_arguments.o

$(OUTPUT_DIR)/sdk/platform/service/cli/src/sl_cli_command.o: $(SDK_PATH)/platform/service/cli/src/sl_cli_command.c
	@echo 'Building $(SDK_PATH)/platform/service/cli/src/sl_cli_command.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/service/cli/src/sl_cli_command.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/cli/src/sl_cli_command.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/cli/src/sl_cli_command.o

$(OUTPUT_DIR)/sdk/platform/service/cli/src/sl_cli_input.o: $(SDK_PATH)/platform/service/cli/src/sl_cli_input.c
	@echo 'Building $(SDK_PATH)/platform/service/cli/src/sl_cli_input.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/service/cli/src/sl_cli_input.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/cli/src/sl_cli_input.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/cli/src/sl_cli_input.o

$(OUTPUT_DIR)/sdk/platform/service/cli/src/sl_cli_io.o: $(SDK_PATH)/platform/service/cli/src/sl_cli_io.c
	@echo 'Building $(SDK_PATH)/platform/service/cli/src/sl_cli_io.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/service/cli/src/sl_cli_io.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/cli/src/sl_cli_io.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/cli/src/sl_cli_io.o

$(OUTPUT_DIR)/sdk/platform/service/cli/src/sl_cli_tokenize.o: $(SDK_PATH)/platform/service/cli/src/sl_cli_tokenize.c
	@echo 'Building $(SDK_PATH)/platform/service/cli/src/sl_cli_tokenize.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/service/cli/src/sl_cli_tokenize.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/cli/src/sl_cli_tokenize.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/cli/src/sl_cli_tokenize.o

$(OUTPUT_DIR)/sdk/platform/service/device_init/src/sl_device_init_dcdc_s2.o: $(SDK_PATH)/platform/service/device_init/src/sl_device_init_dcdc_s2.c
	@echo 'Building $(SDK_PATH)/platform/service/device_init/src/sl_device_init_dcdc_s2.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/service/device_init/src/sl_device_init_dcdc_s2.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/device_init/src/sl_device_init_dcdc_s2.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/device_init/src/sl_device_init_dcdc_s2.o

$(OUTPUT_DIR)/sdk/platform/service/device_init/src/sl_device_init_emu_s2.o: $(SDK_PATH)/platform/service/device_init/src/sl_device_init_emu_s2.c
	@echo 'Building $(SDK_PATH)/platform/service/device_init/src/sl_device_init_emu_s2.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/service/device_init/src/sl_device_init_emu_s2.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/device_init/src/sl_device_init_emu_s2.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/device_init/src/sl_device_init_emu_s2.o

$(OUTPUT_DIR)/sdk/platform/service/device_init/src/sl_device_init_hfxo_s2.o: $(SDK_PATH)/platform/service/device_init/src/sl_device_init_hfxo_s2.c
	@echo 'Building $(SDK_PATH)/platform/service/device_init/src/sl_device_init_hfxo_s2.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/service/device_init/src/sl_device_init_hfxo_s2.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/device_init/src/sl_device_init_hfxo_s2.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/device_init/src/sl_device_init_hfxo_s2.o

$(OUTPUT_DIR)/sdk/platform/service/device_init/src/sl_device_init_lfxo_s2.o: $(SDK_PATH)/platform/service/device_init/src/sl_device_init_lfxo_s2.c
	@echo 'Building $(SDK_PATH)/platform/service/device_init/src/sl_device_init_lfxo_s2.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/service/device_init/src/sl_device_init_lfxo_s2.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/device_init/src/sl_device_init_lfxo_s2.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/device_init/src/sl_device_init_lfxo_s2.o

$(OUTPUT_DIR)/sdk/platform/service/device_init/src/sl_device_init_nvic.o: $(SDK_PATH)/platform/service/device_init/src/sl_device_init_nvic.c
	@echo 'Building $(SDK_PATH)/platform/service/device_init/src/sl_device_init_nvic.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/service/device_init/src/sl_device_init_nvic.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/device_init/src/sl_device_init_nvic.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/device_init/src/sl_device_init_nvic.o

$(OUTPUT_DIR)/sdk/platform/service/hfxo_manager/src/sl_hfxo_manager.o: $(SDK_PATH)/platform/service/hfxo_manager/src/sl_hfxo_manager.c
	@echo 'Building $(SDK_PATH)/platform/service/hfxo_manager/src/sl_hfxo_manager.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/service/hfxo_manager/src/sl_hfxo_manager.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/hfxo_manager/src/sl_hfxo_manager.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/hfxo_manager/src/sl_hfxo_manager.o

$(OUTPUT_DIR)/sdk/platform/service/hfxo_manager/src/sl_hfxo_manager_hal_s2.o: $(SDK_PATH)/platform/service/hfxo_manager/src/sl_hfxo_manager_hal_s2.c
	@echo 'Building $(SDK_PATH)/platform/service/hfxo_manager/src/sl_hfxo_manager_hal_s2.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/service/hfxo_manager/src/sl_hfxo_manager_hal_s2.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/hfxo_manager/src/sl_hfxo_manager_hal_s2.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/hfxo_manager/src/sl_hfxo_manager_hal_s2.o

$(OUTPUT_DIR)/sdk/platform/service/iostream/src/sl_iostream.o: $(SDK_PATH)/platform/service/iostream/src/sl_iostream.c
	@echo 'Building $(SDK_PATH)/platform/service/iostream/src/sl_iostream.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/service/iostream/src/sl_iostream.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/iostream/src/sl_iostream.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/iostream/src/sl_iostream.o

$(OUTPUT_DIR)/sdk/platform/service/iostream/src/sl_iostream_debug.o: $(SDK_PATH)/platform/service/iostream/src/sl_iostream_debug.c
	@echo 'Building $(SDK_PATH)/platform/service/iostream/src/sl_iostream_debug.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/service/iostream/src/sl_iostream_debug.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/iostream/src/sl_iostream_debug.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/iostream/src/sl_iostream_debug.o

$(OUTPUT_DIR)/sdk/platform/service/iostream/src/sl_iostream_swo_itm_8.o: $(SDK_PATH)/platform/service/iostream/src/sl_iostream_swo_itm_8.c
	@echo 'Building $(SDK_PATH)/platform/service/iostream/src/sl_iostream_swo_itm_8.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/service/iostream/src/sl_iostream_swo_itm_8.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/iostream/src/sl_iostream_swo_itm_8.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/iostream/src/sl_iostream_swo_itm_8.o

$(OUTPUT_DIR)/sdk/platform/service/iostream/src/sl_iostream_uart.o: $(SDK_PATH)/platform/service/iostream/src/sl_iostream_uart.c
	@echo 'Building $(SDK_PATH)/platform/service/iostream/src/sl_iostream_uart.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/service/iostream/src/sl_iostream_uart.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/iostream/src/sl_iostream_uart.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/iostream/src/sl_iostream_uart.o

$(OUTPUT_DIR)/sdk/platform/service/iostream/src/sl_iostream_usart.o: $(SDK_PATH)/platform/service/iostream/src/sl_iostream_usart.c
	@echo 'Building $(SDK_PATH)/platform/service/iostream/src/sl_iostream_usart.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/service/iostream/src/sl_iostream_usart.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/iostream/src/sl_iostream_usart.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/iostream/src/sl_iostream_usart.o

$(OUTPUT_DIR)/sdk/platform/service/legacy_hal/src/base-replacement.o: $(SDK_PATH)/platform/service/legacy_hal/src/base-replacement.c
	@echo 'Building $(SDK_PATH)/platform/service/legacy_hal/src/base-replacement.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/service/legacy_hal/src/base-replacement.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/legacy_hal/src/base-replacement.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/legacy_hal/src/base-replacement.o

$(OUTPUT_DIR)/sdk/platform/service/legacy_hal/src/crc.o: $(SDK_PATH)/platform/service/legacy_hal/src/crc.c
	@echo 'Building $(SDK_PATH)/platform/service/legacy_hal/src/crc.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/service/legacy_hal/src/crc.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/legacy_hal/src/crc.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/legacy_hal/src/crc.o

$(OUTPUT_DIR)/sdk/platform/service/legacy_hal/src/diagnostic.o: $(SDK_PATH)/platform/service/legacy_hal/src/diagnostic.c
	@echo 'Building $(SDK_PATH)/platform/service/legacy_hal/src/diagnostic.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/service/legacy_hal/src/diagnostic.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/legacy_hal/src/diagnostic.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/legacy_hal/src/diagnostic.o

$(OUTPUT_DIR)/sdk/platform/service/legacy_hal/src/ember-phy.o: $(SDK_PATH)/platform/service/legacy_hal/src/ember-phy.c
	@echo 'Building $(SDK_PATH)/platform/service/legacy_hal/src/ember-phy.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/service/legacy_hal/src/ember-phy.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/legacy_hal/src/ember-phy.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/legacy_hal/src/ember-phy.o

$(OUTPUT_DIR)/sdk/platform/service/legacy_hal/src/faults.o: $(SDK_PATH)/platform/service/legacy_hal/src/faults.s
	@echo 'Building $(SDK_PATH)/platform/service/legacy_hal/src/faults.s'
	$(ECHO)$(CC) $(ASMFLAGS) -c -o $@ $(SDK_PATH)/platform/service/legacy_hal/src/faults.s
ASMDEPS_s += $(OUTPUT_DIR)/sdk/platform/service/legacy_hal/src/faults.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/legacy_hal/src/faults.o

$(OUTPUT_DIR)/sdk/platform/service/legacy_hal/src/random.o: $(SDK_PATH)/platform/service/legacy_hal/src/random.c
	@echo 'Building $(SDK_PATH)/platform/service/legacy_hal/src/random.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/service/legacy_hal/src/random.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/legacy_hal/src/random.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/legacy_hal/src/random.o

$(OUTPUT_DIR)/sdk/platform/service/legacy_hal/src/token_legacy.o: $(SDK_PATH)/platform/service/legacy_hal/src/token_legacy.c
	@echo 'Building $(SDK_PATH)/platform/service/legacy_hal/src/token_legacy.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/service/legacy_hal/src/token_legacy.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/legacy_hal/src/token_legacy.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/legacy_hal/src/token_legacy.o

$(OUTPUT_DIR)/sdk/platform/service/legacy_printf/src/sl_legacy_printf.o: $(SDK_PATH)/platform/service/legacy_printf/src/sl_legacy_printf.c
	@echo 'Building $(SDK_PATH)/platform/service/legacy_printf/src/sl_legacy_printf.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/service/legacy_printf/src/sl_legacy_printf.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/legacy_printf/src/sl_legacy_printf.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/legacy_printf/src/sl_legacy_printf.o

$(OUTPUT_DIR)/sdk/platform/service/power_manager/src/sl_power_manager.o: $(SDK_PATH)/platform/service/power_manager/src/sl_power_manager.c
	@echo 'Building $(SDK_PATH)/platform/service/power_manager/src/sl_power_manager.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/service/power_manager/src/sl_power_manager.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/power_manager/src/sl_power_manager.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/power_manager/src/sl_power_manager.o

$(OUTPUT_DIR)/sdk/platform/service/power_manager/src/sl_power_manager_debug.o: $(SDK_PATH)/platform/service/power_manager/src/sl_power_manager_debug.c
	@echo 'Building $(SDK_PATH)/platform/service/power_manager/src/sl_power_manager_debug.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/service/power_manager/src/sl_power_manager_debug.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/power_manager/src/sl_power_manager_debug.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/power_manager/src/sl_power_manager_debug.o

$(OUTPUT_DIR)/sdk/platform/service/power_manager/src/sl_power_manager_hal_s2.o: $(SDK_PATH)/platform/service/power_manager/src/sl_power_manager_hal_s2.c
	@echo 'Building $(SDK_PATH)/platform/service/power_manager/src/sl_power_manager_hal_s2.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/service/power_manager/src/sl_power_manager_hal_s2.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/power_manager/src/sl_power_manager_hal_s2.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/power_manager/src/sl_power_manager_hal_s2.o

$(OUTPUT_DIR)/sdk/platform/service/sleeptimer/src/sl_sleeptimer.o: $(SDK_PATH)/platform/service/sleeptimer/src/sl_sleeptimer.c
	@echo 'Building $(SDK_PATH)/platform/service/sleeptimer/src/sl_sleeptimer.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/service/sleeptimer/src/sl_sleeptimer.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/sleeptimer/src/sl_sleeptimer.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/sleeptimer/src/sl_sleeptimer.o

$(OUTPUT_DIR)/sdk/platform/service/sleeptimer/src/sl_sleeptimer_hal_burtc.o: $(SDK_PATH)/platform/service/sleeptimer/src/sl_sleeptimer_hal_burtc.c
	@echo 'Building $(SDK_PATH)/platform/service/sleeptimer/src/sl_sleeptimer_hal_burtc.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/service/sleeptimer/src/sl_sleeptimer_hal_burtc.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/sleeptimer/src/sl_sleeptimer_hal_burtc.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/sleeptimer/src/sl_sleeptimer_hal_burtc.o

$(OUTPUT_DIR)/sdk/platform/service/sleeptimer/src/sl_sleeptimer_hal_sysrtc.o: $(SDK_PATH)/platform/service/sleeptimer/src/sl_sleeptimer_hal_sysrtc.c
	@echo 'Building $(SDK_PATH)/platform/service/sleeptimer/src/sl_sleeptimer_hal_sysrtc.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/service/sleeptimer/src/sl_sleeptimer_hal_sysrtc.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/sleeptimer/src/sl_sleeptimer_hal_sysrtc.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/sleeptimer/src/sl_sleeptimer_hal_sysrtc.o

$(OUTPUT_DIR)/sdk/platform/service/system/src/sl_system_init.o: $(SDK_PATH)/platform/service/system/src/sl_system_init.c
	@echo 'Building $(SDK_PATH)/platform/service/system/src/sl_system_init.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/service/system/src/sl_system_init.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/system/src/sl_system_init.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/system/src/sl_system_init.o

$(OUTPUT_DIR)/sdk/platform/service/system/src/sl_system_process_action.o: $(SDK_PATH)/platform/service/system/src/sl_system_process_action.c
	@echo 'Building $(SDK_PATH)/platform/service/system/src/sl_system_process_action.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/service/system/src/sl_system_process_action.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/system/src/sl_system_process_action.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/system/src/sl_system_process_action.o

$(OUTPUT_DIR)/sdk/platform/service/token_manager/src/sl_token_def.o: $(SDK_PATH)/platform/service/token_manager/src/sl_token_def.c
	@echo 'Building $(SDK_PATH)/platform/service/token_manager/src/sl_token_def.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/service/token_manager/src/sl_token_def.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/token_manager/src/sl_token_def.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/token_manager/src/sl_token_def.o

$(OUTPUT_DIR)/sdk/platform/service/token_manager/src/sl_token_manager.o: $(SDK_PATH)/platform/service/token_manager/src/sl_token_manager.c
	@echo 'Building $(SDK_PATH)/platform/service/token_manager/src/sl_token_manager.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/service/token_manager/src/sl_token_manager.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/token_manager/src/sl_token_manager.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/token_manager/src/sl_token_manager.o

$(OUTPUT_DIR)/sdk/platform/service/token_manager/src/sl_token_manufacturing.o: $(SDK_PATH)/platform/service/token_manager/src/sl_token_manufacturing.c
	@echo 'Building $(SDK_PATH)/platform/service/token_manager/src/sl_token_manufacturing.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/service/token_manager/src/sl_token_manufacturing.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/token_manager/src/sl_token_manufacturing.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/token_manager/src/sl_token_manufacturing.o

$(OUTPUT_DIR)/sdk/platform/service/udelay/src/sl_udelay.o: $(SDK_PATH)/platform/service/udelay/src/sl_udelay.c
	@echo 'Building $(SDK_PATH)/platform/service/udelay/src/sl_udelay.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/platform/service/udelay/src/sl_udelay.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/udelay/src/sl_udelay.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/udelay/src/sl_udelay.o

$(OUTPUT_DIR)/sdk/platform/service/udelay/src/sl_udelay_armv6m_gcc.o: $(SDK_PATH)/platform/service/udelay/src/sl_udelay_armv6m_gcc.S
	@echo 'Building $(SDK_PATH)/platform/service/udelay/src/sl_udelay_armv6m_gcc.S'
	$(ECHO)$(CC) $(ASMFLAGS) -c -o $@ $(SDK_PATH)/platform/service/udelay/src/sl_udelay_armv6m_gcc.S
ASMDEPS_S += $(OUTPUT_DIR)/sdk/platform/service/udelay/src/sl_udelay_armv6m_gcc.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/udelay/src/sl_udelay_armv6m_gcc.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/cli/core-cli.o: $(SDK_PATH)/protocol/zigbee/app/framework/cli/core-cli.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/cli/core-cli.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/cli/core-cli.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/cli/core-cli.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/cli/core-cli.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/cli/network-cli.o: $(SDK_PATH)/protocol/zigbee/app/framework/cli/network-cli.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/cli/network-cli.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/cli/network-cli.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/cli/network-cli.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/cli/network-cli.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/cli/option-cli.o: $(SDK_PATH)/protocol/zigbee/app/framework/cli/option-cli.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/cli/option-cli.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/cli/option-cli.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/cli/option-cli.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/cli/option-cli.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/cli/security-cli.o: $(SDK_PATH)/protocol/zigbee/app/framework/cli/security-cli.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/cli/security-cli.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/cli/security-cli.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/cli/security-cli.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/cli/security-cli.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/cli/zcl-cli.o: $(SDK_PATH)/protocol/zigbee/app/framework/cli/zcl-cli.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/cli/zcl-cli.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/cli/zcl-cli.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/cli/zcl-cli.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/cli/zcl-cli.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/cli/zdo-cli.o: $(SDK_PATH)/protocol/zigbee/app/framework/cli/zdo-cli.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/cli/zdo-cli.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/cli/zdo-cli.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/cli/zdo-cli.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/cli/zdo-cli.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/common/zigbee_app_framework_common.o: $(SDK_PATH)/protocol/zigbee/app/framework/common/zigbee_app_framework_common.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/common/zigbee_app_framework_common.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/common/zigbee_app_framework_common.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/common/zigbee_app_framework_common.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/common/zigbee_app_framework_common.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/common/zigbee_app_framework_sleep.o: $(SDK_PATH)/protocol/zigbee/app/framework/common/zigbee_app_framework_sleep.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/common/zigbee_app_framework_sleep.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/common/zigbee_app_framework_sleep.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/common/zigbee_app_framework_sleep.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/common/zigbee_app_framework_sleep.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/common/zigbee_app_framework_sleep_cli.o: $(SDK_PATH)/protocol/zigbee/app/framework/common/zigbee_app_framework_sleep_cli.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/common/zigbee_app_framework_sleep_cli.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/common/zigbee_app_framework_sleep_cli.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/common/zigbee_app_framework_sleep_cli.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/common/zigbee_app_framework_sleep_cli.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/common/zigbee_app_framework_stack_cb.o: $(SDK_PATH)/protocol/zigbee/app/framework/common/zigbee_app_framework_stack_cb.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/common/zigbee_app_framework_stack_cb.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/common/zigbee_app_framework_stack_cb.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/common/zigbee_app_framework_stack_cb.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/common/zigbee_app_framework_stack_cb.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/address-table/address-table-cli.o: $(SDK_PATH)/protocol/zigbee/app/framework/plugin/address-table/address-table-cli.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/plugin/address-table/address-table-cli.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/plugin/address-table/address-table-cli.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/address-table/address-table-cli.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/address-table/address-table-cli.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/address-table/address-table.o: $(SDK_PATH)/protocol/zigbee/app/framework/plugin/address-table/address-table.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/plugin/address-table/address-table.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/plugin/address-table/address-table.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/address-table/address-table.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/address-table/address-table.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/counters/counters-cb.o: $(SDK_PATH)/protocol/zigbee/app/framework/plugin/counters/counters-cb.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/plugin/counters/counters-cb.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/plugin/counters/counters-cb.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/counters/counters-cb.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/counters/counters-cb.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/counters/counters-cli.o: $(SDK_PATH)/protocol/zigbee/app/framework/plugin/counters/counters-cli.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/plugin/counters/counters-cli.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/plugin/counters/counters-cli.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/counters/counters-cli.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/counters/counters-cli.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/counters/counters-ota.o: $(SDK_PATH)/protocol/zigbee/app/framework/plugin/counters/counters-ota.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/plugin/counters/counters-ota.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/plugin/counters/counters-ota.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/counters/counters-ota.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/counters/counters-ota.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/counters/counters-soc.o: $(SDK_PATH)/protocol/zigbee/app/framework/plugin/counters/counters-soc.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/plugin/counters/counters-soc.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/plugin/counters/counters-soc.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/counters/counters-soc.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/counters/counters-soc.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/debug-print/sl_zigbee_debug_print.o: $(SDK_PATH)/protocol/zigbee/app/framework/plugin/debug-print/sl_zigbee_debug_print.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/plugin/debug-print/sl_zigbee_debug_print.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/plugin/debug-print/sl_zigbee_debug_print.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/debug-print/sl_zigbee_debug_print.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/debug-print/sl_zigbee_debug_print.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/form-and-join/form-and-join-afv2.o: $(SDK_PATH)/protocol/zigbee/app/framework/plugin/form-and-join/form-and-join-afv2.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/plugin/form-and-join/form-and-join-afv2.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/plugin/form-and-join/form-and-join-afv2.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/form-and-join/form-and-join-afv2.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/form-and-join/form-and-join-afv2.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/form-and-join/form-and-join-cb.o: $(SDK_PATH)/protocol/zigbee/app/framework/plugin/form-and-join/form-and-join-cb.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/plugin/form-and-join/form-and-join-cb.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/plugin/form-and-join/form-and-join-cb.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/form-and-join/form-and-join-cb.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/form-and-join/form-and-join-cb.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/fragmentation/fragmentation-cli.o: $(SDK_PATH)/protocol/zigbee/app/framework/plugin/fragmentation/fragmentation-cli.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/plugin/fragmentation/fragmentation-cli.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/plugin/fragmentation/fragmentation-cli.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/fragmentation/fragmentation-cli.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/fragmentation/fragmentation-cli.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/fragmentation/fragmentation-soc.o: $(SDK_PATH)/protocol/zigbee/app/framework/plugin/fragmentation/fragmentation-soc.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/plugin/fragmentation/fragmentation-soc.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/plugin/fragmentation/fragmentation-soc.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/fragmentation/fragmentation-soc.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/fragmentation/fragmentation-soc.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/fragmentation/fragmentation.o: $(SDK_PATH)/protocol/zigbee/app/framework/plugin/fragmentation/fragmentation.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/plugin/fragmentation/fragmentation.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/plugin/fragmentation/fragmentation.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/fragmentation/fragmentation.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/fragmentation/fragmentation.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/key-establishment/key-establishment-cb.o: $(SDK_PATH)/protocol/zigbee/app/framework/plugin/key-establishment/key-establishment-cb.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/plugin/key-establishment/key-establishment-cb.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/plugin/key-establishment/key-establishment-cb.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/key-establishment/key-establishment-cb.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/key-establishment/key-establishment-cb.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/key-establishment/key-establishment-cli.o: $(SDK_PATH)/protocol/zigbee/app/framework/plugin/key-establishment/key-establishment-cli.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/plugin/key-establishment/key-establishment-cli.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/plugin/key-establishment/key-establishment-cli.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/key-establishment/key-establishment-cli.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/key-establishment/key-establishment-cli.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/key-establishment/key-establishment-curve-support.o: $(SDK_PATH)/protocol/zigbee/app/framework/plugin/key-establishment/key-establishment-curve-support.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/plugin/key-establishment/key-establishment-curve-support.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/plugin/key-establishment/key-establishment-curve-support.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/key-establishment/key-establishment-curve-support.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/key-establishment/key-establishment-curve-support.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/key-establishment/key-establishment-storage-buffers.o: $(SDK_PATH)/protocol/zigbee/app/framework/plugin/key-establishment/key-establishment-storage-buffers.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/plugin/key-establishment/key-establishment-storage-buffers.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/plugin/key-establishment/key-establishment-storage-buffers.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/key-establishment/key-establishment-storage-buffers.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/key-establishment/key-establishment-storage-buffers.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/key-establishment/key-establishment.o: $(SDK_PATH)/protocol/zigbee/app/framework/plugin/key-establishment/key-establishment.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/plugin/key-establishment/key-establishment.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/plugin/key-establishment/key-establishment.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/key-establishment/key-establishment.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/key-establishment/key-establishment.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/network-find/network-find-cb.o: $(SDK_PATH)/protocol/zigbee/app/framework/plugin/network-find/network-find-cb.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/plugin/network-find/network-find-cb.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/plugin/network-find/network-find-cb.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/network-find/network-find-cb.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/network-find/network-find-cb.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/network-find/network-find-cli.o: $(SDK_PATH)/protocol/zigbee/app/framework/plugin/network-find/network-find-cli.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/plugin/network-find/network-find-cli.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/plugin/network-find/network-find-cli.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/network-find/network-find-cli.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/network-find/network-find-cli.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/network-find/network-find.o: $(SDK_PATH)/protocol/zigbee/app/framework/plugin/network-find/network-find.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/plugin/network-find/network-find.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/plugin/network-find/network-find.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/network-find/network-find.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/network-find/network-find.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/scan-dispatch/scan-dispatch.o: $(SDK_PATH)/protocol/zigbee/app/framework/plugin/scan-dispatch/scan-dispatch.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/plugin/scan-dispatch/scan-dispatch.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/plugin/scan-dispatch/scan-dispatch.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/scan-dispatch/scan-dispatch.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/scan-dispatch/scan-dispatch.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/zcl_cli/zigbee-zcl-cli.o: $(SDK_PATH)/protocol/zigbee/app/framework/plugin/zcl_cli/zigbee-zcl-cli.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/plugin/zcl_cli/zigbee-zcl-cli.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/plugin/zcl_cli/zigbee-zcl-cli.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/zcl_cli/zigbee-zcl-cli.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/zcl_cli/zigbee-zcl-cli.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/zcl_cli/zigbee-zcl-custom-cluster-cli.o: $(SDK_PATH)/protocol/zigbee/app/framework/plugin/zcl_cli/zigbee-zcl-custom-cluster-cli.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/plugin/zcl_cli/zigbee-zcl-custom-cluster-cli.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/plugin/zcl_cli/zigbee-zcl-custom-cluster-cli.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/zcl_cli/zigbee-zcl-custom-cluster-cli.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/zcl_cli/zigbee-zcl-custom-cluster-cli.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/zcl_cli/zigbee-zcl-global-cli.o: $(SDK_PATH)/protocol/zigbee/app/framework/plugin/zcl_cli/zigbee-zcl-global-cli.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/plugin/zcl_cli/zigbee-zcl-global-cli.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/plugin/zcl_cli/zigbee-zcl-global-cli.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/zcl_cli/zigbee-zcl-global-cli.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/plugin/zcl_cli/zigbee-zcl-global-cli.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/security/af-node.o: $(SDK_PATH)/protocol/zigbee/app/framework/security/af-node.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/security/af-node.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/security/af-node.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/security/af-node.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/security/af-node.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/security/af-security-common.o: $(SDK_PATH)/protocol/zigbee/app/framework/security/af-security-common.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/security/af-security-common.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/security/af-security-common.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/security/af-security-common.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/security/af-security-common.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/security/af-trust-center.o: $(SDK_PATH)/protocol/zigbee/app/framework/security/af-trust-center.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/security/af-trust-center.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/security/af-trust-center.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/security/af-trust-center.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/security/af-trust-center.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/security/crypto-state.o: $(SDK_PATH)/protocol/zigbee/app/framework/security/crypto-state.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/security/crypto-state.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/security/crypto-state.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/security/crypto-state.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/security/crypto-state.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/af-common.o: $(SDK_PATH)/protocol/zigbee/app/framework/util/af-common.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/util/af-common.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/util/af-common.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/af-common.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/af-common.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/af-event.o: $(SDK_PATH)/protocol/zigbee/app/framework/util/af-event.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/util/af-event.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/util/af-event.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/af-event.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/af-event.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/af-soc.o: $(SDK_PATH)/protocol/zigbee/app/framework/util/af-soc.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/util/af-soc.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/util/af-soc.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/af-soc.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/af-soc.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/attribute-size.o: $(SDK_PATH)/protocol/zigbee/app/framework/util/attribute-size.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/util/attribute-size.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/util/attribute-size.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/attribute-size.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/attribute-size.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/attribute-storage.o: $(SDK_PATH)/protocol/zigbee/app/framework/util/attribute-storage.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/util/attribute-storage.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/util/attribute-storage.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/attribute-storage.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/attribute-storage.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/attribute-table.o: $(SDK_PATH)/protocol/zigbee/app/framework/util/attribute-table.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/util/attribute-table.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/util/attribute-table.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/attribute-table.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/attribute-table.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/client-api.o: $(SDK_PATH)/protocol/zigbee/app/framework/util/client-api.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/util/client-api.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/util/client-api.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/client-api.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/client-api.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/global-callback.o: $(SDK_PATH)/protocol/zigbee/app/framework/util/global-callback.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/util/global-callback.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/util/global-callback.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/global-callback.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/global-callback.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/global-other-callback.o: $(SDK_PATH)/protocol/zigbee/app/framework/util/global-other-callback.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/util/global-other-callback.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/util/global-other-callback.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/global-other-callback.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/global-other-callback.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/message.o: $(SDK_PATH)/protocol/zigbee/app/framework/util/message.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/util/message.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/util/message.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/message.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/message.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/multi-network.o: $(SDK_PATH)/protocol/zigbee/app/framework/util/multi-network.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/util/multi-network.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/util/multi-network.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/multi-network.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/multi-network.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/print-formatter.o: $(SDK_PATH)/protocol/zigbee/app/framework/util/print-formatter.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/util/print-formatter.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/util/print-formatter.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/print-formatter.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/print-formatter.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/print.o: $(SDK_PATH)/protocol/zigbee/app/framework/util/print.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/util/print.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/util/print.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/print.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/print.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/process-cluster-message.o: $(SDK_PATH)/protocol/zigbee/app/framework/util/process-cluster-message.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/util/process-cluster-message.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/util/process-cluster-message.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/process-cluster-message.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/process-cluster-message.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/process-global-message.o: $(SDK_PATH)/protocol/zigbee/app/framework/util/process-global-message.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/util/process-global-message.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/util/process-global-message.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/process-global-message.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/process-global-message.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/service-discovery-common.o: $(SDK_PATH)/protocol/zigbee/app/framework/util/service-discovery-common.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/util/service-discovery-common.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/util/service-discovery-common.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/service-discovery-common.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/service-discovery-common.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/service-discovery-soc.o: $(SDK_PATH)/protocol/zigbee/app/framework/util/service-discovery-soc.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/util/service-discovery-soc.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/util/service-discovery-soc.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/service-discovery-soc.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/service-discovery-soc.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/time-util.o: $(SDK_PATH)/protocol/zigbee/app/framework/util/time-util.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/util/time-util.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/util/time-util.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/time-util.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/time-util.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/util.o: $(SDK_PATH)/protocol/zigbee/app/framework/util/util.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/framework/util/util.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/framework/util/util.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/util.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/framework/util/util.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/util/common/form-and-join-node-adapter.o: $(SDK_PATH)/protocol/zigbee/app/util/common/form-and-join-node-adapter.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/util/common/form-and-join-node-adapter.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/util/common/form-and-join-node-adapter.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/util/common/form-and-join-node-adapter.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/util/common/form-and-join-node-adapter.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/util/common/form-and-join.o: $(SDK_PATH)/protocol/zigbee/app/util/common/form-and-join.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/util/common/form-and-join.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/util/common/form-and-join.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/util/common/form-and-join.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/util/common/form-and-join.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/util/common/library.o: $(SDK_PATH)/protocol/zigbee/app/util/common/library.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/util/common/library.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/util/common/library.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/util/common/library.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/util/common/library.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/util/security/security-address-cache.o: $(SDK_PATH)/protocol/zigbee/app/util/security/security-address-cache.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/util/security/security-address-cache.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/util/security/security-address-cache.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/util/security/security-address-cache.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/util/security/security-address-cache.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/util/serial/sl_zigbee_command_interpreter.o: $(SDK_PATH)/protocol/zigbee/app/util/serial/sl_zigbee_command_interpreter.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/util/serial/sl_zigbee_command_interpreter.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/util/serial/sl_zigbee_command_interpreter.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/util/serial/sl_zigbee_command_interpreter.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/util/serial/sl_zigbee_command_interpreter.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/util/zigbee-framework/zigbee-device-common.o: $(SDK_PATH)/protocol/zigbee/app/util/zigbee-framework/zigbee-device-common.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/util/zigbee-framework/zigbee-device-common.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/util/zigbee-framework/zigbee-device-common.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/util/zigbee-framework/zigbee-device-common.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/util/zigbee-framework/zigbee-device-common.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/app/util/zigbee-framework/zigbee-device-library.o: $(SDK_PATH)/protocol/zigbee/app/util/zigbee-framework/zigbee-device-library.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/app/util/zigbee-framework/zigbee-device-library.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/app/util/zigbee-framework/zigbee-device-library.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/util/zigbee-framework/zigbee-device-library.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/app/util/zigbee-framework/zigbee-device-library.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/stack/config/ember-configuration.o: $(SDK_PATH)/protocol/zigbee/stack/config/ember-configuration.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/stack/config/ember-configuration.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/stack/config/ember-configuration.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/stack/config/ember-configuration.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/stack/config/ember-configuration.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/stack/framework/aes-ecb.o: $(SDK_PATH)/protocol/zigbee/stack/framework/aes-ecb.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/stack/framework/aes-ecb.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/stack/framework/aes-ecb.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/stack/framework/aes-ecb.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/stack/framework/aes-ecb.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/stack/framework/ccm-star.o: $(SDK_PATH)/protocol/zigbee/stack/framework/ccm-star.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/stack/framework/ccm-star.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/stack/framework/ccm-star.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/stack/framework/ccm-star.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/stack/framework/ccm-star.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/stack/framework/debug-extended-stub.o: $(SDK_PATH)/protocol/zigbee/stack/framework/debug-extended-stub.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/stack/framework/debug-extended-stub.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/stack/framework/debug-extended-stub.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/stack/framework/debug-extended-stub.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/stack/framework/debug-extended-stub.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/stack/framework/strong-random-api.o: $(SDK_PATH)/protocol/zigbee/stack/framework/strong-random-api.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/stack/framework/strong-random-api.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/stack/framework/strong-random-api.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/stack/framework/strong-random-api.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/stack/framework/strong-random-api.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/stack/framework/zigbee-event-logger-stub-gen.o: $(SDK_PATH)/protocol/zigbee/stack/framework/zigbee-event-logger-stub-gen.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/stack/framework/zigbee-event-logger-stub-gen.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/stack/framework/zigbee-event-logger-stub-gen.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/stack/framework/zigbee-event-logger-stub-gen.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/stack/framework/zigbee-event-logger-stub-gen.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/stack/gp/gp-stub.o: $(SDK_PATH)/protocol/zigbee/stack/gp/gp-stub.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/stack/gp/gp-stub.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/stack/gp/gp-stub.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/stack/gp/gp-stub.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/stack/gp/gp-stub.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/stack/mac/mac-info-element-parsing-stub.o: $(SDK_PATH)/protocol/zigbee/stack/mac/mac-info-element-parsing-stub.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/stack/mac/mac-info-element-parsing-stub.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/stack/mac/mac-info-element-parsing-stub.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/stack/mac/mac-info-element-parsing-stub.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/stack/mac/mac-info-element-parsing-stub.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/stack/routing/zigbee/enhanced-beacon-request-stub.o: $(SDK_PATH)/protocol/zigbee/stack/routing/zigbee/enhanced-beacon-request-stub.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/stack/routing/zigbee/enhanced-beacon-request-stub.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/stack/routing/zigbee/enhanced-beacon-request-stub.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/stack/routing/zigbee/enhanced-beacon-request-stub.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/stack/routing/zigbee/enhanced-beacon-request-stub.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/stack/security/cbke-crypto-engine-dsa-sign-stub.o: $(SDK_PATH)/protocol/zigbee/stack/security/cbke-crypto-engine-dsa-sign-stub.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/stack/security/cbke-crypto-engine-dsa-sign-stub.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/stack/security/cbke-crypto-engine-dsa-sign-stub.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/stack/security/cbke-crypto-engine-dsa-sign-stub.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/stack/security/cbke-crypto-engine-dsa-sign-stub.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/stack/security/cbke-crypto-engine-dsa-verify-283k1-stub.o: $(SDK_PATH)/protocol/zigbee/stack/security/cbke-crypto-engine-dsa-verify-283k1-stub.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/stack/security/cbke-crypto-engine-dsa-verify-283k1-stub.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/stack/security/cbke-crypto-engine-dsa-verify-283k1-stub.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/stack/security/cbke-crypto-engine-dsa-verify-283k1-stub.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/stack/security/cbke-crypto-engine-dsa-verify-283k1-stub.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/stack/security/cbke-crypto-engine-dsa-verify-stub.o: $(SDK_PATH)/protocol/zigbee/stack/security/cbke-crypto-engine-dsa-verify-stub.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/stack/security/cbke-crypto-engine-dsa-verify-stub.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/stack/security/cbke-crypto-engine-dsa-verify-stub.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/stack/security/cbke-crypto-engine-dsa-verify-stub.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/stack/security/cbke-crypto-engine-dsa-verify-stub.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/stack/zigbee/end-device-bind-stub.o: $(SDK_PATH)/protocol/zigbee/stack/zigbee/end-device-bind-stub.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/stack/zigbee/end-device-bind-stub.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/stack/zigbee/end-device-bind-stub.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/stack/zigbee/end-device-bind-stub.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/stack/zigbee/end-device-bind-stub.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/stack/zigbee/zdo-r22-stub.o: $(SDK_PATH)/protocol/zigbee/stack/zigbee/zdo-r22-stub.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/stack/zigbee/zdo-r22-stub.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/stack/zigbee/zdo-r22-stub.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/stack/zigbee/zdo-r22-stub.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/stack/zigbee/zdo-r22-stub.o

$(OUTPUT_DIR)/sdk/protocol/zigbee/stack/zll/zll-stubs.o: $(SDK_PATH)/protocol/zigbee/stack/zll/zll-stubs.c
	@echo 'Building $(SDK_PATH)/protocol/zigbee/stack/zll/zll-stubs.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/protocol/zigbee/stack/zll/zll-stubs.c
CDEPS += $(OUTPUT_DIR)/sdk/protocol/zigbee/stack/zll/zll-stubs.d
OBJS += $(OUTPUT_DIR)/sdk/protocol/zigbee/stack/zll/zll-stubs.o

$(OUTPUT_DIR)/sdk/util/silicon_labs/silabs_core/memory_manager/sl_malloc.o: $(SDK_PATH)/util/silicon_labs/silabs_core/memory_manager/sl_malloc.c
	@echo 'Building $(SDK_PATH)/util/silicon_labs/silabs_core/memory_manager/sl_malloc.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/silicon_labs/silabs_core/memory_manager/sl_malloc.c
CDEPS += $(OUTPUT_DIR)/sdk/util/silicon_labs/silabs_core/memory_manager/sl_malloc.d
OBJS += $(OUTPUT_DIR)/sdk/util/silicon_labs/silabs_core/memory_manager/sl_malloc.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/cipher.o: $(SDK_PATH)/util/third_party/crypto/mbedtls/library/cipher.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/mbedtls/library/cipher.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/mbedtls/library/cipher.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/cipher.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/cipher.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/cipher_wrap.o: $(SDK_PATH)/util/third_party/crypto/mbedtls/library/cipher_wrap.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/mbedtls/library/cipher_wrap.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/mbedtls/library/cipher_wrap.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/cipher_wrap.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/cipher_wrap.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/error.o: $(SDK_PATH)/util/third_party/crypto/mbedtls/library/error.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/mbedtls/library/error.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/mbedtls/library/error.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/error.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/error.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/platform.o: $(SDK_PATH)/util/third_party/crypto/mbedtls/library/platform.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/mbedtls/library/platform.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/mbedtls/library/platform.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/platform.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/platform.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/platform_util.o: $(SDK_PATH)/util/third_party/crypto/mbedtls/library/platform_util.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/mbedtls/library/platform_util.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/mbedtls/library/platform_util.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/platform_util.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/platform_util.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/psa_crypto.o: $(SDK_PATH)/util/third_party/crypto/mbedtls/library/psa_crypto.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/mbedtls/library/psa_crypto.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/mbedtls/library/psa_crypto.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/psa_crypto.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/psa_crypto.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/psa_crypto_aead.o: $(SDK_PATH)/util/third_party/crypto/mbedtls/library/psa_crypto_aead.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/mbedtls/library/psa_crypto_aead.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/mbedtls/library/psa_crypto_aead.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/psa_crypto_aead.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/psa_crypto_aead.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/psa_crypto_cipher.o: $(SDK_PATH)/util/third_party/crypto/mbedtls/library/psa_crypto_cipher.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/mbedtls/library/psa_crypto_cipher.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/mbedtls/library/psa_crypto_cipher.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/psa_crypto_cipher.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/psa_crypto_cipher.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/psa_crypto_client.o: $(SDK_PATH)/util/third_party/crypto/mbedtls/library/psa_crypto_client.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/mbedtls/library/psa_crypto_client.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/mbedtls/library/psa_crypto_client.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/psa_crypto_client.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/psa_crypto_client.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/psa_crypto_driver_wrappers.o: $(SDK_PATH)/util/third_party/crypto/mbedtls/library/psa_crypto_driver_wrappers.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/mbedtls/library/psa_crypto_driver_wrappers.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/mbedtls/library/psa_crypto_driver_wrappers.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/psa_crypto_driver_wrappers.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/psa_crypto_driver_wrappers.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/psa_crypto_ecp.o: $(SDK_PATH)/util/third_party/crypto/mbedtls/library/psa_crypto_ecp.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/mbedtls/library/psa_crypto_ecp.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/mbedtls/library/psa_crypto_ecp.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/psa_crypto_ecp.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/psa_crypto_ecp.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/psa_crypto_hash.o: $(SDK_PATH)/util/third_party/crypto/mbedtls/library/psa_crypto_hash.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/mbedtls/library/psa_crypto_hash.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/mbedtls/library/psa_crypto_hash.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/psa_crypto_hash.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/psa_crypto_hash.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/psa_crypto_mac.o: $(SDK_PATH)/util/third_party/crypto/mbedtls/library/psa_crypto_mac.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/mbedtls/library/psa_crypto_mac.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/mbedtls/library/psa_crypto_mac.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/psa_crypto_mac.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/psa_crypto_mac.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/psa_crypto_rsa.o: $(SDK_PATH)/util/third_party/crypto/mbedtls/library/psa_crypto_rsa.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/mbedtls/library/psa_crypto_rsa.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/mbedtls/library/psa_crypto_rsa.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/psa_crypto_rsa.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/psa_crypto_rsa.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/psa_crypto_se.o: $(SDK_PATH)/util/third_party/crypto/mbedtls/library/psa_crypto_se.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/mbedtls/library/psa_crypto_se.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/mbedtls/library/psa_crypto_se.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/psa_crypto_se.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/psa_crypto_se.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/psa_crypto_slot_management.o: $(SDK_PATH)/util/third_party/crypto/mbedtls/library/psa_crypto_slot_management.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/mbedtls/library/psa_crypto_slot_management.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/mbedtls/library/psa_crypto_slot_management.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/psa_crypto_slot_management.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/psa_crypto_slot_management.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/psa_crypto_storage.o: $(SDK_PATH)/util/third_party/crypto/mbedtls/library/psa_crypto_storage.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/mbedtls/library/psa_crypto_storage.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/mbedtls/library/psa_crypto_storage.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/psa_crypto_storage.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/psa_crypto_storage.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/psa_its_file.o: $(SDK_PATH)/util/third_party/crypto/mbedtls/library/psa_its_file.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/mbedtls/library/psa_its_file.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/mbedtls/library/psa_its_file.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/psa_its_file.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/psa_its_file.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/threading.o: $(SDK_PATH)/util/third_party/crypto/mbedtls/library/threading.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/mbedtls/library/threading.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/mbedtls/library/threading.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/threading.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/mbedtls/library/threading.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager.o: $(SDK_PATH)/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_attestation.o: $(SDK_PATH)/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_attestation.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_attestation.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_attestation.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_attestation.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_attestation.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_cipher.o: $(SDK_PATH)/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_cipher.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_cipher.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_cipher.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_cipher.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_cipher.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_entropy.o: $(SDK_PATH)/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_entropy.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_entropy.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_entropy.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_entropy.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_entropy.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_hash.o: $(SDK_PATH)/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_hash.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_hash.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_hash.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_hash.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_hash.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_key_derivation.o: $(SDK_PATH)/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_key_derivation.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_key_derivation.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_key_derivation.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_key_derivation.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_key_derivation.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_key_handling.o: $(SDK_PATH)/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_key_handling.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_key_handling.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_key_handling.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_key_handling.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_key_handling.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_signature.o: $(SDK_PATH)/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_signature.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_signature.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_signature.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_signature.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_signature.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_util.o: $(SDK_PATH)/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_util.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_util.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_util.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_util.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/se_manager/src/sl_se_manager_util.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_mbedtls_support/src/sl_mbedtls.o: $(SDK_PATH)/util/third_party/crypto/sl_component/sl_mbedtls_support/src/sl_mbedtls.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/sl_component/sl_mbedtls_support/src/sl_mbedtls.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/sl_component/sl_mbedtls_support/src/sl_mbedtls.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_mbedtls_support/src/sl_mbedtls.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_mbedtls_support/src/sl_mbedtls.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_psa_driver_common.o: $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_psa_driver_common.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_psa_driver_common.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_psa_driver_common.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_psa_driver_common.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_psa_driver_common.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_psa_driver_init.o: $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_psa_driver_init.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_psa_driver_init.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_psa_driver_init.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_psa_driver_init.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_psa_driver_init.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_psa_trng.o: $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_psa_trng.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_psa_trng.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_psa_trng.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_psa_trng.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_psa_trng.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_driver_aead.o: $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_driver_aead.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_driver_aead.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_driver_aead.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_driver_aead.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_driver_aead.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_driver_builtin_keys.o: $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_driver_builtin_keys.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_driver_builtin_keys.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_driver_builtin_keys.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_driver_builtin_keys.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_driver_builtin_keys.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_driver_cipher.o: $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_driver_cipher.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_driver_cipher.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_driver_cipher.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_driver_cipher.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_driver_cipher.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_driver_key_derivation.o: $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_driver_key_derivation.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_driver_key_derivation.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_driver_key_derivation.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_driver_key_derivation.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_driver_key_derivation.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_driver_key_management.o: $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_driver_key_management.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_driver_key_management.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_driver_key_management.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_driver_key_management.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_driver_key_management.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_driver_mac.o: $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_driver_mac.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_driver_mac.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_driver_mac.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_driver_mac.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_driver_mac.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_driver_signature.o: $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_driver_signature.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_driver_signature.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_driver_signature.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_driver_signature.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_driver_signature.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_opaque_driver_aead.o: $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_opaque_driver_aead.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_opaque_driver_aead.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_opaque_driver_aead.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_opaque_driver_aead.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_opaque_driver_aead.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_opaque_driver_cipher.o: $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_opaque_driver_cipher.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_opaque_driver_cipher.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_opaque_driver_cipher.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_opaque_driver_cipher.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_opaque_driver_cipher.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_opaque_driver_mac.o: $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_opaque_driver_mac.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_opaque_driver_mac.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_opaque_driver_mac.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_opaque_driver_mac.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_opaque_driver_mac.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_opaque_key_derivation.o: $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_opaque_key_derivation.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_opaque_key_derivation.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_opaque_key_derivation.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_opaque_key_derivation.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_opaque_key_derivation.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_transparent_driver_aead.o: $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_transparent_driver_aead.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_transparent_driver_aead.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_transparent_driver_aead.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_transparent_driver_aead.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_transparent_driver_aead.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_transparent_driver_cipher.o: $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_transparent_driver_cipher.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_transparent_driver_cipher.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_transparent_driver_cipher.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_transparent_driver_cipher.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_transparent_driver_cipher.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_transparent_driver_hash.o: $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_transparent_driver_hash.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_transparent_driver_hash.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_transparent_driver_hash.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_transparent_driver_hash.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_transparent_driver_hash.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_transparent_driver_mac.o: $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_transparent_driver_mac.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_transparent_driver_mac.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_transparent_driver_mac.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_transparent_driver_mac.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_transparent_driver_mac.o

$(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_transparent_key_derivation.o: $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_transparent_key_derivation.c
	@echo 'Building $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_transparent_key_derivation.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_transparent_key_derivation.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_transparent_key_derivation.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/crypto/sl_component/sl_psa_driver/src/sli_se_transparent_key_derivation.o

$(OUTPUT_DIR)/sdk/util/third_party/printf/printf.o: $(SDK_PATH)/util/third_party/printf/printf.c
	@echo 'Building $(SDK_PATH)/util/third_party/printf/printf.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/printf/printf.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/printf/printf.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/printf/printf.o

$(OUTPUT_DIR)/sdk/util/third_party/printf/src/iostream_printf.o: $(SDK_PATH)/util/third_party/printf/src/iostream_printf.c
	@echo 'Building $(SDK_PATH)/util/third_party/printf/src/iostream_printf.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(SDK_PATH)/util/third_party/printf/src/iostream_printf.c
CDEPS += $(OUTPUT_DIR)/sdk/util/third_party/printf/src/iostream_printf.d
OBJS += $(OUTPUT_DIR)/sdk/util/third_party/printf/src/iostream_printf.o

$(OUTPUT_DIR)/project/autogen/sl_board_default_init.o: autogen/sl_board_default_init.c
	@echo 'Building autogen/sl_board_default_init.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ autogen/sl_board_default_init.c
CDEPS += $(OUTPUT_DIR)/project/autogen/sl_board_default_init.d
OBJS += $(OUTPUT_DIR)/project/autogen/sl_board_default_init.o

$(OUTPUT_DIR)/project/autogen/sl_cli_command_table.o: autogen/sl_cli_command_table.c
	@echo 'Building autogen/sl_cli_command_table.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ autogen/sl_cli_command_table.c
CDEPS += $(OUTPUT_DIR)/project/autogen/sl_cli_command_table.d
OBJS += $(OUTPUT_DIR)/project/autogen/sl_cli_command_table.o

$(OUTPUT_DIR)/project/autogen/sl_cli_instances.o: autogen/sl_cli_instances.c
	@echo 'Building autogen/sl_cli_instances.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ autogen/sl_cli_instances.c
CDEPS += $(OUTPUT_DIR)/project/autogen/sl_cli_instances.d
OBJS += $(OUTPUT_DIR)/project/autogen/sl_cli_instances.o

$(OUTPUT_DIR)/project/autogen/sl_device_init_clocks.o: autogen/sl_device_init_clocks.c
	@echo 'Building autogen/sl_device_init_clocks.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ autogen/sl_device_init_clocks.c
CDEPS += $(OUTPUT_DIR)/project/autogen/sl_device_init_clocks.d
OBJS += $(OUTPUT_DIR)/project/autogen/sl_device_init_clocks.o

$(OUTPUT_DIR)/project/autogen/sl_event_handler.o: autogen/sl_event_handler.c
	@echo 'Building autogen/sl_event_handler.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ autogen/sl_event_handler.c
CDEPS += $(OUTPUT_DIR)/project/autogen/sl_event_handler.d
OBJS += $(OUTPUT_DIR)/project/autogen/sl_event_handler.o

$(OUTPUT_DIR)/project/autogen/sl_iostream_handles.o: autogen/sl_iostream_handles.c
	@echo 'Building autogen/sl_iostream_handles.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ autogen/sl_iostream_handles.c
CDEPS += $(OUTPUT_DIR)/project/autogen/sl_iostream_handles.d
OBJS += $(OUTPUT_DIR)/project/autogen/sl_iostream_handles.o

$(OUTPUT_DIR)/project/autogen/sl_iostream_init_usart_instances.o: autogen/sl_iostream_init_usart_instances.c
	@echo 'Building autogen/sl_iostream_init_usart_instances.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ autogen/sl_iostream_init_usart_instances.c
CDEPS += $(OUTPUT_DIR)/project/autogen/sl_iostream_init_usart_instances.d
OBJS += $(OUTPUT_DIR)/project/autogen/sl_iostream_init_usart_instances.o

$(OUTPUT_DIR)/project/autogen/sl_power_manager_handler.o: autogen/sl_power_manager_handler.c
	@echo 'Building autogen/sl_power_manager_handler.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ autogen/sl_power_manager_handler.c
CDEPS += $(OUTPUT_DIR)/project/autogen/sl_power_manager_handler.d
OBJS += $(OUTPUT_DIR)/project/autogen/sl_power_manager_handler.o

$(OUTPUT_DIR)/project/autogen/sl_rail_util_ieee802154_phy_select.o: autogen/sl_rail_util_ieee802154_phy_select.c
	@echo 'Building autogen/sl_rail_util_ieee802154_phy_select.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ autogen/sl_rail_util_ieee802154_phy_select.c
CDEPS += $(OUTPUT_DIR)/project/autogen/sl_rail_util_ieee802154_phy_select.d
OBJS += $(OUTPUT_DIR)/project/autogen/sl_rail_util_ieee802154_phy_select.o

$(OUTPUT_DIR)/project/autogen/sl_rail_util_ieee802154_stack_event.o: autogen/sl_rail_util_ieee802154_stack_event.c
	@echo 'Building autogen/sl_rail_util_ieee802154_stack_event.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ autogen/sl_rail_util_ieee802154_stack_event.c
CDEPS += $(OUTPUT_DIR)/project/autogen/sl_rail_util_ieee802154_stack_event.d
OBJS += $(OUTPUT_DIR)/project/autogen/sl_rail_util_ieee802154_stack_event.o

$(OUTPUT_DIR)/project/autogen/sl_simple_button_instances.o: autogen/sl_simple_button_instances.c
	@echo 'Building autogen/sl_simple_button_instances.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ autogen/sl_simple_button_instances.c
CDEPS += $(OUTPUT_DIR)/project/autogen/sl_simple_button_instances.d
OBJS += $(OUTPUT_DIR)/project/autogen/sl_simple_button_instances.o

$(OUTPUT_DIR)/project/autogen/sl_simple_led_instances.o: autogen/sl_simple_led_instances.c
	@echo 'Building autogen/sl_simple_led_instances.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ autogen/sl_simple_led_instances.c
CDEPS += $(OUTPUT_DIR)/project/autogen/sl_simple_led_instances.d
OBJS += $(OUTPUT_DIR)/project/autogen/sl_simple_led_instances.o

$(OUTPUT_DIR)/project/autogen/sli_cli_hooks.o: autogen/sli_cli_hooks.c
	@echo 'Building autogen/sli_cli_hooks.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ autogen/sli_cli_hooks.c
CDEPS += $(OUTPUT_DIR)/project/autogen/sli_cli_hooks.d
OBJS += $(OUTPUT_DIR)/project/autogen/sli_cli_hooks.o

$(OUTPUT_DIR)/project/autogen/zap-cli.o: autogen/zap-cli.c
	@echo 'Building autogen/zap-cli.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ autogen/zap-cli.c
CDEPS += $(OUTPUT_DIR)/project/autogen/zap-cli.d
OBJS += $(OUTPUT_DIR)/project/autogen/zap-cli.o

$(OUTPUT_DIR)/project/autogen/zap-command-callbacks.o: autogen/zap-command-callbacks.c
	@echo 'Building autogen/zap-command-callbacks.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ autogen/zap-command-callbacks.c
CDEPS += $(OUTPUT_DIR)/project/autogen/zap-command-callbacks.d
OBJS += $(OUTPUT_DIR)/project/autogen/zap-command-callbacks.o

$(OUTPUT_DIR)/project/autogen/zap-command-parser.o: autogen/zap-command-parser.c
	@echo 'Building autogen/zap-command-parser.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ autogen/zap-command-parser.c
CDEPS += $(OUTPUT_DIR)/project/autogen/zap-command-parser.d
OBJS += $(OUTPUT_DIR)/project/autogen/zap-command-parser.o

$(OUTPUT_DIR)/project/autogen/zap-event.o: autogen/zap-event.c
	@echo 'Building autogen/zap-event.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ autogen/zap-event.c
CDEPS += $(OUTPUT_DIR)/project/autogen/zap-event.d
OBJS += $(OUTPUT_DIR)/project/autogen/zap-event.o

$(OUTPUT_DIR)/project/autogen/zigbee_common_callback_dispatcher.o: autogen/zigbee_common_callback_dispatcher.c
	@echo 'Building autogen/zigbee_common_callback_dispatcher.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ autogen/zigbee_common_callback_dispatcher.c
CDEPS += $(OUTPUT_DIR)/project/autogen/zigbee_common_callback_dispatcher.d
OBJS += $(OUTPUT_DIR)/project/autogen/zigbee_common_callback_dispatcher.o

$(OUTPUT_DIR)/project/autogen/zigbee_stack_callback_dispatcher.o: autogen/zigbee_stack_callback_dispatcher.c
	@echo 'Building autogen/zigbee_stack_callback_dispatcher.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ autogen/zigbee_stack_callback_dispatcher.c
CDEPS += $(OUTPUT_DIR)/project/autogen/zigbee_stack_callback_dispatcher.d
OBJS += $(OUTPUT_DIR)/project/autogen/zigbee_stack_callback_dispatcher.o

$(OUTPUT_DIR)/project/autogen/zigbee_zcl_callback_dispatcher.o: autogen/zigbee_zcl_callback_dispatcher.c
	@echo 'Building autogen/zigbee_zcl_callback_dispatcher.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ autogen/zigbee_zcl_callback_dispatcher.c
CDEPS += $(OUTPUT_DIR)/project/autogen/zigbee_zcl_callback_dispatcher.d
OBJS += $(OUTPUT_DIR)/project/autogen/zigbee_zcl_callback_dispatcher.o

$(OUTPUT_DIR)/project/main.o: main.c
	@echo 'Building main.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ main.c
CDEPS += $(OUTPUT_DIR)/project/main.d
OBJS += $(OUTPUT_DIR)/project/main.o

$(OUTPUT_DIR)/project/ZigbeeMinimal_callbacks.o: ZigbeeMinimal_callbacks.c
	@echo 'Building ZigbeeMinimal_callbacks.c'
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ ZigbeeMinimal_callbacks.c
CDEPS += $(OUTPUT_DIR)/project/ZigbeeMinimal_callbacks.d
OBJS += $(OUTPUT_DIR)/project/ZigbeeMinimal_callbacks.o

# Automatically-generated Simplicity Studio Metadata
# Please do not edit or delete these lines!
# SIMPLICITY_STUDIO_METADATA=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END_SIMPLICITY_STUDIO_METADATA
# END OF METADATA