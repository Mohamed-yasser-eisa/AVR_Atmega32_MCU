/*
 * _12_nested_interrupt_buttons_LEDs_7_segment.c
 *
 * Created: 5/16/2022 11:10:41 PM
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
#include "seven_segment.h"
#include <avr/interrupt.h>
#include <util/delay.h>
/*============================ end ==============================*/

/*------------------- global variables: -------------------------*/
volatile uint8 counter1;
volatile uint8 counter2;
/*============================ end ==============================*/

int main(void)
{
	/*initialize the components: */
	Seven_segment_init('C',0);
	Seven_segment_init('A',0);
	Button_init_with_internal_pull_up('B',2);
	Button_init_with_internal_pull_up('D',2);
	Button_init_with_internal_pull_up('D',3);
	LED_init('B',1);
	
	/*initialize interrupts:*/
	sei(); //enable interrupts.
	
	/*set mode of interrupt for each button to falling edge*/
	SET_BIT(MCUCR,ISC01);
	CLR_BIT(MCUCR,ISC00);
	
	SET_BIT(MCUCR,ISC11);
	CLR_BIT(MCUCR,ISC10);
	
	CLR_BIT(MCUCR,ISC2);
	
	/*enable the interrupt bit of each source of interrupt:*/
	SET_BIT(GICR,INT0);
	SET_BIT(GICR,INT1);
	SET_BIT(GICR,INT2);
	
    while(1)
    {
		LED_turn_off('B',1);
        Seven_segment_write('A', 0,0,1);
		Seven_segment_write('C', 0,0,0);
    }
}

ISR(INT0_vect)
{
	sei();
	LED_turn_on('B',1);
	_delay_ms(2000);
}

ISR(INT1_vect)
{
	sei();
	++counter1;
	Seven_segment_write('C', counter1 % 10,0,0);
	_delay_ms(2000);
}

ISR(INT2_vect)
{
	sei();
	++counter2;
	Seven_segment_write('A', counter2 % 10,0,1);
	_delay_ms(2000);
}