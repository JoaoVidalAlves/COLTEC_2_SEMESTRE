# 1. Seleção e ordenação.
/*Lista o código, o modelo, a velocidade, a memória RAM e o preço dos computadores da tabela PC cujo preço seja superior a 800 e ordena do mais caro para o mais barato. Em caso de empate no preço, ordena pelo código.*/

SELECT 	code as id,
		model,
		speed,
		ram,
		price 
FROM PC
WHERE price >= 800
ORDER BY price DESC, code DESC;

# 2. Valores mínimo, máximo, médio e total.
/*Em uma única consulta, mostre a quantidade de laptops cadastrados, o menor preço, o maior preço, o preço médio e a soma dos preços dos laptops. Apresente o preço médio com duas casas decimais.*/

SELECT 	COUNT(code),
		MAX(price) AS Preco_Max,
		MIN(price) AS Preco_Min,
		ROUND(AVG(price), 2) AS Preco_Med,
		ROUND(SUM(price),2) AS Preco_Som
from Laptop;

#3. Agrupamento por modelo. 
/*Para cada modelo da tabela PC, apresente a quantidade de computadores cadastrados e seu preço médio. Mostre apenas os modelos que possuem pelo menos dois computadores cadastrados. Ordene pela quantidade, da maior para a menor, e depois pelo modelo.*/

SELECT  model,
		count(model) AS Quantidade,
		AVG(price) AS preco_med
FROM PC
GROUP BY model
HAVING Quantidade >= 2
ORDER BY Quantidade DESC;

#4. Modelos por fabricante. 
/*Na tabela Product, conte quantos modelos distintos estão associados a cada fabricante. Exiba o fabricante e a quantidade de modelos, ordenando da maior quantidade para a menor.*/

SELECT 	maker,
		COUNT(DISTINCT model) AS Qtde
FROM Product
GROUP BY maker
ORDER BY Qtde DESC;

#5. Junção entre fabricante e PC. 
/*Liste o fabricante, o modelo, o código, a memória RAM e o preço de cada computador cadastrado em PC. Ordene pelo fabricante e, dentro de cada fabricante, pelo preço decrescente.*/

SELECT 	pd.maker,
		pc.model,
		pc.code,
		pc.ram,
		pc.price
FROM PC pc
JOIN Product pd
ORDER BY pd.maker ASC, pc.price DESC;

#6. Fabricantes de laptops. 
/*Para cada fabricante que possua laptops cadastrados, apresente a quantidade de laptops, o menor preço, o maior preço e o preço médio. Use Product e Laptop. Ordene pelo preço médio decrescente.*/

SELECT 	pd.maker,
		count(lp.model) AS Qtde,
		min(lp.price) AS Menor,
		max(lp.price) AS Maior,
		avg(lp.price) AS Medio 
FROM Laptop lp
JOIN Product pd ON lp.model = pd.model
GROUP BY pd.maker
ORDER BY Medio DESC;

#7. Impressoras coloridas. 
/*Liste fabricante, modelo, tipo e preço das impressoras coloridas. Ordene pelo preço crescente e, em caso de empate, pelo modelo.*/

SELECT pd.maker,
	   pt.model AS Modelo,
	   SUM(pt.model) AS Qtde,
       pt.type,
       pt.price AS Preco
FROM Printer pt
JOIN Product pd ON pt.model = pd.model
GROUP BY pd.maker,
		pt.model,
		pt.type,
		pt.price
ORDER BY Preco DESC, Modelo DESC;

#8. Preço acima da média. 
/*Liste código, modelo e preço dos computadores cujo preço seja superior ao preço médio de todos os computadores da tabela PC. Ordene pelo preço decrescente.*/

SELECT code,
		model,
        price
FROM PC
WHERE price > (SELECT AVG(price) FROM PC)
ORDER BY price DESC;

#9. Fabricantes de PCs com preço mínimo. 
/*Para cada fabricante que possua computadores cadastrados em PC, apresente a quantidade de computadores e o menor preço. Mostre apenas os fabricantes que possuam pelo menos dois computadores cadastrados. Ordene pela quantidade decrescente.*/

SELECT 	pd.maker,
		count(pc.model) AS Qtde,
		min(pc.price) AS Menor,
		max(pc.price) AS Maior,
		avg(pc.price) AS Medio 
FROM PC pc
JOIN Product pd ON pc.model = pd.model
GROUP BY pd.maker
HAVING Qtde >=2
ORDER BY Medio DESC;

#10. Fabricantes presentes em duas categorias. 
/*Encontre os fabricantes que possuam pelo menos um computador cadastrado em PC e pelo menos um laptop cadastrado em Laptop. Para cada fabricante, apresente a quantidade de computadores e a quantidade de laptops. Ordene pelo fabricante.*/

SELECT 
    pd.maker,
    COUNT(DISTINCT pc.model) AS QtdePc,
    COUNT(DISTINCT lp.model) AS QtdeLp
FROM Product pd
LEFT JOIN PC pc ON pd.model = pc.model
LEFT JOIN Laptop lp ON pd.model = lp.model
GROUP BY pd.maker
HAVING COUNT(DISTINCT pc.model) >= 1 
   AND COUNT(DISTINCT lp.model) >= 1
ORDER BY pd.maker ASC;