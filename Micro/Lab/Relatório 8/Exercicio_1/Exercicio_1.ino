#define LED PD0
volatile long int valor_contagem=0;
ISR(TIMER0_COMPA_vect){
  
  valor_contagem++;
  if(valor_contagem >= 2000){//2000*75us = 150ms
    valor_contagem = 0;
    PORTD ^= (1<<LED);
  }
}

int main(){
  DDRD = 255;
  PORTD |= (1<<LED);
  TCCR0A |= (1<<WGM01);//CTC Para comparação
  TCCR0B |= (1<<CS01);//PRESCALER 8

  OCR0A = 149;//Ticks 150 - 500ns * 150 = 75us

  TIMSK0 |= (1<<OCIE0A);//Haqbilita a interrupção interna no OCR0A

  sei();

  while(1){
  }
}
