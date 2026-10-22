## Array Multidimensional  
* Também conhecido como matriz.  
* Funciona da mesma forma que em C++.  

## Declaração  
* Pode ser visto como um array cujas posições armazenam outros arrays, formando assim um "array de arrays".  
* Declarado de maneira semelhante ao C++, utilizando colchetes duplos.  
```java
int [][]matrizExemplo;
matrizExemplo = new int [5][5];
```
## Preenchimento  
* Igual ao C++, utilizando um loop `for` duplo.  
```java
int[][] matrizExemplo;
matrizExemplo = new int[5][5];

for (int i = 0; i < matrizExemplo.length; i++) {
    for (int j = 0; j < matrizExemplo[i].length; j++) {
        matrizExemplo[i][j] = i + j;
    }
}
```
## Percorrendo  
* Pode ser feito com um `for` duplo, como em C++.  
* Também pode ser percorrido usando o "for aprimorado", onde iteramos sobre cada array da matriz, acessando diretamente os arrays que compõem a primeira dimensão.
```java
int[][] matrizExemplo;
matrizExemplo = new int[5][5];

for (int[] linha : matrizExemplo) {
    for (int valores : linha) {
        System.out.print(valores + " ");
    }
    System.out.println("");
}
```
