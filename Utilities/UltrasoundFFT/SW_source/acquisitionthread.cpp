/**
******************************************************************************
* @file    acquisitionthread.cpp  
* @author  SRA - Central Labs
* @version v1.0.0
* @date    17-Jan-2020
* @brief   UltrasoundFFT acquisition thread
******************************************************************************
* @attention
*
* Copyright (c) 2020 STMicroelectronics
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or   
* (at your option) any later version.                                 
*                                                                     
* This program is distributed in the hope that it will be useful,     
* but WITHOUT ANY WARRANTY; without even the implied warranty of      
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the       
* GNU General Public License for more details.                        
*                                                                     
* You should have received a copy of the GNU General Public License   
* along with this program.  If not, see http://www.gnu.org/licenses/. 
*
******************************************************************************
*/


#include "acquisitionthread.h"
#include <QtWidgets>
#include <iostream>
#include <stdio.h>

#define USB_PACKET_SIZE 4096
acquisitionthread::acquisitionthread(QObject *parent)
    : QThread(parent)
{
abort = false;
}

acquisitionthread::~acquisitionthread()
{
    mutex.lock();
    abort = true;
    mutex.unlock();
    wait();
}

void acquisitionthread::startAcquisitionformEP(QString filename, int EPn, libusb_device_handle * dev_handle)
{
    QMutexLocker locker(&mutex);

    this->filename = filename;
    this->EPn = EPn;
    this->dev_handle = dev_handle;

    data = new unsigned char[USB_PACKET_SIZE];
    dataOutside = new unsigned char[USB_PACKET_SIZE];

    start(TimeCriticalPriority);
}

void acquisitionthread::stopAcquisitionformEP(void)
{
    mutex.lock();
    abort = true;
    mutex.unlock();
}

uint32_t acquisitionthread::readLastAcquiredData(uint8_t * data)
{
    dataMutex.lock();
    uint32_t ret = 0;
    if(dataAvailable == true)
    {
        memcpy(data, dataOutside, USB_PACKET_SIZE);
        dataAvailable = false;
        ret = USB_PACKET_SIZE;
    }
    else
    {
        dataAvailable = false;
        ret = 0;
    }
    dataMutex.unlock();

    return ret;
}

void acquisitionthread::run()
{
    forever {
        mutex.lock();
        mutex.unlock();

        int r, actual,i= 0;
        r = libusb_bulk_transfer(dev_handle, (this->EPn | LIBUSB_ENDPOINT_IN), data, USB_PACKET_SIZE, &actual, 100);
		
        if(r == 0 )
        {
            i++;
        }
else
        {
           libusb_clear_halt	(dev_handle, (this->EPn | LIBUSB_ENDPOINT_IN));
        }

        dataMutex.lock();
        memcpy(dataOutside,data,USB_PACKET_SIZE);
        dataAvailable = true;
        dataMutex.unlock();

        if (abort)
        {
            delete data;
            return;
        }
    }
}
