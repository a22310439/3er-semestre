<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <title>Bases de datos y MySQL - Agregar Prestamo</title>
        <link href="../styles.css" rel="stylesheet" type="text/css" />
    </head>
    <body>
        <div id="encabezado">
            <h1>Bases de datos y MySQL - Agregar Prestamo</h1>
        </div>
        <div id="menu">
            <ul>
                <li><a href="prestamos.html">P&aacute;gina inicial</a></li>
            </ul>
            <?php
                include '../conexion.php';
                //1.- Conexión al servidor de bases de datos, interface OOP
                $link = new mysqli(DB_SERVER, DB_USER, DB_PASS, DB_NAME);
                if ($link->connect_error) {
                    echo "Fallo al conectar: " . $link->connect_error;
                }

                //2.- obteniendo los datos del formulario
                $idLibro = $_REQUEST["idLibro"];
                $idUsuario = $_REQUEST["idUsuario"];
                $fechaPrestamo = $_REQUEST["fechaPrestamo"];
                $fechaEntrega = $_REQUEST["fechaEntrega"];
                $recargos = $_REQUEST["recargos"];

                //validando los campos
                if (isset($idLibro) && isset($idUsuario) && isset($fechaPrestamo) && 
                isset($fechaEntrega) && isset($recargos)) {
                    //creando la consulta
                    $sql = "SELECT disponible FROM libros WHERE id = $idLibro";
                    $result = $link->query($sql);
                    if ($result) {
                        // Verificando si se encontraron resultados
                        if ($result->num_rows > 0) {
                            // Obtener el primer registro (suponiendo que solo esperas un resultado)
                            $row = $result->fetch_assoc();
                            $disponible = $row['disponible'];
                            if ($disponible == 1) {
                                $sql = "UPDATE libros SET disponible = 0 WHERE id = $idLibro";
                                $result = $link->query($sql);
                                if ($link->affected_rows > 0) {
                                    $sql = "INSERT INTO prestamos (id, claveLibro, claveUsuario, 
                                    fechaPrestamo, fechaEntrega, recargos) "
                                    .
                                    "VALUES ('NULL', $idLibro, $idUsuario, '$fechaPrestamo', 
                                    '$fechaEntrega', '$recargos')";
                                    //echo $sql;
                                    //4.- ejecutando la consulta
                                    $result = $link->query($sql);
                                    //5.- validando la consulta
                                    if ($link->affected_rows > 0) {
                                    echo "La informaci&oacute;n se ha insertado con
                                    &eacute;xito.\n";
                                    } else {
                                    die('Consulta no v&aacute;lida: ' . $link->error);
                                    }
                                    $link->close();
                                } else {
                                    echo "Debes llenar todos los datos \n";
                                }
                            } else {
                                echo "El libro no est&aacute; disponible.\n";
                            }
                        }
                    } else {
                        // Si hubo algún error en la consulta
                        die('El libro no existe.');
                    }
                }
            ?>
        </div>
        <div id="contenido"></div>
        <div id="pie">
            <h2>Todos los derechos reservados</h2>
        </div>
    </body>
</html>