/*
 * timer0_overflow_mode.c
 *
 * Created: 5/23/2022 11:07:07 AM
 *  Author: Mohamed Yasser
 */ 
#include "timer0_overflow_mode.h"

void timer0_overflow_init(void)
{
	/*set F_timer0 = F_CPU/1024 = 8000000/1024 = 7812 Hz*/
	/*tick time = (1024/8000000) = 0.128 mSec.*/
	SET_BIT(TCCR0, CS00);
	CLR_BIT(TCCR0, CS01);
	SET_BIT(TCCR0, CS02);
	/*set timer0 mode to overflow mode*/
	CLR_BIT(TCCR0, WGM00);
	CLR_BIT(TCCR0, WGM01);
	/*enable interrupt of overflow mode*/
	sei(); //enable I-bit
	SET_BIT(TIMSK, TOIE0); //enable bit of timer0 overflow
}

void timer0_TCNT0_value(uint8 val)
{
	TCNT0 = val;
}