#include <iostream>

using namespace std;

template <typename t>
class Node {
public:
    int value;
    Node* next;
    Node() {
        this->next = NULL;
    }
    Node(t value) {
        this->value = value;
        this->next = NULL;
    }
};

template <typename t>
class List {
private:
    Node<t>* head;
public:
    List<t>() {
        head = NULL;
    }
    void append(t value) {
        Node<t>* newNode = new Node<t>();
        newNode->value = value;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node<t>* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void prepend(t value) {
        Node<t>* newNode = new Node<t>();
        newNode->value = value;
        newNode->next = head;
        head = newNode;
    }

    void insert(t value, int pos) {
        Node<t>* newNode = new Node<t>();
        newNode->value = value;
        if (pos == 0) {
            newNode->next = head;
            head = newNode;
        }
        else {
            Node<t>* temp = head;
            for (int i = 0; i < pos - 1; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void remove(int pos) {
        if (pos == 0) {
            Node<t>* temp = head;
            head = head->next;
            delete temp;
        }
        else {
            Node<t>* temp = head;
            for (int i = 0; i < pos - 2; i++) {
                temp = temp->next;
            }
            Node<t>* temp2 = temp->next;
            temp->next = temp2->next;
            delete temp2;
        }
    }

    void print() {
        Node<t>* temp = head;
        cout << endl;
        while (temp != nullptr) {
            cout << temp->value << " - ";
            temp = temp->next;
        }
        cout << endl;
    }    

    ~List() {
        Node<t>* temp = head;
        while (temp != nullptr) {
            Node<t>* temp2 = temp;
            temp = temp->next;
            delete temp2;
        }
    }
};

template <typename t>
void funcionLista(int opcion, List<t>& list) {
    int valor, pos;
    while (opcion != 0) {
        cout << "\n1) Agregar un valor al inicio de la lista\n2) Agregar un valor al final de la lista\n3) Eliminar un valor\n4) Imprimir la lista\n0) Salir\n\nOpcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1: {
                cout << "\nIngresa el valor a agregar: ";
                cin >> valor;
                list.append(valor);
                break;
            }
            case 2: {
                cout << "\nIngresa el valor a agregar: ";
                cin >> valor;
                list.prepend(valor);
                break;
            }
            case 3: {
                cout << "\nIngresa la posicion a eliminar: ";
                cin >> pos;
                list.remove(pos);
                break;
            }
            case 4: {
                list.print();
                break;
            }
            case 0: {
                cout << "Regresando al menu principal\n\n";
                break;
            }
        }
    }
}

int main() {
    int opcion = 1;
    while (opcion != 0){
        cout << "De que tipo va a ser la lista?\n1) Numeros enteros\n2) Numeros con decimales\n3) Caracteres\n\nOpcion: ";
        cin >> opcion;
        while (opcion < 1 || opcion > 3) {
            cin.clear();
            cin.ignore();
            cout << "\nOpcion no valida, intentalo de nuevo: ";
            cin >> opcion;
        }
        switch (opcion) {
            case 1: {
                List<int> list;
                
                funcionLista(opcion, list);
                break;
            }
            case 2: {
                List<float> list;
                funcionLista(opcion, list);
                break;
            }
            case 3: {
                List<char> list;
                funcionLista(opcion, list);
                break;
            }
        }
    }
    return 0;
}