/*
 * _33_SPI_receive_data_LCD.c
 *
 * Created: 5/30/2022 7:59:38 PM
 *  Author: Mohamed Yasser
 */ 


#include "SPI.h"
#include "LCD.h"

int main(void)
{
	char data = '\0';
	LCD_init();
	SPI_slave_init();
    while(1)
    {
        data = SPI_slave_receive(0xff);
		LCD_send_character(data);
    }
}