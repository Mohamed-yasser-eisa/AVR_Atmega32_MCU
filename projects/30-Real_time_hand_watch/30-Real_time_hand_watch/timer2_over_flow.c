/*
 * timer2_over_flow.c
 *
 * Created: 5/24/2022 11:20:49 PM
 *  Author: Mohamed Yasser
 */ 
#include "timer2_over_flow.h"

void timer2_overflow_init(void)
{
	/*set timer2 mode to overflow mode*/ 
	/*it is the default mode*/
	CLR_BIT(TCCR2, WGM20);
	CLR_BIT(TCCR2, WGM21);
	/*set pre-scaler to 128*/
	SET_BIT(TCCR2, CS20);
	CLR_BIT(TCCR2, CS21);
	SET_BIT(TCCR2, CS22);
	/*select clock source to external clock on (TOSC1) */
	SET_BIT(ASSR, AS2);
	/*enable overflow interrupt for timer2*/
	sei();
	SET_BIT(TIMSK, TOIE2);
}