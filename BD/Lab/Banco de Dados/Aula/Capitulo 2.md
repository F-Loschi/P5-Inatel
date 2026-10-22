## 2.1 Conceitos Básicos  
### 2.1.1 Conjunto de Entidades  
* Um conjunto de entidades agrupa entidades do mesmo tipo, que possuem os mesmos atributos.  
* Exemplo:  
  * Funcionários de uma empresa → Conjunto de Entidades Funcionários  
  * Produtos fabricados pela empresa → Conjunto de Entidades Produtos  
* Uma entidade é um objeto ou coisa do mundo real que pode ser identificada de maneira ***única*** em relação às demais.  
* Entidades podem ser:  
  * **Concretas**, como um empregado.  
  * **Abstratas**, como um departamento.  
### 2.1.2 Atributos  
Os conjuntos de entidades são representados por atributos, que são propriedades descritivas associadas a eles.  

* **Simples**: Representados por um único atributo. Ex.: Nome.  
* **Compostos**: Podem ser subdivididos em partes menores. Ex.: Endereço (Rua, Número, Cidade).  
* **Monovalorados**: Possuem apenas um valor por entidade. Ex.: Primeiro Nome, Matrícula, Idade.  
* **Multivalorados**: Possuem um conjunto de valores para uma única entidade. Ex.: Telefones, Dependentes, E-mails. Representado por um círculo dentro de outro.  
* **Derivados**: Obtidos a partir de outros atributos. Ex.: Idade, derivada do atributo Data de Nascimento. Representado por um círculo pontilhado.  
* **Chave**: Identifica de forma única cada entidade. Ex.: Matrícula de um Empregado.  
### 2.1.3 Conjunto de Relacionamentos  
Um conjunto de relacionamentos conecta uma ou mais entidades. Um ***relacionamento*** é uma associação entre entidades.  

* **Grau de um Relacionamento**: Indica o número de conjuntos de entidades que participam de um relacionamento.  
  * **Relacionamento Unário**: Envolve uma única entidade (grau 1).  
  * **Relacionamento Binário**: Envolve duas entidades (grau 2).  
## 2.3 Cardinalidade  
Define a quantidade de entidades que podem se associar em um relacionamento.  
### 2.3.1 Um para Um  
Uma entidade "A" pode estar associada, ***no máximo***, a uma entidade "B".  
### 2.3.2 Um para Muitos  
Uma entidade "A" pode estar associada a ***várias*** entidades "B", mas cada entidade "B" está associada a apenas uma "A".  
### 2.3.3 Muitos para Muitos  
Uma entidade "A" pode estar associada a várias entidades "B", e uma entidade "B" pode estar associada a várias entidades "A".  
Exemplo:
![[Relacionamento.jpg]]
Exercício:
![[Berçario.jpg]]
### 2.3.4 - Restrições de Participações:
* Indicam de forma mais objetiva as obrigatoriedades
* Participação parcial: quando não existe a obrigatoriedade do relacionamento(mínimo 0) - linha simples
* Participação total: acontece quando existe a obrigatoriedade do relacionamento(mínimo 1)- linha dupla
## 2.4 - Chaves:
### Chaves primárias: 
Atributo que permite identificar uma entidade de maneira ÚNICA no meio das outras
### Chaves Compostas:
Conjunto de dois ou mais atributos que, tomados coletivamente, permite identificar uma entidade de maneira ÚNICA.
## 2.6 - Conjunto de Entidades Fracas:
Pode depender fortemente de outro Conjunto para fazer sentido existir. Este tipo de Conjunto é denominado CONJUNTO DE ENTIDADES FRACAS.
* Um retângulo dentro do outro
* Seu identificador é chamado de Chave Parcial
* Sua chave primária é formada por:  Chave Primária da Entidade Dominante + Chave Parcial
## 2.7 - Especialização:
Um conjunto de entidade pode conter subgrupos de Entidades