/*******************************************************************************
 File Name : main.c                    Author : MCD Application Team & bure
*******************************************************************************/

#include "stm32f10x_lib.h"
#include "usb_lib.h"
#include "usb_conf.h"
#include "usb_prop.h"
#include "usb_pwr.h"
#include "hw_config.h"

typedef void    (*pFunction) (void);

u8              DeviceState;
u8              DeviceStatus[6];
pFunction       Jump_To_Application;
u32             JumpAddress;

#include "stdio.h"

int             main(void)
{
#ifdef DEBUG
   debug();
#endif

   Set_System();
   GPIO_Config();

   if (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_9) > 0)
   {
      if (((*(vu32 *) 0x8004000) & 0x2FFF0000) == 0x20000000)
      {
         JumpAddress = *(vu32 *) (ApplicationAddress + 4);
         Jump_To_Application = (pFunction) JumpAddress;
         __MSR_MSP(*(vu32 *) ApplicationAddress);
         Jump_To_Application();
      }
   }
   DeviceState = STATE_dfuERROR;
   DeviceStatus[0] = STATUS_ERRFIRMWARE;
   DeviceStatus[4] = DeviceState;

   LCD_Initial();
   Clear_Screen(0);
   Display_Logo(30, 150);
   Display_Str(8, 87, 0x07E0, 0, "      Please Connect to USB Host!");
   Display_Str(8, 23, 0x07FF, 1, "DS0201 Device Firmware Upgrade Ver 1.0");

   USB_Init();

   Display_Str(8, 87, 0x07E0, 0, "         Firmware Upgrading...  ");
   Display_Str(8, 55, 0x07E0, 0, "             Please Wait");
   Display_Str(8, 23, 0x07FF, 1, "DS0201 Device Firmware Upgrade Ver 1.0");

   while (1)
   {
   }
}

/********************************* END OF FILE ********************************/
