create database torneo;

use torneo;

create table grupos(
  idGrupo int ,
  nombre varchar(50),
  primary key(idGrupo)
);

create table sedes(
   idSede int,
   nombre varchar(60),
   estado varchar(60),
   primary key(idSede)
);

create table equipos(
   idEquipo int,
   nombre varchar(60),
   logo varchar(60),
   idSede int,
   idGrupo int,
   primary key(idEquipo),
   foreign key(idSede) references sedes(idSede),
   foreign key(idGrupo) references grupos(idGrupo)
);

create table jugadores(
   idJugador int,
   idEquipo int,
   nombre varchar(60),
   numero int,
   goles int,
   primary key(idJugador),
   foreign key(idEquipo) references equipos(idEquipo)
);

create table fechas(
  idFecha int,
  fecha date,
  primary key(idFecha)
);

create table partido(
  idPartido int,
  idFecha int,
  idEquipoLocal int,
  idEquipoVisitante int,
  marcadorLocal int,
  marcadorVisitante int,
  hora time,
  idSede int,
  primary key(idPartido),
  foreign key(idFecha) references fechas(idFecha),
  foreign key(idEquipoLocal) references equipos(idEquipo),
  foreign key(idEquipoVisitante) references equipos(idEquipo),
  foreign key(idSede) references sedes(idSede)
);

insert into grupos (idGrupo, nombre) values 
  (1,'1'), 
  (2,'2'), 
  (3,'3'), 
  (4,'4');

insert into sedes (idSede, nombre, estado) 
  values (1, 'Jalisco', 'Jalisco'),
         (2, 'Omnilife', 'Jalisco'),
         (3, 'America', 'CDMX');

insert into equipos (idEquipo, nombre, logo, idSede, idGrupo) values 
  (1, 'Atlas', 'atlas.jpg', 1,1),
  (2, 'Chivas', 'chivas.jpg', 2,2),
  (3, 'America', 'america.jpg', 3,3)
  ;

insert into jugadores (idJugador, idEquipo, nombre, numero, goles) values
  (1,1,"Jugador Atlas 1", 1,1),
  (2,2,"Jugador Chivas 1", 2,2),
  (3,1,"Jugador Atlas 2", 1,1),
  (4,2,"Jugador Chivas 2", 2,0),
  (5,1,"Jugador Atlas 3", 1,0)
;