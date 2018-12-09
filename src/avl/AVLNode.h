#ifndef AVL_NODE_H
#define AVL_NODE_H

#include <algorithm>
#include <string>

struct AVLNode {
public:
    int key;
    std::string value;
    unsigned int height;
    AVLNode* left;
    AVLNode* right;

    explicit AVLNode(int k, std::string v);

    ~AVLNode();

    void update_values();
    int balance_factor();
};

#endif //AVL_NODE_H
