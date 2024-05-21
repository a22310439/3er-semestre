#include <iostream>

int main() {
    int matriz[6][6]; // Matriz original
    int output[4][4]; // Matriz de salida
    int relojMenor;

    // Inicializar la matriz con numeros aleatorios
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
            //matriz[i][j] = 1;
            matriz[i][j] = rand() % 201 - 100;
        }
    }

    relojMenor = matriz[0][0] + matriz[0][1] + matriz[0][2] + matriz[1][1] + matriz[2][0] + matriz[2][1] + matriz[2][2];

    // Mostrar la matriz
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Procesar la matriz
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            output[i][j] = matriz[i][j] + matriz[i][j + 1] + matriz[i][j + 2] + 
            matriz[i + 1][j + 1] + matriz[i + 2][j] + matriz[i + 2][j + 1] + matriz[i + 2][j + 2];
            if(output[i][j] < relojMenor) {
                relojMenor = output[i][j];
            }
        }
    }

    // Mostrar la matriz de salida
    std::cout << std::endl;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            std::cout << output[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Mostrar el reloj de arena menor
    std::cout << std::endl << "El reloj de arena menor es: " << relojMenor << std::endl;

    return 0;
}