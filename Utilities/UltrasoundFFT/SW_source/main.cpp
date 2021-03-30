/**
******************************************************************************
* @file    main.c
* @author  SRA
* @version v1.0.0
* @date    17-Jan-2020
* @brief   Main file for UltrasoundFFT GraphicInterface
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

#include "GraphicInterface.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
