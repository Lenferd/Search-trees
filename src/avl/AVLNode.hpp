#ifndef AVL_NODE_H
#define AVL_NODE_H

#include <algorithm>
#include <string>

template<typename Key, typename T>
struct AVLNode {
public:
    Key key;
    T value;
    unsigned int height;
    AVLNode<Key, T>* left;
    AVLNode<Key, T>* right;

    explicit AVLNode(Key k, T v);

    ~AVLNode();

    void update_values();
    int balance_factor();
};

template<typename Key, typename T>
AVLNode<Key, T>::AVLNode(Key k, T v) {
    key = k;
    value = v;
    left = right = nullptr;
    height = 1;
}

template<typename Key, typename T>
AVLNode<Key, T>::~AVLNode() {
    delete left;
    delete right;
}

template<typename Key, typename T>
void AVLNode<Key, T>::update_values() {
    height = std::max(left ? left->height : 0, right ? right->height : 0) + 1;
}

template<typename Key, typename T>
int AVLNode<Key, T>::balance_factor() {
    return (right ? right -> height : 0) - (left ? left->height : 0);
}

#endif //AVL_NODE_H
