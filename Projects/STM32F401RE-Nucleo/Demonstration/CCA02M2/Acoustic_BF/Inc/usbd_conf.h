/**
  ******************************************************************************
  * @file    usbd_conf.h
  * @author  SRA
  * @version v1.2.0
  * @date    18-Dec-2020
  * @brief   General low level driver configuration
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0055, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0055
  *
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USBD_CONF_H
#define __USBD_CONF_H

/* Includes ------------------------------------------------------------------*/
#ifdef USE_STM32F4XX_NUCLEO
#include "stm32f4xx_hal.h"
#endif
#ifdef USE_STM32F0XX_NUCLEO
#include "stm32f0xx_hal.h"
#endif
#ifdef USE_STM32L0XX_NUCLEO
#include "stm32l0xx_hal.h"
#endif
#ifdef USE_STM32L4XX_NUCLEO
#include "stm32l4xx_hal.h"
#endif
#ifdef USE_STM32F7XX_NUCLEO_144
#include "stm32f7xx_hal.h"
#endif
#ifdef USE_STM32F3XX_NUCLEO
#include "stm32f3xx_hal.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern PCD_HandleTypeDef hpcd;
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Common Config */
#define USBD_MAX_NUM_INTERFACES               2
#define USBD_MAX_NUM_CONFIGURATION            1
#define USBD_MAX_STR_DESC_SIZ                 200
#define USBD_SUPPORT_USER_STRING              0 
#define USBD_SELF_POWERED                     1
#define USBD_DEBUG_LEVEL                      0

/* AUDIO Class Config */
#define USBD_AUDIO_FREQ                       48000
#define AUDIO_TOTAL_IF_NUM              0x02

/* Exported macro ------------------------------------------------------------*/
/* Memory management macros */


#define USBD_memset               memset
#define USBD_memcpy               memcpy

#ifdef USE_STATIC_ALLOCATION

#define USBD_free                 USBD_static_free
#define USBD_malloc               USBD_static_malloc
#define MAX_STATIC_ALLOC_SIZE     1600/4
#else
#define USBD_free                 free
#define USBD_malloc               malloc
#define MAX_STATIC_ALLOC_SIZE     4
#endif

/* DEBUG macros */
#if (USBD_DEBUG_LEVEL > 0)
#define USBD_UsrLog(...)   printf(__VA_ARGS__);\
                            printf("\n");
#else
#define USBD_UsrLog(...)
#endif

#if (USBD_DEBUG_LEVEL > 1)

#define  USBD_ErrLog(...)   printf("ERROR: ") ;\
                            printf(__VA_ARGS__);\
                            printf("\n");
#else
#define USBD_ErrLog(...)   
#endif

#if (USBD_DEBUG_LEVEL > 2)                         
#define  USBD_DbgLog(...)   printf("DEBUG : ") ;\
                            printf(__VA_ARGS__);\
                            printf("\n");
#else
#define USBD_DbgLog(...)                         
#endif

/* Exported functions ------------------------------------------------------- */

#endif /* __USBD_CONF_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
