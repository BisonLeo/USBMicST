/**
******************************************************************************
* @file    acquisitionthread.h  
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
  
#ifndef ACQUISITIONTHREAD_H
#define ACQUISITIONTHREAD_H

#include <QWidget>
#include <QMutex>
#include <QSize>
#include <QThread>
#include <QWaitCondition>
#include "libusb.h"
#include <QFile>


class acquisitionthread : public QThread
{
    Q_OBJECT

public:
    acquisitionthread(QObject *parent = 0);
    ~acquisitionthread();
    void startAcquisitionformEP(QString filename, int EPn, libusb_device_handle *dev_handle);
    void stopAcquisitionformEP(void);
    uint32_t readLastAcquiredData(uint8_t * data);


protected:
    void run() override;

private:
    libusb_device_handle *dev_handle;
    QFile * myFile;
    int EPn;
    QString filename;
    QMutex mutex;
    QMutex dataMutex;
    QWaitCondition condition;
    bool restart;
    bool abort;
    unsigned char * data;
    unsigned char * dataOutside;
    bool dataAvailable;
};

#endif // ACQUISITIONTHREAD_H
