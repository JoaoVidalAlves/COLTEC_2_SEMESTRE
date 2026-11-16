-- =====================================================================
-- Arquivo 04: CONSULTAS (SELECT) E OPERAÇÕES CRUD  (VERSÃO SIMPLES)
-- Rode DEPOIS do 01 e do 02.
-- Selecione UM bloco por vez e clique no raio com o cursor
-- (Execute the selected portion), pois alguns comandos mudam dados.
--
-- CRUD = Create (INSERT) | Read (SELECT) | Update (UPDATE) | Delete (DELETE)
--
-- Guia rápido:
--   SELECT ... FROM ........ lê dados
--   WHERE .................. filtra linhas
--   JOIN ... ON ............ junta duas tabelas pela chave
--   GROUP BY ............... agrupa linhas (para contar/somar por grupo)
--   COUNT / SUM / AVG ...... contar / somar / média
--   ORDER BY ............... ordena
--   CURDATE() .............. data de hoje
-- =====================================================================

USE farmacia_db;

-- =====================================================================
-- PARTE A - 15 CONSULTAS
-- =====================================================================

-- ---------------------------------------------------------------------
-- C01. ATENDIMENTO: achar o cliente pelo CPF ou pelo celular
--      (o atendente já vê o endereço de entrega)
-- ---------------------------------------------------------------------
SELECT nome, cpf, telefone, logradouro, numero, bairro, cidade, cep
  FROM cliente
 WHERE cpf = '10000000003' OR telefone = '31991110003';

-- ---------------------------------------------------------------------
-- C02. ATENDIMENTO: produtos que um cliente mais compra (cliente 1)
-- ---------------------------------------------------------------------
SELECT p.nome AS produto,
       COUNT(*) AS pedidos_com_o_produto,
       SUM(ip.quantidade) AS total_de_unidades
  FROM pedido pe
  JOIN item_pedido ip ON ip.id_pedido = pe.id_pedido
  JOIN produto p      ON p.id_produto = ip.id_produto
 WHERE pe.id_cliente = 1
   AND pe.status <> 'CANCELADO'
 GROUP BY p.id_produto, p.nome
 ORDER BY total_de_unidades DESC;

-- ---------------------------------------------------------------------
-- C03. SITE: lista de produtos com preços (usa a view vw_catalogo)
-- ---------------------------------------------------------------------
SELECT categoria, nome, preco,
       IF(requer_receita, 'Sim', 'Não') AS exige_receita,
       IF(disponivel, 'Em estoque', 'Indisponível') AS situacao
  FROM vw_catalogo
 ORDER BY categoria, nome;

-- ---------------------------------------------------------------------
-- C04. ALERTA: produtos com estoque abaixo do mínimo
-- ---------------------------------------------------------------------
SELECT nome, estoque_atual, estoque_minimo,
       estoque_minimo - estoque_atual AS faltam
  FROM produto
 WHERE ativo = TRUE
   AND estoque_atual < estoque_minimo
 ORDER BY faltam DESC;

-- ---------------------------------------------------------------------
-- C05. ALERTA: produtos vencidos ou que vencem nos próximos 60 dias
--      (dias_para_vencer negativo = já venceu)
-- ---------------------------------------------------------------------
SELECT nome, validade, estoque_atual,
       DATEDIFF(validade, CURDATE()) AS dias_para_vencer
  FROM produto
 WHERE ativo = TRUE
   AND validade <= DATE_ADD(CURDATE(), INTERVAL 60 DAY)
 ORDER BY validade;

-- ---------------------------------------------------------------------
-- C06. ALERTA: promoções em vigor hoje, com o preço já com desconto
-- ---------------------------------------------------------------------
SELECT p.nome, pr.descricao, pr.percentual,
       p.preco AS preco_normal,
       ROUND(p.preco * (1 - pr.percentual / 100), 2) AS preco_promocional,
       pr.data_fim AS vale_ate
  FROM promocao pr
  JOIN produto p ON p.id_produto = pr.id_produto
 WHERE CURDATE() BETWEEN pr.data_inicio AND pr.data_fim;

-- ---------------------------------------------------------------------
-- C07. PEDIDOS: total de cada pedido (itens + taxa de entrega)
-- ---------------------------------------------------------------------
SELECT pe.id_pedido, c.nome AS cliente, pe.status,
       SUM(ip.quantidade * ip.preco_unitario) AS total_dos_itens,
       pe.taxa_entrega,
       SUM(ip.quantidade * ip.preco_unitario) + pe.taxa_entrega AS total_do_pedido
  FROM pedido pe
  JOIN cliente c      ON c.id_cliente = pe.id_cliente
  JOIN item_pedido ip ON ip.id_pedido = pe.id_pedido
 GROUP BY pe.id_pedido, c.nome, pe.status, pe.taxa_entrega
 ORDER BY pe.id_pedido;

-- ---------------------------------------------------------------------
-- C08. FINANCEIRO: faturamento por mês (soma dos pagamentos)
-- ---------------------------------------------------------------------
SELECT DATE_FORMAT(data_hora, '%Y-%m') AS mes,
       COUNT(*) AS pagamentos,
       SUM(valor) AS faturamento
  FROM pagamento
 GROUP BY DATE_FORMAT(data_hora, '%Y-%m')
 ORDER BY mes;

-- ---------------------------------------------------------------------
-- C09. VENDAS: quanto cada canal (internet, telefone, balcão) vendeu
-- ---------------------------------------------------------------------
SELECT pe.canal,
       COUNT(*) AS pedidos,
       SUM(pg.valor) AS total_vendido
  FROM pedido pe
  JOIN pagamento pg ON pg.id_pedido = pe.id_pedido
 GROUP BY pe.canal
 ORDER BY total_vendido DESC;

-- ---------------------------------------------------------------------
-- C10. VENDAS: os 5 produtos mais vendidos
-- ---------------------------------------------------------------------
SELECT p.nome,
       SUM(ip.quantidade) AS unidades_vendidas
  FROM item_pedido ip
  JOIN pedido pe ON pe.id_pedido = ip.id_pedido
  JOIN produto p ON p.id_produto = ip.id_produto
 WHERE pe.status <> 'CANCELADO'
 GROUP BY p.id_produto, p.nome
 ORDER BY unidades_vendidas DESC
 LIMIT 5;

-- ---------------------------------------------------------------------
-- C11. ENTREGAS: pendentes (aguardando ou em rota), com entregador e destino
-- ---------------------------------------------------------------------
SELECT e.id_pedido, e.status,
       f.nome AS entregador,
       c.nome AS cliente,
       CONCAT(c.logradouro, ', ', c.numero, ' - ', c.bairro) AS destino
  FROM entrega e
  JOIN pedido pe     ON pe.id_pedido = e.id_pedido
  JOIN cliente c     ON c.id_cliente = pe.id_cliente
  JOIN funcionario f ON f.id_funcionario = e.id_entregador
 WHERE e.status IN ('AGUARDANDO', 'EM_ROTA');

-- ---------------------------------------------------------------------
-- C12. ENTREGAS: quantas cada entregador fez e o tempo médio (em minutos)
-- ---------------------------------------------------------------------
SELECT f.nome AS entregador,
       COUNT(*) AS entregas,
       ROUND(AVG(TIMESTAMPDIFF(MINUTE, e.data_saida, e.data_entrega)), 1) AS minutos_medios
  FROM entrega e
  JOIN funcionario f ON f.id_funcionario = e.id_entregador
 WHERE e.status = 'ENTREGUE'
 GROUP BY f.id_funcionario, f.nome;

-- ---------------------------------------------------------------------
-- C13. CONTROLE: vendas de produtos que exigem receita (quem, médico, CRM)
-- ---------------------------------------------------------------------
SELECT pe.id_pedido, pe.data_hora, c.nome AS cliente,
       p.nome AS produto, r.nome_medico, r.crm_medico
  FROM item_pedido ip
  JOIN pedido pe  ON pe.id_pedido  = ip.id_pedido
  JOIN produto p  ON p.id_produto  = ip.id_produto
  JOIN receita r  ON r.id_receita  = ip.id_receita
  JOIN cliente c  ON c.id_cliente  = pe.id_cliente
 ORDER BY pe.data_hora;

-- ---------------------------------------------------------------------
-- C14. GESTÃO: produtos que nunca foram vendidos
--      (LEFT JOIN traz o produto mesmo sem venda; IS NULL filtra os "sem venda")
-- ---------------------------------------------------------------------
SELECT p.id_produto, p.nome
  FROM produto p
  LEFT JOIN item_pedido ip ON ip.id_produto = p.id_produto
 WHERE ip.id_produto IS NULL;

-- ---------------------------------------------------------------------
-- C15. CLIENTES: quem mais gastou (só quem pagou 2 ou mais pedidos)
--      HAVING filtra DEPOIS de agrupar (WHERE filtra antes)
-- ---------------------------------------------------------------------
SELECT c.nome,
       COUNT(*) AS pedidos_pagos,
       SUM(pg.valor) AS total_gasto
  FROM pagamento pg
  JOIN pedido pe ON pe.id_pedido = pg.id_pedido
  JOIN cliente c ON c.id_cliente = pe.id_cliente
 GROUP BY c.id_cliente, c.nome
HAVING COUNT(*) >= 2
 ORDER BY total_gasto DESC;

-- =====================================================================
-- PARTE B - OPERAÇÕES CRUD
-- =====================================================================

-- ---------------------------------------------------------------------
-- B1. CREATE (INSERT) - cadastrar um cliente novo
-- ---------------------------------------------------------------------
INSERT INTO cliente (id_cliente, nome, cpf, telefone, email, logradouro, numero, bairro, cep)
VALUES (9, 'Larissa Moura Teixeira', '10000000009', '31991110009',
        'larissa.teixeira@email.example', 'Rua Paraíba', '321', 'Funcionários', '30130140');

SELECT * FROM cliente WHERE id_cliente = 9;

-- ---------------------------------------------------------------------
-- B2. CREATE - um pedido novo completo no balcão:
--     pedido -> itens -> baixa no estoque -> pagamento
-- ---------------------------------------------------------------------
INSERT INTO pedido (id_pedido, id_cliente, id_funcionario, canal, tipo, status, taxa_entrega)
VALUES (14, 9, 3, 'BALCAO', 'RETIRADA', 'ABERTO', 0);

INSERT INTO item_pedido (id_pedido, id_produto, quantidade, preco_unitario, id_receita) VALUES
(14, 1, 3,  8.90, NULL),     -- 3 dipironas
(14, 3, 1, 15.90, NULL);     -- 1 ibuprofeno

-- baixa no estoque (o estoque diminui na quantidade vendida)
UPDATE produto SET estoque_atual = estoque_atual - 3 WHERE id_produto = 1;
UPDATE produto SET estoque_atual = estoque_atual - 1 WHERE id_produto = 3;

-- pagamento: 3 x 8,90 + 15,90 = 42,60
INSERT INTO pagamento (id_pedido, forma, valor) VALUES (14, 'PIX', 42.60);
UPDATE pedido SET status = 'CONCLUIDO' WHERE id_pedido = 14;

SELECT id_produto, nome, estoque_atual FROM produto WHERE id_produto IN (1, 3);

-- ---------------------------------------------------------------------
-- B3. CREATE - novo produto no catálogo
-- ---------------------------------------------------------------------
INSERT INTO produto (id_produto, nome, id_categoria, id_fornecedor, preco, estoque_atual, estoque_minimo, validade, requer_receita)
VALUES (18, 'Relaxante Muscular 36 comprimidos', 1, 2, 18.90, 120, 20, '2028-10-31', FALSE);

-- ---------------------------------------------------------------------
-- B4. UPDATE - reajustar o preço de um produto
-- ---------------------------------------------------------------------
UPDATE produto SET preco = 9.50 WHERE id_produto = 1;
SELECT id_produto, nome, preco FROM produto WHERE id_produto = 1;

-- ---------------------------------------------------------------------
-- B5. UPDATE - cliente mudou de endereço
-- ---------------------------------------------------------------------
UPDATE cliente
   SET logradouro = 'Avenida do Contorno', numero = '4500', bairro = 'Funcionários', cep = '30110028'
 WHERE id_cliente = 1;

-- ---------------------------------------------------------------------
-- B6. UPDATE - confirmar uma entrega: o cliente informa o código.
--     Se o código estiver errado, o UPDATE não altera nenhuma linha.
-- ---------------------------------------------------------------------
UPDATE entrega
   SET status = 'ENTREGUE', data_entrega = NOW(), recebido_por = 'Diego Alves Santos'
 WHERE id_pedido = 10 AND codigo_confirmacao = '482913';

UPDATE pedido SET status = 'CONCLUIDO' WHERE id_pedido = 10;

SELECT id_pedido, status, data_entrega, recebido_por FROM entrega WHERE id_pedido = 10;

-- ---------------------------------------------------------------------
-- B7. UPDATE - cancelar um pedido que ainda está ABERTO (pedido 12)
--     O estoque só baixa quando o pedido é pago; por isso aqui não há
--     nada para devolver. (Se fosse um pedido PAGO, o estoque voltaria
--     com: UPDATE produto SET estoque_atual = estoque_atual + quantidade ...)
-- ---------------------------------------------------------------------
UPDATE pedido SET status = 'CANCELADO' WHERE id_pedido = 12;

-- ---------------------------------------------------------------------
-- B8. UPDATE - retirar um produto de venda SEM apagá-lo
--     (o soro vencido some do catálogo, mas o histórico continua)
-- ---------------------------------------------------------------------
UPDATE produto SET ativo = FALSE WHERE id_produto = 17;

-- ---------------------------------------------------------------------
-- B9. DELETE - apagar uma promoção que já acabou
-- ---------------------------------------------------------------------
DELETE FROM promocao WHERE id_promocao = 3;

-- ---------------------------------------------------------------------
-- B10. DELETE - apagar um cadastro feito por engano
--      (só funciona porque esse cliente ainda não tem nenhum pedido)
-- ---------------------------------------------------------------------
INSERT INTO cliente (id_cliente, nome, cpf, telefone, logradouro, numero, bairro)
VALUES (10, 'Cadastro Duplicado', '10000000010', '31991110010', 'Rua Teste', '1', 'Centro');

DELETE FROM cliente WHERE id_cliente = 10;

-- ---------------------------------------------------------------------
-- B11. O banco PROTEGE os dados (estes comandos dão ERRO de propósito).
--      Tire o "--" da frente de UMA linha por vez para testar:
-- ---------------------------------------------------------------------
-- Cliente que já tem pedidos não pode ser apagado (FOREIGN KEY):
-- DELETE FROM cliente WHERE id_cliente = 1;

-- Não aceita dois clientes com o mesmo CPF (UNIQUE):
-- INSERT INTO cliente (nome, cpf, telefone, logradouro, numero, bairro)
-- VALUES ('Outro Nome', '10000000001', '31900000000', 'Rua X', '1', 'Centro');

-- Não aceita produto com categoria que não existe (FOREIGN KEY):
-- INSERT INTO produto (nome, id_categoria, id_fornecedor, preco)
-- VALUES ('Produto Inválido', 99, 1, 10.00);

-- Pedido só aceita canal da lista (ENUM):
-- INSERT INTO pedido (id_cliente, canal, tipo) VALUES (1, 'CARTA', 'ENTREGA');
