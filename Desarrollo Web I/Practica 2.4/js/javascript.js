function ejercicio1() {
    var a = prompt("Introduce tu nombre: ")
    alert("El nombre es: " + a)
}

function ejercicio3() {
    var a = prompt("Escribe un número (si no se ingresa nada, se considera 0)")
        a = Number(a)
        while (isNaN(a) || a == null) {
            alert("No es un número")
            a = prompt("Escribe un número (si no se ingresa nada, se considera 0)")
        }
        var b = prompt("Escribe otro número diferente de 0 (si no se ingresa nada, se considera 0)")
        b = Number(b)
        while (isNaN(b) || b == null || b == 0) {
            alert("No es un número o no es valido")
            b = prompt("Escribe otro número diferente de 0 (si no se ingresa nada, se considera 0)")
        }
}

function operaciones() {
    var a = Number(document.getElementById('number1').value)
    if (isNaN(a) || a == null) {
        alert("El primer número no es valido");
        return
    }
    var b = Number(document.getElementById('number2').value)
    if (isNaN(b) || b == null || b === 0) {
        alert("El segundo número no es valido o es 0");
        return
    }
    var result = "Suma: " + a + " + " + b + " = " + (a + b) + "<br/>" +
                    "Resta: " + a + " - " + b + " = " + (a - b) + "<br/>" +
                    "Multiplicación: " + a + " * " + b + " = " + (a * b) + "<br/>" +
                    "División: " + a + " / " + b + " = " + (a / b) + "<br/>" +
                    "Módulo: " + a + " % " + b + " = " + (a % b) + "<br/>";

    document.getElementById('result').innerHTML = result;
}

