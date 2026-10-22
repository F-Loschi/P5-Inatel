## Arrays:
- São coleções que possuem um tamanho ***fixo***, o que gera alguns problemas de manipulação
##  Coleções:
 - São usadas para resolver os problemas relacionadas a arrays.
 - O que utilizaremos é a ArrayList. 
## Listas:
- Possibilita usar listas, que é um array de tamanho variável.
- Para adicionar algo a lista, utilizamos o método add.
- Começamos usando uma lista genérica, que aceita todo tipo de dado.
	- O problema disso é não saber, necessariamente, o tipo da variável que está sendo guardado em uma casa aleatória da lista, o que pode nos gerar problemas posteriores quando consultamos a lista.
- Por isso, usamos listas para tipos específicos.
- Assim, o próprio compilador nos protege de adicionarmos elementos inadequados
```java
List<String> listaDeString = new ArrayList<String>();
listaDeString.add(1);//Não funciona, pois tenta adicionar um int em um list de Strings
listaDeString.add("1");
listaDeString.add("QualquerString");
```
- Podemos também criar uma lista de tipos criado por nós mesmo, ou seja, classes e interfaces
- Java já possui, dentro do Collections, métodos estáticos para fazer os sorts que foi aprendido em Algoritmos II.
```java
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        List<String> listaDeString = new ArrayList<String>();
        listaDeString.add("Zebra");
        listaDeString.add("Alpaca");
        Collections.sort(listaDeString);

        for (String elemento : listaDeString) {
            System.out.println(elemento);
        }
        //O sout é Alpaca seguido de Zebra
    }
}
```
- A interface List não aceita tipos primitivos, apenas classes. Para resolver isso, Java possui as chamadas Classes Wrappers, que fazem classes de tipos primitivos. Temos integer para o Int.
```java
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        List<Integer> listaInteiros = new ArrayList<>();
        listaInteiros.add(74);
        listaInteiros.add(3);
        listaInteiros.add(879);
        listaInteiros.add(47);

        Collections.sort(listaInteiros);

        // Enhanced for loop
        for (int numero : listaInteiros) {
            System.out.println(numero);
        }

        // Traditional for loop
        for (int i = 0; i < listaInteiros.size(); i++) {
            System.out.println(listaInteiros.get(i));
        }
    }
}
```
- Para ordenar nossas próprias classes, implementamos a interface Comparable e sobrescrevemos o método compareTo.
- A interface Comparable é parametrizada, então devemos passar, entre <>, qual classe devemos comparar
```java
public class Brownie implements Comparable<Brownie> {
    protected String nome;
    protected double preco;
    protected String sabor;

    @Override
    public int compareTo(Brownie o) {
        // Example comparison by price (ascending order)
        return Double.compare(this.preco, o.preco);
        
        // Alternative: comparison by name
        // return this.nome.compareTo(o.nome);
    }
}
```
- Se desejamos fazer ordenação crescente, basta devolver um valor negativo caso nossa instância seja menor que o Brownie recebido por parâmetro. E passamos um valor positivo caos nossa instância seja maior. Se forem iguais, devolvemos zero(0).
- Para fazer a ordenação decrescente, devemos apenas fazer essa lógica ao contrário.
```java
public class Brownie implements Comparable<Brownie> {
    protected String nome;
    protected double preco;
    protected String sabor;

    @Override
    public int compareTo(Brownie o) {
        if (this.preco < o.preco) {
            return -1;
        }
        if (this.preco > o.preco) {
            return 1;
        }
        return 0;
    }
}
```
