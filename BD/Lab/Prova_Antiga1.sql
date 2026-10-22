DROP DATABASE IF EXISTS AV1;
CREATE DATABASE AV1;
USE AV1;

#COMANDO PARA DESATIVAR O SAFE MODE
SET SQL_SAFE_UPDATES = 0;

CREATE TABLE IF NOT EXISTS Ninja (
    id INT AUTO_INCREMENT PRIMARY KEY NOT NULL,
    nome VARCHAR(50) NOT NULL,
    idade INT NOT NULL,
    titulo VARCHAR(50) NOT NULL,
    dinheiro INT NOT NULL,
    tipoChakra VARCHAR(50) NOT NULL,
    qtdChakra INT NOT NULL
);
select * from Ninja;
# Responda aqui a letra A
insert into Ninja() values (DEFAULT, "Naruto", 13, "Genin", 0,
"Vento", 600);
insert into Ninja() values (DEFAULT, "Sasuke", 14, "Chunin", 500,
"Raio", 400);
insert into Ninja() values (DEFAULT, "Sakura", 12, "Genin", 150,
"Terra", 500);
insert into Ninja() values (DEFAULT, "Gaara", 15, "Chunin", 400,
"Areia", 550);
insert into Ninja() values (DEFAULT, "Kakashi", 28, "Jonin", 1000,
"Raio", 200);
insert into Ninja() values (DEFAULT, "Minato", 35, "Hokage", 5000,
"Vento", 300);
# Responda aqui a letra B
update Ninja set idade = 14 where id = 1; 
# Responda aqui a letra C
select * from Ninja where titulo = "Genin";
# Responda aqui a letra D
delete from Ninja where qtdChakra = 550;
# Responda aqui a letra E
select titulo from Ninja where tipoChakra = "Vento";
# Responda aqui a letra F
select max(idade) from Ninja;
# Responda aqui a letra G
update Ninja set titulo = "Chunin" where nome = "Naruto"
or nome = "Sakura";
# Responda aqui a letra H
SELECT * FROM Ninja WHERE nome LIKE 'Sa____';
# Responda aqui a letra I
SELECT COUNT(*) FROM Ninja WHERE dinheiro <= 1000;