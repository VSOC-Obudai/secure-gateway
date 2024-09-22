################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/board/eth/phy/88EA1517.c \
../vendor/board/eth/phy/eth_phy.c 

COMPILED_SRCS += \
./vendor/board/eth/phy/88EA1517.src \
./vendor/board/eth/phy/eth_phy.src 

C_DEPS += \
./vendor/board/eth/phy/88EA1517.d \
./vendor/board/eth/phy/eth_phy.d 

OBJS += \
./vendor/board/eth/phy/88EA1517.o \
./vendor/board/eth/phy/eth_phy.o 


# Each subdirectory must supply rules for building sources it contributes
vendor/board/eth/phy/88EA1517.src: ../vendor/board/eth/phy/88EA1517.c vendor/board/eth/phy/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/board/eth/phy/%.o: ./vendor/board/eth/phy/%.src vendor/board/eth/phy/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

vendor/board/eth/phy/eth_phy.src: ../vendor/board/eth/phy/eth_phy.c vendor/board/eth/phy/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x -DCONFIG_BOARD_SERIALIO_ENABLE -DCONFIG_BOARD_LED_ENABLE -DCONFIG_BOARD_ETH_ENABLE -DCONFIG_ETH_MAC_DWMAC_QOS "-fC:/workspace/secure-gateway/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-vendor-2f-board-2f-eth-2f-phy

clean-vendor-2f-board-2f-eth-2f-phy:
	-$(RM) ./vendor/board/eth/phy/88EA1517.d ./vendor/board/eth/phy/88EA1517.o ./vendor/board/eth/phy/88EA1517.src ./vendor/board/eth/phy/eth_phy.d ./vendor/board/eth/phy/eth_phy.o ./vendor/board/eth/phy/eth_phy.src

.PHONY: clean-vendor-2f-board-2f-eth-2f-phy

