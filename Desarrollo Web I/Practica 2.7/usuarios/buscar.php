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
                <li><a href="usuarios.php">P&aacute;gina inicial</a></li>
            </ul>
        </div>
            <?php
                include '../conexion.php';
                //1.- Conexión al servidor de bases de datos, interface OOP
                $link = new mysqli(DB_SERVER, DB_USER, DB_PASS, DB_NAME);
                if ($link->connect_error) {
                    echo "Fallo al conectar: " . $link->connect_error;
                }

                //2.- obteniendo los datos del formulario
                $clave = $_REQUEST["clave"];

                //validando el campo
                if (isset($clave)) {
                    // Creando la consulta
                    $sql = "SELECT nombre FROM usuarios WHERE clave = $clave";
                
                    // Ejecutando la consulta
                    $result = $link->query($sql);
                
                    // Validando la consulta
                    if ($result) {
                        // Verificando si se encontraron resultados
                        if ($result->num_rows > 0) {
                            // Obtener el primer registro (suponiendo que solo esperas un resultado)
                            $row = $result->fetch_assoc();
                            $nombre = $row['nombre'];
                            echo "<p>Usuario:</p>";
                        }
                    } else {
                        // Si hubo algún error en la consulta
                        die('Consulta no válida: ' . $link->error);
                    }
                
                    // Cerrar la conexión a la base de datos

                    $sql = "SELECT dir FROM usuarios WHERE clave = $clave";
                    
                    // Ejecutando la consulta
                    $result = $link->query($sql);
                
                    // Validando la consulta
                    if ($result) {
                        // Verificando si se encontraron resultados
                        if ($result->num_rows > 0) {
                            // Obtener el primer registro (suponiendo que solo esperas un resultado)
                            $row = $result->fetch_assoc();
                            $dir = $row['dir'];
                        }
                    } else {
                        // Si hubo algún error en la consulta
                        die('Consulta no válida: ' . $link->error);
                    }
                    $sql = "SELECT telefono FROM usuarios WHERE clave = $clave";
                    
                    // Ejecutando la consulta
                    $result = $link->query($sql);
                
                    // Validando la consulta
                    if ($result) {
                        // Verificando si se encontraron resultados
                        if ($result->num_rows > 0) {
                            // Obtener el primer registro (suponiendo que solo esperas un resultado)
                            $row = $result->fetch_assoc();
                            $telefono = $row['telefono'];
                        }
                    } else {
                        // Si hubo algún error en la consulta
                        die('Consulta no válida: ' . $link->error);
                    }
                }
                
            ?>
        <div id="contenido">
            <form action="buscar.html" method="get">
                <p>Corrobore la información a cambiar:</p>

                <?php
                    echo "<table>
                        <tbody>
                            <tr>
                                <td>Nombre:</td>
                                <td>
                                    <input type='text' name='nombre' size='40' maxlength='40' disabled='true' value='$nombre' required/>
                                </td>
                            </tr>
                            <tr>
                                <td>Direcci&oacute;n:</td>
                                <td>
                                    <input type='text' name='direccion' size='60' maxlength='40' disabled='true' value='$dir' required/>
                                </td>
                            </tr>
                            <tr>
                                <td>Telefono</td>
                                <td>
                                    <input type='text' name='telefono' size='15' maxlength='15' disabled='true' value='$telefono' required/>
                                </td>
                            </tr>
                        </tbody>
                    </table>";
                ?>

                <p><input type="submit" value="Regresar"></p>
                <input type="hidden" name="clave" value="<?php echo $clave; ?>">

            </form>
        </div>
        <div id="pie">
            <h2>Todos los derechos reservados</h2>
        </div>
    </body>
</html>