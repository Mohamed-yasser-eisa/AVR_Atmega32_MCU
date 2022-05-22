/*
 * LM35.h
 *
 * Created: 5/22/2022 11:52:49 PM
 *  Author: Mohamed Yasser
 */ 


#ifndef LM35_H_
#define LM35_H_

#include "Atmega_GPIO.h"
#include "ADC.h"

/*
function name: LM35_init
function arguments: (void)
function return: void
function description: It initializes the ADC pin for LM35 sensor
*/
void LM35_init(void);

/*
function name: LM35_read_temp
function arguments: (char port_name, uint8 pin_number)
function return: float32
function description: It reads ADC value of the LM35 pin and map it to temperature
*/
uint16 LM35_read_temp(void);



#endif /* LM35_H_ */