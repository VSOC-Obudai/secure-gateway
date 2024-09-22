################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/lwip/src/core/altcp.c \
../vendor/lwip/src/core/altcp_alloc.c \
../vendor/lwip/src/core/altcp_tcp.c \
../vendor/lwip/src/core/def.c \
../vendor/lwip/src/core/dns.c \
../vendor/lwip/src/core/inet_chksum.c \
../vendor/lwip/src/core/init.c \
../vendor/lwip/src/core/ip.c \
../vendor/lwip/src/core/mem.c \
../vendor/lwip/src/core/memp.c \
../vendor/lwip/src/core/netif.c \
../vendor/lwip/src/core/pbuf.c \
../vendor/lwip/src/core/raw.c \
../vendor/lwip/src/core/stats.c \
../vendor/lwip/src/core/sys.c \
../vendor/lwip/src/core/tcp.c \
../vendor/lwip/src/core/tcp_in.c \
../vendor/lwip/src/core/tcp_out.c \
../vendor/lwip/src/core/timeouts.c \
../vendor/lwip/src/core/udp.c 

COMPILED_SRCS += \
./vendor/lwip/src/core/altcp.src \
./vendor/lwip/src/core/altcp_alloc.src \
./vendor/lwip/src/core/altcp_tcp.src \
./vendor/lwip/src/core/def.src \
./vendor/lwip/src/core/dns.src \
./vendor/lwip/src/core/inet_chksum.src \
./vendor/lwip/src/core/init.src \
./vendor/lwip/src/core/ip.src \
./vendor/lwip/src/core/mem.src \
./vendor/lwip/src/core/memp.src \
./vendor/lwip/src/core/netif.src \
./vendor/lwip/src/core/pbuf.src \
./vendor/lwip/src/core/raw.src \
./vendor/lwip/src/core/stats.src \
./vendor/lwip/src/core/sys.src \
./vendor/lwip/src/core/tcp.src \
./vendor/lwip/src/core/tcp_in.src \
./vendor/lwip/src/core/tcp_out.src \
./vendor/lwip/src/core/timeouts.src \
./vendor/lwip/src/core/udp.src 

C_DEPS += \
./vendor/lwip/src/core/altcp.d \
./vendor/lwip/src/core/altcp_alloc.d \
./vendor/lwip/src/core/altcp_tcp.d \
./vendor/lwip/src/core/def.d \
./vendor/lwip/src/core/dns.d \
./vendor/lwip/src/core/inet_chksum.d \
./vendor/lwip/src/core/init.d \
./vendor/lwip/src/core/ip.d \
./vendor/lwip/src/core/mem.d \
./vendor/lwip/src/core/memp.d \
./vendor/lwip/src/core/netif.d \
./vendor/lwip/src/core/pbuf.d \
./vendor/lwip/src/core/raw.d \
./vendor/lwip/src/core/stats.d \
./vendor/lwip/src/core/sys.d \
./vendor/lwip/src/core/tcp.d \
./vendor/lwip/src/core/tcp_in.d \
./vendor/lwip/src/core/tcp_out.d \
./vendor/lwip/src/core/timeouts.d \
./vendor/lwip/src/core/udp.d 

OBJS += \
./vendor/lwip/src/core/altcp.o \
./vendor/lwip/src/core/altcp_alloc.o \
./vendor/lwip/src/core/altcp_tcp.o \
./vendor/lwip/src/core/def.o \
./vendor/lwip/src/core/dns.o \
./vendor/lwip/src/core/inet_chksum.o \
./vendor/lwip/src/core/init.o \
./vendor/lwip/src/core/ip.o \
./vendor/lwip/src/core/mem.o \
./vendor/lwip/src/core/memp.o \
./vendor/lwip/src/core/netif.o \
./vendor/lwip/src/core/pbuf.o \
./vendor/lwip/src/core/raw.o \
./vendor/lwip/src/core/stats.o \
./vendor/lwip/src/core/sys.o \
./vendor/lwip/src/core/tcp.o \
./vendor/lwip/src/core/tcp_in.o \
./vendor/lwip/src/core/tcp_out.o \
./vendor/lwip/src/core/timeouts.o \
./vendor/lwip/src/core/udp.o 


# Each subdirectory must supply rules for building sources it contributes
vendor/lwip/src/core/altcp.src: ../vendor/lwip/src/core/altcp.c vendor/lwip/src/core/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/core/%.o: ./vendor/lwip/src/core/%.src vendor/lwip/src/core/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/core/altcp_alloc.src: ../vendor/lwip/src/core/altcp_alloc.c vendor/lwip/src/core/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/core/altcp_tcp.src: ../vendor/lwip/src/core/altcp_tcp.c vendor/lwip/src/core/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/core/def.src: ../vendor/lwip/src/core/def.c vendor/lwip/src/core/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/core/dns.src: ../vendor/lwip/src/core/dns.c vendor/lwip/src/core/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/core/inet_chksum.src: ../vendor/lwip/src/core/inet_chksum.c vendor/lwip/src/core/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/core/init.src: ../vendor/lwip/src/core/init.c vendor/lwip/src/core/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/core/ip.src: ../vendor/lwip/src/core/ip.c vendor/lwip/src/core/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/core/mem.src: ../vendor/lwip/src/core/mem.c vendor/lwip/src/core/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/core/memp.src: ../vendor/lwip/src/core/memp.c vendor/lwip/src/core/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/core/netif.src: ../vendor/lwip/src/core/netif.c vendor/lwip/src/core/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/core/pbuf.src: ../vendor/lwip/src/core/pbuf.c vendor/lwip/src/core/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/core/raw.src: ../vendor/lwip/src/core/raw.c vendor/lwip/src/core/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/core/stats.src: ../vendor/lwip/src/core/stats.c vendor/lwip/src/core/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/core/sys.src: ../vendor/lwip/src/core/sys.c vendor/lwip/src/core/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/core/tcp.src: ../vendor/lwip/src/core/tcp.c vendor/lwip/src/core/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/core/tcp_in.src: ../vendor/lwip/src/core/tcp_in.c vendor/lwip/src/core/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/core/tcp_out.src: ../vendor/lwip/src/core/tcp_out.c vendor/lwip/src/core/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/core/timeouts.src: ../vendor/lwip/src/core/timeouts.c vendor/lwip/src/core/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/core/udp.src: ../vendor/lwip/src/core/udp.c vendor/lwip/src/core/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-vendor-2f-lwip-2f-src-2f-core

clean-vendor-2f-lwip-2f-src-2f-core:
	-$(RM) ./vendor/lwip/src/core/altcp.d ./vendor/lwip/src/core/altcp.o ./vendor/lwip/src/core/altcp.src ./vendor/lwip/src/core/altcp_alloc.d ./vendor/lwip/src/core/altcp_alloc.o ./vendor/lwip/src/core/altcp_alloc.src ./vendor/lwip/src/core/altcp_tcp.d ./vendor/lwip/src/core/altcp_tcp.o ./vendor/lwip/src/core/altcp_tcp.src ./vendor/lwip/src/core/def.d ./vendor/lwip/src/core/def.o ./vendor/lwip/src/core/def.src ./vendor/lwip/src/core/dns.d ./vendor/lwip/src/core/dns.o ./vendor/lwip/src/core/dns.src ./vendor/lwip/src/core/inet_chksum.d ./vendor/lwip/src/core/inet_chksum.o ./vendor/lwip/src/core/inet_chksum.src ./vendor/lwip/src/core/init.d ./vendor/lwip/src/core/init.o ./vendor/lwip/src/core/init.src ./vendor/lwip/src/core/ip.d ./vendor/lwip/src/core/ip.o ./vendor/lwip/src/core/ip.src ./vendor/lwip/src/core/mem.d ./vendor/lwip/src/core/mem.o ./vendor/lwip/src/core/mem.src ./vendor/lwip/src/core/memp.d ./vendor/lwip/src/core/memp.o ./vendor/lwip/src/core/memp.src ./vendor/lwip/src/core/netif.d ./vendor/lwip/src/core/netif.o ./vendor/lwip/src/core/netif.src ./vendor/lwip/src/core/pbuf.d ./vendor/lwip/src/core/pbuf.o ./vendor/lwip/src/core/pbuf.src ./vendor/lwip/src/core/raw.d ./vendor/lwip/src/core/raw.o ./vendor/lwip/src/core/raw.src ./vendor/lwip/src/core/stats.d ./vendor/lwip/src/core/stats.o ./vendor/lwip/src/core/stats.src ./vendor/lwip/src/core/sys.d ./vendor/lwip/src/core/sys.o ./vendor/lwip/src/core/sys.src ./vendor/lwip/src/core/tcp.d ./vendor/lwip/src/core/tcp.o ./vendor/lwip/src/core/tcp.src ./vendor/lwip/src/core/tcp_in.d ./vendor/lwip/src/core/tcp_in.o ./vendor/lwip/src/core/tcp_in.src ./vendor/lwip/src/core/tcp_out.d ./vendor/lwip/src/core/tcp_out.o ./vendor/lwip/src/core/tcp_out.src ./vendor/lwip/src/core/timeouts.d ./vendor/lwip/src/core/timeouts.o ./vendor/lwip/src/core/timeouts.src ./vendor/lwip/src/core/udp.d ./vendor/lwip/src/core/udp.o ./vendor/lwip/src/core/udp.src

.PHONY: clean-vendor-2f-lwip-2f-src-2f-core

