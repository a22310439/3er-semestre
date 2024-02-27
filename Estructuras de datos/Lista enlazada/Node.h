#pragma once
#include <iostream>

template <typename T>
class Node {
private:
    T value;
    Node* next = nullptr;
public:

    Node() = default;
    Node(T value, Node* next = nullptr) : value(value), next(next) {}

    void setValue(T value){
        this->value = value;
    }
    T getValue() const { 
        return value; 
    }

    void setNext(Node* next){
        this->next = next;
    }
    Node* getNext() const { 
        return next;
    }
};
