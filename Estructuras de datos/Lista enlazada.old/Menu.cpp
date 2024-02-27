#include <iostream>
#include "Menu.h"
#include "Validador.h"

using namespace std;

template <typename t>
Menu<t>::Menu(List<t>& list) {}

// Función para caracteres y cadenas de texto
template <typename t>
void menuCaracteres(List<t> &list) {
    const int EXIT_CODE = 0;
    Validador<int> validador;
    int opcion, posicion;
    t valor;
    do {
        cout << "\n1) Agregar un valor al inicio de la lista\n" <<
                "2) Agregar un valor al final de la lista\n" <<
                "3) Insertar un valor en una posicion dada\n" <<
                "4) Eliminar un valor\n" <<
                "5) Imprimir la lista\n" <<
                "0) Regresar al menu principal\n\n" <<
                "Opcion: ";
        cin >> opcion;
        validador.validarOpcion(opcion, 5);
        switch (opcion) {
            case 1: {
                cout << "\nIngresa el valor a agregar: ";
                cin >> valor;
                validarValor(valor);
                list.prepend(valor);
                break;
            }
            case 2: {
                cout << "\nIngresa el valor a agregar: ";
                cin >> valor;
                validarValor(valor);
                list.append(valor);
                break;
            }
            case 3: {
                cout << "\nIngresa el valor a agregar: ";
                cin >> valor;
                validarValor(valor);
                cout << "\nIngresa la posicion a insertar: ";
                cin >> posicion;
                list.insert(valor, posicion);
                break;
            }
            case 4: {
                cout << "\nIngresa la posicion a eliminar (Ingresa -1 para cancelar): ";
                cin >> posicion;
                if(posicion == -1) {
                    cout << "\nCancelando eliminacion" << endl;
                    break;
                }
                validador.validarValor(posicion);
                list.remove(posicion);
                break;
            }
            case 5: {
                cout << string(list) << endl;
                break;
            }
            case EXIT_CODE: {
                string respuesta;
                cout << "\nLa lista sera eliminada, ¿Regresar al menu principal? (si/no): ";
                cin >> respuesta;
                cout << endl;
                while(respuesta != "si" && respuesta != "no") {
                    cout << "\nRespuesta no valida, intentalo de nuevo: ";
                    cin >> respuesta;
                }
                if(respuesta == "si"){
                    cout << "\nRegresando al menu principal\n\n";
                    break;
                }
                opcion++;
                break;
            }
        }
    }while (opcion != EXIT_CODE);
}

template <typename t>
void menuNumeros(List<t> &list){
    int opcion, posicion;
    const int EXIT_CODE = 0;
    t valor;
    Validador<int> validador;
    do {
        cout << "\n1) Agregar un valor al inicio de la lista\n" <<
                "2) Agregar un valor al final de la lista\n" <<
                "3) Insertar un valor en una posicion dada\n" <<
                "4) Eliminar un valor\n" <<
                "5) Imprimir todos los valores de la lista sumados\n" <<
                "6) Sumar 1 a todos los valores de la lista\n" <<
                "7) Sumar un valor a todos los elementos de la lista\n" <<
                "8) Imprimir la lista\n" <<
                "0) Salir\n\n" <<
                "Opcion: ";
        cin >> opcion;
        validador.validarOpcion(opcion, 8);
        switch (opcion) {
            case 1: {
                cout << "\nIngresa el valor a agregar: ";
                cin >> valor;
                validarValor(valor);
                list.prepend(valor);
                break;
            }
            case 2: {
                cout << "\nIngresa el valor a agregar: ";
                cin >> valor;
                validarValor(valor);
                list.append(valor);
                break;
            }
            case 3: {
                cout << "\nIngresa el valor a agregar: ";
                cin >> valor;
                validarValor(valor);
                cout << "\nIngresa la posicion a insertar: ";
                cin >> posicion;
                list.insert(valor, posicion);
                break;
            }
            case 4: {
                cout << "\nIngresa la posicion a eliminar (ingresa '-1' para cancelar): ";
                cin >> posicion;
                if(posicion == -1) {
                    break;
                }
                validador.validarValor(posicion);
                list.remove(posicion);
                break;
            }
            case 5: {
                if(list.listaVacia()){
                    break;
                }
                cout << "\nLa suma de todos los valores de la lista es: " << t(list) << endl;
                break;
            }
            case 6: {
                if(list.listaVacia()){
                    break;
                }
                ++list;
                cout << "\nSe ha sumado 1 a todos los valores de la lista" << endl;
                break;
            }
            case 7: {
                if(list.listaVacia()){
                    break;
                }
                cout << "\nIngresa el valor a sumar: ";
                cin >> valor;
                validarValor(valor);
                list += valor;
                cout << "\nSe ha sumado " << valor << " a todos los valores de la lista" << endl;
                break;
            }
            case 8: {
                list.print();
                break;
            }
            case EXIT_CODE: {
                string respuesta;
                cout << "\nLa lista sera eliminada, ¿Regresar al menu principal? (si/no): ";
                cin >> respuesta;
                cout << endl;
                while(respuesta != "si" && respuesta != "no") {
                    cout << "\nRespuesta no valida, intentalo de nuevo: ";
                    cin >> respuesta;
                }
                if(respuesta == "si"){
                    cout << "\nRegresando al menu principal\n\n";
                    break;
                }
                opcion++;
                break;
            }
        }
    }while (opcion != EXIT_CODE);
}