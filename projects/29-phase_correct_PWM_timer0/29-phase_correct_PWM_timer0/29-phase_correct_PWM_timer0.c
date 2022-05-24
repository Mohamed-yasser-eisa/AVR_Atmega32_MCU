/*
 * _29_phase_correct_PWM_timer0.c
 *
 * Created: 5/24/2022 9:49:47 PM
 *  Author: Mohamed Yasser
 */ 


#include "timer0_phase_correct_PWM.h"
#include "ADC.h"


int main(void)
{
    uint16 ADC_DATA = 0;
    ADC_init();
    timer0_phase_correct_PWM_init();
    while(1)
    {
	    ADC_DATA = ADC_convert_read();
	    timer0_phase_correct_PWM_set(ADC_DATA);
    }
}