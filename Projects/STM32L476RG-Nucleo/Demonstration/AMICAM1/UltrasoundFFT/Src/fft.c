/**
 ******************************************************************************
 * @file    fft.c
 * @author  SRA
 * @version v0.0.1
 * @date    26-Nov-2020
 * @brief   FFT helper functions - based on ARM library.
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
#include "fft.h"



#ifdef FFT_DYNAMIC_ALLOCATION
static FFT_Calloc_Function FFT_calloc = calloc;
static FFT_Free_Function FFT_free = free;
#endif

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

#define FLOAT_NORM_FACTOR 1.0f;
#define INT32_NORM_FACTOR 2147483648.0f;
#define INT16_NORM_FACTOR 32768.0f;

/* Private function prototypes -----------------------------------------------*/

static void TukeyWin(uint16_t len, float ratio, float *dest);
static void BlackmanHarrisWin(uint16_t len, float *dest);
static void HammingWin(uint16_t len, float *dest);
static void FFT_create_window(FFT_instance_t *instance);

static int8_t FFT_Memory_Allocation(FFT_instance_t *instance);

#ifdef FFT_DYNAMIC_ALLOCATION
static int8_t FFT_Dynamic_Allocation(FFT_instance_t *instance);
#endif

#ifdef FFT_STATIC_ALLOCATION
static int8_t FFT_Static_Allocation(FFT_instance_t *instance);
#endif

static void FFT_Set_Normalize_Function(FFT_instance_t *instance);
static float FFT_NormalizeFloat(void *data, uint32_t index);
static float FFT_NormalizeInt32(void *data, uint32_t index);
static float FFT_NormalizeInt16(void *data, uint32_t index);

/* Exported Functions --------------------------------------------------------*/


/* Private macro -------------------------------------------------------------*/

/**
 * @brief  Initialize the FFT processing depending on the desired configuration
 * @param  FFT_instance_t* instance
 * @retval 0 if successful, -1 if not
 */
FFT_error_t FFT_Init(FFT_instance_t *instance)
{
  if(instance == NULL)
  {
    instance->context.status = FFT_ERROR_INVALID_PARAMETER;
    return FFT_ERROR_INVALID_PARAMETER;
  }
  if(!(instance->init_params.data_type == FLOAT32 || instance->init_params.data_type == INT32 || instance->init_params.data_type == INT16))
  {
    instance->context.status = FFT_ERROR_INVALID_PARAMETER;
    return FFT_ERROR_INVALID_PARAMETER;
  }

  /* Set Handler status */
  instance->context.status = FFT_ERROR_NONE;

  /* Initialize FFT ARM structure */
  arm_rfft_fast_init_f32(&(instance->context.S), instance->init_params.FFT_len);

  /* Set scratch memory if needed */
  if(instance->init_params.use_direct_process == 0)
  {
    if(instance->init_params.overlap < 0 || instance->init_params.overlap > 1)
    {
      instance->context.status = FFT_ERROR_INVALID_PARAMETER;
      return FFT_ERROR_INVALID_PARAMETER;
    }
    /*Compute indexes to be used for overlap */
    instance->context.new_data_len = (uint32_t) ((float) (instance->init_params.FFT_len) * (1.0f - (float) (instance->init_params.overlap)));
    instance->context.old_data_len = (uint32_t) ((float) (instance->init_params.FFT_len) - instance->context.new_data_len);
  }

  /* Memory allocation */
  if(!FFT_Memory_Allocation(instance))
  {
    instance->context.status = FFT_ERROR_MEMORY;
    return FFT_ERROR_MEMORY;
  }

  /* Create window depending on the user choice */
  FFT_create_window(instance);

  FFT_Set_Normalize_Function(instance);

  return FFT_ERROR_NONE;
}

/**
 * @brief  Deinitialize FFT library
 * @param  FFT_instance_t* instance
 * @retval None
 */
FFT_error_t FFT_DeInit(FFT_instance_t *instance)
{
  /* Reset context variables */
  instance->context.new_data_len = 0;
  instance->context.old_data_len = 0;
  instance->context.scratch_idx = 0;
#ifdef FFT_DYNAMIC_ALLOCATION
  /* Memory deallocation */
  FFT_free(instance->context.win);
  FFT_free(instance->context.scratch);
  FFT_free(instance->context.dataIn);
  FFT_free(instance->context.fftIn);
  FFT_free(instance->context.fftOut);
#endif
  instance->context.normalizeData = NULL;

  return FFT_ERROR_NONE;
}

/**
 * @brief  Fills the "internal_memory_size" of the pHandler parameter passed as argument with a value representing the
 *         right amount of memory needed by the library, depending on the specific static parameters adopted.
 * @param  FFT_instance_t* instance
 * @retval None
 */
int32_t FFT_getMemorySize(FFT_instance_t *instance)
{
  int32_t counterBytes = 0;

  if(instance == 0)
  {
    instance->context.status = FFT_ERROR_INVALID_PARAMETER;
    return -1;
  }
  counterBytes += instance->init_params.FFT_len * sizeof(float);
  counterBytes += instance->init_params.FFT_len * sizeof(float);

  if(instance->init_params.win_type != FFT_RECT_WIN)
  {
    counterBytes += instance->init_params.FFT_len * sizeof(float);
  }
  if(instance->init_params.output_type == MAGNITUDE)
  {
    counterBytes += instance->init_params.FFT_len * sizeof(float);
  }
  if(instance->init_params.overlap >= 0 && instance->init_params.overlap <= 1)
  {
    uint32_t new_data_len = (uint32_t) ((float) (instance->init_params.FFT_len) * (1.0f - (float) (instance->init_params.overlap)));
    counterBytes += new_data_len * sizeof(float);
  }
  return counterBytes;
}

/**
 * @brief  Pass the input data buffer to the FFT library
 * @param  FFT_instance_t* instance
 * @param  data: input data buffer
 * @param  len: length of input data buffer
 * @retval None
 */
int32_t FFT_Data_Input(void *data, uint32_t len, FFT_instance_t *instance)
{
  int32_t ret = 0;
  uint32_t index = 0;
  FFT_data_type_t dataType = instance->init_params.data_type;
  uint32_t s_idx = instance->context.scratch_idx;
  uint32_t new_data_len = instance->context.new_data_len;
  float *scratch_ptr = &instance->context.scratch[s_idx];

  for(index = 0; index < len; index++)
  {
    switch(dataType)
    {
    case FLOAT32:
      *scratch_ptr++ = FFT_NormalizeFloat(data, index);
      break;
    case INT32:
      *scratch_ptr++ = FFT_NormalizeInt32(data, index);
      break;
    case INT16:
      *scratch_ptr++ = FFT_NormalizeInt16(data, index);
      break;
    default:
      *scratch_ptr++ = FFT_NormalizeInt16(data, index);      
      break;
    }
    
    s_idx++;

    if(s_idx == new_data_len)
    {
      float *data_in = instance->context.dataIn;
      uint32_t old_data_len = instance->context.old_data_len;

      memcpy(data_in, &data_in[instance->init_params.FFT_len - old_data_len], old_data_len * sizeof(float));
      memcpy(&data_in[old_data_len], instance->context.scratch, new_data_len * sizeof(float));

      ret = 1;
      s_idx = 0;
      scratch_ptr = &instance->context.scratch[0];
    }
  }

  instance->context.scratch_idx = s_idx;
  return ret;
}

/**
 * @brief  Execute the FFT calculation and returns the FFT amplitude
 * @param  FFT_instance_t* instance
 * @param  output: FFT amplitude buffer
 * @retval None
 */
FFT_error_t FFT_Process(FFT_instance_t *instance, void *output)
{
  float *win = instance->context.win;
  float *dataIn = instance->context.dataIn;
  float *fftIn = instance->context.fftIn;

  if(instance->init_params.win_type != FFT_RECT_WIN)
  {
    arm_mult_f32(dataIn, win, fftIn, instance->init_params.FFT_len);
  }
  else
  {
    memcpy(fftIn, dataIn, sizeof(float) * instance->init_params.FFT_len);
  }

  if(instance->init_params.output_type == COMPLEX)
  {
    arm_rfft_fast_f32(&instance->context.S, fftIn, output, 0);
  }

  if(instance->init_params.output_type == MAGNITUDE)
  {
    float *fftOut = instance->context.fftOut;
    arm_rfft_fast_f32(&instance->context.S, fftIn, fftOut, 0);
    arm_cmplx_mag_f32(fftOut, output, instance->init_params.FFT_len / 2);
  }
  
  if(output == NULL || instance == NULL)
  {
    instance->context.status = FFT_ERROR_INVALID_PARAMETER;
    return FFT_ERROR_INVALID_PARAMETER;
  }
  else if(instance->context.status != FFT_ERROR_NONE)
  {
    return FFT_ERROR_INVALID_EXECUTION;
  }
  else if(instance->init_params.use_direct_process)
  {
    instance->context.status = FFT_ERROR_INVALID_EXECUTION;
    return FFT_ERROR_INVALID_EXECUTION;
  }
  else
  {
    return FFT_ERROR_NONE;
  }
}

/**
 * @brief  Execute the FFT calculation passing directly the input buffer from the user space and returns the FFT amplitude
 * @param  FFT_instance_t* instance
 * @param  output: FFT amplitude buffer
 * @param  input: input data buffer
 * @retval None
 */
FFT_error_t FFT_Direct_Process(FFT_instance_t *instance, void *input, float *output)
{
  float *win = instance->context.win;
  float *fftIn = instance->context.fftIn;
  float *dataIn = instance->context.dataIn;

  for(int i = 0; i < instance->init_params.FFT_len; i++)
    dataIn[i] = instance->context.normalizeData(input, i);

  if(instance->init_params.win_type != FFT_RECT_WIN)
  {
    arm_mult_f32(dataIn, win, fftIn, instance->init_params.FFT_len);
  }
  else
  {
    memcpy(fftIn, dataIn, sizeof(float) * instance->init_params.FFT_len);
  }

  if(instance->init_params.output_type == COMPLEX)
  {
    arm_rfft_fast_f32(&instance->context.S, fftIn, output, 0);
  }

  if(instance->init_params.output_type == MAGNITUDE)
  {
    float *fftOut = instance->context.fftOut;
    arm_rfft_fast_f32(&instance->context.S, fftIn, fftOut, 0);
    arm_cmplx_mag_f32(fftOut, output, instance->init_params.FFT_len / 2);
  }

  return FFT_ERROR_NONE;
}


static void FFT_create_window(FFT_instance_t *instance)
{
  /* Create window depending on the user choice */
  switch(instance->init_params.win_type)
  {
    case FFT_RECT_WIN:
      break;
    case FFT_HAMMING_WIN:
      HammingWin(instance->init_params.FFT_len, instance->context.win);
      break;
    case FFT_HANNING_WIN:
      TukeyWin(instance->init_params.FFT_len, 1.0f, instance->context.win);
      break;
    case FFT_BLACKMAN_HARRIS_WIN:
      BlackmanHarrisWin(instance->init_params.FFT_len, instance->context.win);
      break;
    case FFT_TUKEY_0_25_WIN:
      TukeyWin(instance->init_params.FFT_len, 0.25f, instance->context.win);
      break;
    case FFT_TUKEY_0_75_WIN:
      TukeyWin(instance->init_params.FFT_len, 0.75f, instance->context.win);
      break;
  }
}

/**
 * @brief  Initialize the FFT processing depending on the desired configuration
 * @param  FFT_instance_t* instance
 * @retval 1 if successful, 0 if not
 */
static int8_t FFT_Memory_Allocation(FFT_instance_t *instance)
{
#ifdef FFT_DYNAMIC_ALLOCATION
  /* Memory allocation */
  if(!FFT_Dynamic_Allocation(instance))
  {
    instance->context.status = FFT_ERROR_MEMORY;
    return FFT_ERROR_MEMORY;
  }
#endif
#ifdef FFT_STATIC_ALLOCATION
  FFT_Static_Allocation(instance);
#endif

  return FFT_ERROR_NONE;
}


/**
 * @brief  Initialize dynamically the FFT memory
 * @param  FFT_instance_t* instance
 * @retval 0 if successful, -1 if not
 */
#ifdef FFT_DYNAMIC_ALLOCATION
static int8_t FFT_Dynamic_Allocation(FFT_instance_t *instance)
{
  /* Memory allocation */
  if(instance->init_params.win_type != FFT_RECT_WIN)
  {
    instance->context.win = (float*) FFT_calloc(instance->init_params.FFT_len, sizeof(float));
    if(!instance->context.win)
    {
      instance->context.status = FFT_ERROR_MEMORY;
    }
  }
  if(instance->init_params.output_type == MAGNITUDE)
  {
    instance->context.fftOut = (float*) FFT_calloc(instance->init_params.FFT_len, sizeof(float));
    if(!instance->context.fftOut)
    {
      instance->context.status = FFT_ERROR_MEMORY;
    }
  }
  instance->context.dataIn = (float*) FFT_calloc(instance->init_params.FFT_len, sizeof(float));
  instance->context.fftIn = (float*) FFT_calloc(instance->init_params.FFT_len, sizeof(float));
  if(!instance->context.fftIn || !instance->context.dataIn)
  {
    return -1;
  }

  instance->context.scratch = (float*) FFT_calloc(instance->context.new_data_len, sizeof(float));
  if(!instance->context.scratch)
  {
    return -1;
  }

  return 0;
}
#endif

/**
 * @brief  Initialize statically the FFT memory using the buffer passed by the user.
 * @param  FFT_instance_t* instance
 * @retval 0 if successful, -1 if not
 */
#ifdef FFT_STATIC_ALLOCATION
void FFT_Static_Allocation(FFT_instance_t *instance)
{
  uint32_t index = 0;

  instance->context.dataIn = instance->init_params.userBuffer;
  index += instance->init_params.FFT_len;

  instance->context.fftIn = &instance->init_params.userBuffer[index];
  index += instance->init_params.FFT_len;

  if(instance->init_params.win_type != FFT_RECT_WIN)
  {
    instance->context.win = &instance->init_params.userBuffer[index];
    index += instance->init_params.FFT_len;
  }
  if(instance->init_params.output_type == MAGNITUDE)
  {
    instance->context.fftOut = &instance->init_params.userBuffer[index];
    index += instance->init_params.FFT_len;
  }
  if(instance->init_params.overlap > 0)
    instance->context.scratch = &instance->init_params.userBuffer[index];
}
#endif


static void FFT_Set_Normalize_Function(FFT_instance_t *instance)
{
  switch(instance->init_params.data_type)
  {
    case FLOAT32:
      instance->context.normalizeData = FFT_NormalizeFloat;
      break;
    case INT32:
      instance->context.normalizeData = FFT_NormalizeInt32;
      break;
    case INT16:
      instance->context.normalizeData = FFT_NormalizeInt16;
      break;
  }
}


static void TukeyWin(uint16_t len, float ratio, float *dest)
{
  uint16_t x = 0;
  for(x = 0; x < len * (ratio / 2); x++)
  {
    dest[x] = 0.5f * (1.0f + cosf(2.0f * M_PI / ratio * ((float) x / (len - 1.0f) - (ratio / 2))));
  }
  for(; x < len - len * (ratio / 2); x++)
  {
    dest[x] = 1.0f;
  }
  for(; x < len; x++)
  {
    dest[x] = 0.5f * (1.0f + cosf(2.0f * M_PI / ratio * ((float) x / (len - 1.0f) - 1 + (ratio / 2))));
  }
}

static void HammingWin(uint16_t len, float *dest)
{
  uint16_t x = 0;
  float alpha0 = 0.53836f;
  float alpha1 = 1.0f - alpha0;

  for(x = 0; x < len; x++)
  {
    dest[x] = alpha0 - alpha1 * cosf(2.0f * M_PI * (float) x / (float) len);
  }
}

static void BlackmanHarrisWin(uint16_t len, float *dest)
{
  uint16_t x = 0;
  float alpha0 = 0.42f;
  float alpha1 = 0.5;
  float alpha2 = 0.08f;

  for(x = 0; x < len; x++)
  {
    dest[x] = alpha0 - alpha1 * cosf(2.0f * M_PI * (float) x / (float) len) + -alpha2 * cosf(4.0f * M_PI * (float) x / (float) len);
  }
}

static float FFT_NormalizeFloat(void *data, uint32_t index)
{
  return ((float*) (data))[index] / FLOAT_NORM_FACTOR;
}

static float FFT_NormalizeInt32(void *data, uint32_t index)
{
  return (float) ((int32_t*) (data))[index] / INT32_NORM_FACTOR;
}

static float FFT_NormalizeInt16(void *data, uint32_t index)
{
  return (float) ((int16_t*) (data))[index] / INT16_NORM_FACTOR;
}


#ifdef FFT_DYNAMIC_ALLOCATION
void FFT_set_allocation_functions(FFT_Calloc_Function calloc_fun, FFT_Free_Function free_fun)
{
  FFT_calloc = calloc_fun;
  FFT_free = free_fun;
}
#endif

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
