/*
 * _16_LCD_write_welcome_screen.c
 *
 * Created: 5/18/2022 2:18:37 PM
 *  Author: Mohamed Yasser
 */ 


#include "LCD.h"

int main(void)
{
	LCD_init();
	LCD_send_string("Mohamed Yasser");
    while(1)
    {
		
    }
}