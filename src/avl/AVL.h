#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "AVLNode.h"

class AVLTree {
public:
    AVLTree();
    ~AVLTree();

    void insert(int key, std::string value);
    void erase(int key);

    std::string find(int key);

private:
    AVLNode* head;
    AVLNode* insert(AVLNode* node, int key, std::string value);
    AVLNode* find_min(AVLNode* node);
    AVLNode* remove_min(AVLNode* node);
    AVLNode* remove(AVLNode* node, int key);
    AVLNode* find(AVLNode* node, int key);

    AVLNode* rotate_left(AVLNode* node);
    AVLNode* rotate_right(AVLNode* node);
    AVLNode* balance(AVLNode* node);
};

#endif // AVL_TREE_H
