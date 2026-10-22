## 4.1 - Introdução:
- Tipos de Querys:
	- DDL
	- DCL
- Modelo Relacional vs. SQL:
	- Relação = Tabela
	- Tupla = Linha
	- Atributo = Coluna
## 4.2 Tipos de Dados:
1) Numéricos: 
	- Números Inteiros de vários tamanhos:
		- TINYINT
		- SMALLINT
		- INTEGER
		- BIGINT
	- Número reais:
		- FLOAT
		- DOUBLE
	- Números formatados:
		- DECIMAL(i, j) ou NUMERIC(i, j)
2) Cadeia de Caracteres:
	- Tamanho Fixo: CHAR(n)
	- Tamanho Variável: VARCHAR(n)
3) Booleano:
	- BIT: aceita os valore 1(para representar TRUE), 0(para representar FALSE) e NULL(para valor desconhecido)
4) Date e Time:
	- DATE: Guarda Ano, Mês e Dia no formato YYYY-MM-DD
	- TIME: Guarda hora, minuto e segundo no formato HH-MM-SS
	- DATETIME: Guarda tudo junto no formato da concatenação dos nomes
## 4.3 - Comandos DDL
**Criar primeiro as tabelas e depois falar o que é o que**
### Comando CREATE:
- ESQUEMA: 
	- Identificado por um nome que representa a Base de Dados
	- Agrupa tabelas, view, functions e outros componentes que pertencem a uma mesma base de dados
 - TABELAS:
	- Cada tabelas é identificada por um nome
	- Possui N atributos com tipos e restrições iniciais
	- Restrições ou regras podem ser especificadas
- Restrições:
	- UNIQUE
	- PRIMARY KEY
	- NOT NULL CHECK(checa alguma coisa específica que eu queira)
	- AUTO_INCREMENT
###  Comando DROP: 
- Deleta uma Tabela ou todo um Esquema de um Banco de Dados
### Comando ALTER:
- Adiciona ou elimina uma coluna, altera a definição de uma coluna, adiciona ou remove restrições(regras)
### Comando TRUNCATE:
- Limpa todos os registros de uma Tabela, mas mantém sua estruturas para futuras inserções
### Comando RENAME:
- Renomeia o nome de uma Tabela. Em alguns bancos, também pode ser usado para renomear uma coluna.
## 4.4 Comando DCL:
**Utilizados para conceder e revogar acesso de usuários a um BD**
* Para criar novos usuários, usamos CREATE USER [usuário] IDENTIFIED BY [senha].
* Após um usuário ser criado, precisamos definir os privilégios dela
### Privilégios:
* ALL PRIVILEGES: o usuário tem total liberdade para manipular o banco
* CREATE DROP: o usuário poderá criar e excluir Tabelas em um banco
* INSER UPDATE DELETE SELECT: o usuário pode inserir, atualizar, excluir e buscar informações no Banco
### Comando GRANT
* Permite que o usuário tenha privilégios
### Comando REVOKE:
- Retira as permissões
