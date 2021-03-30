/**
 ******************************************************************************
 * @file    fft.h
 * @author  SRA
 * @version v0.0.1
 * @date    26-Nov-2020
 * @brief   header for fft.c file .
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
#ifndef __FFT_H
#define __FFT_H

#ifndef __FPU_PRESENT
#define __FPU_PRESENT (1)
#endif

/* Includes ------------------------------------------------------------------*/
#include "arm_math.h"
#include "math.h"
#include "stdlib.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846f
#endif

#define FFT_DYNAMIC_ALLOCATION
//#define FFT_STATIC_ALLOCATION

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
/* Exported typedef --------------------------------------------------------*/


typedef enum
{
  FFT_RECT_WIN = 0, FFT_HAMMING_WIN, FFT_HANNING_WIN, FFT_BLACKMAN_HARRIS_WIN, FFT_TUKEY_0_25_WIN, FFT_TUKEY_0_75_WIN,
} FFT_windows_t;

typedef enum
{
  COMPLEX = 0, MAGNITUDE,
} FFT_output_type_t;

typedef enum
{
  FLOAT32 = 0, INT32, INT16
} FFT_data_type_t;

typedef enum
{
  FFT_ERROR_NONE = 0, FFT_ERROR_INVALID_PARAMETER, FFT_ERROR_MEMORY, FFT_ERROR_INVALID_EXECUTION
} FFT_error_t;

typedef enum
{
  DIRECT_PROCESS_DISABLED = 0, DIRECT_PROCESS_ENABLED
} FFT_direct_process_t;

typedef void* (*FFT_Malloc_Function)(size_t);
typedef void* (*FFT_Calloc_Function)(size_t, size_t);
typedef void (*FFT_Free_Function)(void*);

typedef struct
{
  arm_rfft_fast_instance_f32 S;
  uint32_t new_data_len;
  uint32_t old_data_len; /* New data Idx */
  uint32_t scratch_idx;
  float *win;
  float *scratch;
  float *dataIn;
  float *fftIn;
  float *fftOut;
  float (*normalizeData)(void *data, uint32_t index);
  FFT_error_t status;
} FFT_context_t;

typedef struct
{
  FFT_direct_process_t use_direct_process;
  uint32_t FFT_len;
  float overlap;
  FFT_windows_t win_type;
  FFT_data_type_t data_type;
  FFT_output_type_t output_type;
#ifdef FFT_STATIC
  float * userBuffer;  /*   used to refer the context buffer pointers, in the follow order:
                            - dataIn
                            - fftIn
                            - win
                            - fftOut
                            - scratch   */
#endif
} FFT_init_params_t;

typedef struct
{
  FFT_init_params_t init_params;
  FFT_context_t context;
} FFT_instance_t;

/* Exported macro ------------------------------------------------------------*/
/** @defgroup AUDIO_APPLICATION_Exported_Defines 
 * @{
 */

/**
 * @}
 */
/* Exported functions ------------------------------------------------------- */
FFT_error_t FFT_Init(FFT_instance_t *instance);
FFT_error_t FFT_DeInit(FFT_instance_t *instance);

int32_t FFT_getMemorySize(FFT_instance_t *instance);
int32_t FFT_Data_Input(void *data, uint32_t len, FFT_instance_t *instance);

FFT_error_t FFT_Process(FFT_instance_t *instance, void *output);
FFT_error_t FFT_Direct_Process(FFT_instance_t *instance, void *input, float *output);
void FFT_set_allocation_functions(FFT_Calloc_Function calloc_fun, FFT_Free_Function free_fun);

/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

#endif /* __FFT_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
