#pragma once
#include<iostream>

using namespace std;

template <typename t>
class Validador {
public:
    Validador<t>() {}
    // Validar que el valor ingresado sea del tipo correcto
    void validarValor(t& valor){
        while(cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "\nValor no valido, intentalo de nuevo: ";
            cin >> valor;
        }
    }
    // Validar que la opción ingresada sea del tipo correcto
    void validarOpcion(int& opcion, int max) {
        while(cin.fail() || opcion < 0 || opcion > max) {
            cin.clear();
            cin.ignore();
            cout << "\nOpcion no valida, intentalo de nuevo: ";
            cin >> opcion;
        }
    }
};