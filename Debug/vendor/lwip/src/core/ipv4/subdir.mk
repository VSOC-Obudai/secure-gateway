################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/lwip/src/core/ipv4/acd.c \
../vendor/lwip/src/core/ipv4/autoip.c \
../vendor/lwip/src/core/ipv4/dhcp.c \
../vendor/lwip/src/core/ipv4/etharp.c \
../vendor/lwip/src/core/ipv4/icmp.c \
../vendor/lwip/src/core/ipv4/igmp.c \
../vendor/lwip/src/core/ipv4/ip4.c \
../vendor/lwip/src/core/ipv4/ip4_addr.c \
../vendor/lwip/src/core/ipv4/ip4_frag.c 

COMPILED_SRCS += \
./vendor/lwip/src/core/ipv4/acd.src \
./vendor/lwip/src/core/ipv4/autoip.src \
./vendor/lwip/src/core/ipv4/dhcp.src \
./vendor/lwip/src/core/ipv4/etharp.src \
./vendor/lwip/src/core/ipv4/icmp.src \
./vendor/lwip/src/core/ipv4/igmp.src \
./vendor/lwip/src/core/ipv4/ip4.src \
./vendor/lwip/src/core/ipv4/ip4_addr.src \
./vendor/lwip/src/core/ipv4/ip4_frag.src 

C_DEPS += \
./vendor/lwip/src/core/ipv4/acd.d \
./vendor/lwip/src/core/ipv4/autoip.d \
./vendor/lwip/src/core/ipv4/dhcp.d \
./vendor/lwip/src/core/ipv4/etharp.d \
./vendor/lwip/src/core/ipv4/icmp.d \
./vendor/lwip/src/core/ipv4/igmp.d \
./vendor/lwip/src/core/ipv4/ip4.d \
./vendor/lwip/src/core/ipv4/ip4_addr.d \
./vendor/lwip/src/core/ipv4/ip4_frag.d 

OBJS += \
./vendor/lwip/src/core/ipv4/acd.o \
./vendor/lwip/src/core/ipv4/autoip.o \
./vendor/lwip/src/core/ipv4/dhcp.o \
./vendor/lwip/src/core/ipv4/etharp.o \
./vendor/lwip/src/core/ipv4/icmp.o \
./vendor/lwip/src/core/ipv4/igmp.o \
./vendor/lwip/src/core/ipv4/ip4.o \
./vendor/lwip/src/core/ipv4/ip4_addr.o \
./vendor/lwip/src/core/ipv4/ip4_frag.o 


# Each subdirectory must supply rules for building sources it contributes
vendor/lwip/src/core/ipv4/acd.src: ../vendor/lwip/src/core/ipv4/acd.c vendor/lwip/src/core/ipv4/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/core/ipv4/%.o: ./vendor/lwip/src/core/ipv4/%.src vendor/lwip/src/core/ipv4/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/core/ipv4/autoip.src: ../vendor/lwip/src/core/ipv4/autoip.c vendor/lwip/src/core/ipv4/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/core/ipv4/dhcp.src: ../vendor/lwip/src/core/ipv4/dhcp.c vendor/lwip/src/core/ipv4/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/core/ipv4/etharp.src: ../vendor/lwip/src/core/ipv4/etharp.c vendor/lwip/src/core/ipv4/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/core/ipv4/icmp.src: ../vendor/lwip/src/core/ipv4/icmp.c vendor/lwip/src/core/ipv4/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/core/ipv4/igmp.src: ../vendor/lwip/src/core/ipv4/igmp.c vendor/lwip/src/core/ipv4/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/core/ipv4/ip4.src: ../vendor/lwip/src/core/ipv4/ip4.c vendor/lwip/src/core/ipv4/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/core/ipv4/ip4_addr.src: ../vendor/lwip/src/core/ipv4/ip4_addr.c vendor/lwip/src/core/ipv4/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/core/ipv4/ip4_frag.src: ../vendor/lwip/src/core/ipv4/ip4_frag.c vendor/lwip/src/core/ipv4/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-vendor-2f-lwip-2f-src-2f-core-2f-ipv4

clean-vendor-2f-lwip-2f-src-2f-core-2f-ipv4:
	-$(RM) ./vendor/lwip/src/core/ipv4/acd.d ./vendor/lwip/src/core/ipv4/acd.o ./vendor/lwip/src/core/ipv4/acd.src ./vendor/lwip/src/core/ipv4/autoip.d ./vendor/lwip/src/core/ipv4/autoip.o ./vendor/lwip/src/core/ipv4/autoip.src ./vendor/lwip/src/core/ipv4/dhcp.d ./vendor/lwip/src/core/ipv4/dhcp.o ./vendor/lwip/src/core/ipv4/dhcp.src ./vendor/lwip/src/core/ipv4/etharp.d ./vendor/lwip/src/core/ipv4/etharp.o ./vendor/lwip/src/core/ipv4/etharp.src ./vendor/lwip/src/core/ipv4/icmp.d ./vendor/lwip/src/core/ipv4/icmp.o ./vendor/lwip/src/core/ipv4/icmp.src ./vendor/lwip/src/core/ipv4/igmp.d ./vendor/lwip/src/core/ipv4/igmp.o ./vendor/lwip/src/core/ipv4/igmp.src ./vendor/lwip/src/core/ipv4/ip4.d ./vendor/lwip/src/core/ipv4/ip4.o ./vendor/lwip/src/core/ipv4/ip4.src ./vendor/lwip/src/core/ipv4/ip4_addr.d ./vendor/lwip/src/core/ipv4/ip4_addr.o ./vendor/lwip/src/core/ipv4/ip4_addr.src ./vendor/lwip/src/core/ipv4/ip4_frag.d ./vendor/lwip/src/core/ipv4/ip4_frag.o ./vendor/lwip/src/core/ipv4/ip4_frag.src

.PHONY: clean-vendor-2f-lwip-2f-src-2f-core-2f-ipv4

