-- phpMyAdmin SQL Dump
-- version 5.1.1deb5ubuntu1
-- https://www.phpmyadmin.net/
--
-- Host: localhost:3306
-- Tempo de geração: 29/09/2026 às 00:18
-- Versão do servidor: 8.0.46-0ubuntu0.22.04.4
-- Versão do PHP: 8.1.2-1ubuntu2.26

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Banco de dados: `prova1_joao_pedro`
--

-- --------------------------------------------------------

--
-- Estrutura para tabela `Categorias`
--

CREATE TABLE `Categorias` (
  `id` int NOT NULL,
  `categoria` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Despejando dados para a tabela `Categorias`
--

INSERT INTO `Categorias` (`id`, `categoria`) VALUES
(10, 'papelaria'),
(11, 'informatica'),
(12, 'oficina'),
(13, 'moveis');

-- --------------------------------------------------------

--
-- Estrutura para tabela `cores`
--

CREATE TABLE `cores` (
  `id_cor` int NOT NULL,
  `nome_cor` varchar(20) COLLATE utf8mb4_unicode_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Despejando dados para a tabela `cores`
--

INSERT INTO `cores` (`id_cor`, `nome_cor`) VALUES
(1, 'Vermelha'),
(2, 'Branca'),
(3, 'Amarela'),
(4, 'Rosa'),
(5, 'Roxa');

-- --------------------------------------------------------

--
-- Estrutura para tabela `Estoque`
--

CREATE TABLE `Estoque` (
  `id_produto` int NOT NULL,
  `quantidade` int NOT NULL,
  `tipo` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Despejando dados para a tabela `Estoque`
--

INSERT INTO `Estoque` (`id_produto`, `quantidade`, `tipo`) VALUES
(1, 300, 'unidade'),
(2, 300, 'unidade'),
(3, 500, 'pacote'),
(4, 200, 'pacote'),
(5, 50, 'unidade'),
(6, 60, 'unidade'),
(7, 20, 'unidade'),
(8, 5, 'unidade'),
(9, 30, 'unidade'),
(10, 10, 'unidade');

-- --------------------------------------------------------

--
-- Estrutura para tabela `Financeiro`
--

CREATE TABLE `Financeiro` (
  `produto` int NOT NULL,
  `preco_base` decimal(10,2) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Despejando dados para a tabela `Financeiro`
--

INSERT INTO `Financeiro` (`produto`, `preco_base`) VALUES
(1, '2.00'),
(2, '3.00'),
(3, '30.00'),
(4, '40.00'),
(5, '50.00'),
(6, '100.00'),
(7, '500.00'),
(8, '1000.00'),
(9, '90.00'),
(10, '900.00');

-- --------------------------------------------------------

--
-- Estrutura para tabela `flores`
--

CREATE TABLE `flores` (
  `id_flor` int NOT NULL,
  `nome` varchar(100) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  `especie` varchar(60) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  `preco` decimal(10,2) NOT NULL,
  `estoque` int NOT NULL,
  `id_cor` int NOT NULL,
  `id_formato` int NOT NULL,
  `id_regiao` int NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Despejando dados para a tabela `flores`
--

INSERT INTO `flores` (`id_flor`, `nome`, `especie`, `preco`, `estoque`, `id_cor`, `id_formato`, `id_regiao`) VALUES
(1, 'Rosa Rubi', 'Rosa', '18.00', 40, 1, 2, 1),
(2, 'Rosa Neve', 'Rosa', '22.00', 25, 2, 1, 2),
(3, 'Rosa Sol', 'Rosa', '20.00', 15, 3, 2, 3),
(4, 'Rosa Aurora', 'Rosa', '26.00', 30, 4, 1, 1),
(5, 'Orquídea Lilás', 'Orquídea', '45.00', 12, 5, 3, 2),
(6, 'Lírio Branco', 'Lírio', '32.00', 20, 2, 2, 1),
(7, 'Girassol Dourado', 'Girassol', '15.00', 60, 3, 1, 4),
(8, 'Tulipa Vermelha', 'Tulipa', '28.00', 18, 1, 2, 2),
(9, 'Orquídea Branca', 'Orquídea', '50.00', 8, 2, 3, 5),
(10, 'Rosa Carmim', 'Rosa', '24.00', 35, 1, 1, 3),
(11, 'Lírio Amarelo', 'Lírio', '30.00', 22, 3, 2, 4),
(12, 'Tulipa Rosa', 'Tulipa', '27.00', 16, 4, 1, 1);

-- --------------------------------------------------------

--
-- Estrutura para tabela `formato_petalas`
--

CREATE TABLE `formato_petalas` (
  `id_formato` int NOT NULL,
  `descricao` varchar(20) COLLATE utf8mb4_unicode_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Despejando dados para a tabela `formato_petalas`
--

INSERT INTO `formato_petalas` (`id_formato`, `descricao`) VALUES
(1, 'Circular'),
(2, 'Oval'),
(3, 'Asa');

-- --------------------------------------------------------

--
-- Estrutura para tabela `miniaturas`
--

CREATE TABLE `miniaturas` (
  `id_miniatura` int NOT NULL,
  `modelo` varchar(100) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  `preco` decimal(10,2) NOT NULL,
  `quantidade` int NOT NULL,
  `id_tipo` int NOT NULL,
  `id_tamanho` int NOT NULL,
  `id_raridade` int NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Despejando dados para a tabela `miniaturas`
--

INSERT INTO `miniaturas` (`id_miniatura`, `modelo`, `preco`, `quantidade`, `id_tipo`, `id_tamanho`, `id_raridade`) VALUES
(1, 'Fusca Clássico', '45.00', 18, 1, 1, 1),
(2, 'Ferrari F40', '180.00', 4, 1, 2, 3),
(3, 'Opala SS', '95.00', 9, 1, 2, 2),
(4, 'Ford Mustang 1967', '240.00', 2, 1, 3, 4),
(5, 'Boeing 747', '130.00', 6, 2, 3, 2),
(6, 'Caça F-14', '210.00', 3, 2, 2, 3),
(7, 'Airbus A320', '85.00', 12, 2, 2, 1),
(8, 'Locomotiva a Vapor', '260.00', 2, 3, 3, 4),
(9, 'Trem-Bala Shinkansen', '160.00', 5, 3, 2, 3),
(10, 'Trem de Carga', '70.00', 14, 3, 1, 1),
(11, 'Leão Africano', '55.00', 16, 4, 1, 1),
(12, 'Elefante Asiático', '110.00', 7, 4, 3, 2),
(13, 'Tigre Branco', '195.00', 3, 4, 2, 3),
(14, 'Lobo-Guará', '90.00', 8, 4, 2, 2);

-- --------------------------------------------------------

--
-- Estrutura para tabela `Produtos`
--

CREATE TABLE `Produtos` (
  `id` int NOT NULL,
  `nome` varchar(100) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  `tipo` varchar(1) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  `categoria` int NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Despejando dados para a tabela `Produtos`
--

INSERT INTO `Produtos` (`id`, `nome`, `tipo`, `categoria`) VALUES
(1, 'lapis', 'p', 10),
(2, 'caneta', 'p', 10),
(3, 'papel A4', 'p', 10),
(4, 'papel A3', 'p', 10),
(5, 'mouse', 'I', 11),
(6, 'teclado', 'I', 11),
(7, 'ssd', 'I', 11),
(8, 'impressora', 'I', 11),
(9, 'alicate', 'f', 12),
(10, 'cadeira', 'm', 13);

-- --------------------------------------------------------

--
-- Estrutura para tabela `raridades`
--

CREATE TABLE `raridades` (
  `COL 1` varchar(11) DEFAULT NULL,
  `COL 2` varchar(4) DEFAULT NULL,
  `COL 3` varchar(10) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

--
-- Despejando dados para a tabela `raridades`
--

INSERT INTO `raridades` (`COL 1`, `COL 2`, `COL 3`) VALUES
('id_raridade', 'grau', 'descricao'),
('1', '1', 'Comum'),
('2', '2', 'Incomum'),
('3', '3', 'Rara'),
('4', '4', 'Muito rara');

-- --------------------------------------------------------

--
-- Estrutura para tabela `regioes`
--

CREATE TABLE `regioes` (
  `id_regiao` int NOT NULL,
  `nome_regiao` varchar(20) COLLATE utf8mb4_unicode_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Despejando dados para a tabela `regioes`
--

INSERT INTO `regioes` (`id_regiao`, `nome_regiao`) VALUES
(1, 'Sudeste'),
(2, 'Sul'),
(3, 'Nordeste'),
(4, 'Centro-Oeste'),
(5, 'Norte');

-- --------------------------------------------------------

--
-- Estrutura para tabela `tipos`
--

CREATE TABLE `tipos` (
  `A` int DEFAULT NULL,
  `B` varchar(10) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

--
-- Despejando dados para a tabela `tipos`
--

INSERT INTO `tipos` (`A`, `B`) VALUES
(1, 'Automóveis'),
(2, 'Aviões'),
(3, 'Trens'),
(4, 'Animais');

--
-- Índices para tabelas despejadas
--

--
-- Índices de tabela `Categorias`
--
ALTER TABLE `Categorias`
  ADD PRIMARY KEY (`id`);

--
-- Índices de tabela `cores`
--
ALTER TABLE `cores`
  ADD PRIMARY KEY (`id_cor`);

--
-- Índices de tabela `Estoque`
--
ALTER TABLE `Estoque`
  ADD PRIMARY KEY (`id_produto`);

--
-- Índices de tabela `Financeiro`
--
ALTER TABLE `Financeiro`
  ADD PRIMARY KEY (`produto`);

--
-- Índices de tabela `flores`
--
ALTER TABLE `flores`
  ADD PRIMARY KEY (`id_flor`),
  ADD KEY `fk_flores_cor` (`id_cor`),
  ADD KEY `fk_flores_formato` (`id_formato`),
  ADD KEY `fk_flores_regiao` (`id_regiao`);

--
-- Índices de tabela `formato_petalas`
--
ALTER TABLE `formato_petalas`
  ADD PRIMARY KEY (`id_formato`);

--
-- Índices de tabela `miniaturas`
--
ALTER TABLE `miniaturas`
  ADD PRIMARY KEY (`id_miniatura`),
  ADD KEY `fk_miniaturas_tipos` (`id_tipo`),
  ADD KEY `fk_miniaturas_tamanhos` (`id_tamanho`),
  ADD KEY `fk_miniaturas_raridades` (`id_raridade`);

--
-- Índices de tabela `Produtos`
--
ALTER TABLE `Produtos`
  ADD PRIMARY KEY (`id`),
  ADD KEY `fk_produtos_categoria` (`categoria`);

--
-- Índices de tabela `regioes`
--
ALTER TABLE `regioes`
  ADD PRIMARY KEY (`id_regiao`);

--
-- AUTO_INCREMENT para tabelas despejadas
--

--
-- AUTO_INCREMENT de tabela `cores`
--
ALTER TABLE `cores`
  MODIFY `id_cor` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT de tabela `formato_petalas`
--
ALTER TABLE `formato_petalas`
  MODIFY `id_formato` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT de tabela `regioes`
--
ALTER TABLE `regioes`
  MODIFY `id_regiao` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- Restrições para tabelas despejadas
--

--
-- Restrições para tabelas `Estoque`
--
ALTER TABLE `Estoque`
  ADD CONSTRAINT `fk_estoque_produto` FOREIGN KEY (`id_produto`) REFERENCES `Produtos` (`id`);

--
-- Restrições para tabelas `Financeiro`
--
ALTER TABLE `Financeiro`
  ADD CONSTRAINT `fk_financeiro_produto` FOREIGN KEY (`produto`) REFERENCES `Produtos` (`id`);

--
-- Restrições para tabelas `Produtos`
--
ALTER TABLE `Produtos`
  ADD CONSTRAINT `fk_produtos_categoria` FOREIGN KEY (`categoria`) REFERENCES `Categorias` (`id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
