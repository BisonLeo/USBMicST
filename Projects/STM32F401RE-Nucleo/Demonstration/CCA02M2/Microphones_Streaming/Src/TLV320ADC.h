/*
 * TLV320ADC.h
 * TLV320ADC3100 control file
 *  Created on: Jan 22, 2021
 *      Author: Joaquin
 */

#ifndef INC_TLV320ADC_H_
#define INC_TLV320ADC_H_

//#include "i2c.h"
//#include "i2s.h"
#include "stm32f4xx_hal.h"
extern I2C_HandleTypeDef hi2c1;
extern I2S_HandleTypeDef hi2s2;


void MX_I2S2_Init(void);
void MX_I2C1_Init(void);
void MX_DMA_Init(void);

#include "usbd_audio_if.h"
#include "usbd_audio_in.h"
//#include "usb_device.h"
//#include "usbd_conf.h"



//#define Buffersize 256
#define  Write_device_address 0x31 // 0b00110001
#define  Read_device_address  0x30 // 0b00110000
#define  Page_cl_rg 		  0x00 //0x00 for page 0 0x01 for page 1
#define  Init_OK              0x01
#define  Init_Error			  0x00
#define  DMAbuffersize        256
#define	 R0x01_0                 0x01 //0b00000001    s/w reset
#define	 R0x04_0                 0x0C //0b00001100    default
#define  R0x05_0                 0x0C //0b00001100    default
#define  R0x06_0                 0x0C //0b00001100    default
#define  R0x07_0                 0x0C //0b00001100    default
#define  R0x08_0                 0x0C //0b00001100    default

#define  R0x12_0			0x81 //0b10000001
#define  R0x13_0			0x82 //0b10000010
#define  R0x14_0			0x80 //0b10000000
#define  R0x15_0			0x80 //0b10000000  IADC
#define  R0x16_0			0x80 //0b00000100  ADC Digital Filter Engine Decimation


#define  R0x1B_0            0x00 //0b00000000  ADC Audio Interface Control
#define  R0x35_0			0x02 //0b00000010  DOUT bus keeper enabled, primary DOUT output for codec interface

#define  R0x51_0            0xC0 //0b11000000 left channel power right channel power
#define  R0x52_0            0x00 //0b00000000  ADC fine volume control
#define  R0x53_0            0x28 //0b00000000  Left ADC volume
																	//100 0000 – 110 1000: Left ADC channel volume = 0 dB
																	//110 1000: Left ADC channel volume = –12 dB
																	//110 1001: Left ADC channel volume = –11.5 dB
																	//110 1010: Left ADC channel volume = –11.0 dB
																	//111 1111: Left ADC channel volume = –0.5 dB
																	//000 0000: Left ADC channel volume = –0.0 dB
																	//000 0001: Left ADC channel volume = 0.5 dB
																	//010 0110: Left ADC channel volume = 19.0 dB
																	//010 0111: Left ADC channel volume = 19.5 dB
																	//010 1000: Left ADC channel volume = 20 dB
																	//010 1001– 011 1111 : Reserved. Do not use.
#define  R0x54_0             0x28 //0b00000000  Right ADC volume
																	//100 0000 – 110 1000: Left ADC channel volume = 0 dB
																	//110 1000: Left ADC channel volume = –12 dB
																	//110 1001: Left ADC channel volume = –11.5 dB
																	//110 1010: Left ADC channel volume = –11.0 dB
																	//111 1111: Left ADC channel volume = –0.5 dB
																	//000 0000: Left ADC channel volume = –0.0 dB
																	//000 0001: Left ADC channel volume = 0.5 dB
																	//010 0110: Left ADC channel volume = 19.0 dB
																	//010 0111: Left ADC channel volume = 19.5 dB
																	//010 1000: Left ADC channel volume = 20 dB
																	//010 1001– 011 1111 : Reserved. Do not use.



#define  R0x33_1            0x20 //0b01000000  2V MICBIAS Control
#define  R0x3B_1			0x50 //Left Analog PGA Seeting = 0dB 01010000
#define  R0x3C_1  			0x50 //Right Analog PGA Seeting = 0dB 01010000
#define  R0x34_1  			0xF3 //Left ADC Input selection for Left PGA = IN1L(P) as Single-Ended
#define  R0x36_1  			0x7F //Register 54: Left ADC Input Selection for Left PGA 00111111
#define  R0x37_1  			0xCF //Right ADC Input selection for Right PGA = IN1R(M) as Single-Ended
#define  R0x39_1  			0x7F //Register 57: Right ADC Input Selection for Right PGA


uint8_t I2C_Buffer_Read;
uint8_t I2C_Buffer_Write;
__IO int16_t    UpdatePointer;

extern uint16_t Data[192];
extern USBD_HandleTypeDef hUsbDeviceFS;
void ADC_init();
void ADC_start();
void DMA_ADC();


#endif /* INC_TLV320ADC_H_ */
