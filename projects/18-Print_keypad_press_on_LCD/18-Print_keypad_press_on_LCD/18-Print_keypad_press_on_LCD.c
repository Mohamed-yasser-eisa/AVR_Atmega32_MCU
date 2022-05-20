/*
 * _18_Print_keypad_press_on_LCD.c
 *
 * Created: 5/20/2022 1:58:53 PM
 *  Author: Mohamed Yasser
 */ 


/*************************************************************
* print each keypad button press on LCD.
* clear LCD when button 'c' is pressed.
*************************************************************/

/************ Include section ********************************/
#include "LCD.h"
#include "keypad.h"

/*============================================================*/

int main(void)
{
	char key_value = '\0';
	keypad_init();
	LCD_init();
	
    while(1)
    {
        key_value = keypad_check_press();
		if (0xff != key_value)
		{
			if ((char)'c' == (char) key_value)
			{
				LCD_clear_screen();
			}
			else
			{
				LCD_send_character(key_value);
			}
			_delay_ms(200);
		}
		 
    }
}