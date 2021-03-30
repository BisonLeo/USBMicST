/**
  ******************************************************************************
  * @file    fft_app.h
  * @author  SRA
  * @version v1.1.0
  * @date    18-Dec-2020
  * @brief   Header for fft_app.c module.
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
#ifndef __FFT_APP_H
#define __FFT_APP_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32l4xx_hal.h" 
  
#include "cmsis_os.h"
#include "threadConfig.h"
  
#include "com_manager.h"
#include "usbd_wcid_interface.h"
  
#include "fft.h"
#include "amicam1_conf.h"

  
#define FFT_RAW                 0
#define FFT_AVERAGE             1
#define FFT_WEIGHTED_AVERAGE    2

/* Select one from the list above */
#define FFT_OUTPUT      FFT_RAW
  
  
extern osThreadId FFT_Thread_Id;

void FFT_OS_Init(void);

void FFT_Lib_Data_Input(int16_t * data, uint32_t len);


#ifdef __cplusplus
}
#endif

#endif /* __FFT_APP_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
