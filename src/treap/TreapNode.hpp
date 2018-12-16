#ifndef TREAP_NODE_H
#define TREAP_NODE_H

#include <cstdlib>

template <typename Key, typename T>
struct TreapNode {
public:
    Key key;
    int priority = 0;

    T value;

    TreapNode* left = nullptr;
    TreapNode* right = nullptr;

    explicit TreapNode(Key key, T value) : key(key), value(value) {
        priority = (rand() << 16) + rand();
    }
};


#endif //TREAP_NODE_H
