-- phpMyAdmin SQL Dump
-- version 5.1.1deb5ubuntu1
-- https://www.phpmyadmin.net/
--
-- Host: localhost:3306
-- Generation Time: Aug 13, 2024 at 09:31 AM
-- Server version: 8.0.39-0ubuntu0.22.04.1
-- PHP Version: 8.3.10

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `empresa2`
--

create database if not exists empresa2;
use empresa2;
-- --------------------------------------------------------

--
-- Table structure for table `clientes`
--

CREATE TABLE `clientes` (
  `ID` varchar(2) NOT NULL,
  `Nome` varchar(11) DEFAULT NULL,
  `Endereco` varchar(13) DEFAULT NULL,
  `Cidade` varchar(7) DEFAULT NULL,
  `CEP` varchar(5) DEFAULT NULL,
  `Estado` varchar(6) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

--
-- Dumping data for table `clientes`
--

INSERT INTO `clientes` (`ID`, `Nome`, `Endereco`, `Cidade`, `CEP`, `Estado`) VALUES
('1', 'Jose Maria', 'Rua 1, num 2', 'Betim', '12209', 'MG'),
('2', 'Maria Jose', 'Rua 2, num 33', 'Maceio', '5021', 'AL'),
('3', 'Ana Maria', 'Rua A, num 4', 'Aracaju', '5023', 'SE'),
('4', 'Joana Carla', 'Rua 6, 7', 'BH', '123', 'MG'),
('5', 'João Carlos', 'Av. Flor', 'BH', '12345', 'MG');

-- --------------------------------------------------------

--
-- Table structure for table `descontos`
--

CREATE TABLE `descontos` (
  `codigo_desconto` int NOT NULL,
  `codigo_empregado` int NOT NULL,
  `valor` decimal(10,2) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Dumping data for table `descontos`
--

INSERT INTO `descontos` (`codigo_desconto`, `codigo_empregado`, `valor`) VALUES
(1, 1, '50.00'),
(2, 2, '20.00'),
(3, 5, '30.00');

-- --------------------------------------------------------

--
-- Table structure for table `empregados`
--

CREATE TABLE `empregados` (
  `codigo_empregado` int DEFAULT NULL,
  `nome` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Dumping data for table `empregados`
--

INSERT INTO `empregados` (`codigo_empregado`, `nome`) VALUES
(1, 'Luis'),
(2, 'Marina'),
(3, 'Letícia'),
(4, 'Gustavo'),
(5, 'Mateus');

-- --------------------------------------------------------

--
-- Table structure for table `pagamentos`
--

CREATE TABLE `pagamentos` (
  `codigo_pagto` int NOT NULL,
  `codigo_empregado` int DEFAULT NULL,
  `valor` decimal(10,2) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Dumping data for table `pagamentos`
--

INSERT INTO `pagamentos` (`codigo_pagto`, `codigo_empregado`, `valor`) VALUES
(1, 1, '100.00'),
(2, 1, '200.00'),
(3, 3, '300.00'),
(44, 5, '400.00'),
(55, 5, '500.00');

-- --------------------------------------------------------

--
-- Table structure for table `produtos`
--

CREATE TABLE `produtos` (
  `ID` varchar(2) NOT NULL,
  `ProductName` varchar(11) DEFAULT NULL,
  `CategoriaID` varchar(11) DEFAULT NULL,
  `Quantidade` varchar(10) DEFAULT NULL,
  `Preco` varchar(5) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

--
-- Dumping data for table `produtos`
--

INSERT INTO `produtos` (`ID`, `ProductName`, `CategoriaID`, `Quantidade`, `Preco`) VALUES
('1', 'HD', '1', '12', '400'),
('2', 'PlacaMae', '1', '15', '1000'),
('3', 'Memória RAM', '2', '14', '500'),
('4', 'Papel A4', '3', '33', '40'),
('5', 'Canetas', '4', '44', '2'),
('6', 'Marcador', '4', '22', '3');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `clientes`
--
ALTER TABLE `clientes`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `descontos`
--
ALTER TABLE `descontos`
  ADD PRIMARY KEY (`codigo_desconto`);

--
-- Indexes for table `pagamentos`
--
ALTER TABLE `pagamentos`
  ADD PRIMARY KEY (`codigo_pagto`);

--
-- Indexes for table `produtos`
--
ALTER TABLE `produtos`
  ADD PRIMARY KEY (`ID`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
