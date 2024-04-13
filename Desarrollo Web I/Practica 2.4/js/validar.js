document.addEventListener("DOMContentLoaded", function() {
    const form = document.getElementById('registrationForm');
    form.onsubmit = function(event) {
        event.preventDefault();

        const username = document.getElementById('username').value;
        const password = document.getElementById('password').value;
        const confirmPassword = document.getElementById('confirmPassword').value;
        const message = document.getElementById('message');

        if (password === confirmPassword) {
            message.textContent = "Registro exitoso.";
            message.style.color = "green";
        } else {
            message.textContent = "Las contraseñas no coinciden.";
            message.style.color = "red";
        }
    };
});    