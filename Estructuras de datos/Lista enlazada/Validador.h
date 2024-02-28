#pragma once
#include<iostream>
#include<limits>

template <typename t>
class Validador {
public:
    // Validar que el valor ingresado sea del tipo correcto
    void validarValor(int valor){
        while(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nValor no valido, intentalo de nuevo: ";
            std::cin >> valor;
        }
    }
    // Validar que la opción ingresada sea del tipo correcto
    void validarOpcion(int& opcion, int max) {
        validarValor(opcion);
        while(opcion < 0 || opcion > max) {
            std::cout << "\nOpcion no valida, intentalo de nuevo: ";
            std::cin >> opcion;
            validarValor(opcion);
        }
    }
};
