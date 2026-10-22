bool func = 0;
ISR(INT0_vect){
  PORTD |= 0b00010000;
  _delay_ms(1000);
  PORTD &= ~0b00010000;
}
ISR(INT1_vect){
  if (func) {
    EIMSK &= ~0b00000001; // Desativa INT0
    func = 0;
  } else {
    EIMSK |= 0b00000001;  // Ativa INT0
    func = 1;
  }
}

int main(){
  DDRD = 0b00110000;
  PORTD = 0b00000000;
  EICRA = 0b00001110;
  EIMSK = 0b00000010;
  sei();

  while(1){
    PORTD ^= 0b00100000;
    _delay_ms(500);
  }
}
