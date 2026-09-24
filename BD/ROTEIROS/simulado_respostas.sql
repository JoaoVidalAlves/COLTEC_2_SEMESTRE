-- =====================================================================
-- Simulado da Prova 1 - Introdução a Banco de Dados - COLTEC/UFMG
-- Arquivo de respostas em SQL
-- =====================================================================


-- =====================================================================
-- PARTE 1 - Banco de dados Prova1 (tabelas Empregados e Financeiro já
-- existem no servidor; aqui criamos apenas Departamentos)
-- =====================================================================

-- ---------------------------------------------------------------------
-- Questão 1.1
-- Cria a tabela Departamentos e insere os dados da Tabela 2
-- ---------------------------------------------------------------------
CREATE TABLE Departamentos (
    id            INT PRIMARY KEY,
    departamento  VARCHAR(50) NOT NULL,
    gerente       INT
);

INSERT INTO Departamentos (id, departamento, gerente) VALUES
(101, 'RH',        5),
(102, 'TI',         6),
(103, 'Marketing',  2),
(104, 'Vendas',     4);


-- ---------------------------------------------------------------------
-- Questão 1.2
-- Nome do funcionário, nome do departamento e salário-base,
-- ordenado por departamento e, em empate, por nome do funcionário
-- ---------------------------------------------------------------------
SELECT
    e.nome          AS funcionario,
    d.departamento,
    f.salario_base
FROM Empregados e
JOIN Departamentos d ON d.id = e.dept_id
JOIN Financeiro f    ON f.funcionario = e.id
ORDER BY d.departamento, e.nome;


-- ---------------------------------------------------------------------
-- Questão 1.3
-- Nome de cada departamento e a soma dos salários-base pagos por ele
-- ---------------------------------------------------------------------
SELECT
    d.departamento,
    SUM(f.salario_base) AS total_salarios
FROM Departamentos d
JOIN Empregados e ON e.dept_id = d.id
JOIN Financeiro f ON f.funcionario = e.id
GROUP BY d.departamento;


-- ---------------------------------------------------------------------
-- Questão 1.4
-- Salário-base, salário em cada mês do 1º trimestre (bônus de
-- 20%, 5% e 25%) e total do trimestre, por funcionário
-- ---------------------------------------------------------------------
SELECT
    e.nome,
    f.salario_base,
    f.salario_base * 1.20                                   AS salario_janeiro,
    f.salario_base * 1.05                                   AS salario_fevereiro,
    f.salario_base * 1.25                                   AS salario_marco,
    (f.salario_base * 1.20)
  + (f.salario_base * 1.05)
  + (f.salario_base * 1.25)                                 AS total_trimestre
FROM Empregados e
JOIN Financeiro f ON f.funcionario = e.id;


-- ---------------------------------------------------------------------
-- Questão 1.5
-- Igual à 1.4, mas somente para os funcionários que são gerentes
-- ---------------------------------------------------------------------
SELECT
    e.nome,
    f.salario_base,
    f.salario_base * 1.20                                   AS salario_janeiro,
    f.salario_base * 1.05                                   AS salario_fevereiro,
    f.salario_base * 1.25                                   AS salario_marco,
    (f.salario_base * 1.20)
  + (f.salario_base * 1.05)
  + (f.salario_base * 1.25)                                 AS total_trimestre
FROM Empregados e
JOIN Financeiro f ON f.funcionario = e.id
WHERE e.id IN (SELECT gerente FROM Departamentos);


-- ---------------------------------------------------------------------
-- Questão 1.6
-- Maior salário total do 1º trimestre entre os gerentes (rótulo Maximo)
-- ---------------------------------------------------------------------
SELECT
    MAX( (f.salario_base * 1.20)
       + (f.salario_base * 1.05)
       + (f.salario_base * 1.25) ) AS Maximo
FROM Empregados e
JOIN Financeiro f ON f.funcionario = e.id
WHERE e.id IN (SELECT gerente FROM Departamentos);


-- ---------------------------------------------------------------------
-- Questão 1.7
-- Nome e salário total do trimestre do(s) gerente(s) com maior salário
-- ---------------------------------------------------------------------
SELECT
    e.nome,
    (f.salario_base * 1.20)
  + (f.salario_base * 1.05)
  + (f.salario_base * 1.25) AS total_trimestre
FROM Empregados e
JOIN Financeiro f ON f.funcionario = e.id
WHERE e.id IN (SELECT gerente FROM Departamentos)
  AND (f.salario_base * 1.20 + f.salario_base * 1.05 + f.salario_base * 1.25) = (
        SELECT MAX( (f2.salario_base * 1.20)
                   + (f2.salario_base * 1.05)
                   + (f2.salario_base * 1.25) )
        FROM Empregados e2
        JOIN Financeiro f2 ON f2.funcionario = e2.id
        WHERE e2.id IN (SELECT gerente FROM Departamentos)
      );


-- =====================================================================
-- PARTE 2 - Subconsultas: Produtos, Vendedores e Vendas
-- (tabelas criadas aqui para deixar o script autossuficiente; se já
--  existirem no servidor, basta remover os CREATE/INSERT abaixo)
-- =====================================================================

CREATE TABLE Produtos (
    id         INT PRIMARY KEY,
    nome       VARCHAR(50) NOT NULL,
    categoria  VARCHAR(50) NOT NULL,
    preco      DECIMAL(10,2) NOT NULL
);

INSERT INTO Produtos (id, nome, categoria, preco) VALUES
(1, 'Notebook Pro',      'Computadores',   4500.00),
(2, 'Monitor 24',        'Monitores',      1200.00),
(3, 'Teclado Mecânico',  'Periféricos',     350.00),
(4, 'Mouse Óptico',      'Periféricos',     120.00),
(5, 'Impressora Laser',  'Impressoras',    1800.00),
(6, 'SSD 1 TB',          'Armazenamento',   650.00),
(7, 'Webcam HD',         'Periféricos',     280.00),
(8, 'Roteador Wi-Fi',    'Redes',           420.00);

CREATE TABLE Vendedores (
    id     INT PRIMARY KEY,
    nome   VARCHAR(50) NOT NULL,
    setor  VARCHAR(50) NOT NULL
);

INSERT INTO Vendedores (id, nome, setor) VALUES
(1, 'Alice', 'Loja Física'),
(2, 'Bruno', 'Loja Física'),
(3, 'Carla', 'Comércio Eletrônico'),
(4, 'Diego', 'Comércio Eletrônico'),
(5, 'Elisa', 'Empresas'),
(6, 'Fábio', 'Empresas');

CREATE TABLE Vendas (
    id             INT PRIMARY KEY,
    produto_id     INT NOT NULL,
    vendedor_id    INT NOT NULL,
    quantidade     INT NOT NULL,
    valor_unitario DECIMAL(10,2) NOT NULL,
    data_venda     DATE NOT NULL,
    FOREIGN KEY (produto_id)  REFERENCES Produtos(id),
    FOREIGN KEY (vendedor_id) REFERENCES Vendedores(id)
);

INSERT INTO Vendas (id, produto_id, vendedor_id, quantidade, valor_unitario, data_venda) VALUES
(1,  1, 1, 1,  4500.00, '2026-08-01'),
(2,  2, 2, 3,  1150.00, '2026-08-02'),
(3,  3, 3, 5,   330.00, '2026-08-03'),
(4,  4, 3, 10,  110.00, '2026-08-05'),
(5,  5, 5, 2,  1750.00, '2026-08-06'),
(6,  6, 4, 4,   620.00, '2026-08-08'),
(7,  1, 5, 2,  4400.00, '2026-08-10'),
(8,  2, 1, 2,  1200.00, '2026-08-12'),
(9,  7, 2, 6,   260.00, '2026-08-13'),
(10, 3, 4, 8,   340.00, '2026-08-15'),
(11, 8, 6, 3,   400.00, '2026-08-17'),
(12, 5, 5, 1,  1800.00, '2026-08-19'),
(13, 4, 1, 7,   115.00, '2026-08-20'),
(14, 6, 6, 5,   630.00, '2026-08-22');


-- ---------------------------------------------------------------------
-- Questão 2.1 - Subconsulta escalar
-- Produtos com preço acima da média de todos os produtos
-- ---------------------------------------------------------------------
SELECT id, nome, categoria, preco
FROM Produtos
WHERE preco > (SELECT AVG(preco) FROM Produtos)
ORDER BY preco DESC;


-- ---------------------------------------------------------------------
-- Questão 2.2 - Subconsulta com IN
-- Vendedores que venderam ao menos um Notebook Pro
-- ---------------------------------------------------------------------
SELECT id, nome
FROM Vendedores
WHERE id IN (
    SELECT v.vendedor_id
    FROM Vendas v
    JOIN Produtos p ON p.id = v.produto_id
    WHERE p.nome = 'Notebook Pro'
)
ORDER BY nome;


-- ---------------------------------------------------------------------
-- Questão 2.3 - Subconsulta correlacionada
-- Produtos com preço acima da média da própria categoria
-- ---------------------------------------------------------------------
SELECT p.id, p.nome, p.categoria, p.preco
FROM Produtos p
WHERE p.preco > (
    SELECT AVG(p2.preco)
    FROM Produtos p2
    WHERE p2.categoria = p.categoria
);


-- ---------------------------------------------------------------------
-- Questão 2.4 - Subconsulta correlacionada com NOT EXISTS
-- Vendedores que não realizaram nenhuma venda
-- ---------------------------------------------------------------------
SELECT v.id, v.nome
FROM Vendedores v
WHERE NOT EXISTS (
    SELECT 1
    FROM Vendas s
    WHERE s.vendedor_id = v.id
);


-- =====================================================================
-- PARTE 3 - Banco de dados EmpresaC
-- (esquema clássico: Product(maker, model, type), PC(model, speed, ram,
--  hd, cd, price), Laptop(model, speed, ram, hd, screen, price),
--  Printer(model, color, type, price). As tabelas já existem no
--  servidor - nenhum CREATE/INSERT é necessário aqui.)
-- =====================================================================

-- ---------------------------------------------------------------------
-- Questão 3.1
-- PCs com CD de 12x e preço < 600, ou CD de 24x e preço < 600
-- ---------------------------------------------------------------------
SELECT model, speed, hd
FROM PC
WHERE (cd = '12x' AND price < 600)
   OR (cd = '24x' AND price < 600);


-- ---------------------------------------------------------------------
-- Questão 3.2
-- Modelos e preços de todos os produtos do fabricante B
-- ---------------------------------------------------------------------
SELECT model, price
FROM PC
WHERE model IN (SELECT model FROM Product WHERE maker = 'B')
UNION
SELECT model, price
FROM Laptop
WHERE model IN (SELECT model FROM Product WHERE maker = 'B')
UNION
SELECT model, price
FROM Printer
WHERE model IN (SELECT model FROM Product WHERE maker = 'B');


-- ---------------------------------------------------------------------
-- Questão 3.3
-- Fabricantes que produzem PCs, mas não produzem laptops
-- ---------------------------------------------------------------------
SELECT DISTINCT maker
FROM Product
WHERE type = 'pc'
  AND maker NOT IN (
        SELECT maker FROM Product WHERE type = 'laptop'
      );


-- ---------------------------------------------------------------------
-- Questão 3.4
-- Impressoras de maior preço (com empates)
-- ---------------------------------------------------------------------
SELECT model, price
FROM Printer
WHERE price = (SELECT MAX(price) FROM Printer);
