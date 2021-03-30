/**
 ******************************************************************************
 * @file    cca02m2_conf.h
 * @author  SRA
 * @version v1.0.0
 * @date    17-Jul-2020
 * @brief   This file contains definitions for the MEMSMIC1 applications
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
#include "stm32f4xx_hal.h"
#include "nucleo_f401re_bus.h"
#include "nucleo_f401re_errno.h"


/* The N_MS value defines the number of millisecond to be processed at each AudioProcess call,
that must be consistent with the N_MS_PER_INTERRUPT defined in the audio driver
(cca02m2_audio.h).
The default value of the N_MS_PER_INTERRUPT directive in the driver is set to 1, 
for backward compatibility: leaving this values as it is allows to avoid any 
modification in the application layer developed with the older versions of the driver */

#define N_MS (N_MS_PER_INTERRUPT)
  
#define AUDIO_IN_CHANNELS 2
#define AUDIO_IN_SAMPLING_FREQUENCY 48000

#define AUDIO_IN_BUFFER_SIZE            DEFAULT_AUDIO_IN_BUFFER_SIZE  
#define AUDIO_VOLUME_INPUT              64U
#define CCA02M2_AUDIO_INSTANCE 0U
#define CCA02M2_AUDIO_IN_IT_PRIORITY    6U

#if (AUDIO_IN_SAMPLING_FREQUENCY == 8000)
#define MAX_DECIMATION_FACTOR 160
#else
#define MAX_DECIMATION_FACTOR 128
#endif
  
/*Uncomment to enable High Performance mode when using MP23DB01HP external coupon*/
#define ENABLE_HIGH_PERFORMANCE_MODE 1U
#define AUDIO_IN_BIT_DEPTH AUDIO_RESOLUTION_24b

#ifdef __cplusplus
}
#endif

#endif /* CCA02M2_CONF_H__*/

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

