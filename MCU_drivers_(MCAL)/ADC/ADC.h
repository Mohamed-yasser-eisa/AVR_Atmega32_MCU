/*
 * ADC.h
 *
 * Created: 5/22/2022 7:36:04 PM
 *  Author: Mohamed Yasser
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "Atmega_GPIO.h"

void ADC_init(void);

uint16 ADC_convert_read(void);


#endif /* ADC_H_ */