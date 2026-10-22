DROP DATABASE IF EXISTS exercicio_procedure_functions;
CREATE DATABASE exercicio_procedure_functions;
USE exercicio_procedure_functions;

CREATE TABLE Aluno(
	id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(50),
    idade INT,
    curso VARCHAR(3),
    email VARCHAR(70)
);

DELIMITER $$
DROP FUNCTION IF EXISTS criaEmailAluno $$
CREATE FUNCTION criaEmailAluno(nome VARCHAR(50), curso VARCHAR(3)) RETURNS VARCHAR(70)
deterministic
begin
	DECLARE email VARCHAR(70);
	SET email = concat(nome, '@', curso, '.inatel.br'); 
	RETURN email;
END $$
DELIMITER ;

DELIMITER $$
DROP PROCEDURE IF EXISTS insereAluno $$
CREATE PROCEDURE  insereAluno(IN nome VARCHAR(50), IN idade INT, IN curso VARCHAR(3))
BEGIN
	DECLARE emailGerado VARCHAR(70);
    SET emailGerado = criaEmailAluno(nome, curso);
    INSERT INTO Aluno(id, nome, idade, curso, email) VALUES (DEFAULT, nome, idade, curso, emailGerado);
END $$
DELIMITER ;

SELECT * FROM Aluno;

CALL insereAluno('Joao', 20, 'ges');
CALL insereAluno('Maria', 21, 'gec');
CALL insereAluno('Jose', 18, 'geb');
CALL insereAluno('Ana', 29, 'get');