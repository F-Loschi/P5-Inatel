DROP DATABASE IF EXISTS AV2;
CREATE DATABASE IF NOT EXISTS AV2;
USE AV2;

SET SQL_SAFE_UPDATES = 0;

DROP TABLE IF EXISTS Aventureiro;
CREATE TABLE IF NOT EXISTS Aventureiro (
    id INT PRIMARY KEY AUTO_INCREMENT,
    nome VARCHAR(100) NOT NULL,
    classe VARCHAR(50),
    nivel INT,
    experiencia INT DEFAULT 0
);

DROP TABLE IF EXISTS Missao;
CREATE TABLE IF NOT EXISTS Missao (
    id INT PRIMARY KEY AUTO_INCREMENT,
    titulo VARCHAR(100) NOT NULL,
    dificuldade VARCHAR(20),
    recompensa INT
);

DROP TABLE IF EXISTS Participacao;
CREATE TABLE IF NOT EXISTS Participacao (
    aventureiro_id INT,
    missao_id INT,
    status VARCHAR(50),
    FOREIGN KEY (aventureiro_id) REFERENCES Aventureiro(id),
    FOREIGN KEY (missao_id) REFERENCES Missao(id),
    PRIMARY KEY (aventureiro_id, missao_id)
);

-- A) Crie um trigger 'nivel_experiencia' que, antes de inserir um aventureiro, verifica sua experiência e define um nível a ele
-- Se for menor que 1000, o nível deve ser 1
-- Se for maior ou igual a 1000 e menor que 5000, o nível deve ser 2
-- Se for maior ou igual a 5000, o nível deve ser 3
-- Dica: Utilize ELSEIF
-- Resposta:

DELIMITER $$
CREATE TRIGGER nivel_experiencia BEFORE INSERT
ON Aventureiro
FOR EACH ROW
BEGIN
IF NEW.experiencia >= 5000 THEN
	SET NEW.nivel=3;
ELSEIF NEW.experiencia < 1000 THEN
	SET NEW.nivel = 1;
ELSE 
	SET NEW.nivel = 2;
END IF;
END$$
DELIMITER ;

-- B) Crie uma procedure 'registrar_aventureiro' que recebe um nome, uma classe e uma experiência, e insere um novo aventureiro
-- Resposta:

DELIMITER $$
DROP PROCEDURE IF EXISTS registrar_aventureiro $$
CREATE PROCEDURE  registrar_aventureiro(IN nome VARCHAR(100), IN classe VARCHAR(50), IN experiencia INT)
BEGIN
    INSERT INTO Aluno(id, nome, classe, experiencia) VALUES (DEFAULT, nome, classe, experiencia);
END $$
DELIMITER ;

-- C) Crie uma function 'descricao_missao' que recebe o título e a dificuldade de uma missão e retorna uma única string formatada 
-- 'Missão <titulo>: Dificuldade <dificuldade>'
-- Resposta:

DELIMITER $$
DROP FUNCTION IF EXISTS descricao_missao $$
CREATE FUNCTION descricao_missao(titulo VARCHAR(100), dificuldade VARCHAR(20)) RETURNS VARCHAR(100)
deterministic
begin
	DECLARE descricao VARCHAR(100);
	SET descricao = concat('Missão ', titulo, ': Dificuldade ', dificuldade); 
	RETURN descricao;
END $$
DELIMITER ;

-- D) Use a procedure 'registrar_aventureiro' para inserir 3 aventureiros com diferentes níveis de experiência
-- Resposta:
INSERT INTO Aventureiro(id, nome, classe, experiencia) VALUES (DEFAULT, 'Roberto Dinamite', 'Bombardeador', 5000);
INSERT INTO Aventureiro(id, nome, classe, experiencia) VALUES (DEFAULT, 'Claytinho', 'Arqueiro', 1000);
INSERT INTO Aventureiro(id, nome, classe, experiencia) VALUES (DEFAULT, 'Denise', 'Curandeira', 999);
SELECT * FROM Aventureiro;

-- E) Insira 3 missões com diferentes dificuldades e recompensas, depois, chame a function 'descricao_missao' para cada uma delas
-- Resposta:
INSERT INTO Missao(id, titulo, dificuldade, recompensa) VALUES (DEFAULT, 'Caçando Perereca', 'Difícil', '1500');
INSERT INTO Missao(id, titulo, dificuldade, recompensa) VALUES (DEFAULT, 'Caçando Lobos', 'Média', '500');
INSERT INTO Missao(id, titulo, dificuldade, recompensa) VALUES (DEFAULT, 'Caçando Slime', 'Fácil', '100');
SELECT descricao_missao('Caçando Perereca', 'Difícil');
SELECT descricao_missao('Caçando Lobo', 'Média');
SELECT descricao_missao('Caçando Slime', 'Fácil');

-- F) Escolha dois dos três aventureiros e duas das três missões, relacione-os os dois aventureiros as duas missões,
-- uma com status 'Falhou' e outra com status 'Concluída'
-- Resposta:
SELECT * FROM Aventureiro;
SELECT * FROM Missao;
INSERT INTO Participacao(aventureiro_id, missao_id, status) VALUES (1, 2, 'Concluída');
INSERT INTO Participacao(aventureiro_id, missao_id, status) VALUES (2, 2, 'Concluída');
INSERT INTO Participacao(aventureiro_id, missao_id, status) VALUES (1, 1, 'Falhou');
INSERT INTO Participacao(aventureiro_id, missao_id, status) VALUES (2, 1, 'Falhou');

-- G) Crie uma view 'resumo_aventureiro' que retorne o nome do aventureiro, o nome da missão, o status e a recompensa, depois, chame a view
-- Resposta:

CREATE VIEW resumo_aventureiro AS (SELECT a.nome, m.titulo, p.status, m.recompensa FROM Aventureiro AS a JOIN Participacao AS p
ON a.id = p.aventureiro_id JOIN Missao AS m ON p.missao_id = m.id);
SELECT * FROM resumo_aventureiro;

-- H) Busque o nome do aventureiro, a classe do aventureiro e o título da missão executada por ele
-- Resposta:

SELECT a.nome AS NomeAventureiro, a.classe AS ClasseAventureiro, m.titulo AS TituloMissao 
FROM Aventureiro AS a JOIN Participacao AS p ON a.id = p.aventureiro_id 
JOIN Missao AS m ON p.missao_id = m.id;

-- I) Busque todas as informações de todos os aventureiros e o nome de suas missões, mesmo que não tenham participado de nenhuma missão
-- Resposta:


-- J) Busque todas as informações de todas as missões e o nome de seus aventureiros, mesmo que nenhuma aventureiro tenha participado da missão
-- Resposta:
