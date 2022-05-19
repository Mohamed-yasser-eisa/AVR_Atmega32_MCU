

#ifndef INTERNALEEPROM_H_
#define INTERNALEEPROM_H_

#include "std_macros.h"
#include "typedef.h"
#include <avr/io.h>

/*
function name: EEPROM_write
function arguments: (uint16 address, uint8 data)
function return: void
function description: It writes 8-bit data to the given address in internal EEPROM
*/
void EEPROM_write(uint16 address, uint8 data);


/*
function name: EEPROM_read
function arguments: (uint16 address)
function return: uint8
function description: It reads 8-bit data from the given address in internal EEPROM
*/
uint8 EEPROM_read(uint16 address);


#endif /* INTERNALEEPROM_H_ */