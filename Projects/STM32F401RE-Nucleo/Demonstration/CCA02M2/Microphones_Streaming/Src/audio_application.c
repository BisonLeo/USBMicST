/**
  ******************************************************************************
  * @file    audio_application.c 
  * @author  SRA
  * @version v1.2.0
  * @date    18-Dec-2020
  * @brief   Audio  application. 
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

/* Includes ------------------------------------------------------------------*/
#include "audio_application.h"
#include "TLV320ADC.h"
/** @addtogroup X_CUBE_MEMSMIC1_Applications
* @{
*/ 

/** @addtogroup Microphones_Acquisition
* @{
*/

/** @defgroup AUDIO_APPLICATION 
* @{
*/

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/

/** @defgroup AUDIO_APPLICATION_Exported_Variables 
* @{
*/
uint16_t PDM_Buffer[((((AUDIO_IN_CHANNELS * AUDIO_IN_SAMPLING_FREQUENCY) / 1000) * MAX_DECIMATION_FACTOR) / 16)* N_MS ];
uint16_t PCM_Buffer[((AUDIO_IN_CHANNELS*AUDIO_IN_SAMPLING_FREQUENCY)/1000)  * N_MS ];
CCA02M2_AUDIO_Init_t MicParams;

/**
* @}
*/

/** @defgroup AUDIO_APPLICATION_Private_Variables 
* @{
*/
/* Private variables ---------------------------------------------------------*/
/**
* @}
*/

/** @defgroup AUDIO_APPLICATION_Exported_Function 
* @{
*/

/**
* @brief  Half Transfer user callback, called by BSP functions.
* @param  None
* @retval None
*/
void CCA02M2_AUDIO_IN_HalfTransfer_CallBack(uint32_t Instance)
{  
  UNUSED(Instance);
  AudioProcess();
}

/**
* @brief  Transfer Complete user callback, called by BSP functions.
* @param  None
* @retval None
*/
void CCA02M2_AUDIO_IN_TransferComplete_CallBack(uint32_t Instance)
{  
  UNUSED(Instance);
  AudioProcess();
}

/**
* @brief  User function that is called when 1 ms of PDM data is available.
* 		  In this application only PDM to PCM conversion and USB streaming
*                  is performed.
* 		  User can add his own code here to perform some DSP or audio analysis.
* @param  none
* @retval None
*/

void AudioProcess(void)
{
//  if (CCA02M2_AUDIO_IN_PDMToPCM(CCA02M2_AUDIO_INSTANCE,(uint16_t * )PDM_Buffer,PCM_Buffer) != BSP_ERROR_NONE)
//  {
//    Error_Handler();
//  }
  //Send_Audio_to_USB((int16_t *)PCM_Buffer, (AUDIO_IN_SAMPLING_FREQUENCY/1000)*AUDIO_IN_CHANNELS * N_MS );
  Send_Audio_to_USB((int16_t *)PCM_Buffer, AudioInCtx[0].Size/2);

}

/**
* @brief  User function that is called when 1 ms of PDM data is available.
* 		  In this application only PDM to PCM conversion and USB streaming
*                  is performed.
* 		  User can add his own code here to perform some DSP or audio analysis.
* @param  none
* @retval None
*/
void Init_Acquisition_Peripherals(uint32_t AudioFreq, uint32_t ChnlNbrIn, uint32_t ChnlNbrOut)
{  
  MicParams.BitsPerSample = 16;
  MicParams.ChannelsNbr = ChnlNbrIn;
  MicParams.Device = AUDIO_IN_DIGITAL_MIC;
  MicParams.SampleRate = AudioFreq;
  MicParams.Volume = AUDIO_VOLUME_INPUT;
  
  if (CCA02M2_AUDIO_IN_Init(CCA02M2_AUDIO_INSTANCE, &MicParams)!=BSP_ERROR_NONE)
  {
    Error_Handler();
  }
//  AUDIO_IN_Timer_Init();
  ADC_init();
}

/**
* @brief  User function that is called when 1 ms of PDM data is available.
* 		  In this application only PDM to PCM conversion and USB streaming
*                  is performed.
* 		  User can add his own code here to perform some DSP or audio analysis.
* @param  none
* @retval None
*/
void Start_Acquisition(void)
{  
	ADC_start();
  if (CCA02M2_AUDIO_IN_Record(CCA02M2_AUDIO_INSTANCE, (uint8_t *) PCM_Buffer, AUDIO_IN_BUFFER_SIZE)!=BSP_ERROR_NONE)
  {
    Error_Handler();
  }
//	ADC_start();
//	DMA_ADC();
}



void Error_Handler(void)
{
  while(1);
}


/**
* @}
*/

/**
* @}
*/

/**
* @}
*/

/**
* @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
