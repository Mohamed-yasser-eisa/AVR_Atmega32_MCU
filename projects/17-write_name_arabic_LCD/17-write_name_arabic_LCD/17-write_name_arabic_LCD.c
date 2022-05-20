/*
 * _17_write_name_arabic_LCD.c
 *
 * Created: 5/20/2022 1:57:47 AM
 *  Author: Mohamed Yasser
 */ 

/************************************************
* Write my name (Mohamed Yasser) in English and Arabic on 4x16 LCD
* use this website to generate binary code for any custom character:
*	https://maxpromer.github.io/LCD-Character-Creator/
*
*
************************************************/



#include "LCD.h"


char name[7][8]={ {0x00,0x00,0x0F,0x09,0x19,0x09,0x0F,0x00},
				  {0x18,0x04,0x02,0x02,0x1F,0x00,0x00,0x00},
				  {0x02,0x02,0x02,0x02,0x1F,0x00,0x00,0x00},
				  {0x00,0x00,0x01,0x01,0x1F,0x00,0x0E,0x00},
				  {0x04,0x04,0x04,0x04,0x07,0x00,0x00,0x00},
				  {0x00,0x00,0x15,0x15,0x1F,0x00,0x00,0x00},
				  {0x00,0x00,0x00,0x04,0x07,0x04,0x18,0x00} }; //M-7-D-Y-A-S-R



int main(void)
{
	uint8 i=0,j=0;
	LCD_init();
	LCD_send_string("Mohamed Yasser");
	LCD_send_command(0x40);
	for (i=0;i<7;++i)
	{
		for (j=0;j<8;++j)
		{
			LCD_send_character(name[i][j]);
		}
	}
	for (i=14,j=0;i>6;--i,j++)
	{
		LCD_move_cursor(2,i);
		if (2 == j)
		{
			LCD_send_character(0);
			continue;
		}
		LCD_send_character(j);
	}
    while(1)
    {
		for (i=0; i<2; ++i)
		{
			LCD_send_command(ENTIRE_DISPLAY_RIGHT);
			_delay_ms(1000);
		}
		for (i=0; i<2; ++i)
		{
			LCD_send_command(ENTIRE_DISPLAY_LEFT);
			_delay_ms(1000);
		}
        
    }
}