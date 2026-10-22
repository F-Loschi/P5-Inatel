## Registradores flutuantes:
Registradores que não estão nem ligados no terra nem no vcc, seu valor pode flutuar entre 0 e 1, não se tendo certeza o que ele assume, sendo então chamados de registradores flutuantes
## Resistor de pull-up / pull down:
São usados quando uma entrada digital do microcontrolador não está conectada nem à ***vcc*** e nem à ***gnd***
## Utilização de máscaras
* Ligar um ou mais pinos sem alterar os demais:
	* Faz uma operação lógica | para as casas onde eu quero ligar
	* PORTD = 0b11001011;
	* PORTD = 0b11001011 | 0b00100100;
	* O que vem depois do | é chamado de ***máscara*** 
	* PORTD = PORTD | (1<<PD5) | (1<<PD2);
	* PORTD |= (1<<PD5) | (1<<PD2);
* Desligar um pino sem alterar os demais:
	* Faz uma operação lógica & para as casas onde eu quero desligar
	* PORTD = 0b11000101 & 0b11111011;
	* PORTD = PORTD & ~(1<<PD2);
		* ~(1<<PD2):
			* (1<<PD2) deixaria só o PD2 como 1
			* O ~ inverte isso, que deixa só o PD2 como 0
	* PORTD &= ~(1<<PD2)