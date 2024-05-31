drop database if exists db;

create database db;

use db;

CREATE TABLE productos (
    id INT(11) NOT NULL,
    nombre VARCHAR(60) DEFAULT NULL,
    existencia INT(11) DEFAULT NULL,
    stockMinimo INT(11) DEFAULT NULL,
    stockMaximo INT(11) DEFAULT NULL,
    PRIMARY KEY (id)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

CREATE TABLE pedidos (
    id INT(11) NOT NULL AUTO_INCREMENT,
    idProducto INT(11) DEFAULT NULL,
    cantidadPedir INT(11) DEFAULT NULL,
    PRIMARY KEY (id)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=latin1;

DELIMITER //

CREATE TRIGGER trigger_pedido_stock
AFTER UPDATE ON productos
FOR EACH ROW
BEGIN
    IF NEW.existencia < NEW.stockMinimo THEN
        INSERT INTO pedidos (idProducto, cantidadPedir) 
        VALUES (NEW.id, NEW.stockMaximo - NEW.existencia);
    END IF;
END;
//

DELIMITER ;
