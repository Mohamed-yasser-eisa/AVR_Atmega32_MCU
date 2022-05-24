/*
 * timer0_CTC_mode.c
 *
 * Created: 5/23/2022 7:03:21 PM
 *  Author: Mohamed Yasser
 */ 
#include "timer0_CTC_mode.h"

void timer0_ctc_init(void)
{
	/*set timer0 mode to CTC mode*/
	CLR_BIT(TCCR0, WGM00);
	SET_BIT(TCCR0, WGM01);
	/*set OCR register value to (252) so after this counts for (31) times, one sec will be evaluated*/
	OCR0 = 252;
	/*set F_timer0 = F_CPU/1024 = 8000000/1024 = 7812 Hz*/
	/*tick time = (1024/8000000) = 0.128 mSec.*/
	SET_BIT(TCCR0, CS00);
	CLR_BIT(TCCR0, CS01);
	SET_BIT(TCCR0, CS02);
	/*enable interrupt of CTC mode*/
	sei(); //enable I-bit
	SET_BIT(TIMSK, OCIE0); //enable bit of timer0 CTC interrupt
}