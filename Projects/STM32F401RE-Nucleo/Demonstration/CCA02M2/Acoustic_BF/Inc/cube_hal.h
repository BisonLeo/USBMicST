/**
  ******************************************************************************
  * @file    cube_hal.h
  * @author  SRA
  * @version v1.2.0
  * @date    18-Dec-2020
  * @brief   Header for cube_hal.c module
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

#ifndef _CUBE_HAL_H_
#define _CUBE_HAL_H_

/* Includes ------------------------------------------------------------------*/
#ifdef USE_STM32F4XX_NUCLEO
#define USB_IRQHandler OTG_FS_IRQHandler
#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"
#include "stm32xx_it.h"
#include "stm32f4xx_nucleo.h"
#include "usbd_core.h"
#include "usbd_desc.h"
#include "usbd_audio_in.h"
#include "usbd_audio_if.h"    
#include "audio_application.h"
#include "cca02m2_audio.h"
#endif


void SystemClock_Config(void);

#endif //_CUBE_HAL_H_
