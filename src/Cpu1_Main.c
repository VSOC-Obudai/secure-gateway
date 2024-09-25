/**********************************************************************************************************************
 * \file Cpu1_Main.c
 * \copyright Copyright (C) Infineon Technologies AG 2019
 *
 * Use of this file is subject to the terms of use agreed between (i) you or the company in which ordinary course of
 * business you are acting and (ii) Infineon Technologies AG or its licensees. If and as long as no such terms of use
 * are agreed, use of this file is subject to following:
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization obtaining a copy of the software and
 * accompanying documentation covered by this license (the "Software") to use, reproduce, display, distribute, execute,
 * and transmit the Software, and to prepare derivative works of the Software, and to permit third-parties to whom the
 * Software is furnished to do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including the above license grant, this restriction
 * and the following disclaimer, must be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are solely in the form of
 * machine-executable object code generated by a source language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *********************************************************************************************************************/

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "IfxCpu.h"
#include "IfxScuWdt.h"
#include "Ifx_Types.h"

#include <stdio.h>

#include "board.h"

#include "Dts/Dts/IfxDts_Dts.h"
#include "can/can.h"
#include "ethernetif.h"
#include "lwip/api.h"
#include "lwip/apps/httpd.h"
#include "lwip/init.h"
#include "lwip/sys.h"
#include "lwip/tcpip.h"
#include "lwipopts.h"
#include "net.h"

/*------------------------------------------------------Ethernet configuration---------------------------------------*/

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
#if LWIP_DHCP == 0

/* Static IP ADDRESS */
#define IP_ADDR0 192
#define IP_ADDR1 168
#define IP_ADDR2 0
#define IP_ADDR3 110

/* NETMASK */
#define NETMASK_ADDR0 255
#define NETMASK_ADDR1 255
#define NETMASK_ADDR2 255
#define NETMASK_ADDR3 0

/* Gateway Address */
#define GW_ADDR0 192
#define GW_ADDR1 168
#define GW_ADDR2 0
#define GW_ADDR3 1

#endif

#define LINK_STATUS_TIMEOUT 200U

#define RX_DESC_CNT 4
#define TX_DESC_CNT 4

#define RX_BUFFER_SIZE ETH_DMA_BUFFER_SIZE(1500)
#define TX_BUFFER_SIZE ETH_DMA_BUFFER_SIZE(1500)

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/
struct netif netif_0;
static IFX_ALIGN(8) ETH_DMA_DESC_t rx_descs[RX_DESC_CNT];
static IFX_ALIGN(8) ETH_DMA_DESC_t tx_descs[TX_DESC_CNT];
static IFX_ALIGN(8) uint8 rx_bufs[RX_DESC_CNT][RX_BUFFER_SIZE];
static IFX_ALIGN(8) uint8 tx_bufs[TX_DESC_CNT][TX_BUFFER_SIZE];

static ETH_MTL_RX_QUEUE_t rx_queue_0 = {.mode = IfxGeth_RxQueueMode_generic,
                                        .operation_mode.size = IfxGeth_QueueSize_2048Bytes,
                                        .operation_mode.enable_store_and_foward = TRUE};

static ETH_DMA_CHANNEL_t rx_dma_channel_0 = {
    .desc_cnt = RX_DESC_CNT,
    .descs = &rx_descs[0],
    .bufs = &rx_bufs[0][0],
    .buf_size = RX_BUFFER_SIZE,
    .config = 0,
};

static ETH_MTL_TX_QUEUE_t tx_queue_0 = {
    .operation_mode =
        {
            .enable_store_and_foward = TRUE,
            .mode = IfxGeth_TxQueueMode_generic,
            .size = IfxGeth_QueueSize_2048Bytes,
        },
    .weight = 10,

};

static ETH_DMA_CHANNEL_t tx_dma_channel_0 = {
    .desc_cnt = TX_DESC_CNT, .descs = &tx_descs[0], .bufs = &tx_bufs[0][0], .buf_size = TX_BUFFER_SIZE, .config = 0};

/* device MAC address */
static const ETH_MAC_ADDR_FILTER_t mac_addr = {.mac_addr = {0x00, 0x03, 0x19, 0x00, 0x01, 0x01}};

/*----------------------------------------------End of Ethernet configuration----------------------------------------*/
extern IfxCpu_syncEvent g_cpuSyncEvent;

static const char* ssi_tags[] = {
    "cpu_temp",
};

static float cpu_temp;

/*********************************************************************************************************************/
/*----------------------------------------------Function Implementations---------------------------------------------*/
/*********************************************************************************************************************/

/*----------------------------------------------HTTP Server functions------------------------------------------------*/
/*
 * @brief Convert a decimal number into a string
 * @param string_p pointer to string containing the converted number
 * @param number_i decimal number input
 * @return converted string length
 */

int IntToStr(char* string_p, int number_i)
{
  int l_divide_i;
  int l_modResult_i;
  int l_length_i;
  int l_isNegative_i;
  int l_copyOfNumber_i;

  if (string_p == NULL)
  {
    return 0;
  }

  if (number_i == 0)
  {
    string_p[0] = '0';
    string_p[1] = '\0';
    return 1;
  }

  l_divide_i = 0;
  l_length_i = 0;
  l_isNegative_i = 0;
  l_copyOfNumber_i = number_i;

  if (number_i < 0)
  {
    l_isNegative_i = 1;
    number_i = -number_i;
    l_length_i++;
  }

  while (l_copyOfNumber_i != 0)
  {
    l_length_i++;
    l_copyOfNumber_i /= 10;
  }

  for (l_divide_i = 0; l_divide_i < l_length_i; l_divide_i++)
  {
    l_modResult_i = number_i % 10;
    number_i = number_i / 10;
    string_p[l_length_i - (l_divide_i + 1)] = l_modResult_i + '0';
  }

  if (l_isNegative_i == 1)
  {
    string_p[0] = '-';
  }
  string_p[l_length_i] = '\0';

  return (l_length_i);
}

/* Initialisation of functions to be used with CGi */
/*  CGI handler to switch LED status */
const char* ledcontrol_handler(int iIndex, int iNumParams, char* pcParam[], char* pcValue[])
{
  (void)iIndex;
  (void)iNumParams;
  (void)pcParam;

  if (strcmp(pcValue[0], "led1") == 0)
  {
    LED_Toggle(&LED_RGB_R);
  }
  else if (strcmp(pcValue[0], "led2") == 0)
  {
    LED_Toggle(&LED_RGB_G);
  }
  else
  {
    LED_Toggle(&LED_RGB_B);
  }

  return "/cgi.htm";
}

const char* data_handler(int iIndex, int iNumParams, char* pcParam[], char* pcValue[])
{
  (void)iIndex;
  (void)iNumParams;
  (void)pcParam;
  (void)pcValue;

  return "/data.ssi";
}

tCGI led_handler_struct[] = {{.pcCGIName = "/ledcontrol.cgi", .pfnCGIHandler = ledcontrol_handler},
                             {.pcCGIName = "/data.cgi", .pfnCGIHandler = data_handler}};

int cgi_init(void)
{
  http_set_cgi_handlers(led_handler_struct, 2);

  return 0;
}

static uint16_t ssi_handler(int iIndex, char* pcInsert, int iInsertLen)
{
  (void)iIndex;
  (void)iInsertLen;

  return ((uint16)IntToStr(pcInsert, cpu_temp));
}

static void ssi_init(void)
{
  for (size_t i = 0; i < LWIP_ARRAYSIZE(ssi_tags); ++i)
  {
    LWIP_ASSERT("tag too long for LWIP_HTTPD_MAX_TAG_NAME_LEN", strlen(ssi_tags[i]) <= LWIP_HTTPD_MAX_TAG_NAME_LEN);
  }

  http_set_ssi_handler(ssi_handler, ssi_tags, LWIP_ARRAYSIZE(ssi_tags));
}

/*-------------------------------------------------HTTP Server functions end-----------------------------------------*/

static void ethernetif_link_status(void* args)
{
  (void)args;
  if (MARVELL_88EA1517_GetLinkStatus(&MARVELL_88EA1517_1) == ETH_PHY_LINK_STATUS_DOWN)
  {
    if (netif_is_link_up(&netif_0))
    {
      netif_set_link_down(&netif_0);
    }
  }
  else
  {
    if (!netif_is_link_up(&netif_0))
    {
      netif_set_link_up(&netif_0);
    }
  }

  sys_timeout(LINK_STATUS_TIMEOUT, ethernetif_link_status, NULL);
}

void netif_link_callback(struct netif* const netif)
{
  if (netif_is_link_up(netif))
  {
    sint32 speed = MARVELL_88EA1517_GetLinkSpeed(&MARVELL_88EA1517_1);
    sint32 mode = MARVELL_88EA1517_GetLinkMode(&MARVELL_88EA1517_1);

    MARVELL_88EA1517_ConfigureLeds(&MARVELL_88EA1517_1);

    switch (speed)
    {
    case ETH_PHY_LINK_SPEED_10M:
      speed = ETH_MAC_LINK_SPEED_10M;
      break;

    case ETH_PHY_LINK_SPEED_100M:
      speed = ETH_MAC_LINK_SPEED_100M;
      break;

    case ETH_PHY_LINK_SPEED_1000M:
      speed = ETH_MAC_LINK_SPEED_1000M;
      break;

    default:
      break;
    }
    /* Ethernet input pins configuration */
    BOARD_ETH1_InitInputPins();

    ETH_MAC_Start(&ETH_1, speed, mode);

    /* Ethernet output pins configuration */
    BOARD_ETH1_InitOutputPins();

    netif_set_up(netif);

#if LWIP_DHCP == 1
    /* Start DHCP query */
    dhcp_start(netif);
#elif LWIP_AUTOIP == 1
    /* Start AUTOIP probing */
    autoip_start(netif);
#endif
  }
  else
  {
    netif_set_down(netif);

    BOARD_ETH1_DeInitOutputPins();

    ETH_MAC_Stop(&ETH_1);

    BOARD_ETH1_DeInitInputPins();
  }
}

#if LWIP_NETIF_STATUS_CALLBACK == 1
/* The status callback will be called anytime the interface is brought up and down.
   For example, if you would like to log the IP address chosen by DHCP when it has got one,
   and know when this address changes, then you can use the status callback hook.
   The function being called is netif_status_callback */

void netif_status_callback(struct netif* netif)
{
#if LWIP_DHCP
  if (dhcp_supplied_address(netif) > 0)
  {
    PRINTF_STRING("Got IP:%s\r\n", ip4addr_ntoa(netif_ip4_addr(netif)));
    /* Initialize echo server */
    httpd_init();
    cgi_init();
    ssi_init();
  }
#else
  if (netif_is_up(netif))
  {
    /* Initialize HTTP server */
    httpd_init();
    cgi_init();
    ssi_init();
  }
#endif
}
#endif

uint8 netif_select_egress_queue(struct netif* const netif, struct pbuf* p)
{
  (void)netif;
  (void)p;

  return 0;
}

static void toggle_led(void* arg)
{
  (void)arg;

  LED_Toggle(&LED_1);
  cpu_temp = IfxDts_Dts_getTemperatureCelsius();

  sys_timeout(1000, toggle_led, NULL);
}

/*********************************************************************************************************************/
/*---------------------------------------------- End of Function Implementations-------------------------------------*/
/*********************************************************************************************************************/
void core1_main(void)
{
  IfxCpu_enableInterrupts();

  /* !!WATCHDOG1 IS DISABLED HERE!!
   * Enable the watchdog and service it periodically if it is required
   */
  IfxScuWdt_disableCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());

  /* Wait for CPU sync event */
  IfxCpu_emitEvent(&g_cpuSyncEvent);
  IfxCpu_waitEvent(&g_cpuSyncEvent, 1);

  /* Init serial Interface */
  LED_Init(&LED_1);
  LED_On(&LED_1);
  LED_Init(&LED_RGB_R);
  LED_Init(&LED_RGB_G);
  LED_Init(&LED_RGB_B);

  /* Initialize TCP/IP stack */
  net_initialize();

  /* Configure ethernet port */
  ETH_1.mac_addr = &mac_addr;
  ETH_1.rx_queue[0] = &rx_queue_0;
  ETH_1.rx_dma_channel[0] = &rx_dma_channel_0;
  ETH_1.tx_queue[0] = &tx_queue_0;
  ETH_1.tx_dma_channel[0] = &tx_dma_channel_0;

  /* Initialize ETH port */
  ETH_MAC_Init(&ETH_1);

  BOARD_ETH1_InitMdioPins();
  if (MARVELL_88EA1517_Init(&MARVELL_88EA1517_1, ETH_PHY_CONFIG_INTERFACE_RGMII_TXID | ETH_PHY_CONFIG_AUTONEG) != 0)
  {
    while (1)
      ;
  }

  if (netif_add_noaddr(&netif_0, &ETH_1, ethernetif_init, ethernet_input) == NULL)
  {
    /* error */
    while (1)
      ;
  }

  sys_timeout(LINK_STATUS_TIMEOUT, ethernetif_link_status, NULL);

#if LWIP_DHCP == 1
  /* Start DHCP query */
  dhcp_start(&netif_0);
#else
  ip_addr_t ipaddr;
  ip_addr_t netmask;
  ip_addr_t gw;

  IP4_ADDR(&ipaddr, IP_ADDR0, IP_ADDR1, IP_ADDR2, IP_ADDR3);
  IP4_ADDR(&netmask, NETMASK_ADDR0, NETMASK_ADDR1, NETMASK_ADDR2, NETMASK_ADDR3);
  IP4_ADDR(&gw, GW_ADDR0, GW_ADDR1, GW_ADDR2, GW_ADDR3);

  netif_set_addr(&netif_0, &ipaddr, &netmask, &gw);
#endif

  /* Start LED blink timer */
  sys_timeout(1000, toggle_led, NULL);

  while (1)
  {
    /* Go through the application owned descriptors */
    while (!ETH_MAC_IsRxDescriptorOwnedByDma(&ETH_1, 0))
    {
      ethernetif_input(&netif_0, 0);
    }
    sys_check_timeouts();
  }
}
