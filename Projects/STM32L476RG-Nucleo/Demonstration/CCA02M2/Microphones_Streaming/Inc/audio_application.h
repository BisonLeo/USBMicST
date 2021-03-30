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

/** @addtogroup Microphones_Acquisition
  * @{
  */

/** @defgroup AUDIO_APPLICATION 
  * @{
  */

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/** @defgroup AUDIO_APPLICATION_Exported_Defines 
 * @{
 */


/*Comment this define if you want to configure and start acquisition 
depending on USB functionalities implemented by user*/
#define DISABLE_USB_DRIVEN_ACQUISITION


/**
 * @}
 */
/* Exported functions ------------------------------------------------------- */
void Init_Acquisition_Peripherals(uint32_t AudioFreq, uint32_t ChnlNbrIn, uint32_t ChnlNbrOut);
void Start_Acquisition(void);
void Error_Handler(void);
void AudioProcess(void);

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
