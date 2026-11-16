-- =====================================================================
-- Arquivo 03: NÍVEIS DE ACESSO  (VERSÃO SIMPLES)
-- Rode DEPOIS do 01 e do 02, com o usuário administrador (root).
--
-- Ideia: cada pessoa entra no banco com o SEU usuário, e cada usuário
-- só pode o que a sua função precisa. É como o crachá de um prédio:
-- o porteiro abre algumas portas, o diretor abre todas.
--
--   CREATE USER ... cria o usuário e define a senha
--   GRANT ... ON ... dá uma permissão (SELECT = ler, INSERT = cadastrar,
--                                      UPDATE = alterar, DELETE = apagar)
--
-- 4 níveis:
--   1) TI        -> pode tudo no banco
--   2) Gerente   -> lê tudo; cadastra e altera produtos, promoções, etc.
--   3) Atendente -> atende cliente, faz pedido, pagamento e entrega;
--                   não vê funcionários e não muda preço de produto
--   4) Cliente   -> só vê o catálogo do site (view vw_catalogo)
-- =====================================================================

USE farmacia_db;

-- ---------------------------------------------------------------------
-- Criar os usuários (TROQUE AS SENHAS antes de usar de verdade!)
-- ---------------------------------------------------------------------
CREATE USER IF NOT EXISTS 'ti_farmacia'@'localhost'        IDENTIFIED BY 'Troque#Ti2026';
CREATE USER IF NOT EXISTS 'gerente_farmacia'@'localhost'   IDENTIFIED BY 'Troque#Ger2026';
CREATE USER IF NOT EXISTS 'atendente_farmacia'@'localhost' IDENTIFIED BY 'Troque#Atd2026';
CREATE USER IF NOT EXISTS 'cliente_site'@'localhost'       IDENTIFIED BY 'Troque#Cli2026';

-- ---------------------------------------------------------------------
-- 1) TI: tudo no banco da farmácia
-- ---------------------------------------------------------------------
GRANT ALL PRIVILEGES ON farmacia_db.* TO 'ti_farmacia'@'localhost';

-- ---------------------------------------------------------------------
-- 2) Gerente: lê todas as tabelas e cadastra/altera o "catálogo"
-- ---------------------------------------------------------------------
GRANT SELECT ON farmacia_db.* TO 'gerente_farmacia'@'localhost';
GRANT INSERT, UPDATE ON farmacia_db.produto     TO 'gerente_farmacia'@'localhost';
GRANT INSERT, UPDATE ON farmacia_db.categoria   TO 'gerente_farmacia'@'localhost';
GRANT INSERT, UPDATE ON farmacia_db.fornecedor  TO 'gerente_farmacia'@'localhost';
GRANT INSERT, UPDATE ON farmacia_db.funcionario TO 'gerente_farmacia'@'localhost';
GRANT INSERT, UPDATE, DELETE ON farmacia_db.promocao TO 'gerente_farmacia'@'localhost';

-- ---------------------------------------------------------------------
-- 3) Atendente: dia a dia do balcão e do telefone
-- ---------------------------------------------------------------------
GRANT SELECT ON farmacia_db.vw_catalogo TO 'atendente_farmacia'@'localhost';
GRANT SELECT ON farmacia_db.produto     TO 'atendente_farmacia'@'localhost';
GRANT SELECT ON farmacia_db.promocao    TO 'atendente_farmacia'@'localhost';
GRANT SELECT, INSERT, UPDATE ON farmacia_db.cliente     TO 'atendente_farmacia'@'localhost';
GRANT SELECT, INSERT, UPDATE ON farmacia_db.receita     TO 'atendente_farmacia'@'localhost';
GRANT SELECT, INSERT, UPDATE ON farmacia_db.pedido      TO 'atendente_farmacia'@'localhost';
GRANT SELECT, INSERT, UPDATE ON farmacia_db.item_pedido TO 'atendente_farmacia'@'localhost';
GRANT SELECT, INSERT, UPDATE ON farmacia_db.pagamento   TO 'atendente_farmacia'@'localhost';
GRANT SELECT, INSERT, UPDATE ON farmacia_db.entrega     TO 'atendente_farmacia'@'localhost';
-- Permissão só para UMA coluna: o atendente pode baixar o estoque,
-- mas não consegue mudar o preço do produto.
GRANT UPDATE (estoque_atual) ON farmacia_db.produto TO 'atendente_farmacia'@'localhost';

-- ---------------------------------------------------------------------
-- 4) Cliente (site): só vê o catálogo
-- ---------------------------------------------------------------------
GRANT SELECT ON farmacia_db.vw_catalogo TO 'cliente_site'@'localhost';

FLUSH PRIVILEGES;

-- ---------------------------------------------------------------------
-- Como testar: abra uma conexão nova com cada usuário e tente:
--
--   atendente_farmacia:
--     SELECT nome, cpf FROM cliente;                  -- FUNCIONA
--     SELECT * FROM funcionario;                      -- ERRO (sem permissão)
--     UPDATE produto SET preco = 1 WHERE id_produto = 1;   -- ERRO (preço é só do gerente)
--
--   cliente_site:
--     SELECT nome, preco FROM vw_catalogo;            -- FUNCIONA
--     SELECT * FROM cliente;                          -- ERRO
--
-- Para ver o que um usuário pode:
--   SHOW GRANTS FOR 'atendente_farmacia'@'localhost';
-- ---------------------------------------------------------------------
