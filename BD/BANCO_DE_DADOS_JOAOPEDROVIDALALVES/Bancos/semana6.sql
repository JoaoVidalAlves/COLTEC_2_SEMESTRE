CREATE DATABASE IF NOT EXISTS lojaVirtual
CHARACTER SET utf8mb4
COLLATE utf8mb4_0900_ai_ci;
USE lojaVirtual;
SELECT DATABASE();

CREATE TABLE clientes (
cliente_id INT UNSIGNED AUTO_INCREMENT,
nome VARCHAR(100) NOT NULL,
cidade VARCHAR(80) NOT NULL,
uf CHAR(2) NOT NULL,
email VARCHAR(120) NOT NULL,
data_cadastro DATE NOT NULL,
CONSTRAINT pk_clientes PRIMARY KEY (cliente_id),
CONSTRAINT uq_clientes_email UNIQUE (email)
) ENGINE = InnoDB;

 CREATE TABLE produtos (
 produto_id INT UNSIGNED AUTO_INCREMENT,
 nome VARCHAR(100) NOT NULL,
 categoria VARCHAR(50) NOT NULL,
 preco DECIMAL(10,2) NOT NULL,
 estoque INT UNSIGNED NOT NULL DEFAULT 0,
 ativo BOOLEAN NOT NULL DEFAULT TRUE,
 CONSTRAINT pk_produtos PRIMARY KEY (produto_id),
 CONSTRAINT ck_produtos_preco CHECK (preco >= 0)
) ENGINE = InnoDB;

 CREATE TABLE vendedores (
 vendedor_id INT UNSIGNED AUTO_INCREMENT,
 nome VARCHAR(100) NOT NULL,
 setor VARCHAR(50) NOT NULL,
 comissao DECIMAL(5,2) NOT NULL DEFAULT 0,
 data_admissao DATE NOT NULL,
 CONSTRAINT pk_vendedores PRIMARY KEY (vendedor_id),
 CONSTRAINT ck_vendedores_comissao
 CHECK (comissao BETWEEN 0 AND 100)
 ) ENGINE = InnoDB;

CREATE TABLE vendas (
    venda_id INT UNSIGNED AUTO_INCREMENT,
    cliente_id INT UNSIGNED NOT NULL,
    produto_id INT UNSIGNED NOT NULL,
    vendedor_id INT UNSIGNED NOT NULL,
    data_venda DATE NOT NULL,
    quantidade INT UNSIGNED NOT NULL,
    preco_unitario DECIMAL(10,2) NOT NULL,
    status_venda VARCHAR(20) NOT NULL DEFAULT 'PENDENTE',
    CONSTRAINT pk_vendas PRIMARY KEY (venda_id),
    CONSTRAINT ck_vendas_quantidade CHECK (quantidade > 0),
    CONSTRAINT fk_vendas_clientes FOREIGN KEY (cliente_id) REFERENCES clientes (cliente_id) ON UPDATE CASCADE ON DELETE RESTRICT,
    CONSTRAINT fk_vendas_produtos FOREIGN KEY (produto_id) REFERENCES produtos (produto_id) ON UPDATE CASCADE ON DELETE RESTRICT,
    CONSTRAINT fk_vendas_vendedores FOREIGN KEY (vendedor_id) REFERENCES vendedores (vendedor_id) ON UPDATE CASCADE ON DELETE RESTRICT
) ENGINE = InnoDB;
 
INSERT INTO clientes
(nome, cidade, uf, email, data_cadastro)
VALUES
('Ana Souza', 'Belo Horizonte', 'MG','ana@email.com', '2026-02-10'),
('Bruno Lima', 'Contagem', 'MG','bruno@email.com', '2026-03-15'),
('Carla Mendes', 'São Paulo', 'SP','carla@email.com', '2026-04-20'),
('Diego Alves', 'Curitiba', 'PR','diego@email.com', '2026-05-05'),
('Elisa Rocha', 'Belo Horizonte', 'MG','elisa@email.com', '2026-06-12');

INSERT INTO produtos
(nome, categoria, preco, estoque, ativo)
VALUES
('Notebook Pro 15', 'Informática', 4500.00, 12, TRUE),
('Mouse sem fio', 'Informática', 120.00, 50, TRUE),
('Cadeira Office', 'Móveis', 980.00, 8, TRUE),
('Monitor 27', 'Informática', 1600.00, 15, TRUE),
('Luminária LED', 'Casa', 180.00, 30, TRUE);

INSERT INTO vendedores
(nome, setor, comissao, data_admissao)
VALUES
('Felipe Costa', 'Corporativo', 5.00, '2022-03-10'),
('Gabriela Reis', 'Varejo', 4.50, '2023-07-18'),
('Henrique Melo', 'Varejo', 4.00, '2024-01-22'),
('Isabela Nunes', 'Corporativo', 5.50, '2021-09-01'),
('João Martins', 'On-line', 3.50, '2025-02-14');

INSERT INTO vendas
(cliente_id, produto_id, vendedor_id, data_venda,quantidade, preco_unitario, status_venda)
VALUES
(1, 1, 1, '2026-08-01', 1, 4400.00, 'CONCLUIDA'),
(2, 2, 2, '2026-08-03', 3, 115.00, 'CONCLUIDA'),
(1, 4, 5, '2026-08-07', 2, 1550.00, 'CONCLUIDA'),
(3, 3, 4, '2026-08-10', 1, 950.00, 'PENDENTE'),
(5, 5, 2, '2026-08-15', 4, 175.00, 'CANCELADA');

-- 1. Liste todas as colunas e linhas da tabela clientes.
SELECT * FROM clientes;

-- 2. Mostre apenas nome, categoria e preço dos produtos.
SELECT nome, categoria, preco
FROM produtos;

-- 3. Liste os clientes de Minas Gerais, em ordem alfabética.
SELECT *
FROM clientes
WHERE uf = 'MG'
ORDER BY nome ASC;

-- 4. Exiba os produtos cujo preço esteja entre R$ 150,00 e R$ 1.700,00.
SELECT *
FROM produtos
WHERE preco BETWEEN 150.00 AND 1700.00;

-- 5. Mostre os produtos da categoria Informática com estoque maior que 10.
SELECT *
FROM produtos
WHERE categoria = 'Informática'
  AND estoque > 10;

-- 6. Liste as três mercadorias mais caras.
SELECT *
FROM produtos
ORDER BY preco DESC
LIMIT 3;

-- 7. Mostre as cidades distintas cadastradas em clientes.
SELECT DISTINCT cidade
FROM clientes;

-- 8. Calcule o menor preço, o maior preço e o preço médio dos produtos.
SELECT MIN(preco) AS menor_preco,
       MAX(preco) AS maior_preco,
       AVG(preco) AS preco_medio
FROM produtos;

-- 9. Calcule a quantidade total de unidades mantidas em estoque.
SELECT SUM(estoque) AS total_estoque
FROM produtos;

-- 10. Conte quantos clientes existem em cada UF e ordene do maior para o menor total.
SELECT uf,
       COUNT(*) AS total_clientes
FROM clientes
GROUP BY uf
ORDER BY total_clientes DESC;

-- 11. Calcule a quantidade de produtos e o preço médio de cada categoria.
SELECT categoria,
       COUNT(*) AS quantidade_produtos,
       AVG(preco) AS preco_medio
FROM produtos
GROUP BY categoria;

-- 12. Mostre somente as categorias cujo preço médio seja superior a R$ 500,00.
SELECT categoria,
       AVG(preco) AS preco_medio
FROM produtos
GROUP BY categoria
HAVING AVG(preco) > 500.00;

-- 13. Calcule, para cada venda, o valor total (quantidade * preco_unitario).
SELECT venda_id,
       quantidade,
       preco_unitario,
       quantidade * preco_unitario AS valor_total
FROM vendas;

-- 14. Calcule a soma das vendas concluídas, ignorando as pendentes e canceladas.
SELECT SUM(quantidade * preco_unitario) AS total_vendas_concluidas
FROM vendas
WHERE status_venda = 'CONCLUIDA';

-- 15. Conte as vendas por status e ordene do status mais frequente para o menos frequente.
SELECT status_venda,
       COUNT(*) AS total_vendas
FROM vendas
GROUP BY status_venda
ORDER BY total_vendas DESC;

-- JUNÇÕES 1 A 8

-- 1. Liste cada venda com data, nome do cliente e nome do produto.
SELECT
    v.data_venda,
    c.nome AS cliente,
    p.nome AS produto
FROM vendas v
INNER JOIN clientes c
    ON v.cliente_id = c.cliente_id
INNER JOIN produtos p
    ON v.produto_id = p.produto_id;

-- 2. Acrescente à consulta anterior o vendedor, a quantidade e o valor total.
SELECT
    v.data_venda,
    c.nome AS cliente,
    p.nome AS produto,
    vd.nome AS vendedor,
    v.quantidade,
    (v.quantidade * v.preco_unitario) AS valor_total
FROM vendas v
INNER JOIN clientes c
    ON v.cliente_id = c.cliente_id
INNER JOIN produtos p
    ON v.produto_id = p.produto_id
INNER JOIN vendedores vd
    ON v.vendedor_id = vd.vendedor_id;

-- 3. Mostre somente as vendas concluídas, com cliente, produto e valor total, em ordem decrescente de valor.
SELECT
    c.nome AS cliente,
    p.nome AS produto,
    (v.quantidade * v.preco_unitario) AS valor_total
FROM vendas v
INNER JOIN clientes c
    ON v.cliente_id = c.cliente_id
INNER JOIN produtos p
    ON v.produto_id = p.produto_id
WHERE v.status_venda = 'CONCLUIDA'
ORDER BY valor_total DESC;

-- 4. Calcule o total vendido por vendedor. Considere somente vendas concluídas.
SELECT
    vd.nome AS vendedor,
    SUM(v.quantidade * v.preco_unitario) AS total_vendido
FROM vendas v
INNER JOIN vendedores vd
    ON v.vendedor_id = vd.vendedor_id
WHERE v.status_venda = 'CONCLUIDA'
GROUP BY vd.vendedor_id, vd.nome
ORDER BY total_vendido DESC;

-- 5. Calcule o total comprado por cliente, incluindo com LEFT JOIN os clientes que não fizeram nenhuma compra. Use COALESCE para mostrar zero em vez de NULL.
SELECT
    c.nome AS cliente,
    COALESCE(
        SUM(
            CASE
                WHEN v.status_venda = 'CONCLUIDA'
                THEN v.quantidade * v.preco_unitario
                ELSE 0
            END
        ),
        0
    ) AS total_comprado
FROM clientes c
LEFT JOIN vendas v
    ON c.cliente_id = v.cliente_id
GROUP BY c.cliente_id, c.nome
ORDER BY total_comprado DESC;

-- 6. Liste todos os produtos e a quantidade total de unidades vendidas. Inclua produtos sem vendas.
SELECT
    p.nome AS produto,
    COALESCE(SUM(v.quantidade), 0) AS total_unidades_vendidas
FROM produtos p
LEFT JOIN vendas v
    ON p.produto_id = v.produto_id
GROUP BY p.produto_id, p.nome
ORDER BY total_unidades_vendidas DESC;

-- 7. Mostre o total faturado por categoria, considerando vendas concluídas.
SELECT
    p.categoria,
    SUM(v.quantidade * v.preco_unitario) AS total_faturado
FROM vendas v
INNER JOIN produtos p
    ON v.produto_id = p.produto_id
WHERE v.status_venda = 'CONCLUIDA'
GROUP BY p.categoria
ORDER BY total_faturado DESC;

-- 8. Liste os vendedores sem nenhuma venda, usando LEFT JOIN e IS NULL.
SELECT
    vd.vendedor_id,
    vd.nome
FROM vendedores vd
LEFT JOIN vendas v
    ON vd.vendedor_id = v.vendedor_id
WHERE v.venda_id IS NULL;