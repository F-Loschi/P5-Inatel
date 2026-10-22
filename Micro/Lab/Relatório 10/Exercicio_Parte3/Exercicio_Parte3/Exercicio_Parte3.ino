#define led PD6
unsigned long int leitura_AD;
/* 
 *  Ao fazer a mudança da porta de A0 para
 *  A2(PC0 para PC2) e realizar a mudança
 *  apropriada no ADMUX, o código funciona como
 *  esperado.
 */
int main() {
  // Configura PD6 como saída
  DDRD |= (1 << led);

  // Configura TIMER0 para Fast PWM
  TCCR0A |= (1 << COM0A1); 
  TCCR0A |= (1 << WGM01) | (1 << WGM00);
  TCCR0B |= (1 << CS01);

  OCR0A = 0; // Inicia LED apagado

  // Configura ADC
  ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS0); // habilita ADC e prescaler de 32
  ADMUX |= (1 << REFS0); // tensão de referência = AVCC (5V)

  while(1) {
    // Seleciona canal ADC0
    ADMUX = (ADMUX & 0b11110000) | 0b00000010; 

    // Inicia conversão
    ADCSRA |= (1 << ADSC);

    // Espera a conversão acabar
    while(ADCSRA & (1 << ADSC));

    // Lê valor
    leitura_AD = ADC;

    // Mapeia para PWM (0-255)
    OCR0A = leitura_AD / 4;
  }
}
