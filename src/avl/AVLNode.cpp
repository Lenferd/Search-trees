#include "AVLNode.h"

AVLNode::AVLNode(int k, std::string v) {
    key = k;
    value = v;
    left = right = nullptr;
    height = 1;
}

AVLNode::~AVLNode() {
    delete left;
    delete right;
}

void AVLNode::update_values() {
    height = std::max(left ? left->height : 0, right ? right->height : 0) + 1;
}

int AVLNode::balance_factor() {
    return (right ? right -> height : 0) - (left ? left->height : 0);
}
