## ATMEGA 328 - Timer/Counter
* Clock 0 - T/C0 = 8bits(0-255)
* Clock 1 - T/C1 = 16bits(0-65535)
* Clock 2 - T/C2 = 8bits(0-255)

## Clock 0 (8 bits):
* Frequência do clock é de 16MHz e seu período é 1 sobre isso, logo, para contar de 0 a 255, ele leva 16us(micro segundos). Tendo um led que pisca a cada período, ele pisca 1 vez a cada 16 micro segundos.
## Por isso usamos o Prescaler
* Ele é um divisor que faz o timer enrolar um pouco
* Considerando um prescaler de 256 bits, ele faz o clock contar de 0 a 255 para poder contar 1 vez, o que significa que, agora, ele não conta mais cada bit de 65,5ns(nano segundos) em 65,5ns e sim de 16us em 16us. Assim, agora temos uma frequência de clock de 62,5KHz e um período de 16us. Assim, cada bit agora é contado de 16us em 16us, fazendo com que contar de 0 a 255 agora leve 4,096ms
## Registradores:
* TCCR0A = 0;
* TCCR0B : CS00, CS01, CS02 - Fonte de clock externo e interno(prescaler)
* TCNT0: Guarda o valor atual da contagem
* TIMSK0: Liga a interrupção por overflow(TOIE0)