int main() {
    // Configuração dos pinos
    DDRD &= ~((1 << PD0) | (1 << PD1) | (1 << PD2)); // PD0, PD1, PD2 como entrada (botões/chaves)
    DDRB |= (1 << PB0) | (1 << PB1) | (1 << PB2);    // PB0, PB1, PB2 como saída (LEDs)
    PORTD |= (1 << PD0) | (1 << PD1) | (1 << PD2);   // Ativar pull-up interno para os botões

    while (1) {
        // Leitura dos botões
        int botaoA = (PIND & (1 << PD0)); // Botão A (Motor M1)
        int botaoB = (PIND & (1 << PD1)); // Botão B (Motor M2)
        int botaoC = (PIND & (1 << PD2)); // Botão C (Motor M3)

        // Potência dos motores
        int potenciaM1 = 30;
        int potenciaM2 = 50;
        int potenciaM3 = 70;

        // Estado dos motores
        int motorM1 = 0;
        int motorM2 = 0;
        int motorM3 = 0;

        //Fazendo a leitura das chaves:
        
        // Verifica se o botão A foi pressionado para ligar o motor M1
        if (!(PIND & (1 << PD0))) {
            motorM1 = 1;
        }

        // Verifica se o botão B foi pressionado para ligar o motor M2
        if (!(PIND & (1 << PD1))) {
            motorM2 = 1;
        }

        // Verifica se o botão C foi pressionado para ligar o motor M3
        if (!(PIND & (1 << PD2))) {
            motorM3 = 1;
        }
        
        /* Cálculo da potência total
         * Essa lógica tem que estar antes do acionamento dos leds, se estiver depois dela, os três leds irão ligar juntos de qualquer jeito
         * pois o acionamento dos leds só verifica se a chave está fechada ou aberta, não se eu posso ligar os três juntos
         */
        int potenciaTotal = motorM1 * potenciaM1 + motorM2 * potenciaM2 + motorM3 * potenciaM3;

        // Verificação e ajuste da potência total para saber se eu preciso desligar algum led
        while (potenciaTotal > 90) {
            if (motorM1) {
                motorM1 = 0; // Desliga o motor de menor potência
            } else if (motorM2) {
                motorM2 = 0; // Desliga o motor de segunda menor potência
            } else {
              motorM3 = 0;
            }
            potenciaTotal = motorM1 * potenciaM1 + motorM2 * potenciaM2 + motorM3 * potenciaM3;
        }
        /*
         * Com a leitura das chaves e a lógica de quem pode ou não estar ligado, agora sim eu posso ligar meus leds:
         */
        if (motorM1) {
            PORTB |= (1 << PB0); // Liga LED do motor M1
        } else {
            PORTB &= ~(1 << PB0); // Desliga LED do motor M1
        }
        if (motorM2) {
            PORTB |= (1 << PB1); // Liga LED do motor M2
        } else {
            PORTB &= ~(1 << PB1); // Desliga LED do motor M2
        }
        if (motorM3) {
            PORTB |= (1 << PB2); // Liga LED do motor M3
        } else {
            PORTB &= ~(1 << PB2); // Desliga LED do motor M3
        }
    }
}
