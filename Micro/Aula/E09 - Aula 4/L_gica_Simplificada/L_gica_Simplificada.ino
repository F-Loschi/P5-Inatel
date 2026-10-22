#include <avr/io.h>
#include <util/delay.h>

#define VERMELHO_ON (1 << PC5)
#define AMARELO_ON  (1 << PC1)
#define VERDE_ON    (1 << PB5)

int main() {
    // Configuração dos pinos de saída
    DDRC |= VERMELHO_ON | AMARELO_ON; // Define PC5 e PC1 como saída
    DDRB |= VERDE_ON;                 // Define PB5 como saída
    DDRD = 0;                          // Todos os pinos de D como entrada

    while (1) {
        // Liga somente o vermelho e espera 2s
        PORTC = VERMELHO_ON;
        PORTB = 0;
        _delay_ms(2000);

        // Liga somente o amarelo e espera 1s
        PORTC = AMARELO_ON;
        PORTB = 0;
        _delay_ms(1000);

        // Liga somente o verde e espera 2s
        PORTC = 0;
        PORTB = VERDE_ON;
        _delay_ms(2000);
    }
}
