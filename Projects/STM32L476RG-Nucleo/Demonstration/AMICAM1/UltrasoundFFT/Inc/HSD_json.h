/**
  ******************************************************************************
  * @file    HSD_json.h
  * @author  SRA
  * @version v1.1.0
  * @date    18-Dec-2020
  * @brief   This file contains all the functions prototypes for the main.c
  *          file.
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
#ifndef __JSON_PARSER_H
#define __JSON_PARSER_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "com_manager.h"
#include "string.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
  
#define PRETTY_JSON 1U
#define SHORT_JSON  0U
  
/* Exported functions ------------------------------------------------------- */
  
int32_t HSD_JSON_set_allocation_functions(void * (*Malloc_Function)(size_t), void(*Free_Function)(void *));
int32_t HSD_JSON_free(void * mem);
int32_t HSD_JSON_serialize_Device(COM_Device_t *Device, char **SerializedJSON, uint8_t pretty);
int32_t HSD_JSON_serialize_DeviceInfo(COM_DeviceDescriptor_t *DeviceInfo, char **SerializedJSON);
int32_t HSD_JSON_serialize_Sensor(COM_Sensor_t *Sensor, char **SerializedJSON);
int32_t HSD_JSON_serialize_SensorDescriptor(COM_SensorDescriptor_t *SensorDescriptor, char **SerializedJSON);
int32_t HSD_JSON_serialize_SensorStatus(COM_SensorStatus_t *SensorStatus, char **SerializedJSON);
int32_t HSD_JSON_serialize_SubSensorDescriptor(COM_SubSensorDescriptor_t *SubSensorDescriptor, char **SerializedJSON);
int32_t HSD_JSON_serialize_SubSensorStatus(COM_SubSensorStatus_t *SubSensorStatus, char **SerializedJSON);
  
int32_t HSD_JSON_parse_Device(char *SerializedJSON, COM_Device_t * Device);
int32_t HSD_JSON_parse_Status(char *SerializedJSON, COM_SensorStatus_t * SensorStatus);
int32_t HSD_JSON_parse_Command(char *SerializedJSON, COM_Command_t * Command);


#ifdef __cplusplus
}
#endif

#endif /* __JSON_PARSER_H */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
