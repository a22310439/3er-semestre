#pragma once
#include <iostream>
#include "List.h"
#include "Validador.h"


template <typename t>
class Menu {
public:
    Menu(List<t>& list){}
    // Funcion para caracteres y cadenas de texto
    void menuCaracteres(List<t>& list){
        Validador<t>& validador = list.getValidador();
        const int EXIT_CODE = 0;
        int opcion, posicion;
        t valor;
        do {
            std::cout << "\n1) Agregar un valor al inicio de la lista\n" <<
                    "2) Agregar un valor al final de la lista\n" <<
                    "3) Insertar un valor en una posicion dada\n" <<
                    "4) Eliminar un valor\n" <<
                    "5) Imprimir la lista\n" <<
                    "0) Regresar al menu principal\n\n" <<
                    "Opcion: ";
            std::cin >> opcion;
            validador.validarOpcion(opcion, 5);
            switch (opcion) {
                case 1: {
                    std::cout << "\nIngresa el valor a agregar: ";
                    std::cin >> valor;
                    list.prepend(valor);
                    break;
                }
                case 2: {
                    std::cout << "\nIngresa el valor a agregar: ";
                    std::cin >> valor;
                    list.append(valor);
                    break;
                }
                case 3: {
                    std::cout << "\nIngresa el valor a agregar: ";
                    std::cin >> valor;
                    std::cout << "\nIngresa la posicion a insertar: ";
                    std::cin >> posicion;
                    validador.validarOpcion(posicion, list.getSize());
                    list.insert(valor, posicion);
                    break;
                }
                case 4: {
                    std::cout << "\nIngresa la posicion a eliminar (Ingresa -1 para cancelar): ";
                    std::cin >> posicion;
                    if(posicion == -1) {
                        std::cout << "\nCancelando eliminacion" << endl;
                        break;
                    }
                    validador.validarOpcion(posicion, list.getSize());
                    list.remove(posicion);
                    break;
                }
                case 5: {
                    std::cout << string(list) << endl;
                    break;
                }
                case EXIT_CODE: {
                    std::string respuesta;
                    std::cout << "\nLa lista sera eliminada, ¿Regresar al menu principal? (si/no): ";
                    std::cin >> respuesta;
                    std::cout << endl;
                    while(respuesta != "si" && respuesta != "no") {
                        std::cout << "\nRespuesta no valida, intentalo de nuevo: ";
                        std::cin >> respuesta;
                        std::cout << endl;
                    }
                    if(respuesta == "si"){
                        std::cout << "\nRegresando al menu principal\n\n";
                        break;
                    }
                    opcion++;
                    break;
                }
            }
        }while (opcion != EXIT_CODE);
    }
    //Funcion para numeros enteros y con decimales
    void menuNumeros(List<t>& list){
        Validador<t>& validador = list.getValidador();
        int opcion, posicion;
        const int EXIT_CODE = 0;
        t valor;
        do {
            std::cout << "\n1) Agregar un valor al inicio de la lista\n" <<
                    "2) Agregar un valor al final de la lista\n" <<
                    "3) Insertar un valor en una posicion dada\n" <<
                    "4) Eliminar un valor\n" <<
                    "5) Imprimir todos los valores de la lista sumados\n" <<
                    "6) Sumar 1 a todos los valores de la lista\n" <<
                    "7) Sumar un valor a todos los elementos de la lista\n" <<
                    "8) Imprimir la lista\n" <<
                    "0) Salir\n\n" <<
                    "Opcion: ";
            std::cin >> opcion;
            validador.validarOpcion(opcion, 8);
            switch (opcion) {
                case 1: {
                    std::cout << "\nIngresa el valor a agregar: ";
                    std::cin >> valor;
                    validador.validarValor(valor);
                    list.prepend(valor);
                    break;
                }
                case 2: {
                    std::cout << "\nIngresa el valor a agregar: ";
                    std::cin >> valor;
                    validador.validarValor(valor);
                    list.append(valor);
                    break;
                }
                case 3: {
                    std::cout << "\nIngresa el valor a agregar: ";
                    std::cin >> valor;
                    validador.validarValor(valor);
                    std::cout << "\nIngresa la posicion a insertar: ";
                    std::cin >> posicion;
                    validador.validarOpcion(posicion, list.getSize());
                    list.insert(valor, posicion);
                    break;
                }
                case 4: {
                    std::cout << "\nIngresa la posicion a eliminar (ingresa '-1' para cancelar): ";
                    std::cin >> posicion;
                    validador.validarValor(posicion);
                    if(posicion == -1) {
                        break;
                    }
                    validador.validarOpcion(posicion, list.getSize());
                    list.remove(posicion);
                    break;
                }
                case 5: {
                    if(list.listaVacia()){
                        break;
                    }
                    std::cout << "\nLa suma de todos los valores de la lista es: " << t(list) << endl;
                    break;
                }
                case 6: {
                    if(list.listaVacia()){
                        break;
                    }
                    ++list;
                    std::cout << "\nSe ha sumado 1 a todos los valores de la lista" << endl;
                    break;
                }
                case 7: {
                    if(list.listaVacia()){
                        break;
                    }
                    std::cout << "\nIngresa el valor a sumar: ";
                    std::cin >> valor;
                    validador.validarValor(valor);
                    list += valor;
                    std::cout << "\nSe ha sumado " << valor << " a todos los valores de la lista" << endl;
                    break;
                }
                case 8: {
                    list.print();
                    break;
                }
                case EXIT_CODE: {
                    std::string respuesta;
                    std::cout << "\nLa lista sera eliminada, ¿Regresar al menu principal? (si/no): ";
                    std::cin >> respuesta;
                    std::cout << endl;
                    while(respuesta != "si" && respuesta != "no") {
                        std::cout << "\nRespuesta no valida, intentalo de nuevo: ";
                        std::cin >> respuesta;
                    }
                    if(respuesta == "si"){
                        std::cout << "\nRegresando al menu principal\n\n";
                        break;
                    }
                    opcion++;
                    break;
                }
            }
        }while (opcion != EXIT_CODE);
    }
};