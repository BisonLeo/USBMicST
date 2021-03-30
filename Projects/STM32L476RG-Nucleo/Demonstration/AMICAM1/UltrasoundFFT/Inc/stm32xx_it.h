/**
  ******************************************************************************
  * @file    stm32xx_it.h 
  * @author  SRA
  * @version v1.1.0
  * @date    18-Dec-2020
  * @brief   This file contains the headers of the interrupt handlers.
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
#ifndef __STM32xx_IT_H
#define __STM32xx_IT_H

#ifdef __cplusplus
 extern "C" {
#endif 

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_hal.h"
#include "cmsis_os.h"
#include "amicam1_audio.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
   
void NMI_Handler(void);
void HardFault_Handler(void);
void DebugMon_Handler(void);
void SysTick_Handler(void);
void OTG_FS_IRQHandler(void);

void DMA1_Channel7_IRQHandler(void);
void DMA1_Channel1_IRQHandler(void);
void DMA1_Channel4_IRQHandler(void);
void DMA1_Channel3_IRQHandler(void);

#ifdef __cplusplus
}
#endif

#endif /* __STM32xx_IT_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
