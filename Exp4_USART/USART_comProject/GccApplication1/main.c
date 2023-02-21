/*
 * GccApplication1.c
 *
 * Created: 1/31/2023 11:01:06 AM
 * Author : User
 */ 

#define F_CPU 1000000


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


void uart_init()
{
	UCSRA = 0b00000000;
	UCSRB = 0b00011000;
	UCSRC = 0b10000110;
	
	UBRRH = 0;
	UBRRL = 25;
}


void uart_send(unsigned char data){
	while ((UCSRA & (1<<UDRE)) == 0x00);
	UDR = data;
}


unsigned char uart_receive(void){
	while ((UCSRA & (1<<RXC)) == 0x00);
	return UDR;
}

ISR(INT0_vect)
{
	//cli();
	//PORTA = PORTA^1;
	uart_send('a');
	_delay_ms(100);
	//sei();
}


int main(void)
{
	uart_init();
	//DDRA = 0xFF;
	//PORTA = 0x00;
	_delay_ms(1000);
	GICR = (1 << INT0);
	MCUCR = MCUCR | (1 << ISC00);
	MCUCR = MCUCR | (1 << ISC01);
	sei();
	while(1);
}


