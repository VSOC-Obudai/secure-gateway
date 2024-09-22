################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/lwip/src/api/api_lib.c \
../vendor/lwip/src/api/api_msg.c \
../vendor/lwip/src/api/err.c \
../vendor/lwip/src/api/if_api.c \
../vendor/lwip/src/api/netbuf.c \
../vendor/lwip/src/api/netdb.c \
../vendor/lwip/src/api/netifapi.c \
../vendor/lwip/src/api/sockets.c \
../vendor/lwip/src/api/tcpip.c 

COMPILED_SRCS += \
./vendor/lwip/src/api/api_lib.src \
./vendor/lwip/src/api/api_msg.src \
./vendor/lwip/src/api/err.src \
./vendor/lwip/src/api/if_api.src \
./vendor/lwip/src/api/netbuf.src \
./vendor/lwip/src/api/netdb.src \
./vendor/lwip/src/api/netifapi.src \
./vendor/lwip/src/api/sockets.src \
./vendor/lwip/src/api/tcpip.src 

C_DEPS += \
./vendor/lwip/src/api/api_lib.d \
./vendor/lwip/src/api/api_msg.d \
./vendor/lwip/src/api/err.d \
./vendor/lwip/src/api/if_api.d \
./vendor/lwip/src/api/netbuf.d \
./vendor/lwip/src/api/netdb.d \
./vendor/lwip/src/api/netifapi.d \
./vendor/lwip/src/api/sockets.d \
./vendor/lwip/src/api/tcpip.d 

OBJS += \
./vendor/lwip/src/api/api_lib.o \
./vendor/lwip/src/api/api_msg.o \
./vendor/lwip/src/api/err.o \
./vendor/lwip/src/api/if_api.o \
./vendor/lwip/src/api/netbuf.o \
./vendor/lwip/src/api/netdb.o \
./vendor/lwip/src/api/netifapi.o \
./vendor/lwip/src/api/sockets.o \
./vendor/lwip/src/api/tcpip.o 


# Each subdirectory must supply rules for building sources it contributes
vendor/lwip/src/api/api_lib.src: ../vendor/lwip/src/api/api_lib.c vendor/lwip/src/api/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/api/%.o: ./vendor/lwip/src/api/%.src vendor/lwip/src/api/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/api/api_msg.src: ../vendor/lwip/src/api/api_msg.c vendor/lwip/src/api/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/api/err.src: ../vendor/lwip/src/api/err.c vendor/lwip/src/api/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/api/if_api.src: ../vendor/lwip/src/api/if_api.c vendor/lwip/src/api/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/api/netbuf.src: ../vendor/lwip/src/api/netbuf.c vendor/lwip/src/api/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/api/netdb.src: ../vendor/lwip/src/api/netdb.c vendor/lwip/src/api/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/api/netifapi.src: ../vendor/lwip/src/api/netifapi.c vendor/lwip/src/api/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/api/sockets.src: ../vendor/lwip/src/api/sockets.c vendor/lwip/src/api/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/api/tcpip.src: ../vendor/lwip/src/api/tcpip.c vendor/lwip/src/api/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-vendor-2f-lwip-2f-src-2f-api

clean-vendor-2f-lwip-2f-src-2f-api:
	-$(RM) ./vendor/lwip/src/api/api_lib.d ./vendor/lwip/src/api/api_lib.o ./vendor/lwip/src/api/api_lib.src ./vendor/lwip/src/api/api_msg.d ./vendor/lwip/src/api/api_msg.o ./vendor/lwip/src/api/api_msg.src ./vendor/lwip/src/api/err.d ./vendor/lwip/src/api/err.o ./vendor/lwip/src/api/err.src ./vendor/lwip/src/api/if_api.d ./vendor/lwip/src/api/if_api.o ./vendor/lwip/src/api/if_api.src ./vendor/lwip/src/api/netbuf.d ./vendor/lwip/src/api/netbuf.o ./vendor/lwip/src/api/netbuf.src ./vendor/lwip/src/api/netdb.d ./vendor/lwip/src/api/netdb.o ./vendor/lwip/src/api/netdb.src ./vendor/lwip/src/api/netifapi.d ./vendor/lwip/src/api/netifapi.o ./vendor/lwip/src/api/netifapi.src ./vendor/lwip/src/api/sockets.d ./vendor/lwip/src/api/sockets.o ./vendor/lwip/src/api/sockets.src ./vendor/lwip/src/api/tcpip.d ./vendor/lwip/src/api/tcpip.o ./vendor/lwip/src/api/tcpip.src

.PHONY: clean-vendor-2f-lwip-2f-src-2f-api

