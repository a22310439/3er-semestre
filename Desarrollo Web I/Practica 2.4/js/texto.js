document.addEventListener("DOMContentLoaded", function() {
    const form = document.getElementById('textoForm');
    form.onsubmit = function(event) {
        event.preventDefault();

        const text = document.getElementById('textoInput').value;
        if (!text) {
            alert('Por favor, inserte algún texto.');
            return;
        }

        const words = text.trim().split(/\s+/);
        const numberOfWords = words.length;
        const firstWord = words[0];
        const lastWord = words[words.length - 1];
        const reversedWords = words.slice().reverse().join(', ');
        const sortedWords = words.slice().sort().join(', ');
        const sortedWordsDesc = words.slice().sort((a, b) => b.localeCompare(a)).join(', ');

        const resultContent = `
            Número de palabras: ${numberOfWords}<br/>
            Primera palabra: ${firstWord}<br/>
            Última palabra: ${lastWord}<br/>
            Palabras en orden inverso: ${reversedWords}<br/>
            Palabras ordenadas de la A a la Z: ${sortedWords}<br/>
            Palabras ordenadas de la Z a la A: ${sortedWordsDesc}<br/>
        `;

        document.getElementById('result').innerHTML = resultContent;
        // Open new window and show results
        // const resultWindow = window.open("", "_blank");
        // resultWindow.document.write(`<h1>Resultados del Análisis de Texto</h1><p>${resultContent}</p>`);
        // resultWindow.document.close();
    };
});
