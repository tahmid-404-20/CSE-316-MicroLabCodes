/*
 * GccApplication2.c
 *
 * Created: 1/10/2023 11:42:20 AM
 * Author : User
 */ 

#include <avr/io.h>

#ifndef F_CPU
#define F_CPU 1000000UL
#endif // F_CPU

#include<avr/io.h>
#include<util/delay.h>

int main(void)
{	
	DDRA = 0b11111111;
	DDRB = 0b11111111;
	unsigned char all = 0b00000000;
	unsigned char column[] = {0b00000001, 0b00000010, 0b00000100, 0b00001000, 0b00010000, 0b00100000, 0b01000000, 0b10000000};
    /* Replace with your application code */
	int i=0;
	PORTB = ~all;
    while (1) 
    {
		PORTA = ~column[i];
		i = (i+1) % 8;
		_delay_ms(5);
    }
}

