/**
  @page SLocApplication Source Localization Application
  
  @verbatim
  ******************** (C) COPYRIGHT 2020 STMicroelectronics *******************
  * @file    readme.txt  
  * @author  SRA
  * @version v1.2.0
  * @date    18-Dec-2020
  * @brief   Description of the Source Localization application example.
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
  @endverbatim

@par Application Description 


This document provides a description of the sound source localization application based 
on Nucleo boards and X-NUCLEO-CCA02M2 expansion board. It allows acquisition of 
4 digital MEMS microphones, PDM to PCM decimation and microphone streaming.
The 4 microphones acquired are used to run Acoustic SL library in order to detect 
sound direction in a range of 360 degrees. The detected angle is then streamed via the 
ST-Link virtual com port to an host PC running a standard serial communication tool.

NOTE: to fully take advantage of this example, microphones must be arranged in a square shape 
using the following X-NUCLEO-CCA02M2 connectors: M1_EXT_B, M2_EXT, M3_EXT, M4_EXT_B.
Solder bridge configuration must be set for 4 microphone acquisition, as depicted in the 
X-CUBE-MEMSMIC1 user manual.

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application need to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents 

  - Acoustic_SL/Src/stm32xx_it.c            	Interrupt handlers file for STM32F4
  - Acoustic_SL/Src/system_stm32f4xx.c      	STM32F4xx system clock configuration file
  - Acoustic_SL/Src/usbd_audio_if.c		    	USBD Audio-input interface  
  - Acoustic_SL/Src/usbd_conf_f4.c    			USB device driver Configuration file for STM32F4
  - Acoustic_SL/Src/usbd_desc.c    				USB device AUDIO-input descriptor   
  - Acoustic_SL/Src/cube_hal_f4.c           	Clock configuration file for STM32F4
  - Acoustic_SL/Src/main.c                  	Main program	
  - Acoustic_SL/Src/audio_application.c  		Audio application file
  - Acoustic_SL/Src/com.c						UART configuration file
												
  - Acoustic_SL/Inc/stm32f4xx_hal_conf.h    	HAL configuration file for STM32F4
  - Acoustic_SL/Inc/stm32xx_it.h            	Interrupt handlers header file for STM32F4
  - Acoustic_SL/Inc/main.h                  	Main program header file
  - Acoustic_SL/Inc/cube_hal.h			    	X-CUBE includes file
  - Acoustic_SL/Inc/audio_application.h  		Application header file
  - Acoustic_SL/Inc/usbd_audio_if.h		    	USBD Audio-input interface header file  
  - Acoustic_SL/Inc/usbd_conf.h    				USB device driver Configuration file
  - Acoustic_SL/Inc/usbd_desc.h    				USB device AUDIO-input descriptor header file
  - Acoustic_SL/Inc/com.h						UART configuration header file 
  - Acoustic_SL/Inc/cca02m2_conf.h 	X-NUCLEO-CCA02M2 configuration file
  - Acoustic_SL/Inc/cca02m2_errno.h	Error file


@par Hardware and Software environment

  - This example runs on STM32F401RE.
    
  - This example has been tested with STMicroelectronics NUCLEO-F401RE RevC  
    boards and can be easily tailored to any other supported device 
    and development board.
    
@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
