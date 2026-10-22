## PCINT
- Ocorre uma interrupção no código, ele roda a rotina de interrupção e depois volta ao que estava previamente ocorrendo
- É uma interrupção de prioridade mais baixa que as outras, porém mais versátil
- Uma vez configurado, a interrupção irá ocorrer quando houver uma mudança de estado no grupo do pino configurado, podendo ser ela de subida ou descida
### Registradores do PCINT
- Possui dois registradores principais.
	- PCICR: Configura qual grupo está habilitado a causar interrupções:
		- 0 para o B
		- 1 para o C
		- 2 para o D
	- PCMSKx: Configura qual pino do determinado grupo irá causar a interrupção
		- PCMSK0: PORTB, do PCINT0 ao PCINT7
		- PCMSK1: PORTC, do PCINT8 ao PCINT14
		- PCMSK2: PORTD, do PCINT15 ao PCINT23
### Função de Interrupção
- Para serem diferenciadas, há um vetor para cada um dos PCMSKs
	- PCINT0_vect para PCMSK0
	- PCINT1_vect para PCMSK1
	- PCINT2_vect para PCMSK2
## Timer
- Bloco interno do micro capaz de contar o tempo.
- O ATMega328p possui 3 temporizadores internos, o timer de 0 e 2 de 8 bits e o timer 1 de 16 bits. O clock do cristal que abordamos possui uma frequência de 16MHz, que significa um período de 62,5ns.
- Para não usar o mísero tempo de 62,5ns toda vez, usamos um Prescaler antes do clock com um fator de divisão que pode ser ajustado a vontade para fazer com que esse tempo aumente.

| Fator de Divisão | Frequência do Clock (Fclk) | Período do Clock (Tclk) |
|------------------|-----------------------------|--------------------------|
| 8                | 2 MHz                       | 500 ns                   |
| 64               | 250 kHz                     | 4 µs                     |
| 256              | 62,5 kHz                    | 16 µs                    |
| 1024             | 15,6 kHz                    | 64 µs                    |
### Modos do Timer:
- CTC: Por comparação. 
	- Sempre que o contador do clock chegar em um valor pré-setado, a contagem é interrompida e reiniciada.
	- Feito pela configuração WGM00=0, WGM01=1 no TCCR0A
	- A contagem é feita pelo TCNT0 e quando ele atinge o valor setado no OCR0A ele estoura e o fim da contagem é indicado por um bit de sinalização. Para o OCR0A é o OCF0A. Quando isso ocorre, o TCNT0 é reiniciado.
	- Registradores:
		- TCCR0A: Define em qual modo o timer vai funcionar
		- TCCR0B: Define o valor do prescaler, ou seja, por quanto a frequência será dividida
		- TIMSK0: Serve para definir como irá ser lançado uma interrupção caso eu queira que haja
## PWM
- O sinal PWM apresenta um período fixo e um ciclo de trabalho(Dutycycle) variável e, portanto, um tempo ligado(Ton) também variável. Assim, se variarmos o dutycycle, temos uma variação no nível médio do sinal. Isso serve para algumas coisas, como intensidade de rotação, etc. O PWM consiste então em aumentar ou diminuir o Ton, comparado ao período para que forneça uma ideia de ajuste proporcional de uma carga conectada ao micro.
- Como configurar:
	- Primeiro precisamos escolher um timer e verificar qual sua saída. Depois, devemos indicar ao micro que o pino será saída. Para isso usa-se o DDRx.
	- Consideremos que escolhemos o Timer 0. Sua saída é dada pelo OCR0A(Comparador A do Timer 0). Para ele usamos o pino PD6.
	- Com o pino configurado, precisamos agora configurar o TIMER, pois é ele que irá gerar os tempos que serão utilizados para ligar e desligar a saída. Precisamos agora configurar o SER e RESET do TCCR0A. Essa configuração faz com que haja uma transição toda vez que o TIMER alcançar o OCR0A e o TCNT0 reseta. (TCCR0A |= (1<<COM0A1);)
	- Agora devemos configurar o modo de operação do TIMER0, que iremos usar o FAST PWM(TCCR0A |= (1<<WGM00) | (1<<WGM01);).
	- Agora escolhemos o prescaler do clock