/*
 * LM35.c
 *
 * Created: 5/22/2022 11:52:32 PM
 *  Author: Mohamed Yasser
 */ 
#include "LM35.h"


void LM35_init(void)
{
	ADC_init();
}


uint16 LM35_read_temp(void)
{
	uint16 temp = 0;
	temp = ADC_convert_read();
	temp = (temp*0.25);
	return temp;	
}