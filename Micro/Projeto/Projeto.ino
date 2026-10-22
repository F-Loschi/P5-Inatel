// Felipe Silva Loschi(601) & Felipe Tagawa Reis(2037) & Pedro Henrique Ribeiro Dias(529)
// ------------------ UART ---------------------
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>

#define F_CPU 16000000UL
#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1

// ------------- Entradas e saídas -------------
#define botao PD4
#define botaoLIGA PD5
#define led PB1 // LED que pisca
#define potenciometro PC0 // A0
#define buzzer PB2 // PWM para controle de volume (OC1B)
#define botaoOFF PD7
#define ledSistema PB3 // LED indicador do sistema

unsigned char contadorPontos = 0; // Pontuação
volatile unsigned char ledAceso = 0; // Flag para indicar se LED está aceso
volatile unsigned char contadorTimer = 0; // Contador para controle do piscar
volatile unsigned char sistemaLigado = 0; // Flag para controlar se o sistema está ligado
volatile unsigned char debounceCounter = 0; // Contador para debounce do botão

// ----------- Inicialização UART ---------------
void UART_Init(unsigned int ubrr) {
  UBRR0H = (unsigned char)(ubrr >> 8);
  UBRR0L = (unsigned char)ubrr;
  UCSR0B = (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0);
  UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

// ----------- Recepção UART --------------------
ISR(USART_RX_vect) {
  char comando = UDR0;
  
  // Ignora caracteres de controle (CR, LF, espaços, tabs)
  if (comando == '\r' || comando == '\n' || comando == ' ' || comando == '\t') {
    return; // Sai da ISR sem processar
  }
  
  switch (comando) {
    case 'r':
      if (sistemaLigado) {
        contadorPontos = 0;
        UART_SendString("Pontuacao reiniciada.\r\n");
      } else {
        UART_SendString("Sistema desligado! Ligue o sistema primeiro.\r\n");
      }
      break;
    case 's':
      UART_SendString("Pontuacao atual: ");
      UART_SendInt(contadorPontos);
      UART_SendString("\r\n");
      break;
    case 'd': // Debug do volume do buzzer
      UART_SendString("Volume buzzer: ");
      UART_SendInt(OCR1B);
      UART_SendString("\r\n");
      break;
    case 'o': // Status do sistema
      if (sistemaLigado) {
        UART_SendString("Sistema LIGADO\r\n");
      } else {
        UART_SendString("Sistema DESLIGADO\r\n");
      }
      break;
    case 'x': // Comando de debug para ver caracteres recebidos
      UART_SendString("Ultimo char recebido: ");
      UART_SendInt((unsigned char)comando);
      UART_SendString(" (ASCII: '");
      UART_Transmit(comando);
      UART_SendString("')\r\n");
      break;
    case 'h': // Help - mostra comandos disponíveis
      UART_SendString("=== COMANDOS DISPONIVEIS ===\r\n");
      UART_SendString("r = Reset pontuacao\r\n");
      UART_SendString("s = Mostrar pontuacao atual\r\n");
      UART_SendString("d = Debug volume do buzzer\r\n");
      UART_SendString("o = Status do sistema (ON/OFF)\r\n");
      UART_SendString("x = Debug ultimo caractere recebido\r\n");
      UART_SendString("h = Mostrar esta ajuda\r\n");
      UART_SendString("=============================\r\n");
      break;
    default:
      UART_SendString("Comando invalido. Digite 'h' para ver comandos disponiveis.\r\n");
      // Debug: mostra qual caractere foi recebido
      UART_SendString("Caractere recebido: ");
      UART_SendInt((unsigned char)comando);
      UART_SendString(" (ASCII)\r\n");
      break;
  }
}

// ------------ Transmissão de dados -------------
void UART_Transmit(unsigned char data) {
  // Espera o buffer estar vazio
  while (!(UCSR0A & (1 << UDRE0)));
  // Envia o dado
  UDR0 = data;
}

// --------- Envio de valores inteiros com UART ----------
void UART_SendInt(uint8_t valor) {
  char buffer[10];
  itoa(valor, buffer, 10); // Conversão de inteiro para string
  UART_SendString(buffer);
}

// ---------- Envio de Strings com UART --------------------
void UART_SendString(const char* str) {
  while (*str) {
    UART_Transmit(*str++); // Transmissão de mensagens
  }
}

void ligaBuzzer(){
  if (sistemaLigado && OCR1B > 0) { // Só toca se sistema ligado e volume > 0
    // Ativa o buzzer com PWM usando Timer1
    TCCR1A |= (1 << COM1B1); // Habilita PWM no pino OC1B (PB2)
    _delay_ms(300);
    TCCR1A &= ~(1 << COM1B1); // Desabilita PWM
    PORTB &= ~(1 << buzzer); // Garante que o pino fica em LOW
  }
}

// ---------- Interrupção dos botões --------------------
ISR(PCINT2_vect) {
  // Verifica se é o botão de ON/OFF (PD7)
  if (!(PIND & (1 << botaoOFF))) {
    if (debounceCounter == 0) { // Só processa se não estiver em debounce
      sistemaLigado = !sistemaLigado; // Inverte o estado do sistema
      
      if (sistemaLigado) {
        PORTB |= (1 << ledSistema); // Liga LED do sistema
        UART_SendString("=== SISTEMA LIGADO ===\r\n");
        UART_SendString("Jogo ativo! Pressione o botao quando o LED piscar.\r\n");
      } else {
        PORTB &= ~(1 << ledSistema); // Desliga LED do sistema
        PORTB &= ~(1 << led); // Desliga LED do jogo
        ledAceso = 0;
        contadorTimer = 0;
        UART_SendString("=== SISTEMA DESLIGADO ===\r\n");
        UART_SendString("Pressione o botao ON/OFF para ligar novamente.\r\n");
      }
      debounceCounter = 20; // Inicia debounce (20 * 12.8ms = ~256ms)
    }
    return; // Sai da interrupção para não processar outros botões
  }
  
  // Só processa outros botões se sistema estiver ligado
  if (!sistemaLigado) {
    return;
  }
  
  // Verifica se é o botão de tiro (PD4)
  if (!(PIND & (1 << botao))) {
    if (ledAceso) { // Só conta ponto se LED estiver aceso
      contadorPontos++; // Incrementa a pontuação do jogador
      PORTB &= ~(1 << led); // Desliga o LED imediatamente
      ligaBuzzer();
      ledAceso = 0; // Marca LED como apagado
      contadorTimer = 0; // Reinicia o contador do timer
      UART_SendString("Acertou! Pontuacao: ");
      UART_SendInt(contadorPontos);
      UART_SendString("\r\n");
    } else {
      UART_SendString("Errou! LED estava apagado.\r\n");
    }
  }
  
  // Verifica se é o botão LIGA (PD5)
  if (!(PIND & (1 << botaoLIGA))) {
    UART_SendString("Iniciando nova leitura de tensao.\r\n");
    
    // Seleciona o canal ADC0 (potenciometro PC0)
    ADMUX = (ADMUX & 0xF0) | (potenciometro & 0x0F);
    
    // Inicia uma nova conversão ADC
    ADCSRA |= (1 << ADSC);

    // Espera a conversão terminar
    while (ADCSRA & (1 << ADSC));

    uint16_t leituraAD = ADC; // Lê o valor convertido

    // Atualiza o PWM do buzzer proporcional à tensão
    OCR1B = leituraAD >> 2; // Dividindo por 4 (1023/4 ≈ 255) para caber no PWM de 8 bits
    
    UART_SendString("Volume do buzzer ajustado para: ");
    UART_SendInt(OCR1B);
    UART_SendString("\r\n");
  }
}

// ------------------- Rotina de TIMER 2 (PISCA LED E DEBOUNCE) ----------------------- //
ISR(TIMER2_COMPA_vect) { 
  // Debounce do botão ON/OFF
  if (debounceCounter > 0) {
    debounceCounter--;
  }
  
  // Só pisca LED se sistema estiver ligado
  if (sistemaLigado) {
    contadorTimer++;
    
    // Pisca o LED a cada ~500ms (aproximadamente 39 interrupções de 12.8ms)
    if (contadorTimer >= 39) {
      contadorTimer = 0;
      
      if (ledAceso) {
        PORTB &= ~(1 << led); // Apaga o LED
        ledAceso = 0;
      } else {
        PORTB |= (1 << led); // Acende o LED
        ledAceso = 1;
      }
    }
  }
}

// ------------------------  Função Principal  ------------------ //
int main() {
    UART_Init(MYUBRR); // Inicialização do UART
    
    // Configuração dos pinos
    DDRD &= ~(1 << botao); // botão como entrada
    DDRD &= ~(1 << botaoLIGA); // botão LIGA como entrada
    DDRD &= ~(1 << botaoOFF); // botão ON/OFF como entrada
    DDRB |= (1 << led) | (1 << buzzer) | (1 << ledSistema); // LEDs e buzzer como saída
    PORTD |= (1 << botao) | (1 << botaoLIGA) | (1 << botaoOFF); // Pull-up nos botões
    
    // Sistema inicia desligado
    sistemaLigado = 0;
    PORTB &= ~(1 << ledSistema); // LED do sistema desligado
    PORTB &= ~(1 << led); // LED do jogo desligado
    
    //----------------- Configuração do PWM para buzzer (Timer1) -----------------
    TCCR1A |= (1 << WGM10); // PWM 8-bit (Fast PWM)
    TCCR1B |= (1 << WGM12) | (1 << CS11) | (1 << CS10); // Fast PWM 8-bit, prescaler = 64
    // COM1B1 será habilitado apenas quando o buzzer tocar
    
    // Configuração para piscar do LED (Timer2)
    TCCR2A |= (1 << WGM21); // CTC mode
    TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20); // Prescaler = 1024
    OCR2A = 199; // Para gerar interrupção a cada ~12.8ms
    TIMSK2 |= (1 << OCIE2A); // Habilita a interrupção por comparação
    
    //----------------- Interrupção externa: -----------------
    PCICR |= (1 << PCIE2); // Habilita interrupções PCINT para porta D
    PCMSK2 |= (1 << PCINT20) | (1 << PCINT21) | (1 << PCINT23); // Interrupção em PD4, PD5 e PD7
    
    //----------------- Configuração do conversor ADC: -----------------
    ADCSRA |= (1 << ADEN); // Liga o ADC
    // PRESCALER ADC:
    ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // Prescaler = 128(125kHz)
    ADMUX |= (1 << REFS0); // Usando AVCC como referência
    
    sei(); // Habilita interrupções globais
    
    // Inicializa buzzer com volume zero
    OCR1B = 0;
    
    // Mensagens iniciais
    UART_SendString("=== Tiro ao LED - Sistema Inicializado ===\r\n");
    UART_SendString("Sistema DESLIGADO - Pressione o botao ON/OFF para ligar\r\n");
    UART_SendString("Comandos: 'r'=reset, 's'=score, 'd'=debug, 'o'=status, 'h'=help\r\n\r\n");
    
    while (1) {
        // Loop principal vazio - tudo é controlado por interrupções
    }
}
