#pragma once
#include <iostream>
#include "NodeTree.h"
#include "Validador.h"

template <typename t>
class BTree {
private:
    NodeTree<t>* root;
    Validador<t> validador;
    // Método auxiliar para liberar memoria de forma recursiva
    void destroyTree(NodeTree<t>* node) {
        if (node != nullptr) {
            destroyTree(node->getLeft());
            destroyTree(node->getRight());
            delete node;
        }
    }

public:
    BTree() : root(nullptr){
        validador = Validador<t>();
    }

    NodeTree<t>* getRoot() {
        return root;
    }

    Validador<t>& getValidador() {
        return validador;
    }

    void insert(t value) {
        NodeTree<t>* newNode = new NodeTree<t>(value);
        if (root == nullptr) {
            root = newNode;
            return;
        }

        NodeTree<t>* temp = root;
        while (true) {
            if (value < temp->getValue()) {
                if (temp->getLeft() == nullptr) {
                    temp->setLeft(newNode);
                    break;
                } else {
                    temp = temp->getLeft();
                }
            } else {
                if (temp->getRight() == nullptr) {
                    temp->setRight(newNode);
                    break;
                } else {
                    temp = temp->getRight();
                }
            }
        }
    }

    void printPreOrder(NodeTree<t>* node) {
        if (node != nullptr) {
            std::cout << node->getValue() << " ";
            printPreOrder(node->getLeft());
            printPreOrder(node->getRight());
        }
    }

    void printPostOrder(NodeTree<t>* node) {
        if (node != nullptr) {
            printPostOrder(node->getLeft());
            printPostOrder(node->getRight());
            std::cout << node->getValue() << " ";
        }
    }

    void printInOrder(NodeTree<t>* node) {
        if (node != nullptr) {
            printInOrder(node->getLeft());
            std::cout << node->getValue() << " ";
            printInOrder(node->getRight());
        }
    }

    ~BTree() {
        destroyTree(root);
    }
};
