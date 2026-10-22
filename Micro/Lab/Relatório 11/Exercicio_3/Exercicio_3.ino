#define F_CPU 16000000UL
#define BAUD 9600
#define MYUBRR (F_CPU / 16 / BAUD - 1)
#define PWM_PIN PD6  // Pino OC0A (Timer0) - Pino 6 no Arduino

volatile char buffer[4];     // Buffer para os caracteres recebidos
volatile short int idx = 0;  // Índice do buffer

void UART_Init(unsigned int ubrr) {
    UBRR0H = (unsigned char)(ubrr >> 8);
    UBRR0L = (unsigned char)ubrr;
    UCSR0B = (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0);
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void UART_Transmit_String(const char* mensagem) {
    while (*mensagem) {
        while (!(UCSR0A & (1 << UDRE0)));
        UDR0 = *mensagem++;
    }
}

void set_PWM_porcentagem(uint8_t porcentagem) {
    if (porcentagem > 100){
      porcentagem = 100;
    }
    OCR0A = (porcentagem * 255) / 100;//Converte o valor da porcentagem
}

ISR(USART_RX_vect) {
    char c = UDR0;
    
    if (c == '\n' || c == '\r') {
        buffer[idx] = '\0';
        short int duty = atoi((char*)buffer);
        set_PWM_porcentagem(duty);

        char msg[10];
        itoa(duty, msg, 10);
        UART_Transmit_String(msg);
        UART_Transmit_String("%\n");

        idx = 0;
    } else if (idx < sizeof(buffer) - 1) {
        buffer[idx++] = c;
    }
}

int main(void) {
    DDRD |= (1 << PWM_PIN);
    // Configura para Fast PWM:
    TCCR0A = (1 << COM0A1) | (1 << WGM01) | (1 << WGM00);
    TCCR0B = (1 << CS01);  // Prescaler = 8
    OCR0A = 0;  // Duty cycle inicial = 0%

    UART_Init(MYUBRR);
    sei();

    while (1) {}
}
