## 3.1 Conceitos do Modelo Relacional
* Um banco de dados relacional consiste em uma coleção de **tabelas** cada uma com um nome único, e que podem ou não se relacionar
* Representa o BD como uma coleção de **relações**, que geralmente se relacionam entre si
## 3.2 Domínio, Atributos, Tuplas e Relações
* A tabela também é formalmente chamada de relação
* Um linha também é formalmente chamada de **tupla**
* Um cabeçalho de coluna é chamado de **atributo**
* O tipo e formato de dado que descreve o atributo é representado pelo **domínio** do atributo
* Exemplo:
	* ![[Pasted image 20250423142619.png]]
	* Cada tupla representa uma entidade aluno
	* Cada atributo corresponde a uma cabeça da coluna
	* Valores NULL representam atributos cujos valores não existem
* Um **esquema de relação**, indicado por R(A1, A2, An) é composto de um nome de relação "R" e de uma lista de atributos "A1, A2, An"
* Exemplo:
	* FUNCIONARIO(**CPF**, Nome, Endereco, Fone, Data_Nasc, Cargo)
* O **grau de uma relação** é o número n de atributos de seu esquema de relação (O grau de relação de FUNCIONARIO é 6)
## 3.3 Mapeamento
Vamos transformar esse DER em um modelo de bancos de dados relacional:
![[Pasted image 20250423143503.png]]
Para isso, precisamos fazer um mapeamentos das:
1) Entidades:
	* Para cada entidade de um Esquema de Banco de Dados, cria-se uma RELAÇÃO "R" que inclua todos os atributos SIMPLES da Entidade
	* Nos **atributos compostos**, o atributo mais geral some e seus atributos partes viram atributos simples (Data_Nasc fica como atributo simples e Idade some)
	* Os **atributos multivalorados** são representados como Relações(Tabelas) separadas (Uma nova Relação deverá ser criada exclusivamente para este atributo, com relacionamento 1 para N) 
	* **Chave Primária**: deverá ser o atributo chave de um respectivo Conjunto de Entidades.
	* **Chave Estrangeira**: é um atributo que se refere à chave primária de outra Entidade. O domínio da chave estrangeira deve ser idêntico ao domínio da chave primária que ela se relaciona
	* ![[Pasted image 20250423144317.png]]
2) Relacionamentos:
	* Relacionamento 1 para 1:
		* **Escolher uma das Relações e nela inserir como Chave Estrangeira a Chave Primária da outra relação**
		* Melhor escolher aquela com a participação total no relacionamento para receber a chave estrangeira(Entre empregado e Departamento, quem recebe é o Departamento)
		* ![[Pasted image 20250423145108.png]]
	* Relacionamento 1 para N:
		* Para cada relacionamento Binário 1 para N ou N para 1 de um Esquema, **inserir a Chave Estrangeira na relação do lado N**.
		* Isso é feito porque cada Instância de uma Entidade do lado N está relacionada a no máximo uma instância do lado 1.
		* Os atributos do relacionamento também são colocados, caso existam, na relação que recebeu a Chave Estrangeira
		* ![[Pasted image 20250423145025.png]]
	* Relacionamento M para N:
		* **Cria-se uma nova Relação para representar o relacionamento**. Insere-se como Chave Estrangeira desta nova Relação as chaves primárias das entidades participantes do relacionamento. A combinação delas formará a Chave Primária desta nova Relação
		* Os atributos do relacionamento, caso existam, deverão ser colocados na nova tabela
		* Não se pode representar um relacionamento M para N por meio de uma simples chave estrangeira em uma das Relações participantes
		* ![[Pasted image 20250423145428.png]]
	* Entidades Fracas:
		* O controle da Entidade fraca está relacionada à Entidade Proprietária. A Entidade Fraca não faz sentido se não existir a Entidade Proprietária.
		* A chave primária de uma Entidade Fraca é formada pela Chave Parcial + Chave Estrangeira
		* ![[Pasted image 20250423145649.png]]
## 3.4 Esquema e Estado de um BD
* Um esquema de BD indicado por E(R1,R2,Rn) é composto de um nome de esquema "E" e de uma lista de Relações "R1", "R2", "Rn"...
* Exemplo:
	* Empresa = {EMPREGRADO, DEPARTAMENTO, DEPTO_LOCALIZACOES, PROJETO, TRABALHA_EM, DEPENDENTE}
	* e abaixo seus esquemas de relações:
	* ![[Pasted image 20250423182923.png]]
* O estado de um BD relacional é a instância(Backup) deste BD, ou seja, um conjunto de dados em um determinado momento
* Importante ressaltar que é uma ótima prática nas empresas gerar e armazenar Instâncias de BDs frequentemente para que, em caso de um "crash" no BD principal, algumas instâncias antigas possam ajudar no processo de recuperação
## 3.5 Restrições do Modelo Relacional
### 1. Restrição de CHAVE
* Um atributo chave é usado para identificar, **UNICAMENTE**, cada tupla na relação. Uma chave não deve variar com o tempo.
## 2. Restrição de ENTIDADE
* Estabelece que NENHUM valor de chave primária pode ser nulo(NULL)
## 3. Restrição de Integridade Referencial
* Se existe um valor de chave estrangeira em uma tupla, ele deve ocorrer como um valor de chave primária em outra tupla(da mesma relação ou outra relação), ou é NULL se, para aquela tupla, não houver relacionamento
## 4. Restrições Semânticas
* Além das restrições automáticas do BD relacional, também podemos criar **restrições semânticas** como:
	1) "O salário de um empregado não deve exceder o do supervisor do empregado"
	2) "O número de horas que um empregado pode trabalhar por semana é 56"
	3) O salário de um empregado pode ser apenas aumentado
* Estas restrições podem ser especificadas e impostas dentro dos nossos programas de aplicações ou até mesmo por meio de recursos oferecidos pelos próprios BDs Relacionais como: **Triggers e Assertions**