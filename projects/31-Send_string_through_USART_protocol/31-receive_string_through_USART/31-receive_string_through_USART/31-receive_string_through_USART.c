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
	uint8 i = 0;
	char data = '\0';
	USART_init();
	LCD_init();
	
	while(1)
	{
		data = USART_receive_char();
		LCD_send_character(data);
    } 
		
}