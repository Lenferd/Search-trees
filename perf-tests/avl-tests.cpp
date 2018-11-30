#include "AVL.h"

#include "hayai.hpp"

// run, per unit
BENCHMARK(AVL, AVL_Insert, 10, 100)
{
    AVLTree *tree = new AVLTree();
    tree->insert(10);
}
