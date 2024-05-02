<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <title>Bases de datos y MySQL - Listar Prestamos</title>
        <link href="../styles.css" rel="stylesheet" type="text/css" />
    </head>
    <body>
        <div id="encabezado">
            <h1>Bases de datos y MySQL - Listar Prestamos</h1>
        </div>
        <div id="menu">
            <ul>
                <li><a href="prestamos.html">P&aacute;gina inicial</a></li>
            </ul>
        </div>
        <div id="tabla">
            <h2>Pr&eacute;stamos Registrados</h2>
            <?php
                include '../conexion.php';
                //1.- Conexión al servidor de bases de datos, interface OOP
                $link = new mysqli(DB_SERVER, DB_USER, DB_PASS, DB_NAME);
                if ($link->connect_error) {
                    echo "Fallo al conectar: " . $link->connect_error;
                }

                //creando la consulta
                $sql = "SELECT * FROM prestamos";

                echo "<table border='1'>
                    <tr>
                    <td>ID</td>
                    <td>ID Libro</td>
                    <td>ID Usuario</td>
                    <td>Fecha de Prestamo</td>
                    <td>Fecha de Entrega</td>
                    <td>Recargos</td>
                    </tr>";

                if ($result = $link->query($sql)) {
                    while ($row = $result->fetch_row()) {
                        echo "<tr>
                            <td>$row[0]</td>
                            <td>$row[1]</td>
                            <td>$row[2]</td>
                            <td>$row[3]</td>
                            <td>$row[4]</td>
                            <td>$row[5]</td>
                            <tr>";
                    }
                    $result->close();
                }
            ?>
        </div>
        <div id="pie">
            <h2>Todos los derechos reservados</h2>
        </div>
    </body>
</html>