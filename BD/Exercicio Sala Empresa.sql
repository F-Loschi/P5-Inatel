DROP DATABASE IF EXISTS Empresa;
CREATE DATABASE IF NOT EXISTS Empresa;
USE Empresa;

CREATE TABLE Empresa.Departamento(
	DNome VARCHAR(45),
    DNumero TINYINT PRIMARY KEY NOT NULL AUTO_INCREMENT,
    DataInicio DATE,
    SSN_Empregado SMALLINT NOT NULL
);

CREATE TABLE Empresa.Empregado(
	SSN TINYINT PRIMARY KEY,
    PNome VARCHAR(45) NOT NULL,
    Minicial CHAR(1) NOT NULL,
    DataNasc DATE NOT NULL,
    Endereco VARCHAR(45) NOT NULL,
    Salario DECIMAL(10,2) NOT NULL,
    Sexo BIT NOT NULL,
    SSN_supervisor SMALLINT NOT NULL,
    DNumero_Departamento TINYINT NOT NULL
);

CREATE TABLE Empresa.Projeto(
	PNumero SMALLINT AUTO_INCREMENT PRIMARY KEY NOT NULL,
    PNome VARCHAR(45),
    PLocalizacao VARCHAR(45) NOT NULL,
    DNumero_Departamento SMALLINT NOT NULL
);

CREATE TABLE Empresa.Dependente(
	SSN_Empregado SMALLINT PRIMARY KEY NOT NULL,
    NomeDependente VARCHAR(45),
    Sexo BIT NOT NULL,
    DataNasc DATE NOT NULL,
    Parentesco VARCHAR(45) NOT NULL
);

CREATE TABLE Empresa.Depto_Localizacoes(
	LNumero TINYINT AUTO_INCREMENT NOT NULL PRIMARY KEY,
    DLocalizacao VARCHAR(45) NOT NULL,
    DNumero_Departamento SMALLINT NOT NULL
);