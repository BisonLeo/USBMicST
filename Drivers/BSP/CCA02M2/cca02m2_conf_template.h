/**
******************************************************************************
* @file    cca02m2_conf_template.h
* @author  SRA
* @version v1.1.1
* @date    18-Dec-2020
* @brief   This file contains definitions for the MEMSMIC1 applications.
*			User can copy in user space, modify and rename it cca02m2_conf.h
******************************************************************************
* @attention
*
* <h2><center>&copy; Copyright (c) 2020 STMicroelectronics. 
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
#ifndef CCA02M2_CONF_H__
#define CCA02M2_CONF_H__

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
(cca02m2_audio.h).
The default value of the N_MS_PER_INTERRUPT directive in the driver is set to 1, 
for backward compatibility: leaving this values as it is allows to avoid any 
modification in the application layer developed with the older versions of the driver */


#define N_MS (N_MS_PER_INTERRUPT)
  
#define AUDIO_IN_CHANNELS 4
#define AUDIO_IN_SAMPLING_FREQUENCY 16000

#define AUDIO_IN_BUFFER_SIZE            DEFAULT_AUDIO_IN_BUFFER_SIZE  
#define AUDIO_VOLUME_INPUT              64U
#define CCA02M2_AUDIO_INSTANCE 			0U /*Select 0U or 1U in base of the peripheral used (0U->I2S/SAI 1U->DFSDM)*/
#define CCA02M2_AUDIO_IN_IT_PRIORITY    6U

#if (AUDIO_IN_SAMPLING_FREQUENCY == 8000)
#define MAX_DECIMATION_FACTOR 160
#else
#define MAX_DECIMATION_FACTOR 128
#endif
      
	  
/* 	If you want to customize the length of the buffers used into the BSP, uncomment and modify these defines.
	Change the values according to the max PDM clock you want to customize and number of microphones you want to use
 */
	  
//	#define MAX_MIC_FREQ                 	  3072  /*kHz - Maximum PDM clock */ 
//	#define MAX_AUDIO_IN_CHANNEL_NBR_PER_IF   2 /* Maximum number of microhpones channels for peripheral interface */
//	#define MAX_AUDIO_IN_CHANNEL_NBR_TOTAL    4 /* For WB, this must be minimum equal to 2 */

  
//  #define USE_SPI3
  /*If you want to use SPI3 instead of SPI2 for M3 and M4, uncomment this define and 
  close SB20 and SB21*/
  
//  #define PDM_FREQ_16K 2048
  /*Uncomment if you need to change PDM clock frequency when AUDIO_IN_SAMPLING_FREQUENCY = 16000*/

#ifdef __cplusplus
}
#endif

#endif /* CCA02M2_CONF_H__*/

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

