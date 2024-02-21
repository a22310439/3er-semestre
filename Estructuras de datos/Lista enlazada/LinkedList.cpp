// Ordenar en archivos (headers)
// 
#include <iostream>

template <typename t>
void validarValor(t& valor);

using namespace std;

const int EXIT_CODE = 0;

template <typename t>
class Node {
public:
    t value;
    Node* next;
    Node() {
        this->next = nullptr;
    }
    Node(t value) {
        this->value = value;
        this->next = nullptr;
    }
};

template <typename t>
class List {
private:
    Node<t>* head;
    int size;
public:
    List<t>() {
        head = nullptr;
        size = 0;
    }
    //Verificar el tamaño de la lista
    int Size(){
        return size;
    }
    // Agregar un valor al final
    void append(t value) {
        Node<t>* newNode = new Node<t>(value);
        if (head == nullptr) {
            head = newNode;
        }else {
            Node<t>* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }
    // Agregar un valor al inicio
    void prepend(t value) {
        Node<t>* newNode = new Node<t>(value);
        newNode->next = head;
        head = newNode;
        size++;
    }
    // Insertar un valor
    void insert(t value, int pos) {
        //Verificar que la posición no sea negativa
        if (pos < 0) {
            cout << "La posicion no puede ser negativa." << endl;
            return;
        }
        Node<t>* newNode = new Node<t>(value); 
        if (pos == 0) {             // Si la posicion es 0, usar prepend
            prepend(value);
        }else if(pos >= Size()) {   //Si la posicion es mayor o igual al tamaño de la lista, usar append
            cout << "La posicion es mayor que el tamaño de la lista, " <<
            "se agregara al final de la lista." << endl;
            append(value);
        }else {                     //Si la posicion es válida, insertar el nodo en la posición dada
            Node<t>* temp = head;
            for (int i = 0; i < pos - 1; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        size++;
    }
    // Eliminar un valor
    void remove(int posicion) {
        // Verificar si la lista está vacía
        if (listaVacia()) {
            return;
        }
        // Verificar si la posición es válida
        while (posicion < 1 || posicion > Size()) {
            cout << "\nLa posicion no existe, intentalo de nuevo: " ;
            cin >> posicion;
            validarValor(posicion);
        }
        posicion--;
        // Eliminar el nodo en la posición dada
        if (posicion == 0) {
            Node<t>* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node<t>* temp = head;
            for (int i = 0; i < posicion - 1; i++) {
                temp = temp->next;
            }
            Node<t>* temp2 = temp->next;
            temp->next = temp2->next;
            delete temp2;
        }
        size--;
    }
    // Imprimir la lista
    void print() {
        Node<t>* temp = head;
        cout << endl;
        while (temp != nullptr) {
            cout << temp->value;
            if(temp->next != nullptr) {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }
    //Overload del operador int
    operator int() {
        int suma = 0;
        Node<t>* temp = head;
        while(temp != nullptr) {
            suma += temp->value;
            temp = temp->next;
        }
        return suma;
    }
    //Overload del operador float
    operator float() {
        float suma = 0;
        Node<t>* temp = head;
        while(temp != nullptr) {
            suma += temp->value;
            temp = temp->next;
        }
        return suma;
    }
    //Overload del operador string
    operator string() {
        string suma = "";
        Node<t>* temp = head;
        while(temp != nullptr) {
            suma += temp->value;
            if(temp->next != nullptr) {
                suma += ", ";
            }
            temp = temp->next;
        }
        return suma;
    }
    //Overload del operador ++
    List& operator ++() {
        Node<t>* temp = head;
        while(temp != nullptr) {
            temp->value += 1;
            temp = temp->next;
        }
        return *this;
    }
    //Overload del operador - (int)
    List operator +=(int valor) { //Sumar un valor (int) a todos los elementos de la lista
        Node<t>* temp = head;
        while (temp != nullptr) {
            temp->value += valor;
            temp = temp->next;
        }
        return *this;
    }
    //Overload del operador - (float)
    List operator+=(float valor) { //Sumar un valor (float) a todos los elementos de la lista
        Node<t>* temp = head;
        while (temp != nullptr) {
            temp->value += valor;
            temp = temp->next;
        }
        return *this;
    }

    //Verificar si la lista está vacía
    bool listaVacia() {
        if(head == nullptr) {
            cout << "\nLa lista esta vacia." << endl;
            return true;
        }
        return false;
    }
    //Destructor
    ~List() {
        Node<t>* temp = head;
        while (temp != nullptr) {
            Node<t>* temp2 = temp;
            temp = temp->next;
            delete temp2;
        }
    }
};

// Validar que el valor ingresado sea del tipo correcto
template <typename t>
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

// Función para caracteres y cadenas de texto
template <typename t>
void menuCaracteres(List<t>& list) {
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
        validarOpcion(opcion, 5);
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
                validarValor(posicion);
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
void menuNumeros(List<t>& list) {
    int opcion, posicion;
    t valor;
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
        validarOpcion(opcion, 8);
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
                validarValor(posicion);
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


int main() {
    int opcion;
    do{
        cout << "De que tipo va a ser la lista?\n" <<
            "1) Numeros enteros\n" <<
            "2) Numeros con decimales\n" <<
            "3) Cadenas de texto\n"
            "0) Salir\n\n" <<
            "Opcion: ";
        cin >> opcion;
        validarOpcion(opcion, 3);

        switch (opcion) {
            case 1: {
                List<int> list;
                menuNumeros<int>(list);
                break;
            }
            case 2: {
                List<float> list;
                menuNumeros<float>(list);
                break;
            }
            case 3: {
                List<string> list;
                menuCaracteres<string>(list);
                break;
            }
            case EXIT_CODE: {
                cout << "\nSaliendo del programa\n\n";
                break;
            }
        }
    }while(opcion != EXIT_CODE);
    
    return 0;
}