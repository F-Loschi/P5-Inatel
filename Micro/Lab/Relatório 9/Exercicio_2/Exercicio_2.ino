#define pwm_out PD6
#define botao PD1
unsigned int Ton = 26; // aproximadamente 10% de 255

ISR(PCINT2_vect){
  if((!(PIND & (1<<botao)))){ // se o botão estiver pressionado
    OCR0A += Ton;             // aumenta o brilho em 10%
    if(OCR0A > 255){          // se ultrapassar 100% de brilho
      OCR0A = 0;              // reinicia o brilho (LED apaga)
    }
  }
}

int main(){
  DDRD |= (1<<pwm_out);       // configura PD6 como saída
  PORTD |= (1<<botao);        // ativa resistor de pull-up interno no botão

  PCICR |= (1<<PCIE2);        // habilita interrupção por mudança de pino no PORTD
  PCMSK2 |= (1<<PCINT17);     // habilita interrupção especificamente no pino PD1

  TCCR0A |= (1<<COM0A1);      // conecta saída PWM ao pino OC0A (PD6)
  TCCR0A |= (1<<WGM01) | (1<<WGM00); // configura modo FAST PWM
  TCCR0B |= (1<<CS01);        // configura o prescaler do timer (divisor de clock por 8)

  OCR0A = 0;                  // inicia com LED apagado

  sei();                      
  while(1){
    // loop principal vazio, tudo é controlado pela interrupção
  }
}
