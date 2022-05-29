/*
 * _32_Interface_with_PC_by_USART.c
 *
 * Created: 5/29/2022 7:05:07 AM
 *  Author: Mohamed Yasser
 */ 

#include "USART.h"
#include "LCD.h"

int main(void)
{
	char data = '\0';
	LCD_init();
	USART_init();
	
	
	while(1)
	{
		data = USART_receive_char();
		LCD_send_character(data);
	}
	
}