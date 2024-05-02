<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <title>Bases de datos y MySQL - Inicio</title>
        <link href="../styles.css" rel="stylesheet" type="text/css" />
    </head>
    <body>
        <div id="encabezado">
            <h1>Bases de datos y MySQL - Inicio</h1>
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
                $titulo = $_REQUEST["titulo"];
                $autor = $_REQUEST["autor"];
                $isbn = $_REQUEST["isbn"];
                $disponible = $_REQUEST["disponible"];

                //validando los campos
                if (isset($titulo) && isset($autor) && isset($isbn) && isset($disponible)) {
                    //creando la consulta
                    $sql = "INSERT INTO libros (id, isbn, titulo, autor, disponible) "
                    .
                    "VALUES ('NULL', $isbn, '$titulo', '$autor', $disponible)";
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