#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

class AVLTree {
public:
    AVLTree();
    ~AVLTree();

    void insert(const int value);
    void erase(const int value);

    int find(const int value) const;

private:
    // TODO
};

#endif // AVL_TREE_H
