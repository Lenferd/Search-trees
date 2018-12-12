
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>

#include "Treap.hpp"

int main() {
    Treap<int, int> tree{};
    tree.insert(5, 10);
    tree.insert(8, 20);
    tree.erase(5);

    auto res = tree.find(8);
    if (res) {
        std::cout << *res << std::endl;
    } else {
        std::cout << "Result is empty" << '\n';
    }
}
