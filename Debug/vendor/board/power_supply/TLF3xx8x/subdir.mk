################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/board/power_supply/TLF3xx8x/TLF3xx8x.c 

COMPILED_SRCS += \
./vendor/board/power_supply/TLF3xx8x/TLF3xx8x.src 

C_DEPS += \
./vendor/board/power_supply/TLF3xx8x/TLF3xx8x.d 

OBJS += \
./vendor/board/power_supply/TLF3xx8x/TLF3xx8x.o 


# Each subdirectory must supply rules for building sources it contributes
vendor/board/power_supply/TLF3xx8x/TLF3xx8x.src: ../vendor/board/power_supply/TLF3xx8x/TLF3xx8x.c vendor/board/power_supply/TLF3xx8x/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/board/power_supply/TLF3xx8x/%.o: ./vendor/board/power_supply/TLF3xx8x/%.src vendor/board/power_supply/TLF3xx8x/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-vendor-2f-board-2f-power_supply-2f-TLF3xx8x

clean-vendor-2f-board-2f-power_supply-2f-TLF3xx8x:
	-$(RM) ./vendor/board/power_supply/TLF3xx8x/TLF3xx8x.d ./vendor/board/power_supply/TLF3xx8x/TLF3xx8x.o ./vendor/board/power_supply/TLF3xx8x/TLF3xx8x.src

.PHONY: clean-vendor-2f-board-2f-power_supply-2f-TLF3xx8x

