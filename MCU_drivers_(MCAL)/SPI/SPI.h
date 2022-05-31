/*
 * SPI.h
 *
 * Created: 5/30/2022 7:39:14 PM
 *  Author: Mohamed Yasser
 */ 


#ifndef SPI_H_
#define SPI_H_

#define SPI_SS 4
#define MOSI 5
#define MISO 6
#define SPI_SCK 7
#define F_CPU 8000000UL

#include <util/delay.h>

#include "Atmega_GPIO.h"

/*
function name: SPI_master_init
function arguments: void
function return: void
function description: It initialize the master SPI mode in MC
*/
void SPI_master_init(void);

/*
function name: SPI_master_transmit
function arguments: (char data)
function return: char
function description: It sends the given char data, and receives 8-bits data throughout SPI protocol
*/
char SPI_master_transmit(char data);

/*
function name: SPI_master_transmit_string
function arguments: (char* data)
function return: void
function description: It sends the given string throughout SPI protocol
*/
void SPI_master_transmit_string(char* data);

/*
function name: SPI_slave_init
function arguments: void
function return: void
function description: It initialize the slave SPI mode in MC
*/
void SPI_slave_init(void);

/*
function name: SPI_slave_receive
function arguments: (char data)
function return: char
function description: It returns the a char data, and sends a char data throughout SPI protocol
*/
char SPI_slave_receive(char data);

#endif /* SPI_H_ */