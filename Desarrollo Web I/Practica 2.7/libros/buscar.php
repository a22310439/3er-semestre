<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <title>Bases de datos y MySQL - Buscar Libro</title>
        <link href="../styles.css" rel="stylesheet" type="text/css" />
    </head>
    <body>
        <div id="encabezado">
            <h1>Bases de datos y MySQL - Buscar Libro</h1>
        </div>
        <div id="menu">
            <ul>
                <li><a href="usuarios.html">P&aacute;gina inicial</a></li>
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
                    $sql = "SELECT titulo FROM libros WHERE id = $id";
                
                    // Ejecutando la consulta
                    $result = $link->query($sql);
                
                    // Validando la consulta
                    if ($result) {
                        // Verificando si se encontraron resultados
                        if ($result->num_rows > 0) {
                            // Obtener el primer registro (suponiendo que solo esperas un resultado)
                            $row = $result->fetch_assoc();
                            $titulo = $row['titulo'];
                            echo "<p>Libro: $titulo</p>";
                        }
                    } else {
                        // Si hubo algún error en la consulta
                        die('Consulta no válida: ' . $link->error);
                    }
                
                    // Cerrar la conexión a la base de datos

                    $sql = "SELECT isbn FROM libros WHERE id = $id";
                    
                    // Ejecutando la consulta
                    $result = $link->query($sql);
                
                    // Validando la consulta
                    if ($result) {
                        // Verificando si se encontraron resultados
                        if ($result->num_rows > 0) {
                            // Obtener el primer registro (suponiendo que solo esperas un resultado)
                            $row = $result->fetch_assoc();
                            $isbn = $row['isbn'];
                        }
                    } else {
                        // Si hubo algún error en la consulta
                        die('Consulta no válida: ' . $link->error);
                    }
                    $sql = "SELECT autor FROM libros WHERE id = $id";
                    
                    // Ejecutando la consulta
                    $result = $link->query($sql);
                
                    // Validando la consulta
                    if ($result) {
                        // Verificando si se encontraron resultados
                        if ($result->num_rows > 0) {
                            // Obtener el primer registro (suponiendo que solo esperas un resultado)
                            $row = $result->fetch_assoc();
                            $autor = $row['autor'];
                        }
                    } else {
                        // Si hubo algún error en la consulta
                        die('Consulta no válida: ' . $link->error);
                    }
                    $sql = "SELECT disponible FROM libros WHERE id = $id";
                    
                    // Ejecutando la consulta
                    $result = $link->query($sql);
                
                    // Validando la consulta
                    if ($result) {
                        // Verificando si se encontraron resultados
                        if ($result->num_rows > 0) {
                            // Obtener el primer registro (suponiendo que solo esperas un resultado)
                            $row = $result->fetch_assoc();
                            $disponible = $row['disponible'];
                        }
                    } else {
                        // Si hubo algún error en la consulta
                        die('Consulta no válida: ' . $link->error);
                    }
                }
                
            ?>
        <div id="contenido">
            <form action="buscar.html" method="get">
                <p>Libro:</p>

                <?php
                    echo "<table>
                        <tbody>
                            <tr>
                                <td>Titulo:</td>
                                <td>
                                    <input type='text' name='titulo' size='40' maxlength='40' disabled='true' value='$titulo' required/>
                                </td>
                                <td>ISBN:</td>
                                <td>
                                    <input type='text' name='isbn' size='15' maxlength='40' disabled='true' value='$isbn' required/>
                                </td>
                            </tr>
                            <tr>
                                <td>Autor:</td>
                                <td>
                                    <input type='text' name='autor' size='40' maxlength='15' disabled='true' value='$autor' required/>
                                </td>
                                <td>Disponible</td>
                                <td>
                                <input type='text' name='disponible' size='15' maxlength='15' disabled='true' value='".($disponible == 1 ? 'Si' : 'No')."' required/>

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