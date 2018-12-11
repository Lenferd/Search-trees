
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>

#include "AVL.hpp"

int main() {
    {
        AVLTree<int, std::string> tree;
        tree.insert(1, "A");
        tree.insert(2, "B");
        tree.insert(3, "C");

        std::cout << *tree.find(1) << std::endl;

        tree.erase(1);

        auto res = tree.find(1);
        if (res) {
            std::cout << *res << std::endl;
        } else {
            std::cout << "Result is empty" << '\n';
        }

        std::cout << "OP mizantrop\n";
    }
    {
        AVLTree<std::string, std::string> tree;
        tree.insert("C", "A");
        tree.insert("B", "B");
        tree.insert("A", "C");

        std::cout << *tree.find("A") << std::endl;
    }
    return 0;
}
