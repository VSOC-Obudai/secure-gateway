################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/infineon/Libraries/Infra/Ssw/TC37AED/Tricore/Ifx_Ssw_Infra.c \
../vendor/infineon/Libraries/Infra/Ssw/TC37AED/Tricore/Ifx_Ssw_Tc0.c \
../vendor/infineon/Libraries/Infra/Ssw/TC37AED/Tricore/Ifx_Ssw_Tc1.c \
../vendor/infineon/Libraries/Infra/Ssw/TC37AED/Tricore/Ifx_Ssw_Tc2.c 

COMPILED_SRCS += \
./vendor/infineon/Libraries/Infra/Ssw/TC37AED/Tricore/Ifx_Ssw_Infra.src \
./vendor/infineon/Libraries/Infra/Ssw/TC37AED/Tricore/Ifx_Ssw_Tc0.src \
./vendor/infineon/Libraries/Infra/Ssw/TC37AED/Tricore/Ifx_Ssw_Tc1.src \
./vendor/infineon/Libraries/Infra/Ssw/TC37AED/Tricore/Ifx_Ssw_Tc2.src 

C_DEPS += \
./vendor/infineon/Libraries/Infra/Ssw/TC37AED/Tricore/Ifx_Ssw_Infra.d \
./vendor/infineon/Libraries/Infra/Ssw/TC37AED/Tricore/Ifx_Ssw_Tc0.d \
./vendor/infineon/Libraries/Infra/Ssw/TC37AED/Tricore/Ifx_Ssw_Tc1.d \
./vendor/infineon/Libraries/Infra/Ssw/TC37AED/Tricore/Ifx_Ssw_Tc2.d 

OBJS += \
./vendor/infineon/Libraries/Infra/Ssw/TC37AED/Tricore/Ifx_Ssw_Infra.o \
./vendor/infineon/Libraries/Infra/Ssw/TC37AED/Tricore/Ifx_Ssw_Tc0.o \
./vendor/infineon/Libraries/Infra/Ssw/TC37AED/Tricore/Ifx_Ssw_Tc1.o \
./vendor/infineon/Libraries/Infra/Ssw/TC37AED/Tricore/Ifx_Ssw_Tc2.o 


# Each subdirectory must supply rules for building sources it contributes
vendor/infineon/Libraries/Infra/Ssw/TC37AED/Tricore/Ifx_Ssw_Infra.src: ../vendor/infineon/Libraries/Infra/Ssw/TC37AED/Tricore/Ifx_Ssw_Infra.c vendor/infineon/Libraries/Infra/Ssw/TC37AED/Tricore/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/infineon/Libraries/Infra/Ssw/TC37AED/Tricore/%.o: ./vendor/infineon/Libraries/Infra/Ssw/TC37AED/Tricore/%.src vendor/infineon/Libraries/Infra/Ssw/TC37AED/Tricore/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/infineon/Libraries/Infra/Ssw/TC37AED/Tricore/Ifx_Ssw_Tc0.src: ../vendor/infineon/Libraries/Infra/Ssw/TC37AED/Tricore/Ifx_Ssw_Tc0.c vendor/infineon/Libraries/Infra/Ssw/TC37AED/Tricore/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/infineon/Libraries/Infra/Ssw/TC37AED/Tricore/Ifx_Ssw_Tc1.src: ../vendor/infineon/Libraries/Infra/Ssw/TC37AED/Tricore/Ifx_Ssw_Tc1.c vendor/infineon/Libraries/Infra/Ssw/TC37AED/Tricore/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/infineon/Libraries/Infra/Ssw/TC37AED/Tricore/Ifx_Ssw_Tc2.src: ../vendor/infineon/Libraries/Infra/Ssw/TC37AED/Tricore/Ifx_Ssw_Tc2.c vendor/infineon/Libraries/Infra/Ssw/TC37AED/Tricore/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-vendor-2f-infineon-2f-Libraries-2f-Infra-2f-Ssw-2f-TC37AED-2f-Tricore

clean-vendor-2f-infineon-2f-Libraries-2f-Infra-2f-Ssw-2f-TC37AED-2f-Tricore:
	-$(RM) ./vendor/infineon/Libraries/Infra/Ssw/TC37AED/Tricore/Ifx_Ssw_Infra.d ./vendor/infineon/Libraries/Infra/Ssw/TC37AED/Tricore/Ifx_Ssw_Infra.o ./vendor/infineon/Libraries/Infra/Ssw/TC37AED/Tricore/Ifx_Ssw_Infra.src ./vendor/infineon/Libraries/Infra/Ssw/TC37AED/Tricore/Ifx_Ssw_Tc0.d ./vendor/infineon/Libraries/Infra/Ssw/TC37AED/Tricore/Ifx_Ssw_Tc0.o ./vendor/infineon/Libraries/Infra/Ssw/TC37AED/Tricore/Ifx_Ssw_Tc0.src ./vendor/infineon/Libraries/Infra/Ssw/TC37AED/Tricore/Ifx_Ssw_Tc1.d ./vendor/infineon/Libraries/Infra/Ssw/TC37AED/Tricore/Ifx_Ssw_Tc1.o ./vendor/infineon/Libraries/Infra/Ssw/TC37AED/Tricore/Ifx_Ssw_Tc1.src ./vendor/infineon/Libraries/Infra/Ssw/TC37AED/Tricore/Ifx_Ssw_Tc2.d ./vendor/infineon/Libraries/Infra/Ssw/TC37AED/Tricore/Ifx_Ssw_Tc2.o ./vendor/infineon/Libraries/Infra/Ssw/TC37AED/Tricore/Ifx_Ssw_Tc2.src

.PHONY: clean-vendor-2f-infineon-2f-Libraries-2f-Infra-2f-Ssw-2f-TC37AED-2f-Tricore

