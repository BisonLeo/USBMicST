/*
 * TLV320ADC.c
 * TLV320ADC3100 control file
 *  Created on: Jan 22, 2021
 *      Author: Joaquin
 */

#include "TLV320ADC.h"
//
//USBD_AUDIO_HandleTypeDef   *haudio1;
//haudio1 = (USBD_AUDIO_HandleTypeDef *)hUsbDeviceFS->pClassData;
//uint16_t PCM_Buffer[((2*48000)/1000)  * 1 * 2];
extern uint16_t PCM_Buffer[];
extern uint16_t I2S_InternalBuffer[];
extern HAL_StatusTypeDef AUDIO_IN_Timer_Init(void);

/**
  * @brief  TLV320ADC3100 init function
  * @note   You can check the TLV320ADC.h for more register fucntion
  * @retval Init status
  */

void ADC_init(){

	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,0);  //reset
	HAL_Delay(10);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,1);  //reset

	I2C_Buffer_Read =0x00;

	I2C_Buffer_Write = 0x00;
	HAL_I2C_Mem_Write(&hi2c1, Write_device_address, 0x00, I2C_MEMADD_SIZE_8BIT, &I2C_Buffer_Write, 1, 100); //page 0
	HAL_I2C_Mem_Read(&hi2c1, Write_device_address, 0x00, I2C_MEMADD_SIZE_8BIT, &I2C_Buffer_Read, 1, 100);
	if (I2C_Buffer_Read!=I2C_Buffer_Write){
		while(1);
	}

	I2C_Buffer_Write = R0x01_0;
	HAL_I2C_Mem_Write(&hi2c1, Write_device_address, 0x01, I2C_MEMADD_SIZE_8BIT, &I2C_Buffer_Write, 1, 100); //soft reset


	I2C_Buffer_Write = R0x12_0;
	HAL_I2C_Mem_Write(&hi2c1, Write_device_address, 0x12, I2C_MEMADD_SIZE_8BIT, &I2C_Buffer_Write, 1, 100); //NADC 1
	HAL_I2C_Mem_Read(&hi2c1, Write_device_address, 0x12, I2C_MEMADD_SIZE_8BIT, &I2C_Buffer_Read, 1, 100);
	if (I2C_Buffer_Read!=I2C_Buffer_Write){
		while(1);
	}


	I2C_Buffer_Write = R0x13_0;
	HAL_I2C_Mem_Write(&hi2c1, Write_device_address, 0x13, I2C_MEMADD_SIZE_8BIT, &I2C_Buffer_Write, 1, 100);	//MADC 2
	HAL_I2C_Mem_Read(&hi2c1, Write_device_address, 0x13, I2C_MEMADD_SIZE_8BIT, &I2C_Buffer_Read, 1, 100);
	if (I2C_Buffer_Read!=I2C_Buffer_Write){
		while(1);
	}


	I2C_Buffer_Write = R0x14_0;
	HAL_I2C_Mem_Write(&hi2c1, Write_device_address, 0x14, I2C_MEMADD_SIZE_8BIT, &I2C_Buffer_Write, 1, 100);	//AOSR 128
	HAL_I2C_Mem_Read(&hi2c1, Write_device_address, 0x14, I2C_MEMADD_SIZE_8BIT, &I2C_Buffer_Read, 1, 100);
	if (I2C_Buffer_Read!=I2C_Buffer_Write){
		while(1);
	}


	I2C_Buffer_Write = R0x1B_0;
	HAL_I2C_Mem_Write(&hi2c1, Write_device_address, 0x1B, I2C_MEMADD_SIZE_8BIT, &I2C_Buffer_Write, 1, 100);	//ADC Audio Interface Control
	HAL_I2C_Mem_Read(&hi2c1, Write_device_address, 0x1B, I2C_MEMADD_SIZE_8BIT, &I2C_Buffer_Read, 1, 100);
	if (I2C_Buffer_Read!=I2C_Buffer_Write){
		while(1);
	}


//	I2C_Buffer_Write = R0x35_0;
//	HAL_I2C_Mem_Write(&hi2c1, Write_device_address, 0x35, I2C_MEMADD_SIZE_8BIT, &I2C_Buffer_Write, 1, 100);	//DOUT bus keeper enabled, primary DOUT output for codec interface

	I2C_Buffer_Write = 0x01;
	HAL_I2C_Mem_Write(&hi2c1, Write_device_address, 0x00, I2C_MEMADD_SIZE_8BIT, &I2C_Buffer_Write, 1, 100); //page 1
	HAL_I2C_Mem_Read(&hi2c1, Write_device_address, 0x00, I2C_MEMADD_SIZE_8BIT, &I2C_Buffer_Read, 1, 100);
	if (I2C_Buffer_Read!=I2C_Buffer_Write){
		while(1);
	}


	I2C_Buffer_Write = R0x33_1;
	HAL_I2C_Mem_Write(&hi2c1, Write_device_address, 0x33, I2C_MEMADD_SIZE_8BIT, &I2C_Buffer_Write, 1, 100); //MICBIAS 2.5V
	HAL_I2C_Mem_Read(&hi2c1, Write_device_address, 0x33, I2C_MEMADD_SIZE_8BIT, &I2C_Buffer_Read, 1, 100);
	if (I2C_Buffer_Read!=I2C_Buffer_Write){
		while(1);
	}


	I2C_Buffer_Write = R0x3B_1;
	HAL_I2C_Mem_Write(&hi2c1, Write_device_address, 0x3B, I2C_MEMADD_SIZE_8BIT, &I2C_Buffer_Write, 1, 100); //Left PGA on and gain
	HAL_I2C_Mem_Read(&hi2c1, Write_device_address, 0x3B, I2C_MEMADD_SIZE_8BIT, &I2C_Buffer_Read, 1, 100);
	if (I2C_Buffer_Read!=I2C_Buffer_Write){
		while(1);
	}


	I2C_Buffer_Write = R0x3C_1;
	HAL_I2C_Mem_Write(&hi2c1, Write_device_address, 0x3C, I2C_MEMADD_SIZE_8BIT, &I2C_Buffer_Write, 1, 100);//Right PGA on and gain
	HAL_I2C_Mem_Read(&hi2c1, Write_device_address, 0x3C, I2C_MEMADD_SIZE_8BIT, &I2C_Buffer_Read, 1, 100);
	if (I2C_Buffer_Read!=I2C_Buffer_Write){
		while(1);
	}


	I2C_Buffer_Write = R0x34_1;
	HAL_I2C_Mem_Write(&hi2c1, Write_device_address, 0x34, I2C_MEMADD_SIZE_8BIT, &I2C_Buffer_Write, 1, 100);//Left PGA input selection
	HAL_I2C_Mem_Read(&hi2c1, Write_device_address, 0x34, I2C_MEMADD_SIZE_8BIT, &I2C_Buffer_Read, 1, 100);
	if (I2C_Buffer_Read!=I2C_Buffer_Write){
		while(1);
	}


	I2C_Buffer_Write = R0x36_1;
	HAL_I2C_Mem_Write(&hi2c1, Write_device_address, 0x36, I2C_MEMADD_SIZE_8BIT, &I2C_Buffer_Write, 1, 100);//Left PGA input selection 2
	HAL_I2C_Mem_Read(&hi2c1, Write_device_address, 0x36, I2C_MEMADD_SIZE_8BIT, &I2C_Buffer_Read, 1, 100);
	if (I2C_Buffer_Read!=I2C_Buffer_Write){
		while(1);
	}


	I2C_Buffer_Write = R0x37_1;
	HAL_I2C_Mem_Write(&hi2c1, Write_device_address, 0x37, I2C_MEMADD_SIZE_8BIT, &I2C_Buffer_Write, 1, 100);//Right PGA input selection
	HAL_I2C_Mem_Read(&hi2c1, Write_device_address, 0x37, I2C_MEMADD_SIZE_8BIT, &I2C_Buffer_Read, 1, 100);
	if (I2C_Buffer_Read!=I2C_Buffer_Write){
		while(1);
	}


	I2C_Buffer_Write = R0x39_1;
	HAL_I2C_Mem_Write(&hi2c1, Write_device_address, 0x39, I2C_MEMADD_SIZE_8BIT, &I2C_Buffer_Write, 1, 100);//Right PGA input selection 2
	HAL_I2C_Mem_Read(&hi2c1, Write_device_address, 0x39, I2C_MEMADD_SIZE_8BIT, &I2C_Buffer_Read, 1, 100);
	if (I2C_Buffer_Read!=I2C_Buffer_Write){
		while(1);
	}




}


void ADC_start(){


	I2C_Buffer_Write = 0x00;
	HAL_I2C_Mem_Write(&hi2c1, Write_device_address, 0x00, I2C_MEMADD_SIZE_8BIT, &I2C_Buffer_Write, 1, 100); //page 0
	HAL_I2C_Mem_Read(&hi2c1, Write_device_address, 0x00, I2C_MEMADD_SIZE_8BIT, &I2C_Buffer_Read, 1, 100);
	if (I2C_Buffer_Read!=I2C_Buffer_Write){
		while(1);
	}



	I2C_Buffer_Write = R0x51_0;                                               //power on
	HAL_I2C_Mem_Write(&hi2c1, Write_device_address, 0x51, I2C_MEMADD_SIZE_8BIT, &I2C_Buffer_Write, 1, 100);
	HAL_I2C_Mem_Read(&hi2c1, Write_device_address, 0x51, I2C_MEMADD_SIZE_8BIT, &I2C_Buffer_Read, 1, 100);
	if (I2C_Buffer_Read!=I2C_Buffer_Write){
		while(1);
	}



	I2C_Buffer_Write = R0x52_0;
	HAL_I2C_Mem_Write(&hi2c1, Write_device_address, 0x52, I2C_MEMADD_SIZE_8BIT, &I2C_Buffer_Write, 1, 100);
	HAL_I2C_Mem_Read(&hi2c1, Write_device_address, 0x52, I2C_MEMADD_SIZE_8BIT, &I2C_Buffer_Read, 1, 100);
	if (I2C_Buffer_Read!=I2C_Buffer_Write){
		while(1);
	}


//	I2C_Buffer_Write = R0x53_0;
//	HAL_I2C_Mem_Write(&hi2c1, Write_device_address, 0x53, I2C_MEMADD_SIZE_8BIT, &I2C_Buffer_Write, 1, 100);
//
//	I2C_Buffer_Write = R0x54_0;
//	HAL_I2C_Mem_Write(&hi2c1, Write_device_address, 0x54, I2C_MEMADD_SIZE_8BIT, &I2C_Buffer_Write, 1, 100);

//	I2C_Buffer_Write = 0x01;
//	HAL_I2C_Mem_Write(&hi2c1, Write_device_address, 0x00, I2C_MEMADD_SIZE_8BIT, &I2C_Buffer_Write, 8, 100); //page 1
//	HAL_I2C_Mem_Read(&hi2c1, Read_device_address, 0x3B, I2C_MEMADD_SIZE_8BIT, &I2C_Buffer_Read, 8, 100);

}


//
void DMA_ADC(){

	if(HAL_OK != HAL_I2S_Receive_DMA(&hi2s2,(uint16_t *)(PCM_Buffer), AUDIO_IN_CHANNELS*(AUDIO_IN_SAMPLING_FREQUENCY/1000) * 1))
	   {
	     Error_Handler();
	   }

}


void HAL_I2S_RxHalfCpltCallback(I2S_HandleTypeDef *hi2s){
	  uint32_t index;
//	for (int i =0;i<DMAbuffersize/2;i++){
//	Data[UpdatePointer][i] = DMA_buffer[i];
//	}
//	 for (int idx = 0; idx < 96 ;idx ++)
//	  {
//	    (PCM_Buffer)[idx] = Data[96+idx];
//	  }

//	Send_Audio_to_USB((int16_t *)PCM_Buffer,(48000/1000)*2 * 1);

	uint16_t * DataTempI2S = I2S_InternalBuffer;

    for(index=0; index<(AudioInCtx[0].Size/2U); index++)
    {
//        a = ((uint8_t *)(DataTempI2S))[(index*2U)];
//        b = ((uint8_t *)(DataTempI2S))[(index*2U)+1U];
//        ((uint8_t *)(AudioInCtx[0].pBuff))[(index*2U)] = Channel_Demux[a & CHANNEL_DEMUX_MASK] | (Channel_Demux[b & CHANNEL_DEMUX_MASK] << 4);;
//        ((uint8_t *)(AudioInCtx[0].pBuff))[(index*2U)+1U] = Channel_Demux[(a>>1) & CHANNEL_DEMUX_MASK] | (Channel_Demux[(b>>1) & CHANNEL_DEMUX_MASK] << 4);
//    	  b = dummy>>8;
//		  a = dummy & 0xFF;
//		  ((uint8_t *)(AudioInCtx[0].pBuff))[(index*2U)] = Channel_Demux[a & CHANNEL_DEMUX_MASK] | (Channel_Demux[b & CHANNEL_DEMUX_MASK] << 4);;
//		  ((uint8_t *)(AudioInCtx[0].pBuff))[(index*2U)+1U] = Channel_Demux[(a>>1) & CHANNEL_DEMUX_MASK] | (Channel_Demux[(b>>1) & CHANNEL_DEMUX_MASK] << 4);
  	  ((uint8_t *)(AudioInCtx[0].pBuff))[(index*2U)+1U] = ((uint8_t *)(DataTempI2S))[(index*2U)+1U];
  	  ((uint8_t *)(AudioInCtx[0].pBuff))[(index*2U)] = ((uint8_t *)(DataTempI2S))[(index*2U)];
    }

	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_9);
//	USBD_LL_FlushEP(&hUsbDeviceFS, AUDIO_IN_EP);
//	USBD_LL_Transmit(&hUsbDeviceFS, AUDIO_IN_EP,
//			(uint8_t *)Data[UpdatePointer],
//	                   192);

//	UpdatePointer= 1-UpdatePointer;
//	HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_10);

}


void HAL_I2S_RxCpltCallback(I2S_HandleTypeDef *hi2s){
	 uint32_t index;
//	for (int i =0;i<DMAbuffersize/2;i++){
//	Data[UpdatePointer][i] = DMA_buffer[i];
//	}
//	 for (int idx = 0; idx < 96 ;idx ++)
//	  {
//	    (PCM_Buffer)[idx] = Data[idx];
//	  }
//	Send_Audio_to_USB((int16_t *)PCM_Buffer,(48000/1000)*2 * 1);
		uint16_t * DataTempI2S = &(I2S_InternalBuffer[AudioInCtx[0].Size/2U]);
	    uint8_t a,b;
	    for(index=0; index<(AudioInCtx[0].Size/2U); index++)
	    {
	//        a = ((uint8_t *)(DataTempI2S))[(index*2U)];
	//        b = ((uint8_t *)(DataTempI2S))[(index*2U)+1U];
	//        ((uint8_t *)(AudioInCtx[0].pBuff))[(index*2U)] = Channel_Demux[a & CHANNEL_DEMUX_MASK] | (Channel_Demux[b & CHANNEL_DEMUX_MASK] << 4);;
	//        ((uint8_t *)(AudioInCtx[0].pBuff))[(index*2U)+1U] = Channel_Demux[(a>>1) & CHANNEL_DEMUX_MASK] | (Channel_Demux[(b>>1) & CHANNEL_DEMUX_MASK] << 4);
	//    	  b = dummy>>8;
	//		  a = dummy & 0xFF;
	//		  ((uint8_t *)(AudioInCtx[0].pBuff))[(index*2U)] = Channel_Demux[a & CHANNEL_DEMUX_MASK] | (Channel_Demux[b & CHANNEL_DEMUX_MASK] << 4);;
	//		  ((uint8_t *)(AudioInCtx[0].pBuff))[(index*2U)+1U] = Channel_Demux[(a>>1) & CHANNEL_DEMUX_MASK] | (Channel_Demux[(b>>1) & CHANNEL_DEMUX_MASK] << 4);
	  	  ((uint8_t *)(AudioInCtx[0].pBuff))[(index*2U)+1U] = ((uint8_t *)(DataTempI2S))[(index*2U)+1U];
	  	  ((uint8_t *)(AudioInCtx[0].pBuff))[(index*2U)] = ((uint8_t *)(DataTempI2S))[(index*2U)];
	    }

	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_9);
//	USBD_LL_FlushEP(&hUsbDeviceFS, AUDIO_IN_EP);
//	USBD_LL_Transmit(&hUsbDeviceFS, AUDIO_IN_EP,
//			(uint8_t *) Data[UpdatePointer],
//	                   192);

//	UpdatePointer= 1-UpdatePointer;
//	HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_10);
}

