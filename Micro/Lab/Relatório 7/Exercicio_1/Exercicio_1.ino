#define Led1 PD5
#define Led2 PD7
#define Led3 PD6
#define Led4 PB1

ISR(PCINT0_vect){
  if(!(PINB & (1<<PB0))){
    PORTD |= (1<<Led2);
    _delay_ms(1000);
    PORTD &= ~(1<<Led2);
    _delay_ms(1000);
  }
  if(!(PINB & (1<<PB2))){
    PORTD |= (1<<Led3);
    _delay_ms(1000);
    PORTD &= ~(1<<Led3);
    _delay_ms(1000);
  }
}
ISR(PCINT2_vect){
  if(!(PIND & (1<<PD4))){
    PORTB |= (1<<Led4);
    _delay_ms(1000);
    PORTB &= ~(1<<Led4);
    _delay_ms(1000);
  }
}

int main(){
  DDRD |= (1<<Led1)|(1<<Led2)|(1<<Led3);
  DDRB |= (1<<Led4);

  PORTB |= (1<<PB0)|(1<<PB2);
  PORTD |= (1<<PD4);
  
  PCICR |= (1<<PCIE0) | (1<<PCIE2);//PCIE0 para habilitar a interrupção para o grupo B
  // e PCIE2 para habilitar para o grupo D
  PCMSK0 |= (1<<PCINT0) | (1<<PCINT2);//Habilita interrupção para PCINT0 e PCINT2
  PCMSK2 |= (1<<PCINT20);//Habilita interrupção para PCINT20
  
  sei();
  while(1){
    PORTD ^= (1<<Led1);
    _delay_ms(250);
  }
}
