################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/lwip/src/core/ipv6/dhcp6.c \
../vendor/lwip/src/core/ipv6/ethip6.c \
../vendor/lwip/src/core/ipv6/icmp6.c \
../vendor/lwip/src/core/ipv6/inet6.c \
../vendor/lwip/src/core/ipv6/ip6.c \
../vendor/lwip/src/core/ipv6/ip6_addr.c \
../vendor/lwip/src/core/ipv6/ip6_frag.c \
../vendor/lwip/src/core/ipv6/mld6.c \
../vendor/lwip/src/core/ipv6/nd6.c 

COMPILED_SRCS += \
./vendor/lwip/src/core/ipv6/dhcp6.src \
./vendor/lwip/src/core/ipv6/ethip6.src \
./vendor/lwip/src/core/ipv6/icmp6.src \
./vendor/lwip/src/core/ipv6/inet6.src \
./vendor/lwip/src/core/ipv6/ip6.src \
./vendor/lwip/src/core/ipv6/ip6_addr.src \
./vendor/lwip/src/core/ipv6/ip6_frag.src \
./vendor/lwip/src/core/ipv6/mld6.src \
./vendor/lwip/src/core/ipv6/nd6.src 

C_DEPS += \
./vendor/lwip/src/core/ipv6/dhcp6.d \
./vendor/lwip/src/core/ipv6/ethip6.d \
./vendor/lwip/src/core/ipv6/icmp6.d \
./vendor/lwip/src/core/ipv6/inet6.d \
./vendor/lwip/src/core/ipv6/ip6.d \
./vendor/lwip/src/core/ipv6/ip6_addr.d \
./vendor/lwip/src/core/ipv6/ip6_frag.d \
./vendor/lwip/src/core/ipv6/mld6.d \
./vendor/lwip/src/core/ipv6/nd6.d 

OBJS += \
./vendor/lwip/src/core/ipv6/dhcp6.o \
./vendor/lwip/src/core/ipv6/ethip6.o \
./vendor/lwip/src/core/ipv6/icmp6.o \
./vendor/lwip/src/core/ipv6/inet6.o \
./vendor/lwip/src/core/ipv6/ip6.o \
./vendor/lwip/src/core/ipv6/ip6_addr.o \
./vendor/lwip/src/core/ipv6/ip6_frag.o \
./vendor/lwip/src/core/ipv6/mld6.o \
./vendor/lwip/src/core/ipv6/nd6.o 


# Each subdirectory must supply rules for building sources it contributes
vendor/lwip/src/core/ipv6/dhcp6.src: ../vendor/lwip/src/core/ipv6/dhcp6.c vendor/lwip/src/core/ipv6/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/core/ipv6/%.o: ./vendor/lwip/src/core/ipv6/%.src vendor/lwip/src/core/ipv6/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/core/ipv6/ethip6.src: ../vendor/lwip/src/core/ipv6/ethip6.c vendor/lwip/src/core/ipv6/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/core/ipv6/icmp6.src: ../vendor/lwip/src/core/ipv6/icmp6.c vendor/lwip/src/core/ipv6/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/core/ipv6/inet6.src: ../vendor/lwip/src/core/ipv6/inet6.c vendor/lwip/src/core/ipv6/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/core/ipv6/ip6.src: ../vendor/lwip/src/core/ipv6/ip6.c vendor/lwip/src/core/ipv6/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/core/ipv6/ip6_addr.src: ../vendor/lwip/src/core/ipv6/ip6_addr.c vendor/lwip/src/core/ipv6/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/core/ipv6/ip6_frag.src: ../vendor/lwip/src/core/ipv6/ip6_frag.c vendor/lwip/src/core/ipv6/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/core/ipv6/mld6.src: ../vendor/lwip/src/core/ipv6/mld6.c vendor/lwip/src/core/ipv6/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/core/ipv6/nd6.src: ../vendor/lwip/src/core/ipv6/nd6.c vendor/lwip/src/core/ipv6/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-vendor-2f-lwip-2f-src-2f-core-2f-ipv6

clean-vendor-2f-lwip-2f-src-2f-core-2f-ipv6:
	-$(RM) ./vendor/lwip/src/core/ipv6/dhcp6.d ./vendor/lwip/src/core/ipv6/dhcp6.o ./vendor/lwip/src/core/ipv6/dhcp6.src ./vendor/lwip/src/core/ipv6/ethip6.d ./vendor/lwip/src/core/ipv6/ethip6.o ./vendor/lwip/src/core/ipv6/ethip6.src ./vendor/lwip/src/core/ipv6/icmp6.d ./vendor/lwip/src/core/ipv6/icmp6.o ./vendor/lwip/src/core/ipv6/icmp6.src ./vendor/lwip/src/core/ipv6/inet6.d ./vendor/lwip/src/core/ipv6/inet6.o ./vendor/lwip/src/core/ipv6/inet6.src ./vendor/lwip/src/core/ipv6/ip6.d ./vendor/lwip/src/core/ipv6/ip6.o ./vendor/lwip/src/core/ipv6/ip6.src ./vendor/lwip/src/core/ipv6/ip6_addr.d ./vendor/lwip/src/core/ipv6/ip6_addr.o ./vendor/lwip/src/core/ipv6/ip6_addr.src ./vendor/lwip/src/core/ipv6/ip6_frag.d ./vendor/lwip/src/core/ipv6/ip6_frag.o ./vendor/lwip/src/core/ipv6/ip6_frag.src ./vendor/lwip/src/core/ipv6/mld6.d ./vendor/lwip/src/core/ipv6/mld6.o ./vendor/lwip/src/core/ipv6/mld6.src ./vendor/lwip/src/core/ipv6/nd6.d ./vendor/lwip/src/core/ipv6/nd6.o ./vendor/lwip/src/core/ipv6/nd6.src

.PHONY: clean-vendor-2f-lwip-2f-src-2f-core-2f-ipv6

