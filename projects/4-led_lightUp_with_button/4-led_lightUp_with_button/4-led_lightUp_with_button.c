/*
 * _4_led_lightUp_with_button.c
 *
 * Created: 5/8/2022 4:50:30 PM
 *  Author: Mohamed Yasser
 */ 

/*************************************
*light up an LED on pin 2 port 'D' as long as button on pin 1,
*port 'A' is pushed, and turn off LED when button is released.
*use pull down resistor with button.
*************************************/

/*------------------- macros section: -------------------------*/
#define F_CPU 8000000UL
/*============================ end ==============================*/

/*------------------- includes section: -------------------------*/
#include "button.h"
#include "led.h"
#include <util/delay.h>
/*============================ end ==============================*/

int main(void)
{
	LED_init('D', 2);
	Button_init('A', 1);
	
    while(1)
    {
        if ( Button_read('A', 1) )
        {
			_delay_ms(30); //software solution for switch bouncing
			if ( Button_read('A', 1) )
			{
				LED_turn_on('D', 2);
			}
        }
		else //you MUST use else{}, other wise you won't notice the led turning on
		{
			LED_turn_off('D', 2);
		}
		
    }
}