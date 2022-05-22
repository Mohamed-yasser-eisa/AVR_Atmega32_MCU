/*
 * _21_control_10_LEDs_using_analog_input_ADC.c
 *
 * Created: 5/22/2022 7:23:08 PM
 *  Author: Mohamed Yasser
 */ 

#define F_CPU 8000000UL
#include "led.h"
#include "ADC.h"


int main(void)
{
	uint8 i = 0;
	uint16 ADC_DATA = 0;
	for (i=0; i<8; ++i)
	{
		LED_init('C',i);
	}
	for (i=0; i<2; ++i)
	{
		LED_init('D',i);
	}
	ADC_init();
	
	
    while(1)
    {
        ADC_DATA = ADC_convert_read();
		for (i=0; i<8; ++i)
		{
			if ( 1 == READ_BIT(ADC_DATA,i)  )
			{
				LED_turn_on('C', i);
			}
			else
			{
				LED_turn_off('C', i);
			}
		}
		for (i=8; i<10; ++i)
		{
			if ( 1 == READ_BIT(ADC_DATA,i)  )
			{
				LED_turn_on('D', i-8);
			}
			else
			{
				LED_turn_off('D', i-8);
			}
		}
    }
}