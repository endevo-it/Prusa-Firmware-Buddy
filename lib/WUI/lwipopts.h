
/**
  ******************************************************************************
  * File Name          : lwipopts.h
  * Description        : This file overrides LwIP stack default configuration
  *                      done in opt.h file.
  ******************************************************************************
  * This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * Copyright (c) 2019 STMicroelectronics International N.V.
  * All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice,
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other
  *    contributors to this software may be used to endorse or promote products
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under
  *    this license is void and will automatically terminate your rights under
  *    this license.
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion --------------------------------------*/
#ifndef __LWIPOPTS__H__
    #define __LWIPOPTS__H__

/*-----------------------------------------------------------------------------*/
/* Current version of LwIP supported by CubeMx: 2.0.3 -*/
/*-----------------------------------------------------------------------------*/

/* Within 'USER CODE' section, code will be kept by default at each generation */
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

    #ifdef __cplusplus
extern "C" {
    #endif

    #include <stdint.h>

    /* STM32CubeMX Specific Parameters (not defined in opt.h) ---------------------*/
    /* Parameters set in STM32CubeMX LwIP Configuration GUI -*/
    /*----- WITH_RTOS enabled (Since FREERTOS is set) -----*/
    #define WITH_RTOS 1
    /*----- CHECKSUM_BY_HARDWARE disabled -----*/
    #define CHECKSUM_BY_HARDWARE 0
    /*-----------------------------------------------------------------------------*/

    /* LwIP Stack Parameters (modified compared to initialization value in opt.h) -*/
    /* Parameters set in STM32CubeMX LwIP Configuration GUI -*/
    /*----- Value in opt.h for LWIP_DHCP: 0 -----*/
    #define LWIP_DHCP 1
    /*----- Value in opt.h for MEM_ALIGNMENT: 1 -----*/
    #define MEM_ALIGNMENT 4
    /*----- Value in opt.h for MEMP_NUM_SYS_TIMEOUT: (LWIP_TCP + IP_REASSEMBLY + LWIP_ARP + (2*LWIP_DHCP) + LWIP_AUTOIP + LWIP_IGMP + LWIP_DNS + (PPP_SUPPORT*6*MEMP_NUM_PPP_PCB) + (LWIP_IPV6 ? (1 + LWIP_IPV6_REASS + LWIP_IPV6_MLD) : 0)) -*/
    #define MEMP_NUM_SYS_TIMEOUT 7
    /*----- Value in opt.h for LWIP_ETHERNET: LWIP_ARP || PPPOE_SUPPORT -*/
    #define LWIP_ETHERNET 1
    /*----- Value in opt.h for LWIP_DNS_SECURE: (LWIP_DNS_SECURE_RAND_XID | LWIP_DNS_SECURE_NO_MULTIPLE_OUTSTANDING | LWIP_DNS_SECURE_RAND_SRC_PORT) -*/
    #define LWIP_DNS_SECURE 7

    #define TCP_MSS 536
    #define TCP_WND (2 * TCP_MSS)
    /*----- Value in opt.h for TCP_SND_QUEUELEN: (4*TCP_SND_BUF + (TCP_MSS - 1))/TCP_MSS -----*/
    /*----- Value in opt.h for TCPIP_THREAD_STACKSIZE: 0 -----*/
    #define TCPIP_THREAD_STACKSIZE 2048

    #define TCPIP_MBOX_SIZE 6

    /*----- Value in opt.h for DEFAULT_UDP_RECVMBOX_SIZE: 0 -----*/
    #define DEFAULT_UDP_RECVMBOX_SIZE TCPIP_MBOX_SIZE
    /*----- Value in opt.h for DEFAULT_TCP_RECVMBOX_SIZE: 0 -----*/
    #define DEFAULT_TCP_RECVMBOX_SIZE TCPIP_MBOX_SIZE
    /*----- Value in opt.h for DEFAULT_ACCEPTMBOX_SIZE: 0 -----*/
    #define DEFAULT_ACCEPTMBOX_SIZE TCPIP_MBOX_SIZE
    /*----- Value in opt.h for RECV_BUFSIZE_DEFAULT: INT_MAX -----*/
    #define RECV_BUFSIZE_DEFAULT 2000000000
    /*----- Default Value for LWIP_HTTPD: 0 ---*/
    #define LWIP_HTTPD 1
    /*----- Value in opt.h for LWIP_STATS: 1 -----*/
    #define LWIP_STATS 0
    /*----- Value in opt.h for CHECKSUM_GEN_IP: 1 -----*/
    #define CHECKSUM_GEN_IP 0
    /*----- Value in opt.h for CHECKSUM_GEN_UDP: 1 -----*/
    #define CHECKSUM_GEN_UDP 0
    /*----- Value in opt.h for CHECKSUM_GEN_TCP: 1 -----*/
    #define CHECKSUM_GEN_TCP 0
    /*----- Value in opt.h for CHECKSUM_GEN_ICMP: 1 -----*/
    #define CHECKSUM_GEN_ICMP 0
    /*----- Value in opt.h for CHECKSUM_GEN_ICMP6: 1 -----*/
    #define CHECKSUM_GEN_ICMP6 0
    /*----- Value in opt.h for CHECKSUM_CHECK_IP: 1 -----*/
    #define CHECKSUM_CHECK_IP 0
    /*----- Value in opt.h for CHECKSUM_CHECK_UDP: 1 -----*/
    #define CHECKSUM_CHECK_UDP 0
    /*----- Value in opt.h for CHECKSUM_CHECK_TCP: 1 -----*/
    #define CHECKSUM_CHECK_TCP 0
    /*----- Value in opt.h for CHECKSUM_CHECK_ICMP: 1 -----*/
    #define CHECKSUM_CHECK_ICMP 0
    /*----- Value in opt.h for CHECKSUM_CHECK_ICMP6: 1 -----*/
    #define CHECKSUM_CHECK_ICMP6 0
    /*-----------------------------------------------------------------------------*/
    /* USER CODE BEGIN 1 */
    #define HTTPD_USE_CUSTOM_FSDATA 1 // uses the web resources from fsdata_custom.c (buddy web pages)
    /*
     * FIXME:
     * Workaround:
     *
     * We observed a very weird bug where, while sending a "file", the packets
     * either got reordered (1, 3, 2), which makes a mess of all the TCP
     * congestion algorithms or, when the other side ACKs twice the first
     * packet (to hint that the second one is missing while seeing the third)
     * before the second one goes out, we never actually send the second one.
     * Finding the real cause in either LwIP or our integration of that will be
     * *fun*.
     *
     * As a temporary workaround to deliver the damn file and not require F5 3
     * times to get the pages working, we make sure to send only a single
     * packet at a time. That way it won't reorder. This gives us slight
     * performance degradation, but that doesn't matter with the small web page
     * and makes it actually usable.
     *
     * #BFW-2357
     */
    #define HTTPD_MAX_WRITE_LEN(pcb)     ((u16_t)(altcp_mss(pcb)))
    #define LWIP_NETIF_API               1 // enable LWIP_NETIF_API==1: Support netif api (in netifapi.c)
    #define LWIP_NETIF_LINK_CALLBACK     1 // Support a callback function from an interface whenever the link changes (i.e., link down)
    #define LWIP_NETIF_STATUS_CALLBACK   1 // Support a callback function whenever an interface changes its up/down status (i.e., due to DHCP IP acquisition)
    #define LWIP_HTTPD_DYNAMIC_HEADERS   1
    #define LWIP_SINGLE_NETIF            1
    #define LWIP_NETIF_HOSTNAME          1
    #define LWIP_HTTPD_SUPPORT_POST      1
    #define LWIP_COMPAT_SOCKETS          0
    #define LWIP_ALTCP                   1
    #define LWIP_HTTPD_DYNAMIC_FILE_READ 1
    #define LWIP_TIMERS                  1

    #define HTTPD_SERVER_AGENT "PrusaLink"
    #define LWIP_DNS           1
    #define MEMP_NUM_TCP_PCB   6
    #define SO_REUSE           1 // Allow SOF_REUSEADDR to do something useful.

/* USER CODE END 1 */

    #ifdef __cplusplus
}
    #endif
#endif /*__LWIPOPTS__H__ */

/************************* (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
