#pragma once
#include <iostream>
#include "Node.h"
#include "Validador.h"

using namespace std;

template <typename t>
class List {
private:
    Validador<t> validador;
    Node<t>* head;
    int size;
public:
    //Constructor
    List(){
        validador = Validador<t>();
        head = nullptr;
        size = 0;
    }
    //Obtener el validador
    Validador<t>& getValidador(){
        return validador;
    }
    //Obtener el primer nodo
    Node<t>* getHead(){
        return head;
    }
    //Verificar el tamaño de la lista
    int getSize(){
        return size;
    }
    // Agregar un valor al final
    void append(t value){
        Node<t>* newNode = new Node<t>(value);
        if (head == nullptr) {
            head = newNode;
        }else {
            Node<t>* temp = head;
            while (temp->getNext() != nullptr) {
                temp = temp->getNext();
            }
            temp->setNext(newNode);
        }
        size++;
    }
    // Agregar un valor al inicio
    void prepend(t value){
        Node<t>* newNode = new Node<t>(value);
        newNode->setNext(head);
        head = newNode;
        size++;
    }
    // Insertar un valor
    void insert(t value, int pos){
        //Verificar que la posición no sea negativa
        if (pos < 0) {
            std::cout << "La posicion no puede ser negativa." << endl;
            return;
        }
        Node<t>* newNode = new Node<t>(value); 
        if (pos == 0) {             // Si la posicion es 0, usar prepend
            prepend(value);
        }else if(pos >= getSize()) {   //Si la posicion es mayor o igual al tamaño de la lista, usar append
            std::cout << "La posicion es mayor que el tamaño de la lista, " <<
            "se agregara al final de la lista." << endl;
            append(value);
        }else {                     //Si la posicion es válida, insertar el nodo en la posición dada
            Node<t>* temp = head;
            for (int i = 0; i < pos - 1; i++) {
                temp = temp->getNext();
            }
            newNode->setNext(temp->getNext());
            temp->setNext(newNode);
        }
        size++;
    }
    // Eliminar un valor
    void remove(int posicion){
        // Verificar si la lista está vacía
        if (listaVacia()) {
            return;
        }
        // Verificar si la posición es válida
        while (posicion < 1 || posicion > getSize()) {
            std::cout << "\nLa posicion no existe, intentalo de nuevo: " ;
            std::cin >> posicion;
            validador.validarValor(posicion);
        }
        posicion--;
        // Eliminar el nodo en la posición dada
        if (posicion == 0) {
            Node<t>* temp = head;
            head = head->getNext();
            delete temp;
        } else {
            Node<t>* temp = head;
            for (int i = 0; i < posicion - 1; i++) {
                temp = temp->getNext();
            }
            Node<t>* temp2 = temp->getNext();
            temp->setNext(temp2->getNext());
            delete temp2;
        }
        size--;
    }
    // Imprimir la lista
    void print(){
        std::cout << endl;
        Node<t>* temp = head;
        while (temp != nullptr) {
            std::cout << temp->getValue();
            if(temp->getNext() != nullptr) {
                std::cout << " -> ";
            }
            temp = temp->getNext();
        }
        std::cout << endl;
    }
    //Overload del operador int
    operator int(){
        int suma = 0;
        Node<t>* temp = head;
        while(temp != nullptr) {
            suma += temp->getValue();
            temp = temp->getNext();
        }
        return suma;
    }
    //Overload del operador float
    operator float(){
        float suma = 0;
        Node<t>* temp = head;
        while(temp != nullptr) {
            suma += temp->getValue();
            temp = temp->getNext();
        }
        return suma;
    }
    //Overload del operador string
    operator string(){
        string suma = "";
        Node<t>* temp = head;
        while(temp != nullptr) {
            suma += temp->getValue();
            if(temp->getNext() != nullptr) {
                suma += ", ";
            }
            temp = temp->getNext();
        }
        return suma;
    }
    //Overload del operador ++
    List& operator ++(){
        Node<t>* temp = head;
        while(temp != nullptr) {
            temp->setValue(temp->getValue() + 1);
            temp = temp->getNext();
        }
        return *this;
    }
    //Overload del operador int
    List& operator +=(int valor){    //Sumar un valor (int) a todos los elementos de la lista
        Node<t>* temp = head;
        while (temp != nullptr) {
            temp->setValue(temp->getValue() + valor);
            temp = temp->getNext();
        }
        return *this;
    }
    //Overload del operador float
    List& operator +=(float valor){ //Sumar un valor (float) a todos los elementos de la lista
        Node<t>* temp = head;
        while (temp != nullptr) {
            temp->setValue(temp->getValue() + valor);
            temp = temp->getNext();
        }
        return *this;
    }
    //Verificar si la lista está vacía
    bool listaVacia(){
        if(head == nullptr) {
            std::cout << "\nLa lista esta vacia." << endl;
            return true;
        }
        return false;
    }
    //Destructor
    ~List(){
        Node<t>* temp = head;
        while (temp != nullptr) {
            Node<t>* temp2 = temp;
            temp = temp->getNext();
            delete temp2;
        }
    }
};