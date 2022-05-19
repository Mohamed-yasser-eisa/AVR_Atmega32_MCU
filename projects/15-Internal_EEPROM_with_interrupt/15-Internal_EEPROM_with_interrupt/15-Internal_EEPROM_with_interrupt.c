/*
 * _15_Internal_EEPROM_with_interrupt.c
 *
 * Created: 5/18/2022 1:04:55 PM
 *  Author: Mohamed Yasser
 */ 


/*************************************
*turn on LED using interrupt of EEPROM.
*when the data are written successfully to EEPROM, it will generate an interrupt.
*************************************/

/*------------------- macros section: -------------------------*/
#define F_CPU 8000000UL
/*============================ end ==============================*/

/*------------------- includes section: -------------------------*/
#include "internalEEPROM.h"
#include "led.h"
#include <util/delay.h>
#include <avr/interrupt.h>
/*============================ end ==============================*/

int main(void)
{
	uint8 data = 0;
	/*initialize the LED*/
	LED_init('C',5);
	/*initialize interrupt*/
	sei(); // set I-bit.
	SET_BIT(EECR,EERIE); //set interrupt enable bit for EEPROM write.
	/*write data to EEPROM*/
	EEPROM_write(0x80,0x95);
	data = EEPROM_read(0x80);
    while(1)
    {
        LED_turn_off('C',5);
    }
}

ISR(EE_RDY_vect)
{
	LED_turn_on('C',5);
	_delay_ms(2000);
	CLR_BIT(EECR,EERIE); //clear the interrupt enable bit of EEPROM, because it will continuously generate interrupt.
}