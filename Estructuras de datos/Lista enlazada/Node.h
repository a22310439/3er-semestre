#pragma once
#include <iostream>

template <typename t>
class Node {
private:
    t value;
    Node* next = nullptr;
public:

    Node() = default;
    Node(t value, Node* next = nullptr) : value(value), next(next) {}
    

    void setValue(t value){
        this->value = value;
    }
    t getValue() const { 
        return value; 
    }

    void setNext(Node* next){
        this->next = next;
    }
    Node* getNext() const { 
        return next;
    }
};
