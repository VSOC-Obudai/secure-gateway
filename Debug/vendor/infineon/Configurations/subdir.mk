################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/infineon/Configurations/Ifx_Cfg_Ssw.c \
../vendor/infineon/Configurations/Ifx_Cfg_SswBmhd.c 

COMPILED_SRCS += \
./vendor/infineon/Configurations/Ifx_Cfg_Ssw.src \
./vendor/infineon/Configurations/Ifx_Cfg_SswBmhd.src 

C_DEPS += \
./vendor/infineon/Configurations/Ifx_Cfg_Ssw.d \
./vendor/infineon/Configurations/Ifx_Cfg_SswBmhd.d 

OBJS += \
./vendor/infineon/Configurations/Ifx_Cfg_Ssw.o \
./vendor/infineon/Configurations/Ifx_Cfg_SswBmhd.o 


# Each subdirectory must supply rules for building sources it contributes
vendor/infineon/Configurations/Ifx_Cfg_Ssw.src: ../vendor/infineon/Configurations/Ifx_Cfg_Ssw.c vendor/infineon/Configurations/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/infineon/Configurations/%.o: ./vendor/infineon/Configurations/%.src vendor/infineon/Configurations/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/infineon/Configurations/Ifx_Cfg_SswBmhd.src: ../vendor/infineon/Configurations/Ifx_Cfg_SswBmhd.c vendor/infineon/Configurations/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-vendor-2f-infineon-2f-Configurations

clean-vendor-2f-infineon-2f-Configurations:
	-$(RM) ./vendor/infineon/Configurations/Ifx_Cfg_Ssw.d ./vendor/infineon/Configurations/Ifx_Cfg_Ssw.o ./vendor/infineon/Configurations/Ifx_Cfg_Ssw.src ./vendor/infineon/Configurations/Ifx_Cfg_SswBmhd.d ./vendor/infineon/Configurations/Ifx_Cfg_SswBmhd.o ./vendor/infineon/Configurations/Ifx_Cfg_SswBmhd.src

.PHONY: clean-vendor-2f-infineon-2f-Configurations

