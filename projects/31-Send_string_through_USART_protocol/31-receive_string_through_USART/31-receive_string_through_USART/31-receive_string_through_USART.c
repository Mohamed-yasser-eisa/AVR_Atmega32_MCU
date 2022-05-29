/*
 * _31_receive_string_through_USART.c
 *
 * Created: 5/29/2022 1:48:09 AM
 *  Author: Mohamed Yasser
 */ 


#include "USART.h"
#include "LCD.h"

int main(void)
{
	uint8 row = 1;
	char data = '\0';
	LCD_init();
	USART_init();
	
	
	while(1)
	{
		data = USART_receive_char();
		if ('\0' != data)
		{
			LCD_send_character(data);
			if ((char) 'd' == (char)data)
			{
				++row;
				if (6 == row)
				{
					row = 1;
					LCD_clear_screen();
				}
				else
				{
					LCD_move_cursor(row, 1);
				}
			}
			else
			{
				data = '\0';
			}
			
		}
		
    } 
		
}