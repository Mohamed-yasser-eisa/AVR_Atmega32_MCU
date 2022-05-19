/*
 * _16_LCD_write_welcome_screen.c
 *
 * Created: 5/18/2022 2:18:37 PM
 *  Author: Mohamed Yasser
 */ 


#include "LCD.h"

int main(void)
{
	uint8 i = 0; //outer loop counter
	uint8 j = 0; //inner loop counter
	LCD_init();
	
    while(1)
    {
		LCD_send_string("Welcome");
		for (i=0; i<3; ++i)
		{
			for(j=0; j<9; ++j)
			{
				_delay_ms(100);
				LCD_send_command(ENTIRE_DISPLAY_RIGHT);
			}
			for(j=0; j<9; ++j)
			{
				_delay_ms(100);
				LCD_send_command(ENTIRE_DISPLAY_LEFT);
			}
		}
		
		LCD_clear_screen();
		LCD_send_string("*Mohamed Yasser*");
		LCD_move_cursor(2,1);
		LCD_send_string("  23 years old ");
		LCD_move_cursor(3,1);
		LCD_send_string(" Biomedical eng.");
		LCD_move_cursor(4,1);
		LCD_send_string("  Embedded eng.");
		_delay_ms(7000);
		LCD_clear_screen();
    }
}