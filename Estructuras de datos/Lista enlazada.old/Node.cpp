#include<iostream>
#include "Node.h"

using namespace std;

template <typename T>
Node<T>::Node() {
    this->next = nullptr;
}

template <typename T>
Node<T>::Node(T value) {
    this->value = value;
    this->next = nullptr;
}