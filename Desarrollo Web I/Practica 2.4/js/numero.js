document.addEventListener("DOMContentLoaded", function() {
    const form = document.getElementById('numberForm');
    form.onsubmit = function(event) {
        event.preventDefault();

        const number = Number(document.getElementById('number').value);
        const message = document.getElementById('message');

        if (isNaN(number) || number < 2) {
            message.textContent = "Por favor, ingrese un número válido mayor que 1.";
            return;
        }

        const primes = new Array(number + 1).fill(true);
        primes[0] = primes[1] = false; 

        for (let i = 2; i * i <= number; i++) {
            if (primes[i]) {
                for (let j = i * i; j <= number; j += i) {
                    primes[j] = false;
                }
            }
        }

        const primeNumbers = [];
        for (let i = 2; i <= number; i++) {
            if (primes[i]) {
                primeNumbers.push(i);
            }
        }
        
        message.textContent = primeNumbers.length > 0 ? 
            `Números primos hasta ${number}: ` + primeNumbers.join(", ") :
            `No hay números primos disponibles hasta ${number}.`;
    };
});
