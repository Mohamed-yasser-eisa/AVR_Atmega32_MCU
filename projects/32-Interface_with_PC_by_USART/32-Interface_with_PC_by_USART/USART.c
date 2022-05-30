/*
 * USART.c
 *
 * Created: 5/28/2022 10:57:08 PM
 *  Author: Mohamed Yasser
 */ 
#include "USART.h"

#if defined USART_asynchronous_mode

void USART_init(void)
{
	/*enable TX and RX for USART*/
	UCSRB |= (1 << TXEN) | (1 << RXEN);
	/*configure 8-bits character size*/
	UCSRC |= (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
	/*set baud rate of USART*/
	UBRRL = (char)BAUD_PRESCALE;
	UBRRH = (char)(BAUD_PRESCALE >> 8);
	/*initialize interrupt*/
	sei();
	SET_BIT(UCSRB, RXCIE);
}


void USART_send_char(char character)
{
	/*wait until UDR (data buffer register) be empty*/
	while (!READ_BIT(UCSRA,UDRE))
	{
		//wait until empty buffer becomes 1;
	}
	/*now write your data to UDR register*/
	UDR = character;
}


void USART_send_string(char* string)
{
	/*call USART_send_char, until you reach end of string*/
	while (*string != '\0')
	{
		USART_send_char(*string);
		++string;
	}
}


char USART_receive_char(void)
{
	char data;
	while(!READ_BIT(UCSRA,RXC))
	{
		//wait until RXC becomes one;
	}
	/*read 8-bit data from UDR register*/
	data = UDR;
	return data;
}

#elif defined USART_synchronous_mode

#endif