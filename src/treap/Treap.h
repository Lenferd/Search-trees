#ifndef TREAP_TREE_H
#define TREAP_TREE_H

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

class TreapTree {
public:
    TreapTree();
    ~TreapTree();

    void insert(const int value);
    void erase(const int value);

    int find(const int value) const;

private:
    // TODO
};

#endif // TREAP_TREE_H
