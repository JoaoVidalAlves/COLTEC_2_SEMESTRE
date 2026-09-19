-- phpMyAdmin SQL Dump
-- version 5.1.1deb5ubuntu1
-- https://www.phpmyadmin.net/
--
-- Host: localhost:3306
-- Tempo de geração: 14/09/2026 às 14:40
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
-- Banco de dados: `EmpresaC`
--

-- --------------------------------------------------------

--
-- Estrutura para tabela `Laptop`
--

CREATE TABLE `Laptop` (
  `code` int DEFAULT NULL,
  `model` varchar(50) DEFAULT NULL,
  `speed` smallint DEFAULT NULL,
  `ram` smallint DEFAULT NULL,
  `hd` double DEFAULT NULL,
  `price` decimal(10,0) DEFAULT NULL,
  `screen` tinyint DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Despejando dados para a tabela `Laptop`
--

INSERT INTO `Laptop` (`code`, `model`, `speed`, `ram`, `hd`, `price`, `screen`) VALUES
(1, '1298', 350, 32, 4, '700', 11),
(2, '1321', 500, 64, 8, '970', 12),
(3, '1750', 750, 128, 12, '1200', 14),
(4, '1298', 600, 64, 10, '1050', 15),
(5, '1752', 750, 128, 10, '1150', 14),
(6, '1298', 450, 64, 10, '950', 12);

-- --------------------------------------------------------

--
-- Estrutura para tabela `PC`
--

CREATE TABLE `PC` (
  `code` int DEFAULT NULL,
  `model` varchar(50) DEFAULT NULL,
  `speed` smallint DEFAULT NULL,
  `ram` smallint DEFAULT NULL,
  `hd` double DEFAULT NULL,
  `cd` varchar(10) DEFAULT NULL,
  `price` decimal(10,0) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Despejando dados para a tabela `PC`
--

INSERT INTO `PC` (`code`, `model`, `speed`, `ram`, `hd`, `cd`, `price`) VALUES
(1, '1232', 500, 64, 5, '12x', '600'),
(2, '1121', 750, 128, 14, '40x', '850'),
(3, '1233', 500, 64, 5, '12x', '600'),
(4, '1121', 600, 128, 14, '40x', '850'),
(5, '1121', 600, 128, 8, '40x', '850'),
(6, '1233', 750, 128, 20, '50x', '950'),
(7, '1232', 500, 32, 10, '12x', '400'),
(8, '1232', 450, 64, 8, '24x', '350'),
(9, '1232', 450, 32, 10, '24x', '350'),
(10, '1260', 500, 32, 10, '12x', '350'),
(11, '1233', 900, 128, 40, '40x', '980'),
(12, '1233', 800, 128, 20, '50x', '970');

-- --------------------------------------------------------

--
-- Estrutura para tabela `Printer`
--

CREATE TABLE `Printer` (
  `code` int DEFAULT NULL,
  `model` varchar(50) DEFAULT NULL,
  `color` char(1) DEFAULT NULL,
  `type` varchar(10) DEFAULT NULL,
  `price` decimal(10,0) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Despejando dados para a tabela `Printer`
--

INSERT INTO `Printer` (`code`, `model`, `color`, `type`, `price`) VALUES
(6, '1288', 'n', 'Laser', '400'),
(5, '1408', 'n', 'Matrix', '270'),
(4, '1401', 'n', 'Matrix', '150'),
(3, '1434', 'y', 'Jet', '290'),
(2, '1433', 'y', 'Jet', '270'),
(1, '1276', 'n', 'Laser', '400');

-- --------------------------------------------------------

--
-- Estrutura para tabela `Product`
--

CREATE TABLE `Product` (
  `maker` varchar(10) DEFAULT NULL,
  `model` varchar(50) DEFAULT NULL,
  `type` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Despejando dados para a tabela `Product`
--

INSERT INTO `Product` (`maker`, `model`, `type`) VALUES
('B', '1121', 'PC'),
('A', '1232', 'PC'),
('A', '1233', 'PC'),
('E', '1260', 'PC'),
('A', '1276', 'Printer'),
('D', '1288', 'Printer'),
('A', '1298', 'Laptop'),
('C', '1321', 'Laptop'),
('A', '1401', 'Printer'),
('A', '1408', 'Printer'),
('D', '1433', 'Printer'),
('E', '1434', 'Printer'),
('B', '1750', 'Laptop'),
('A', '1752', 'Laptop'),
('E', '2113', 'PC'),
('E', '2112', 'PC');
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
