/*
 * GccApplication1.c
 *
 * Created: 1/10/2023 11:23:30 AM
 * Author : User
 */ 

#ifndef F_CPU
#define F_CPU 1000000UL
#endif // F_CPU

#include<avr/io.h>
#include<util/delay.h>
#include"LED.h"

void drift(unsigned char *arr, int slen)
{
	unsigned char a = arr[0];
	for(int i=0; i<slen-1; i++){
		arr[i] = arr[i+1];
	}
	arr[slen-1] = a;
}

int main()
{
	DDRA = 0b11111111;
	DDRB = 0b11111111;
	DDRD = 0b00000000;
	invert = 0b11111111;
	unsigned char* row = loadArr((unsigned char*)"CSE ");
	//unsigned char row[8] = {0b11111111, 0b11111111, 0b01000110, 0b11110110, 0b11110110, 0b11110000, 0b11111111, 0b11111111};
	unsigned char column[] = {0b00000001, 0b00000010, 0b00000100, 0b00001000, 0b00010000, 0b00100000, 0b01000000, 0b10000000};
	int slen = getLength();
	//int slen = 8;
	int i = 0;
	int j = 0;
	
	
	while(1){
		if(j == 3000){
			int in = PIND;
			if(in & 1){
				drift(row, slen);
			}
			j = 0;
		}
		PORTA = column[i]^invert;
		PORTB = row[i];
		i++;
		i = i%8;
		j++;
		_delay_ms(0.03);
	}
}


