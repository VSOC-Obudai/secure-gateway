################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/infineon/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_DPipe.c \
../vendor/infineon/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Pos.c \
../vendor/infineon/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_PwmHl.c \
../vendor/infineon/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Timer.c 

COMPILED_SRCS += \
./vendor/infineon/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_DPipe.src \
./vendor/infineon/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Pos.src \
./vendor/infineon/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_PwmHl.src \
./vendor/infineon/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Timer.src 

C_DEPS += \
./vendor/infineon/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_DPipe.d \
./vendor/infineon/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Pos.d \
./vendor/infineon/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_PwmHl.d \
./vendor/infineon/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Timer.d 

OBJS += \
./vendor/infineon/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_DPipe.o \
./vendor/infineon/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Pos.o \
./vendor/infineon/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_PwmHl.o \
./vendor/infineon/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Timer.o 


# Each subdirectory must supply rules for building sources it contributes
vendor/infineon/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_DPipe.src: ../vendor/infineon/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_DPipe.c vendor/infineon/Libraries/Service/CpuGeneric/StdIf/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/infineon/Libraries/Service/CpuGeneric/StdIf/%.o: ./vendor/infineon/Libraries/Service/CpuGeneric/StdIf/%.src vendor/infineon/Libraries/Service/CpuGeneric/StdIf/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/infineon/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Pos.src: ../vendor/infineon/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Pos.c vendor/infineon/Libraries/Service/CpuGeneric/StdIf/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/infineon/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_PwmHl.src: ../vendor/infineon/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_PwmHl.c vendor/infineon/Libraries/Service/CpuGeneric/StdIf/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/infineon/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Timer.src: ../vendor/infineon/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Timer.c vendor/infineon/Libraries/Service/CpuGeneric/StdIf/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-vendor-2f-infineon-2f-Libraries-2f-Service-2f-CpuGeneric-2f-StdIf

clean-vendor-2f-infineon-2f-Libraries-2f-Service-2f-CpuGeneric-2f-StdIf:
	-$(RM) ./vendor/infineon/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_DPipe.d ./vendor/infineon/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_DPipe.o ./vendor/infineon/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_DPipe.src ./vendor/infineon/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Pos.d ./vendor/infineon/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Pos.o ./vendor/infineon/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Pos.src ./vendor/infineon/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_PwmHl.d ./vendor/infineon/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_PwmHl.o ./vendor/infineon/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_PwmHl.src ./vendor/infineon/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Timer.d ./vendor/infineon/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Timer.o ./vendor/infineon/Libraries/Service/CpuGeneric/StdIf/IfxStdIf_Timer.src

.PHONY: clean-vendor-2f-infineon-2f-Libraries-2f-Service-2f-CpuGeneric-2f-StdIf

