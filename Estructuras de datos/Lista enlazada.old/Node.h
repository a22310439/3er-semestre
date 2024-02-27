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

    T getValue(){ 
        return value; 
    }
    void setValue(T value) {
        this->value = value;
    }

    Node* getNext(){ 
        return next;
    }
    void setNext(Node* next){
        this->next = next;
    }
};
