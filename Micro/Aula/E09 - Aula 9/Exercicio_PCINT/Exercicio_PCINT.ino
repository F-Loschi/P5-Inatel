#define led1 PC5
#define led2 PB5
#define Porta1 PD1
#define Porta2 PB7

ISR(PCINT0_vect){
  PORTC &= ~(1<<led1);
  PORTB |= (1<<led2);
  _delay_ms(300);
  PORTB &= ~(1<<led2);
  _delay_ms(300);
}
ISR(PCINT2_vect){
  PORTC &= ~(1<<led1);
  PORTB |= (1<<led2);
  _delay_ms(600);
  PORTB &= ~(1<<led2);
  _delay_ms(600);
}
int main(){
  DDRD &= ~(1<<Porta1);
  DDRB &= ~(1<<Porta2);
  DDRB |= (1<<led2);
  DDRC |= (1<<led1);

  PCICR |= (1<< PCIE0) | (1<<PCIE2);

  PCMSK0 |= (1<<PCINT7);
  PCMSK2 |= (1<<PCINT17);
  
  sei();
  while(1){
    PORTC ^= (1<<led1);
    _delay_ms(5000);
  }
}
