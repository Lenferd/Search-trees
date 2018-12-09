#include "AVL.h"
#include <unistd.h>

AVLTree::AVLTree() {
    head = nullptr;
}

AVLTree::~AVLTree(){
    delete head;
}

void AVLTree::insert(int key, std::string value) {
    head = insert(head, key, value);
}

void AVLTree::erase(int key) {
    head = remove(head, key);
}

std::string AVLTree::find(int key) {
    AVLNode* result = find(head, key);
    return result ? result->value : "";
}

AVLNode *AVLTree::insert(AVLNode *node, int key, std::string value) {
    if (!node) return new AVLNode(key, value);
    if (key < node->key) {
        node->left = insert(node->left, key, value);
    } else {
        node->right = insert(node->right, key, value);
    }
    return balance(node);

}

AVLNode *AVLTree::find_min(AVLNode* node) {
    return node->left ? find_min(node->left) : node;
}

AVLNode *AVLTree::remove_min(AVLNode *node) {
    if (!node->left) {
        return node->right;
    }
    node->left = remove_min(node->left);
    return balance(node);
}

AVLNode *AVLTree::remove(AVLNode *node, int key) {
    if (!node) {
        return nullptr;
    }
    if (key < node->key) {
        return remove(node->left, key);
    } else if (key > node->key) {
        return remove(node->right, key);
    } else {
        AVLNode* left = node->left;
        AVLNode* right = node->right;
        delete node; // tut ved' net garbage collector'a? lol
        if (!right) {
            return left;
        }
        AVLNode* min = find_min(right);
        min->right = remove_min(right);
        min->left = left;
        return balance(min);
    }
}

AVLNode *AVLTree::find(AVLNode *node, int key) {
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

AVLNode* AVLTree::rotate_left(AVLNode* node) {
    AVLNode* p = node->right;
    node->right = p->left;
    p->left = node;
    node->update_values();
    p->update_values();
    return p;
}

AVLNode *AVLTree::rotate_right(AVLNode* node) {
    AVLNode* p = node->left;
    node->left = p->right;
    p->right = node;
    node->update_values();
    p->update_values();
    return p;
}

AVLNode *AVLTree::balance(AVLNode* node) {
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


