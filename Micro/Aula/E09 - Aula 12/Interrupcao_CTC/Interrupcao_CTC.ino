#define led PC0
unsigned char contador=0;
ISR(TIMER0_COMPA_vect){
  contador++;
  if(contador>122){
    PORTC ^= (1<<led);
    contador = 0;
  }
}

int main(){
  DDRC |= (1<<led);
  TCCR0A = (1<<WGM01); //TIMER NO MODO CTC(COMPARAÇÃO)
  TCCR0B |= (1<<CS00) | (1<<CS02);//BORDA DE SUBIDA
  TIMSK0 |= (1<<OCIE0A);//LIGA INT POR OVERFLOW(INTERRUPÇÃO DE MODO NORMAL)
  sei();
  OCR0A = 200;
  while(1){
    
  }
}
