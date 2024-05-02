<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <title>Bases de datos y MySQL - Modificar Prestamo</title>
        <link href="../styles.css" rel="stylesheet" type="text/css" />
    </head>
    <body>
        <div id="encabezado">
            <h1>Bases de datos y MySQL - Modificar Prestamo</h1>
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
                $id = $_REQUEST["id"];
                $claveLibro = $_REQUEST["claveLibro"];
                $claveUsuario = $_REQUEST["claveUsuario"];
                $fechaPrestamo = $_REQUEST["fechaPrestamo"];
                $fechaEntrega = $_REQUEST["fechaEntrega"];
                $recargos = $_REQUEST["recargos"];

                //validando el campo
                if (isset($claveLibro) && isset($claveUsuario) && isset($fechaPrestamo) &&
                isset($fechaEntrega) && isset($recargos)) {
                    //creando la consulta
                    $sql = "UPDATE prestamos SET claveLibro = $claveLibro, claveUsuario = $claveUsuario, fechaPrestamo = '$fechaPrestamo', fechaEntrega = '$fechaEntrega', recargos = $recargos WHERE id = $id";
                    //echo $sql;
                    //4.- ejecutando la consulta
                    $result = $link->query($sql);
                    //5.- validando la consulta
                    if ($link->affected_rows > 0) {
                    echo "El prestamo se ha modificado de forma correcta.\n";
                    } else {
                    die('Consulta no v&aacute;lida: ' . $link->error);
                    }
                    $link->close();
                } else {
                    echo "Debes llenar todos los datos \n";
                }
            ?>
        </div>
        <div id="contenido"></div>
        <div id="pie">
            <h2>Todos los derechos reservados</h2>
        </div>
    </body>
</html>