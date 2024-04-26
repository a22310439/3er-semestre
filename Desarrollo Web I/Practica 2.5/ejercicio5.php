<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Ejercicio 5</title>
    <link rel="stylesheet" href="styles.css">
</head>
<header>
    <h1><img src="imagenes/logoceti.png" alt="logoceti.png" width="10%">Ejercicio 5</h1>
</header>
<body>
<form method="post">
    <div>
        <label for="nombreUsuario">Nombre de usuario:</label>
        <input type="text" name="nombreUsuario" id="nombreUsuario" required>
    </div>
    <div>
        <label for="nombreCompleto">Nombre completo:</label>
        <input type="text" name="nombreCompleto" id="nombreCompleto" required>
    </div>
    <div>
        <label for="contrasena">Contraseña:</label>
        <input type="password" name="contrasena" id="contrasena" required>
    </div>
    <div>
        <label for="confirmarContrasena">Confirmar contraseña:</label>
        <input type="password" name="confirmarContrasena" id="confirmarContrasena" required>
    </div>
    <div>
        <label for="correoElectronico">Correo electrónico:</label>
        <input type="email" name="correoElectronico" id="correoElectronico" required>
    </div>
    <div>
        <label>Sexo:</label>
        <input type="radio" name="sexo" id="sexoMasculino" value="masculino" required>
        <label for="sexoMasculino">Masculino</label>
        <input type="radio" name="sexo" id="sexoFemenino" value="femenino" required>
        <label for="sexoFemenino">Femenino</label>
    </div>
    <div>
        <label>Hobbies:</label>
        <input type="checkbox" name="hobbies" id="deporte" value="deporte">
        <label for="deporte">Deporte</label>
        <input type="checkbox" name="hobbies" id="lectura" value="lectura">
        <label for="lectura">Lectura</label>
        <input type="checkbox" name="hobbies" id="musica" value="musica">
        <label for="musica">Música</label>
        <input type="checkbox" name="hobbies" id="cine" value="cine">
        <label for="cine">Cine</label>
    </div>
    <div>
        <label for="estadoCivil">Estado civil:</label>
        <select name="estadoCivil" id="estadoCivil" required>
            <option value="soltero">Soltero(a)</option>
            <option value="casado">Casado(a)</option>
            <option value="divorciado">Divorciado(a)</option>
        </select>
    </div>
    <div>
        <label for="calle">Calle:</label>
        <input type="text" name="calle" id="calle" required>
    </div>
    <div>
        <label for="numeroInterior">Número interior:</label>
        <input type="text" name="numeroInterior" id="numeroInterior">
    </div>
    <div>
        <label for="colonia">Colonia:</label>
        <input type="text" name="colonia" id="colonia" required>
    </div>
    <div>
        <label for="estado">Estado:</label>
        <input type="text" name="estado" id="estado" required>
    </div>
    <div>
        <label for="pais">País:</label>
        <input type="text" name="pais" id="pais" required>
    </div>
    <div>
        <label for="cp">CP:</label>
        <input type="text" name="cp" id="cp" required>
    </div>
    <div>
        <input type="submit" value="Registrar">
    </div>
</form>
<p>
<?php
// Verificar si se han enviado los datos del formulario
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Verificar si los datos del formulario están seteados
    if (isset($_POST['nombreUsuario']) && isset($_POST['nombreCompleto']) && isset($_POST['contrasena']) && isset($_POST['confirmarContrasena']) && isset($_POST['correoElectronico']) && isset($_POST['sexo']) && isset($_POST['hobbies']) && isset($_POST['estadoCivil']) && isset($_POST['calle']) && isset($_POST['numeroInterior']) && isset($_POST['colonia']) && isset($_POST['estado']) && isset($_POST['pais']) && isset($_POST['cp'])) {
        // Recuperar los datos del formulario
        $nombreUsuario = $_POST['nombreUsuario'];
        $nombreCompleto = $_POST['nombreCompleto'];
        $contrasena = $_POST['contrasena'];
        $confirmarContrasena = $_POST['confirmarContrasena'];
        $correoElectronico = $_POST['correoElectronico'];
        $sexo = $_POST['sexo'];
        $hobbies = $_POST['hobbies'];
        $estadoCivil = $_POST['estadoCivil'];
        $calle = $_POST['calle'];
        $numeroInterior = $_POST['numeroInterior'];
        $colonia = $_POST['colonia'];
        $estado = $_POST['estado'];
        $pais = $_POST['pais'];
        $cp = $_POST['cp'];

        echo "<table border='1'>";
        echo "<tr>";
        echo "<th>Nombre de usuario</th>";
        echo "<td>$nombreUsuario</td>";
        echo "</tr>";
        echo "<tr>";
        echo "<th>Nombre completo</th>";
        echo "<td>$nombreCompleto</td>";
        echo "</tr>";
        echo "<tr>";
        echo "<th>Contraseña</th>";
        echo "<td>$contrasena</td>";
        echo "</tr>";
        echo "<tr>";
        echo "<th>Correo electrónico</th>";
        echo "<td>$correoElectronico</td>";
        echo "</tr>";
        echo "<tr>";
        echo "<th>Sexo</th>";
        echo "<td>$sexo</td>";
        echo "</tr>";
        echo "<tr>";
        echo "<th>Hobbies</th>";
        echo "<td>$hobbies</td>";
        echo "</tr>";
        echo "<tr>";
        echo "<th>Estado civil</th>";
        echo "<td>$estadoCivil</td>";
        echo "</tr>";
        echo "<tr>";
        echo "<th>Calle</th>";
        echo "<td>$calle</td>";
        echo "</tr>";
        echo "<tr>";
        echo "<th>Número interior</th>";
        echo "<td>$numeroInterior</td>";
        echo "</tr>";
        echo "<tr>";
        echo "<th>Colonia</th>";
        echo "<td>$colonia</td>";
        echo "</tr>";
        echo "<tr>";
        echo "<th>Estado</th>";
        echo "<td>$estado</td>";
        echo "</tr>";
        echo "<tr>";
        echo "<th>País</th>";
        echo "<td>$pais</td>";
        echo "</tr>";
        echo "<tr>";
        echo "<th>Código postal</th>";
        echo "<td>$cp</td>";
        echo "</tr>";
        echo "</table>";
    } else {
        // Si no se han enviado todos los datos, muestra un mensaje de error
        echo "Por favor, completa todos los campos del formulario.";
    }
}
?>
</p>
</body>
<script>
    //validar que las contraseñas coincidan
    document.querySelector('form').addEventListener('submit', function(event) {
        var contrasena = document.getElementById('contrasena').value;
        var confirmarContrasena = document.getElementById('confirmarContrasena').value;
        if (contrasena !== confirmarContrasena) {
            alert('Las contraseñas no coinciden');
            event.preventDefault();
        }
    });
</script>
<footer>
    <h2>Jesús Alberto Aréchiga Carrillo - 22310439</h2>
    <h3>Centro de Enseñanza Técnica Industrial</h3>
    <div>
        <a href="index.php" class="button">Ir al inicio</a>
    </div>
</footer>
</html>
