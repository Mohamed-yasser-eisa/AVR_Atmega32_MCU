/*
 * _13_measure_execution_time_of_ISR.c
 *
 * Created: 5/17/2022 12:21:22 PM
 *  Author: Mohamed Yasser
 */ 


/*************************************
*light up an LED connected to port 'D' using push button.
*use interrupt to read button press.
*If button is pressed then turn on LED for 1 sec.
*otherwise turn off LED.
*measure execution time of ISR using oscilloscope
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
	
	sei(); //enable I-bit
	CLR_BIT(MCUCR,ISC2); //set interrupt to low edge trigger
	SET_BIT(GICR,INT2); //enable interrupt on pin INT2
	
    while(1)
    {
        
    }
}

ISR(INT2_vect)
{
	LED_turn_on('D',0);
	_delay_ms(1000);
	LED_turn_off('D',0);
}