 #define F_CPU 1000000


#include <avr/io.h>
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




int main(void)
{
    DDRA = 0xFF;
    PORTA = 0x00;
  uart_init();
  while(1)
    {    
        unsigned char c = uart_receive();
        PORTA = PORTA ^ 1;
      
    }
}
