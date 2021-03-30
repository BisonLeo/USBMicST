
% Copyright (c) 2020 STMicroelectronics. All rights reserved.
%
% The STMicroelectronics corporate logo is a trademark of STMicroelectronics
%                         
% Redistribution and use in source and binary forms, with or without modification,
% are permitted provided that the following conditions are met:
%          
% - Redistributions of source code must retain the above copyright notice, this 
% list of conditions and the following disclaimer.
% - Redistributions in binary form must reproduce the above copyright notice, 
% this list of conditions and the following disclaimer in the documentation and/or
% other materials provided with the distribution.
% - Neither the name nor trademarks of STMicroelectronics International N.V. nor 
% any other STMicroelectronics company nor the names of its contributors may be 
% used to endorse or promote products derived from this software without specific 
% prior written permission.
%                         
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND 
% ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
% WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
% IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
% INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
% BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
% DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
% LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE 
% OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED 
% OF THE POSSIBILITY OF SUCH DAMAGE.



fclose all;
clear all;
close all;
clc;

[fJ,fpath] = uigetfile('.\Acquisitions\*.dat');
if iscell(fJ)
    fJs = strings(1, length(fJ));
    for ii = 1:length(fJ)
        fJs(ii) = cell2mat(fJ(ii));
    end
else
    fJs = strings(1, 1);
    fJs(1) = fJ;
end

for ii = 1:length(fJs)
    audioFile = fJs(ii);
    audioFile = strcat(fpath, audioFile);
    
    fid = fopen(audioFile);
    rawData = fread(fid,inf, 'single');
    fclose(fid);
    
    rawData = rawData / 256;
    rawData = 20 * log10(rawData);
    Data = reshape(rawData,256,[]);
    lengthData = size(Data);
    lengthrawData = size(rawData);
    timeAxes = linspace(0,lengthData(2),lengthData(2));
    fftAxes = linspace(0,lengthData(1),lengthData(1));
    fftAxes = fftAxes * 375;
    timeAxes = timeAxes / (2 * 375);
    
    mesh(timeAxes, fftAxes, Data);
    view(2)
    colorbar
    xlabel('sec')
    ylabel('Hz')
    
end
