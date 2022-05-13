/*
 * _1_toggle_8_leds_on_port.c
 *
 * Created: 5/8/2022 6:41:33 AM
 *  Author: Mohamed Yasser
 */ 


/*------------------- macros section: -------------------------*/
#define F_CPU 8000000UL
/*============================ end ==============================*/

/*------------------- includes section: -------------------------*/
#include "Atmega_GPIO.h"
#include <util/delay.h>
/*============================ end ==============================*/

int main(void)
{
	GPIO_port_direction('a',0xff); // set port direction to output
    while(1)
    {
        GPIO_port_write('a', 0xff); //turn on all LEDs
		_delay_ms(1000); //wait for 1 sec
		GPIO_port_write('a', 0x00); //turn off all LEDs
		_delay_ms(1000); //wait for 1 sec
    }
}