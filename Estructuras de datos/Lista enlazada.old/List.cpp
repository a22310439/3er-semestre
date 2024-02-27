#include<iostream>
#include "List.h"

using namespace std;

template <typename t>
List<t>::List(Validador<t>& validador) {
    head = nullptr;
    size = 0;
}

//Verificar el tamaño de la lista
template <typename t>
int List<t>::Size(){
    return size;
}

// Agregar un valor al final
template <typename t>
void List<t>::append(t value) {
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
template <typename t>
void List<t>::prepend(t value) {
    Node<t>* newNode = new Node<t>(value);
    newNode->next = head;
    head = newNode;
    size++;
}

// Insertar un valor
template <typename t>
void List<t>::insert(t value, int pos) {
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
template <typename t>
void List<t>::remove(int posicion) {
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
template <typename t>
void List<t>::print() {
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
template <typename t>
List<t>::operator int() {
    int suma = 0;
    Node<t>* temp = head;
    while(temp != nullptr) {
        suma += temp->value;
        temp = temp->next;
    }
    return suma;
}

//Overload del operador float
template <typename t>
List<t>::operator float() {
    float suma = 0;
    Node<t>* temp = head;
    while(temp != nullptr) {
        suma += temp->value;
        temp = temp->next;
    }
    return suma;
}

//Overload del operador string
template <typename t>
List<t>::operator string() {
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
template <typename t>
List<t>& List<t>::operator ++() {
    Node<t>* temp = head;
    while(temp != nullptr) {
        temp->value += 1;
        temp = temp->next;
    }
    return *this;
}
//Overload del operador - (int)
template <typename t>
List<t> List<t>::operator +=(int valor) { //Sumar un valor (int) a todos los elementos de la lista
    Node<t>* temp = head;
    while (temp != nullptr) {
        temp->value += valor;
        temp = temp->next;
    }
    return *this;
}
//Overload del operador - (float)
template <typename t>
List<t> List<t>::operator +=(float valor) { //Sumar un valor (float) a todos los elementos de la lista
    Node<t>* temp = head;
    while (temp != nullptr) {
        temp->value += valor;
        temp = temp->next;
    }
    return *this;
}

//Verificar si la lista está vacía
template <typename t>
bool List<t>::listaVacia(Node<t>* head) {
    if(head == nullptr) {
        cout << "\nLa lista esta vacia." << endl;
        return true;
    }
    return false;
}

//Destructor
template <typename t>
List<t>::~List() {
    Node<t>* temp = head;
    while (temp != nullptr) {
        Node<t>* temp2 = temp;
        temp = temp->next;
        delete temp2;
    }
}