#include "AVL.h"
#include <unistd.h>

AVLTree::AVLTree() {

}

AVLTree::~AVLTree(){

}

void AVLTree::insert(const int value) {
    usleep(value * 1000);
}
