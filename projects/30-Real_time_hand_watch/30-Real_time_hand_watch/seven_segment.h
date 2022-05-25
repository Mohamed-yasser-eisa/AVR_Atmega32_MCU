#ifndef __SEVEN_SEGMENT_HEADER__
#define __SEVEN_SEGMENT_HEADER__


/*******************************************************************************
*@file: seven_segment.h
*@author: Mohamed Yasser
*@brief: driver for seven segment display
*@How_to_use?
*   1- configer port direction using (DDRx) register. (1 for output, 0 for input).
*   2- use (PORTx) register to output data on port.
*   3- use (PINx) register to read data on port.
*******************************************************************************/


/*------------------- includes section: -------------------------*/
#include "Atmega_GPIO.h"
/*============================ end ==============================*/


/*------------------- functions prototypes: -------------------------*/


/*
function name: Seven_segment_init();
function return: void
function arguments: (char port_name, uint8 DP_pin)
function description: initialize selected port name as output to connect seven-segment display to it.
*/
void Seven_segment_init(char port_name, uint8 DP_pin);


/*
function name: Seven_seg_BCD_init();
function return: void
function arguments: (char port_name)
function description: initialize selected port name as output to connect seven-segment display to it.
*/
void Seven_seg_BCD_init(char port_name);



/*
function name: Seven_seg_BCD_write();
function return: void
function arguments: (char port_name, uint8 number, uint8 DP_pin)
function description: it writes the given number on BCD seven segment display. The "DP" is for doit point
*/
void Seven_seg_BCD_write(char port_name, uint8 number);



/*
function name: Seven_segment_write();
function return: void
function arguments: (char port_name, uint8 number, uint8 DP_pin,uint8 common_anod)
function description: it writes the given number on seven segment display. The "DP" is for doit point
*/
void Seven_segment_write(char port_name, uint8 number, uint8 DP_pin, uint8 common_anod);

/*
function name: Seven_seg1_write();
function return: void
function arguments: (uint8 number)
function description: it turn on first 7-seg. and turn off others, and print number
*/
void Seven_seg1_write(uint8 number);

/*
function name: Seven_seg2_write();
function return: void
function arguments: (uint8 number)
function description: it turn on second 7-seg. and turn off others, and print number
*/
void Seven_seg2_write(uint8 number);

/*
function name: Seven_seg3_write();
function return: void
function arguments: (uint8 number)
function description: it turn on third 7-seg. and turn off others, and print number
*/
void Seven_seg3_write(uint8 number);

/*
function name: Seven_seg4_write();
function return: void
function arguments: (uint8 number)
function description: it turn on forth 7-seg. and turn off others, and print number
*/
void Seven_seg4_write(uint8 number);

/*
function name: Seven_seg5_write();
function return: void
function arguments: (uint8 number)
function description: it turn on fifth 7-seg. and turn off others, and print number
*/
void Seven_seg5_write(uint8 number);

/*
function name: Seven_seg6_write();
function return: void
function arguments: (uint8 number)
function description: it turn on sixth 7-seg. and turn off others, and print number
*/
void Seven_seg6_write(uint8 number);

/*============================ end ==============================*/



#endif //__SEVEN_SEGMENT_HEADER__