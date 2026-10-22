int main(void)
{
  DDRD = DDRD | 0b11000000; // Configura os pinos PD6 e PD7 como saída
  PORTD = PORTD | 0b00110000; // Habilita PULL-UP nos pinos PD4 e PD5
  PORTD = PORTD & ~(0b11000000); // Garante que PD6 e PD7 iniciem em LOW
  
  for (;;){ // Loop infinito
    int botao = PIND & 0b00100000; // Lê o estado do botão conectado ao PD5
    int botao2 = PIND & 0b00010000; // Lê o estado do botão conectado ao PD4
    
    if (botao == 0){ // Se o botão no PD5 estiver pressionado
      PORTD = PORTD | 0b10000000; // Define PD7 como HIGH
      _delay_ms(100); // Aguarda 100ms
      PORTD = PORTD & ~(0b10000000); // Define PD7 como LOW
      PORTD = PORTD | 0b01000000; // Define PD6 como HIGH
      _delay_ms(100); // Aguarda 100ms
      PORTD = PORTD & ~(0b01000000); // Define PD6 como LOW
    }

    if (botao2 == 0){ // Se o botão no PD4 estiver pressionado
      PORTD = PORTD | 0b10000000; // Define PD7 como HIGH
      _delay_ms(1000); // Aguarda 1 segundo
      PORTD = PORTD & ~(0b10000000); // Define PD7 como LOW
      PORTD = PORTD | 0b01000000; // Define PD6 como HIGH
      _delay_ms(1000); // Aguarda 1 segundo
      PORTD = PORTD & ~(0b01000000); // Define PD6 como LOW
    }
  }
}
