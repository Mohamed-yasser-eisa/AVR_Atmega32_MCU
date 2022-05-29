/*
 * _31_Send_string_through_USART_protocol.c
 *
 * Created: 5/28/2022 10:33:04 PM
 *  Author: Mohamed Yasser
 */ 


#include "USART.h"

int main(void)
{
	USART_init();
	/*send string through USART*/
	USART_send_string("Mohamed Yasser");
}