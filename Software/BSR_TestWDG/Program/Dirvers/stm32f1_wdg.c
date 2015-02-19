/*=====================================================================================================*/
/*=====================================================================================================*/
#include "stm32f1_system.h"
#include "stm32f1_wdg.h"
/*=====================================================================================================*/
/*=====================================================================================================*
**函數 : IWDG_Config
**功能 : 獨立看門狗初始化
**輸入 : Prescaler, Reload
**輸出 : None
**使用 : IWDG_Config(IWDG_Prescaler_32, 625);   // TimeOut = 500ms
**=====================================================================================================*/
/*=====================================================================================================*/
void IWDG_Config( uint8_t Prescaler, uint16_t Reload )
{
  // IWDG_Clock = LSI / Prescaler = 40KHz / Prescaler
  // Reload = TimeOut / IWDG_Clock = TimeOut * LSI / Prescaler

  IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
  IWDG_SetPrescaler(Prescaler);
  IWDG_SetReload(Reload);
  IWDG_FeedDog();

  IWDG_Enable();
}
/*=====================================================================================================*/
/*=====================================================================================================*
**函數 : IWDG_FeedDog
**功能 : 餵食獨立看門狗
**輸入 : None
**輸出 : None
**使用 : IWDG_FeedDog();
**=====================================================================================================*/
/*=====================================================================================================*/
void IWDG_FeedDog( void )
{	
  IWDG->KR = 0xAAAA;
}
/*=====================================================================================================*/
/*=====================================================================================================*
**函數 : WWDG_Config
**功能 : 視窗看門狗初始化
**輸入 : Prescaler, WindowValue, CounterValue
**輸出 : None
**使用 : WWDG_Config(WWDG_Prescaler_8, 100);   // 24.57ms < FeedDog < 58.25ms
**=====================================================================================================*/
/*=====================================================================================================*/
void WWDG_Config( uint32_t Prescaler, uint8_t WindowValue )
{
  // WWDG_Clock = (PCLK1/4096)/Prescaler = (36MHz/4096)/Prescaler
  // 1098.6328125Hz
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_WWDG, ENABLE);
  WWDG_SetPrescaler(Prescaler);
  WWDG_SetWindowValue(WindowValue);   // 0x3F(63) < !TimeOut < WindowValue
  WWDG_Enable(0x7F);
}
/*=====================================================================================================*/
/*=====================================================================================================*
**函數 : WWDG_FeedDog
**功能 : 餵食視窗看門狗
**輸入 : None
**輸出 : None
**使用 : WWDG_FeedDog(0x7F);
**=====================================================================================================*/
/*=====================================================================================================*/
void WWDG_FeedDog( uint8_t CounterValue )
{
  WWDG->CR |= CounterValue & 0x7F;  // 遞減計數器, 0xCF = 127 = 0111_1111
}
/*=====================================================================================================*/
/*=====================================================================================================*/
