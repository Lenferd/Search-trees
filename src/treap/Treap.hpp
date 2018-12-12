#ifndef TREAP_TREE_H
#define TREAP_TREE_H

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "TreapNode.hpp"

template <typename Key, typename T>
class Treap {
public:
    Treap() = default;

    ~Treap() {
        // TODO: delete tree
    }

    void insert(Key key, T value);
    void erase(Key key);

    T* find(Key key);

private:
    TreapNode<Key, T>* root = nullptr;

    void merge(TreapNode<Key, T>*& root, TreapNode<Key, T>* left, TreapNode<Key, T>* right);
    void split(TreapNode<Key, T>* root, TreapNode<Key, T>*& left, TreapNode<Key, T>*& right, Key key);

    void insert(TreapNode<Key, T>*& root, TreapNode<Key, T>* vertex);
    void erase(TreapNode<Key, T>*& root, Key key);
    TreapNode<Key, T>* find(TreapNode<Key, T>* node, Key key);
};

template <typename Key, typename T>
void Treap<Key, T>::insert(Key key, T value) {
    insert(root, new TreapNode<Key, T>(key, value));
}

template <typename Key, typename T>
void Treap<Key, T>::erase(Key key) {
    erase(root, key);
}

template <typename Key, typename T>
T* Treap<Key, T>::find(Key key) {
    TreapNode<Key, T>* result = find(root, key);
    return result ? &result->value : nullptr;
}

template <typename Key, typename T>
void Treap<Key, T>::merge(TreapNode<Key, T> *&root, TreapNode<Key, T> *left, TreapNode<Key, T> *right) {
    if (!left || !right) {
        root = left ? left : right;
    } else if (left->priority > right->priority) {
        merge(left->right, left->right, right);
        root = left;
    } else {
        merge(right->left, left, right->left);
        root = right;
    }
}

template <typename Key, typename T>
void Treap<Key, T>::split(TreapNode<Key, T> *root, TreapNode<Key, T> *&left, TreapNode<Key, T> *&right, Key key) {
    if (!root) {
        left = right = nullptr;
    } else if (key < root->key) {
        split(root->left, left, root->left, key);
        right = root;
    } else {
        split(root->right, root->right, right, key);
        left = root;
    }
}

template <typename Key, typename T>
void Treap<Key, T>::insert(TreapNode<Key, T> *&root, TreapNode<Key, T> *vertex) {
    if (root == nullptr) {
        root = vertex;
    } else if (vertex->priority < root->priority) {
        if (vertex->key < root->key) {
            insert(root->left, vertex);
        } else {
            insert(root->right, vertex);
        }
    } else {
        split(root, vertex->left, vertex->right, vertex->key);
        root = vertex;
    }
}

template <typename Key, typename T>
void Treap<Key, T>::erase(TreapNode<Key, T> *&root, Key key) {
    if (root == nullptr) {
        return;
    } else if (root->key == key) {
        merge(root, root->left, root->right);
    } else {
        erase(key < root->key ? root->left : root->right, key);
    }
}

template <typename Key, typename T>
TreapNode<Key, T>* Treap<Key, T>::find(TreapNode<Key, T> *node, Key key) {
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


#endif // TREAP_TREE_H
