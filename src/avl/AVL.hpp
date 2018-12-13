#ifndef AVL_HPP
#define AVL_HPP

#include <unistd.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "AVLNode.hpp"

template <typename Key, typename T>
class AVLTree {
public:
    AVLTree();
    ~AVLTree();

    void insert(Key key, T value);
    void erase(Key key);

    T* find(Key key);

private:
    AVLNode<Key, T>* head;
    AVLNode<Key, T>* insert(AVLNode<Key, T>* node, Key key, T value);
    AVLNode<Key, T>* find_min(AVLNode<Key, T>* node);
    AVLNode<Key, T>* remove_min(AVLNode<Key, T>* node);
    AVLNode<Key, T>* remove(AVLNode<Key, T>* node, Key key);
    AVLNode<Key, T>* find(AVLNode<Key, T>* node, Key key);

    AVLNode<Key, T>* rotate_left(AVLNode<Key, T>* node);
    AVLNode<Key, T>* rotate_right(AVLNode<Key, T>* node);
    AVLNode<Key, T>* balance(AVLNode<Key, T>* node);
};

template <typename Key, typename T>
AVLTree<Key, T>::AVLTree() {
    head = nullptr;
}

template <typename Key, typename T>
AVLTree<Key, T>::~AVLTree(){
    if (head) {
        delete head;
    }
}

template <typename Key, typename T>
void AVLTree<Key, T>::insert(Key key, T value) {
    head = insert(head, key, value);
}

template <typename Key, typename T>
void AVLTree<Key, T>::erase(Key key) {
    head = remove(head, key);
}

template <typename Key, typename T>
T* AVLTree<Key, T>::find(Key key) {
    AVLNode<Key, T>* result = find(head, key);
    return result ? &result->value : nullptr;
}

template <typename Key, typename T>
AVLNode<Key, T> *AVLTree<Key, T>::insert(AVLNode<Key, T> *node, Key key, T value) {
    if (!node) return new AVLNode<Key, T>(key, value);
    if (key < node->key) {
        node->left = insert(node->left, key, value);
    } else {
        node->right = insert(node->right, key, value);
    }
    return balance(node);

}

template <typename Key, typename T>
AVLNode<Key, T> *AVLTree<Key, T>::find_min(AVLNode<Key, T>* node) {
    return node->left ? find_min(node->left) : node;
}

template <typename Key, typename T>
AVLNode<Key, T> *AVLTree<Key, T>::remove_min(AVLNode<Key, T> *node) {
    if (!node->left) {
        return node->right;
    }
    node->left = remove_min(node->left);
    return balance(node);
}

template <typename Key, typename T>
AVLNode<Key, T> *AVLTree<Key, T>::remove(AVLNode<Key, T> *node, Key key) {
    if (!node) {
        return nullptr;
    }
    if (key < node->key) {
        node->left = remove(node->left, key);
    } else if (key > node->key) {
        node->right = remove(node->right, key);
    } else {
        AVLNode<Key, T>* left = node->left;
        AVLNode<Key, T>* right = node->right;
        node->left = nullptr;
        node->right = nullptr;
        delete node;
        if (!right) {
            return left;
        }
        AVLNode<Key, T>* min = find_min(right);
        min->right = remove_min(right);
        min->left = left;
        return balance(min);
    }
    return balance(node);
}

template <typename Key, typename T>
AVLNode<Key, T> *AVLTree<Key, T>::find(AVLNode<Key, T> *node, Key key) {
    if (!node) {
        return nullptr;
    }
    if (key < node->key) {
        return find(node->left, key);
    }
    if (key > node->key) {
        return find(node->right, key);
    }
    return node;
}

template <typename Key, typename T>
AVLNode<Key, T>* AVLTree<Key, T>::rotate_left(AVLNode<Key, T>* node) {
    AVLNode<Key, T>* p = node->right;
    node->right = p->left;
    p->left = node;
    node->update_values();
    p->update_values();
    return p;
}

template <typename Key, typename T>
AVLNode<Key, T> *AVLTree<Key, T>::rotate_right(AVLNode<Key, T>* node) {
    AVLNode<Key, T>* p = node->left;
    node->left = p->right;
    p->right = node;
    node->update_values();
    p->update_values();
    return p;
}

template <typename Key, typename T>
AVLNode<Key, T> *AVLTree<Key, T>::balance(AVLNode<Key, T>* node) {
    node->update_values();
    int bf = node->balance_factor();
    if (bf == 2) {
        if (node->right->balance_factor() < 0) {
            node->right = rotate_right(node->right);
        }
        return rotate_left(node);
    }
    if (bf == -2) {
        if (node->left->balance_factor() > 0) {
            node->left = rotate_left(node->left);
        }
        return rotate_right(node);
    }
    return node;
}

#endif // AVL_HPP
