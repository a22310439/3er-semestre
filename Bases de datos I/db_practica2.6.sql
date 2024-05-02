drop database if exists facturacion;

create database facturacion;

use facturacion;

create table if not exists categorias (
id int primary key auto_increment,
nombre varchar(60)
);
create table if not exists productos (
id int not null auto_increment,
nombre varchar(60) null default null,
precio decimal(10,0) null default null,
unidadMedida varchar(60) null default null,
id_categoria int,
stock int,
stock_min int,
descuento int,
foreign key(id_categoria) references categorias(id),
primary key (id)
);

create table if not exists modo_pago(
id int primary key,
nombre varchar(60),
detalles varchar (60)
);

create table if not exists clientes(
id int not null default '0',
nombre varchar(60) null default null,
direccion varchar(60) null default null,
rfc varchar(15) null default null,
modo_pago int,
primary key (id),
foreign key (modo_pago) references modo_pago(id)
);

create table if not exists facturas(
id int not null auto_increment,
fecha date null default null,
id_cliente int null default null,
subtotal decimal(10,0) null default null,
notas varchar(60) default null,
foreign key (id_cliente) references clientes(id)
on delete cascade,
primary key (id)
);

create table if not exists detalle_fac(
id int not null auto_increment,
id_factura int null default null,
id_producto int null default null,
cantidad int null default null,
foreign key (id_factura) references facturas(id)
on delete cascade,
foreign key (id_producto) references productos(id)
on delete cascade,
primary key(id)
);

insert into categorias(id, nombre) values (1, 'Herramienta Manual'), 
(2, 'Desarmadores');

insert into modo_pago(id, nombre, detalles) values (1, '4189334533345', 'Debito'),
(2, '123445677', 'Credito');

insert into clientes(id, nombre, direccion, rfc, modo_pago) values (1, 'Juan', 'conocido', 'aaax6666', 1),
(2, 'Pedro', 'conocido', 'aaax6666', 2),
(3, 'Oscar', 'conocido', 'aaax6666', 2);

insert into productos(id, nombre, precio, unidadMedida, id_categoria, stock, stock_min, descuento) values
(1, 'Mazo', 90, 'pieza', 1, 100, 100, 60),
(2, 'Pinza', 75, 'pieza', 1, 50, 100, 60),
(3, 'Desarmador', 100, 'pieza', 2, 80, 100, 60),
(4, 'Martillo', 50, 'pieza', 1, 50, 20, 10),
(5, 'Taladro', 89, 'pieza', 1, 10, 10, 20);

insert into facturas values (1, '2024-05-02', 1, 500, 'Compra de 5 desarmadores'),
(2, '2024-05-02', 1, 165, 'Compra de una pinza y un mazo');

insert into detalles_fac values (1, 1, 1, 5),
(2, 1, 2, 1),
(3, 1, 3, 1);