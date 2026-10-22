int main(void)
{
  DDRD = DDRD | 0b11001000; // Configura os pinos PD3, PD6 e PD7 como saída
  PORTD = PORTD | 0b00111000; // Habilita PULL-UP nos pinos PD3, PD4 e PD5
  PORTD = PORTD & ~(0b11001000); // Garante que PD3, PD6 e PD7 iniciem em LOW
  
  for (;;){ // Loop infinito
    int botao = PIND & 0b00100000; // Lê o estado do botão conectado ao PD5
    
    if (botao == 0){ // Se o botão no PD5 estiver pressionado
      // Acende LED vermelho (PD3)
      PORTD = PORTD | 0b00001000; // PD3 -> HIGH
      _delay_ms(2000); // Aguarda 2 segundos
      PORTD = PORTD & ~(0b00001000); // PD3 -> LOW
      
      // Acende LED verde (PD7)
      PORTD = PORTD | 0b10000000; // PD7 -> HIGH
      _delay_ms(2000); // Aguarda 2 segundos
      PORTD = PORTD & ~(0b10000000); // PD7 -> LOW

      // Acende LED amarelo (PD6)
      PORTD = PORTD | 0b01000000; // PD6 -> HIGH
      _delay_ms(2000); // Aguarda 2 segundos
      PORTD = PORTD & ~(0b01000000); // PD6 -> LOW
    }
  }
}
