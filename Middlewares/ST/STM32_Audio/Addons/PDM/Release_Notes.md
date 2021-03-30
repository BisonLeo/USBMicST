---
pagetitle: Release Notes for PDM library
lang: en
header-includes: <link rel="icon" type="image/x-icon" href="_htmresc/favicon.png" />
---

::: {.row}
::: {.col-sm-12 .col-lg-4}

<center>
# Release Notes for <mark>PDM library</mark>
Copyright &copy; 2020 STMicroelectronics\
    
[![ST logo](_htmresc/st_logo_2020.png)](https://www.st.com){.logo}
</center>

# License

This software component is
licensed by ST under **MCD-ST Image SW License Agreement V2**, the "License"; You may not use this component except in compliance
with the License. You may obtain a copy of the License at:
[MCD-ST Image SW License Agreement V2](http://www.st.com/software_license_agreement_image_v2)
 
# Purpose

The **PDM library** has the function to decimate and filter out a Pulse Density Modulated (PDM) stream from a digital microphone,
in order to convert it to a Pulse Code Modulated (PCM) signal output stream. 

The PCM output stream is implemented at a sampling rate of 16kHz with a 16 bits resolution. Various decimation factors can be 
configured, in order to adapt to various PDM clocks.
Digital microphone gain is configurable at any time and allows 1dB step in the range of -12dB to +51dB.

Here is the list of references to the user documents:

- [UM2372](https://www.st.com/resource/en/user_manual/dm00482421.pdf): STM32Cube PDM2PCM software library for the STM32F4/F7/H7 Series
- [DB2599](https://www.st.com/resource/en/data_brief/x-cube-memsmic1.pdf): Analog and digital MEMS microphone acquisition and processing software
expansion for STM32Cube

:::

::: {.col-sm-12 .col-lg-8}
# Update history

::: {.collapse}
<input type="checkbox" id="collapse-section5" checked aria-hidden="true">
<label for="collapse-section5" aria-hidden="true"> V3.2.0MOD / 18-December-2020 </label>
<div>			

## Main changes
### Product update
- CRC bug fixed for STM32H7
- Removed support for Cortex M3
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
<input type="checkbox" id="collapse-section4" aria-hidden="true">
<label for="collapse-section4" aria-hidden="true"> V3.2.0 / 06-November-2019 </label>
<div>			

## Main changes
### Maintenance release
- Add new PDM Filter libraries compliant with GCC version with FPU = softfp
  - libPDMFilter_CM4_GCC_wc32_softfp.a for GCC with wchar = 4
  - libPDMFilter_CM7_GCC_wc32_softfp.a for GCC with wchar = 4
  - libPDMFilter_CM4_GCC_wc16_softfp.a for GCC with wchar = 2 
  - libPDMFilter_CM7_GCC_wc16_softfp.a for GCC with wchar = 2
- Add new PDM Filter libraries compliant with GCC version with wchar = 2
  - libPDMFilter_CM3_GCC_wc16.a
  - libPDMFilter_CM4_GCC_wc16.a
  - libPDMFilter_CM7_GCC_wc16.a
- This PDM Filter libraries cortexM3 version is not backward compatible with previous V3.1.0 and earlier version,
below the list of complete changes requiring updates on User applications:
  - For cortexM3 (CM3):
    - libPDMFilter_CM3_IAR.a updated and renamed to:
      - libPDMFilter_CM3_IAR_wc32.a for EWARM V8.x and later versions
      - libPDMFilter_CM3_IAR_wc16.a for EWARM V7.80.x and earlier versions
    - libPDMFilter_CM3_Keil.lib updated and renamed to libPDMFilter_CM3_Keil_wc16.lib
    - libPDMFilter_CM3_GCC.a updated and renamed to libPDMFilter_CM3_GCC_wc32.a

</div>
:::

::: {.collapse}
<input type="checkbox" id="collapse-section3" aria-hidden="true">
<label for="collapse-section3" aria-hidden="true"> V3.1.0 / 29-September-2018 </label>
<div>			

## Main changes
### Product update
- Update PDM Filter libraries for CortexM7 (CM7) and cortexM4 (CM4) core versions.

## Known limitations
- This version is not backward compatible with previous V3.0.1 and earlier version, below the list of complete changes requiring updates on User applications:
  - For cortexM4 (CM4):
    - libPDMFilter_CM4_IAR.a updated and renamed to:
      - libPDMFilter_CM4_IAR_wc32.a for EWARM V8.x and later versions
      - libPDMFilter_CM4_IAR_wc16.a for EWARM V7.80.x and earlier versions
    - libPDMFilter_CM4_Keil.lib updated and renamed to libPDMFilter_CM4_Keil_wc16.lib
    - libPDMFilter_CM4_GCC.a updated and renamed to libPDMFilter_CM4_GCC_wc32.a
  - For cortexM7 (CM7):
    - libPDMFilter_CM7_IAR.a updated and renamed to:
      - libPDMFilter_CM7_IAR_wc32.a for EWARM V8.x and later versions
      - libPDMFilter_CM7_IAR_wc16.a for EWARM V7.80.x and earlier versions
    - libPDMFilter_CM7_Keil.lib updated and renamed to libPDMFilter_CM7_Keil_wc16.lib
    - libPDMFilter_CM7_GCC.a updated and renamed to libPDMFilter_CM7_GCC_wc32.
     
- New CM7 libs support both CortexM7 core versions for STM32F7 and STM32H7 series

</div>
:::

::: {.collapse}
<input type="checkbox" id="collapse-section2" aria-hidden="true">
<label for="collapse-section2" aria-hidden="true"> V3.0.1 / 29-December-2017 </label>
<div>			

## Main changes
### Patch release
- Update libPDMFilter_CM7_Keil.lib to support  CortexM7 (CM7) core version available on STM32F7 family.

## Known limitations
- The new libPDMFilter_CM7_Keil.lib supports only CortexM7 core version available on STM32F7 family. 
New version for libPDMFilter_CM7_Keil.lib supporting both CortexM7 core versions (STM32F7 and STM32H7) will be available for next release.
The libPDMFilter_CM7_Keil.lib compatible with CortexM7 core version available on STM32H7 family is available on PDM Lib version V3.0.0

</div>
:::

::: {.collapse}
<input type="checkbox" id="collapse-section1" aria-hidden="true">
<label for="collapse-section1" aria-hidden="true"> V3.0.0 / 28-February-2017 </label>
<div>			

## Main changes
### Product update
- Major APIs change
- Only one filtering function is provided PDM_Filter()
- The decimation factor, endianness, and bit order are now configured once at the PDM_Filter_Init() function call
- Decimation factor, demodulation loop size and digital gain can be changed on-the-fly using PDM_Filter_setConfig() function

## Known limitations
This version is not backward compatible with previous V2.1.0 and earlier version, below guidelines on how to use the new APIs

Library initialization

Once the memory is allocated, some routines must be called to initialize the PDM2PCM library static memory:

- PDM_Filter_Init() routine should be called each time the processing in the audio is stopped and started.
- PDM_Filter_setConfig() routine should be called at least once before processing start in order to set configurable parameter

Furthermore, has the PDM2PCM library runs on STM32 devices, CRC HW block must be enabled and reset.

Module execution

The run time process can start, when the hardware is configured and the PDM2PCM library is initialized and configured. At each new interrupt, when enough bits have been buffered, the PDM2PCM filter routine PDM_Filter() can be called. Between two consecutive calls to this filter routine, the dynamic parameters can be changed. 

</div>
:::

:::
:::

<footer class="sticky">
::: {.columns}
::: {.column width="95%"}
For complete documentation on **PDM library** ,
visit: [PDM library](https://www.st.com/en/embedded-software/x-cube-memsmic1.html)
:::
::: {.column width="5%"}
<abbr title="Based on template cx566953 version 2.0">Info</abbr>
:::
:::
</footer>
