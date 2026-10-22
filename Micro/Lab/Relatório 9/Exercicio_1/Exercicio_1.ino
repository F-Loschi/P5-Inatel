#define pwm_out PD6
#define botao PD1
unsigned int Ton = 128; // 50% de 255 (meio ciclo ativo)

ISR(PCINT2_vect){
  if((!(PIND & (1<<botao)))){ // se o botão estiver pressionado
    OCR0A = Ton;              // define o duty cycle do PWM para 50% (LED meio brilho)
  }
  else{
    OCR0A = 0;                // botão solto: LED apaga (0% de duty cycle)
  }
}

int main(){
  DDRD |= (1<<pwm_out);        // configura PD6 como saída (LED)
  PORTD |= (1<<botao);         // ativa resistor de pull-up interno no botão (entrada em PD1)

  PCICR |= (1<<PCIE2);         // habilita interrupções por mudança nos pinos do PORTD
  PCMSK2 |= (1<<PCINT17);      // habilita interrupção especificamente no pino PD1

  TCCR0A |= (1<<COM0A1);       // conecta o sinal PWM ao pino OC0A (PD6)
  TCCR0A |= (1<<WGM01) | (1<<WGM00); // configura o timer em modo FAST PWM
  TCCR0B |= (1<<CS01);         // configura prescaler do timer (divisor de clock por 8)

  OCR0A = 0;                   // inicia com o LED apagado (0% de duty cycle)

  sei();                       // habilita interrupções globais

  while(1){
    // loop principal vazio, controle feito via interrupção
  }
}
