/*
 * USART.h
 *
 * Created: 5/28/2022 10:57:19 PM
 *  Author: Mohamed Yasser
 */ 


#ifndef USART_H_
#define USART_H_


#include "USART_config.h"
#include "Atmega_GPIO.h"

#if defined USART_asynchronous_mode

/*
function name: USART_init
function arguments: (void)
function return: void
function description: It initialize USART in Asynchronous mode.
*/
void USART_init(void);

/*
function name: USART_send_char
function arguments: (char character)
function return: void
function description: It sends the given character through USART in Asynchronous mode.
*/
void USART_send_char(char character);

/*
function name: USART_send_string
function arguments: (char* string)
function return: void
function description: It sends the given string through USART in Asynchronous mode.
*/
void USART_send_string(char* string);

/*
function name: USART_receive_char
function arguments: (void)
function return: char
function description: It read a character from UDR (RXB) receive data register.
*/
char USART_receive_char(void);

#elif defined USART_synchronous_mode

#endif



#endif /* USART_H_ */