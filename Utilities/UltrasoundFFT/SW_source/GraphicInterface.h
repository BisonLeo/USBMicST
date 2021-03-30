/**
******************************************************************************
* @file    GraphicInterface.h
* @author  SRA
* @version v1.0.0
* @date    17-Jan-2020
* @brief   header file for UltrasoundFFT GraphicInterface
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

#ifndef GRAPHICINTERFACE_H
#define GRAPHICINTERFACE_H

#include <QMainWindow>
#include <QString>
#include <QCheckBox>
#include <QLineEdit>
#include <QTimer>
#include <QDebug>
#include "qcustomplot.h"
#include "HS_DataLog.h"

#define FLOATING_POINT

#ifdef FLOATING_POINT
#define DATASIZE            (4) // datasize in bytes
#else
#define DATASIZE            (2) // datasize in bytes
#endif
#define FFT_LEN             (256)
#define DATALEN             (FFT_LEN * DATASIZE) // DATALEN in bytes
#define PLOTBUFFLEN         (2048 * 10)
#define FFT_BANDWIDTH_HZ    (96000)
#define FFT_BIN_HZ          (FFT_BANDWIDTH_HZ/FFT_LEN)


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    bool USBConnected, logStarted;
    QString * epDescriptors;
    QCheckBox * EP_cB;
    QLineEdit * EP_lE;
    QTimer * isAliveTimer;

    QTimer * plotTimer;
    uint8_t * rawFFTData;
//    uint8_t * plotData;
    QVector<double> plotData;
    uint32_t plotDataCounter;
    uint32_t plotDataInPointer;
    uint32_t plotDataOutPointer;
    QCPItemText *textLabel;
    QCPItemLine *arrow;

    QCPItemLine *fTreshold;
    QCPItemLine *dBTreshold;
    QCPItemRect *backgnd;

    QVector<double> ticks;
    QCPBars *regen;

    QCPColorMap *colorMap;

    int EPn;

    int deviceID = 0;

    QFile logFile;

    int xMaxVisibleValue;

private slots:
    void checkIsAlive(void);

    void toggleConnection(void);
    void toggleStartLog(void);
    void updatePlot(void);
    void resetPlot(void);
    void updateTreshold(void);
    void updateFreqTreshold(void);


};

#endif // GRAPHICINTERFACE_H
