int main(){
  //Definindo entrada e saída
  DDRD = 0b00000000; //Como todos são igual a 0, eu poderia simplesmente igualar tudo isso a 0
  DDRC = 0b00100010;
  DDRB = 0b00100000;
  while(1){
    PORTB = 0;
    PORTC = 0b00100000;
    _delay_ms(500);
    PORTC = 0b00000010;
    _delay_ms(500);
    PORTC = 0;
    PORTB = 0b00100000;
    _delay_ms(500);
  }
}
