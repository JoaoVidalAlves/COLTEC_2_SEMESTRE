-- =====================================================================
-- Arquivo 02: INSERÇÃO DE DADOS DE EXEMPLO  (VERSÃO SIMPLES)
-- Rode DEPOIS do 01_criar_banco.sql.
-- Todos os nomes, CPFs, CNPJs e telefones são FICTÍCIOS.
--
-- ORDEM IMPORTANTE: primeiro as tabelas "de origem" (categoria,
-- fornecedor...) e só depois as que dependem delas (produto, pedido...).
-- Se inverter, o banco recusa por causa das FOREIGN KEYs.
-- =====================================================================

USE farmacia_db;

-- ---------------------------------------------------------------------
-- Categorias
-- ---------------------------------------------------------------------
INSERT INTO categoria (id_categoria, nome) VALUES
(1, 'Analgésicos e Antitérmicos'),
(2, 'Antibióticos'),
(3, 'Controlados'),
(4, 'Vitaminas e Suplementos'),
(5, 'Higiene e Cuidados'),
(6, 'Infantil');

-- ---------------------------------------------------------------------
-- Fornecedores
-- ---------------------------------------------------------------------
INSERT INTO fornecedor (id_fornecedor, razao_social, cnpj, telefone) VALUES
(1, 'Distribuidora Mineira de Medicamentos Ltda', '22000000000101', '3133330001'),
(2, 'Atacadão Farma BH Ltda',                     '22000000000202', '3133330002'),
(3, 'Nacional Saúde Distribuidora S.A.',          '22000000000303', '3133330003');

-- ---------------------------------------------------------------------
-- Produtos (17)
-- Colunas: id, nome, categoria, fornecedor, preço, estoque atual,
--          estoque mínimo, validade, exige receita?
-- Obs.: o produto 6 está com estoque baixo, o 9 vence em breve e
--       o 17 já está vencido (servem para testar os alertas).
-- ---------------------------------------------------------------------
INSERT INTO produto (id_produto, nome, id_categoria, id_fornecedor, preco, estoque_atual, estoque_minimo, validade, requer_receita) VALUES
( 1, 'Dipirona Sódica 500mg 10 comprimidos',       1, 1,  8.90, 200, 30, '2028-03-31', FALSE),
( 2, 'Paracetamol 750mg 20 comprimidos',           1, 1, 12.50, 180, 30, '2028-05-31', FALSE),
( 3, 'Ibuprofeno 600mg 10 comprimidos',            1, 2, 15.90, 150, 20, '2027-11-30', FALSE),
( 4, 'Amoxicilina 500mg 21 cápsulas',              2, 3, 38.90,  60, 15, '2027-08-31', TRUE),
( 5, 'Azitromicina 500mg 3 comprimidos',           2, 3, 29.90,  40, 15, '2027-10-31', TRUE),
( 6, 'Cefalexina 500mg 8 cápsulas',                2, 1, 34.50,   8, 10, '2027-07-31', TRUE),
( 7, 'Clonazepam 2mg 30 comprimidos',              3, 3, 22.00,  50, 10, '2028-01-31', TRUE),
( 8, 'Alprazolam 0,5mg 30 comprimidos',            3, 3, 19.90,  45, 10, '2028-02-29', TRUE),
( 9, 'Vitamina C 1g 30 comprimidos efervescentes', 4, 2, 21.90, 100, 20, '2026-12-15', FALSE),
(10, 'Vitamina D3 2000UI 30 cápsulas',             4, 1, 35.00,  50, 15, '2028-06-30', FALSE),
(11, 'Multivitamínico 60 comprimidos',             4, 2, 49.90,  30, 10, '2028-07-31', FALSE),
(12, 'Sabonete Líquido Antisséptico 250ml',        5, 2, 14.90,  70, 20, '2029-01-31', FALSE),
(13, 'Álcool em Gel 70% 500ml',                    5, 2, 11.90, 100, 25, '2029-03-31', FALSE),
(14, 'Protetor Solar FPS 50 120ml',                5, 2, 59.90,  25, 10, '2028-11-30', FALSE),
(15, 'Fralda Descartável Tamanho M 40 unidades',   6, 2, 52.90,  40, 10, '2030-01-31', FALSE),
(16, 'Lenço Umedecido 100 unidades',               6, 2, 13.90,  60, 15, '2029-10-31', FALSE),
(17, 'Soro Fisiológico 0,9% 500ml',                5, 1,  9.50,   5, 20, '2026-10-20', FALSE);

-- ---------------------------------------------------------------------
-- Promoções
-- ---------------------------------------------------------------------
INSERT INTO promocao (id_promocao, id_produto, descricao, percentual, data_inicio, data_fim) VALUES
(1,  9, 'Novembro Imune', 20, '2026-11-01', '2026-11-30'),
(2, 14, 'Verão Chegando', 15, '2026-11-01', '2026-12-31'),
(3, 15, 'Semana do Bebê', 10, '2026-10-01', '2026-10-31');

-- ---------------------------------------------------------------------
-- Funcionários
-- ---------------------------------------------------------------------
INSERT INTO funcionario (id_funcionario, nome, cpf, cargo, telefone, data_admissao) VALUES
(1, 'Carlos Eduardo Mendes',   '30000000001', 'Gerente',        '31988880001', '2022-03-01'),
(2, 'Fernanda Lopes Ribeiro',  '30000000002', 'Farmacêutica',   '31988880002', '2022-05-16'),
(3, 'Juliana Castro Almeida',  '30000000003', 'Atendente',      '31988880003', '2023-02-01'),
(4, 'Rafael Souza Lima',       '30000000004', 'Atendente',      '31988880004', '2023-08-21'),
(5, 'Marcos Vinícius Pereira', '30000000005', 'Entregador',     '31988880005', '2024-01-08'),
(6, 'Bruno Henrique Dias',     '30000000006', 'Entregador',     '31988880006', '2024-06-10'),
(7, 'Patrícia Nogueira',       '30000000007', 'Analista de TI', '31988880007', '2025-01-13');

-- ---------------------------------------------------------------------
-- Clientes (8)
-- ---------------------------------------------------------------------
INSERT INTO cliente (id_cliente, nome, cpf, telefone, email, logradouro, numero, bairro, cidade, cep, data_cadastro) VALUES
(1, 'Ana Paula Ferreira',       '10000000001', '31991110001', 'ana.ferreira@email.example',     'Rua Pernambuco',           '1200', 'Savassi',         'Belo Horizonte', '30130151', '2026-01-10 10:00:00'),
(2, 'Bruno Martins Costa',      '10000000002', '31991110002', 'bruno.costa@email.example',      'Avenida Otacílio Negrão de Lima', '800', 'Pampulha',  'Belo Horizonte', '31365450', '2026-01-15 14:20:00'),
(3, 'Camila Rodrigues Silva',   '10000000003', '31991110003', 'camila.silva@email.example',     'Rua Salinas',              '250',  'Buritis',         'Belo Horizonte', '30575090', '2026-02-02 09:45:00'),
(4, 'Diego Alves Santos',       '10000000004', '31991110004', 'diego.santos@email.example',     'Rua Itambé',               '75',   'Santa Efigênia',  'Belo Horizonte', '30260120', '2026-02-20 16:10:00'),
(5, 'Eduarda Pinto Moreira',    '10000000005', '31991110005', 'eduarda.moreira@email.example',  'Rua Rio Grande do Norte',  '990',  'Lourdes',         'Belo Horizonte', '30130131', '2026-03-05 11:30:00'),
(6, 'Felipe Araújo Gomes',      '10000000006', '31991110006', 'felipe.gomes@email.example',     'Rua Grão Mogol',           '310',  'Sion',            'Belo Horizonte', '30315290', '2026-03-18 08:55:00'),
(7, 'Gabriela Nunes Carvalho',  '10000000007', '31991110007', 'gabriela.carvalho@email.example','Rua Marquês de Maricá',    '45',   'Anchieta',        'Belo Horizonte', '30310100', '2026-04-01 13:15:00'),
(8, 'Henrique Barros Monteiro', '10000000008', '31991110008', 'henrique.monteiro@email.example','Rua Santa Catarina',       '1500', 'Santo Agostinho', 'Belo Horizonte', '30170080', '2026-04-12 17:40:00');

-- ---------------------------------------------------------------------
-- Receitas
-- ---------------------------------------------------------------------
INSERT INTO receita (id_receita, id_cliente, nome_medico, crm_medico, data_emissao, data_validade) VALUES
(1, 3, 'Dr. Paulo Henrique Lacerda', 'CRM-MG 45678', '2026-10-10', '2026-11-09'),  -- clonazepam
(2, 5, 'Dra. Marina Teixeira',       'CRM-MG 12345', '2026-10-16', '2026-10-26'),  -- amoxicilina
(3, 8, 'Dr. Ricardo Aguiar',         'CRM-MG 33210', '2026-10-18', '2026-10-28');  -- azitromicina

-- ---------------------------------------------------------------------
-- Pedidos (13)
-- Colunas: id, cliente, atendente (NULL = pediu pelo site), canal, tipo,
--          data/hora, status, taxa de entrega
-- ---------------------------------------------------------------------
INSERT INTO pedido (id_pedido, id_cliente, id_funcionario, canal, tipo, data_hora, status, taxa_entrega) VALUES
( 1, 1, NULL, 'INTERNET', 'ENTREGA',  '2026-10-05 09:15:00', 'CONCLUIDO', 6.00),
( 2, 2, 3,    'TELEFONE', 'ENTREGA',  '2026-10-08 14:30:00', 'CONCLUIDO', 6.00),
( 3, 3, 4,    'BALCAO',   'RETIRADA', '2026-10-12 10:05:00', 'CONCLUIDO', 0.00),
( 4, 4, NULL, 'INTERNET', 'ENTREGA',  '2026-10-14 19:40:00', 'CONCLUIDO', 6.00),
( 5, 5, 3,    'TELEFONE', 'ENTREGA',  '2026-10-18 16:20:00', 'CONCLUIDO', 7.50),
( 6, 8, 4,    'BALCAO',   'RETIRADA', '2026-10-20 11:00:00', 'CONCLUIDO', 0.00),
( 7, 1, NULL, 'INTERNET', 'ENTREGA',  '2026-10-24 08:50:00', 'CONCLUIDO', 6.00),
( 8, 6, 3,    'TELEFONE', 'ENTREGA',  '2026-10-28 13:10:00', 'CONCLUIDO', 8.00),
( 9, 2, NULL, 'INTERNET', 'ENTREGA',  '2026-11-02 10:30:00', 'CONCLUIDO', 6.00),
(10, 4, NULL, 'INTERNET', 'ENTREGA',  '2026-11-05 20:10:00', 'EM_ROTA',   6.00),
(11, 3, 3,    'TELEFONE', 'ENTREGA',  '2026-11-06 09:40:00', 'PAGO',      6.00),
(12, 7, NULL, 'INTERNET', 'RETIRADA', '2026-11-07 08:20:00', 'ABERTO',    0.00),
(13, 5, 3,    'BALCAO',   'RETIRADA', '2026-11-04 12:00:00', 'CANCELADO', 0.00);

-- ---------------------------------------------------------------------
-- Itens dos pedidos
-- Colunas: pedido, produto, quantidade, preço cobrado, receita
-- Obs.: nos pedidos 4, 9 e 11 o preço já está com a promoção
--       (fralda -10%, vitamina C -20%, protetor solar -15%).
-- ---------------------------------------------------------------------
INSERT INTO item_pedido (id_pedido, id_produto, quantidade, preco_unitario, id_receita) VALUES
( 1,  1, 2,  8.90, NULL),
( 1,  9, 1, 21.90, NULL),
( 1, 13, 2, 11.90, NULL),
( 2,  2, 1, 12.50, NULL),
( 2,  3, 2, 15.90, NULL),
( 3,  7, 1, 22.00, 1),
( 4, 15, 1, 47.61, NULL),
( 4, 16, 2, 13.90, NULL),
( 4, 12, 1, 14.90, NULL),
( 5,  4, 1, 38.90, 2),
( 5, 10, 1, 35.00, NULL),
( 6,  5, 1, 29.90, 3),
( 6,  2, 1, 12.50, NULL),
( 6, 13, 1, 11.90, NULL),
( 7, 14, 1, 59.90, NULL),
( 8,  3, 1, 15.90, NULL),
( 8, 17, 2,  9.50, NULL),
( 9,  9, 2, 17.52, NULL),
( 9, 11, 1, 49.90, NULL),
(10, 15, 2, 52.90, NULL),
(10, 16, 3, 13.90, NULL),
(11,  1, 1,  8.90, NULL),
(11, 14, 1, 50.92, NULL),
(12, 12, 1, 14.90, NULL),
(13,  2, 2, 12.50, NULL);

-- ---------------------------------------------------------------------
-- Pagamentos (valor = soma dos itens + taxa de entrega)
-- Os pedidos 12 (aberto) e 13 (cancelado) não têm pagamento.
-- ---------------------------------------------------------------------
INSERT INTO pagamento (id_pedido, forma, valor, data_hora) VALUES
( 1, 'PIX',      69.50, '2026-10-05 09:16:00'),
( 2, 'CREDITO',  50.30, '2026-10-08 14:32:00'),
( 3, 'DEBITO',   22.00, '2026-10-12 10:06:00'),
( 4, 'PIX',      96.31, '2026-10-14 19:41:00'),
( 5, 'CREDITO',  81.40, '2026-10-18 16:22:00'),
( 6, 'DINHEIRO', 54.30, '2026-10-20 11:02:00'),
( 7, 'PIX',      65.90, '2026-10-24 08:51:00'),
( 8, 'CREDITO',  42.90, '2026-10-28 13:12:00'),
( 9, 'PIX',      90.94, '2026-11-02 10:31:00'),
(10, 'PIX',     153.50, '2026-11-05 20:11:00'),
(11, 'CREDITO',  65.82, '2026-11-06 09:42:00');

-- ---------------------------------------------------------------------
-- Entregas (só pedidos do tipo ENTREGA)
-- Colunas: pedido, entregador, saída, entrega, status, recebido por, código
-- ---------------------------------------------------------------------
INSERT INTO entrega (id_pedido, id_entregador, data_saida, data_entrega, status, recebido_por, codigo_confirmacao) VALUES
( 1, 5, '2026-10-05 09:40:00', '2026-10-05 10:10:00', 'ENTREGUE',   'Ana Paula Ferreira',   '100001'),
( 2, 6, '2026-10-08 14:55:00', '2026-10-08 15:30:00', 'ENTREGUE',   'Bruno Martins Costa',  '100002'),
( 4, 5, '2026-10-14 20:05:00', '2026-10-14 20:40:00', 'ENTREGUE',   'Diego Alves Santos',   '100004'),
( 5, 6, '2026-10-18 16:45:00', '2026-10-18 17:25:00', 'ENTREGUE',   'Eduarda Pinto Moreira','100005'),
( 7, 5, '2026-10-24 09:15:00', '2026-10-24 09:45:00', 'ENTREGUE',   'Ana Paula Ferreira',   '100007'),
( 8, 6, '2026-10-28 13:35:00', '2026-10-28 14:10:00', 'ENTREGUE',   'Felipe Araújo Gomes',  '100008'),
( 9, 5, '2026-11-02 10:55:00', '2026-11-02 11:30:00', 'ENTREGUE',   'Bruno Martins Costa',  '100009'),
(10, 6, '2026-11-05 20:30:00', NULL,                  'EM_ROTA',    NULL,                   '482913'),
(11, 5, NULL,                  NULL,                  'AGUARDANDO', NULL,                   '715204');

-- ---------------------------------------------------------------------
-- Conferência: quantas linhas ficaram em cada tabela
-- ---------------------------------------------------------------------
SELECT 'categoria' AS tabela, COUNT(*) AS linhas FROM categoria
UNION ALL SELECT 'fornecedor',  COUNT(*) FROM fornecedor
UNION ALL SELECT 'produto',     COUNT(*) FROM produto
UNION ALL SELECT 'promocao',    COUNT(*) FROM promocao
UNION ALL SELECT 'funcionario', COUNT(*) FROM funcionario
UNION ALL SELECT 'cliente',     COUNT(*) FROM cliente
UNION ALL SELECT 'receita',     COUNT(*) FROM receita
UNION ALL SELECT 'pedido',      COUNT(*) FROM pedido
UNION ALL SELECT 'item_pedido', COUNT(*) FROM item_pedido
UNION ALL SELECT 'pagamento',   COUNT(*) FROM pagamento
UNION ALL SELECT 'entrega',     COUNT(*) FROM entrega;
