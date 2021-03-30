/**
  ******************************************************************************
  * @file    usbd_wcid_interface.h
  * @author  SRA
  * @version v1.1.0
  * @date    18-Dec-2020
  * @brief   Header file for USBD WCID interface
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
#ifndef __USBD_WCID_STREAMING_IF_H
#define __USBD_WCID_STREAMING_IF_H

/* Includes ------------------------------------------------------------------*/
#include "usbd_wcid_streaming.h"
#include "com_manager.h"

#define USB_PACKET_SIZE         4096*2
#define APP_TX_DATA_SIZE        (USB_PACKET_SIZE*2)
#define APP_RX_DATA_SIZE        512

#define STATE_WAITING           (uint8_t)(0x00)
#define STATE_REQUEST_SET       (uint8_t)(0x01)
#define STATE_SIZE_SENT         (uint8_t)(0x02)
#define STATE_DATA_GET          (uint8_t)(0x03)
#define STATE_DATA_SET          (uint8_t)(0x04)
#define STATE_SIZE_RCVD         (uint8_t)(0x05)



#define CMD_SET_REQ           (uint8_t)(0x00)
#define CMD_SIZE_GET          (uint8_t)(0x01)
#define CMD_DATA_GET          (uint8_t)(0x02)
#define CMD_SIZE_SET          (uint8_t)(0x03)
#define CMD_DATA_SET          (uint8_t)(0x04)

extern USBD_WCID_STREAMING_ItfTypeDef  USBD_WCID_STREAMING_fops;
    
/** USB device core handle. */
extern USBD_HandleTypeDef USBD_Device;

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */




#endif /* __USBD_WCID_STREAMING_IF_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
