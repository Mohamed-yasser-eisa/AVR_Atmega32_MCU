/*
 * _3_toggle_leds_in_different_time.c
 *
 * Created: 5/8/2022 4:06:06 PM
 *  Author: Mohamed Yasser
 */ 

/*********************************************************************
* Toggle LED on PIN 0 every 1 sec, and LED on PIN 1 every 2 sec.
*********************************************************************/


/*------------------- macros section: -------------------------*/
#define F_CPU 8000000UL
/*============================ end ==============================*/

/*------------------- includes section: -------------------------*/
#include "led.h"
#include <util/delay.h>
/*============================ end ==============================*/

int main(void)
{
	uint8 number = 0;
	LED_init('A', 0);
	LED_init('A', 1);
	
    while(1)
    {
        if ( 1 == (number % 2) ) // If number of seconds is odd, then toggle first LED.
        {
			LED_toggle('A', 0);
			_delay_ms(1000);
        }
		else // If number of seconds is not odd, then toggle both LEDs.
		{
			LED_toggle('A', 0);
			LED_toggle('A', 1);
			_delay_ms(1000);
		}
		++number;		
    }
}