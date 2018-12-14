#include "util.h"
#include "AVL.hpp"
#include <vector>
#include <tuple>
#include <memory>
#include "Benchmark.hpp"

static void AVL_Insert(BenchState& state) {
    AVLTree<int, int> tree;
    int actions_count = state.range(1);
    TIME_START
    for (size_t i = 0; i < actions_count; i++) {
        tree.insert(rand() % 10, rand() % 100);
    }
    TIME_FINISH_PASS
}

static void AVL_Insert_STR_DOUBLE(BenchState& state) {
    AVLTree<std::string, double> tree;
    int actions_count = state.range(1);
    TIME_START
    for (size_t i = 0; i < actions_count; i++) {
        tree.insert(std::to_string(rand() % 10), (rand() % 1000) / 100);
    }
    TIME_FINISH_PASS
}

static void AVL_Find(BenchState& state) {
    AVLTree<int, int> tree;
    int actions_count = state.range(1);

    for (size_t i = 0; i < actions_count; i++) {
        tree.insert(i, rand() % 100);
    }
    TIME_START
    for (size_t i = 0; i < actions_count; i++) {
        tree.find(i);
    }
    TIME_FINISH_PASS
}

static void AVL_Remove(BenchState& state) {
    AVLTree<int, int> tree;

    int actions_count = state.range(1);
    for (size_t i = 0; i < actions_count; i++) {
        tree.insert(i, rand() % 100);
    }
    TIME_START
    for (size_t i = 0; i < actions_count; i++) {
        tree.erase(i);
    }
    TIME_FINISH_PASS
}

int main() {
    srand(time(NULL));
    /*      Args
    /   First - amount of time measurement run,
    /   Second - iterations of algorithm runs
    /   For example Args(100, 10) - run 100 measurement of 10 inserts
    */
    BENCH(AVL_Insert, "AVL_Insert")->Args(10000, 10)->Args(100, 100)->Args(100, 10000)->Args(100, 100000);
    BENCH(AVL_Insert_STR_DOUBLE, "AVL_Insert_STR_DOUBLE")->Args(10000, 10)->Args(100, 100)->Args(100, 10000)->Args(100, 100000);
    BENCH(AVL_Find, "AVL_Find")->Args(10000, 10)->Args(100, 100)->Args(100, 10000)->Args(100, 100000);
    BENCH(AVL_Remove, "AVL_Remove")->Args(10000, 10)->Args(100, 100)->Args(100, 10000)->Args(100, 100000);
    BENCH_RUN();
}
