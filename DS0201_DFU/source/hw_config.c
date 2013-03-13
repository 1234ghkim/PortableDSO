/*******************************************************************************
 File Name : hw_config.c              Author  : MCD Application Team & bure
*******************************************************************************/

#include "stm32f10x_lib.h"
#include "hw_config.h"

ErrorStatus     HSEStartUpStatus;

unsigned const short Char_Dot[744] =
{
   0x0000, 0x0000, 0x0000, 0x001C, 0x0020, 0x0040, 0x0040, 0x0040, /*
                                                                    * " No
                                                                    * used
                                                                    */
   0x0040, 0x0040, 0x0020, 0x001C, 0x0000, 0x0000, 0x0000, 0x0000, /*
                                                                    * # No
                                                                    * used
                                                                    */
   0x0000, 0x0000, 0x0000, 0xE000, 0x1000, 0x0800, 0x0800, 0x0800, /*
                                                                    * $ No
                                                                    * used
                                                                    */
   0x0C30, 0x0C60, 0x00C0, 0x0180, 0x0300, 0x0630, 0x0C30, 0x0000, /*
                                                                    * %    
                                                                    */
   0x0800, 0x0800, 0x1000, 0xE000, 0x0000, 0x0000, 0x0000, 0x0000, /*
                                                                    * & 
                                                                    */
   0x2010, 0x2010, 0x2010, 0x2010, 0x2010, 0x2010, 0x3FF0, 0x0000, /*
                                                                    * ' Empty 
                                                                    * bottom
                                                                    */
   0x0000, 0x0000, 0x0FC0, 0x1FE0, 0x3030, 0x2010, 0x0000, 0x0000, /*
                                                                    * (    
                                                                    */
   0x0000, 0x0000, 0x2010, 0x3030, 0x1FE0, 0x0FC0, 0x0000, 0x0000, /*
                                                                    * )    
                                                                    */
   0x0000, 0x18C0, 0x0D80, 0x0700, 0x0700, 0x0D80, 0x18C0, 0x0000,
/**  ¡Á*/
   0x0000, 0x0100, 0x0100, 0x07C0, 0x07C0, 0x0100, 0x0100, 0x0000, /*
                                                                    * +    
                                                                    */
   0x0000, 0x0000, 0x0000, 0xFFFC, 0x0000, 0x0000, 0x0000, 0x0000, /*
                                                                    * , No
                                                                    * used
                                                                    */
   0x0000, 0x0100, 0x0100, 0x0100, 0x0100, 0x0100, 0x0100, 0x0000,
/*-    */
   0x0000, 0x0000, 0x0000, 0x0030, 0x0030, 0x0000, 0x0000, 0x0000, /*
                                                                    * .    
                                                                    */
   0x0030, 0x0060, 0x00C0, 0x0180, 0x0300, 0x0600, 0x0C00, 0x0000, /*
                                                                    * /    
                                                                    */
   0x1FE0, 0x3FF0, 0x2090, 0x2310, 0x2410, 0x3FF0, 0x1FE0, 0x0000, /*
                                                                    * 0    
                                                                    */
   0x0000, 0x0810, 0x1810, 0x3FF0, 0x3FF0, 0x0010, 0x0010, 0x0000, /*
                                                                    * 1    
                                                                    */
   0x1070, 0x30F0, 0x2190, 0x2310, 0x2610, 0x3830, 0x1830, 0x0000, /*
                                                                    * 2    
                                                                    */
   0x1020, 0x3030, 0x2210, 0x2210, 0x2210, 0x3FF0, 0x1DE0, 0x0000, /*
                                                                    * 3    
                                                                    */
   0x0300, 0x0700, 0x0D00, 0x1910, 0x3FF0, 0x3FF0, 0x0110, 0x0000, /*
                                                                    * 4    
                                                                    */
   0x3E20, 0x3E30, 0x2210, 0x2210, 0x2310, 0x23F0, 0x21E0, 0x0000, /*
                                                                    * 5    
                                                                    */
   0x0FE0, 0x1FF0, 0x3210, 0x2210, 0x2210, 0x03F0, 0x01E0, 0x0000, /*
                                                                    * 6    
                                                                    */
   0x3000, 0x3000, 0x20F0, 0x21F0, 0x2300, 0x3E00, 0x3C00, 0x0000, /*
                                                                    * 7    
                                                                    */
   0x1DE0, 0x3FF0, 0x2210, 0x2210, 0x2210, 0x3FF0, 0x1DE0, 0x0000, /*
                                                                    * 8    
                                                                    */
   0x1C00, 0x3E10, 0x2210, 0x2210, 0x2230, 0x3FE0, 0x1FC0, 0x0000, /*
                                                                    * 9    
                                                                    */
   0x0000, 0x0000, 0x0000, 0x0C60, 0x0C60, 0x0000, 0x0000, 0x0000, /*
                                                                    * :    
                                                                    */
   0x0040, 0x0040, 0x0040, 0x0040, 0x0040, 0x0040, 0x0040, 0x0040, /*
                                                                    * ; No
                                                                    * used
                                                                    */
   0x0000, 0x0100, 0x0380, 0x06C0, 0x0C60, 0x1830, 0x1010, 0x0000, /*
                                                                    * <    
                                                                    */
   0x0240, 0x0240, 0x0240, 0x0240, 0x0240, 0x0240, 0x0240, 0x0000,
/*=    */
   0x0000, 0x1010, 0x1830, 0x0C60, 0x06C0, 0x0380, 0x0100, 0x0000, /*
                                                                    * >    
                                                                    */
   0x1800, 0x3800, 0x2000, 0x23B0, 0x27B0, 0x3C00, 0x1800, 0x0000, /*
                                                                    * ?    
                                                                    */
   0x0FC0, 0x1020, 0x2790, 0x2490, 0x27D0, 0x1050, 0x0F80, 0x0000, /*
                                                                    * @    
                                                                    */
   0x07F0, 0x0FF0, 0x1900, 0x3100, 0x1900, 0x0FF0, 0x07F0, 0x0000, /*
                                                                    * A    
                                                                    */
   0x2010, 0x3FF0, 0x3FF0, 0x2210, 0x2210, 0x3FF0, 0x1DE0, 0x0000, /*
                                                                    * B    
                                                                    */
   0x0FC0, 0x1FE0, 0x3030, 0x2010, 0x2010, 0x3030, 0x1860, 0x0000, /*
                                                                    * C    
                                                                    */
   0x2010, 0x3FF0, 0x3FF0, 0x2010, 0x3030, 0x1FE0, 0x0FC0, 0x0000, /*
                                                                    * D    
                                                                    */
   0x2010, 0x3FF0, 0x3FF0, 0x2210, 0x2710, 0x3030, 0x3870, 0x0000, /*
                                                                    * E    
                                                                    */
   0x2010, 0x3FF0, 0x3FF0, 0x2210, 0x2700, 0x3000, 0x3800, 0x0000, /*
                                                                    * F    
                                                                    */
   0x0FC0, 0x1FE0, 0x3030, 0x2110, 0x2110, 0x31E0, 0x19F0, 0x0000, /*
                                                                    * G    
                                                                    */
   0x3FF0, 0x3FF0, 0x0200, 0x0200, 0x0200, 0x3FF0, 0x3FF0, 0x0000, /*
                                                                    * H    
                                                                    */
   0x0000, 0x0000, 0x2010, 0x3FF0, 0x3FF0, 0x2010, 0x0000, 0x0000, /*
                                                                    * I    
                                                                    */
   0x00E0, 0x00F0, 0x0010, 0x2010, 0x3FF0, 0x3FE0, 0x2000, 0x0000, /*
                                                                    * J    
                                                                    */
   0x2010, 0x3FF0, 0x3FF0, 0x0300, 0x0F00, 0x3CF0, 0x3070, 0x0000, /*
                                                                    * K    
                                                                    */
   0x2010, 0x3FF0, 0x3FF0, 0x2010, 0x0010, 0x0030, 0x0030, 0x0000, /*
                                                                    * L    
                                                                    */
   0x3FF0, 0x3FF0, 0x1C00, 0x0E00, 0x1C00, 0x3FF0, 0x3FF0, 0x0000, /*
                                                                    * M    
                                                                    */
   0x3FF0, 0x3FF0, 0x1C00, 0x0E00, 0x0700, 0x3FF0, 0x3FF0, 0x0000, /*
                                                                    * N    
                                                                    */
   0x0FC0, 0x1FE0, 0x3030, 0x2010, 0x3030, 0x1FE0, 0x0FC0, 0x0000, /*
                                                                    * O    
                                                                    */
   0x2010, 0x3FF0, 0x3FF0, 0x2210, 0x2200, 0x3E00, 0x1C00, 0x0000, /*
                                                                    * P    
                                                                    */
   0x1FE0, 0x3FF0, 0x2010, 0x2070, 0x2030, 0x3FF8, 0x1FE8, 0x0000, /*
                                                                    * Q    
                                                                    */
   0x2010, 0x3FF0, 0x3FF0, 0x2200, 0x2300, 0x3FF0, 0x1CF0, 0x0000, /*
                                                                    * R    
                                                                    */
   0x1860, 0x3C70, 0x2610, 0x2210, 0x2310, 0x39F0, 0x18E0, 0x0000, /*
                                                                    * S    
                                                                    */
   0x0000, 0x3800, 0x3010, 0x3FF0, 0x3FF0, 0x3010, 0x3800, 0x0000, /*
                                                                    * T    
                                                                    */
   0x3FE0, 0x3FF0, 0x0010, 0x0010, 0x0010, 0x3FF0, 0x3FE0, 0x0000, /*
                                                                    * U    
                                                                    */
   0x3F80, 0x3FC0, 0x0060, 0x0030, 0x0060, 0x3FC0, 0x3F80, 0x0000, /*
                                                                    * V    
                                                                    */
   0x3FC0, 0x3FF0, 0x0070, 0x01C0, 0x0070, 0x3FF0, 0x3FC0, 0x0000, /*
                                                                    * W    
                                                                    */
   0x3030, 0x3CF0, 0x0FC0, 0x0300, 0x0FC0, 0x3CF0, 0x3030, 0x0000, /*
                                                                    * X    
                                                                    */
   0x0000, 0x3C00, 0x3E10, 0x03F0, 0x03F0, 0x3E10, 0x3C00, 0x0000, /*
                                                                    * Y    
                                                                    */
   0x3870, 0x30F0, 0x2190, 0x2310, 0x2610, 0x3C30, 0x3870, 0x0000, /*
                                                                    * Z    
                                                                    */
   0x0010, 0x0030, 0x0050, 0x0190, 0x0310, 0x0C10, 0x3FF0, 0x0000, /*
                                                                    * [ Delta
                                                                    */
   0x0800, 0x0800, 0x0800, 0x0800, 0x0800, 0x0800, 0x0800, 0x0800, /*
                                                                    * \ No
                                                                    * used
                                                                    */
   0x0000, 0x0000, 0x0000, 0xFC7C, 0x0280, 0x0280, 0x0100, 0x0100, /*
                                                                    * ] No
                                                                    * used
                                                                    */
   0x0200, 0x0400, 0x0C00, 0x1FF0, 0x3FF0, 0x0C00, 0x0400, 0x0200, /*
                                                                    * ^
                                                                    * rising
                                                                    * edge
                                                                    */
   0x0100, 0x0080, 0x00C0, 0x3FE0, 0x3FF0, 0x00C0, 0x0080, 0x0100,
/*_ falling edge*/
   0x2010, 0x2010, 0x2010, 0x2010, 0x2010, 0x2010, 0x2010, 0x2010, /*
                                                                    * ` Empty 
                                                                    * body
                                                                    */
   0x00E0, 0x05F0, 0x0510, 0x0510, 0x07E0, 0x03F0, 0x0010, 0x0000, /*
                                                                    * a    
                                                                    */
   0x2010, 0x3FF0, 0x3FE0, 0x0210, 0x0210, 0x03F0, 0x01E0, 0x0000, /*
                                                                    * b    
                                                                    */
   0x03E0, 0x07F0, 0x0410, 0x0410, 0x0410, 0x0630, 0x0220, 0x0000, /*
                                                                    * c    
                                                                    */
   0x01E0, 0x03F0, 0x0610, 0x2410, 0x3FF0, 0x3FF0, 0x0010, 0x0000, /*
                                                                    * d    
                                                                    */
   0x03E0, 0x07F0, 0x0510, 0x0510, 0x0510, 0x0730, 0x0320, 0x0000, /*
                                                                    * e    
                                                                    */
   0x0000, 0x0210, 0x1FF0, 0x3FF0, 0x2210, 0x3000, 0x1800, 0x0000, /*
                                                                    * f    
                                                                    */
   0x03C8, 0x07EC, 0x0424, 0x0424, 0x03FC, 0x07F8, 0x0400, 0x0000, /*
                                                                    * g    
                                                                    */
   0x2010, 0x3FF0, 0x3FF0, 0x0220, 0x0400, 0x07F0, 0x03F0, 0x0000, /*
                                                                    * h    
                                                                    */
   0x0000, 0x0000, 0x0410, 0x37F0, 0x37F0, 0x0010, 0x0000, 0x0000, /*
                                                                    * i    
                                                                    */
   0x0000, 0x0018, 0x001C, 0x0404, 0x37FC, 0x37F8, 0x0400, 0x0000, /*
                                                                    * j    
                                                                    */
   0x2010, 0x3FF0, 0x3FF0, 0x2180, 0x03C0, 0x0670, 0x0430, 0x0000, /*
                                                                    * k    
                                                                    */
   0x0000, 0x0000, 0x2010, 0x3FF0, 0x3FF0, 0x0010, 0x0000, 0x0000, /*
                                                                    * l    
                                                                    */
   0x07F0, 0x07F0, 0x0600, 0x03F0, 0x0600, 0x07F0, 0x07F0, 0x0000, /*
                                                                    * m    
                                                                    */
   0x0400, 0x07F0, 0x03F0, 0x0400, 0x0400, 0x07F0, 0x03F0, 0x0000, /*
                                                                    * n    
                                                                    */
   0x03E0, 0x07F0, 0x0410, 0x0410, 0x0410, 0x07F0, 0x03E0, 0x0000, /*
                                                                    * o    
                                                                    */
   0x0404, 0x07FC, 0x03FC, 0x0444, 0x0440, 0x07C0, 0x0380, 0x0000, /*
                                                                    * p    
                                                                    */
   0x0380, 0x07C0, 0x0440, 0x0444, 0x07FC, 0x03FC, 0x0404, 0x0000, /*
                                                                    * q    
                                                                    */
   0x0410, 0x07F0, 0x03F0, 0x0610, 0x0400, 0x0600, 0x0300, 0x0000, /*
                                                                    * r    
                                                                    */
   0x0000, 0x0220, 0x0730, 0x0590, 0x0490, 0x06F0, 0x0260, 0x0000, /*
                                                                    * s    
                                                                    */
   0x0400, 0x0400, 0x1FE0, 0x3FF0, 0x0410, 0x0430, 0x0020, 0x0000, /*
                                                                    * t    
                                                                    */
   0x07E0, 0x07F0, 0x0010, 0x0010, 0x07E0, 0x07F0, 0x0010, 0x0000, /*
                                                                    * u    
                                                                    */
   0x0000, 0x07C0, 0x07E0, 0x0030, 0x0030, 0x07E0, 0x07C0, 0x0000, /*
                                                                    * v    
                                                                    */
   0x07E0, 0x07F0, 0x0030, 0x00E0, 0x0030, 0x07F0, 0x07E0, 0x0000, /*
                                                                    * w    
                                                                    */
   0x0410, 0x0630, 0x03E0, 0x01C0, 0x03E0, 0x0630, 0x0410, 0x0000, /*
                                                                    * x    
                                                                    */
   0x0780, 0x07C4, 0x0044, 0x0044, 0x0044, 0x07F8, 0x07F0, 0x0000, /*
                                                                    * y    
                                                                    */
   0x0630, 0x0670, 0x04D0, 0x0590, 0x0710, 0x0630, 0x0430, 0x0000, /*
                                                                    * z    
                                                                    */
   0x0780, 0x0480, 0x3CF0, 0x2010, 0x2FD0, 0x2FD0, 0x2FD0, 0x2FD0, /*
                                                                    * {
                                                                    * Battery 
                                                                    * head
                                                                    */
   0x2FD0, 0x2FD0, 0x2FD0, 0x2FD0, 0x2FD0, 0x2FD0, 0x2FD0, 0x2FD0, /*
                                                                    * |
                                                                    * Battery 
                                                                    * body
                                                                    */
   0x2FD0, 0x2FD0, 0x2FD0, 0x2FD0, 0x2FD0, 0x2010, 0x3FF0, 0x0000, /*
                                                                    * }
                                                                    * Battery 
                                                                    * bottom
                                                                    */
   0x0780, 0x0480, 0x3CF0, 0x2010, 0x2010, 0x2010, 0x2010, 0x2010 /*
                                                                   * ~ Empty
                                                                   * head
                                                                   */
};

unsigned const int Logo_Dot[512] =
{
   0xFC000000, 0x0000003F, 0xFFC00000, 0x000003FF, 0xFFF00000, 0x00000FFF, 0xFFFE0000, 0x00007FFF,
   0xFFFF8000, 0x0000FFFF, 0x1FFFC000, 0x0003FFF8, 0x00FFE000, 0x0007FF80, 0x003FF800, 0x001FFC00,
/*
 * Block 00
 */
   0x0007FC00, 0x003FE000, 0xF803FE00, 0x007FC007, 0xFE00FF00, 0x00FF007F, 0xFFC07F80, 0x01FE03FF,
   0xFFE03F80, 0x01FC0FFF, 0xFFF81FC0, 0x03F81FFF, 0x0FFC0FE0, 0x07F03FF0, 0x01FF07E0, 0x0FE0FF80,
/*
 * Block 01
 */
   0x007F83F0, 0x0FC1FE00, 0x001F83F8, 0x1FC1F800, 0xF00FC1F8, 0x1F83F00F, 0xFC07E0F8, 0x1F07E03F,
   0xFF03F0FC, 0x3F07C0FF, 0xFF81F0FC, 0x3F0F81FF, 0x1FC1F87E, 0x7E1F83F8, 0x07E0F87E, 0x7E1F07FC,
/*
 * Block 02
 */
   0x01F0F87E, 0x7E1F0FFC, 0x00F07C3E, 0x7E3E0FFE, 0x00F87C3F, 0xFC3E1FFF, 0x00787C3F, 0xFC7E1FFF,
   0x807C3C3F, 0xFC7C3FFF, 0xC03C3E1F, 0xF87C3FFF, 0xE03C3E1F, 0xF87C3FFF, 0xE03C3E1F, 0xF87C3FFF,
/*
 * Block 03
 */
   0xF03C3E1F, 0xF87C3FFF, 0xF83C3E1F, 0xF87C3FFF, 0xF83C3E1F, 0xF87C3FFF, 0xFC3C3E3F, 0xFC3C3FFF,
   0xFE387E3F, 0xFC3E1FFF, 0xFE187C3F, 0xFC3E1FFF, 0xFF007C3E, 0x7C3E0FFF, 0xFF80F83E, 0x7E1F0FFF,
/*
 * Block 04
 */
   0xFFC0F87E, 0x7E1F07FF, 0xFFE1F87E, 0x7E1F83FF, 0xFFE1F0FC, 0x3F0F81FF, 0xFFF3E0FC, 0x3F0FC0FF,
   0xFCFFE0F8, 0x1F07E03F, 0xF0FFC1F8, 0x1F83F00F, 0x007F83F8, 0x1FC1F800, 0x007F83F0, 0x0F81FE00,
/*
 * Block 05
 */
   0x01FF07F0, 0x0E00FF80, 0x0FFC0FE0, 0x00003FF0, 0xFFF81FC0, 0x00041FFF, 0xFFF03F80, 0x001807FF,
   0xFFC07F80, 0x00F003FF, 0xFE00FF00, 0x03F0007F, 0xE003FE00, 0x07E0C01F, 0x0007FC00, 0x03E0E000,
/*
 * Block 06
 */
   0x003FF800, 0x01E0FC00, 0x01FFE000, 0x00C1FF00, 0x1FFFC000, 0x0041FFF8, 0xFFFF0000, 0x0001FFFF,
   0xFFFE0000, 0x00007FFF, 0xFFF00000, 0x00000FFF, 0xFFC00000, 0x000003FF, 0xFC000000, 0x0000003F,
/*
 * Block 07
 */
   0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
   0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
/*
 * Block 08
 */
   0xFFF80000, 0x00000003, 0xFFFF0000, 0x0000001F, 0xFFFFC000, 0x0000007F, 0xFFFFF000, 0x000000FF,
   0xFFFFF800, 0x000001FF, 0xFFFFF800, 0x000003FF, 0xFFFFFC00, 0x000003FF, 0x1F87FC00, 0x000007FE,
/*
 * Block 09
 */
   0x1F83FC00, 0x000007FC, 0x1F81FE00, 0x000007F8, 0x1F81FE00, 0x000007F8, 0x1F81FE00, 0x000007F8,
   0x1F83FC00, 0x000007FC, 0x1F87FC00, 0x000007FE, 0xFF8FFC00, 0x000003FF, 0xFF8FF800, 0x000001FF,
/*
 * Block 10
 */
   0xFF8FF000, 0x000000FF, 0xFF8FE000, 0x0000007F, 0xFF8FC000, 0x0000001F, 0xFF8F0000, 0x00000003,
   0x1F880000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
/*
 * Block 11
 */
   0x00000000, 0x00000000, 0xFF800000, 0x00000000, 0xFF800000, 0x00000000, 0xFF800000, 0x00000000,
   0xFF800000, 0x00000000, 0xFF800000, 0x00000000, 0xFF800000, 0x00000000, 0xFF800000, 0x00000000,
/*
 * Block 12
 */
   0xFF800000, 0x00000000, 0xFF800000, 0x00000000, 0xFF800000, 0x00000000, 0xFF800000, 0x00000000,
   0xFF800000, 0x00000000, 0xFF800000, 0x00000000, 0xFF800000, 0x00000000, 0xFF800000, 0x00000000,
/*
 * Block 13
 */
   0xFF800000, 0x00000000, 0xFF800000, 0x00000000, 0xFF800000, 0x00000000, 0x00000000, 0x00000000,
   0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFE00, 0x0001FFFF,
/*
 * Block 14
 */
   0xFFFFFE00, 0x0001FFFF, 0xFFFFFE00, 0x0001FFFF, 0xFFFFFE00, 0x0001FFFF, 0xFFFFFE00, 0x0001FFFF,
   0xFFFFFE00, 0x0001FFFF, 0xFFFFFE00, 0x0001FFFF, 0x0007FE00, 0x0001FF80, 0x0007FE00, 0x0001FF80,
/*
 * Block 15
 */
   0x0007FE00, 0x0001FF80, 0x0007FE00, 0x0001FF80, 0x0007FE00, 0x0001FF80, 0x0007FE00, 0x0001FF80,
   0x000FFE00, 0x0001FFC0, 0x001FFE00, 0x0001FFE0, 0x00FFFC00, 0x0000FFFC, 0xFFFFFC00, 0x0000FFFF,
/*
 * Block 16
 */
   0xFFFFF800, 0x00007FFF, 0xFFFFF000, 0x00003FFF, 0xFFFFE000, 0x00001FFF, 0xFFFFC000, 0x00000FFF,
   0xFFFF0000, 0x000003FF, 0xFFFC0000, 0x000000FF, 0xFF000000, 0x00000003, 0x00000000, 0x00000000,
/*
 * Block 17
 */
   0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFF80000, 0x00000003,
   0xFFFF0000, 0x0000001F, 0xFFFFC000, 0x0000007F, 0xFFFFF000, 0x000000FF, 0xFFFFF800, 0x000001FF,
/*
 * Block 18
 */
   0xFFFFF800, 0x000003FF, 0xFFFFFC00, 0x000003FF, 0x1F87FC00, 0x000007FE, 0x1F83FC00, 0x000007FC,
   0x1F81FE00, 0x000007F8, 0x1F81FE00, 0x000007F8, 0x1F81FE00, 0x000007F8, 0x1F83FC00, 0x000007FC,
/*
 * Block 19
 */
   0x1F87FC00, 0x000007FE, 0xFF8FFC00, 0x000003FF, 0xFF8FF800, 0x000001FF, 0xFF8FF000, 0x000000FF,
   0xFF8FE000, 0x0000007F, 0xFF8FC000, 0x0000001F, 0xFF8F0000, 0x00000003, 0x1F880000, 0x00000000,
/*
 * Block 20
 */
   0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
   0xF00F0000, 0x0000001F, 0xFC0FC000, 0x0000007F, 0xFE0FF000, 0x000000FF, 0xFE0FF800, 0x000001FF,
/*
 * Block 21
 */
   0xFF0FF800, 0x000003FF, 0xFF0FFC00, 0x000003FF, 0xFF87FC00, 0x000007FF, 0x7F83FE00, 0x000007F8,
   0x3FC1FE00, 0x000007F8, 0x3FC1FE00, 0x000007F8, 0x3FC1FE00, 0x000007F8, 0x1FE3FE00, 0x000007FC,
/*
 * Block 22
 */
   0x1FFFFC00, 0x000007FF, 0x0FFFFC00, 0x000003FF, 0x0FFFF800, 0x000003FF, 0x07FFF800, 0x000001FF,
   0x07FFF000, 0x000000FF, 0x03FFE000, 0x0000007F, 0x01FF8000, 0x0000001F, 0x007E0000, 0x00000000,
/*
 * Block 23
 */
   0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFE00, 0x000063FF,
   0xFFFFFE00, 0x0001E3FF, 0xFFFFFE00, 0x0007E3FF, 0xFFFFFE00, 0x001FE3FF, 0xFFFFFE00, 0x0007E3FF,
/*
 * Block 24
 */
   0xFFFFFE00, 0x0001E3FF, 0xFFFFFE00, 0x000063FF, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
   0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFE00000, 0x00000003, 0xFFFC0380, 0x0000001F,
/*
 * Block 25
 */
   0xFFFF03F0, 0x0000007F, 0xFFFF83F8, 0x000000FF, 0xFFFFC3FC, 0x000001FF, 0xFFFFE3FE, 0x000003FF,
   0xFFFFE3FE, 0x000003FF, 0xC07FE1FF, 0x000007FF, 0x003FE0FF, 0x000007FF, 0x001FE0FF, 0x000007FE,
/*
 * Block 26
 */
   0x001FE0FF, 0x000007FE, 0x001FE0FF, 0x000003FE, 0x003FC0FF, 0x000001FF, 0x807F83FF, 0x000000FF,
   0xFFFFFFFE, 0x0000007F, 0xFFFFFFFE, 0x000003FF, 0xFFFFFFFC, 0x000003FF, 0xFFFFFFF8, 0x000003FF,
/*
 * Block 27
 */
   0xFFFFFFE0, 0x000003FF, 0xFFFFFF80, 0x000003FF, 0xFFFFFE00, 0x000003FF, 0x00000000, 0x00000000,
   0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFE00, 0x000003FF,
/*
 * Block 28
 */
   0xFFFFFE00, 0x000003FF, 0xFFFFFE00, 0x000003FF, 0xFFFFFE00, 0x000003FF, 0xFFFFFE00, 0x000003FF,
   0xFFFFFE00, 0x000003FF, 0xFFFFFE00, 0x000003FF, 0xC0000000, 0x000000FF, 0x80000000, 0x000001FF,
/*
 * Block 29
 */
   0x00000000, 0x008003FF, 0x00000000, 0x008003FF, 0x80000000, 0x008003FF, 0xFFFFFE00, 0x00FF03FF,
   0xFFFFFE00, 0x008003FF, 0xFFFFFE00, 0x008001FF, 0xFFFFFE00, 0x008000FF, 0xFFFFFE00, 0x0000007F,
/*
 * Block 30
 */
   0xFFFFFE00, 0x0000001F, 0xFFFFFE00, 0x00FF0003, 0x00000000, 0x00400000, 0x00000000, 0x00300000,
0x00000000, 0x000C0000, 0x00000000, 0x00300000, 0x00000000, 0x00400000, 0x00000000, 0x00FF0000};

/*
 * Block 31
 */

/*******************************************************************************
Function Name: Set_System     Description: Configures Main system clocks & power
*******************************************************************************/
void            Set_System(void)
{
   FLASH_Unlock();
   RCC_DeInit();
   RCC_HSEConfig(RCC_HSE_ON);
   HSEStartUpStatus = RCC_WaitForHSEStartUp();
   if (HSEStartUpStatus == SUCCESS)
   {
      FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
      FLASH_SetLatency(FLASH_Latency_2);
      RCC_HCLKConfig(RCC_SYSCLK_Div1);
      RCC_PCLK2Config(RCC_HCLK_Div1);
      RCC_PCLK1Config(RCC_HCLK_Div2);
      RCC_ADCCLKConfig(RCC_PCLK2_Div4);
      RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_9);
      RCC_PLLCmd(ENABLE);
      while (RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET)
      {
      }
      RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
      while (RCC_GetSYSCLKSource() != 0x08)
      {
      }
   }
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC |
                       RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOE, ENABLE);
   RCC_USBCLKConfig(RCC_USBCLKSource_PLLCLK_1Div5);
   RCC_APB1PeriphClockCmd(RCC_APB1Periph_USB, ENABLE);

   USB_Cable_Config(DISABLE);
   USB_Cable_Config(ENABLE);
}

/*******************************************************************************
Function Name: GPIO_Config            Description: Configures the GPIO
*******************************************************************************/
void            GPIO_Config(void)
{
   GPIOA_CRL = 0x88888080; /*
                            * GPIOA Bit0-7  |||||||+----- Nib0  Ain   Analog
                            * input ||||||+------ Nib1  NC    Pull up input
                            * |||||+------- Nib2  Vbat  Analog input  
                            * ||||+-------- Nib3  NC    Pull up input  
                            * |||+--------- Nib4  KP    Pull up input  
                            * ||+---------- Nib5  KL    Pull up input  
                            * |+----------- Nib6  KU    Pull up input  
                            * +------------ Nib7  KR    Pull up input
                            */
   GPIOA_CRH = 0x8884488B; /*
                            * GPIOA Bit8-15  |||||||+----- Nib8  MCO
                            * Alternate output ||||||+------ Nib9  NC    Pull 
                            * up input |||||+------- Nib10 NC    Pull up
                            * input   ||||+-------- Nib11 D-    Input  
                            * |||+--------- Nib12 D+    Input   ||+---------- 
                            * Nib13 TMS   Pull up input   |+----------- Nib14 
                            * TCK   Pull up input   +------------ Nib15 TDI
                            * Pull up input
                            */
   GPIOA_ODR = 0x0FFFF;
   GPIOB_CRL = 0x88888411; /*
                            * GPIOB Bit0-7  |||||||+----- Nib0  A     Low
                            * speed output ||||||+------ Nib1  D     Low
                            * speed output |||||+------- Nib2  BT1   Input  
                            * ||||+-------- Nib3  TDO   Pull up input  
                            * |||+--------- Nib4  TRST  Pull up input  
                            * ||+---------- Nib5  NC    Pull up input  
                            * |+----------- Nib6  NC    Pull up input  
                            * +------------ Nib7  NC    Pull up input
                            */
   GPIOB_CRH = 0xBBB1B488; /*
                            * GPIOB Bit8-15  |||||||+----- Nib8  NC    Pull
                            * up input ||||||+------ Nib9  NC    Pull up
                            * input |||||+------- Nib10 Vusb  Input  
                            * ||||+-------- Nib11 V0    Alternate output  
                            * |||+--------- Nib12 SDCS  Low speed output  
                            * ||+---------- Nib13 SCK   Alternate output  
                            * |+----------- Nib14 MISO  Alternate output  
                            * +------------ Nib15 MOSI  Alternate output
                            */
   GPIOB_ODR = 0x0FFFF;
   GPIOC_CRL = 0x84118881; /*
                            * GPIOB Bit0-7  |||||||+----- Nib0  nCLS  Low
                            * speed output ||||||+------ Nib1  NC    Pull up
                            * input |||||+------- Nib2  NC    Pull up input  
                            * ||||+-------- Nib3  NC    Pull up input  
                            * |||+--------- Nib4  C     Low speed output  
                            * ||+---------- Nib5  B     Low speed output  
                            * |+----------- Nib6  NC    Input   +------------
                            * Nib7  NC    Pull up input
                            */
   GPIOC_CRH = 0x88888884; /*
                            * GPIOB Bit8-15  |||||||+----- Nib8  NC    Input
                            * ||||||+------ Nib9  NC    Pull up input
                            * |||||+------- Nib10 NC    Pull up input  
                            * ||||+-------- Nib11 NC    Pull up input  
                            * |||+--------- Nib12 NC    Pull up input  
                            * ||+---------- Nib13 NC    Pull up input  
                            * |+----------- Nib14 NC    Pull up input  
                            * +------------ Nib15 NC    Pull up input
                            */
   GPIOC_ODR = 0x0FFFF;
   GPIOD_CRL = 0x38338838; /*
                            * GPIOB Bit0-7  |||||||+----- Nib0  NC    Pull up 
                            * input ||||||+------ Nib1  RS    Hight speed
                            * output |||||+------- Nib2  NC    Pull up input
                            *  ||||+-------- Nib3  NC    Pull up input  
                            * |||+--------- Nib4  nRD   Hight speed output  
                            * ||+---------- Nib5  nWR   Hight speed output  
                            * |+----------- Nib6  NC    Pull up input  
                            * +------------ Nib7  nCS   Hight speed output
                            */
   GPIOD_CRH = 0x888B8884; /*
                            * GPIOB Bit8-15  |||||||+----- Nib8  NC    Pull
                            * up input ||||||+------ Nib9  KD    Pull up
                            * input |||||+------- Nib10 SDDT  Pull up input  
                            * ||||+-------- Nib11 KM    Pull up input  
                            * |||+--------- Nib12 Fout  Alternate output  
                            * ||+---------- Nib13 NC    Pull up input  
                            * |+----------- Nib14 NC    Pull up input  
                            * +------------ Nib15 NC    Pull up input
                            */
   GPIOD_ODR = 0x0FF7F;
   GPIOE_CRL = 0x33333333; // Bit0-7  Hight speed output£¨LCD_DB0-7 £©

   GPIOE_CRH = 0x33333333; // Bit8-15 Hight speed output£¨LCD_DB8-15£©

}

/*******************************************************************************
 LCD_WR_REG: Set LCD Register  Input: Register addr., Data¡£
*******************************************************************************/
void            LCD_WR_REG(unsigned short Reg, unsigned short Data)
{
   LDC_DATA_OUT = Reg; // Reg. Addr.

   LCD_RS_LOW(); // RS=0,Piont to Index Reg.

   LCD_nWR_ACT(); // WR Cycle from 1 -> 0 -> 1

   LCD_RS_HIGH(); // RS=1,Piont to object Reg.

   LDC_DATA_OUT = Data; // Reg. Data 

   LCD_nWR_ACT(); // WR Cycle from 1 -> 0 -> 1

}

/*******************************************************************************
 delayms:  Delay   Input: Millisecond
*******************************************************************************/
void            Delay_ms(unsigned short mS)
{
   u32             i;

   for (i = 0; i < (3600 * mS); ++i)
   {
      LCD_nRD_HIGH();
      LCD_nRD_HIGH();
   }
}
/*******************************************************************************
 LCD_Initial: ST7781 LCD Initialization 
*******************************************************************************/
void            LCD_Initial(void)
{
   // ------------------------- Reset LCD Driver ---------------------//
   LCD_DATA_BUS_OUT(); // Set LCD Data Bus as Output Mode

   LCD_nWR_HIGH();
   LCD_nRD_HIGH();
   LCD_RS_HIGH(); // RS=1        

   LCD_nRST_HIGH();
   Delay_ms(1); // RST=1£¬Delay 1ms      

   LCD_nRST_LOW();
   Delay_ms(1); // RST=0 Reset LCD£¬Delay 1ms      

   LCD_nRST_HIGH();
   Delay_ms(5); // RST=1£¬Delay 5 ms  
   // ----------------ST7781 Internal Register Initial------------//         

   LCD_WR_REG(0x00FF, 0x0001);
   LCD_WR_REG(0x00F3, 0x0008);
   LDC_DATA_OUT = 0x00F3;
   LCD_RS_LOW();
   LCD_nWR_ACT(); // Read Parameter      

   LCD_RS_HIGH();
   // -------------------Display Control Setting-----------------//
   LCD_WR_REG(0x0001, 0x0100); // Output Direct 

   LCD_WR_REG(0x0002, 0x0700); // Line Inversion

   LCD_WR_REG(0x0003, 0x0030); // BGR=0,ID=11

   LCD_WR_REG(0x0008, 0x0302); // Porch Setting

   LCD_WR_REG(0x0009, 0x0000); // Scan Cycle

   LCD_WR_REG(0x000A, 0x0000); // FMARK off
   // ----------------power Control Register Initial------------//

   LCD_WR_REG(0x0010, 0x0790); // Power Control1

   LCD_WR_REG(0x0011, 0x0005); // Power Control2

   LCD_WR_REG(0x0012, 0x0000); // Power Control3

   LCD_WR_REG(0x0013, 0x0000); // Power Control4

   Delay_ms(100); // Delay 100ms   

   LCD_WR_REG(0x0010, 0x12B0); // Power Control1

   Delay_ms(50); // delay 50ms

   LCD_WR_REG(0x0011, 0x0007); // Power Control2

   Delay_ms(50); // delay 50ms

   LCD_WR_REG(0x0012, 0x008C); // Power Control3

   LCD_WR_REG(0x0013, 0x1700); // Power Control4

   LCD_WR_REG(0x0029, 0x001A); // VCOMH Setting

   Delay_ms(50); // delay 50ms
   // ------------------GAMMA Cluster Setting-------------------//

   LCD_WR_REG(0x0030, 0x0000);
   LCD_WR_REG(0x0031, 0x0507);
   LCD_WR_REG(0x0032, 0x0003);
   LCD_WR_REG(0x0035, 0x0200);
   LCD_WR_REG(0x0036, 0x0106);
   LCD_WR_REG(0x0037, 0x0000);
   LCD_WR_REG(0x0038, 0x0507);
   LCD_WR_REG(0x0039, 0x0104);
   LCD_WR_REG(0x003C, 0x0200);
   LCD_WR_REG(0x003D, 0x0005);
   // ------------------Display Windows 240*320-----------------//
   LCD_WR_REG(0x0050, 0x0000);
   LCD_WR_REG(0x0051, 0x00EF);
   LCD_WR_REG(0x0052, 0x0000);
   LCD_WR_REG(0x0053, 0x013F);
   // --------------------Frame Rate Setting--------------------//
   LCD_WR_REG(0x0060, 0xA700);
   LCD_WR_REG(0x0061, 0x0001);
   LCD_WR_REG(0x0090, 0x0033);
   LCD_WR_REG(0x0007, 0x0133);
   Delay_ms(50); // delay 50ms

}

/*******************************************************************************
 Point_SCR : Set display position   Input: X¡¢Y 
*******************************************************************************/
void            Point_SCR(unsigned short x0, unsigned short y0)
{
   LCD_WR_REG(0x0020, y0);
   LCD_WR_REG(0x0021, x0);
   LDC_DATA_OUT = 0x0022;
   LCD_RS_LOW();
   LCD_nWR_ACT();
   LCD_nWR_ACT();
   LCD_RS_HIGH();
}
/*******************************************************************************
 Set_Pixel: Set a Pixel  Input: Color
*******************************************************************************/
void            Set_Pixel(unsigned short Color)
{
   LDC_DATA_OUT = Color;
   LCD_nWR_ACT();
}
/*******************************************************************************
 Clear_Screen 
*******************************************************************************/
void            Clear_Screen(unsigned short Color)
{
   unsigned int    i;

   Point_SCR(0, 0); // X_pos=0£¬Y_pos=0

   for (i = 0; i < 240 * 320; ++i)
      Set_Pixel(Color);
}

/*******************************************************************************
 Display_Str: Display String   Input: X¡¢Y, Color, Mode, String 
*******************************************************************************/
void            Display_Str(unsigned short x0, unsigned short y0, unsigned short Color, unsigned char Mode, unsigned const char *s)
{
   signed short    i, j, b;

   Point_SCR(x0, y0);
   for (j = 0; j < 14; ++j)
   {
      if (Mode == 0)
         Set_Pixel(0);
      if (Mode == 1)
         Set_Pixel(Color);
   }
   x0++;
   while (*s != 0)
   {
      unsigned const short *scanline = Char_Dot + ((*s - 0x22) * 8);

      for (i = 0; i < 8; ++i)
      {
         Point_SCR(x0 + i, y0);
         if ((*s == 0x20) || (*s == 0x21))
            b = 0x0000;
         else
            b = scanline[i];
         if ((*s == 0x21) && (i == 4))
            break;
         for (j = 0; j < 14; ++j)
         {
            if (b & 4)
            {
               if (Mode == 0)
                  Set_Pixel(Color);
               if (Mode == 1)
                  Set_Pixel(0);
               if (Mode == 2)
                  Set_Pixel(Color);
               if (Mode == 3)
                  Set_Pixel(0);
            } else
            {
               if (Mode == 0)
                  Set_Pixel(0);
               if (Mode == 1)
                  Set_Pixel(Color);
               if (Mode == 2)
                  Set_Pixel(0);
               if (Mode == 3)
                  Set_Pixel(Color);
            }
            b >>= 1;
         }
      }
      if (*s == 0x21)
         x0 += 4;
      else
         x0 += 8;
      ++s; // next character

   }
}

/*******************************************************************************
 Display_Logo: Display Logo   Input: X¡¢Y 
*******************************************************************************/
void            Display_Logo(unsigned short Dot_x, unsigned short Dot_y)
{
   unsigned short  i, j, k, Color;
   int             b;

   for (i = 0; i < 256; ++i)
   {
      Point_SCR(Dot_x + i, Dot_y);
      for (j = 0; j < 2; ++j)
      {
         b = Logo_Dot[(i * 2) + j];
         for (k = 0; k < 32; ++k)
         {
            if (b & 1)
            {
               if (i < 64)
                  Color = 0x051F;
               else
                  Color = 0xFFE0;
            } else
               Color = 0;
            Set_Pixel(Color);
            b >>= 1;
         }
      }
   }
   for (i = 0; i < 320; ++i)
   {
      Point_SCR(i, 0);
      Set_Pixel(0xFFFF);
      Point_SCR(i, 239);
      Set_Pixel(0xFFFF);
   }
   for (i = 3; i < 317; ++i)
   {
      Point_SCR(i, 3);
      Set_Pixel(0xFFFF);
      Point_SCR(i, 236);
      Set_Pixel(0xFFFF);
   }
   Point_SCR(0, 0);
   for (j = 0; j < 240; ++j)
      Set_Pixel(0xFFFF);
   Point_SCR(3, 3);
   for (j = 3; j < 237; ++j)
      Set_Pixel(0xFFFF);
   Point_SCR(316, 3);
   for (j = 3; j < 237; ++j)
      Set_Pixel(0xFFFF);
   Point_SCR(319, 0);
   for (j = 0; j < 240; ++j)
      Set_Pixel(0xFFFF);
}

/*******************************************************************************
* Function Name  : Enter_LowPowerMode.
* Description    : Power-off system clocks and power while entering suspend mode.
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void            Enter_LowPowerMode(void)
{
}

/*******************************************************************************
* Function Name  : Leave_LowPowerMode.
* Description    : Restores system clocks and power while exiting suspend mode.
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void            Leave_LowPowerMode(void)
{
}
/*******************************************************************************
* Function Name  : USB_Cable_Config.
* Description    : Software Connection/Disconnection of USB Cable.
* Input          : NewState: new state.
* Output         : None.
* Return         : None.
*******************************************************************************/
void            USB_Cable_Config(FunctionalState NewState)
{
   if (NewState != DISABLE)
   {
      GPIO_ResetBits(GPIOD, GPIO_Pin_8);
   } else
   {
      GPIO_SetBits(GPIOD, GPIO_Pin_8);
   }
}

/*******************************************************************************
* Function Name  : DFU_Button_Read.
* Description    : Reads the DFU selector Button to enter DFU Mode.
* Input          : None.
* Output         : None.
* Return         : Status
*******************************************************************************/
u8              DFU_Button_Read(void)
{
   return GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_9);
}

/*******************************************************************************
* Function Name  : USB_Interrupts_Config.
* Description    : Configures the USB interrupts.
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void            USB_Interrupts_Config(void)
{
   NVIC_InitTypeDef NVIC_InitStructure;

   NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0);

   NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

   NVIC_InitStructure.NVIC_IRQChannel = USB_LP_CAN_RX0_IRQChannel;
   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
   NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
   NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
   NVIC_Init(&NVIC_InitStructure);

   /*
    * Enable USART1 Interrupt 
    */
   NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQChannel;
   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
   NVIC_Init(&NVIC_InitStructure);
}

/*******************************************************************************
* Function Name  : Reset_Device.
* Description    : Reset the device.
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void            Reset_Device(void)
{
   USB_Cable_Config(DISABLE);
   NVIC_GenerateSystemReset();
}

/*******************************************************************************
* Function Name  : Internal_FLASH_WordWrite.
* Description    : Writes a Word in the Flash
* Input          : - Address of the Destination.
*                  - Word to program at Address.
* Output         : None.
* Return         : None.
*******************************************************************************/
void            Internal_FLASH_WordWrite(u32 XtargetAdd, u32 Xdata)
{
   FLASH_ProgramWord(XtargetAdd, Xdata);
}
/*******************************************************************************
* Function Name  : Internal_FLASH_SectorErase.
* Description    : Erases a Flash sector 
* Input          : Sectors to be Erased.
* Output         : None.
* Return         : None.
*******************************************************************************/
void            Internal_FLASH_PageErase(u32 XPage)
{
   FLASH_ErasePage(XPage);
}

/*******************************************************************************
* Function Name  : FLASH_WritePrConfig.
* Description    : Enable Write protection or Disable temporarily Write
*                  protection of a flash sector.
* Input          : - Flash Sector.
*                  - Enable or disable Flash sector Write Protection.
* Output         : None.
* Return         : None.
*******************************************************************************/
void            Internal_FLASH_WritePrConfig(u32 Xsectors, FunctionalState NewState)
{
}

/********************************* END OF FILE ********************************/
