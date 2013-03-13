/******************** (C) COPYRIGHT 2007 STMicroelectronics ********************
* File Name          : usb_prop.c
* Author             : MCD Application Team
* Version            : V1.0
* Date               : 10/08/2007
* Description        : All processings related to DFU demo
********************************************************************************
* THE PRESENT SOFTWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH SOFTWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/*
 * Includes ------------------------------------------------------------------
 */
#include "spi_flash.h"
#include "usb_lib.h"
#include "hw_config.h"
#include "usb_conf.h"
#include "usb_prop.h"
#include "usb_desc.h"
#include "usb_pwr.h"

/*
 * Private typedef -----------------------------------------------------------
 */
/*
 * Private define ------------------------------------------------------------
 */
/*
 * Private macro -------------------------------------------------------------
 */
/*
 * Private variables ---------------------------------------------------------
 */
u8              Load_Buffer[wTransferSize]; /*

                                             * 
                                             * * RAM Buffer for Downloaded
                                             * Data  
                                             */
u32             wBlockNum = 0, wlength = 0;
u32             Manifest_State = Manifest_complete;
u32             Pointer = ApplicationAddress; /*

                                               * 
                                               * * Base Address to Erase, *
                                               * Program or Read  
                                               */

DEVICE          Device_Table =
{
   EP_NUM,
   1
};

DEVICE_PROP     Device_Property =
{
   DFU_init,
   DFU_Reset,
   DFU_Status_In,
   DFU_Status_Out,
   DFU_Data_Setup,
   DFU_NoData_Setup,
   DFU_Get_Interface_Setting,
   DFU_GetDeviceDescriptor,
   DFU_GetConfigDescriptor,
   DFU_GetStringDescriptor,
   0,                           /*
                                 * DFU_EP0Buffer
                                 */
   bMaxPacketSize0              /*
                                 * Max Packet size
                                 */
};

USER_STANDARD_REQUESTS User_Standard_Requests =
{
   DFU_GetConfiguration,
   DFU_SetConfiguration,
   DFU_GetInterface,
   DFU_SetInterface,
   DFU_GetStatus,
   DFU_ClearFeature,
   DFU_SetEndPointFeature,
   DFU_SetDeviceFeature,
   DFU_SetDeviceAddress
};

ONE_DESCRIPTOR  Device_Descriptor =
{
   (u8 *) DFU_DeviceDescriptor,
   DFU_SIZ_DEVICE_DESC
};

ONE_DESCRIPTOR  Config_Descriptor =
{
   (u8 *) DFU_ConfigDescriptor,
   DFU_SIZ_CONFIG_DESC
};

ONE_DESCRIPTOR  DFU_String_Descriptor[6] =
{
   {(u8 *) DFU_StringLangId, DFU_SIZ_STRING_LANGID}
   ,
   {(u8 *) DFU_StringVendor, DFU_SIZ_STRING_VENDOR}
   ,
   {(u8 *) DFU_StringProduct, DFU_SIZ_STRING_PRODUCT}
   ,
   {(u8 *) DFU_StringSerial, DFU_SIZ_STRING_SERIAL}
   ,
   {(u8 *) DFU_StringInterface0, DFU_SIZ_STRING_INTERFACE0}
   ,
   {(u8 *) DFU_StringInterface1, DFU_SIZ_STRING_INTERFACE1}
};

/*
 * Extern variables ----------------------------------------------------------
 */
extern u8       DeviceState;
extern u8       DeviceStatus[6];

/*
 * Private function prototypes -----------------------------------------------
 */
/*
 * Private functions ---------------------------------------------------------
 */

/*******************************************************************************
* Function Name  : DFU_init.
* Description    : DFU init routine.
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void            DFU_init(void)
{
   DEVICE_INFO    *pInfo = &Device_Info;

   pInfo->Current_Configuration = 0;
   pInfo->Current_Feature = DFU_ConfigDescriptor[7];

   /*
    * Connect the device 
    */
   PowerOn();

   /*
    * USB interrupts initialization 
    */
   _SetISTR(0); /*
                 * clear pending interrupts 
                 */
   wInterrupt_Mask = IMR_MSK;
   _SetCNTR(wInterrupt_Mask); /*
                               * set interrupts mask 
                               */

   /*
    * Enable USB interrupts 
    */
   USB_Interrupts_Config();

   /*
    * Wait until device is configured 
    */
   while (pInfo->Current_Configuration == 0)
   {
      NOP_Process();
   }

   bDeviceState = CONFIGURED;
}

/*******************************************************************************
* Function Name  : DFU_Reset.
* Description    : DFU reset routine
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void            DFU_Reset(void)
{
   /*
    * Set DFU_DEVICE as not configured 
    */
   Device_Info.Current_Configuration = 0;

   _SetBTABLE(BTABLE_ADDRESS);

   /*
    * Initialize Endpoint 0 
    */
   _SetEPType(ENDP0, EP_CONTROL);
   _SetEPTxStatus(ENDP0, EP_TX_NAK);
   _SetEPRxAddr(ENDP0, ENDP0_RXADDR);
   SetEPRxCount(ENDP0, Device_Property.MaxPacketSize);
   _SetEPTxAddr(ENDP0, ENDP0_TXADDR);
   SetEPTxCount(ENDP0, Device_Property.MaxPacketSize);
   Clear_Status_Out(ENDP0);
   SetEPRxValid(ENDP0);

   /*
    * Set this device to response on default address 
    */
   SetDeviceAddress(0);

}

/*******************************************************************************
* Function Name  : DFU_Status_In.
* Description    : DFU status IN routine.
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void            DFU_Status_In(void)
{
}

/*******************************************************************************
* Function Name  : DFU_Status_Out.
* Description    : DFU status OUT routine.
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void            DFU_Status_Out(void)
{
   DEVICE_INFO    *pInfo = &Device_Info;
   u32             i, Addr, DATA, pages;

   if (pInfo->USBbRequest == DFU_GETSTATUS)
   {
      if (DeviceState == STATE_dfuDNBUSY)
      {
         if (wBlockNum == 0) /*
                              * Decode the Special Command
                              */
         {
            if ((Load_Buffer[0] == CMD_GETCOMMANDS) && (wlength == 1))
            {
            } else if ((Load_Buffer[0] == CMD_SETADDRESSPOINTER) && (wlength == 5))
            {
               Pointer = Load_Buffer[1];
               Pointer += Load_Buffer[2] << 8;
               Pointer += Load_Buffer[3] << 16;
               Pointer += Load_Buffer[4] << 24;
            } else if ((Load_Buffer[0] == CMD_ERASE) && (wlength == 5))
            {
               Pointer = Load_Buffer[1];
               Pointer += Load_Buffer[2] << 8;
               Pointer += Load_Buffer[3] << 16;
               Pointer += Load_Buffer[4] << 24;

               if (Pointer > 0x800000) /*
                                        * Internal Flash 
                                        */
               {
                  Internal_FLASH_PageErase(Pointer);
               } else
               {
                  SPI_FLASH_SectorErase(Pointer);
               }
            }
         } else if (wBlockNum > 1) // Download Command

         {
            Addr = ((wBlockNum - 2) * wTransferSize) + Pointer;
            if (Pointer > 0x800000) /*
                                     * Internal flash programming 
                                     */
            {
               if (wlength & 0x3) /*
                                   * Not an aligned data 
                                   */
               {
                  for (i = wlength; i < ((wlength & 0xFFFC) + 4); i++)
