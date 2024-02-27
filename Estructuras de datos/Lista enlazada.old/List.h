#pragma once
#include <iostream>
#include "Node.h"
#include "Validador.h"

using namespace std;

template <typename t>
class List {
private:
    Node<t>* head;
    int size;
public:
    List(Validador<t>& validador);
    //Verificar el tamaño de la lista
    int Size();
    // Agregar un valor al final
    void append(t value);
    // Agregar un valor al inicio
    void prepend(t value);
    // Insertar un valor
    void insert(t value, int pos);
    // Eliminar un valor
    void remove(int posicion) ;
    // Imprimir la lista
    void print();
    //Overload del operador int
    operator int();
    //Overload del operador float
    operator float();
    //Overload del operador string
    operator string();
    //Overload del operador ++
    List& operator ++();
    //Overload del operador - (int)
    List operator +=(int valor);
    //Overload del operador - (float)
    List operator +=(float valor);
    //Verificar si la lista está vacía
    bool listaVacia(Node<t>* head);
    //Destructor
    ~List();
};