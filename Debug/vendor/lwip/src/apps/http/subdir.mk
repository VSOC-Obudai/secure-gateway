################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/lwip/src/apps/http/altcp_proxyconnect.c \
../vendor/lwip/src/apps/http/fs.c \
../vendor/lwip/src/apps/http/http_client.c \
../vendor/lwip/src/apps/http/httpd.c 

COMPILED_SRCS += \
./vendor/lwip/src/apps/http/altcp_proxyconnect.src \
./vendor/lwip/src/apps/http/fs.src \
./vendor/lwip/src/apps/http/http_client.src \
./vendor/lwip/src/apps/http/httpd.src 

C_DEPS += \
./vendor/lwip/src/apps/http/altcp_proxyconnect.d \
./vendor/lwip/src/apps/http/fs.d \
./vendor/lwip/src/apps/http/http_client.d \
./vendor/lwip/src/apps/http/httpd.d 

OBJS += \
./vendor/lwip/src/apps/http/altcp_proxyconnect.o \
./vendor/lwip/src/apps/http/fs.o \
./vendor/lwip/src/apps/http/http_client.o \
./vendor/lwip/src/apps/http/httpd.o 


# Each subdirectory must supply rules for building sources it contributes
vendor/lwip/src/apps/http/altcp_proxyconnect.src: ../vendor/lwip/src/apps/http/altcp_proxyconnect.c vendor/lwip/src/apps/http/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/apps/http/%.o: ./vendor/lwip/src/apps/http/%.src vendor/lwip/src/apps/http/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/apps/http/fs.src: ../vendor/lwip/src/apps/http/fs.c vendor/lwip/src/apps/http/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/apps/http/http_client.src: ../vendor/lwip/src/apps/http/http_client.c vendor/lwip/src/apps/http/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/lwip/src/apps/http/httpd.src: ../vendor/lwip/src/apps/http/httpd.c vendor/lwip/src/apps/http/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-vendor-2f-lwip-2f-src-2f-apps-2f-http

clean-vendor-2f-lwip-2f-src-2f-apps-2f-http:
	-$(RM) ./vendor/lwip/src/apps/http/altcp_proxyconnect.d ./vendor/lwip/src/apps/http/altcp_proxyconnect.o ./vendor/lwip/src/apps/http/altcp_proxyconnect.src ./vendor/lwip/src/apps/http/fs.d ./vendor/lwip/src/apps/http/fs.o ./vendor/lwip/src/apps/http/fs.src ./vendor/lwip/src/apps/http/http_client.d ./vendor/lwip/src/apps/http/http_client.o ./vendor/lwip/src/apps/http/http_client.src ./vendor/lwip/src/apps/http/httpd.d ./vendor/lwip/src/apps/http/httpd.o ./vendor/lwip/src/apps/http/httpd.src

.PHONY: clean-vendor-2f-lwip-2f-src-2f-apps-2f-http

