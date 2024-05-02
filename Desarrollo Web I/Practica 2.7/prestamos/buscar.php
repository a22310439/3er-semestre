<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <title>Bases de datos y MySQL - Buscar Prestamo</title>
        <link href="../styles.css" rel="stylesheet" type="text/css" />
    </head>
    <body>
        <div id="encabezado">
            <h1>Bases de datos y MySQL - Buscar Prestamo</h1>
        </div>
        <div id="menu">
            <ul>
                <li><a href="prestamos.html">P&aacute;gina inicial</a></li>
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
                $id = $_REQUEST["id"];

                //validando el campo
                if (isset($id)) {
                    // Creando la consulta
                    $sql = "SELECT claveLibro FROM prestamos WHERE id = $id";
                
                    // Ejecutando la consulta
                    $result = $link->query($sql);
                
                    // Validando la consulta
                    if ($result) {
                        // Verificando si se encontraron resultados
                        if ($result->num_rows > 0) {
                            // Obtener el primer registro (suponiendo que solo esperas un resultado)
                            $row = $result->fetch_assoc();
                            $claveLibro = $row['claveLibro'];
                        }
                    } else {
                        // Si hubo algún error en la consulta
                        die('Consulta no válida: ' . $link->error);
                    }
                    $sql = "SELECT claveUsuario FROM prestamos WHERE id = $id";
                    
                    // Ejecutando la consulta
                    $result = $link->query($sql);
                
                    // Validando la consulta
                    if ($result) {
                        // Verificando si se encontraron resultados
                        if ($result->num_rows > 0) {
                            // Obtener el primer registro (suponiendo que solo esperas un resultado)
                            $row = $result->fetch_assoc();
                            $claveUsuario = $row['claveUsuario'];
                        }
                    } else {
                        // Si hubo algún error en la consulta
                        die('Consulta no válida: ' . $link->error);
                    }
                    $sql = "SELECT fechaPrestamo FROM prestamos WHERE id = $id";
                    
                    // Ejecutando la consulta
                    $result = $link->query($sql);
                
                    // Validando la consulta
                    if ($result) {
                        // Verificando si se encontraron resultados
                        if ($result->num_rows > 0) {
                            // Obtener el primer registro (suponiendo que solo esperas un resultado)
                            $row = $result->fetch_assoc();
                            $fechaPrestamo = $row['fechaPrestamo'];
                        }
                    } else {
                        // Si hubo algún error en la consulta
                        die('Consulta no válida: ' . $link->error);
                    }
                    $sql = "SELECT fechaEntrega FROM prestamos WHERE id = $id";
                
                    // Ejecutando la consulta
                    $result = $link->query($sql);
                
                    // Validando la consulta
                    if ($result) {
                        // Verificando si se encontraron resultados
                        if ($result->num_rows > 0) {
                            // Obtener el primer registro (suponiendo que solo esperas un resultado)
                            $row = $result->fetch_assoc();
                            $fechaEntrega = $row['fechaEntrega'];
                        }
                    } else {
                        // Si hubo algún error en la consulta
                        die('Consulta no válida: ' . $link->error);
                    }
                    $sql = "SELECT recargos FROM prestamos WHERE id = $id";
                
                    // Ejecutando la consulta
                    $result = $link->query($sql);
                
                    // Validando la consulta
                    if ($result) {
                        // Verificando si se encontraron resultados
                        if ($result->num_rows > 0) {
                            // Obtener el primer registro (suponiendo que solo esperas un resultado)
                            $row = $result->fetch_assoc();
                            $recargos = $row['recargos'];
                        }
                    } else {
                        // Si hubo algún error en la consulta
                        die('Consulta no válida: ' . $link->error);
                    }
                    $sql = "SELECT titulo FROM libros WHERE id = $claveLibro";
                
                    // Ejecutando la consulta
                    $result = $link->query($sql);
                
                    // Validando la consulta
                    if ($result) {
                        // Verificando si se encontraron resultados
                        if ($result->num_rows > 0) {
                            // Obtener el primer registro (suponiendo que solo esperas un resultado)
                            $row = $result->fetch_assoc();
                            $titulo = $row['titulo'];
                        }
                    } else {
                        // Si hubo algún error en la consulta
                        die('Consulta no válida: ' . $link->error);
                    }
                }
                
            ?>
        <div id="contenido">
            <form action="buscar.html" method="get">

                <?php
                    echo "Libro prestado: $titulo<br><br>
                    <table>
                        <tbody>
                            <tr>
                                <td align='right'>ID Libro:</td>
                                <td>
                                    <input type='number' name='idLibro' size='40' maxlength='10' value='$claveLibro' disabled='true' required/>
                                </td>
                                <td align='right'>ID Usuario:</td>
                                <td>
                                    <input type='number' name='idUsuario' size='40' maxlength='40' value='$claveUsuario' disabled='true' required/>
                                </td>
                            </tr>
                            <tr>
                                <td>Fecha de Prestamo:</td>
                                <td>
                                    <input type='date' name='fechaPrestamo' size='40' maxlength='60' value='$fechaPrestamo' disabled='true' required/>
                                </td>
                                <td>Fecha de Entrega:</td>
                                <td>
                                    <input type='date' name='fechaEntrega' size='40' maxlength='15' value='$fechaEntrega' disabled='true'/>
                                </td>
                            </tr>
                            <tr>
                                <td align='right'>Recargos:</td>
                                <td>
                                    <input type='text' name='recargos' size='15' maxlength='10' value='$recargos' disabled='true'/>
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