CREATE DATABASE agenda_db;
USE agenda_db;

CREATE TABLE contatos
(
    id INT   AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR  (40),
    telefone VARCHAR (20),
    email VARCHAR (30)
);