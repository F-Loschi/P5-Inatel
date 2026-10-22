#define led PC0
unsigned char contador=0;
ISR(TIMER0_OVF_vect){
  contador++;
  if(contador>122){
    PORTC ^= (1<<led);
  }
}

int main(){
  DDRC |= (1<<led);
  TCCR0A = 0; //Timer no modo normal
  TCCR0B |= (1<<CS00) | (1<<CS02);//PRESCALER = 1024
  TIMSK0 |= (1<<TOIE0);//LIGA INT POR OVERFLOW(INTERRUPÇÃO DE MODO NORMAL)
  sei();
  while(1){
    
  }
}
