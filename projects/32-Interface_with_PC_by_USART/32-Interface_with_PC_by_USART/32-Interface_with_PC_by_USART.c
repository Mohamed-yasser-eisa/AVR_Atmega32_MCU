/*
 * _32_Interface_with_PC_by_USART.c
 *
 * Created: 5/29/2022 7:05:07 AM
 *  Author: Mohamed Yasser
 */ 

#include "USART.h"
#include "LCD.h"
#include "keypad.h"

volatile char data = '\0';
volatile uint8 row = 1;

int main(void)
{
	char button = NOTPRESSED;
	LCD_init();
	keypad_init();
	USART_init();
	
	while(1)
	{
		button = keypad_check_press();
		if (NOTPRESSED != button)
		{
			LCD_send_character(button);
			USART_send_char(button);
			_delay_ms(250);
		}
		
		
	}
	
}

ISR(USART_RXC_vect)
{
	if (5 == row)
	{
		row = 1;
		LCD_clear_screen();
	}
	else
	{
		LCD_move_cursor(row,1);
	}
	data = USART_receive_char();
	while((char)'#' != (char)data)
	{
		LCD_send_character(data);
		data = USART_receive_char();
	}
	++row;
}