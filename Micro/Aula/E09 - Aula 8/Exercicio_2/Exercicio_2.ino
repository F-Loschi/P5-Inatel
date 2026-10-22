#define FORNO PB0

ISR(INT0_vect){
  PORTB &= ~(1<<FORNO);
}
ISR(INT1_vect){
  PORTB |= (1<<FORNO);
}

int main(){
  DDRD &= ~((1<<PD2) | (1<<PD3));
  DDRB |= (1<<FORNO);

  //PORTB |= (1<<FORNO);
  
  EICRA |= (1<<ISC01);
  EIMSK |= (1<<INT0);

  EICRA |= (1<<ISC11);
  EIMSK |= (1<<INT1);
  sei();

  while(1){
    
  }
}
