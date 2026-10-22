## Aula 2 - Introdução Java:
- WORE: Write once, run everywhere. A ideia de escrever um único código que pudesse ser rodado em qualquer tipo de dispositivo.
- JVM: Java Virtual Machine - Realiza o trabalho de Garbage Collector(Gerência de memória), escalonamento de threads e pilhas de execução. Máquina virtual que interpreta o bytecode.
- JRE: Java Runtime Enviroment - Ambiente de execução do java. Formado por bibliotecas e a JVM.
- JDK: Formada pela JRE e por ferramentas adicionais para se criar aplicações Java
## Aula 3 - Variáveis Primitivas e etc:
- Java é fortemente tipado
- Tipos primitivos são os mesmos de C++
- String pode ser usado como um tipo primitivo, mas é uma classe especial do Java(o que significa que pode dar NullPointerException)
	- Não se compara Strings com == por ser uma classe especial. Se fizer isso, ele vai estar comparando dois endereços de memória, não o que há dentro do ponteiro
- Por ser fortemente tipado, não podemos, normalmente, por exemplo, atribuir uma variável a outra que não seja do mesmo tipo, a não ser que não há perca de informação.
	- Podemos resolver isso com Casting e Promoção:
```java
		- double numero = 3.14;
		- int numero2 = (int)numero;
		- 
		- int x=10;
		- long x1=x;
```
- As estruturas de decisão são as mesmas de C++ e seguem o mesmo padrão de escrita e funcionamento, desde if a switch-case
- As estruturas de repetição também seguem
## Aula 4 - Introdução a POO:
* Java é uma linguagem com programação orientada a objetos, que é visto como uma evolução da programação estruturada e que tenta replicar o mundo real em código
* Classes são a nossa receita e mostra como deve ser o real, ela é a especificação
* A instância da classe é o objeto concreto, é o que é feito da receita. Mesmo usando a mesma receita para fazer dois bolos, os bolos não sairão iguais.
* Variáveis declaradas no escopo da classe são chamadas de "Membros da classe" ou simplesmente de atributos
* Os métodos são o que a classe sabe fazer e eles são invocados usando o operador "."
* Quando declaramos uma variável para guardar um objeto, na verdade guardamos uma referência para o endereço de memória, o que significa que estamos falando de ponteiros.
	* Assim se criarmos duas instâncias de uma classe, com os mesmos valores para todos seus atributos e as igualarmos, isso retornará um "false", pois estaremos, na verdade, igualando dois endereços de memória
* UML(Unified Modeling Language): É uma linguagem visual do software
* Relacionamento entre objetos: Chamamos a comunicação entre classes de Associação, que significa que um objeto contém ou está conectado a outro objeto
	* Agregação: Um tipo de associação todo/parte. A existência de um faz sentido mesmo sem termos o outro. Atletas(parte) podem existir sem o time(todo). Feito com uma associação na main.
	* Composição: Também é uma associação todo/parte, mas aqui não faz sentido termos o parte sem termos o todo. Impossível eu ter um departamento(parte) sem ter uma empresa(todo). Feito com o construtor.
## Aula 5 - Arrays:
- Coleção de um ou mais objetos do mesmo tipo armazenados em endereços adjacentes de memória
- Cada elemento é chamado de elemento de array
- Um array de tipos primitivos guarda valores, um de objeto guarda referências(endereços de memória)
- Multiplicidade == Cardinalidade
- Arrays multidimensionais são matrizes
## Aula 6 - Pacotes:
- Um jeito legal de organizar as classes Java
## Aula 7 - Modificadores de Acesso:
- Para evitar o fuzue de escrever coisas impossíveis, usamos modificadores de acesso para impossibilitar maluquices.
- Public: Todo mundo consegue ver, utilizar e modificar
- Private: Faz com que modificações só possam ser feitas dentro da própria classe(De mais comum uso, principalmente para os membros da classe). A ideia é encapsular o estado do objeto e deixar que apenas a classe modifique seu estado.
	- Como não temos acesso direto aos membros quando usamos private, usamos getters e setters para fazer modificações e verificações
## Aula 8 - Construtores e o Modificador Static:
- Construtor implícito: Quando não fazemos um construtor explícito para o Java, ele constrói um próprio por debaixo dos panos
- Construindo um construtor próprio, obrigamos o uso de parâmetros, pois não compila se não passarmos nada tendo um construtor
- Imagine que colocamos um contador dentro da classe para contar quantas instâncias temos. Ao criar 3 instâncias e dar um sout nesse contador, qual será a saída? 1, pois cada instância da classe cria seu próprio contador que é incrementado apenas uma vez. 
- Quando precisamos compartilhar algo entre as instâncias como nesse caso, usamos o modificador Static, que significa que esse algo não pertence a instância e sim a classe
- Métodos do tipo static são métodos que não dependem de nenhuma variável de instância e quando invocados, executam uma função sem a dependência do conteúdo de um objeto.
	- Criado como o membro de um objeto, mas não precisa de uma instância para ser acessado
## Aula 9 - Herança e Polimorfismo:
### Herança:
- Quando temos classes que possuem membros e métodos muito parecidos e apenas com algumas poucas diferenças, podemos criar uma classe maior com os atributos e métodos em comum das classes e fazer com que as menores herdem da maior. 
- Nesse sentido, a classe maior é chamada de Classe Mãe ou Superclasse e a classe menor é chamada de Classe Filho ou Subclasse.
- Para isso, usamos o modificador de acesso **protected**, que é mais limitado que o **public**, porém, menos restrito que o **private**, é um modificador de acesso que está no meio termo da coisa toda. Com esse modificador, **somente a prórpia classe  e as subclasses podem ter acesso a esses membros**. Esse modificador é utilizado nos membros da superclasse.
- As especializações das subclasses, ou seja, os membros e métodos que são específicos da subclasse, são definidos apenas na subclasse.
### Polimorfismo:
- Permite que um mesmo nome represente vários comportamentos diferentes.
- Podemos especializar algo da superclasse na subclasse usando a sobrescrita de método, que é feito usando o @Override.
- Quando dizemos que uma subclasse herda uma superclasse, significa que a subclasse não deixa de ser o que a superclasse é, o que significa que podemos guardar uma instância da subclasse em uma variável do tipo da superclasse.
- Quando fazemos isso, ao chamar métodos que foram sobrescritos na subclasse, o que será chamado é o método sobrescrito, não o da superclasse, pois mesmo guardando a instância dentro de uma variável da superclasse, a instância não deixa de ser da subclasse.
- Porém, fazendo isso, o que não podemos é chamar métodos específicos da subclasse, pois ela está dentro de uma variável do tipo da superclasse, que não conhece o método específico da subclasse.
- Para utilizar os métodos específicos da subclasse, precisamos primeiro ver se a instância que está sendo guardada é da subclasse que queremos. Para isso, usamos o **instanceof**, que testa para ver se é uma instância de uma classe específica. Ao realizar esse teste e termos uma confirmação, podemos fazer um casting para mudar o tipo da variável para o tipo da subclasse e então chamar o método específico.
- A vantagem é deixar nossas funcionalidades mais genéricas
## Aula 10 - Classes Abstratas:
- Classes abstratas são usadas quando não faz sentido termos instâncias da superclasse. Ou seja, é uma classe que não pode ser instanciada. Nesse sentido, ela serve meio que como uma receita de bolo, para sabermos o que devemos ter nas nossas subclasses. "A classe Brownie é criada apenas para ser referências(variáveis) e não instâncias(objetos na memória)"
- Quando usamos o "abstract" na definição da superclasse e definimos que não desejamos instanciar essa classe, que ela deve ser uma superclasse e suas subclasses serão instanciadas e que ela deve ser usada como referência para permitir o polimorfismo.
- Não é correto dizer que toda superclasse deve ser uma classe abstrata, pois ainda podemos usar herança em cadeia, que significa que, em algum momento, uma instância de uma classe abstrata também será uma superclasse.
- Se quisermos forçar uma subclasse a especializar um método da superclasse, podemos usar o modificador abstract no método da superclasse, que força a subclasse a especializar o método antes de poder utilizá-lo. Ao fazer isso, não podemos mais definir o comportamento do método, mas devemos deixar apenas a assinatura do método
## Aula 11 - Interfaces:
- Um conjunto de métodos públicos é conhecido como "interface da classe", pois é a única forma de trocar mensagens com ela.
- Uma interface é um tipo de classe que contém especificações para as outras classes, um manual de implementação.
- Uma classe que implementa uma interface é obrigada a implementar todos os métodos especificados e a especializá-los.
- Interface vs Classe Abstrata:
	- Ambas não podem ser instanciadas
	- Ambas definem novos tipos
	- Classes podem implementar várias interfaces, mas herdar apenas uma superclasse
	- Na prática, uma classe abstrata que não possui membros e apenas métodos abstratos é uma interface