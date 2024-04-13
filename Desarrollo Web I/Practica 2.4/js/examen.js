document.addEventListener("DOMContentLoaded", function() {
    const form = document.getElementById('quizForm');
    const resultDiv = document.getElementById('result');
    form.onsubmit = function(event) {
        event.preventDefault();
        let score = 0;
        const answers = {
            q1: "Paris",
            q2: "Jupiter",
            q3: "Oxigeno"
        };
        const userAnswers = {
            q1: form["q1"].value,
            q2: form["q2"].value,
            q3: form["q3"].value
        };
        let resultHTML = "<h3>Resultados:</h3>";
        Object.keys(answers).forEach(function(key, index) {
            if (userAnswers[key] === answers[key]) {
                score++;
                resultHTML += `<p>Pregunta ${index+1}: Correcto!</p>`;
            } else {
                resultHTML += `<p>Pregunta ${index+1}: Incorrecto (Respuesta correcta: ${answers[key]})</p>`;
            }
        });
        resultHTML += `<p>Calificación: ${score}/${Object.keys(answers).length}</p>`;
        resultDiv.innerHTML = resultHTML;
    };
});
