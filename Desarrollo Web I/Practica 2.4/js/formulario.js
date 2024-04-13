document.addEventListener("DOMContentLoaded", function() {
    const form = document.getElementById('registrationForm');
    form.addEventListener('submit', function(event) {
        event.preventDefault();

        const password = document.getElementById('password').value;
        const confirmPassword = document.getElementById('confirmPassword').value;
        const email = document.getElementById('email').value;
        const street = document.getElementById('street').value;
        const interiorNumber = document.getElementById('interiorNumber').value;
        const colony = document.getElementById('colony').value;
        const postalCode = document.getElementById('postalCode').value;

        if (password !== confirmPassword) {
            alert("Las contraseñas no coinciden.");
            return;
        }

        if (!email.includes('@') || !email.includes('.')) {
            alert("El correo electrónico no es válido. Asegúrate de incluir '@' y '.'");
            return;
        }

        if (street.includes('@') || street.includes('!')) {
            alert("La calle contiene caracteres no válidos.");
            return;
        }

        if (interiorNumber !== "" && (isNaN(interiorNumber) || interiorNumber.trim() === "")) {
            alert("El número interior debe ser numérico o estar vacío.");
            return;
        }

        if (colony.split('').some(char => '0123456789'.includes(char))) {
            alert("La colonia debe contener sólo letras y espacios.");
            return;
        }

        if (postalCode.length !== 5 || isNaN(postalCode)) {
            alert("El Código Postal debe ser un número de 5 dígitos.");
            return;
        }
        
        alert("Formulario enviado con éxito!");
        
    });
});
