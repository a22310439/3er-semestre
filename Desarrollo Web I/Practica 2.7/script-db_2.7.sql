drop database if exists biblio;
CREATE DATABASE biblio;
USE biblio;
drop table if exists biblio;
CREATE TABLE `libros` (
`id` int(11) NOT NULL auto_increment,
`isbn` int(11) DEFAULT NULL,
`titulo` varchar(50) DEFAULT NULL,
`autor` varchar(50) DEFAULT NULL,
`disponible` tinyint(4) DEFAULT NULL,
PRIMARY KEY (`id`)
) ;
drop table if exists usuarios;
CREATE TABLE `usuarios` (
`clave` int(11) NOT NULL auto_increment,
`nombre` varchar(60) DEFAULT NULL,
`dir` varchar(60) DEFAULT NULL,
`telefono` varchar(15) DEFAULT NULL,
PRIMARY KEY (`clave`)
);

CREATE TABLE `prestamos` (
`id` int(11) NOT NULL auto_increment,
`claveLibro` int(11) DEFAULT NULL,
`claveUsuario` int(11) DEFAULT NULL,
`fechaPrestamo` date DEFAULT NULL,
`fechaEntrega` date DEFAULT NULL,
`recargos` float DEFAULT NULL,
PRIMARY KEY (`id`),
FOREIGN KEY (`claveLibro`)
REFERENCES `libros` (`id`)
ON DELETE NO ACTION
ON UPDATE NO ACTION,
FOREIGN KEY (`claveUsuario`)
REFERENCES `usuarios` (`clave`)
ON DELETE CASCADE
ON UPDATE CASCADE
);
insert into libros (id, isbn, titulo, autor, disponible)
values (1, 333, 'Programacion en java', 'Luis Joyanes' ,
1),
(2, 444, 'Java en 21 Días', 'Deitel & deitel',1),
(3, 555, 'C# en 21 Días', 'Deitel & deitel',1),
(4, 666, 'Aprenda a programar en 21 Días',
'Joyanes',1 );
insert into usuarios (clave, nombre, dir, telefono)
values (1, 'Oscar Perez', 'Conocida', '2222'),
(2, 'Juan Perez', 'Conocida', '555');