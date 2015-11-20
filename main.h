/*
 * main.h
 *
 *  Created on: May 6, 2015
 *      Author: RiddhiHardik
 */

#ifndef MAIN_H_
#define MAIN_H_
#include "system.h"
#include "altera_avalon_pio_regs.h"

#define RED 0xf800
#define GREEN 0x07e0
#define BLUE 0x001f

#define SINGLE_SHIFT_RED 0x7800
#define SINGLE_SHIFT_GREEN 0x03e0
#define SINGLE_SHIFT_BLUE 0x000f

#define DOUBLE_SHIFT_RED 0x3800
#define DOUBLE_SHIFT_GREEN 0x01e0
#define DOUBLE_SHIFT_BLUE 0x0007

#define TRIPPLE_SHIFT_RED 0x1800
#define TRIPPLE_SHIFT_GREEN 0x00e0
#define TRIPPLE_SHIFT_BLUE 0x0003

#define LCD_DEST_REG_ADDR (0x80000000 | LCD_DMA_0_BASE )
#define LCD_WIDTH_REG_ADDR (LCD_DEST_REG_ADDR + 4)
#define LCD_HEIGHT_REG_ADDR (LCD_DEST_REG_ADDR + 8)
#define LCD_CMD_REG_ADDR (LCD_DEST_REG_ADDR + 12)

#define  LCD_WR_REG(value)  IOWR(LT24_CONTROLLER_0_BASE,0x00,value)
#define  LCD_WR_DATA(value)  IOWR(LT24_CONTROLLER_0_BASE,0x01,value)

#define  Set_LCD_RST  IOWR_ALTERA_AVALON_PIO_DATA(LCD_RESET_N_BASE,0x01)
#define  Clr_LCD_RST  IOWR_ALTERA_AVALON_PIO_DATA(LCD_RESET_N_BASE,0x00)


/*The size of the lcd_frame is VGA although the LCD can only display 240 x 320 resolution*/
volatile unsigned char *lcd_frame;// __attribute__ ((section (".frame_buffer")));

void Delay_Ms(alt_u16 count_ms)
{
    while(count_ms--)
    {
        usleep(1000);
    }
}


void LCD_Init()
{
	alt_u16 data1,data2;
	alt_u16 data3,data4;
	Set_LCD_RST;
	Delay_Ms(1);
	Clr_LCD_RST;
	Delay_Ms(10);       // Delay 10ms // This delay time is necessary
	Set_LCD_RST;
	Delay_Ms(120);       // Delay 120 ms
//	Clr_LCD_CS;



	LCD_WR_REG(0x0011); //Exit Sleep
	LCD_WR_REG(0x00CF);
		LCD_WR_DATA(0x0000);
		LCD_WR_DATA(0x0081);
		LCD_WR_DATA(0X00c0);

	LCD_WR_REG(0x00ED);
		LCD_WR_DATA(0x0064);
		LCD_WR_DATA(0x0003);
		LCD_WR_DATA(0X0012);
		LCD_WR_DATA(0X0081);

	LCD_WR_REG(0x00E8);
		LCD_WR_DATA(0x0085);
		LCD_WR_DATA(0x0001);
		LCD_WR_DATA(0x00798);

	LCD_WR_REG(0x00CB);
		LCD_WR_DATA(0x0039);
		LCD_WR_DATA(0x002C);
		LCD_WR_DATA(0x0000);
		LCD_WR_DATA(0x0034);
		LCD_WR_DATA(0x0002);

	LCD_WR_REG(0x00F7);
		LCD_WR_DATA(0x0020);

	LCD_WR_REG(0x00EA);
		LCD_WR_DATA(0x0000);
		LCD_WR_DATA(0x0000);

	LCD_WR_REG(0x00B1);
		LCD_WR_DATA(0x0000);
		LCD_WR_DATA(0x001b);

	LCD_WR_REG(0x00B6);
		LCD_WR_DATA(0x000A);
		LCD_WR_DATA(0x00A2);

	LCD_WR_REG(0x00C0);    //Power control
		LCD_WR_DATA(0x0005);   //VRH[5:0]

	LCD_WR_REG(0x00C1);    //Power control
		LCD_WR_DATA(0x0011);   //SAP[2:0];BT[3:0]

	LCD_WR_REG(0x00C5);    //VCM control
		LCD_WR_DATA(0x0045);       //3F
		LCD_WR_DATA(0x0045);       //3C

	 LCD_WR_REG(0x00C7);    //VCM control2
		 LCD_WR_DATA(0X00a2);

	LCD_WR_REG(0x0036);    // Memory Access Control
		LCD_WR_DATA(0x0008);//48

	LCD_WR_REG(0x00F2);    // 3Gamma Function Disable
		LCD_WR_DATA(0x0000);

	LCD_WR_REG(0x0026);    //Gamma curve selected
		LCD_WR_DATA(0x0001);

	LCD_WR_REG(0x00E0);    //Set Gamma
		LCD_WR_DATA(0x000F);
		LCD_WR_DATA(0x0026);
		LCD_WR_DATA(0x0024);
		LCD_WR_DATA(0x000b);
		LCD_WR_DATA(0x000E);
		LCD_WR_DATA(0x0008);
		LCD_WR_DATA(0x004b);
		LCD_WR_DATA(0X00a8);
		LCD_WR_DATA(0x003b);
		LCD_WR_DATA(0x000a);
		LCD_WR_DATA(0x0014);
		LCD_WR_DATA(0x0006);
		LCD_WR_DATA(0x0010);
		LCD_WR_DATA(0x0009);
		LCD_WR_DATA(0x0000);

	LCD_WR_REG(0X00E1);    //Set Gamma
		LCD_WR_DATA(0x0000);
		LCD_WR_DATA(0x001c);
		LCD_WR_DATA(0x0020);
		LCD_WR_DATA(0x0004);
		LCD_WR_DATA(0x0010);
		LCD_WR_DATA(0x0008);
		LCD_WR_DATA(0x0034);
		LCD_WR_DATA(0x0047);
		LCD_WR_DATA(0x0044);
		LCD_WR_DATA(0x0005);
		LCD_WR_DATA(0x000b);
		LCD_WR_DATA(0x0009);
		LCD_WR_DATA(0x002f);
		LCD_WR_DATA(0x0036);
		LCD_WR_DATA(0x000f);

	LCD_WR_REG(0x002A);
		LCD_WR_DATA(0x0000);
		LCD_WR_DATA(0x0000);
		LCD_WR_DATA(0x0000);
		LCD_WR_DATA(0x00ef);

	 LCD_WR_REG(0x002B);
		LCD_WR_DATA(0x0000);
		LCD_WR_DATA(0x0000);
		LCD_WR_DATA(0x0001);
		LCD_WR_DATA(0x003f);

	LCD_WR_REG(0x003A);
		LCD_WR_DATA(0x0055);

	LCD_WR_REG(0x00f6);
		LCD_WR_DATA(0x0001);
		LCD_WR_DATA(0x0030);
		LCD_WR_DATA(0x0000);

	LCD_WR_REG(0x0029); //display on

	LCD_WR_REG(0x002c);    // 0x2C

}

void LCD_Clear(alt_u16 Color)
{
        alt_u32 index=0;
        LCD_WR_REG(0x002C);
        //while(1)
        for(index=0;index<76800;index++)
        {
        	LCD_WR_DATA(Color);
        }


}

void init_lcd_frame()
{

    unsigned int i, j = 0;
    unsigned short data = 0x00;
	lcd_frame = (volatile unsigned char*)(0x1f00000 | 0x80000000);
	printf("%x\n", lcd_frame);

	for (i = 0; i < 480; i++)
		for (j = 0; j < 640; j++)
	   {
		   if (i < 320/3) data = (RED | GREEN | BLUE) ;

		   if ( (i >= 320/3) && (i < 2 * 320/3)) data = (SINGLE_SHIFT_RED | SINGLE_SHIFT_GREEN | SINGLE_SHIFT_BLUE);

		   if (i >= 2 * 320/3) data = 0; //(TRIPPLE_SHIFT_RED | TRIPPLE_SHIFT_GREEN | TRIPPLE_SHIFT_BLUE);

		   *lcd_frame = data;
		   lcd_frame++;
		   //IOWR(lcd_frame, (i*320 + j)*2, data);
	   }
}

void print_pattern()
{

    unsigned int i, j = 0;
    unsigned short data = 0x00;
	lcd_frame = (volatile unsigned char*)(0x1f00000 | 0x80000000);

	for (i = 0; i < 480; i++)
		for (j = 0; j < 640; j++)
	   {
		   *lcd_frame = *lcd_frame << 1;
		   lcd_frame++;
		   //IOWR(lcd_frame, (i*320 + j)*2, data);
	   }
}

void check_lcd_frame()
{
	unsigned int i, j = 0;
	unsigned short data = 0x00;
	lcd_frame = (volatile unsigned short*)(0x1f00000 | 0x80000000);
	printf("%x\n", lcd_frame);

	for (i = 0; i < 480; i++)
		for (j = 0; j < 640; j++)
		{
			data = *lcd_frame; lcd_frame++;

			if (i < 110) {
				if (data != BLUE) printf (" i = %u; j = %u, data = %x\n", i, j, data);
			}

			if ( (i < 220) && (i >= 110) ) {
				if (data != GREEN) printf (" i = %u; j = %u, data = %x\n", i, i, data);
			}

			if (i >= 220) {
				if (data != RED) printf (" i = %u; j = %u, data = %x\n", i, i, data);
			}
		}
}



#endif /* MAIN_H_ */
