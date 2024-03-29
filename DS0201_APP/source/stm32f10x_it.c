/******************** (C) COPYRIGHT 2009 e-Design Co.,Ltd. *********************
* File Name: stm32f10x_it.c  Author: bure   Hardware: DS0201V1.1   Version: V1.0
*******************************************************************************/
#include "stm32f10x_it.h"
#include "usb_lib.h"
#include "usb_istr.h"
#include "lcd.h"
#include "HW_V1_Config.h"
#include "Function.h"

void            NMIException(void)
{
}

void            HardFaultException(void)
{
   while (1)
   {
   }
}

void            MemManageException(void)
{
   while (1)
   {
   }
}

void            BusFaultException(void)
{
   while (1)
   {
   }
}
void            UsageFaultException(void)
{
   while (1)
   {
   }
}

void            DebugMonitor(void)
{
}

void            SVCHandler(void)
{
}

void            PendSVC(void)
{
}

void            SysTickHandler(void)
{
}

void            WWDG_IRQHandler(void)
{
}

void            PVD_IRQHandler(void)
{
}

void            TAMPER_IRQHandler(void)
{
}

void            RTC_IRQHandler(void)
{
}

void            FLASH_IRQHandler(void)
{
}

void            RCC_IRQHandler(void)
{
}

void            EXTI0_IRQHandler(void)
{
}

void            EXTI1_IRQHandler(void)
{
}

void            EXTI2_IRQHandler(void)
{
}

void            EXTI3_IRQHandler(void)
{
}

void            EXTI4_IRQHandler(void)
{
}

void            DMAChannel1_IRQHandler(void)
{
}

void            DMAChannel2_IRQHandler(void)
{
}

void            DMAChannel3_IRQHandler(void)
{
}

void            DMAChannel4_IRQHandler(void)
{
}

void            DMAChannel5_IRQHandler(void)
{
}

void            DMAChannel6_IRQHandler(void)
{
}

void            DMAChannel7_IRQHandler(void)
{
}

void            ADC_IRQHandler(void)
{
}

void            USB_HP_CAN_TX_IRQHandler(void)
{
   CTR_HP();
}

void            USB_LP_CAN_RX0_IRQHandler(void)
{
   USB_Istr();
}

void            CAN_RX1_IRQHandler(void)
{
}

void            CAN_SCE_IRQHandler(void)
{
}

void            EXTI9_5_IRQHandler(void)
{
}

void            TIM1_BRK_IRQHandler(void)
{
}

void            TIM1_UP_IRQHandler(void)
{
}

void            TIM1_TRG_COM_IRQHandler(void)
{
}

void            TIM1_CC_IRQHandler(void)
{
}

void            TIM2_IRQHandler(void)
{
}

void            TIM3_IRQHandler(void)
{
   unsigned char   KeyCode;

   TIM3_SR = 0;
   if (Delay_Counter)
      Delay_Counter--;
   if (Counter_20mS > 0)
      Counter_20mS--;
   else
   { // read key per 20mS

      Cursor_Counter++;
      if (Cursor_Counter > 24)
      { // 25*20mS=500mS

         Cursor_Counter = 0;
         Update[Item] = 1;
         Type = 1 - Type;
      }
      Counter_20mS = 20;
      if (Key_Wait_Counter)
         Key_Wait_Counter--;
      if (Key_Repeat_Counter)
         Key_Repeat_Counter--;
      KeyCode = KeyScan();
      if (KeyCode != 0)
         Key_Buffer = KeyCode;
   }
}

void            TIM4_IRQHandler(void)
{
}

void            I2C1_EV_IRQHandler(void)
{
}

void            I2C1_ER_IRQHandler(void)
{
}

void            I2C2_EV_IRQHandler(void)
{
}

void            I2C2_ER_IRQHandler(void)
{
}

void            SPI1_IRQHandler(void)
{
}

void            SPI2_IRQHandler(void)
{
}

void            USART1_IRQHandler(void)
{
}

void            USART2_IRQHandler(void)
{
}

void            USART3_IRQHandler(void)
{
}

void            EXTI15_10_IRQHandler(void)
{
}

void            RTCAlarm_IRQHandler(void)
{
}

void            USBWakeUp_IRQHandler(void)
{
}
/********************************* END OF FILE ********************************/
