#define motor PD1
#define liga PB1
#define desliga PB2

volatile long int valor_contagem = 0;
volatile bool contando = false;// Indica se a contagem está em andamento
volatile bool motor_ligado = false;// Estado atual do motor

// Interrupção por mudança de estado nos botões LIGA (PB1) e DESLIGA (PB2)
ISR(PCINT0_vect) {
    // Se o botão DESLIGA for pressionado
    if (!(PINB & (1 << desliga))) {
        PORTD &= ~(1 << motor);// Desliga o motor
        motor_ligado = false;
        contando = false;// Cancela qualquer contagem
        valor_contagem = 0;
    }

    // Se o botão LIGA for pressionado
    // E se o motor ainda estiver desligado e não estiver contando
    if (!(PINB & (1 << liga)) && !motor_ligado && !contando) {
        contando = true; // Inicia a contagem
        valor_contagem = 0;
        TIMSK0 |= (1 << OCIE0A);// Habilita interrupção do Timer0
    }
}

// Interrupção do Timer0 a cada 10ms
ISR(TIMER0_COMPA_vect) {
    if (contando && !motor_ligado) {
        valor_contagem++;

        // Se o botão LIGA for solto durante a contagem
        if (PINB & (1 << liga)) {
            contando = false;// Cancela contagem
            valor_contagem = 0;
        }
        // Se o botão LIGA foi mantido pressionado por 10 segundos (1000 x 10ms)
        else if (valor_contagem >= 10000) {
            PORTD |= (1 << motor);// Liga o motor
            motor_ligado = true;
            contando = false;
            TIMSK0 &= ~(1 << OCIE0A);// Desabilita a interrupção do Timer0
        }
    }
}

int main() {
    DDRD |= (1 << motor);// Configura PD1 como saída (motor)
    DDRB &= ~((1 << liga) | (1 << desliga));// Configura PB1 e PB2 como entrada
    PORTB |= (1 << liga) | (1 << desliga);// Ativa resistores de pull-up nos botões

    // Configura interrupções por mudança de estado nos pinos PB1 e PB2
    PCICR |= (1 << PCIE0);                    
    PCMSK0 |= (1 << PCINT1) | (1 << PCINT2);  

    // Configuração do Timer0 para modo CTC com prescaler 64, gerando interrupções a cada ~10ms
    TCCR0A = (1 << WGM01);                     
    TCCR0B = (1 << CS01) | (1 << CS00);       
    OCR0A = 249;                              

    sei(); // Habilita interrupções globais

    while (1) {
        // Loop principal vazio — toda lógica ocorre por interrupções
    }
}
