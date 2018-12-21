#include "util.h"
#include <vector>
#include <tuple>
#include <memory>
#include <map>
#include <utility>

#include "Benchmark.hpp"

#include "AVL.hpp"
#include "Treap.hpp"
#include "Splay.hpp"

RandomGenerator randGen;

static void AVL_Insert(BenchState& state) {
    AVLTree<int, int> tree;
    int actions_count = state.range(1);
    std::vector<int> values = randGen.GenIntegralVector<int>(actions_count, INT_MIN, INT_MAX);

    TIME_START
    for (size_t i = 0; i < actions_count; i++) {
        tree.insert(values[i], values[i]);
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
    std::vector<int> values = randGen.GenIntegralVector<int>(actions_count, INT_MIN, INT_MAX);

    for (size_t i = 0; i < actions_count; i++) {
        tree.insert(values[i], values[i]);
    }

    TIME_START
    for (size_t i = 0; i < actions_count; i++) {
        tree.find(values[i]);
    }
    TIME_FINISH_PASS
}

static void AVL_Remove(BenchState& state) {
    AVLTree<int, int> tree;
    int actions_count = state.range(1);
    std::vector<int> values = randGen.GenIntegralVector<int>(actions_count, INT_MIN, INT_MAX);

    for (size_t i = 0; i < actions_count; i++) {
        tree.insert(values[i], values[i]);
    }

    TIME_START
    for (size_t i = 0; i < actions_count; i++) {
        tree.erase(values[i]);
    }
    TIME_FINISH_PASS
}


/// STD::Set

static void Map_Insert(BenchState& state) {
    std::map<int, int> tree;
    int actions_count = state.range(1);
    std::vector<int> values = randGen.GenIntegralVector<int>(actions_count, INT_MIN, INT_MAX);

    TIME_START
    for (size_t i = 0; i < actions_count; i++) {
        tree.insert(std::pair<int,int>(values[i], values[i]));
    }
    TIME_FINISH_PASS
}

static void Map_Insert_STR_DOUBLE(BenchState& state) {
    std::map<std::string, double> tree;
    int actions_count = state.range(1);
    TIME_START
    for (size_t i = 0; i < actions_count; i++) {
        tree.insert(std::pair<std::string,double>(std::to_string(rand() % 10), (rand() % 1000) / 100));
    }
    TIME_FINISH_PASS
}

static void Map_Find(BenchState& state) {
    std::map<int, int> tree;
    int actions_count = state.range(1);
    std::vector<int> values = randGen.GenIntegralVector<int>(actions_count, INT_MIN, INT_MAX);

    for (size_t i = 0; i < actions_count; i++) {
        tree.insert(std::pair<int,int>(values[i], values[i]));
    }

    TIME_START
    for (size_t i = 0; i < actions_count; i++) {
        tree.find(values[i]);
    }
    TIME_FINISH_PASS
}

static void Map_Remove(BenchState& state) {
    std::map<int, int> tree;
    int actions_count = state.range(1);
    std::vector<int> values = randGen.GenIntegralVector<int>(actions_count, INT_MIN, INT_MAX);

    for (size_t i = 0; i < actions_count; i++) {
        tree.insert(std::pair<int,int>(values[i], values[i]));
    }

    TIME_START
    for (size_t i = 0; i < actions_count; i++) {
        tree.erase(values[i]);
    }
    TIME_FINISH_PASS
}

/////////////////////

/// Treap

static void Treap_Insert(BenchState& state) {
    Treap<int, int> tree;
    int actions_count = state.range(1);
    std::vector<int> values = randGen.GenIntegralVector<int>(actions_count, INT_MIN, INT_MAX);

    TIME_START
    for (size_t i = 0; i < actions_count; i++) {
        tree.insert(values[i], values[i]);
    }
    TIME_FINISH_PASS
}

static void Treap_Insert_STR_DOUBLE(BenchState& state) {
    Treap<std::string, double> tree;
    int actions_count = state.range(1);
    TIME_START
    for (size_t i = 0; i < actions_count; i++) {
        tree.insert(std::to_string(rand() % 10), (rand() % 1000) / 100);
    }
    TIME_FINISH_PASS
}

static void Treap_Find(BenchState& state) {
    Treap<int, int> tree;
    int actions_count = state.range(1);
    std::vector<int> values = randGen.GenIntegralVector<int>(actions_count, INT_MIN, INT_MAX);

    for (size_t i = 0; i < actions_count; i++) {
        tree.insert(values[i], values[i]);
    }

    TIME_START
    for (size_t i = 0; i < actions_count; i++) {
        tree.find(values[i]);
    }
    TIME_FINISH_PASS
}

static void Treap_Remove(BenchState& state) {
    Treap<int, int> tree;
    int actions_count = state.range(1);
    std::vector<int> values = randGen.GenIntegralVector<int>(actions_count, INT_MIN, INT_MAX);

    for (size_t i = 0; i < actions_count; i++) {
        tree.insert(values[i], values[i]);
    }

    TIME_START
    for (size_t i = 0; i < actions_count; i++) {
        tree.erase(values[i]);
    }
    TIME_FINISH_PASS
}
/////////////////////

// Splay

static void Splay_Insert(BenchState& state) {
    SplayTree<int, int> tree;
    int actions_count = state.range(1);
    std::vector<int> values = randGen.GenIntegralVector<int>(actions_count, INT_MIN, INT_MAX);

    TIME_START
    for (size_t i = 0; i < actions_count; i++) {
        tree.insert(values[i], values[i]);
    }
    TIME_FINISH_PASS
}

static void Splay_Insert_STR_DOUBLE(BenchState& state) {
    SplayTree<std::string, double> tree;
    int actions_count = state.range(1);
    TIME_START
    for (size_t i = 0; i < actions_count; i++) {
        tree.insert(std::to_string(rand() % 10), (rand() % 1000) / 100);
    }
    TIME_FINISH_PASS
}

static void Splay_Find(BenchState& state) {
    SplayTree<int, int> tree;
    int actions_count = state.range(1);
    std::vector<int> values = randGen.GenIntegralVector<int>(actions_count, INT_MIN, INT_MAX);

    for (size_t i = 0; i < actions_count; i++) {
        tree.insert(values[i], values[i]);
    }

    TIME_START
    for (size_t i = 0; i < actions_count; i++) {
        tree.find(values[i]);
    }
    TIME_FINISH_PASS
}

static void Splay_Remove(BenchState& state) {
    SplayTree<int, int> tree;
    int actions_count = state.range(1);
    std::vector<int> values = randGen.GenIntegralVector<int>(actions_count, INT_MIN, INT_MAX);

    for (size_t i = 0; i < actions_count; i++) {
        tree.insert(values[i], values[i]);
    }

    TIME_START
    for (size_t i = 0; i < actions_count; i++) {
        tree.erase(values[i]);
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
    //
    //->Args(10000, 10)->Args(1000, 100)->Args(100, 1000)->Args(100, 10000)->Args(100, 100000)->Args(100, 1000000);
    BENCH(AVL_Insert, "AVL;Insert")
    ->Args(10000, 10)->Args(1000, 100)->Args(100, 1000)->Args(100, 10000)->Args(100, 100000);
    BENCH(AVL_Insert_STR_DOUBLE, "AVL;Insert_STR_DOUBLE")
    ->Args(10000, 10)->Args(1000, 100)->Args(100, 1000)->Args(100, 10000)->Args(100, 100000);
    BENCH(AVL_Find, "AVL;Find")
    ->Args(10000, 10)->Args(1000, 100)->Args(100, 1000)->Args(100, 10000)->Args(100, 100000);
    BENCH(AVL_Remove, "AVL;Remove")
    ->Args(10000, 10)->Args(1000, 100)->Args(100, 1000)->Args(100, 10000)->Args(100, 100000);

    BENCH(Map_Insert, "Map;Insert")
    ->Args(10000, 10)->Args(1000, 100)->Args(100, 1000)->Args(100, 10000)->Args(100, 100000);
    BENCH(Map_Insert_STR_DOUBLE, "Map;Insert_STR_DOUBLE")
    ->Args(10000, 10)->Args(1000, 100)->Args(100, 1000)->Args(100, 10000)->Args(100, 100000);
    BENCH(Map_Find, "Map;Find")
    ->Args(10000, 10)->Args(1000, 100)->Args(100, 1000)->Args(100, 10000)->Args(100, 100000);
    BENCH(Map_Remove, "Map;Remove")
    ->Args(10000, 10)->Args(1000, 100)->Args(100, 1000)->Args(100, 10000)->Args(100, 100000);

    BENCH(Treap_Insert, "Treap;Insert")
    ->Args(10000, 10)->Args(1000, 100)->Args(100, 1000)->Args(100, 10000)->Args(100, 100000);
    BENCH(Treap_Insert_STR_DOUBLE, "Treap;Insert_STR_DOUBLE")
    ->Args(10000, 10)->Args(1000, 100)->Args(100, 1000)->Args(100, 10000)->Args(100, 100000);
    BENCH(Treap_Find, "Treap;Find")
    ->Args(10000, 10)->Args(1000, 100)->Args(100, 1000)->Args(100, 10000)->Args(100, 100000);
    BENCH(Treap_Remove, "Treap;Remove")
    ->Args(10000, 10)->Args(1000, 100)->Args(100, 1000)->Args(100, 10000)->Args(100, 100000);

    BENCH(Splay_Insert, "Splay;Insert")
    ->Args(10000, 10)->Args(1000, 100)->Args(100, 1000)->Args(100, 10000)->Args(100, 100000);
    BENCH(Splay_Insert_STR_DOUBLE, "Splay;Insert_STR_DOUBLE")
    ->Args(10000, 10)->Args(1000, 100)->Args(100, 1000)->Args(100, 10000)->Args(100, 100000);
    BENCH(Splay_Find, "Splay;Find")
    ->Args(10000, 10)->Args(1000, 100)->Args(100, 1000)->Args(100, 10000)->Args(100, 100000);
    BENCH(Splay_Remove, "Splay;Remove")
    ->Args(10000, 10)->Args(1000, 100)->Args(100, 1000)->Args(100, 10000)->Args(100, 100000);

    BENCH_RUN();
}
