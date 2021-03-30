/**
  @page UltrasoundFFT application for STWIN
  
  @verbatim
  ******************************************************************************
  * @file    readme.txt  
  * @author  SRA
  * @version v1.1.0
  * @date    18-Dec-2020
  * @brief   This application contains an example which shows how to calculate
  *			 and stream FFT values from onboard analog mic to a PC GUI
  ******************************************************************************
  *
  * Copyright (c) 2020 STMicroelectronics. All rights reserved.
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0055, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                               www.st.com/SLA0055
  *
  ******************************************************************************
  @endverbatim

@par Application Description 

The UltrasoundFFT shows how to calculate and stream FFT values from the onboard 
analog mic sampled at 192KHz to a PC GUI, available in 'Utilities/UltrasoundFFT'.
Thanks to the very high sampling frequency available, the application can be used
to make condition analysis in the ultrasound frequency domain on any kind of machinery.

Once the example starts, the board is in idle state, waiting for a 'start'
command from the PC.
'UltrasoundFFT' PC GUI handle this commands: user can start the PC application and
click on the 'Start' button available on the GUI.

When the command is sent from the PC to the STWIN board through USB, it starts
calculating and streaming the audio FFT.
The Audio Power Spectrum Density is plotted into the GUI and the user can select a 
threshold in energy and frequency to find out the maximum energetic bin in the 
ultrasound frequency range.

Through the GUI it is also possible to store the FFT values into a raw data file,
simply checking the flag 'Save to file'. 
Files are saved in the folder 'Acquisition'; file name is 'data_HHMMSS.dat'

The folder 'Utilities/UltrasoundFFT' contains also a Matlab and a Python scripts called
'ReadFFT' to plot the spectrogram of the data saved into the 'Acquisition' folder.
'ReadFFT.py' was tested using Python 3.7 on Linux and Windows 10 (Anaconda environment).
'ReadFFT.m' was tested using MATLABv2019a.


@par Hardware and Software environment

  - This application runs on X-NUCLEO-AMICAM1 on top of a NUCLEO-L476RG.
  - STM32 Virtual COM Port Driver for Windows can be downloaded from st.com - STSW-STM32102
    
@par How to use it? 

This package contains projects for 3 IDEs viz. IAR, µVision and STM32CubeIDE. In order to make
the program work, you must do the following:
 - WARNING: before opening the project with any toolchain be sure your folder
   installation path is not too in-depth since the toolchain may report errors
   after building.

For IAR:
 - Open IAR toolchain (this firmware has been successfully tested with
   Embedded Workbench V8.32.3).
 - Open the IAR project file EWARM\Project.eww
 - Rebuild all files and load your image into target memory.
 - Run the example.

For µVision:
 - Open µVision 5 toolchain (this firmware has been successfully tested with MDK-ARM Professional 
   Version: 5.29).
 - Open the µVision project file MDK-ARM\Project.uvprojx
 - Rebuild all files and load your image into target memory.
 - Run the example.

For STM32CubeIDE:
 - Open STM32CubeIDE (this firmware has been successfully tested with STM32CubeIDE v1.3.0).
 - Set the default workspace proposed by the IDE (please be sure that there are not spaces in the
   workspace path).
 - Press "File" -> "Import" -> "Existing Projects into Workspace"; press "Browse" in the "Select 
   root directory" and choose the path where the project is located
 - Rebuild all files and load your image into target memory.
 - Run the example.


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
