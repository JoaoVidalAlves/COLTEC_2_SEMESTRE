-- =====================================================================
-- TRABALHO FINAL - INTRODUÇÃO A BANCO DE DADOS (COLTEC UFMG)
-- Tema 8: Sistema de Gestão de Farmácia / Delivery  (VERSÃO SIMPLES)
-- Arquivo 01: CRIAÇÃO DO BANCO E DAS TABELAS (modelo físico)
--
-- Como usar: abra no MySQL Workbench e clique no raio amarelo
--            (executa o arquivo inteiro).
-- ATENÇÃO: este script APAGA o banco "farmacia_db" (se já existir)
--          e cria tudo de novo.
--
-- Guia rápido dos comandos usados aqui:
--   CREATE TABLE ........ cria uma tabela (uma "planilha" do banco)
--   PRIMARY KEY ......... o "CPF" da linha: identifica cada registro
--                         e nunca se repete
--   AUTO_INCREMENT ...... o banco numera sozinho (1, 2, 3...)
--   NOT NULL ............ o campo é obrigatório
--   UNIQUE .............. não aceita valor repetido (ex.: dois CPFs iguais)
--   DEFAULT ............. valor usado quando você não preenche o campo
--   FOREIGN KEY ......... liga uma tabela a outra: só aceita um valor
--                         que já existe na tabela de origem
--                         (ex.: um produto só pode ter categoria que existe)
--   ENUM ................ o campo só aceita uma das opções da lista
-- =====================================================================

DROP DATABASE IF EXISTS farmacia_db;
CREATE DATABASE farmacia_db CHARACTER SET utf8mb4;
USE farmacia_db;

-- ---------------------------------------------------------------------
-- Categorias de produto (ex.: Antibióticos, Vitaminas)
-- ---------------------------------------------------------------------
CREATE TABLE categoria (
  id_categoria INT AUTO_INCREMENT PRIMARY KEY,
  nome         VARCHAR(60) NOT NULL UNIQUE
);

-- ---------------------------------------------------------------------
-- Fornecedores (quem vende os produtos para a farmácia)
-- ---------------------------------------------------------------------
CREATE TABLE fornecedor (
  id_fornecedor INT AUTO_INCREMENT PRIMARY KEY,
  razao_social  VARCHAR(120) NOT NULL,
  cnpj          CHAR(14)     NOT NULL UNIQUE,
  telefone      VARCHAR(15)
);

-- ---------------------------------------------------------------------
-- Produtos (o estoque fica aqui mesmo, na coluna estoque_atual)
-- ---------------------------------------------------------------------
CREATE TABLE produto (
  id_produto     INT AUTO_INCREMENT PRIMARY KEY,
  nome           VARCHAR(120)  NOT NULL,
  id_categoria   INT           NOT NULL,
  id_fornecedor  INT           NOT NULL,
  preco          DECIMAL(10,2) NOT NULL,           -- dinheiro: sempre DECIMAL
  estoque_atual  INT           NOT NULL DEFAULT 0,
  estoque_minimo INT           NOT NULL DEFAULT 10, -- abaixo disso, vira alerta
  validade       DATE,
  requer_receita BOOLEAN       NOT NULL DEFAULT FALSE,
  ativo          BOOLEAN       NOT NULL DEFAULT TRUE, -- FALSE = retirado de venda
  FOREIGN KEY (id_categoria)  REFERENCES categoria (id_categoria),
  FOREIGN KEY (id_fornecedor) REFERENCES fornecedor (id_fornecedor)
);

-- ---------------------------------------------------------------------
-- Promoções (desconto em % por período)
-- ---------------------------------------------------------------------
CREATE TABLE promocao (
  id_promocao INT AUTO_INCREMENT PRIMARY KEY,
  id_produto  INT          NOT NULL,
  descricao   VARCHAR(100) NOT NULL,
  percentual  DECIMAL(5,2) NOT NULL,
  data_inicio DATE         NOT NULL,
  data_fim    DATE         NOT NULL,
  FOREIGN KEY (id_produto) REFERENCES produto (id_produto)
);

-- ---------------------------------------------------------------------
-- Clientes (o atendente busca por CPF ou celular e já vê o endereço)
-- ---------------------------------------------------------------------
CREATE TABLE cliente (
  id_cliente    INT AUTO_INCREMENT PRIMARY KEY,
  nome          VARCHAR(120) NOT NULL,
  cpf           CHAR(11)     NOT NULL UNIQUE,
  telefone      VARCHAR(15)  NOT NULL UNIQUE,
  email         VARCHAR(100),
  logradouro    VARCHAR(120) NOT NULL,
  numero        VARCHAR(10)  NOT NULL,
  bairro        VARCHAR(60)  NOT NULL,
  cidade        VARCHAR(60)  NOT NULL DEFAULT 'Belo Horizonte',
  cep           CHAR(8),
  data_cadastro DATETIME     NOT NULL DEFAULT CURRENT_TIMESTAMP,
  ativo         BOOLEAN      NOT NULL DEFAULT TRUE
);

-- ---------------------------------------------------------------------
-- Funcionários (atendentes, entregadores, gerente, TI...)
-- ---------------------------------------------------------------------
CREATE TABLE funcionario (
  id_funcionario INT AUTO_INCREMENT PRIMARY KEY,
  nome           VARCHAR(120) NOT NULL,
  cpf            CHAR(11)     NOT NULL UNIQUE,
  cargo          VARCHAR(30)  NOT NULL,
  telefone       VARCHAR(15),
  data_admissao  DATE         NOT NULL
);

-- ---------------------------------------------------------------------
-- Receitas médicas apresentadas pelos clientes
-- ---------------------------------------------------------------------
CREATE TABLE receita (
  id_receita    INT AUTO_INCREMENT PRIMARY KEY,
  id_cliente    INT          NOT NULL,
  nome_medico   VARCHAR(120) NOT NULL,
  crm_medico    VARCHAR(20)  NOT NULL,
  data_emissao  DATE         NOT NULL,
  data_validade DATE         NOT NULL,
  FOREIGN KEY (id_cliente) REFERENCES cliente (id_cliente)
);

-- ---------------------------------------------------------------------
-- Pedidos
--   id_funcionario = atendente (fica vazio se o cliente pediu pelo site)
--   canal  = por onde o pedido chegou
--   tipo   = entrega em casa ou retirada na loja
-- ---------------------------------------------------------------------
CREATE TABLE pedido (
  id_pedido      INT AUTO_INCREMENT PRIMARY KEY,
  id_cliente     INT      NOT NULL,
  id_funcionario INT,
  canal          ENUM('INTERNET','TELEFONE','BALCAO')                     NOT NULL,
  tipo           ENUM('ENTREGA','RETIRADA')                               NOT NULL,
  data_hora      DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
  status         ENUM('ABERTO','PAGO','EM_ROTA','CONCLUIDO','CANCELADO') NOT NULL DEFAULT 'ABERTO',
  taxa_entrega   DECIMAL(8,2) NOT NULL DEFAULT 0,
  FOREIGN KEY (id_cliente)     REFERENCES cliente (id_cliente),
  FOREIGN KEY (id_funcionario) REFERENCES funcionario (id_funcionario)
);

-- ---------------------------------------------------------------------
-- Itens do pedido (um pedido tem vários produtos, e um produto aparece
-- em vários pedidos). A chave primária usa DUAS colunas juntas:
-- o mesmo produto não se repete dentro do mesmo pedido.
-- preco_unitario guarda o preço COBRADO na venda (já com promoção).
-- id_receita só é preenchido quando o produto exige receita.
-- ---------------------------------------------------------------------
CREATE TABLE item_pedido (
  id_pedido      INT           NOT NULL,
  id_produto     INT           NOT NULL,
  quantidade     INT           NOT NULL,
  preco_unitario DECIMAL(10,2) NOT NULL,
  id_receita     INT,
  PRIMARY KEY (id_pedido, id_produto),
  FOREIGN KEY (id_pedido)  REFERENCES pedido (id_pedido),
  FOREIGN KEY (id_produto) REFERENCES produto (id_produto),
  FOREIGN KEY (id_receita) REFERENCES receita (id_receita)
);

-- ---------------------------------------------------------------------
-- Pagamentos
-- ---------------------------------------------------------------------
CREATE TABLE pagamento (
  id_pagamento INT AUTO_INCREMENT PRIMARY KEY,
  id_pedido    INT           NOT NULL,
  forma        ENUM('DINHEIRO','CREDITO','DEBITO','PIX') NOT NULL,
  valor        DECIMAL(10,2) NOT NULL,
  data_hora    DATETIME      NOT NULL DEFAULT CURRENT_TIMESTAMP,
  FOREIGN KEY (id_pedido) REFERENCES pedido (id_pedido)
);

-- ---------------------------------------------------------------------
-- Entregas (só para pedidos do tipo ENTREGA)
--   id_pedido UNIQUE = cada pedido tem no máximo uma entrega
--   id_entregador    = funcionário que leva o pedido
--   codigo_confirmacao = código que o cliente informa ao receber
-- ---------------------------------------------------------------------
CREATE TABLE entrega (
  id_entrega         INT AUTO_INCREMENT PRIMARY KEY,
  id_pedido          INT      NOT NULL UNIQUE,
  id_entregador      INT      NOT NULL,
  data_saida         DATETIME,
  data_entrega       DATETIME,
  status             ENUM('AGUARDANDO','EM_ROTA','ENTREGUE') NOT NULL DEFAULT 'AGUARDANDO',
  recebido_por       VARCHAR(120),
  codigo_confirmacao CHAR(6)  NOT NULL,
  FOREIGN KEY (id_pedido)     REFERENCES pedido (id_pedido),
  FOREIGN KEY (id_entregador) REFERENCES funcionario (id_funcionario)
);

-- ---------------------------------------------------------------------
-- VIEW = uma "janela" que mostra só parte dos dados.
-- Este é o catálogo que o cliente vê no site: nome, categoria e preço,
-- sem mostrar estoque mínimo, fornecedor etc.
-- ---------------------------------------------------------------------
CREATE VIEW vw_catalogo AS
SELECT p.id_produto,
       p.nome,
       c.nome AS categoria,
       p.preco,
       p.requer_receita,
       p.estoque_atual > 0 AS disponivel
  FROM produto p
  JOIN categoria c ON c.id_categoria = p.id_categoria
 WHERE p.ativo = TRUE;
