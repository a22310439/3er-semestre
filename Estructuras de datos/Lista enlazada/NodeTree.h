#pragma once

template <typename t>
class NodeTree {
private:
    t value;
    NodeTree* left;
    NodeTree* right;

public:
    NodeTree(t value) : value(value), left(nullptr), right(nullptr) {}

    void setValue(t value) {
        this->value = value;
    }

    t getValue() const {
        return value;
    }

    void setLeft(NodeTree* left) {
        this->left = left;
    }

    NodeTree* getLeft() const {
        return left;
    }

    void setRight(NodeTree* right) {
        this->right = right;
    }

    NodeTree* getRight() const {
        return right;
    }
};
