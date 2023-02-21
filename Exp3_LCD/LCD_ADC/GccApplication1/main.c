/*
 * GccApplication1.c
 *
 * Created: 1/17/2023 11:02:14 AM
 * Author : TeamGGWP
 */ 

#ifndef F_CPU
#define F_CPU 1000000UL // 1 MHz clock speed
#endif


#define D4 eS_PORTD4
#define D5 eS_PORTD5
#define D6 eS_PORTD6
#define D7 eS_PORTD7
#define RS eS_PORTC6
#define EN eS_PORTC7

#include <avr/io.h>
#include <stdlib.h>
#include <string.h>
#include <util/delay.h>
#include "lcd.h"


int main(void)
{
	DDRD = 0xFF;
	DDRC = 0xFF;
	/*DDRB = 0b00000001;*/
	
	ADMUX = 0b11000000;		
	// AREF				: 01 -> Vref - 5V
	// ADLAR : 0 -- Keep the result in lsb
	// ADC0 for ADC		: 00000 [MUX4-0]
	
	ADCSRA = 0b10000010;	
	// Enable ADC : 1 [ADEN]
	// Do not start conversion now : 0 [ADSC]
	// No Trigger : 0 [ADATE, auto trigger enable]	
	// No Interrupt Flag : 0 [ADIF, interrupt flag]
	// No Interrupt : 0 [ADIE, interrupt enable]
	// ADC Clock : 010 -> [ADPS2-0, prescalar select bits] 1MHz/4 = 250kHz
	
	Lcd4_Init();		// Initialize LCDin 4 communication bit mode
	
	while(1)
	{
		// if v > 4.2, LED On
		ADCSRA |= (1 << ADSC);			// Start ADC Conversion
		while(ADCSRA & (1 << ADSC)){;}	// Wait to finish ADC Conversion, interrupt not used		
		
		
		// Lcd4_Clear();   
		
		Lcd4_Set_Cursor(1,1);	// Cursor in (row, column) = (1, 1)
		

		float voltage = ADC>>2;   // (Vin/step_size; stepsize = Vmax/1024)
		
		char str[32];
		dtostrf(voltage, 3, 0, str);	// double-to-string-format width = 3, precision = 2
		strcat(str, " degree");
		Lcd4_Write_String(str);
		
		Lcd4_Set_Cursor(2,5);
		Lcd4_Write_String("celcius");
		
// 		if(voltage > 4.2) {
// 			PORTB = 0x01;
// 			} else {
// 			PORTB = 0x00;
// 		}
		_delay_ms(500);
	}
	return 0;
}

