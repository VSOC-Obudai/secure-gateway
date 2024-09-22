/**
 * \file board.h
 * \brief Board configuration file for SecureGateway_V10
 *
 * \version ASDK_0_6_0
 * \copyright Copyright (c) 2019-2020 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Use of this file is subject to the terms of use agreed between (i) you or 
 * the company in which ordinary course of business you are acting and (ii) 
 * Infineon Technologies AG or its licensees. If and as long as no such 
 * terms of use are agreed, use of this file is subject to following:


 * Boost Software License - Version 1.0 - August 17th, 2003

 * Permission is hereby granted, free of charge, to any person or 
 * organization obtaining a copy of the software and accompanying 
 * documentation covered by this license (the "Software") to use, reproduce,
 * display, distribute, execute, and transmit the Software, and to prepare
 * derivative works of the Software, and to permit third-parties to whom the 
 * Software is furnished to do so, all subject to the following:

 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer, must
 * be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are
 * solely in the form of machine-executable object code generated by a source
 * language processor.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE 
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.

 */

#ifndef BOARD_H
#define BOARD_H

#if defined(CONFIG_BOARD_LED_ENABLE)
#include "led/led.h"
extern const LED_t LED_0;
extern const LED_t LED_1;
extern const LED_t LED_RGB_R;
extern const LED_t LED_RGB_G;
extern const LED_t LED_RGB_B;
#endif

#if defined(CONFIG_BOARD_MMC_ENABLE)
void BOARD_MMC_InitPins(void);
#endif

#if defined(CONFIG_BOARD_ETH_ENABLE)
#include "eth/phy/88EA1517.h"
#include "eth/mac/dwmac_qos.h"
extern ETH_MAC_t ETH_0;
extern MARVELL_88EA1517_t MARVELL_88EA1517_0;

void BOARD_ETH0_InitMdioPins(void);
void BOARD_ETH0_InitInputPins(void);
void BOARD_ETH0_DeInitInputPins(void);
void BOARD_ETH0_InitOutputPins(void);
void BOARD_ETH0_DeInitOutputPins(void);

void BOARD_ETH0_InitPpsPins(void);
void BOARD_ETH0_DeInitPpsPins(void);

extern ETH_MAC_t ETH_1;
extern MARVELL_88EA1517_t MARVELL_88EA1517_1;

void BOARD_ETH1_InitMdioPins(void);
void BOARD_ETH1_InitInputPins(void);
void BOARD_ETH1_DeInitInputPins(void);
void BOARD_ETH1_InitOutputPins(void);
void BOARD_ETH1_DeInitOutputPins(void);

void BOARD_ETH1_InitPpsPins(void);
void BOARD_ETH1_DeInitPpsPins(void);

#endif

#if defined(CONFIG_BOARD_SERIALIO_ENABLE)
    #include "serialio.h"
#endif /* CONFIG_BOARD_SERIALIO_ENABLE */

/******************************************************
** TLF       ******************************************
*******************************************************/
//#if defined(CONFIG_BOARD_TLF_ENABLE)
#define TLF_SCLK_PIN    IfxQspi4_SCLK_P22_3_OUT
#define TLF_MTSR_PIN    IfxQspi4_MTSR_P22_0_OUT
#define TLF_MRST_PIN    IfxQspi4_MRSTB_P22_1_IN
#define TLF_CS_PIN      IfxQspi4_SLSO3_P22_2_OUT
#define TLF_QSPI_MAX_BAUDRATE 1000

void BOARD_CAN0_InitSTBpin(void);

#include "Power_Supply.h"

#endif /* BOARD_H */