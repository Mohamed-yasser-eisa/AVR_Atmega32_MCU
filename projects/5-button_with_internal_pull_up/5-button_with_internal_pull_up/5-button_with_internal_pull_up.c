/*
 * _5_button_with_internal_pull_up.c
 *
 * Created: 5/8/2022 5:37:41 AM
 *  Author: Mohamed Yasser
 */ 


/*************************************
*light up an LED on pin 2 port 'D' as long as button on pin 1,
*port 'A' is pushed, and turn off LED when button is released.
*use internal pull up resistor with button.
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
	Button_init_with_internal_pull_up('A', 1);
	LED_init('D', 2);
	
    while(1) 
    {
        if ( !Button_read('A', 1) )
        {
	        _delay_ms(30); //software solution for switch bouncing
	        if ( !Button_read('A', 1) )
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