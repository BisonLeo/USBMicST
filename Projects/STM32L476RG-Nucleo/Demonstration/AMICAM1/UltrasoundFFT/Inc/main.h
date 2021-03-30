/**
  ******************************************************************************
  * @file    main.h 
  * @author  SRA
  * @version v1.1.0
  * @date    18-Dec-2020
  * @brief   This file contains all the functions prototypes for the main.c
  *          file.
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
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
  
#include "stm32xx_it.h"
#include "stm32l4xx_nucleo.h"
#include "stm32l4xx_hal.h"
#include "stm32l4xx_hal_conf.h"
#include "cmsis_os.h"
#include "freeRTOS.h"

#include "arm_math.h"

#include "usbd_desc.h"
#include "usbd_wcid_interface.h"
  
#include "sensors_manager.h"
#include "com_manager.h"
  
#include "amicam1_app.h"

#include "HSD_json.h"
#include "device_description.h"  

#ifndef M_PI   
  #define M_PI   3.14159265358979323846264338327950288
#endif

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/  
       
//#define DATA_TEST     /* Uncomment to use fake data for debugging */

/* Memory management macros */   
#define HSD_malloc               malloc
#define HSD_calloc               calloc
#define HSD_free                 free
#define HSD_memset               memset
#define HSD_memcpy               memcpy


/* Exported functions ------------------------------------------------------- */

/** USB Device initialization function. */
void MX_USB_DEVICE_Init(void);
uint8_t StartSensorThread(uint32_t id);
uint8_t StopSensorThread(uint32_t id);

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
