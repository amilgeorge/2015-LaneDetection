//
//#include "main.h"
////#include "head.h"
//int main()
//{
//
//	unsigned int i, j = 0;
//
//   volatile unsigned int *pLcdDestReg = (volatile unsigned int*)(LCD_DEST_REG_ADDR);
//   volatile unsigned int *pLcdWidthReg = (volatile unsigned int*)(LCD_WIDTH_REG_ADDR);
//   volatile unsigned int *pLcdHeightReg = (volatile unsigned int*)(LCD_HEIGHT_REG_ADDR);
//   volatile unsigned int *pLcdCmdReg = (volatile unsigned int*)(LCD_CMD_REG_ADDR);
//
//   volatile unsigned int *pCam = (volatile unsigned int*)(OV7670_0_BASE | 0x80000000);
//   volatile unsigned char pid[2] = {0,0};
//
//  *pLcdCmdReg = 0; // make sure that the DMA is stopped before calling the LCD init functions
//  *pCam = 0;
//  LCD_Init();
//  LCD_Clear(0X00ff);
//  //init_lcd_frame();
//
//
//
//   printf("%x\n", lcd_frame);
//
//   *pCam = 1; // turns the camera ON. Camera turns on with the next new frame
//   Delay_Ms(2000); // add delay to be sure that frames are already in the memory
//
//   *pLcdDestReg = LT24_CONTROLLER_0_BASE + 4;
//   *pLcdWidthReg = 240; // LCD width
//   *pLcdHeightReg = 320; // LCD height
//   *pLcdCmdReg = 0x1f00000; // by default camera throws images starting from here
//   *pLcdCmdReg |= 0x80000000; // this commands turns the LCD ON
//
//
//
//}
