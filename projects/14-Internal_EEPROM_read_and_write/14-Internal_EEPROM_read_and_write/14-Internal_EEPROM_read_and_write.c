/*
 * _14_Internal_EEPROM_read_and_write.c
 *
 * Created: 5/18/2022 12:12:29 PM
 *  Author: Mohamed Yasser
 */ 


/*************************************
*write 8 bit data to internal EEPROM, and read it again.
*if data are read correctly, turn on LED for 2 seconds ,then turn off LED.
*************************************/

/*------------------- macros section: -------------------------*/
#define F_CPU 8000000UL
/*============================ end ==============================*/

/*------------------- includes section: -------------------------*/
#include "internalEEPROM.h"
#include "led.h"
#include <util/delay.h>
/*============================ end ==============================*/

int main(void)
{
	uint8 EEPROM_data = 0;
	LED_init('C',5);
	EEPROM_write(0x30, 0x50);
	EEPROM_data = EEPROM_read(0x30);
    while(1)
    {
		
        if (0x50 == EEPROM_data)
        {
			LED_turn_on('C',5);
			_delay_ms(2000);
			LED_turn_off('c',5);
			_delay_ms(2000);
        }
    }
}