################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/CompilerDcc.c \
../vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/CompilerGcc.c \
../vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/CompilerGhs.c \
../vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/CompilerGnuc.c \
../vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.c 

COMPILED_SRCS += \
./vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/CompilerDcc.src \
./vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/CompilerGcc.src \
./vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/CompilerGhs.src \
./vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/CompilerGnuc.src \
./vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.src 

C_DEPS += \
./vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/CompilerDcc.d \
./vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/CompilerGcc.d \
./vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/CompilerGhs.d \
./vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/CompilerGnuc.d \
./vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.d 

OBJS += \
./vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/CompilerDcc.o \
./vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/CompilerGcc.o \
./vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/CompilerGhs.o \
./vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/CompilerGnuc.o \
./vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.o 


# Each subdirectory must supply rules for building sources it contributes
vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/CompilerDcc.src: ../vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/CompilerDcc.c vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/%.o: ./vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/%.src vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/CompilerGcc.src: ../vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/CompilerGcc.c vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/CompilerGhs.src: ../vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/CompilerGhs.c vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/CompilerGnuc.src: ../vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/CompilerGnuc.c vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.src: ../vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.c vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-vendor-2f-infineon-2f-Libraries-2f-Infra-2f-Platform-2f-Tricore-2f-Compilers

clean-vendor-2f-infineon-2f-Libraries-2f-Infra-2f-Platform-2f-Tricore-2f-Compilers:
	-$(RM) ./vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/CompilerDcc.d ./vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/CompilerDcc.o ./vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/CompilerDcc.src ./vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/CompilerGcc.d ./vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/CompilerGcc.o ./vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/CompilerGcc.src ./vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/CompilerGhs.d ./vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/CompilerGhs.o ./vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/CompilerGhs.src ./vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/CompilerGnuc.d ./vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/CompilerGnuc.o ./vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/CompilerGnuc.src ./vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.d ./vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.o ./vendor/infineon/Libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.src

.PHONY: clean-vendor-2f-infineon-2f-Libraries-2f-Infra-2f-Platform-2f-Tricore-2f-Compilers

