-- phpMyAdmin SQL Dump
-- version 4.6.5.2
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1
-- Tiempo de generación: 19-05-2017 a las 10:31:21
-- Versión del servidor: 10.1.21-MariaDB
-- Versión de PHP: 7.1.1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `proyectoweb`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `actividadbaloncesto`
--

CREATE TABLE `actividadbaloncesto` (
  `dia` int(5) UNSIGNED NOT NULL,
  `9:30 - 10:30` text NOT NULL,
  `10:30 - 11:30` text NOT NULL,
  `11:30 - 12:30` text NOT NULL,
  `12:30 - 13:30` text NOT NULL,
  `13:30 - 14:30` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `actividadbaloncesto`
--

INSERT INTO `actividadbaloncesto` (`dia`, `9:30 - 10:30`, `10:30 - 11:30`, `11:30 - 12:30`, `12:30 - 13:30`, `13:30 - 14:30`) VALUES
(1, 'Disponible', 'Ocupado', 'Ocupado', 'Ocupado', 'Disponible'),
(2, 'Ocupado', 'Ocupado', 'Ocupado', 'Ocupado', 'Disponible'),
(3, 'Ocupado', 'Ocupado', 'Ocupado', 'Ocupado', 'Disponible'),
(4, 'Ocupado', 'Disponible', 'Ocupado', 'Ocupado', 'Disponible'),
(5, 'Disponible', 'Disponible', 'Ocupado', 'Disponible', 'Disponible'),
(6, 'Ocupado', 'Ocupado', 'Ocupado', 'Disponible', 'Disponible'),
(7, 'Disponible', 'Disponible', 'Ocupado', 'Ocupado', 'Disponible'),
(8, 'Ocupado', 'Disponible', 'Ocupado', 'Ocupado', 'Disponible'),
(9, 'Disponible', 'Disponible', 'Ocupado', 'Disponible', 'Disponible'),
(10, 'Ocupado', 'Ocupado', 'Ocupado', 'Disponible', 'Disponible'),
(11, 'Disponible', 'Ocupado', 'Ocupado', 'Ocupado', 'Disponible'),
(12, 'Disponible', 'Disponible', 'Ocupado', 'Disponible', 'Disponible'),
(13, 'Disponible', 'Ocupado', 'Ocupado', 'Ocupado', 'Ocupado'),
(14, 'Ocupado', 'Ocupado', 'Ocupado', 'Ocupado', 'Disponible'),
(15, 'Disponible', 'Disponible', 'Ocupado', 'Ocupado', 'Disponible'),
(16, 'Ocupado', 'Ocupado', 'Ocupado', 'Disponible', 'Ocupado'),
(17, 'Ocupado', 'Ocupado', 'Ocupado', 'Ocupado', 'Disponible'),
(18, 'Ocupado', 'Disponible', 'Disponible', 'Ocupado', 'Disponible'),
(19, 'Disponible', 'Disponible', 'Disponible', 'Disponible', 'Disponible'),
(20, 'Disponible', 'Ocupado', 'Ocupado', 'Disponible', 'Disponible'),
(21, 'Disponible', 'Ocupado', 'Ocupado', 'Ocupado', 'Disponible'),
(22, 'Disponible', 'Disponible', 'Ocupado', 'Disponible', 'Disponible'),
(23, 'Ocupado', 'Ocupado', 'Disponible', 'Ocupado', 'Disponible'),
(24, 'Ocupado', 'Disponible', 'Ocupado', 'Ocupado', 'Disponible'),
(25, 'Ocupado', 'Disponible', 'Ocupado', 'Disponible', 'Ocupado'),
(26, 'Ocupado', 'Ocupado', 'Ocupado', 'Ocupado', 'Disponible'),
(27, 'Disponible', 'Disponible', 'Disponible', 'Ocupado', 'Disponible'),
(28, 'Disponible', 'Disponible', 'Ocupado', 'Ocupado', 'Disponible'),
(29, 'Disponible', 'Disponible', 'Disponible', 'Disponible', 'Ocupado'),
(30, 'Disponible', 'Disponible', 'Ocupado', 'Disponible', 'Disponible'),
(31, 'Disponible', 'Disponible', 'Ocupado', 'Disponible', 'Disponible');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `actividadfutbol`
--

CREATE TABLE `actividadfutbol` (
  `dia` int(5) UNSIGNED NOT NULL,
  `9:30 - 10:30` text NOT NULL,
  `10:30 - 11:30` text NOT NULL,
  `11:30 - 12:30` text NOT NULL,
  `12:30 - 13:30` text NOT NULL,
  `13:30 - 14:30` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `actividadfutbol`
--

INSERT INTO `actividadfutbol` (`dia`, `9:30 - 10:30`, `10:30 - 11:30`, `11:30 - 12:30`, `12:30 - 13:30`, `13:30 - 14:30`) VALUES
(1, 'Ocupado', 'Ocupado', 'Ocupado', 'Ocupado', 'Ocupado'),
(2, 'Ocupado', 'Ocupado', 'Ocupado', 'Ocupado', 'Ocupado'),
(3, 'Ocupado', 'Ocupado', 'Ocupado', 'Ocupado', 'Disponible'),
(4, 'Ocupado', 'Ocupado', 'Ocupado', 'Ocupado', 'Disponible'),
(5, 'Disponible', 'Ocupado', 'Disponible', 'Ocupado', 'Disponible'),
(6, 'Disponible', 'Disponible', 'Disponible', 'Ocupado', 'Ocupado'),
(7, 'Disponible', 'Disponible', 'Disponible', 'Ocupado', 'Disponible'),
(8, 'Ocupado', 'Ocupado', 'Ocupado', 'Ocupado', 'Ocupado'),
(9, 'Disponible', 'Disponible', 'Ocupado', 'Ocupado', 'Ocupado'),
(10, 'Ocupado', 'Disponible', 'Ocupado', 'Disponible', 'Ocupado'),
(11, 'Ocupado', 'Disponible', 'Ocupado', 'Disponible', 'Disponible'),
(12, 'Ocupado', 'Disponible', 'Disponible', 'Ocupado', 'Disponible'),
(13, 'Disponible', 'Disponible', 'Disponible', 'Ocupado', 'Disponible'),
(14, 'Disponible', 'Disponible', 'Ocupado', 'Ocupado', 'Disponible'),
(15, 'Disponible', 'Ocupado', 'Ocupado', 'Ocupado', 'Disponible'),
(16, 'Ocupado', 'Ocupado', 'Ocupado', 'Ocupado', 'Disponible'),
(17, 'Ocupado', 'Ocupado', 'Ocupado', 'Ocupado', 'Ocupado'),
(18, 'Ocupado', 'Ocupado', 'Ocupado', 'Ocupado', 'Ocupado'),
(19, 'Ocupado', 'Disponible', 'Ocupado', 'Ocupado', 'Disponible'),
(20, 'Disponible', 'Disponible', 'Disponible', 'Ocupado', 'Ocupado'),
(21, 'Disponible', 'Disponible', 'Disponible', 'Disponible', 'Disponible'),
(22, 'Disponible', 'Ocupado', 'Ocupado', 'Ocupado', 'Ocupado'),
(23, 'Disponible', 'Disponible', 'Disponible', 'Ocupado', 'Ocupado'),
(24, 'Disponible', 'Ocupado', 'Ocupado', 'Ocupado', 'Disponible'),
(25, 'Disponible', 'Disponible', 'Ocupado', 'Disponible', 'Disponible'),
(26, 'Ocupado', 'Ocupado', 'Ocupado', 'Ocupado', 'Disponible'),
(27, 'Ocupado', 'Disponible', 'Ocupado', 'Ocupado', 'Ocupado'),
(28, 'Ocupado', 'Ocupado', 'Ocupado', 'Ocupado', 'Disponible'),
(29, 'Disponible', 'Disponible', 'Ocupado', 'Ocupado', 'Disponible'),
(30, 'Disponible', 'Disponible', 'Disponible', 'Ocupado', 'Ocupado'),
(31, 'Disponible', 'Disponible', 'Disponible', 'Ocupado', 'Ocupado');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `actividadpadel`
--

CREATE TABLE `actividadpadel` (
  `dia` int(5) UNSIGNED NOT NULL,
  `9:30 - 10:30` text NOT NULL,
  `10:30 - 11:30` text NOT NULL,
  `11:30 - 12:30` text NOT NULL,
  `12:30 - 13:30` text NOT NULL,
  `13:30 - 14:30` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `actividadpadel`
--

INSERT INTO `actividadpadel` (`dia`, `9:30 - 10:30`, `10:30 - 11:30`, `11:30 - 12:30`, `12:30 - 13:30`, `13:30 - 14:30`) VALUES
(1, 'Ocupado', 'Ocupado', 'Ocupado', 'Ocupado', 'Ocupado'),
(2, 'Ocupado', 'Ocupado', 'Disponible', 'Ocupado', 'Ocupado'),
(3, 'Ocupado', 'Ocupado', 'Disponible', 'Ocupado', 'Disponible'),
(4, 'Disponible', 'Ocupado', 'Ocupado', 'Ocupado', 'Disponible'),
(5, 'Disponible', 'Ocupado', 'Disponible', 'Ocupado', 'Disponible'),
(6, 'Disponible', 'Disponible', 'Disponible', 'Ocupado', 'Ocupado'),
(7, 'Disponible', 'Disponible', 'Disponible', 'Ocupado', 'Disponible'),
(8, 'Ocupado', 'Ocupado', 'Ocupado', 'Ocupado', 'Ocupado'),
(9, 'Disponible', 'Ocupado', 'Ocupado', 'Ocupado', 'Ocupado'),
(10, 'Ocupado', 'Disponible', 'Ocupado', 'Disponible', 'Ocupado'),
(11, 'Disponible', 'Disponible', 'Ocupado', 'Disponible', 'Disponible'),
(12, 'Ocupado', 'Disponible', 'Disponible', 'Ocupado', 'Disponible'),
(13, 'Disponible', 'Disponible', 'Disponible', 'Ocupado', 'Disponible'),
(14, 'Disponible', 'Disponible', 'Ocupado', 'Ocupado', 'Disponible'),
(15, 'Disponible', 'Ocupado', 'Ocupado', 'Ocupado', 'Disponible'),
(16, 'Ocupado', 'Ocupado', 'Ocupado', 'Ocupado', 'Ocupado'),
(17, 'Ocupado', 'Disponible', 'Ocupado', 'Ocupado', 'Ocupado'),
(18, 'Ocupado', 'Ocupado', 'Disponible', 'Ocupado', 'Ocupado'),
(19, 'Ocupado', 'Disponible', 'Ocupado', 'Ocupado', 'Disponible'),
(20, 'Disponible', 'Disponible', 'Disponible', 'Ocupado', 'Ocupado'),
(21, 'Disponible', 'Disponible', 'Disponible', 'Disponible', 'Disponible'),
(22, 'Disponible', 'Ocupado', 'Ocupado', 'Ocupado', 'Ocupado'),
(23, 'Disponible', 'Disponible', 'Disponible', 'Ocupado', 'Ocupado'),
(24, 'Disponible', 'Ocupado', 'Ocupado', 'Ocupado', 'Disponible'),
(25, 'Disponible', 'Disponible', 'Ocupado', 'Disponible', 'Disponible'),
(26, 'Disponible', 'Ocupado', 'Ocupado', 'Ocupado', 'Disponible'),
(27, 'Ocupado', 'Disponible', 'Ocupado', 'Ocupado', 'Ocupado'),
(28, 'Ocupado', 'Ocupado', 'Ocupado', 'Ocupado', 'Disponible'),
(29, 'Disponible', 'Disponible', 'Ocupado', 'Ocupado', 'Disponible'),
(30, 'Disponible', 'Disponible', 'Disponible', 'Ocupado', 'Ocupado'),
(31, 'Disponible', 'Disponible', 'Disponible', 'Ocupado', 'Ocupado');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `actividadtenis`
--

CREATE TABLE `actividadtenis` (
  `dia` int(5) UNSIGNED NOT NULL,
  `9:30 - 10:30` text NOT NULL,
  `10:30 - 11:30` text NOT NULL,
  `11:30 - 12:30` text NOT NULL,
  `12:30 - 13:30` text NOT NULL,
  `13:30 - 14:30` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `actividadtenis`
--

INSERT INTO `actividadtenis` (`dia`, `9:30 - 10:30`, `10:30 - 11:30`, `11:30 - 12:30`, `12:30 - 13:30`, `13:30 - 14:30`) VALUES
(1, 'Ocupado', 'Ocupado', 'Ocupado', 'Ocupado', 'Disponible'),
(2, 'Ocupado', 'Ocupado', 'Ocupado', 'Ocupado', 'Ocupado'),
(3, 'Ocupado', 'Ocupado', 'Ocupado', 'Ocupado', 'Ocupado'),
(4, 'Disponible', 'Disponible', 'Ocupado', 'Ocupado', 'Disponible'),
(5, 'Disponible', 'Disponible', 'Ocupado', 'Disponible', 'Disponible'),
(6, 'Ocupado', 'Ocupado', 'Ocupado', 'Disponible', 'Disponible'),
(7, 'Disponible', 'Disponible', 'Ocupado', 'Ocupado', 'Disponible'),
(8, 'Ocupado', 'Disponible', 'Ocupado', 'Ocupado', 'Disponible'),
(9, 'Disponible', 'Ocupado', 'Disponible', 'Disponible', 'Disponible'),
(10, 'Ocupado', 'Ocupado', 'Ocupado', 'Disponible', 'Disponible'),
(11, 'Disponible', 'Ocupado', 'Ocupado', 'Ocupado', 'Disponible'),
(12, 'Disponible', 'Disponible', 'Ocupado', 'Disponible', 'Disponible'),
(13, 'Disponible', 'Ocupado', 'Ocupado', 'Ocupado', 'Ocupado'),
(14, 'Ocupado', 'Ocupado', 'Ocupado', 'Ocupado', 'Disponible'),
(15, 'Disponible', 'Disponible', 'Ocupado', 'Ocupado', 'Disponible'),
(16, 'Ocupado', 'Ocupado', 'Ocupado', 'Disponible', 'Ocupado'),
(17, 'Disponible', 'Ocupado', 'Ocupado', 'Ocupado', 'Disponible'),
(18, 'Ocupado', 'Disponible', 'Disponible', 'Ocupado', 'Disponible'),
(19, 'Disponible', 'Disponible', 'Disponible', 'Disponible', 'Disponible'),
(20, 'Disponible', 'Ocupado', 'Ocupado', 'Disponible', 'Disponible'),
(21, 'Disponible', 'Ocupado', 'Ocupado', 'Ocupado', 'Disponible'),
(22, 'Disponible', 'Disponible', 'Ocupado', 'Disponible', 'Disponible'),
(23, 'Ocupado', 'Ocupado', 'Disponible', 'Ocupado', 'Disponible'),
(24, 'Ocupado', 'Disponible', 'Ocupado', 'Ocupado', 'Disponible'),
(25, 'Ocupado', 'Disponible', 'Ocupado', 'Disponible', 'Ocupado'),
(26, 'Ocupado', 'Ocupado', 'Ocupado', 'Ocupado', 'Disponible'),
(27, 'Disponible', 'Disponible', 'Disponible', 'Ocupado', 'Disponible'),
(28, 'Disponible', 'Disponible', 'Ocupado', 'Ocupado', 'Disponible'),
(29, 'Disponible', 'Disponible', 'Disponible', 'Disponible', 'Ocupado'),
(30, 'Disponible', 'Disponible', 'Ocupado', 'Disponible', 'Disponible'),
(31, 'Disponible', 'Disponible', 'Ocupado', 'Disponible', 'Disponible');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `materialbaloncesto`
--

CREATE TABLE `materialbaloncesto` (
  `num` int(5) UNSIGNED NOT NULL,
  `dia` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `materialbaloncesto`
--

INSERT INTO `materialbaloncesto` (`num`, `dia`) VALUES
(1, 'Disponible'),
(2, 'Disponible'),
(3, 'Disponible'),
(4, 'Disponible'),
(5, 'Ocupado'),
(6, 'Ocupado'),
(7, 'Ocupado'),
(8, 'Ocupado'),
(9, 'Ocupado'),
(10, 'Ocupado'),
(11, 'Ocupado'),
(12, 'Disponible'),
(13, 'Disponible'),
(14, 'Disponible'),
(15, 'Disponible'),
(16, 'Disponible'),
(17, 'Disponible'),
(18, 'Disponible'),
(19, 'Disponible'),
(20, 'Ocupado'),
(21, 'Ocupado'),
(22, 'Disponible'),
(23, 'Disponible'),
(24, 'Disponible'),
(25, 'Ocupado'),
(26, 'Ocupado'),
(27, 'Ocupado'),
(28, 'Ocupado'),
(29, 'Disponible'),
(30, 'Disponible'),
(31, 'Disponible');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `materialfutbol`
--

CREATE TABLE `materialfutbol` (
  `num` int(5) UNSIGNED NOT NULL,
  `dia` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `materialfutbol`
--

INSERT INTO `materialfutbol` (`num`, `dia`) VALUES
(1, 'Ocupado'),
(2, 'Ocupado'),
(3, 'Ocupado'),
(4, 'Ocupado'),
(5, 'Ocupado'),
(6, 'Ocupado'),
(7, 'Ocupado'),
(8, 'Ocupado'),
(9, 'Ocupado'),
(10, 'Disponible'),
(11, 'Disponible'),
(12, 'Disponible'),
(13, 'Disponible'),
(14, 'Disponible'),
(15, 'Disponible'),
(16, 'Ocupado'),
(17, 'Ocupado'),
(18, 'Ocupado'),
(19, 'Ocupado'),
(20, 'Ocupado'),
(21, 'Disponible'),
(22, 'Ocupado'),
(23, 'Ocupado'),
(24, 'Ocupado'),
(25, 'Disponible'),
(26, 'Disponible'),
(27, 'Disponible'),
(28, 'Disponible'),
(29, 'Disponible'),
(30, 'Disponible'),
(31, 'Disponible');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `materialpadel`
--

CREATE TABLE `materialpadel` (
  `num` int(5) UNSIGNED NOT NULL,
  `dia` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `materialpadel`
--

INSERT INTO `materialpadel` (`num`, `dia`) VALUES
(1, 'Disponible'),
(2, 'Disponible'),
(3, 'Disponible'),
(4, 'Disponible'),
(5, 'Ocupado'),
(6, 'Ocupado'),
(7, 'Ocupado'),
(8, 'Ocupado'),
(9, 'Ocupado'),
(10, 'Ocupado'),
(11, 'Ocupado'),
(12, 'Disponible'),
(13, 'Disponible'),
(14, 'Disponible'),
(15, 'Disponible'),
(16, 'Disponible'),
(17, 'Disponible'),
(18, 'Disponible'),
(19, 'Disponible'),
(20, 'Ocupado'),
(21, 'Ocupado'),
(22, 'Disponible'),
(23, 'Disponible'),
(24, 'Ocupado'),
(25, 'Ocupado'),
(26, 'Ocupado'),
(27, 'Ocupado'),
(28, 'Ocupado'),
(29, 'Disponible'),
(30, 'Disponible'),
(31, 'Disponible');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `materialtenis`
--

CREATE TABLE `materialtenis` (
  `num` int(5) UNSIGNED NOT NULL,
  `dia` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `materialtenis`
--

INSERT INTO `materialtenis` (`num`, `dia`) VALUES
(1, 'Ocupado'),
(2, 'Ocupado'),
(3, 'Disponible'),
(4, 'Disponible'),
(5, 'Disponible'),
(6, 'Ocupado'),
(7, 'Ocupado'),
(8, 'Ocupado'),
(9, 'Disponible'),
(10, 'Disponible'),
(11, 'Ocupado'),
(12, 'Disponible'),
(13, 'Disponible'),
(14, 'Disponible'),
(15, 'Disponible'),
(16, 'Ocupado'),
(17, 'Ocupado'),
(18, 'Ocupado'),
(19, 'Ocupado'),
(20, 'Ocupado'),
(21, 'Disponible'),
(22, 'Ocupado'),
(23, 'Ocupado'),
(24, 'Ocupado'),
(25, 'Disponible'),
(26, 'Disponible'),
(27, 'Disponible'),
(28, 'Disponible'),
(29, 'Disponible'),
(30, 'Disponible'),
(31, 'Disponible');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `usuarios`
--

CREATE TABLE `usuarios` (
  `Id` int(11) NOT NULL,
  `Usuario` varchar(50) NOT NULL,
  `Password` varchar(50) NOT NULL,
  `Nombre` varchar(50) NOT NULL,
  `Edad` int(50) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `usuarios`
--

INSERT INTO `usuarios` (`Id`, `Usuario`, `Password`, `Nombre`, `Edad`) VALUES
(1, 'jose@gmail.com', '123', 'Jose', 22);

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `actividadbaloncesto`
--
ALTER TABLE `actividadbaloncesto`
  ADD PRIMARY KEY (`dia`);

--
-- Indices de la tabla `actividadfutbol`
--
ALTER TABLE `actividadfutbol`
  ADD PRIMARY KEY (`dia`);

--
-- Indices de la tabla `actividadpadel`
--
ALTER TABLE `actividadpadel`
  ADD PRIMARY KEY (`dia`);

--
-- Indices de la tabla `actividadtenis`
--
ALTER TABLE `actividadtenis`
  ADD PRIMARY KEY (`dia`);

--
-- Indices de la tabla `materialbaloncesto`
--
ALTER TABLE `materialbaloncesto`
  ADD PRIMARY KEY (`num`);

--
-- Indices de la tabla `materialfutbol`
--
ALTER TABLE `materialfutbol`
  ADD PRIMARY KEY (`num`);

--
-- Indices de la tabla `materialpadel`
--
ALTER TABLE `materialpadel`
  ADD PRIMARY KEY (`num`);

--
-- Indices de la tabla `materialtenis`
--
ALTER TABLE `materialtenis`
  ADD PRIMARY KEY (`num`);

--
-- Indices de la tabla `usuarios`
--
ALTER TABLE `usuarios`
  ADD PRIMARY KEY (`Id`);

--
-- AUTO_INCREMENT de las tablas volcadas
--

--
-- AUTO_INCREMENT de la tabla `actividadbaloncesto`
--
ALTER TABLE `actividadbaloncesto`
  MODIFY `dia` int(5) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=32;
--
-- AUTO_INCREMENT de la tabla `actividadfutbol`
--
ALTER TABLE `actividadfutbol`
  MODIFY `dia` int(5) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=32;
--
-- AUTO_INCREMENT de la tabla `actividadpadel`
--
ALTER TABLE `actividadpadel`
  MODIFY `dia` int(5) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=32;
--
-- AUTO_INCREMENT de la tabla `actividadtenis`
--
ALTER TABLE `actividadtenis`
  MODIFY `dia` int(5) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=32;
--
-- AUTO_INCREMENT de la tabla `materialbaloncesto`
--
ALTER TABLE `materialbaloncesto`
  MODIFY `num` int(5) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=32;
--
-- AUTO_INCREMENT de la tabla `materialfutbol`
--
ALTER TABLE `materialfutbol`
  MODIFY `num` int(5) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=32;
--
-- AUTO_INCREMENT de la tabla `materialpadel`
--
ALTER TABLE `materialpadel`
  MODIFY `num` int(5) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=32;
--
-- AUTO_INCREMENT de la tabla `materialtenis`
--
ALTER TABLE `materialtenis`
  MODIFY `num` int(5) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=32;
--
-- AUTO_INCREMENT de la tabla `usuarios`
--
ALTER TABLE `usuarios`
  MODIFY `Id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
