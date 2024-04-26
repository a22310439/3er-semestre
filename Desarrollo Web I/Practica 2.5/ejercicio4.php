<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Ejercicio 4</title>
    <link rel="stylesheet" href="styles.css">
</head>
<header>
    <h1><img src="imagenes/logoceti.png" alt="logoceti.png" width="10%">Ejercicio 4</h1>
</header>
<body>
    <form method="post">
    <input type="text" name="cadena" placeholder="Cadena" size="50">
    <input type="submit" value="Procesar">
    </form>
    <p>
        <?php
            // Verificar si se han enviado los valores
            if (isset($_POST['cadena'])) {
                $cadena = $_POST['cadena']; 
                $cadena = strtoupper($cadena);  //Convertir cadena a mayusculas
                $cadena = trim($cadena);        //Eliminar espacios en blanco al inicio y al final
                echo "Cadena: " . $cadena . "<br>";
            }
        ?>
    </p>
</body>
<footer>
    <h2>Jesús Alberto Aréchiga Carrillo - 22310439</h2>
    <h3>Centro de Enseñanza Técnica Industrial</h3>
    <div>
        <a href="index.php" class="button">Ir al inicio</a>
    </div>
</footer>
</html>
