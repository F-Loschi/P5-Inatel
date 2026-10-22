#define F_CPU 16000000U      
#define BAND 9600
#define MYUBRR (F_CPU/16/BAND - 1)

#define led1 PC0 //led1 (vermelho)
#define led2 PC1 //led2 (verde)

char numero;

void UART_Init(unsigned ubrr){
  UBRR0H = (unsigned char)(ubrr >> 8);
  UBRR0L = (unsigned char)ubrr;
  UCSR0C = (1 << UCSZ00) | (1 << UCSZ01);
  UCSR0B = (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0);
}

void UART_TX(char mensagem){
  while(!(UCSR0A & (1 << UDRE0)));  // Espera até o registrador estar pronto para transmissão
  UDR0 = mensagem;                  // Coloca o caractere no registrador de transmissão
}

ISR(USART_RX_vect){
  numero = UDR0;  // Armazena o caractere recebido na variável global
}

int main(){
  DDRC |= (1<<led1)|(1<<led2);
  PORTC |= (1<<led1)|(1<<led2);

  UART_Init(MYUBRR);
  
  sei();
  while(1){
    
    if(numero == '9'){
      PORTC |= (1 << led1);
      PORTC &= ~(1 << led2);
    }
    
    if(numero == '8'){
      PORTC &= ~(1 << led1);
      PORTC |= (1 << led2);
    }
  }
}
