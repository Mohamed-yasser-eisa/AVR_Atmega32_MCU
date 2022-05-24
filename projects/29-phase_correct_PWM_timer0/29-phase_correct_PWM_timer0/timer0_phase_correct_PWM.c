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
	/*set OC0 pin as output*/
	GPIO_pin_direction('B',3,1);
	/*set timer0 to phase correct PWM mode*/
	SET_BIT(TCCR0, WGM00);
	CLR_BIT(TCCR0, WGM01);
	/*set mode of OC0 to non-inverting mode*/
	SET_BIT(TCCR0, COM00);
	SET_BIT(TCCR0, COM01);
}

void timer0_phase_correct_PWM_set(uint16 duty_cycle)
{
	duty_cycle = (((float)duty_cycle/1023)*100.00);
	OCR0 = (uint8)(((uint64)duty_cycle*255)/100);
}

