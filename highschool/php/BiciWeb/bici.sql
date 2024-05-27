-- MariaDB dump 10.19  Distrib 10.4.18-MariaDB, for Linux (x86_64)
--
-- Host: localhost    Database: bici
-- ------------------------------------------------------
-- Server version	10.4.18-MariaDB

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
-- Table structure for table `amministratori`
--

DROP TABLE IF EXISTS `amministratori`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `amministratori` (
  `user_id` int(11) NOT NULL,
  `password` char(255) NOT NULL,
  PRIMARY KEY (`user_id`),
  CONSTRAINT `amministratori_ibfk_1` FOREIGN KEY (`user_id`) REFERENCES `utenti` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `amministratori`
--

LOCK TABLES `amministratori` WRITE;
/*!40000 ALTER TABLE `amministratori` DISABLE KEYS */;
INSERT INTO `amministratori` VALUES (34,'d247d639bb24497742a70df7cfe235be35b463ec4e6924f8d04608ac276eb606');
/*!40000 ALTER TABLE `amministratori` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `biciclette`
--

DROP TABLE IF EXISTS `biciclette`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `biciclette` (
  `id` int(11) NOT NULL,
  `modello` varchar(64) NOT NULL,
  `annoProd` int(4) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `biciclette`
--

LOCK TABLES `biciclette` WRITE;
/*!40000 ALTER TABLE `biciclette` DISABLE KEYS */;
INSERT INTO `biciclette` VALUES (1,'City Bike - FIXIE Inc. Betty Leeds, black',2020),(2,'City Bike - FIXIE Inc. Betty Leeds, black',2020),(3,'City Bike - Serious Rockville 20\" Bambino, black/green',2019),(4,'City Bike - Serious Rockville 20\" Bambino, black/green',2019),(5,'Electric Bike - Ortler Montreux 6100 Intube Trapeze',2021);
/*!40000 ALTER TABLE `biciclette` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `noleggi`
--

DROP TABLE IF EXISTS `noleggi`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `noleggi` (
  `id` int(11) NOT NULL,
  `data_inizio` date NOT NULL,
  `data_fine` date DEFAULT NULL,
  `costo` smallint(6) DEFAULT NULL,
  `id_utente` int(11) NOT NULL,
  `id_bicicletta` int(11) NOT NULL,
  `id_stazione_partenza` int(11) NOT NULL,
  `id_stazione_arrivo` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `bici` (`id_bicicletta`),
  KEY `ut` (`id_utente`),
  KEY `par` (`id_stazione_partenza`),
  KEY `arr` (`id_stazione_arrivo`),
  CONSTRAINT `arrivo` FOREIGN KEY (`id_stazione_arrivo`) REFERENCES `stazioni` (`id`),
  CONSTRAINT `bici` FOREIGN KEY (`id_bicicletta`) REFERENCES `biciclette` (`id`),
  CONSTRAINT `partenza` FOREIGN KEY (`id_stazione_partenza`) REFERENCES `stazioni` (`id`),
  CONSTRAINT `ut` FOREIGN KEY (`id_utente`) REFERENCES `utenti` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `noleggi`
--

LOCK TABLES `noleggi` WRITE;
/*!40000 ALTER TABLE `noleggi` DISABLE KEYS */;
INSERT INTO `noleggi` VALUES (1,'2021-02-09','2021-02-11',35,34,2,1,3),(2,'2021-03-01',NULL,NULL,234,5,2,NULL);
/*!40000 ALTER TABLE `noleggi` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `slot`
--

DROP TABLE IF EXISTS `slot`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `slot` (
  `id` int(11) NOT NULL,
  `stato` set('libero','occupato') NOT NULL,
  `id_bicicletta` int(11) DEFAULT NULL,
  `id_stazione` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `st` (`id_stazione`),
  KEY `bic` (`id_bicicletta`),
  CONSTRAINT `bic` FOREIGN KEY (`id_bicicletta`) REFERENCES `biciclette` (`id`),
  CONSTRAINT `st0` FOREIGN KEY (`id_stazione`) REFERENCES `stazioni` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `slot`
--

LOCK TABLES `slot` WRITE;
/*!40000 ALTER TABLE `slot` DISABLE KEYS */;
INSERT INTO `slot` VALUES (1,'libero',NULL,1),(4,'occupato',1,2),(5,'occupato',3,2),(6,'occupato',4,3),(7,'occupato',2,3);
/*!40000 ALTER TABLE `slot` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `stazioni`
--

DROP TABLE IF EXISTS `stazioni`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `stazioni` (
  `id` int(11) NOT NULL,
  `indirizzo` varchar(128) NOT NULL,
  `cap` varchar(5) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `stazioni`
--

LOCK TABLES `stazioni` WRITE;
/*!40000 ALTER TABLE `stazioni` DISABLE KEYS */;
INSERT INTO `stazioni` VALUES (1,'Via della stazione, 41','45685'),(2,'Via della vittoria, 23','45685'),(3,'Viale trionfale, 78','45685');
/*!40000 ALTER TABLE `stazioni` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `utenti`
--

DROP TABLE IF EXISTS `utenti`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `utenti` (
  `id` int(11) NOT NULL,
  `nome` varchar(64) NOT NULL,
  `cognome` varchar(64) NOT NULL,
  `cap` varchar(5) NOT NULL,
  `indirizzo` varchar(128) NOT NULL,
  `num_carta_credito` varchar(16) NOT NULL,
  `cellulare` varchar(11) NOT NULL,
  `mail` varchar(64) NOT NULL,
  `data_nascita` date NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `utenti`
--

LOCK TABLES `utenti` WRITE;
/*!40000 ALTER TABLE `utenti` DISABLE KEYS */;
INSERT INTO `utenti` VALUES (34,'Giacomo','Canton','36100','Via Rossi, 36','15641644','1146646565','mail@dominio.com','2001-05-08'),(234,'Luca','Piano','36057','Via Sole, 38','152351644','11434236565','mail@nuovodominio.it','1988-05-08');
/*!40000 ALTER TABLE `utenti` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2021-04-13 18:01:50
