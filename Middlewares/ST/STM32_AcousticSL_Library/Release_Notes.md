---
pagetitle: Release Notes for AcousticSL library
lang: en
header-includes: <link rel="icon" type="image/x-icon" href="_htmresc/favicon.png" />
---

::: {.row}
::: {.col-sm-12 .col-lg-4}

<center>
# Release Notes for <mark>AcousticSL library</mark>
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
AcousticSL application note, in the AcousticSL header file and it's available [here](http://www.keil.com/pack/doc/CMSIS/DSP/html/index.html)
 
# Purpose

The **AcousticSL Sound Source Localization** software library is an optimized software implementation for Sound Source Localization.

Acoustic SL library implements an optimized software implementation for Sound Source Localization.

Acoustic SL allows the user to experience advanced Sound Source Localization algorithms whith a minimum effort. 

**AcousticSL features** :

- Advance Sound Source Localization algorithm.
- based on three different algoritms:
  - Cross Correlation
  - GCC-PHAT
  - BMPH
- 16 KHz PCM input
- Designed for optimal performance in applications using ST’s digital MEMS microphones (such as MP34DT06J).
- Easy portability across different STM32 MCU families thanks to modular architecture and STM32Cube
- Free user-friendly license terms

Here is the list of references to the user documents:

- [UM2212](https://www.st.com/resource/en/user_manual/dm00390468.pdf): Getting started with AcousticSL, real-time sound source localization middleware
- [UM2219](https://www.st.com/resource/en/user_manual/dm00393676.pdf): Getting started with STM32Cube function pack for MEMS microphones
acquisition, advanced audio processing and audio output

:::

::: {.col-sm-12 .col-lg-8}
# Update history

::: {.collapse}
<input type="checkbox" id="collapse-section7" checked aria-hidden="true">
<label for="collapse-section7" aria-hidden="true"> v2.3.0 / 18-Dec-2020 </label>
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
- Added new DOA estimation algorithm (BMPH)
- Removed include of the license file from the library header
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
For complete documentation on **AcousticSL library** ,
visit: [AcousticSL library](https://www.st.com/en/embedded-software/fp-aud-smartmic1.html)
:::
::: {.column width="5%"}
<abbr title="Based on template cx566953 version 2.0">Info</abbr>
:::
:::
</footer>
