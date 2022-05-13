/*
 * _6_toggle_led_with_button_press.c
 *
 * Created: 5/8/2022 5:49:35 AM
 *  Author: Mohamed Yasser
 */ 


/*************************************
*toggle an LED on pin 2 port 'D' if button on pin 1,
*port 'A' is pushed.
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
	        _delay_ms(100); //software solution for switch bouncing
	        if ( !Button_read('A', 1) )
	        {
		        LED_toggle('D', 2);
	        }
        }
		else
		{
			//for MISRA-C rules
		} 
    }
}