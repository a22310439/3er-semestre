DROP DATABASE IF EXISTS bd_peic;
CREATE DATABASE bd_peic;
USE bd_peic;

-- Tabla usuario
CREATE TABLE usuario (
    id INT PRIMARY KEY AUTO_INCREMENT,
    nombreusuario VARCHAR(50),
    contrasenia VARCHAR(50)
);

-- Tabla participante
CREATE TABLE participante (
    id INT PRIMARY KEY AUTO_INCREMENT,
    nombre VARCHAR(100),
    correo VARCHAR(100),
    telefono VARCHAR(20),
    direccion VARCHAR(255),
    edad INT,
    fechaRegistro DATE,
    idUsuario INT,
    FOREIGN KEY (idUsuario) REFERENCES usuario(id)
);

-- Tabla evaluador
CREATE TABLE evaluador (
    id INT PRIMARY KEY AUTO_INCREMENT,
    nombre VARCHAR(100),
    correo VARCHAR(100),
    telefono VARCHAR(20),
    idUsuario INT,
    FOREIGN KEY (idUsuario) REFERENCES usuario(id)
);

-- Tabla estandar
CREATE TABLE estandar (
    id INT PRIMARY KEY AUTO_INCREMENT,
    descripcion VARCHAR(255),
    nivel INT,
    vigencia_anios INT  -- Añadir columna para la vigencia en años
);

-- Tabla alineacion
CREATE TABLE alineacion (
    id INT PRIMARY KEY AUTO_INCREMENT,
    descripcion VARCHAR(255),
    idEstandar INT,
    FOREIGN KEY (idEstandar) REFERENCES estandar(id)
);

-- Tabla evaluacion
CREATE TABLE evaluacion (
    id INT PRIMARY KEY AUTO_INCREMENT,
    descripcion VARCHAR(255),
    idEvaluador INT,
    idParticipante INT,
    idEstandar INT,
    fecha DATE,
    resultado VARCHAR(15),
    FOREIGN KEY (idEvaluador) REFERENCES evaluador(id),
    FOREIGN KEY (idParticipante) REFERENCES participante(id),
    FOREIGN KEY (idEstandar) REFERENCES estandar(id)
);

CREATE TABLE certificado (
    id INT PRIMARY KEY AUTO_INCREMENT,
    idEstandar INT,
    idParticipante INT,
    vigencia DATE,
    vigente VARCHAR(10) DEFAULT 'vigente',
    FOREIGN KEY (idEstandar) REFERENCES Estandar(id),
    FOREIGN KEY (idParticipante) REFERENCES Participante(id)
);

-- TRIGGERS
DELIMITER $$

-- Trigger para inserción en evaluacion
CREATE TRIGGER trg_after_evaluacion_insert
AFTER INSERT ON evaluacion
FOR EACH ROW
BEGIN
    IF NEW.resultado = 'competente' THEN
        IF NOT EXISTS (
            SELECT 1
            FROM certificado
            WHERE idParticipante = NEW.idParticipante
              AND idEstandar = NEW.idEstandar
              AND vigencia >= CURDATE()
        ) THEN
            INSERT INTO certificado (idEstandar, idParticipante, vigencia, vigente)
            VALUES (
                NEW.idEstandar,
                NEW.idParticipante,
                DATE_ADD(CURDATE(), INTERVAL (SELECT vigencia_anios FROM estandar WHERE id = NEW.idEstandar) YEAR),
                'vigente'
            );
        END IF;
    END IF;
END$$

-- Trigger para actualización en evaluacion
CREATE TRIGGER trg_after_evaluacion_update
AFTER UPDATE ON evaluacion
FOR EACH ROW
BEGIN
    IF NEW.resultado = 'competente' THEN
        IF NOT EXISTS (
            SELECT 1
            FROM certificado
            WHERE idParticipante = NEW.idParticipante
              AND idEstandar = NEW.idEstandar
              AND vigencia >= CURDATE()
        ) THEN
            INSERT INTO certificado (idEstandar, idParticipante, vigencia, vigente)
            VALUES (
                NEW.idEstandar,
                NEW.idParticipante,
                DATE_ADD(CURDATE(), INTERVAL (SELECT vigencia_anios FROM estandar WHERE id = NEW.idEstandar) YEAR),
                'vigente'
            );
        END IF;
    END IF;
END$$

-- Trigger para actualizar el estado de vigencia de los certificados
CREATE TRIGGER trg_update_certificado_vigencia
BEFORE UPDATE ON certificado
FOR EACH ROW
BEGIN
    IF NEW.vigencia < CURDATE() THEN
        SET NEW.vigente = 'vencido';
    END IF;
END$$

-- Trigger para inserción en la tabla usuario
CREATE TRIGGER trg_usuario_insert
AFTER INSERT ON usuario
FOR EACH ROW
BEGIN
    INSERT INTO bitacora (tabla, operacion, registro_id, usuario, detalles)
    VALUES ('usuario', 'INSERT', NEW.id, NEW.nombreusuario, CONCAT('nombreusuario: ', NEW.nombreusuario, ', contraseña: ', NEW.contraseña));
END$$

-- Trigger para actualización en la tabla usuario
CREATE TRIGGER trg_usuario_update
AFTER UPDATE ON usuario
FOR EACH ROW
BEGIN
    INSERT INTO bitacora (tabla, operacion, registro_id, usuario, detalles)
    VALUES ('usuario', 'UPDATE', NEW.id, NEW.nombreusuario, CONCAT('nombreusuario: ', NEW.nombreusuario, ', contraseña: ', NEW.contraseña));
END$$

-- Trigger para eliminación en la tabla usuario
CREATE TRIGGER trg_usuario_delete
AFTER DELETE ON usuario
FOR EACH ROW
BEGIN
    INSERT INTO bitacora (tabla, operacion, registro_id, usuario, detalles)
    VALUES ('usuario', 'DELETE', OLD.id, OLD.nombreusuario, CONCAT('nombreusuario: ', OLD.nombreusuario, ', contraseña: ', OLD.contraseña));
END$$

-- Trigger para inserción en la tabla participante
CREATE TRIGGER trg_participante_insert
AFTER INSERT ON participante
FOR EACH ROW
BEGIN
    INSERT INTO bitacora (tabla, operacion, registro_id, usuario, detalles)
    VALUES ('participante', 'INSERT', NEW.id, NEW.correo, CONCAT('nombre: ', NEW.nombre, ', correo: ', NEW.correo, ', telefono: ', NEW.telefono, ', direccion: ', NEW.direccion, ', edad: ', NEW.edad, ', fechaRegistro: ', NEW.ferchaRegistro));
END$$

-- Trigger para actualización en la tabla participante
CREATE TRIGGER trg_participante_update
AFTER UPDATE ON participante
FOR EACH ROW
BEGIN
    INSERT INTO bitacora (tabla, operacion, registro_id, usuario, detalles)
    VALUES ('participante', 'UPDATE', NEW.id, NEW.correo, CONCAT('nombre: ', NEW.nombre, ', correo: ', NEW.correo, ', telefono: ', NEW.telefono, ', direccion: ', NEW.direccion, ', edad: ', NEW.edad, ', fechaRegistro: ', NEW.ferchaRegistro));
END$$

-- Trigger para eliminación en la tabla participante
CREATE TRIGGER trg_participante_delete
AFTER DELETE ON participante
FOR EACH ROW
BEGIN
    INSERT INTO bitacora (tabla, operacion, registro_id, usuario, detalles)
    VALUES ('participante', 'DELETE', OLD.id, OLD.correo, CONCAT('nombre: ', OLD.nombre, ', correo: ', OLD.correo, ', telefono: ', OLD.telefono, ', direccion: ', OLD.direccion, ', edad: ', OLD.edad, ', fechaRegistro: ', OLD.ferchaRegistro));
END$$

-- Trigger para inserción en la tabla evaluador
CREATE TRIGGER trg_evaluador_insert
AFTER INSERT ON evaluador
FOR EACH ROW
BEGIN
    INSERT INTO bitacora (tabla, operacion, registro_id, usuario, detalles)
    VALUES ('evaluador', 'INSERT', NEW.id, NEW.correo, CONCAT('nombre: ', NEW.nombre, ', correo: ', NEW.correo, ', telefono: ', NEW.telefono));
END$$

-- Trigger para actualización en la tabla evaluador
CREATE TRIGGER trg_evaluador_update
AFTER UPDATE ON evaluador
FOR EACH ROW
BEGIN
    INSERT INTO bitacora (tabla, operacion, registro_id, usuario, detalles)
    VALUES ('evaluador', 'UPDATE', NEW.id, NEW.correo, CONCAT('nombre: ', NEW.nombre, ', correo: ', NEW.correo, ', telefono: ', NEW.telefono));
END$$

-- Trigger para eliminación en la tabla evaluador
CREATE TRIGGER trg_evaluador_delete
AFTER DELETE ON evaluador
FOR EACH ROW
BEGIN
    INSERT INTO bitacora (tabla, operacion, registro_id, usuario, detalles)
    VALUES ('evaluador', 'DELETE', OLD.id, OLD.correo, CONCAT('nombre: ', OLD.nombre, ', correo: ', OLD.correo, ', telefono: ', OLD.telefono));
END$$

-- Trigger para inserción en la tabla estandar
CREATE TRIGGER trg_estandar_insert
AFTER INSERT ON estandar
FOR EACH ROW
BEGIN
    INSERT INTO bitacora (tabla, operacion, registro_id, usuario, detalles)
    VALUES ('estandar', 'INSERT', NEW.id, NULL, CONCAT('descripcion: ', NEW.descripcion, ', nivel: ', NEW.nivel, ', vigencia_años: ', NEW.vigencia_años));
END$$

-- Trigger para actualización en la tabla estandar
CREATE TRIGGER trg_estandar_update
AFTER UPDATE ON estandar
FOR EACH ROW
BEGIN
    INSERT INTO bitacora (tabla, operacion, registro_id, usuario, detalles)
    VALUES ('estandar', 'UPDATE', NEW.id, NULL, CONCAT('descripcion: ', NEW.descripcion, ', nivel: ', NEW.nivel, ', vigencia_años: ', NEW.vigencia_años));
END$$

-- Trigger para eliminación en la tabla estandar
CREATE TRIGGER trg_estandar_delete
AFTER DELETE ON estandar
FOR EACH ROW
BEGIN
    INSERT INTO bitacora (tabla, operacion, registro_id, usuario, detalles)
    VALUES ('estandar', 'DELETE', OLD.id, NULL, CONCAT('descripcion: ', OLD.descripcion, ', nivel: ', OLD.nivel, ', vigencia_años: ', OLD.vigencia_años));
END$$

-- Trigger para inserción en la tabla evaluacion
CREATE TRIGGER trg_evaluacion_insert
AFTER INSERT ON evaluacion
FOR EACH ROW
BEGIN
    INSERT INTO bitacora (tabla, operacion, registro_id, usuario, detalles)
    VALUES ('evaluacion', 'INSERT', NEW.id, NULL, CONCAT('descripcion: ', NEW.descripcion, ', idEvaluador: ', NEW.idEvaluador, ', idParticipante: ', NEW.idParticipante, ', idEstandar: ', NEW.idEstandar, ', fecha: ', NEW.fecha, ', resultado: ', NEW.resultado));
END$$

-- Trigger para actualización en la tabla evaluacion
CREATE TRIGGER trg_evaluacion_update
AFTER UPDATE ON evaluacion
FOR EACH ROW
BEGIN
    INSERT INTO bitacora (tabla, operacion, registro_id, usuario, detalles)
    VALUES ('evaluacion', 'UPDATE', NEW.id, NULL, CONCAT('descripcion: ', NEW.descripcion, ', idEvaluador: ', NEW.idEvaluador, ', idParticipante: ', NEW.idParticipante, ', idEstandar: ', NEW.idEstandar, ', fecha: ', NEW.fecha, ', resultado: ', NEW.resultado));
END$$

-- Trigger para eliminación en la tabla evaluacion
CREATE TRIGGER trg_evaluacion_delete
AFTER DELETE ON evaluacion
FOR EACH ROW
BEGIN
    INSERT INTO bitacora (tabla, operacion, registro_id, usuario, detalles)
    VALUES ('evaluacion', 'DELETE', OLD.id, NULL, CONCAT('descripcion: ', OLD.descripcion, ', idEvaluador: ', OLD.idEvaluador, ', idParticipante: ', OLD.idParticipante, ', idEstandar: ', OLD.idEstandar, ', fecha: ', OLD.fecha, ', resultado: ', OLD.resultado));
END$$

-- Trigger para inserción en la tabla certificado
CREATE TRIGGER trg_certificado_insert
AFTER INSERT ON certificado
FOR EACH ROW
BEGIN
    INSERT INTO bitacora (tabla, operacion, registro_id, usuario, detalles)
    VALUES ('certificado', 'INSERT', NEW.id, NULL, CONCAT('idEstandar: ', NEW.idEstandar, ', idParticipante: ', NEW.idParticipante, ', vigencia: ', NEW.vigencia, ', vigente: ', NEW.vigente));
END$$

-- Trigger para actualización en la tabla certificado
CREATE TRIGGER trg_certificado_update
AFTER UPDATE ON certificado
FOR EACH ROW
BEGIN
    INSERT INTO bitacora (tabla, operacion, registro_id, usuario, detalles)
    VALUES ('certificado', 'UPDATE', NEW.id, NULL, CONCAT('idEstandar: ', NEW.idEstandar, ', idParticipante: ', NEW.idParticipante, ', vigencia: ', NEW.vigencia, ', vigente: ', NEW.vigente));
END$$

-- Trigger para eliminación en la tabla certificado
CREATE TRIGGER trg_certificado_delete
AFTER DELETE ON certificado
FOR EACH ROW
BEGIN
    INSERT INTO bitacora (tabla, operacion, registro_id, usuario, detalles)
    VALUES ('certificado', 'DELETE', OLD.id, NULL, CONCAT('idEstandar: ', OLD.idEstandar, ', idParticipante: ', OLD.idParticipante, ', vigencia: ', OLD.vigencia, ', vigente: ', OLD.vigente));
END$$

DELIMITER ;