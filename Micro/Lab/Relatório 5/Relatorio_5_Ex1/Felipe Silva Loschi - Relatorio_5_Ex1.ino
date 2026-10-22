#include <avr/io.h>

int main() {
    // Configuração dos pinos
    DDRD &= ~((1 << PD7) | (1 << PD6) | (1 << PD5)); // PD7, PD6, PD5 como entrada
    DDRC = 255; // Todos os pinos da porta C como saída
    PORTD |= (1 << PD7) | (1 << PD6) | (1 << PD5); // Ativar pull-up interno

    while (1) {
        int botaoNA = (PIND & (1 << PD7)); // Lógica para ligar o botão (NA)
        int botaoNF = (!(PIND & (1 << PD6))); // Lógica para desligar o botão (NF)
        int S1 = (PIND & (1 << PD5)); // Leitura do sensor S1

        if (S1) {
            // Vê se tem amontoamento
            PORTC &= ~(1 << PC7); // Desliga motor
            PORTC |= (1 << PC6);  // Liga alarme
        } else {
            // Funcionamento do motor se não houver amontoamento
            if (botaoNA) {
                PORTC |= (1 << PC7); // Liga motor
            }
            if (botaoNF) {
                PORTC &= ~(1 << PC7); // Desliga motor
            }
            // Se o amontoamento foi resolvido e o botão NA foi pressionado, desliga o alarme
            if (botaoNA) {
                PORTC &= ~(1 << PC6); // Desliga alarme
            }
        }
    }
}
