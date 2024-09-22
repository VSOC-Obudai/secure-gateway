################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/lwip/port/netif/ethernetif.c 

COMPILED_SRCS += \
./vendor/lwip/port/netif/ethernetif.src 

C_DEPS += \
./vendor/lwip/port/netif/ethernetif.d 

OBJS += \
./vendor/lwip/port/netif/ethernetif.o 


# Each subdirectory must supply rules for building sources it contributes
vendor/lwip/port/netif/ethernetif.src: ../vendor/lwip/port/netif/ethernetif.c vendor/lwip/port/netif/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/port/netif/%.o: ./vendor/lwip/port/netif/%.src vendor/lwip/port/netif/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-vendor-2f-lwip-2f-port-2f-netif

clean-vendor-2f-lwip-2f-port-2f-netif:
	-$(RM) ./vendor/lwip/port/netif/ethernetif.d ./vendor/lwip/port/netif/ethernetif.o ./vendor/lwip/port/netif/ethernetif.src

.PHONY: clean-vendor-2f-lwip-2f-port-2f-netif

