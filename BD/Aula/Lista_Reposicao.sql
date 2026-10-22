## Felipe Silva Loschi - 601 - GES
## 1)

DROP DATABASE IF exists Heroi_Mundo;
CREATE DATABASE IF NOT EXISTS Heroi_Mundo;
USE Heroi_Mundo;

CREATE TABLE IF NOT EXISTS Heroi (
    idHeroi INT PRIMARY KEY AUTO_INCREMENT,
    nome VARCHAR(45) NOT NULL,
    endereco VARCHAR(45),
    nascimento DATE,
    habilidade VARCHAR(45),
    sexo CHAR(1),
    email VARCHAR(45)
);

CREATE TABLE IF NOT EXISTS Vilao (
    idVilao INT PRIMARY KEY AUTO_INCREMENT,
    nome VARCHAR(45) NOT NULL,
    num_crimes INT
);

CREATE TABLE IF NOT EXISTS Missao (
    idMissao INT PRIMARY KEY AUTO_INCREMENT,
    dataMissao DATE NOT NULL,
    nome VARCHAR(45) NOT NULL,
    localMissao VARCHAR(45),
    duracao INT,
    Vilao_idVilao INT,
    FOREIGN KEY (Vilao_idVilao) REFERENCES Vilao(idVilao) ON DELETE SET NULL
);

CREATE TABLE Heroi_has_Missao (
    Heroi_idHeroi INT,
    Missao_idMissao INT,
    PRIMARY KEY (Heroi_idHeroi, Missao_idMissao),
    CONSTRAINT fk_Heroi_has_Missao_Heroi FOREIGN KEY (Heroi_idHeroi) REFERENCES Heroi(idHeroi) ON DELETE CASCADE,
    CONSTRAINT fk_Heroi_has_Missao_Missao FOREIGN KEY (Missao_idMissao) REFERENCES Missao(idMissao) ON DELETE CASCADE
);

SELECT * FROM Heroi;
SELECT * FROM Heroi_has_Missao;
SELECT * FROM Missao;
SELECT * FROM Vilao;

## 2)
## Heroi:
INSERT INTO Heroi (nome, endereco, nascimento, habilidade, sexo, email) VALUES ('Superman', 'Metrópolis', '1978-06-18', 'Super força', 'M', 'superman@dc.com');
INSERT INTO Heroi (nome, endereco, nascimento, habilidade, sexo, email) VALUES ('Batman', 'Gotham', '1980-02-19', 'Artes marciais', 'M', 'batman@dc.com');
INSERT INTO Heroi (nome, endereco, nascimento, habilidade, sexo, email) VALUES ('Mulher-Maravilha', 'Themyscira', '1985-03-22', 'Força sobre-humana', 'F', 'diana@dc.com');
INSERT INTO Heroi (nome, endereco, nascimento, habilidade, sexo, email) VALUES ('Flash', 'Central City', '1992-07-30', 'Velocidade extrema', 'M', 'flash@dc.com');
INSERT INTO Heroi (nome, endereco, nascimento, habilidade, sexo, email) VALUES ('Lanterna Verde', 'Coast City', '1986-05-11', 'Anel energético', 'M', 'lanterna@dc.com');

## Vilão:
INSERT INTO Vilao (nome, num_crimes) VALUES ('Coringa', 500);
INSERT INTO Vilao (nome, num_crimes) VALUES ('Lex Luthor', 300);
INSERT INTO Vilao (nome, num_crimes) VALUES ('Ares', 200);
INSERT INTO Vilao (nome, num_crimes) VALUES ('Capitão Frio', 150);
INSERT INTO Vilao (nome, num_crimes) VALUES ('Sinestro', 250);

## Missao:
INSERT INTO Missao (dataMissao, nome, localMissao, duracao, Vilao_idVilao) VALUES ('2025-04-01', 'Derrotar Coringa', 'Gotham', 3, 1);
INSERT INTO Missao (dataMissao, nome, localMissao, duracao, Vilao_idVilao) VALUES ('2025-04-02', 'Impedir Lex Luthor', 'Metrópolis', 4, 2);
INSERT INTO Missao (dataMissao, nome, localMissao, duracao, Vilao_idVilao) VALUES ('2025-04-03', 'Combate contra Ares', 'Themyscira', 5, 3);
INSERT INTO Missao (dataMissao, nome, localMissao, duracao, Vilao_idVilao) VALUES ('2025-04-04', 'Parar Capitão Frio', 'Central City', 2, 4);
INSERT INTO Missao (dataMissao, nome, localMissao, duracao, Vilao_idVilao) VALUES ('2025-04-05', 'Derrotar Sinestro', 'Coast City', 3, 5);

## 3) Missao para heroi
INSERT INTO Heroi_has_Missao (Heroi_idHeroi, Missao_idMissao) VALUES (1, 1), (1, 2), (1, 5); -- Superman em 3 missões
INSERT INTO Heroi_has_Missao (Heroi_idHeroi, Missao_idMissao) VALUES (2, 1), (2, 2), (2, 3);  -- Batman em 3 missões
INSERT INTO Heroi_has_Missao (Heroi_idHeroi, Missao_idMissao) VALUES (3, 3), (3, 4), (3, 5);  -- Mulher-Maravilha em 3 missões
INSERT INTO Heroi_has_Missao (Heroi_idHeroi, Missao_idMissao) VALUES (4, 1), (4, 4), (4, 5);  -- Flash em 3 missões
INSERT INTO Heroi_has_Missao (Heroi_idHeroi, Missao_idMissao) VALUES (5, 2), (5, 3), (5, 4);  -- Lanterna Verde em 3 missões

## 4) 
SELECT H.nome, M.nome, V.nome FROM Heroi AS H JOIN Heroi_has_Missao AS HM ON H.idHeroi = HM.Heroi_idHeroi JOIN Missao AS M ON HM.Missao_idMissao = M.idMissao JOIN Vilao AS V ON M.Vilao_idVilao = V.idVilao ORDER BY H.nome;

## 5)
SELECT H.nome, sum(M.duracao) AS duracaoTotal, count(HM.Missao_idMissao)AS quantMissao FROM Heroi AS H JOIN Heroi_has_Missao AS HM ON H.idHeroi = HM.Heroi_idHeroi JOIN Missao AS M ON HM.Missao_idMissao = M.idMissao GROUP BY H.nome ORDER BY H.nome;

## 6)
SELECT H.nome, M.nome, V.num_crimes FROM Heroi AS H JOIN Heroi_has_Missao AS HM ON H.idHeroi = HM.Heroi_idHeroi JOIN Missao AS M ON HM.Missao_idMissao = M.idMissao JOIN Vilao AS V ON M.Vilao_idVilao = V.idVilao ORDER BY M.nome;