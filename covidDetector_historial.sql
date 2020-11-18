CREATE DATABASE  IF NOT EXISTS `covidDetector` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci */ /*!80016 DEFAULT ENCRYPTION='N' */;
USE `covidDetector`;
-- MySQL dump 10.13  Distrib 8.0.21, for macos10.15 (x86_64)
--
-- Host: localhost    Database: covidDetector
-- ------------------------------------------------------
-- Server version	8.0.21

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `historial`
--

DROP TABLE IF EXISTS `historial`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `historial` (
  `idHistorial` int NOT NULL,
  `idPersona` int NOT NULL,
  `edadRiesgo` tinyint NOT NULL,
  `diabetes` tinyint NOT NULL,
  `hipertension` tinyint NOT NULL,
  `enfermedadesRespiratorias` varchar(120) NOT NULL,
  `fiebre` tinyint NOT NULL,
  `perdidaOlfato` tinyint NOT NULL,
  `dificultadRespiracion` tinyint NOT NULL,
  `enfermedadesGastro` varchar(120) NOT NULL,
  PRIMARY KEY (`idHistorial`),
  KEY `idPersona_historial_fk_idx` (`idPersona`),
  CONSTRAINT `idPersona_historial_fk` FOREIGN KEY (`idPersona`) REFERENCES `persona` (`idPersona`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `historial`
--

LOCK TABLES `historial` WRITE;
/*!40000 ALTER TABLE `historial` DISABLE KEYS */;
INSERT INTO `historial` VALUES (1,1,1,0,0,'Ninguna',1,1,0,'Ninguna'),(800011,800011,0,1,1,'Enfermedad pulmonar',1,1,1,'Náuseas'),(800012,800012,0,1,1,'Enfermedad pulmonar',1,1,1,'Náuseas'),(800013,800013,0,1,1,'Enfermedad pulmonar',1,1,1,'Náuseas'),(800014,800014,0,1,1,'Enfermedad pulmonar',1,1,1,'Náuseas'),(800015,800015,0,1,1,'Enfermedad pulmonar',1,1,1,'Náuseas'),(800016,800016,0,1,1,'Enfermedad pulmonar',1,1,1,'Náuseas'),(800017,800017,1,1,1,'Enfermedad pulmonar',1,1,1,'Náuseas'),(800018,800018,1,1,1,'Enfermedad pulmonar',1,1,1,'Náuseas'),(800019,800019,1,1,1,'Enfermedad pulmonar',1,1,1,'Náuseas'),(800020,800020,0,1,1,'Enfermedad pulmonar',1,1,1,'Náuseas'),(800021,800021,1,1,1,'Enfermedad pulmonar',1,1,1,'Náuseas'),(800022,800022,1,1,1,'Enfermedad pulmonar',1,1,1,'Náuseas'),(800023,800023,1,1,1,'Enfermedad pulmonar',1,1,1,'Náuseas'),(800024,800024,0,1,1,'Enfermedad pulmonar',1,1,1,'Náuseas');
/*!40000 ALTER TABLE `historial` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2020-11-17 17:33:29
