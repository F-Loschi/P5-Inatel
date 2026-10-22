## Pra que usar essa bomba?
É mais fácil usar um micro que te deixa só atualizar um software toda vez que você precisar fazer uma mudança no seu sistema do que ter que ficar mudando a sua placa inteira toda vez que você quiser fazer uma única mudança.
## O ATMEGA328:
O micro que a gente usa que está embutido no arduíno
## Se eu quero definir uma porta como entrada ou saída, como eu faço?
Uso o DDRx, sendo que o meu x vai ser substituído por B, C ou D, a depender de qual família de portas eu estou mexendo. Para falar que uma porta específica é entrada, eu seto ela como 0 e para falar que é saída, seto como 1. 
Para fazer essas alterações, eu posso tanto usar o formato binário, como números inteiros(mais simples quando uma família é inteira entrada ou inteira saída) ou simplesmente deslocar 1 na porta que eu quero usar. 
Por exemplo, se eu quero setar a porta D4 como saída, eu posso fazer fazer tanto DDRD=0b00010000; ou DDRD |= (1<<PD4);
Se caso você quisesse usar a família B como entrada, poderia definir como DDRB = 0;
## Se eu quisesse definir uma casa que foi definida como saída como inicialmente ligada?
Fazemos isso com o PORTx.
Usamos o PORT para definir algo como inicialmente no alto ou no baixo.
Por exemplo, para definir o PB4 como inicialmente ligado, fazemos: PORTB = 0b00010000; mas isso faz com que eu mexa com as outras portas também quando eu só quero mexer com uma delas, então podemos mexer só com ela da seguinte forma: PORTB |= (1<<PB4);
## Pra que usamos um Pull-up ou um Pull-down?
O pull-up é usado quando queremos garantir que um pino de entrada fique em HIGH quando não há nada conectado a ele. O pull-down faz o mesmo, mas garantindo que o pino fique em LOW.
Definimos tanto o pull-up  pelo PORTx, definindo as entradas que tem um estado indefinido. O AVR possui apenas um resistor de pull-up interno, mas não um resistor de pull-down interno, então podemos definir apenas o pull-up.
Para um pull-up no PD4, por exemplo, definiriamos como: PORTD |= (1<<PD4);
## Verificação
Para verificar um pino, quando queremos, por exemplo, verificar se um botão está sendo pressionado ou não, verificamos usando o PINx.
Para verificar se, por exemplo, o PD4 está em HIGH, verificamos da seguinte forma: if(PIND & (1<<PD4))
Para verificar se ele está em LOW, verificamos da seguinte forma: if(!(PIND &(1<<PD4)))
## Interrupção:
A lógica da interrupção está no nome, interromper. Ela é feita quando precisamos interromper nosso código quando algo acontece. Se, por exemplo, eu estou escrevendo um código para uma máquina de uma fábrica que precisa de um botão de interrupção imediata da máquina para caso algo aconteça, usamos a lógica da interrupção. A rotina de interrupção **pausa** o que estava acontecendo, **executa o código da interrupção** e, quando termina, o programa **continua exatamente de onde parou**.
A interrupção de um Arduíno segue uma cadeia de preferências. O maior na cadeia de preferência é o botão de reset do arduíno, que aqui não interessa tanto. Seguindo a cadeia, temos o INT0 e o INT1, que são, respectivamente, o segundo e terceiro na cadeia de preferência do arduíno. Eles estão ligados diretamente aos pinos PD2 e PD3. Seguindo a linha de comando, teríamos os PCINTs, mas esse não vai ser cobrado na prova.
Para a interrupção temos coisas a serem definidas:
* EIMSK: Habilita as interrupções no INT0 e no INT1 
* EICRA: Define como a interrupção no INT0 e no INT1 vão acontecer, se é por descida ou por subida.
* sei(): Habilita globalmente as interrupções externas
* ISR(INT0_vect): Função que define a rotina de interrupção do INT0
* ISR(INT1_vect): Função que define a rotina de interrupção do INT1