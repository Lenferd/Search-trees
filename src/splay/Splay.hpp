#ifndef SPLAY_HPP
#define SPLAY_HPP

#include "SplayNode.hpp"

template<typename Key, typename T>
class SplayTree {
public:
    SplayTree();

    ~SplayTree();

    void insert(Key key, T value);

    void erase(Key key);

    T *find(Key key);

private:
    SplayNode<Key, T> *root = nullptr;

    void rotate(SplayNode<Key, T> *parent, SplayNode<Key, T> *child);

    void splay(SplayNode<Key, T> *node);

};

template<typename Key, typename T>
void SplayTree<Key, T>::rotate(SplayNode<Key, T> *parent, SplayNode<Key, T> *child) {
    SplayNode<Key, T> *p = parent->parent;

    if (parent->left == child) {
        parent->set_left(child->right);
        child->set_right(parent);
    } else {
        parent->set_right(child->left);
        child->set_left(parent);
    }

    if (!p) {
        root = child;
        child->parent = nullptr;
    } else if (p->left == parent) {
        p->set_left(child);
    } else {
        p->set_right(child);
    }
}

template<typename Key, typename T>
void SplayTree<Key, T>::splay(SplayNode<Key, T> *node) {
    while (node != root) {
        SplayNode<Key, T> *parent = node->parent;
        SplayNode<Key, T> *grandparent = node->parent->parent;

        if (parent == root) {
            // zig
            rotate(parent, node);
            break;
        }

        if ((grandparent->left && grandparent->left->left == node) ||
            (grandparent->right && grandparent->right->right == node)) {
            //zig-zig
            rotate(grandparent, parent);
            rotate(parent, node);
        } else {
            //zig-zag
            rotate(parent, node);
            rotate(grandparent, node);
        }
    }
}

template<typename Key, typename T>
T *SplayTree<Key, T>::find(Key key) {
    SplayNode<Key, T> *temp = root;
    SplayNode<Key, T> *prev = nullptr;
    while (temp != nullptr) {
        prev = temp;
        if (key < temp->key) {
            temp = temp->left;
        } else if (key > temp->key) {
            temp = temp->right;
        } else {
            splay(temp);
            return &(root->value);
        }
    }
    if (prev) splay(prev);
    return nullptr;
}

template<typename Key, typename T>
void SplayTree<Key, T>::insert(Key key, T value) {
    find(key);
    SplayNode<Key, T> *new_node = new SplayNode<Key, T>(key, value);
    if (!root) {
        root = new_node;
        return;
    }
    SplayNode<Key, T> *temp = root;
    if (key < temp->key) {
        SplayNode<Key, T> *left = temp->left;
        temp->left = nullptr;
        root = new_node;
        root->set_right(temp);
        root->set_left(left);
    } else {
        SplayNode<Key, T> *right = temp->right;
        temp->right = nullptr;
        root = new_node;
        root->set_right(right);
        root->set_left(temp);
    }
}

template<typename Key, typename T>
void SplayTree<Key, T>::erase(Key key) {
    find(key);
    if (!root || (root && root->key != key)) {
        return;
    }
    SplayNode<Key, T> *to_delete = root; // TODO: delete it

    if (! root->right && !root->left) {
        root = nullptr;
        return;
    }

    if (root->right == nullptr || root->left == nullptr) {
        root = root->right ? root->right : root->left;
        root->parent = nullptr;
        return;
    }

    // finding max elem in left subtree
    SplayNode<Key, T> *right_subtree = root->right;
    root = root->left;
    root->parent = nullptr;
    // splay max elem of left subtree
    find(key);
    root->set_right(right_subtree);
}

template<typename Key, typename T>
SplayTree<Key, T>::~SplayTree() = default;

template<typename Key, typename T>
SplayTree<Key, T>::SplayTree() = default;


#endif //SPLAY_HPP