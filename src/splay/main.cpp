
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>
#include <string>

#include "Splay.hpp"

int main() {
    {
        SplayTree<int, std::string> tree;
        tree.insert(1, "A");
        tree.insert(2, "B");
        tree.insert(3, "C");

        std::cout << *tree.find(1) << std::endl;
        tree.erase(1);
        std::cout << *tree.find(2) << std::endl;
        tree.erase(3);

        auto res = tree.find(3);
        if (res) {
            std::cout << *res << std::endl;
        } else {
            std::cout << "Result is empty" << '\n';
        }

        std::cout << "OP mizantrop\n";
    }
    {
        SplayTree<std::string, std::string> tree;
        tree.insert("C", "A");
        tree.insert("B", "B");
        tree.insert("A", "C");

        std::cout << *tree.find("A") << std::endl;
    }
    return 0;
}
