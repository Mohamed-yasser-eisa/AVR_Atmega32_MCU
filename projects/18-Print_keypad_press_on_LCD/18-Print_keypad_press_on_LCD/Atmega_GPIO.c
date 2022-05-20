#include "Atmega_GPIO.h"

void GPIO_pin_direction(char PORT, uint8 BIT, uint8 DIR)
{
    switch(PORT)
    {
        case 'A':
        case 'a':
            if(1 == DIR)
            {
                SET_BIT(DDRA, BIT); //set direction of this pin in port A as output
            }
            else
            {
                CLR_BIT(DDRA, BIT); //set direction of this pin in port A as input
            }
        break;
        case 'B':
        case 'b':
            if(1 == DIR)
            {
                SET_BIT(DDRB, BIT); //set direction of this pin in port B as output
            }
            else
            {
                CLR_BIT(DDRB, BIT); //set direction of this pin in port B as input
            }
        break;
        case 'C':
        case 'c':
            if(1 == DIR)
            {
                SET_BIT(DDRC, BIT); //set direction of this pin in port B as output
            }
            else
            {
                CLR_BIT(DDRC, BIT); //set direction of this pin in port B as input
            }
        break;
        case 'D':
        case 'd':
            if(1 == DIR)
            {
                SET_BIT(DDRD, BIT); //set direction of this pin in port C as output
            }
            else
            {
                CLR_BIT(DDRD, BIT); //set direction of this pin in port C as input
            }
        break;
        default:
        break;
    } //end of switch(PORT);
} //end of  GPIO_pin_direction();


void GPIO_pin_write(char PORT, uint8 BIT, uint8 DATA)
{
    switch(PORT)
    {
        case 'A':
        case 'a':
            if(1 == DATA)
            {
                SET_BIT(PORTA, BIT); //set output value of this pin in port A to 1
            }
            else
            {
                CLR_BIT(PORTA, BIT); //set output value of this pin in port A to 0
            }
        break;
        case 'B':
        case 'b':
            if(1 == DATA)
            {
                SET_BIT(PORTB, BIT); //set output value of this pin in port B to 1
            }
            else
            {
                CLR_BIT(PORTB, BIT); //set output value of this pin in port B to 0
            }
        break;
        case 'C':
        case 'c':
            if(1 == DATA)
            {
                SET_BIT(PORTC, BIT); //set output value of this pin in port C to 1
            }
            else
            {
                CLR_BIT(PORTC, BIT); //set output value of this pin in port C to 0
            }
        break;
        case 'D':
        case 'd':
            if(1 == DATA)
            {
                SET_BIT(PORTD, BIT); //set output value of this pin in port C to 1
            }
            else
            {
                CLR_BIT(PORTD, BIT); //set output value of this pin in port C to 0
            }
        break;
        default:
        break;
    } //end of switch(PORT);
} // end of GPIO_pin_write();


uint8 GPIO_pin_read(char PORT, uint8 BIT)
{
    uint8 read_value = 0;
    switch(PORT)
    {
        case 'A':
        case 'a':
            read_value = READ_BIT(PINA, BIT); //read value of given pin in port A
        break;
        case 'B':
        case 'b':
            read_value = READ_BIT(PINB, BIT); //read value of given pin in port B
        break;
        case 'C':
        case 'c':
            read_value = READ_BIT(PINC, BIT); //read value of given pin in port C
        break;
        case 'D':
        case 'd':
            read_value = READ_BIT(PIND, BIT); //read value of given pin in port D
        break;
        default:
        break;
    } //end of switch(PORT);
    return read_value;
} // end of GPIO_pin_read();


void GPIO_pin_toggle(char PORT, uint8 BIT)
{
    switch(PORT)
    {
        case 'A':
        case 'a':
            TOG_BIT(PORTA, BIT); //toggle value of given pin in port A
        break;
        case 'B':
        case 'b':
            TOG_BIT(PORTB, BIT); //toggle value of given pin in port B
        break;
        case 'C':
        case 'c':
            TOG_BIT(PORTC, BIT); //toggle value of given pin in port C
        break;
        case 'D':
        case 'd':
            TOG_BIT(PORTD, BIT); //toggle value of given pin in port D
        break;
        default:
        break;
    } //end of switch(PORT);
} // end of GPIO_pin_toggle();


void GPIO_port_direction(char PORT, uint8 DIR)
{
    switch(PORT)
    {
        case 'A':
        case 'a':
            DDRA = DIR; // set direction of port A to the given DIR
        break;
        case 'B':
        case 'b':
            DDRB = DIR; // set direction of port B to the given DIR
        break;
        case 'C':
        case 'c':
            DDRC = DIR; // set direction of port C to the given DIR
        break;
        case 'D':
        case 'd':
            DDRD = DIR; // set direction of port D to the given DIR
        break;
        default:
        break;
    } // end of switch(PORT);
} // end of GPIO_port_direction();


void GPIO_port_write(char PORT, uint8 DATA)
{
    switch(PORT)
    {
        case 'A':
        case 'a':
            PORTA = DATA; // write these data on port A
        break;
        case 'B':
        case 'b':
            PORTB = DATA; // write these data on port B
        break;
        case 'C':
        case 'c':
            PORTC = DATA; // write these data on port C
        break;
        case 'D':
        case 'd':
            PORTD = DATA; // write these data on port D
        break;
        default:
        break;
    } // end of switch(PORT);
} // end of GPIO_port_write();


uint8 GPIO_port_read(char PORT)
{
    uint8 read_port = 0;
    switch(PORT)
    {
        case 'A':
        case 'a':
            read_port = PINA; // read data from port A
        break;
        case 'B':
        case 'b':
            read_port = PINB; // read data from port B
        break;
        case 'C':
        case 'c':
            read_port = PINC; // read data from port C
        break;
        case 'D':
        case 'd':
            read_port = PIND; // read data from port D
        break;
        default:
        break;
    } // end of switch(PORT);
    return read_port;
} // end of GPIO_port_read();


void GPIO_pin_pull_up(char port_name, uint8 pin_number)
{
    switch(port_name)
    {
        case 'A':
        case 'a':
            CLR_BIT(DDRA,pin_number); //set pin_number of port_name as input
            CLR_BIT(SFIOR,PUD); //clear PUD bit in SFIOR register
            SET_BIT(PORTA,pin_number); //set pin_number of port_name as high value
        break;
        case 'B':
        case 'b':
            CLR_BIT(DDRB,pin_number); //set pin_number of port_name as input
            CLR_BIT(SFIOR,PUD); //clear PUD bit in SFIOR register
            SET_BIT(PORTB,pin_number); //set pin_number of port_name as high value
        break;
        case 'C':
        case 'c':
            CLR_BIT(DDRC,pin_number); //set pin_number of port_name as input
            CLR_BIT(SFIOR,PUD); //clear PUD bit in SFIOR register
            SET_BIT(PORTC,pin_number); //set pin_number of port_name as high value
        break;
        case 'D':
        case 'd':
            CLR_BIT(DDRD,pin_number); //set pin_number of port_name as input
            CLR_BIT(SFIOR,PUD); //clear PUD bit in SFIOR register
            SET_BIT(PORTD,pin_number); //set pin_number of port_name as high value
        break;
        default:
        break;
    } // end of switch(port_name);
}



void GPIO_port_write_high_nibble(char port_name, uint8 high_nibble)
{
    high_nibble <<= 4; //clear low_nibble bits in number
    switch(port_name)
    {
        case 'A':
        case 'a':
            PORTA &= 0x0f;
            PORTA |= high_nibble;
        break;
        case 'B':
        case 'b':
            PORTB &= 0x0f;
            PORTB |= high_nibble;
        break;
        case 'C':
        case 'c':
            PORTC &= 0x0f;
            PORTC |= high_nibble;
        break;
        case 'D':
        case 'd':
            PORTD &= 0x0f;
            PORTD |= high_nibble;
        break;
        default:
        break;
    } // end of switch(port_name);
}

void GPIO_port_write_low_nibble(char port_name, uint8 low_nibble)
{
    low_nibble &= 0x0f; //clear high_nibble bits in number
    switch(port_name)
    {
        case 'A':
        case 'a':
            PORTA &= 0xf0;
            PORTA |= low_nibble;
        break;
        case 'B':
        case 'b':
            PORTB &= 0xf0;
            PORTB |= low_nibble;
        break;
        case 'C':
        case 'c':
            PORTC &= 0xf0;
            PORTC |= low_nibble;
        break;
        case 'D':
        case 'd':
            PORTD &= 0xf0;
            PORTD |= low_nibble;
        break;
        default:
        break;
    } // end of switch(port_name);
}