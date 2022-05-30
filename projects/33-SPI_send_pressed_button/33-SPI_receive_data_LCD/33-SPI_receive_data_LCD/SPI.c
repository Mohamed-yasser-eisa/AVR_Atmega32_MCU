/*
 * SPI.c
 *
 * Created: 5/30/2022 7:39:01 PM
 *  Author: Mohamed Yasser
 */ 
#include "SPI.h"

void SPI_master_init(void)
{
	/*set MOSI and SCK pins as output pins*/
	DDRB |= (1 << MOSI) | (1 << SPI_SCK) | (1 << SPI_SS);
	/*set MISO as input pins*/
	DDRB &= (~(1 << MISO));
	/*enable master mode, and SCK clock to (F_CPU/16)*/
	SPCR |= (1 << SPE) | (1 << MSTR) | (1 << SPR0);
	/*write high to SS*/
	PORTB |= (1 << SPI_SS);
}


char SPI_master_transmit(char data)
{
	char received;
	/*clear SPI_SS pin to start slave receive*/
	PORTB &= (~(1 << SPI_SS));
	/*write the given data to SPI data register to start transmission*/
	SPDR = data;
	/*wait 8-clock cycles until SPI transmission finished*/
	while( ! ((SPSR >> SPIF) & 1) )
	{
		//wait
	}
	received = SPDR;
	/*write high to SS*/
	PORTB |= (1 << SPI_SS);
	return received;
}


void SPI_master_transmit_string(char* data)
{
	while('\0' != (*data) )
	{
		SPI_master_transmit(*data);
		_delay_ms(300);
		++data;
	}
}


void SPI_slave_init(void)
{
	/*set MISO output pin*/
	DDRB |= (1 << MISO);
	/*enable slave mode of SPI*/
	SPCR |= (1 << SPE);
}


char SPI_slave_receive(char data)
{
	char received;
	/*put data to SPI data register, to be shifted*/
	SPDR = data;
	/*wait until data are received*/
	while (! ( (SPSR >> SPIF) & 1 ) )
	{
		//wait for data
	}
	received = SPDR;
	return received;
}