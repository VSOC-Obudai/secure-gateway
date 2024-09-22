################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/infineon/Configurations/Debug/sync_on_halt.c 

COMPILED_SRCS += \
./vendor/infineon/Configurations/Debug/sync_on_halt.src 

C_DEPS += \
./vendor/infineon/Configurations/Debug/sync_on_halt.d 

OBJS += \
./vendor/infineon/Configurations/Debug/sync_on_halt.o 


# Each subdirectory must supply rules for building sources it contributes
vendor/infineon/Configurations/Debug/sync_on_halt.src: ../vendor/infineon/Configurations/Debug/sync_on_halt.c vendor/infineon/Configurations/Debug/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/infineon/Configurations/Debug/%.o: ./vendor/infineon/Configurations/Debug/%.src vendor/infineon/Configurations/Debug/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-vendor-2f-infineon-2f-Configurations-2f-Debug

clean-vendor-2f-infineon-2f-Configurations-2f-Debug:
	-$(RM) ./vendor/infineon/Configurations/Debug/sync_on_halt.d ./vendor/infineon/Configurations/Debug/sync_on_halt.o ./vendor/infineon/Configurations/Debug/sync_on_halt.src

.PHONY: clean-vendor-2f-infineon-2f-Configurations-2f-Debug

