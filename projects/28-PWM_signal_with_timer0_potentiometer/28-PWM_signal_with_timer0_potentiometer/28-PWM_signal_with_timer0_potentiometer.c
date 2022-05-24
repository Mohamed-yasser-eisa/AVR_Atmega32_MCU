/*
 * _28_PWM_signal_with_timer0_potentiometer.c
 *
 * Created: 5/24/2022 5:13:52 PM
 *  Author: Mohamed Yasser
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
#include "timer0_fast_PWM_mode.h"
#include "ADC.h"


int main(void)
{
	uint16 ADC_DATA = 0;
	ADC_init();
	timer0_fast_PWM_init();
   // while(1)
    //{
        ADC_DATA = ADC_convert_read(); 
		set_duty_cycle(ADC_DATA);
		_delay_ms(1000);
    //}
}