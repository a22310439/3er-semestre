-- MariaDB dump 10.19  Distrib 10.4.28-MariaDB, for Win64 (AMD64)
--
-- Host: localhost    Database: salon_eventos
-- ------------------------------------------------------
-- Server version	10.4.28-MariaDB

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `animador`
--

DROP TABLE IF EXISTS `animador`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `animador` (
  `codigo` int(11) NOT NULL AUTO_INCREMENT,
  `nombre` varchar(60) DEFAULT NULL,
  PRIMARY KEY (`codigo`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `animador`
--

LOCK TABLES `animador` WRITE;
/*!40000 ALTER TABLE `animador` DISABLE KEYS */;
INSERT INTO `animador` VALUES (1,'Omar Flores'),(2,'Osiris Carrillo'),(3,'Karen Mora');
/*!40000 ALTER TABLE `animador` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `clientes`
--

DROP TABLE IF EXISTS `clientes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `clientes` (
  `num_cliente` int(11) NOT NULL AUTO_INCREMENT,
  `nombre` varchar(20) DEFAULT NULL,
  `apellido` varchar(20) DEFAULT NULL,
  `domicilio` varchar(100) DEFAULT NULL,
  `telefono` int(10) DEFAULT NULL,
  PRIMARY KEY (`num_cliente`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `clientes`
--

LOCK TABLES `clientes` WRITE;
/*!40000 ALTER TABLE `clientes` DISABLE KEYS */;
INSERT INTO `clientes` VALUES (2,'Juan','Perez','Av. Providencia #2586',2147483647),(3,'Luis','Vazquez','Calle Rio Tomatlan #738',2147483647),(4,'Pedro','Castillo','Calle Perla #2345',2147483647);
/*!40000 ALTER TABLE `clientes` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `disfraz`
--

DROP TABLE IF EXISTS `disfraz`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `disfraz` (
  `codigo` int(11) NOT NULL AUTO_INCREMENT,
  `personaje` varchar(15) DEFAULT NULL,
  `precio` int(6) DEFAULT NULL,
  PRIMARY KEY (`codigo`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `disfraz`
--

LOCK TABLES `disfraz` WRITE;
/*!40000 ALTER TABLE `disfraz` DISABLE KEYS */;
INSERT INTO `disfraz` VALUES (1,'La Sirenita',3500),(2,'Buzz Lightyear',2000),(3,'Iron Man',5300);
/*!40000 ALTER TABLE `disfraz` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `eventos`
--

DROP TABLE IF EXISTS `eventos`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `eventos` (
  `codigo` int(11) NOT NULL AUTO_INCREMENT,
  `domicilio` varchar(100) DEFAULT NULL,
  `descripcion` varchar(120) DEFAULT NULL,
  `valor_base` int(5) DEFAULT NULL,
  `valor_real` int(6) DEFAULT NULL,
  `horario` varchar(13) DEFAULT NULL,
  `forma_pago` varchar(19) DEFAULT NULL,
  PRIMARY KEY (`codigo`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `eventos`
--

LOCK TABLES `eventos` WRITE;
/*!40000 ALTER TABLE `eventos` DISABLE KEYS */;
INSERT INTO `eventos` VALUES (1,'Calle Azaleas #3710','Techado con amplio espacio para muchas mesas, cuenta con alberca',15000,19500,'15:00 - 23:59','tarjeta de credito'),(2,'Av. Conchita #3241','Espacio amplio techado con jardin',6000,8600,'13:00 - 20:00','tarjeta de debito'),(3,'Calle Helios #1107','Espacio abierto con jardin, incluye un brincolin para fiestas infantiles',8000,10600,'15:00 - 20:00','tarjeta de credito');
/*!40000 ALTER TABLE `eventos` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `presentador`
--

DROP TABLE IF EXISTS `presentador`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `presentador` (
  `codigo` int(11) NOT NULL AUTO_INCREMENT,
  `nombre` varchar(60) DEFAULT NULL,
  `antiguedad` varchar(10) DEFAULT NULL,
  PRIMARY KEY (`codigo`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `presentador`
--

LOCK TABLES `presentador` WRITE;
/*!40000 ALTER TABLE `presentador` DISABLE KEYS */;
INSERT INTO `presentador` VALUES (1,'Jorge Zandoval','2 a?os'),(2,'Ana De La Mora','5 a?os'),(3,'Luis Gonzalez','11 meses');
/*!40000 ALTER TABLE `presentador` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2024-04-19  2:19:14
