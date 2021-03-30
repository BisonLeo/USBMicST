/**
  ******************************************************************************
  * @file    audio_application.h 
  * @author  SRA
  * @version v1.2.0
  * @date    18-Dec-2020
  * @brief   Header for audio_application.c module.
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
#ifndef __AUDIO_APPLICATION_H
#define __AUDIO_APPLICATION_H

/* Includes ------------------------------------------------------------------*/
#include "cube_hal.h"

/** @addtogroup X_CUBE_MEMSMIC1_Applications
  * @{
  */ 

/** @addtogroup ACOUSTIC_SL_Example
  * @{
  */

/** @defgroup AUDIO_APPLICATION 
  * @{
  */

 /** @defgroup AUDIO_APPLICATION_Private_Types 
  * @{
  */  

  /**
  * @}
  */ 

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/** @defgroup AUDIO_APPLICATION_Exported_Defines 
 * @{
 */

/*Uncomment this define if you want to configure and start acquisition 
independentrly from USB functionalities*/
#define DISABLE_USB_DRIVEN_ACQUISITION

#define TOP_LEFT_MIC 3
#define TOP_RIGHT_MIC 0
#define BOTTOM_LEFT_MIC 2
#define BOTTOM_RIGHT_MIC 1
#define SIDE 147
#define DIAGONAL 212

/**
 * @}
 */
/* Exported functions ------------------------------------------------------- */
void Audio_Libraries_Init(void);
void Error_Handler(void);
void AudioProcess(void);
void SW_IRQ_Tasks_Init(void);
void SW_Task1_Callback(void);
void SW_Task2_Callback(void);
void SW_Task1_Start(void);
void SW_Task2_Start(void);


/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */



#endif /* __AUDIO_APPLICATION_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
