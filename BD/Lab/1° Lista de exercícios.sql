DROP DATABASE IF EXISTS aula3;
CREATE DATABASE aula3;
USE aula3;

#COMANDO PARA DESATIVAR O SAFE MODE
SET SQL_SAFE_UPDATES = 0;

#QUESTAO 1
CREATE TABLE IF NOT EXISTS pessoa(
	id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(45),
    endereco VARCHAR(45),
    cargo VARCHAR(45)
);

#RESPONDA A QUESTAO 1 AQUI
# a)
INSERT INTO pessoa() VALUES(DEFAULT, "Felipe Tagawa", "Varginha", "GP");
INSERT INTO pessoa() VALUES(DEFAULT, "Pedro", "Três Corações", "Motorista");
INSERT INTO pessoa() VALUES(DEFAULT, "Beatriz", "Pouso Alegre", "Professora");
# b)
SELECT nome FROM pessoa;
# c)
UPDATE pessoa SET endereco = "Poços de Caldas" WHERE ID = 1;
SELECT * FROM pessoa;
# d)
DELETE FROM pessoa WHERE id = 3;
SELECT * FROM pessoa;

#QUESTAO 2
CREATE TABLE IF NOT EXISTS empresa(
	matricula INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(45),
    cpf VARCHAR(45),
    cargo VARCHAR(45),
    nProjetos INT
);

#RESPONDA A QUESTAO 2 AQUI
# a)
INSERT INTO empresa() VALUES(DEFAULT, "Junior", "000.000.000-00", "GP", 2);
INSERT INTO empresa() VALUES(DEFAULT, "Maria", "111.111.111-11", "Desenvolvedor", 3);
INSERT INTO empresa() VALUES(DEFAULT, "Carlos", "222.222.222-22", "Tester", 4);
INSERT INTO empresa() VALUES(DEFAULT, "Julia", "333.333.333-33", "Desenvolvedor", 5);
# b)
SELECT COUNT(*) AS funcionarios_4_projetos
FROM empresa
WHERE nProjetos >= 4;
# c)
SELECT AVG(nProjetos) AS media_projetos
FROM empresa
WHERE Cargo <> 'GP';
# d)
SELECT DISTINCT cargo FROM empresa;
# e)
SELECT nome, cpf,nProjetos FROM empresa WHERE cargo = "Desenvolvedor";

#QUESTAO 3
CREATE TABLE IF NOT EXISTS aluno(
	matricula INT NOT NULL PRIMARY KEY,
    nome VARCHAR(45),
    endereco VARCHAR(45),
    ano_nasc INT,
    curso VARCHAR(45)
);

#RESPONDA AS QUESTOES 3 E 4 AQUI
# 3)
# a)
# A coluna matrícula pode ser usada como primary key, uma vez que cada um tem a sua
# b)
INSERT INTO aluno(nome, matricula, endereco, ano_nasc, curso) 
VALUES ("Carlos", "333", "Rua 0", "2003", "GEB");
INSERT INTO aluno() 
VALUES ("123", "Janaina", "Rua 1", "1998", "GEB");
INSERT INTO aluno() 
VALUES ("213", "Luca", "Rua 2", "2004", "GES");
INSERT INTO aluno(nome, matricula, endereco, ano_nasc, curso) 
VALUES ("Paula", "223", "Rua 3", "2000", "GEC");
# 4)
# a)
INSERT INTO aluno(nome, matricula, endereco, ano_nasc, curso) 
VALUES ("Pedro", "225", "Rua 25", "1999", "GEA");
INSERT INTO aluno(nome, matricula, endereco, ano_nasc, curso) 
VALUES ("Jander", "109", "Rua 10", "2000", "GES");
INSERT INTO aluno(nome, matricula, endereco, ano_nasc, curso) 
VALUES ("Laura", "342", "Rua 3", "2002", "GEC");
SELECT * FROM aluno;
# b)
SELECT nome, matricula, curso FROM aluno WHERE nome LIKE "Jan%" AND LENGTH(Nome) = 7;
# c)
SELECT nome, curso FROM aluno WHERE nome LIKE "L%A";
# D)
SELECT nome, ano_nasc, curso FROM aluno WHERE ano_nasc <=2000;
# E)
SELECT * FROM aluno LIMIT 4;
# F)
UPDATE aluno SET endereco = "Rua das Cuecas" WHERE curso = "GES";
# G)
DELETE FROM aluno WHERE curso = "GES";
SELECT * FROM aluno;
#Atencao: para a resposta da letra A, preencha a linha da tabela da resposta no comando 'CREATE TABLE' com ''
#Exemplo: caso você acredite que a chave primária deva ser o campo "ano_nasc" preencha na linha com 'ano_nasc INT NOT NULL PRIMARY KEY'
