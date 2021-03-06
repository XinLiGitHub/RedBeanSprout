[RedBeanSprout](https://github.com/KitSprout/RedBeanSprout)
========
* Author  : [Hom](https://github.com/Hom-Wang)
* Version : v2.2
* Update  : 2016/01/09

Description
========
RedBeanSprout 是一個 STM32F103C / STM32F303C 的開發板，有 CortexM3 與 CortexM4 兩種版本，皆工作於 72 MHz 時脈下，體積小、成本低、可以直接插在麵包板上，有外加 LDO，可以使用 5V 或 3V3 供電。

 > 預計結合 [STM32duino](https://github.com/rogerclarkmelbourne/Arduino_STM32) 實現在 arduino IDE 上開發和燒錄。

License
========
* 硬體(Hardware)採用 [CC BY-SA 4.0](http://creativecommons.org/licenses/by-sa/4.0/deed.zh_TW) 方式授權 
  
　　<a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/deed.zh_TW"><img alt="創用 CC 授權條款" style="border-width:0" src="http://i.creativecommons.org/l/by-sa/3.0/tw/80x15.png" /></a>  
　　<span xmlns:dct="http://purl.org/dc/terms/" property="dct:title"> RedBeanSprout v2.2 </span>由<a xmlns:cc="http://creativecommons.org/ns#" href="https://github.com/KitSprout" property="cc:attributionName" rel="cc:attributionURL"> KitSprout </a>製作，以<a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/deed.zh_TW"> 創用CC 姓名標示-相同方式分享 4.0 國際 授權條款 </a>釋出。  


* 軟體(Software)採用 [MIT License](http://opensource.org/licenses/MIT) 方式授權  

Hardware
========
* 控制器　 : [STM32F103C](http://www.st.com/web/catalog/mmc/FM141/SC1169/SS1031/LN1565/PF189782) / [STM32F303C](http://www.st.com/web/catalog/mmc/FM141/SC1169/SS1576/LN1531/PF253449) 48Pin 72MHz
* PCB 尺寸 : 15.24 * 43.18mm
* 設計軟體 [Altium Designer 15](http://www.altium.com/en/products/altium-designer) ( PcbLib use AD [PcbLib v1.2](https://github.com/KitSprout/AltiumDesigner_PcbLibrary/releases/tag/v1.2) )  
  
相關的應用  
MicroMultimeter：https://github.com/KitSprout/MicroMultimeter  
ReflowOven：https://github.com/KitSprout/ReflowOven  

Software
========
RedBeanSprout CortexM3 版本  
Use HAL Library  
* [BSR_testHardware](https://github.com/KitSprout/RedBeanSprout/tree/master/Software/BSR_testHardware) ... 開發板硬體測試
* [BSR_PeripheralHAL_ADC](https://github.com/KitSprout/RedBeanSprout/tree/master/Software/BSR_PeripheralHAL_ADC) ... ADC 讀取範例
* [BSR_PeripheralHAL_CRC](https://github.com/KitSprout/RedBeanSprout/tree/master/Software/BSR_PeripheralHAL_CRC) ... CRC 驗證碼範例
* [BSR_PeripheralHAL_EXIT](https://github.com/KitSprout/RedBeanSprout/tree/master/Software/BSR_PeripheralHAL_EXIT) ... EXIT 中斷範例
* [BSR_PeripheralHAL_FLASH](https://github.com/KitSprout/RedBeanSprout/tree/master/Software/BSR_PeripheralHAL_FLASH) ... FLASH 讀寫範例
* [BSR_PeripheralHAL_GPIO](https://github.com/KitSprout/RedBeanSprout/tree/master/Software/BSR_PeripheralHAL_GPIO) ... GPIO 輸入輸出範例
* [BSR_PeripheralHAL_PWR](https://github.com/KitSprout/RedBeanSprout/tree/master/Software/BSR_PeripheralHAL_PWR) ... 低功耗模式範例
* [BSR_PeripheralHAL_TIM](https://github.com/KitSprout/RedBeanSprout/tree/master/Software/BSR_PeripheralHAL_TIM) ... TIM Base 計時中斷範例
* [BSR_PeripheralHAL_TIM-InputCap](https://github.com/KitSprout/RedBeanSprout/tree/master/Software/BSR_PeripheralHAL_TIM-InputCap) ... TIM 輸入捕捉範例
* [BSR_PeripheralHAL_TIM-PWM](https://github.com/KitSprout/RedBeanSprout/tree/master/Software/BSR_PeripheralHAL_TIM-PWM) ... TIM PWM 輸出範例
* [BSR_PeripheralHAL_UART](https://github.com/KitSprout/RedBeanSprout/tree/master/Software/BSR_PeripheralHAL_UART) ... UART 傳輸範例
* [BSR_PeripheralHAL_UART-IntRecv](https://github.com/KitSprout/RedBeanSprout/tree/master/Software/BSR_PeripheralHAL_UART-IntRecv) ... UART 中斷接收範例
* [BSR_ModuleHAL_DAC-DAC128S085](https://github.com/KitSprout/RedBeanSprout/tree/master/Software/BSR_ModuleHAL_DAC128S085) ... DAC128S085 範例
* [BSR_ModuleHAL_MPU6050-SimuI2C](https://github.com/KitSprout/RedBeanSprout/tree/master/Software/BSR_ModuleHAL_MPU6050-SimuI2C) ... MPU6050 SimuI2C 讀取範例
* [BSR_ModuleHAL_MPU6500-SPI](https://github.com/KitSprout/RedBeanSprout/tree/master/Software/BSR_ModuleHAL_MPU6500-SPI) ... MPU6500-SPI 範例
* [BSR_ModuleHAL_MPU9250-SPI](https://github.com/KitSprout/RedBeanSprout/tree/master/Software/BSR_ModuleHAL_MPU9250-SPI) ... MPU9250-SPI 範例
* [BSR_FreeRTOS_Peripheral_GPIO](https://github.com/KitSprout/RedBeanSprout/tree/master/Software/BSR_FreeRTOS_Peripheral_GPIO) ... FreeRTOS 範例
  
RedBeanSprout CortexM4 版本  
* [BSR_M4_PeripheralHAL_GPIO](https://github.com/KitSprout/RedBeanSprout/tree/master/SoftwareM4/BSR4_PeripheralHAL_GPIO) ... GPIO 輸入輸出範例

Related Documents
========
* [Google Drive](http://goo.gl/fQwBCc)

View
========
<img src="https://lh6.googleusercontent.com/-J5awKviGcxs/VRBtkeZY8uI/AAAAAAAAL_M/XQagI8r_zH4/s1200/DSC_2731.jpg" />

Config
========
<img src="https://lh3.googleusercontent.com/-dYO0WGnJa1w/VQ5zEcizwII/AAAAAAAAL9o/bA5z3fE46Jw/s1600/Config_v2.2.png" />

Schematic
========
<img src="https://lh5.googleusercontent.com/-m0ccQtZ--AM/VQcaIvHzk0I/AAAAAAAAL10/y6l9HnhyKic/s1600/Sch_RedBeanSprout_v2.2.png" />

