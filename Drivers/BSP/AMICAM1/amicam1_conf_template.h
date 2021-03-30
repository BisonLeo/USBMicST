/**
******************************************************************************
* @file    amicam1_conf_template.h
* @author  SRA - Central Labs
* @version v1.1.0
* @date    03-Apr-2020
* @brief   This file contains definitions for the MEMSMIC1 applications.
*			User can copy in user space, modify and rename it amicam1_conf.h
******************************************************************************
* @attention
*
* <h2><center>&copy; Copyright (c) 2019 STMicroelectronics. 
* All rights reserved.</center></h2>
*
* This software component is licensed by ST under BSD 3-Clause license,
* the "License"; You may not use this file except in compliance with the 
* License. You may obtain a copy of the License at:
*                        opensource.org/licenses/BSD-3-Clause
*
******************************************************************************
*/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef AMICAM1_CONF_H__
#define AMICAM1_CONF_H__

#ifdef __cplusplus
extern "C" {
#endif
  
/* Includes ------------------------------------------------------------------*/  
/* Replace the header file names with the ones of the target platform */
#include "stm32yyxx_hal.h"
#include "nucleo_xyyyzz_bus.h"
#include "nucleo_xyyyzz_errno.h"


/* The N_MS value defines the number of millisecond to be processed at each AudioProcess call,
that must be consistent with the N_MS_PER_INTERRUPT defined in the audio driver
(amicam1_audio.h).
The default value of the N_MS_PER_INTERRUPT directive in the driver is set to 1, 
for backward compatibility: leaving this values as it is allows to avoid any 
modification in the application layer developed with the older versions of the driver */


#define N_MS (N_MS_PER_INTERRUPT)

/* 
Use AUDIO_IN_INSTANCE_ADC_EXT when acquiring microphones AUDIO_IN_ANALOG_MIC1, 2, 3 and/or 4
Use AUDIO_IN_INSTANCE_ADC_INT when acquiring microphones AUDIO_IN_ANALOG_MIC5
In base of the microphones you want to use, select the right AUDIO_IN_CHANNELS
*/  

#define AUDIO_IN_CHANNELS                       2
#define AUDIO_IN_SAMPLING_FREQUENCY             192000
#define AUDIO_IN_INSTANCE          AUDIO_IN_INSTANCE_ADC_EXT //AUDIO_IN_INSTANCE_ADC_INT
#define AUDIO_IN_MICS              (AUDIO_IN_ANALOG_MIC1 | AUDIO_IN_ANALOG_MIC2) //(AUDIO_IN_ANALOG_MIC1 | AUDIO_IN_ANALOG_MIC2| AUDIO_IN_ANALOG_MIC3 | AUDIO_IN_ANALOG_MIC4) //(AUDIO_IN_ANALOG_MIC5)

#define AUDIO_IN_NOT_USED               0
#define AUDIO_IN_BUFFER_SIZE            DEFAULT_AUDIO_IN_BUFFER_SIZE  
#define AUDIO_VOLUME_INPUT              64U
#define AMICAM1_AUDIO_IN_IT_PRIORITY    6U    

  
#define AD1974_BUS_Init                      BSP_SPI1_Init
#define AD1974_BUS_DeInit                    BSP_SPI1_DeInit  
#define AD1974_BUS_Recv                      BSP_SPI1_Recv 
#define AD1974_BUS_Send                      BSP_SPI1_Send   
#define AD1974_BUS_SendRecv                  BSP_SPI1_SendRecv
#define AD1974_BUS_CS_CLK_ENABLE()           __GPIOC_CLK_ENABLE() 
#define AD1974_BUS_CS_PORT                   GPIOC 
#define AD1974_BUS_CS_PIN                    GPIO_PIN_9 

#ifdef __cplusplus
}
#endif

#endif /* AMICAM1_CONF_H__*/

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

