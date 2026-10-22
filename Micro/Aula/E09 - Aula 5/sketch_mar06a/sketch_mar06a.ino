int main(){
  DDRD =  (1<<PD6); //Todos pinos como entrada
  PORTD = 255;//Liga o pull-up em todos os pinos de entrada
  while(1){
    DDRD &= ~(1<<PD6);//Liga PD6 como saída
    _delay_ms(1000);

    PORTD |= (1<<PD6);
    _delay_ms(1000);
  }
}
