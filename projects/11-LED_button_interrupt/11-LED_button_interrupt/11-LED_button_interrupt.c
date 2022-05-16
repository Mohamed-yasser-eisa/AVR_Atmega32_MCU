/*
 * _11_LED_button_interrupt.c
 *
 * Created: 5/16/2022 10:33:08 PM
 *  Author: Mohamed Yasser
 */ 


/*************************************
*light up an LED connected to port 'D' using push button.
*use interrupt to read button press.
*If button is pressed then turn on LED for 1 sec.
*otherwise turn off LED.
*************************************/

/*------------------- macros section: -------------------------*/
#define F_CPU 8000000UL
/*============================ end ==============================*/

/*------------------- includes section: -------------------------*/
#include "button.h"
#include "led.h"
#include <avr/interrupt.h>
#include <util/delay.h>
/*============================ end ==============================*/

int main(void)
{
	LED_init('D',0);
	Button_init_with_internal_pull_up('B',2);
	
	sei(); //set the global interrupt bit (I-bit).
	CLR_BIT(MCUCSR,ISC2); //set interrupt mode to falling edge.
	SET_BIT(GICR,INT2); //enable interrupt on pin INT2
	
    while(1)
    {
		LED_turn_off('d',0); 
    }
}

ISR(INT2_vect)
{
	LED_turn_on('D',0);
	_delay_ms(1000);
}