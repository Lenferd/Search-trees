#ifndef SPLAY_NODE_H
#define SPLAY_NODE_H

#include <algorithm>
#include <string>

template<typename Key, typename T>
struct SplayNode {
public:
    Key key;
    T value;

    SplayNode<Key, T>* left = nullptr;
    SplayNode<Key, T>* right = nullptr;
    SplayNode<Key, T>* parent = nullptr;

    explicit SplayNode(Key k, T v) : key(k), value(v) {};

    void set_left(SplayNode* node) {
        left = node;
        if (left) {
            left->parent = this;
        }
    }

    void set_right(SplayNode* node) {
        right = node;
        if (right) {
            right->parent = this;
        }
    }
};

#endif //SPLAY_NODE_H
