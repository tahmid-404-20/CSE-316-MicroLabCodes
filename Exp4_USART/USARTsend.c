#define F_CPU 1000000


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


void uart_init()
{
  UCSRA = 0b00000010;
  UCSRB = 0b00011000;
  UCSRC = 0b10000110;
 
  UBRRH = 0;
  UBRRL = 12;
}


void uart_send(unsigned char data){
  while ((UCSRA & (1<<UDRE)) == 0x00);
  UDR = data;
}


unsigned char uart_receive(void){
  while ((UCSRA & (1<<RXC)) == 0x00);
  return UDR;
}

ISR(INT1_vect)
{
    cli();
    PORTA = PORTA^1;
    uart_send('a');
    _delay_ms(100);
    sei();
}    


int main(void)
{
  uart_init();
  DDRA = 0xFF;
  PORTA = 0x00;
  _delay_ms(1000);
  GICR = (1 << INT1);
  MCUCR = MCUCR | (1 << ISC10);
  sei();
  while(1);
}

