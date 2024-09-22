################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/board/serialio/serialio.c 

COMPILED_SRCS += \
./vendor/board/serialio/serialio.src 

C_DEPS += \
./vendor/board/serialio/serialio.d 

OBJS += \
./vendor/board/serialio/serialio.o 


# Each subdirectory must supply rules for building sources it contributes
vendor/board/serialio/serialio.src: ../vendor/board/serialio/serialio.c vendor/board/serialio/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/board/serialio/%.o: ./vendor/board/serialio/%.src vendor/board/serialio/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-vendor-2f-board-2f-serialio

clean-vendor-2f-board-2f-serialio:
	-$(RM) ./vendor/board/serialio/serialio.d ./vendor/board/serialio/serialio.o ./vendor/board/serialio/serialio.src

.PHONY: clean-vendor-2f-board-2f-serialio

