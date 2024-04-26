<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Ejercicio 1</title>
    <link rel="stylesheet" href="styles.css">
</head>
<header>
    <h1><img src="imagenes/logoceti.png" alt="logoceti.png" width="10%">Ejercicio 1</h1>
</header>
<body>
    <h2>Lista de productos para impresión en 3D</h2>
    <form method="post">
    <table border="1">
        <tr>
            <th>Codigo</th>
            <th>Producto</th>
            <th>Precio por kg</th>
            <th>Cantidad (kg)</th>
        </tr>
        <tr>
            <td>001</td>
            <td>Nylon</td>
            <td>$631.98</td>
            <td onkeypress="return soloNumeros(event)">
            <input type="text" name="nylon">
            </td>
        </tr>
        <tr>
            <td>002</td>
            <td>TPU</td>
            <td>$469.85</td>
            <td onkeypress="return soloNumeros(event)">
            <input type="text" name="tpu">
            </td>
        </tr>
        <tr>
            <td>003</td>
            <td>ABS</td>
            <td>$480.99</td>
            <td onkeypress="return soloNumeros(event)">
            <input type="text" name="abs">
            </td>
        </tr>
    </table>
    <input type="submit" value="Procesar">
    </form>
    <p>
        <?php
            // Verificar si se han enviado los valores
            if (isset($_POST['nylon']) && isset($_POST['tpu']) && isset($_POST['abs'])) {
                $nylon = $_POST['nylon'];
                $tpu = $_POST['tpu'];
                $abs = $_POST['abs'];
                $totalSinIVA = $nylon * 631.98 + $tpu * 469.85 + $abs * 480.99;
                $IVA = $totalSinIVA * 0.16;
                $totalConIVA = $totalSinIVA + $IVA;
                echo "Nylon: $" . $nylon * 631.98 . "<br>";
                echo "TPU: $" . $tpu * 469.85 . "<br>";
                echo "ABS: $" . $abs * 480.99 . "<br>";
                echo "Total sin IVA: $$totalSinIVA<br>";
                echo "IVA: $$IVA<br>";
                echo "Total con IVA: $$totalConIVA";
            } else {
                echo "Por favor, complete todos los campos.";
            }
        ?>
    </p>

</body>
<script> //script para que solo se puedan ingresar números en las celdas
    function soloNumeros(event) {
      var codigoTecla = event.which || event.keyCode;
      if (codigoTecla == 13 || codigoTecla == 8) {
        return true;
      }
      var caracter = String.fromCharCode(codigoTecla);
      // Verificar si el carácter es un número
      if (!/^\d+$/.test(caracter)) {
        // Si no es un número, cancelar el evento
        event.preventDefault();
        return false;
      }
    };
</script>
<footer>
    <h2>Jesús Alberto Aréchiga Carrillo - 22310439</h2>
    <h3>Centro de Enseñanza Técnica Industrial</h3>
    <div>
        <a href="index.php" class="button">Ir al inicio</a>
    </div>
</footer>
</html>
