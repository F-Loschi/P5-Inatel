#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>

#define BUFFER_SIZE 10
#define F_CPU 16000000UL
#define BAUD 9600
#define MYUBRR (F_CPU / 16 / BAUD - 1)

volatile short int contador = 0;
char comando_buffer[BUFFER_SIZE];
short int buffer_index = 0;


void UART_Init(unsigned int ubrr) {
    UBRR0H = (unsigned char)(ubrr >> 8);
    UBRR0L = (unsigned char)ubrr;

    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);

    UCSR0B = (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0);
}

void UART_Transmit(char mensagem) {
    while (!(UCSR0A & (1 << UDRE0))); // Espera até o registrador de transmissão estar vazio
    UDR0 = mensagem;                      // Envia o dado
}

// Função para enviar uma string pela UART
void UART_SendString(const char* mensagem) {
    while (*mensagem) {
        UART_Transmit(*mensagem++);       // Envia caractere por caractere
    }
}

// Interrupção de recepção da UART
ISR(USART_RX_vect) {
    char recebido = UDR0;  // Lê o caractere recebido

    if (recebido == '\n' || recebido == '\r') { // Se for fim de linha
        comando_buffer[buffer_index] = '\0';    // Finaliza a string recebida

        if (strcmp(comando_buffer, "zerar") == 0) {  // Compara com o comando "zerar"
            contador = 0;                            // Zera o contador
        }

        buffer_index = 0;  // Reinicia o índice do buffer
    } else {
        // Adiciona o caractere no buffer se ainda houver espaço
        if (buffer_index < BUFFER_SIZE - 1) {
            comando_buffer[buffer_index++] = recebido;
        }
    }
}

ISR(INT0_vect) {
    contador++;
    char msg[30];
    itoa(contador, msg, 10);         // Converte o número para string
    UART_SendString(msg);           // Envia o valor atual do contador
    UART_SendString("\n");
}

// Função principal
int main(void) {
    UART_Init(MYUBRR);

    DDRD &= ~(1 << PD2);
    PORTD |= (1 << PD2);
    
    EICRA |= (1 << ISC01);
    EICRA &= ~(1 << ISC00);

    EIMSK |= (1 << INT0);

    sei();
    while (1) {
    }
}
