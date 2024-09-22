################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include vendor/lwip/src/netif/ppp/polarssl/subdir.mk
-include vendor/lwip/src/netif/ppp/subdir.mk
-include vendor/lwip/src/netif/subdir.mk
-include vendor/lwip/src/core/ipv6/subdir.mk
-include vendor/lwip/src/core/ipv4/subdir.mk
-include vendor/lwip/src/core/subdir.mk
-include vendor/lwip/src/apps/http/subdir.mk
-include vendor/lwip/src/api/subdir.mk
-include vendor/lwip/port/sys/subdir.mk
-include vendor/lwip/port/netif/subdir.mk
-include vendor/infineon/Libraries/iLLD/TC37AED/Tricore/_PinMap/subdir.mk
-include vendor/infineon/Libraries/iLLD/TC37AED/Tricore/_Impl/subdir.mk
-include vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Stm/Timer/subdir.mk
-include vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Stm/Std/subdir.mk
-include vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Src/Std/subdir.mk
-include vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Scu/Std/subdir.mk
-include vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Qspi/Std/subdir.mk
-include vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Qspi/SpiMaster/subdir.mk
-include vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Port/Std/subdir.mk
-include vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Pms/Std/subdir.mk
-include vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Mtu/Std/subdir.mk
-include vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/subdir.mk
-include vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Geth/Std/subdir.mk
-include vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Geth/Eth/subdir.mk
-include vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Evadc/Std/subdir.mk
-include vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Evadc/Adc/subdir.mk
-include vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Dts/Std/subdir.mk
-include vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Dts/Dts/subdir.mk
-include vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Dma/Std/subdir.mk
-include vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Dma/Dma/subdir.mk
-include vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Cpu/Trap/subdir.mk
-include vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Cpu/Std/subdir.mk
-include vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Cpu/Irq/subdir.mk
-include vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Can/Std/subdir.mk
-include vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Can/Can/subdir.mk
-include vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Asclin/Std/subdir.mk
-include vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Asclin/Lin/subdir.mk
-include vendor/infineon/Libraries/Service/CpuGeneric/StdIf/subdir.mk
-include vendor/infineon/Libraries/Service/CpuGeneric/If/subdir.mk
-include vendor/infineon/Libraries/Infra/Ssw/TC37AED/Tricore/subdir.mk
-include vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/subdir.mk
-include vendor/infineon/Configurations/Debug/subdir.mk
-include vendor/infineon/Configurations/subdir.mk
-include vendor/board/serialio/subdir.mk
-include vendor/board/power_supply/power_good_s/subdir.mk
-include vendor/board/power_supply/analog_measure/subdir.mk
-include vendor/board/power_supply/TLF3xx8x/subdir.mk
-include vendor/board/power_supply/subdir.mk
-include vendor/board/lin/subdir.mk
-include vendor/board/led/subdir.mk
-include vendor/board/eth/phy/subdir.mk
-include vendor/board/eth/mac/subdir.mk
-include vendor/board/can/subdir.mk
-include vendor/board/subdir.mk
-include src/subdir.mk
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := secure-gateway
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_SIZE += \
secure-gateway.siz \


# All Target
all: main-build

# Main-build Target
main-build: secure-gateway.elf secondary-outputs

# Tool invocations
secure-gateway.elf: $(OBJS) makefile $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: TASKING Linker'
	cctc --lsl-file="C:\workspace\secure-gateway\Lcf_Tasking_Tricore_Tc.lsl" -Wl-Oc -Wl-OL -Wl-Ot -Wl-Ox -Wl-Oy -Wl--map-file="secure-gateway.map" -Wl-mc -Wl-mf -Wl-mi -Wl-mk -Wl-ml -Wl-mm -Wl-md -Wl-mr -Wl-mu --no-warnings= -Wl--error-limit=42 --fp-model=3 -lrt --lsl-core=vtc --exceptions --strict --anachronisms --force-c++ -Ctc37x -o"secure-gateway.elf" -Wl-o"secure-gateway.hex:IHEX" $(OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

secure-gateway.siz: secure-gateway.elf makefile $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: Print Size'
	elfsize  "secure-gateway.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) secure-gateway.siz secure-gateway.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_SIZE)

.PHONY: all clean dependents main-build

-include ../makefile.targets
