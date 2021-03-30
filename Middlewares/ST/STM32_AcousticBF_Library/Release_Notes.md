---
pagetitle: Release Notes for AcousticBF library
lang: en
header-includes: <link rel="icon" type="image/x-icon" href="_htmresc/favicon.png" />
---

::: {.row}
::: {.col-sm-12 .col-lg-4}

<center>
# Release Notes for <mark>AcousticBF library</mark>
Copyright &copy; 2020 STMicroelectronics\
    
[![ST logo](_htmresc/st_logo_2020.png)](https://www.st.com){.logo}
</center>

# License

This software component is
licensed by ST under **SLA0077**, the "License"; You may not use this component except in compliance
with the License. You may obtain a copy of the License at:
[SLA0077](http://www.st.com/content/st_com/en/search.html#q=SLA0077-t=keywords-page=1)

Some of the library code is based on the CMSIS DSP software library by ARM, a suite of common signal processing functions 
for use on Cortex-M processor based devices and. Licencing terms are available at the end of this document, in the 
AcousticBF application note, in the AcousticBF header file and it's available [here](http://www.keil.com/pack/doc/CMSIS/DSP/html/index.html)

Some of the library code is based on the open Source patent-free SPEEX software, by Jean-Marc Valin/Xiph.Org Foundation,
released under "revised BSD" license. Licensing terms are available in this application note, in the AcousticBF release 
note, in the AcousticBF header file and it's available [here](http://www.xiph.org/licenses/bsd/speex/)

SPEEX revised BSD license note:

© 2002-2003, Jean-Marc Valin/Xiph.Org Foundation.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

- Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
- Redistributions in binary form must reproduce the above copyright  notice, this list of conditions and the following disclaimer in the 
documentation and/or other materials provided with the distribution.
- Neither the name of ARM nor the names of its contributors may be used to endorse or promote products derived from this software 
without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS AND CONTRIBUTORS
 BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 POSSIBILITY OF SUCH DAMAGE.
 
# Purpose

**AcousticBF library** implements a beamforming algorithm, enabling the creation of a virtual directional
microphone using a couple of STMiroelectronics digital MEMS microphones.

AcousticBF allows the user to experience advanced beamforming algorithms whith a minimum effort. A fully
configurable system is provided to perform several kind of beamforming, featuring different degrees of 
directionality and noise rejection.  

**AcousticBF features** :

- Advance beamforming library.
- User selectable algorithm, featuring different level of noise rejection:
  - basic cardioid
  - denoise cardioid
  - ASR ready
  - Strong
- Microphone distances up to 21 mm.
- PDM or PCM input
- Designed for optimal performance in applications using ST’s digital MEMS microphones (such as MP34DT06J).
- Easy portability across different STM32 MCU families thanks to modular architecture and STM32Cube
- Free user-friendly license terms

This Library includes one header file acoustic_bf.h and binary/object codes running on running on STM32 devices
based on CortexM4F and CortexM7F cores. 

Here is the list of references to the user documents:

- [UM2213](https://www.st.com/resource/en/user_manual/dm00391112.pdf): Getting started with AcousticBF, real-time beam forming middleware
- [UM2219](https://www.st.com/resource/en/user_manual/dm00393676.pdf): Getting started with STM32Cube function pack for MEMS microphones
acquisition, advanced audio processing and audio output

:::

::: {.col-sm-12 .col-lg-8}
# Update history

::: {.collapse}
<input type="checkbox" id="collapse-section8" checked aria-hidden="true">
<label for="collapse-section8" aria-hidden="true"> v2.3.0 / 18-Dec-2020 </label>
<div>			

## Main changes
### Product update
- Added support for Cortex M33
- Added hardfp compiled version libraries

## Known limitations
- The provided library supports MCUs based on M33, M4 and M7 cores with FPU unit.

## Development toolchains and compilers
- ARM GCC compiler, softfp and hardfp options
  - With Keil use wc16_softfp version
  - With IAR 8 or STM32CubeIDE use wc32 or wc32_softfp version
  - With IAR 7 use wc16 or wc16_softfp version


</div>
:::

::: {.collapse}
<input type="checkbox" id="collapse-section7" aria-hidden="true">
<label for="collapse-section7" aria-hidden="true"> v2.2.1 / 09-Apr-2020 </label>
<div>			

## Main changes
### Patch release
- Solved MISRA compliancy warning in acoustic_bf.h

## Known limitations
- The provided library supports MCUs based on M4 and M7 cores with FPU unit.

## Development toolchains and compilers
- ARM GCC compiler, softfp options

</div>
:::

::: {.collapse}
<input type="checkbox" id="collapse-section6" aria-hidden="true">
<label for="collapse-section6" aria-hidden="true"> v2.2.0 / 29-Mar-2019 </label>
<div>			

## Main changes
### Maintenance release
- Unification of the librariy to single EABI library per Cortex core and wchar size

## Known limitations
- The provided library supports MCUs based on M4 and M7 cores with FPU unit.

## Development toolchains and compilers
- ARM GCC compiler, softfp options

</div>
:::

::: {.collapse}
<input type="checkbox" id="collapse-section5" aria-hidden="true">
<label for="collapse-section5" aria-hidden="true"> v2.1.1 / 15-Feb-2018 </label>
<div>			

## Main changes
### Maintenance and patch release
- Added support for STM32H7

## Known limitations
- The provided library supports MCUs based on M4 and M7 cores with FPU unit.

## Development toolchains and compilers
- IAR Embedded Workbench for ARM (EWARM) toolchain V8.20 
- RealView Microcontroller Development Kit (MDK-ARM) toolchain V5.24.1
- Ac6 System Workbench for STM32 V2.1.4 

</div>
:::

::: {.collapse}
<input type="checkbox" id="collapse-section4" aria-hidden="true">
<label for="collapse-section4" aria-hidden="true"> v2.0.1 / 12-Jul-2017 </label>
<div>			

## Main changes
### Patch release
- Bugfix
- Added IAR 8.11 support.

## Known limitations
- The provided library supports MCUs based on M4 and M7 cores with FPU unit.
- A compiler warning is generated when using the library in IAR v 7.x. It doesn't affect library performances.

## Development toolchains and compilers
- IAR Embedded Workbench for ARM (EWARM) toolchain V8.11 (backward compatible with IAR 7.x)
- RealView Microcontroller Development Kit (MDK-ARM) toolchain V5.23 
- Ac6 System Workbench for STM32 V2.1.0 

</div>
:::

::: {.collapse}
<input type="checkbox" id="collapse-section3" aria-hidden="true">
<label for="collapse-section3" aria-hidden="true"> v2.0.0 / 08-Mar-2017 </label>
<div>			

## Main changes
### Product update
- First version of the library published under the ODE initiative. Previously released as part of OSX framework.

## Known limitations
- The provided library supports MCUs based on M4 and M7 cores with FPU unit.

## Development toolchains and compilers
- IAR Embedded Workbench for ARM (EWARM) toolchain V7.70 + ST-Link
- RealView Microcontroller Development Kit (MDK-ARM) toolchain V5.23 + ST-LINK
- Ac6 System Workbench for STM32 V1.13.1 + ST-LINK/V2

</div>
:::

::: {.collapse}
<input type="checkbox" id="collapse-section2" aria-hidden="true">
<label for="collapse-section2" aria-hidden="true"> v1.1.0 / 01-Sep-2016 </label>
<div>			

## Main changes
### Maintenance release
- Added volume control when input is in PDM format, allowing to control the amount of gain added to the microphone signals
- Delay to microphone signals can now be applied externally (i.e in Hardware)
- Removed include of the license file from the library header
- PDM clock frequency is now parametric and can be choosen by the user in the initialization phase
- Added support for M7 cores

## Known limitations
- The provided library supports MCUs based on M4 and M7 cores with FPU unit.

## Development toolchains and compilers
- IAR Embedded Workbench for ARM (EWARM) toolchain V7.70 + ST-Link
- RealView Microcontroller Development Kit (MDK-ARM) toolchain V5.20 + ST-LINK
- Ac6 System Workbench for STM32 V1.9.1 + ST-LINK/V2

</div>
:::

::: {.collapse}
<input type="checkbox" id="collapse-section1" aria-hidden="true">
<label for="collapse-section1" aria-hidden="true"> v1.0.0 / 15-Sep-2015 </label>
<div>			

## Main changes
### First release
- First official version of the library.

## Known limitations
- The provided library supports STM32F4xx devices with FPU unit.

## Development toolchains and compilers
- IAR Embedded Workbench for ARM (EWARM) toolchain V7.30 + ST-Link
- RealView Microcontroller Development Kit (MDK-ARM) toolchain V5.12 + ST-LINK
- Ac6 System Workbench for STM32 V1.3.0 + ST-LINK

</div>
:::

:::
:::

<footer class="sticky">
::: {.columns}
::: {.column width="95%"}
For complete documentation on **AcousticBF library** ,
visit: [AcousticBF library](https://www.st.com/en/embedded-software/fp-aud-smartmic1.html)
:::
::: {.column width="5%"}
<abbr title="Based on template cx566953 version 2.0">Info</abbr>
:::
:::
</footer>
