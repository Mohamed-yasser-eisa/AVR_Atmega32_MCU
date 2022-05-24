#include "seven_segment.h"

void Seven_segment_init(char port_name, uint8 DP_pin)
{
    if(1 == DP_pin)
    {
        GPIO_port_direction(port_name, 0xff); //initialize port_name as output pins with "DP" pin
    }
    else
    {
        uint8 counter = 0;
        for(counter=0; counter<7; ++counter)
        {
            GPIO_pin_direction(port_name,counter,1);
        }
    }
}


void Seven_seg_BCD_init(char port_name)
{
    uint8 counter = 0;
        for(counter=0; counter<4; ++counter)
        {
            GPIO_pin_direction(port_name,counter,1);//initialize 4 pins from port_name as output pins
        }
}


void Seven_seg_BCD_write(char port_name, uint8 number)
{
    uint8 cAnode_hex[] = {0x00,0x1,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09}; //{0,1,2,3,4,5,6,7,8,9}
    GPIO_port_write(port_name, cAnode_hex[number]);
}




void Seven_segment_write(char port_name, uint8 number, uint8 DP_pin, uint8 common_anod)
{
    if(1 == common_anod) //Is the connected display a common anode?
    {
        uint8 cAnode_hex[] = {0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x38,0x00,0x10,0x08,0x00,0x46,0x40,0x06,0x0e}; //{0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F}
        if(1 == DP_pin) //turn on the digit LED
        {
            number = ( (cAnode_hex[number]) & (~(1<<7)) );
        }
        else
        {
            number = ( (cAnode_hex[number]) | (1<<7) );
        }
        GPIO_port_write(port_name, number);
    }
    else
    {
        uint8 cCathode_hex[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x47,0x7f,0x6f,0x77,0x7f,0x39,0x3f,0x79,0x71}; //{0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F}
        if(1 == DP_pin) //turn on the digit LED
        {
            number = ( (cCathode_hex[number]) | (DP_pin<<7) );
        }
        else
        {
            number = cCathode_hex[number];
        }
        GPIO_port_write(port_name, number);
    }
}



