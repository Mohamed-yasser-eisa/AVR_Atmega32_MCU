/*
 * timer0_fast_PWM_mode.c
 *
 * Created: 5/24/2022 5:15:33 PM
 *  Author: Mohamed Yasser
 */ 
#include "timer0_fast_PWM_mode.h"

void timer0_fast_PWM_init(void)
{
	/*set OC0 pin as output*/
	GPIO_pin_direction('B',3,1);
	/*load initial value in (OCR0 = 128) */
	OCR0 = 128;
	/*set timer0 to fast PWM mode*/
	TCCR0 |= (1<<WGM00);
	SET_BIT(TCCR0, WGM01);
	/*set clock of timer0*/
	TCCR0 |= (1<<CS00);
	TCCR0 &= (~(1<<CS01));
	TCCR0 |= (1<<CS02);
	/*set mode of OC0 to inverting mode*/
	SET_BIT(TCCR0, COM00);
	SET_BIT(TCCR0, COM01);
}

void set_duty_cycle(uint16 duty_cycle)
{
	duty_cycle = ((uint64)duty_cycle*25)/256;
	OCR0 = (uint8)(((uint64)duty_cycle*51)/2000);
}
