/*
 * USART_config.h
 *
 * Created: 5/29/2022 12:56:18 AM
 *  Author: Mohamed Yasser
 */ 


#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_

/************* select mode of operation of USART ******************/
#define F_CPU 8000000UL
#define USART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU/(USART_BAUDRATE*16UL)))-1)
#define USART_asynchronous_mode

//#define USART_synchronous_mode

/*=========================== end ==============================*/

#endif /* USART_CONFIG_H_ */