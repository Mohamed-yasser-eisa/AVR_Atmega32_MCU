/*
 * ADC.c
 *
 * Created: 5/22/2022 7:35:53 PM
 *  Author: Mohamed Yasser
 */ 

#include "ADC.h"

void ADC_init(void)
{
	/*enable ADC peripheral in MCU*/
	SET_BIT(ADCSRA, ADEN);
	/*set reference voltage of AVCC with external capacitor at AREE pin*/
	SET_BIT(ADMUX, REFS0);
	CLR_BIT(ADMUX, REFS1);
	/*select input channel to pin PA2*/
	CLR_BIT(ADMUX, MUX0);
	SET_BIT(ADMUX, MUX1);
	CLR_BIT(ADMUX, MUX2);
	CLR_BIT(ADMUX, MUX3);
	CLR_BIT(ADMUX, MUX4);
	/*clear ADLAR bit, so the first 8-bits will return in ADCL, and last 2-bits in ADCH*/
	CLR_BIT(ADMUX, ADLAR);
	/*clear AUTO trigger ADC, so the ADC conversion will start only when you call:  ADC_convert_read() */
	CLR_BIT(ADCSRA, ADATE);
	/*disable ADC interrupt: */
	CLR_BIT(ADCSRA, ADIE);
	/*set pre-scaler to be: (F_CPU/64) = (8000000/64) = 125 KHz */
	CLR_BIT(ADCSRA, ADPS0);
	SET_BIT(ADCSRA, ADPS1);
	SET_BIT(ADCSRA, ADPS2);
}

uint16 ADC_convert_read(void)
{
	uint16 ADC_data = 0;
	/*start conversion:*/
	SET_BIT(ADCSRA, ADSC);
	/*wait until conversion ended*/
	while(READ_BIT(ADCSRA, ADSC) == 1)
	{
		//wait until ADSC bit becomes zero
	}
	/*after conversion is finished, read data from ADCL then ADCH*/
	ADC_data = ADCL;
	ADC_data |= (ADCH << 8);
	/*return ADC data*/
	return ADC_data;
	
}