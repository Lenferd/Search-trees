
#include <benchmark/benchmark.h>
#include "AVL.h"


static void AVL_Insert(benchmark::State& state) {
    for (auto _ : state) {
        AVLTree tree;
        tree.insert(10);
    }
}

BENCHMARK(AVL_Insert);


BENCHMARK_MAIN();
