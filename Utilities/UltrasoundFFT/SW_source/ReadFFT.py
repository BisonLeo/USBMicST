
# Copyright (c) 2020 STMicroelectronics. All rights reserved.
#
# The STMicroelectronics corporate logo is a trademark of STMicroelectronics
#                      
# Redistribution and use in source and binary forms, with or without modification,
# are permitted provided that the following conditions are met:
#          
# - Redistributions of source code must retain the above copyright notice, this 
# list of conditions and the following disclaimer.
# - Redistributions in binary form must reproduce the above copyright notice, 
# this list of conditions and the following disclaimer in the documentation and/or
# other materials provided with the distribution.
# - Neither the name nor trademarks of STMicroelectronics International N.V. nor 
# any other STMicroelectronics company nor the names of its contributors may be 
# used to endorse or promote products derived from this software without specific 
# prior written permission.
#                         
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND 
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
# IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
# INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
# BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
# LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE 
# OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED 
# OF THE POSSIBILITY OF SUCH DAMAGE.


import numpy as np
import matplotlib.pyplot as plt
from glob import glob
        
plt.ion()   
choice = 0     

while choice != 'q':
    fpath = ''
    files = glob('./Acquisitions/*.dat')
    for idx, fpath in enumerate(files):
        print(idx,'-', fpath)
    print('q - Quit')    
    choice = input('Select the file ==> ')
    if choice != 'q':
        fpath = files[int(choice)]
        print('\n',fpath,'\n')
        with open(fpath, 'rb') as fid:
            rawData = np.fromfile(fid,dtype='float32')
            fid.close()
             
        rawData = rawData / 256   
        rawData = 20 * np.log10(rawData)
        Data = np.reshape(rawData,(-1,256))
        lengthData = np.shape(Data)
        lengthrawData = np.shape(rawData)
        timeAxes = np.linspace(0,lengthData[0],lengthData[0])
        fftAxes = np.linspace(0,lengthData[1],lengthData[1])
        fftAxes = fftAxes * 375
        timeAxes = timeAxes / (2 * 375)
		
        Data = Data.transpose()
        
        cf = plt.pcolormesh(timeAxes, fftAxes, Data,cmap = 'jet') 
        plt.colorbar(cf)
        plt.xlabel('sec')
        plt.ylabel('Hz')
        plt.show()
		
