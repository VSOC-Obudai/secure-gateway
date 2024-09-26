add_library(infineon-board OBJECT)

target_compile_definitions(infineon-board
        PUBLIC
        CONFIG_BOARD_SERIALIO_ENABLE=1
        CONFIG_BOARD_LED_ENABLE=1
        CONFIG_BOARD_ETH_ENABLE=1
        CONFIG_ETH_MAC_DWMAC_QOS=1
)

target_sources(infineon-board
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/assert/assert.h
        ${CMAKE_CURRENT_SOURCE_DIR}/can/can.h
        ${CMAKE_CURRENT_SOURCE_DIR}/eth/mac/dwmac_qos.h
        ${CMAKE_CURRENT_SOURCE_DIR}/eth/mac/eth_mac.h
        ${CMAKE_CURRENT_SOURCE_DIR}/eth/phy/88EA1517.h
        ${CMAKE_CURRENT_SOURCE_DIR}/eth/phy/eth_phy.h
        ${CMAKE_CURRENT_SOURCE_DIR}/eth/phy/mii.h
        ${CMAKE_CURRENT_SOURCE_DIR}/led/led.h
        ${CMAKE_CURRENT_SOURCE_DIR}/lin/ASCLIN_LIN_Master.h
        ${CMAKE_CURRENT_SOURCE_DIR}/power_supply/analog_measure/Analog_Measure.h
        ${CMAKE_CURRENT_SOURCE_DIR}/power_supply/power_good_s/Power_Good_Signals.h
        ${CMAKE_CURRENT_SOURCE_DIR}/power_supply/Power_Supply.h
        ${CMAKE_CURRENT_SOURCE_DIR}/power_supply/TLF3xx8x/TLF3xx8x.h
        ${CMAKE_CURRENT_SOURCE_DIR}/serialio/serialio.h
        ${CMAKE_CURRENT_SOURCE_DIR}/board.h

        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/assert/assert.c
        ${CMAKE_CURRENT_SOURCE_DIR}/can/can.c
        ${CMAKE_CURRENT_SOURCE_DIR}/eth/mac/dwmac_qos.c
        ${CMAKE_CURRENT_SOURCE_DIR}/eth/phy/88EA1517.c
        ${CMAKE_CURRENT_SOURCE_DIR}/eth/phy/eth_phy.c
        ${CMAKE_CURRENT_SOURCE_DIR}/led/led.c
        ${CMAKE_CURRENT_SOURCE_DIR}/lin/ASCLIN_LIN_Master.c
        ${CMAKE_CURRENT_SOURCE_DIR}/power_supply/analog_measure/Analog_Measure.c
        ${CMAKE_CURRENT_SOURCE_DIR}/power_supply/power_good_s/Power_Good_Signals.c
        ${CMAKE_CURRENT_SOURCE_DIR}/power_supply/Power_Supply.c
        ${CMAKE_CURRENT_SOURCE_DIR}/power_supply/TLF3xx8x/TLF3xx8x.c
        ${CMAKE_CURRENT_SOURCE_DIR}/serialio/serialio.c
        ${CMAKE_CURRENT_SOURCE_DIR}/board.c
)

target_include_directories(infineon-board
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/assert
        ${CMAKE_CURRENT_SOURCE_DIR}/can
        ${CMAKE_CURRENT_SOURCE_DIR}/eth/mac
        ${CMAKE_CURRENT_SOURCE_DIR}/eth/phy
        ${CMAKE_CURRENT_SOURCE_DIR}/led
        ${CMAKE_CURRENT_SOURCE_DIR}/lin
        ${CMAKE_CURRENT_SOURCE_DIR}/power_supply
        ${CMAKE_CURRENT_SOURCE_DIR}/power_supply/TLF3xx8x
        ${CMAKE_CURRENT_SOURCE_DIR}/power_supply/analog_measure
        ${CMAKE_CURRENT_SOURCE_DIR}/power_supply/power_good_s
        ${CMAKE_CURRENT_SOURCE_DIR}/serialio
)

target_link_libraries(infineon-board infineon-std)
