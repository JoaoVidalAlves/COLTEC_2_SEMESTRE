#Consulta Banco de Dados Floricultura
#1
SELECT nome, especie, preco FROM flores ORDER BY preco ASC;

#2
SELECT nome, preco, estoque FROM flores WHERE (preco > 25 AND estoque < 25);

#3
SELECT nome, preco FROM flores WHERE nome LIKE "ROSA%" ORDER BY nome ASC;

#4
SELECT SUM(estoque) AS Flores_Cadastradas, 
MIN(preco) AS Menor_preco, 
MAX(preco) AS Maior_preco, 
AVG(preco) AS Preco_medio 
FROM flores;

#5
SELECT especie, 
SUM(estoque) AS Total_de_Flores
FROM flores
GROUP BY especie
ORDER BY Total_de_Flores DESC;

#6
SELECT f.nome, f.preco, c.nome_cor
FROM flores f
JOIN cores c ON f.id_cor = c.id_cor
GROUP BY f.nome, f.preco, c.id_cor;

#7
SELECT f.nome, p.descricao, r.nome_regiao
FROM flores f
JOIN formato_petalas p ON f.id_formato = p.id_formato
JOIN regioes r ON f.id_regiao = r.id_regiao
WHERE p.descricao = 'Oval'
GROUP BY f.nome, p.descricao, r.nome_regiao;

#8
SELECT r.nome_regiao, COUNT(f.id_regiao) AS Quantidade_de_Flores
FROM regioes r
LEFT JOIN flores f ON r.id_regiao = f.id_regiao
GROUP BY r.id_regiao, r.nome_regiao;

#9
SELECT especie, AVG(preco) AS Preco_medio
FROM flores
WHERE estoque > 10
GROUP BY especie
HAVING COUNT(*) > 1
ORDER BY Preco_medio ASC;

#10
SELECT nome, especie, preco
FROM flores
WHERE preco > (SELECT AVG(preco) FROM flores)
ORDER BY preco ASC;

#Banco de Dados Empresa1
#11
SELECT p.id,  e.quantidade, f.preco_base
FROM Produtos p
JOIN Estoque e ON p.id = e.id_produto
JOIN Financeiro f ON p.id = f.produto;

#12 
SELECT p.nome,  e.quantidade, f.preco_base
FROM Produtos p
JOIN Estoque e ON p.id = e.id_produto
JOIN Financeiro f ON p.id = f.produto;

#13
SELECT p.categoria,
p.nome,
e.quantidade,
f.preco_base,
(e.quantidade * f.preco_base) AS preco_total_em_estoque
FROM Produtos p
JOIN Estoque e ON p.id = e.id_produto
JOIN Financeiro f ON p.id = f.produto;

#14
SELECT p.categoria,
SUM(e.quantidade) AS quantidade_total,
SUM(e.quantidade * f.preco_base) AS valor_total_preco_base
FROM Produtos p
JOIN Estoque e ON p.id = e.id_produto
JOIN Financeiro f ON p.id = f.produto
GROUP BY p.categoria;

#15
SELECT p.categoria,
p.nome,
e.quantidade,
f.preco_base * 0.95 AS preco_janeiro,
f.preco_base * 1.10 AS preco_fevereiro
FROM Produtos p
JOIN Estoque e ON p.id = e.id_produto
JOIN Financeiro f ON p.id = f.produto;

#16
SELECT p.categoria,
SUM(e.quantidade) AS quantidade_total,
SUM(e.quantidade * f.preco_base) AS preco_base_total,
SUM(e.quantidade * f.preco_base * 0.95) AS preco_total_janeiro,
SUM(e.quantidade * f.preco_base * 1.10) AS preco_total_fevereiro
FROM Produtos p
JOIN Estoque e ON p.id = e.id_produto
JOIN Financeiro f ON p.id = f.produto
GROUP BY p.categoria
HAVING SUM(e.quantidade * f.preco_base * 0.95) > 100;