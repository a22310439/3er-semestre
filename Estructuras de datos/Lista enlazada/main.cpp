#include <iostream>
#include "List.h"
#include "Menu.h"
#include "Validador.h"
#include "BTree.h"

using namespace std;

const int EXIT_CODE = 0;

int main() {
    Validador<int> validadorInt;
    int opcion;
    do{
        cout << "De que tipo va a ser la lista?\n" <<
            "1) Numeros enteros\n" <<
            "2) Numeros con decimales\n" <<
            "3) Cadenas de texto\n"
            "0) Salir\n\n" <<
            "Opcion: ";
        cin >> opcion;
        validadorInt.validarOpcion(opcion, 3);

        switch (opcion) {
            case 1: {
                List<int> list;
                Menu<int> menu(list);
                menu.menuNumeros(list);
                break;
            }
            case 2: {
                List<float> list;
                Menu<float> menu(list);
                menu.menuNumeros(list);
                break;
            }
            case 3: {
                List<string> list;
                Menu<string> menu(list);
                menu.menuCaracteres(list);
                break;
            }
            case EXIT_CODE: {
                cout << "\nSaliendo del programa\n\n";
                break;
            }
        }
    }while(opcion != EXIT_CODE);
    
    return 0;
};