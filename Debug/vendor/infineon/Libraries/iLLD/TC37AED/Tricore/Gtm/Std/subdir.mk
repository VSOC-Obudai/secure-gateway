################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm.c \
../vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Atom.c \
../vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Cmu.c \
../vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Dpll.c \
../vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Dtm.c \
../vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Psm.c \
../vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Spe.c \
../vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Tbu.c \
../vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Tim.c \
../vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Tom.c 

COMPILED_SRCS += \
./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm.src \
./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Atom.src \
./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Cmu.src \
./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Dpll.src \
./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Dtm.src \
./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Psm.src \
./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Spe.src \
./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Tbu.src \
./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Tim.src \
./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Tom.src 

C_DEPS += \
./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm.d \
./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Atom.d \
./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Cmu.d \
./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Dpll.d \
./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Dtm.d \
./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Psm.d \
./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Spe.d \
./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Tbu.d \
./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Tim.d \
./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Tom.d 

OBJS += \
./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm.o \
./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Atom.o \
./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Cmu.o \
./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Dpll.o \
./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Dtm.o \
./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Psm.o \
./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Spe.o \
./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Tbu.o \
./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Tim.o \
./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Tom.o 


# Each subdirectory must supply rules for building sources it contributes
vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm.src: ../vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm.c vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/%.o: ./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/%.src vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Atom.src: ../vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Atom.c vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Cmu.src: ../vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Cmu.c vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Dpll.src: ../vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Dpll.c vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Dtm.src: ../vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Dtm.c vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Psm.src: ../vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Psm.c vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Spe.src: ../vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Spe.c vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Tbu.src: ../vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Tbu.c vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Tim.src: ../vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Tim.c vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Tom.src: ../vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Tom.c vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-vendor-2f-infineon-2f-Libraries-2f-iLLD-2f-TC37AED-2f-Tricore-2f-Gtm-2f-Std

clean-vendor-2f-infineon-2f-Libraries-2f-iLLD-2f-TC37AED-2f-Tricore-2f-Gtm-2f-Std:
	-$(RM) ./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm.d ./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm.o ./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm.src ./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Atom.d ./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Atom.o ./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Atom.src ./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Cmu.d ./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Cmu.o ./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Cmu.src ./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Dpll.d ./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Dpll.o ./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Dpll.src ./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Dtm.d ./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Dtm.o ./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Dtm.src ./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Psm.d ./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Psm.o ./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Psm.src ./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Spe.d ./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Spe.o ./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Spe.src ./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Tbu.d ./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Tbu.o ./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Tbu.src ./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Tim.d ./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Tim.o ./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Tim.src ./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Tom.d ./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Tom.o ./vendor/infineon/Libraries/iLLD/TC37AED/Tricore/Gtm/Std/IfxGtm_Tom.src

.PHONY: clean-vendor-2f-infineon-2f-Libraries-2f-iLLD-2f-TC37AED-2f-Tricore-2f-Gtm-2f-Std

