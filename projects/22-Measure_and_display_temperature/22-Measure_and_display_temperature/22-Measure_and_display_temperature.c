/*
 * _22_Measure_and_display_temperature.c
 *
 * Created: 5/22/2022 11:34:43 PM
 *  Author: Mohamed Yasser
 */ 


#include "LM35.h"
#include "LCD.h"

int main(void)
{
	uint8 temperature = 0;
	
	LCD_init();
	LM35_init();
	
	LCD_send_string("Temperature is:");
	
    while(1)
    {
         temperature = LM35_read_temp();
		 if (temperature <10)
		 {
			 LCD_move_cursor(2,1);
			 LCD_send_character('=');
			 LCD_send_character('0');
			 LCD_send_character(temperature + 48);
			 LCD_send_character(0xDF);
			 LCD_send_character('C');
			 LCD_send_character(' ');
		 }
		 else
		 {
			 LCD_move_cursor(2,1);
			 LCD_send_character('=');
			 LCD_send_character( (temperature/10) + 48);
			 LCD_send_character( (temperature%10) + 48);
			 LCD_send_character(0xDF);
			 LCD_send_character('C');
		 }
    }
}