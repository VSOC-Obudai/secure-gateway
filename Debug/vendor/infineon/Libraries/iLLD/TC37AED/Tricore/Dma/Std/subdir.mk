################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Dma/Std/IfxDma.c 

COMPILED_SRCS += \
./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Dma/Std/IfxDma.src 

C_DEPS += \
./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Dma/Std/IfxDma.d 

OBJS += \
./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Dma/Std/IfxDma.o 


# Each subdirectory must supply rules for building sources it contributes
vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Dma/Std/IfxDma.src: ../vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Dma/Std/IfxDma.c vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Dma/Std/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Dma/Std/%.o: ./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Dma/Std/%.src vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Dma/Std/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-vendor-2f-infineon-2f-Libraries-2f-iLLD-2f-TC37AED-2f-Tricore-2f-Dma-2f-Std

clean-vendor-2f-infineon-2f-Libraries-2f-iLLD-2f-TC37AED-2f-Tricore-2f-Dma-2f-Std:
	-$(RM) ./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Dma/Std/IfxDma.d ./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Dma/Std/IfxDma.o ./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Dma/Std/IfxDma.src

.PHONY: clean-vendor-2f-infineon-2f-Libraries-2f-iLLD-2f-TC37AED-2f-Tricore-2f-Dma-2f-Std

