document.addEventListener("DOMContentLoaded", function() {
    const form = document.getElementById('registrationForm');
    form.onsubmit = function(event) {
        event.preventDefault(); // Prevent form submission to server

        const username = document.getElementById('username').value;
        const password = document.getElementById('password').value;
        const confirmPassword = document.getElementById('confirmPassword').value;
        const message = document.getElementById('message');

        if (password === confirmPassword) {
            message.textContent = "Registro exitoso.";
            message.style.color = "green";
            // Here you would normally submit the form or further process the data
            console.log("Username: ", username, "Password: ", password);
            // form.submit(); // Uncomment this to submit the form once all validations pass
        } else {
            message.textContent = "Las contraseñas no coinciden.";
            message.style.color = "red";
        }
    };
});    