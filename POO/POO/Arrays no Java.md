## Arrays:
* Coleção de um ou mais objetos do mesmo tipo armazenados em endereços adjacentes de memória
* Cada objeto é um "elemento do array"
## Como declarar?
```java
/*Declarando uma váriavel que irá
guardar a referência para um array*/
int []x;
int[] y;
int z[];
int [] x = new int[10];//Array de 10 posições
int []y = new int[];//Não compila
int z[] = {1,2,3,4};//Array com 4 posições inicializado com os valores 1,2,3 e 4
```

## Índices
Assim como C/C++/C#, o primeiro índice é 0 e vai até n-1
## Arrays em Java
* A grande diferença é agora criar arrays de tipos de classes. 
* Um array de classe tem suas repartições nulas até que um objeto seja endereçado à ele
## Preenchendo array
Dois jeitos:
1. Cria o array, cria um instância e iguala os dois:
```java
Conta[] contas = new Conta[5];
Conta contal = new Conta();
contal.deposita(quantia: 1000);
// Deposita e aumenta o saldo
contas[0] = contal; //Associando
System.out.println(contas[0].saldo);
```

2.Criar uma instância dentro do próprio array:
```java
Conta[] contas = new Conta[5];

contas[0] = new Conta();
contas[0].deposita(quantia: 1000); // Deposita e aumenta o saldo

System.out.println(contas[0].saldo);
```
## Percorrendo um array
Mesmo de C++
```java
double[] versoesWindows = {95, 98, 2000, 7, 8, 8.1, 10};
// observe o membro "length"
// Ele possui salvo o tamanho do array
for (int i = 0; i < versoesWindows.length; i++) {    System.out.println(versoesWindows[i]);
}
```
Existe ainda o for melhorada
```java
double[] versoesWindows = {95, 98, 2000, 7, 8, 8.1, 10};
for (double versao : versoesWindows) {
    System.out.println(versao);
}
```

