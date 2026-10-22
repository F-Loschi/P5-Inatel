#define LEDS PD0
#define LEDM PD4

volatile long int valor_contagem = 0;
volatile long int segundos = 0;
volatile long int minutos = 0;

ISR(TIMER0_COMPA_vect) {
  valor_contagem++;

  // LED vermelho (1 segundo)
  if (valor_contagem == 1000) {         // Após 1s
    PORTD |= (1 << LEDS);               // Acende LED vermelho
  }
  if (valor_contagem == 1100) {         // Após 100ms ligado
    PORTD &= ~(1 << LEDS);              // Apaga LED vermelho
    valor_contagem = 0;
    segundos++;

    if (segundos == 60) {               // A cada 1 minuto
      segundos = 0;
      PORTD |= (1 << LEDM);             // Acende LED verde
    }
  }

  // Desliga o LED verde após 100ms
  if (PORTD & (1 << LEDM)) {
    minutos++;
    if (minutos == 100) {
      PORTD &= ~(1 << LEDM);
      minutos = 0;
    }
  }
}

int main() {
  DDRD |= (1 << LEDS) | (1 << LEDM);     
  PORTD &= ~((1 << LEDS) | (1 << LEDM)); 

  // Timer0 - CTC, 1ms por interrupção
  TCCR0A |= (1 << WGM01);                
  TCCR0B |= (1 << CS01) | (1 << CS00);   // Prescaler 64 (16MHz/64 = 250kHz → 4us por tick)
  OCR0A = 249;                           // 250 * 4us = 1ms

  TIMSK0 |= (1 << OCIE0A);               

  sei();  

  while (1) {
    // Tudo controlado via interrupção
  }
}
