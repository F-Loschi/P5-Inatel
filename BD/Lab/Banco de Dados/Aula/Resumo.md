## 1.1 Conceitos Iniciais:
- Banco de Dados são coleções de dados que se relacionam de forma que criem sentido.
- Dados são fatos que podem ser gravados e que quando possuem um significado implícito se tornam informações.
### Sistemas de bancos de dados:
Fornecem:
- Recursos para definição das estruturas de armazenamento de dados
- Mecanismos de manipulação de dados
- Segurança no processo de armazenamento e acesso dos dados
## 1.2 Armazenamento em Arquivos Tradicionais:
- Nos tradicionais poderiam acarretar em N erros
### SGBDs:
- Programa que permite ao usuário controlar os dados de forma mais completa e profissional
- Permite ao usuário uma visão abstrata dos dados
## 1.3 Visão de um Banco de Dados
### Níveis de abstração:
Forma como compreendemos um BD
Subdividida em:
- Nível Físico: Usuários que entendem todos os detalhes dos bastidores da criação da ferramenta de um BD
- Nível Lógico: Usuários que compreendem bem como utilizar uma ferramenta de BD
- Nível de Visão: Usuários que usam dos serviços de um banco mas nem sabem disso
### Instâncias e Esquemas:
- Instâncias: Informações contidas em um BD em um determinado momento
- Esquemas: Projeto geral do BD
### Independência de Dados:
Capacidade de modificar o esquema de um BD sem afetar as aplicações conectadas a ele
- Independência Física: Modifica o esquema físico sem que qualquer programa precise ser reescrito
- Independência Lógica: Modifica o esquema lógico sem que qualquer programa precise ser reescrito
## 1.4 Modelos de Dados:
### Modelos Lógicos com Base em Objetos:
- Usado na primeira etapa do projeto de um BD Relacional
#### Modelo Entidade-Relacionamento:
Percepção do mundo real como conjunto de objetos básicos.
- Entidades(Quadrado): Coisa ou objeto do mundo real que precisa ser armazenado no BD
- Atributos(Oval): A forma como a gente descreve as entidades
- Relacionamentos(Losango): A associação entre as Entidades
- Cardinalidade: Número de entidades às quais a outra entidade se relaciona
### Modelos Lógicos com Base em Registros:
- Aqui estamos falando de tabelas propriamente ditas
- Registros, que são formados por um conjunto de atributos, já podem ser adicionados
#### Modelo Relacional:
- Utiliza um conjunto de tabelas para representar tanto dados como o relacionamento
## 1.5 Linguagens de Bancos de Dados:
Bancos de Dados Relacionais utilizam SQL, que é internamente diferenciada por:
1) DDL(Data Definition Language): Definição do esquema
2) DML(Data Management Language): Manipulação de dados
3) DCL(Data Control Language): Controlam a autorização de acesso
## 1.6 Gerenciamento de Transações:
Uma Transação é uma coleção de operações que desempenham uma função lógica única, ou seja, ou tudo funciona ou nada funciona
***ACID***:
1) Atomicidade: tudo ou nada
2) Consistência: obedece as regras do BD
3) Isolamento: Uma transação não interfere na outra
4) Durabilidade: Garante a gravação com sucesso no BD
## 1.7 Desempenho de um BD
- BD exigem um grande volume de armazenamento
- Seu desempenho depende da eficiência de suas estruturas internas
- Acompanham uma série de recursos que permite realizar otimizações
- Importante que o hardware seja compatível
## 1.8 O ADM
O DBA controla o Banco de Dados e o acesso dos programas aos ESQUEMAS com o auxílio do SGBD
Funções:
- Supervisão dos Esquemas
- Autorizar acesso
- Acompanhar o fluxo de dados
- Prestar suporte aos desenvolvedores
## 1.9 Visão Geral da Estrutura de um BD
Internamente é dividida em módulos de modo a atender todas as funções do sistema
### 1.9.1 Processador de Consultas:
1) Compilador DML: Traduz os comandos para instruções de baixo nível
2) Pré-Compilador DML: Convertem comandos DML em chamadas de procedimentos
3) Interpretador DDL: Interpreta os comandos DDL e registra-os em um conjunto de tabelas que contêm metadados
4) Componente de Execução de Consultas: Executa instruções de baixo nível geradas pelo compilador DML
### 1.9.2 Gerenciador de Memória:
1) Gerenciamento de Autorização e Integridade: Testam as regras de integridade e a permissão do usuário ao acessar o dados
2) Gerenciamento de Transações: Garante que tudo ocorra sem conflitos
3) Gerenciador de Arquivos: Gerencia a alocação de espaço em disco e as estruturas para representar os dados armazenados
4) Gerenciador de Buffer: Intermedia os dados do disco para a memória principal e qual dados colocar em memória cache
### 1.9.3 Armazenamento em Disco
Estrutura de dados exigidas para implementação física de um Sistema de Banco de Dados
1) Arquivo de Dados: Armazena o banco de dados
2) Dicionário de Dados: Armazena metadados relativos à estrutura do banco de dados
3) Índices: Proporcionam acesso rápido aos itens de dados que são associado a valores determinados
4) Estatísticas de Dados: Armazena informações estatísticas relativas aos dados contidos no banco de dados

--- 
# 📌 PONTOS ESSENCIAIS PARA A PROVA – INTRODUÇÃO A BANCO DE DADOS

## **1.1 Conceitos Iniciais**
- **Banco de Dados (BD):** Conjunto organizado de dados relacionados para criar sentido.
- **Dados vs Informação:** Dados são fatos brutos; quando possuem significado, viram informação.

## **1.2 Armazenamento em Arquivos Tradicionais**
- Modelos tradicionais tinham problemas como redundância e inconsistência.
- **SGBD (Sistema de Gerenciamento de Banco de Dados):** Software que gerencia BD de forma eficiente e segura.

## **1.3 Visão de um BD**
### **Três níveis de abstração:**
1. **Físico:** Como os dados são armazenados internamente.
2. **Lógico:** Estrutura e relações entre os dados.
3. **Visão:** Como os usuários acessam os dados.

### **Instância vs Esquema:**
- **Instância:** Dados armazenados em um momento específico.
- **Esquema:** Estrutura fixa do BD.

### **Independência de Dados:**
- **Física:** Mudanças na estrutura física não afetam os programas.
- **Lógica:** Mudanças na estrutura lógica não afetam os programas.

## **1.4 Modelos de Dados**
### **Modelos Lógicos com Base em Objetos:**
- **Modelo Entidade-Relacionamento:**
  - **Entidades (🔲 Quadrado):** Objetos do mundo real.
  - **Atributos (⚪ Oval):** Características das entidades.
  - **Relacionamentos (🔷 Losango):** Ligações entre entidades.
  - **Cardinalidade:** Número de relações possíveis entre entidades.

### **Modelo Relacional:**
- Utiliza **tabelas** para armazenar dados.
- Registros possuem **atributos** que definem informações.

## **1.5 Linguagens de BD**
### **SQL e suas subdivisões:**
1. **DDL (Data Definition Language)** – Define a estrutura do BD (`CREATE`, `ALTER`, `DROP`).
2. **DML (Data Manipulation Language)** – Manipula dados (`INSERT`, `UPDATE`, `DELETE`, `SELECT`).
3. **DCL (Data Control Language)** – Controle de acesso (`GRANT`, `REVOKE`).

## **1.6 Gerenciamento de Transações**
### **Transação:** Conjunto de operações que devem ser executadas **integralmente**.
### **Propriedades ACID:**
1. **Atomicidade:** Ou tudo acontece ou nada acontece.
2. **Consistência:** Mantém a integridade dos dados.
3. **Isolamento:** Transações não interferem entre si.
4. **Durabilidade:** Dados permanecem gravados mesmo após falhas.

## **1.7 Desempenho de um BD**
- **Otimização** das estruturas internas melhora o desempenho.
- **Hardware adequado** influencia a eficiência do sistema.

## **1.8 Administração de Banco de Dados (DBA)**
### **Responsabilidades do DBA:**
- Gerenciar esquemas.
- Controlar acessos.
- Monitorar fluxo de dados.
- Prestar suporte a desenvolvedores.

## **1.9 Estrutura Interna de um BD**
### **Componentes principais:**
- **Processador de Consultas:** Tradução e execução de comandos SQL.
- **Gerenciador de Memória:** Controla acesso, transações e integridade dos dados.
- **Armazenamento em Disco:** Contém dados, índices e metadados.

### **Elementos de armazenamento:**
1. **Arquivos de Dados:** Contém os dados do BD.
2. **Dicionário de Dados:** Contém metadados sobre a estrutura do BD.
3. **Índices:** Melhoram a velocidade de busca dos dados.
4. **Estatísticas de Dados:** Otimizam consultas e desempenho.

---
