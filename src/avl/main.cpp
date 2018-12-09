
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>

#include "AVL.h"
#include "AVLNode.h"

int main() {
    auto * tree = new AVLTree();
    tree->insert(1, "A");
    tree->insert(2, "B");
    tree->insert(3, "C");

    std::cout << tree->find(1) << std::endl;

    tree->erase(1);

    std::cout << tree->find(1) << std::endl;

    std::cout << "OP mizantrop";
    return 0;
}
