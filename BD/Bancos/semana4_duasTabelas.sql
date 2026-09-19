-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Generation Time: Aug 22, 2026 at 12:18 AM
-- Server version: 8.0.46-0ubuntu0.22.04.3
-- PHP Version: 8.4.13

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `semana4`
--

CREATE DATABASE IF NOT EXISTS semana4;
use semana4

-- --------------------------------------------------------

--
-- Table structure for table `clientes`
--

CREATE TABLE `clientes` (
  `ID` int NOT NULL,
  `Nome` varchar(30) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `Endereco` varchar(30) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `Cidade` varchar(30) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `CEP` varchar(6) NOT NULL,
  `Estado` varchar(2) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Dumping data for table `clientes`
--

INSERT INTO `clientes` (`ID`, `Nome`, `Endereco`, `Cidade`, `CEP`, `Estado`) VALUES
(1, 'Jose Maria', 'Rua 1, num 2', 'Betim', '12209', 'MG'),
(2, 'Maria Jose', 'Rua 2, num 33', 'Maceio', '5021', 'AL'),
(3, 'Ana Maria  ', 'Rua A, num 4', 'Aracaju ', '5023', 'SE'),
(4, 'Joana Carla', 'Rua 6, 7 ', 'BH', '123', 'MG'),
(5, 'Joao Carlos', ' Av. Flor', 'BH', '12345', 'MG');

-- --------------------------------------------------------

--
-- Table structure for table `produtos`
--

CREATE TABLE `produtos` (
  `ID` int NOT NULL,
  `ProductName` varchar(11) DEFAULT NULL,
  `CategoriaID` int DEFAULT NULL,
  `Quantidade` int DEFAULT NULL,
  `Preco` int DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

--
-- Dumping data for table `produtos`
--

INSERT INTO `produtos` (`ID`, `ProductName`, `CategoriaID`, `Quantidade`, `Preco`) VALUES
(1, 'HD', 1, 12, 400),
(2, 'PlacaMae', 1, 15, 1000),
(3, 'Memoria RAM', 2, 14, 500),
(4, 'Papel A4', 3, 33, 40),
(5, 'Canetas', 4, 44, 2),
(6, 'Marcador', 4, 22, 3);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `clientes`
--
ALTER TABLE `clientes`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `produtos`
--
ALTER TABLE `produtos`
  ADD PRIMARY KEY (`ID`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `clientes`
--
ALTER TABLE `clientes`
  MODIFY `ID` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
