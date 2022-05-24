/*
 * timer0_phase_correct_PWM.c
 *
 * Created: 5/24/2022 9:52:25 PM
 *  Author: Mohamed Yasser
 */ 
#include "timer0_phase_correct_PWM.h"

void timer0_phase_correct_PWM_init(void)
{
	/*set timer clock*/
	SET_BIT(TCCR0, CS00);
	CLR_BIT(TCCR0, CS01);
	SET_BIT(TCCR0, CS02);
	/**/
	
}

void timer0_phase_correct_PWM_set(uint16 duty_cycle);

