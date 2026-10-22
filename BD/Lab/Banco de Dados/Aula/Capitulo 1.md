## O que é um banco de dados?
* Um banco de dados é uma grande coleção de dados que se relacionam de alguma maneira de forma a criar um sentido.
* Dados são fatos que podem ser gravados e que, quando possuem um sentido implícito, se tornam informação.

---
## Como eram guardados os dados antes?
* Era feito com arquivos tradicionais de um computador, o que poderia causar:
  1) Inconsistência e Redundância de Dados;
  2) Dificuldade de Acesso a Dados;
  3) Falta de Isolamento de Dados;
  4) Problemas de Integridade;
  5) Problemas de Atomicidade;
  6) Problemas com Acesso Concorrente;
  7) Problemas de Segurança;
  e muitos outros...

---
## O que é um SGBD?
* Um sistema projetado para gerir grandes volumes de dados.
* Eles precisam fornecer:
  * Recursos para definição das estruturas de armazenamento de dados.
  * Mecanismos de manipulação de dados.
  * Segurança no processo de armazenamento e acesso desses dados.
* Níveis de abstração:
  * **Nível físico**: Usuários que entendam todos os detalhes dos bastidores. Ex.: Criadores de uma ferramenta de BD.
  * **Nível lógico**: Usuários que compreendem bem como usar uma ferramenta de BD. Ex.: Desenvolvedores de aplicações e DBA's.
  * **Nível visão**: Os que usam os serviços.
* Instâncias e Esquemas:
  * **Instâncias**: Informações contidas em um BD em um determinado momento.
  * **Esquemas**: Projeto geral do Banco de Dados ("Esqueleto de um Banco de Dados").
* Independência de Dados:
  * Capacidade de modificar o Esquema de um BD sem afetar as aplicações conectadas a ele.
  * **Independência Física**: Modifica o esquema físico sem que qualquer programa precise ser reescrito.
  * **Independência Lógica**: Modifica o esquema lógico sem que qualquer programa precise ser reescrito.

---
## Modelos de Dados
Conjunto de ferramentas conceituais usadas para a descrição e relacionamento entre os dados.

Os modelos usados recentemente são subdivididos em 3 grupos:
1) Modelos Lógicos com base em Objetos.
2) Modelos Lógicos com base em Registros.
3) Modelos Físicos (Não abordaremos esses).

* **Modelos Lógicos com base em Objetos**:
  * Utilizado nas primeiras etapas do projeto de um BD Relacional.
  * Usa-se de Recursos de Estruturação Flexíveis (peças ou representações gráficas que representam cada parte de um BD e que podem ser facilmente modificadas).
  * Mais conhecidos:
    * ***Modelo entidade-relacionamento***.
    * Modelo orientado a objeto.
    * Modelo semântico de dados.
    * Modelo funcional de dados.
* **Modelo Entidade-Relacionamento**:
  * Percepção do mundo real como conjunto de objetos básicos.
  * Toda estrutura pode ser expressa graficamente por um diagrama.
  * ***Entidades***: Coisa ou objeto do mundo real que precisa ser armazenado no Banco de dados. Ex.: Pessoa.
  * ***Atributos***: A forma como as entidades são descritas. Ex.: RG, CPF, Nome, Endereço, etc.
  * ***Relacionamentos***: A associação entre entidades. Ex.: Uma chave e um cadeado, uma pessoa e um curso.
* **Modelos Lógicos com base em Registros**:
  * Já estruturamos o BD em formato de tabelas.
  * Registros já podem ser adicionados.
  * Cada registro é formado por um conjunto de atributos.
  * Mais conhecidos:
    * Modelo Relacional.
    * Modelo de Rede.
    * Modelo Hierárquico.

---
## Linguagens de Bancos de Dados
Os Bancos de Dados Relacionais usam o SQL para gerenciamento de dados, que internamente possui várias subfamílias de comandos:
* **DDL (Data Definition Language)**:
  * Comandos utilizados para definição, modificação e exclusão de partes relacionadas ao ESQUEMA de um BD.
* **DML (Data Manipulation Language)**:
  * Comandos utilizados para MANIPULAÇÃO de dados como inserção, atualização e exclusão de registros.
* **DCL (Data Control Language)**:
  * Comandos que controlam os aspectos de AUTORIZAÇÃO de acesso ao BD (quem pode ver ou editar dados).

---
## Gerenciamento de Transações
***Uma transação é uma coleção de operações que desempenham uma função lógica ÚNICA, ou seja, ou todo um processo de operações/comunicações juntas dão certo, ou em caso de erro, tudo é retornado ao começo. Uma boa transação deve se basear em um conceito chamado ACID.***
* **ACID**:
  * **ATOMICIDADE** (Tudo ou nada).
  * **CONSISTÊNCIA** (Obedecer a todas as regras do BD).
  * **ISOLAMENTO** (Uma transação não afeta a outra).
  * **DURABILIDADE** (Garante a gravação com sucesso no banco).
* Bancos de Dados Relacionais podem utilizar Transações, e caso usem, é responsabilidade dele detectar falhas e recuperar o BD em caso de uma falha na Transação.
* Para um exemplo, só pensar em uma transação bancária.

---
## Desempenho de um Banco de Dados
* Bancos de Dados exigem um grande volume de armazenamento (medido em TB).
* O desempenho depende da eficiência de suas estruturas internas usadas para a representação dos dados e como o sistema trabalha sobre essas estruturas.
* Vem acompanhados de recursos que permitem realizar otimizações para atenderem a situações de fluxos de dados específicos.
* O hardware onde o SGBD será instalado deve ser compatível com o mesmo e possua uma boa capacidade de armazenamento e processamento de dados.

---
## O adm
***O DBA (Database Administrator) controla o Banco de Dados e o acesso dos programas aos ESQUEMAS com o auxílio do SGBD.***
* Funções de um DBA:
  * Supervisão dos Esquemas criados em uma ferramenta de BD.
  * Autorizar acesso de usuários a Esquemas específicos.
  * Acompanhar o fluxo de dados que está ocorrendo no BD e tomar iniciativas em caso de problemas.
  * Prestar suporte aos devs que precisam conectar suas aplicações a esquemas específicos.

---
## Visão Geral da Estrutura de um BD
***Internamente uma ferramenta de BD geralmente é dividida em módulos de modo a atender todas as funções do sistema.***
* **Processamento de Consultas**:
  * **Compilador DML**: Traduz comandos DML da linguagem de consulta em instruções de baixo nível.
  * **Pré-compilador DML**: Convertem comandos DML em chamadas de procedimentos da linguagem hospedeira.
  * **Interpretador DDL**: Interpreta os comandos DDL e registra-os em um conjunto de tabelas que contêm metadados.
  * **Componentes de Execução de Consultas**: Executa instruções de baixo nível geradas pelo compilador DML.
* **Gerenciamento de Memória**:
  * **Gerenciamento de Autorização e Integridade**: Testam as regras de integridade e a permissão do usuário ao acessar o dado.
  * **Gerenciamento de Transações**: Garante que as transações ocorram sem conflitos.
  * **Gerenciador de Arquivos**: Gerencia a alocação de espaço em disco e as estruturas para representar os dados armazenados.
  * **Gerenciador de Buffer**: Responsável pela intermediação de dados dos disco para a memória principal e qual dados colocar em memória cache.
* **Armazenamento em Disco**:
  Estrutura de dados exigidas para implementação física de um Sistema de Banco de Dados.
  * **Arquivo de Dados**: Armazena o banco de dados.
  * **Dicionário de Dados**: Armazena os metadados relativos à estrutura do banco de dados.
  * **Índices**: Proporcionam acesso rápido aos itens de dados que são associados a valores determinados.
  * **Estatísticas de Dados**: Armazena informações estatísticas relativas aos dados contidos no banco de dados.

* **Visão Geral de uma Estrutura de BD**:

[![imagem-2025-02-22-191058011.png](https://i.postimg.cc/Qxn0Y9fd/imagem-2025-02-22-191058011.png)](https://postimg.cc/BXHTX6Wr)