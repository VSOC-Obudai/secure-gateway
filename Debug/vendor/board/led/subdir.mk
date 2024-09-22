################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/board/led/led.c 

COMPILED_SRCS += \
./vendor/board/led/led.src 

C_DEPS += \
./vendor/board/led/led.d 

OBJS += \
./vendor/board/led/led.o 


# Each subdirectory must supply rules for building sources it contributes
vendor/board/led/led.src: ../vendor/board/led/led.c vendor/board/led/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/board/led/%.o: ./vendor/board/led/%.src vendor/board/led/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-vendor-2f-board-2f-led

clean-vendor-2f-board-2f-led:
	-$(RM) ./vendor/board/led/led.d ./vendor/board/led/led.o ./vendor/board/led/led.src

.PHONY: clean-vendor-2f-board-2f-led

