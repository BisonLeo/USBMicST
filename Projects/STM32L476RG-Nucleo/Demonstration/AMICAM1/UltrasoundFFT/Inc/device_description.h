/**
  ******************************************************************************
  * @file    com_manager.h
  * @author  SRA
  * @version v1.1.0
  * @date    18-Dec-2020
  * @brief   Header for com_manager.c file.
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
#ifndef __DEVICE_DESCRIPTION_H
#define __DEVICE_DESCRIPTION_H

/* Includes ------------------------------------------------------------------*/
#include "com_manager.h"
#include "sensors_manager.h"
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */


void set_default_description(void);
void update_sensorStatus(COM_SensorStatus_t * oldSensorStatus, COM_SensorStatus_t * newSensorStatus, uint8_t sID);
void update_sensors_config(void);





#endif /* __DEVICE_DESCRIPTION_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
