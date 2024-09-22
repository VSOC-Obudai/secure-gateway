################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/lwip/src/netif/ppp/polarssl/arc4.c \
../vendor/lwip/src/netif/ppp/polarssl/des.c \
../vendor/lwip/src/netif/ppp/polarssl/md4.c \
../vendor/lwip/src/netif/ppp/polarssl/md5.c \
../vendor/lwip/src/netif/ppp/polarssl/sha1.c 

COMPILED_SRCS += \
./vendor/lwip/src/netif/ppp/polarssl/arc4.src \
./vendor/lwip/src/netif/ppp/polarssl/des.src \
./vendor/lwip/src/netif/ppp/polarssl/md4.src \
./vendor/lwip/src/netif/ppp/polarssl/md5.src \
./vendor/lwip/src/netif/ppp/polarssl/sha1.src 

C_DEPS += \
./vendor/lwip/src/netif/ppp/polarssl/arc4.d \
./vendor/lwip/src/netif/ppp/polarssl/des.d \
./vendor/lwip/src/netif/ppp/polarssl/md4.d \
./vendor/lwip/src/netif/ppp/polarssl/md5.d \
./vendor/lwip/src/netif/ppp/polarssl/sha1.d 

OBJS += \
./vendor/lwip/src/netif/ppp/polarssl/arc4.o \
./vendor/lwip/src/netif/ppp/polarssl/des.o \
./vendor/lwip/src/netif/ppp/polarssl/md4.o \
./vendor/lwip/src/netif/ppp/polarssl/md5.o \
./vendor/lwip/src/netif/ppp/polarssl/sha1.o 


# Each subdirectory must supply rules for building sources it contributes
vendor/lwip/src/netif/ppp/polarssl/arc4.src: ../vendor/lwip/src/netif/ppp/polarssl/arc4.c vendor/lwip/src/netif/ppp/polarssl/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/netif/ppp/polarssl/%.o: ./vendor/lwip/src/netif/ppp/polarssl/%.src vendor/lwip/src/netif/ppp/polarssl/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/netif/ppp/polarssl/des.src: ../vendor/lwip/src/netif/ppp/polarssl/des.c vendor/lwip/src/netif/ppp/polarssl/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/netif/ppp/polarssl/md4.src: ../vendor/lwip/src/netif/ppp/polarssl/md4.c vendor/lwip/src/netif/ppp/polarssl/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/netif/ppp/polarssl/md5.src: ../vendor/lwip/src/netif/ppp/polarssl/md5.c vendor/lwip/src/netif/ppp/polarssl/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/netif/ppp/polarssl/sha1.src: ../vendor/lwip/src/netif/ppp/polarssl/sha1.c vendor/lwip/src/netif/ppp/polarssl/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-vendor-2f-lwip-2f-src-2f-netif-2f-ppp-2f-polarssl

clean-vendor-2f-lwip-2f-src-2f-netif-2f-ppp-2f-polarssl:
	-$(RM) ./vendor/lwip/src/netif/ppp/polarssl/arc4.d ./vendor/lwip/src/netif/ppp/polarssl/arc4.o ./vendor/lwip/src/netif/ppp/polarssl/arc4.src ./vendor/lwip/src/netif/ppp/polarssl/des.d ./vendor/lwip/src/netif/ppp/polarssl/des.o ./vendor/lwip/src/netif/ppp/polarssl/des.src ./vendor/lwip/src/netif/ppp/polarssl/md4.d ./vendor/lwip/src/netif/ppp/polarssl/md4.o ./vendor/lwip/src/netif/ppp/polarssl/md4.src ./vendor/lwip/src/netif/ppp/polarssl/md5.d ./vendor/lwip/src/netif/ppp/polarssl/md5.o ./vendor/lwip/src/netif/ppp/polarssl/md5.src ./vendor/lwip/src/netif/ppp/polarssl/sha1.d ./vendor/lwip/src/netif/ppp/polarssl/sha1.o ./vendor/lwip/src/netif/ppp/polarssl/sha1.src

.PHONY: clean-vendor-2f-lwip-2f-src-2f-netif-2f-ppp-2f-polarssl

