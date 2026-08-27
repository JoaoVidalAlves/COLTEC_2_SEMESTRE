-- =====================================================================
-- Banco de dados: livraria01
-- Usado nos Roteiros de Estudo 1, 2, 3 e 4 (SELECT, WHERE, funcoes de
-- agregacao, GROUP BY / HAVING).
-- Fonte: adaptado de R.L. DE CARVALHO COSTA, "SQL Guia Pratico", Brasport.
-- =====================================================================

CREATE DATABASE IF NOT EXISTS livraria01;
USE livraria01;

DROP TABLE IF EXISTS livro;
DROP TABLE IF EXISTS assunto;
DROP TABLE IF EXISTS editora;

CREATE TABLE editora (
  codigo INT NOT NULL,
  nome   VARCHAR(40) NOT NULL,
  PRIMARY KEY (codigo)
);

CREATE TABLE assunto (
  sigla     CHAR(1) NOT NULL,
  descricao VARCHAR(40) NOT NULL,
  PRIMARY KEY (sigla)
);

CREATE TABLE livro (
  codigo     INT NOT NULL,
  titulo     VARCHAR(60) NOT NULL,
  preco      DECIMAL(8,2) NOT NULL,
  lancamento DATE DEFAULT NULL,
  assunto    CHAR(1) DEFAULT NULL,
  editora    INT DEFAULT NULL,
  PRIMARY KEY (codigo),
  CONSTRAINT fk_livro_assunto FOREIGN KEY (assunto) REFERENCES assunto (sigla),
  CONSTRAINT fk_livro_editora FOREIGN KEY (editora) REFERENCES editora (codigo)
);

INSERT INTO editora (codigo, nome) VALUES
(1, 'Mirandela Editora'),
(2, 'Editora Via-Norte'),
(3, 'Editora Ilhas Tijucas'),
(4, 'Maria Jose Editora');

INSERT INTO assunto (sigla, descricao) VALUES
('B', 'Banco de Dados'),
('P', 'Programacao'),
('R', 'Redes'),
('S', 'Sistemas Operacionais');

INSERT INTO livro (codigo, titulo, preco, lancamento, assunto, editora) VALUES
(1, 'Banco de Dados para Web',        31.20, '1999-01-10', 'B', 1),
(2, 'Programando em Linguagem C',     30.00, '1997-10-01', 'P', 1),
(3, 'Programando em Linguagem C++',  111.50, '1998-11-01', 'P', 3),
(4, 'Banco de Dados na Bioinformatica', 48.00, NULL,        'B', 2),
(5, 'Redes de Computadores',          42.00, '1996-09-01', 'R', 2);
