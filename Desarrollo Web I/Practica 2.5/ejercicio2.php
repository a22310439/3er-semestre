<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Ejercicio 2</title>
    <link rel="stylesheet" href="styles.css">
</head>
<header>
    <h1><img src="imagenes/logoceti.png" alt="logoceti.png" width="10%">Ejercicio 2</h1>
</header>
<body>
    <h2>Lista de caracteres del código ASCII</h2>
    <form method="post">
    <table border="1">
        <tr>
            <th>Valor</th>
            <th>Caracter</th>
        </tr>
        <?php
            if (isset($_POST['valor'])) {
                $valor = $_POST['valor'];
                for ($i = 32; $i <= $valor; $i++) {
                    echo "<tr>";
                    echo "<td>$i</td>";
                    echo "<td>" . chr($i) . "</td>";
                    echo "</tr>";
                }
            }else{
                echo "no hay valor ingresado";
            }
        ?>
    </table>
    <p>Introduce un valor igual o mayor a 32</p>
    <input type="text" name="valor" placeholder="Introduce un valor">
    <input type="submit" value="Procesar">
    </form>
    <p>
</body>
<footer>
    <h2>Jesús Alberto Aréchiga Carrillo - 22310439</h2>
    <h3>Centro de Enseñanza Técnica Industrial</h3>
    <div>
        <a href="index.php" class="button">Ir al inicio</a>
    </div>
</footer>
</html>
