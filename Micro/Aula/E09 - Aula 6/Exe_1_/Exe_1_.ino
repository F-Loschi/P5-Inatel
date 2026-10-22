#include <util/delay.h>
int main(){
  // Configuração de pinos
  DDRD = 0;  // Configura PD0 e PD4 como entrada
  DDRB = 0;  // Configura PB0 e PB1 como entrada
  DDRC = 0b11111111; // Configura PC0 a PC7 como saída
  PORTD |= (1<<PD0) | (1<<PD4); // Habilita pull-up interno para PD0 e PD4
  
  PORTC = 0; // Apaga todos os LEDs no início
  
  for(;;){
    // Chave A: Todos os LEDs piscam a cada 300ms
    if (!(PIND & (1<<PD0))) {
      PORTC |= (1<<PC3);
      PORTC |= (1<<PC2);
      PORTC |= (1<<PC1);
      PORTC |= (1<<PC0);
      _delay_ms(300);
      PORTC &= (~(1<<PC3));
      PORTC &= (~(1<<PC2));
      PORTC &= (~(1<<PC1));
      PORTC &= (~(1<<PC0));
      _delay_ms(300);
    }
    
    // Chave B: Acende alternadamente dois LEDs por vez
    else if (!(PIND & (1<<PD4))) {
      PORTC |= (1<<PC3);
      PORTC |= (1<<PC2);
      _delay_ms(800);
      PORTC &= (~(1<<PC3));
      PORTC &= (~(1<<PC2));
      _delay_ms(800);
      PORTC |= (1<<PC1);
      PORTC |= (1<<PC0);
      _delay_ms(800);
      PORTC &= (~(1<<PC1));
      PORTC &= (~(1<<PC0));
    }
    
    // Chave C: Liga LEDs sequencialmente
    else if (!(PINB & (1<<PB0))) {
       PORTC |= (1<<PC3);
      _delay_ms(300);
      PORTC &= (~(1<<PC3));
      _delay_ms(300);
      PORTC |= (1<<PC2);
      _delay_ms(300);
      PORTC &= (~(1<<PC2));
      _delay_ms(300);
      PORTC |= (1<<PC1);
      _delay_ms(300);
       PORTC &= (~(1<<PC1));
      _delay_ms(300);
      PORTC |= (1<<PC0);
      _delay_ms(300);
      PORTC &= (~(1<<PC0));
    }
    
    // Chave D: Desliga LEDs um por um
    else if (!(PINB & (1<<PB1))) {
      PORTC |= (1<<PC3);
      PORTC |= (1<<PC2);
      PORTC |= (1<<PC1);
      PORTC |= (1<<PC0);
      _delay_ms(300);
      PORTC &= (~(1<<PC0));
      _delay_ms(300);
      PORTC &= (~(1<<PC1));
      _delay_ms(300);
      PORTC &= (~(1<<PC2));
      _delay_ms(300);
      PORTC &= (~(1<<PC3));
      _delay_ms(300);
    }
  }
}
