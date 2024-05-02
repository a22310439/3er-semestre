<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <title>Bases de datos y MySQL - Borrar Libro</title>
        <link href="../styles.css" rel="stylesheet" type="text/css" />
    </head>
    <body>
        <div id="encabezado">
            <h1>Bases de datos y MySQL - Borrar Libro</h1>
        </div>
        <div id="menu">
            <ul>
                <li><a href="libros.html">P&aacute;gina inicial</a></li>
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

                //validando el campo
                if (isset($id)) {
                    //creando la consulta
                    $sql = "DELETE FROM libros WHERE id = $id";
                    //echo $sql;
                    //4.- ejecutando la consulta
                    $result = $link->query($sql);
                    //5.- validando la consulta
                    if ($link->affected_rows > 0) {
                    echo "El libro se ha eliminado de forma correcta.\n";
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