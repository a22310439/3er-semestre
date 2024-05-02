<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <title>Bases de datos y MySQL - Agregar Usuario</title>
        <link href="../styles.css" rel="stylesheet" type="text/css" />
    </head>
    <body>
        <div id="encabezado">
            <h1>Bases de datos y MySQL - Agregar Usuario</h1>
        </div>
        <div id="menu">
            <ul>
                <li><a href="usuarios.html">P&aacute;gina inicial</a></li>
            </ul>
            <?php
                include '../conexion.php';
                //1.- Conexión al servidor de bases de datos, interface OOP
                $link = new mysqli(DB_SERVER, DB_USER, DB_PASS, DB_NAME);
                if ($link->connect_error) {
                    echo "Fallo al conectar: " . $link->connect_error;
                }

                //2.- obteniendo los datos del formulario
                $nombre = $_REQUEST["nombre"];
                $direccion = $_REQUEST["direccion"];
                $telefono = $_REQUEST["telefono"];

                //validando los campos
                if (isset($nombre) && isset($direccion) &&
                isset($telefono)) {
                    //creando la consulta
                    $sql = "INSERT INTO usuarios (clave, nombre, dir, telefono) "
                    .
                    "VALUES ('NULL', '$nombre', '$direccion', '$telefono')";
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
            ?>
        </div>
        <div id="contenido"></div>
        <div id="pie">
            <h2>Todos los derechos reservados</h2>
        </div>
    </body>
</html>