<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Ejercicio 3</title>
    <link rel="stylesheet" href="styles.css">
</head>
<header>
    <h1><img src="imagenes/logoceti.png" alt="logoceti.png" width="10%">Ejercicio 3</h1>
</header>
<body>
    <form method="post">
    <select name="seleccion" id="grados">
        <option value="celcius">Celcius</option>
        <option value="farenheit">Farenheit</option>
        <option value="kelvin">Kelvin</option>
    </select>
    <input type="text" name="grados" placeholder="Grados" size="5" onkeypress="return soloNumeros(event)" width= 20px>
    <input type="submit" value="Procesar">
    </form>
    <p>
        <?php
            // Verificar si se han enviado los valores
            if (isset($_POST['seleccion']) && isset($_POST['grados'])) {
                $seleccion = $_POST['seleccion'];
                $grados = $_POST['grados'];
                if ($seleccion == "celcius") {
                    $farenheit = $grados * 9 / 5 + 32;
                    $kelvin = $grados + 273.15;
                    echo "Celcius: " . $grados . "<br>";
                    echo "Farenheit: " . $farenheit . "<br>";
                    echo "Kelvin: " . $kelvin . "<br>";
                } elseif ($seleccion == "farenheit") {
                    $celcius = ($grados - 32) * 5 / 9;
                    $kelvin = $celcius + 273.15;
                    echo "Celcius: " . $celcius . "<br>";
                    echo "Farenheit: " . $grados . "<br>";
                    echo "Kelvin: " . $kelvin . "<br>";
                } elseif ($seleccion == "kelvin") {
                    $celcius = $grados - 273.15;
                    $farenheit = $celcius * 9 / 5 + 32;
                    echo "Celcius: " . $celcius . "<br>";
                    echo "Farenheit: " . $farenheit . "<br>";
                    echo "Kelvin: " . $grados . "<br>";
                }
            }
        ?>
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
