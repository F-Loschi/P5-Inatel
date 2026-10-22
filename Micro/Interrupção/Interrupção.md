O código roda normalmente dentro de um loop infinito e quando um comando específico é disparado, ele para o que está fazendo e roda um outro código de interrupção até o fim e depois volta ao loop.
* Externa: Quando eu tenho um sensor ou chave conectado ao micro e o sensor manda um sinal que interrompe o código
* Interna: Quando eu tenho, por exemplo, um temporizador que vai interromper o código quando terminar
* Mascarável: Um laço que não é interrompível de maneira alguma
* Não mascarável: O contrário, quando é interrompível
* INT0: PD2
* INT1: PD3
## EICRA: External Interrupt Control Register A
Define como INT0 e INT1 são ativados: por borda ou por nível
