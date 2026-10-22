## Funções:
- max(list)
- min(list)
- binarySearch(list, elemento)
	- **Importante**: A lista precisa estar ordenada para usar a busca binária
- reverse(list)
## HashSet
- Possui alto desempenho para buscar elementos.
- Guardar uma lista de elementos e garantir que não haverá duplicidade.
- Utiliza uma tabela hash para guardar os elementos e não garante a ordem.
### Criação:

```java
Set<String> conjunto = new HashSet<String>();
conjunto.add("String_1");
conjunto.add("String_2");
conjunto.add("String_3");
conjunto.add("String_4");
conjunto.add("String_5");
```
### Percorrer:
```java
import java.util.HashSet;
import java.util.Set;

public class ExemploSet {
    public static void main(String[] args) {
        // Criando um conjunto de Strings
        Set<String> conjunto = new HashSet<String>();
        conjunto.add("String_1");
        conjunto.add("String_2");
        conjunto.add("String_3");
        conjunto.add("String_4");
        conjunto.add("String_5");

        // Iterando e imprimindo os elementos do conjunto
        for (String elemento : conjunto) {
            System.out.println(elemento);
        }
    }
}
```
### Remover:
```java
sout(conjunto.remove("String_5"));
/*Retorna true ou false dependendo de ele
conseguir ou não remover o item passado
*/
for(String elemento:conjunto){
	sout(elemento);
}
/*Isso retorna primeiro true e depois todas as strings menos a que foi removida
*/
```
### Iterator:
- Antes do foreach era necessário usar um Iterator para percorrer um Set, que é o que o foreach faz hoje em dia nos bastidores.
### LinkedHashSet:
- Mantém a ordem de inserção, mas perde um pouco em desempenho quando comparado com o HashSet.
- Se não for necessário manter a ordem de inserção, dê preferência ao HashSet.
## Mapas - Chave -> Valor
- Para salvar elementos na forma de um ***dicionário***, onde dada uma palavra(chave) você pegue o seu significado(valor).
- O Java oferece uma interface que é possível salvar elementos na forma ***<chave,valor>***.
- Para fazer inputs, usamos o método put(chave, valor).
- A busca para essa estrutura é a mais rápida dos três
- No Java, o nome Map leva a ideia de mapear um valor
- Depois de inserido, podemos procurar usando get(chave)
```java
import java.util.HashMap;
import java.util.Map;

public class ExemploMapaStreaming {
    public static void main(String[] args) {
        // Criando um mapa de chave: String e valor: Double
        Map<String, Double> mapaPrecoStreaming = new HashMap<>();

        // Adicionando valores
        mapaPrecoStreaming.put("Netflix", 25.90);
        mapaPrecoStreaming.put("PrimeVideo", 14.90);
        mapaPrecoStreaming.put("HBOMax", 19.90);
        mapaPrecoStreaming.put("Crunchyroll", 25.0);
        mapaPrecoStreaming.put("Globoplay", 22.90);  // Corrigido de "Groboplay" para "Globoplay"

        // Iterando e imprimindo os valores do mapa
        for (Map.Entry<String, Double> entrada : mapaPrecoStreaming.entrySet()) {
            System.out.println("Serviço: " + entrada.getKey() + 
                             ", Preço: R$" + entrada.getValue());
        }
    }
}
```
- Só pode existir um único valor para cada chave, o que significa que ao fazer uma inserção de uma chave que já existe uma segunda vez, estamos, na verdade, sobrescrevendo o valor que ele já possui.
- Iterando com lambda:
	- A partir do Java 8, podemos utilizar o método forEach() que está presente na interface do Collections. Combinado com as expressões lambda fica bem mais simples iterar sobre um mapa.
```java
// Iterando pelo mapa usando forEach
mapaPrecoStreaming.forEach((chave, valor) -> {
    System.out.println("Chave: " + chave);
    System.out.println("Valor: " + valor);
});
```
