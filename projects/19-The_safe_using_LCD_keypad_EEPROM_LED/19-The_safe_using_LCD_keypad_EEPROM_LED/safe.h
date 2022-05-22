/*
 * safe.h
 *
 * Created: 5/20/2022 3:15:55 PM
 *  Author: Mohamed Yasser
 */ 


#ifndef SAFE_H_
#define SAFE_H_

/*************** Include section *******************/
#include "LCD.h"
#include "keypad.h"
#include "internalEEPROM.h"
#include "led.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*=================== end ========================*/

/*
function name: safe_pass_status
function arguments: (uint16 address)
function return: uint8
function description: Reads value in the given address, returns '0' (pass set) or '0xff' (pass not set)
*/
uint8 safe_pass_status(uint16 address);

/*
function name: safe_read_pass
function arguments: (uint16* address)
function return: uint16
function description: Reads the password from EEPROM and returns the password
*/
uint32 safe_read_pass(uint16* address);

/*
function name: safe_set_pass
function arguments: (uint8* pass, uint16* address)
function return: void
function description: Sets the password and saves it to EEPROM then returns the password to the given array address
*/
void safe_set_pass(uint8* pass, uint16* address, uint16 pass_status);

/*
function name: safe_check_pass
function arguments: (uint16* address)
function return: uint8
function description: Check if password is correct (1) or not correct (0)
*/
uint8 safe_check_pass(uint16* address);


#endif /* SAFE_H_ */