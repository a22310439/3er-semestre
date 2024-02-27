#pragma once
#include <iostream>
#include "List.h"
#include "Validador.h"

using namespace std;

template <typename t>
class Menu {
public:
    Menu(List<t>& list);
    // Funcion para caracteres y cadenas de texto
    void menuCaracteres(List<t>& list);
    //Funcion para numeros enteros y con decimales
    void menuNumeros(List<t>& list);
};