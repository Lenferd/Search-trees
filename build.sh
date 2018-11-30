#!/bin/sh
root_dir="$( pwd )"

git submodule init
git submodule update --recursive

Build () {
    mkdir _build
    cd _build
    echo $root_dir
    cmake -DBENCHMARK_ENABLE_GTEST_TESTS=OFF -DCMAKE_BUILD_TYPE=RELEASE $root_dir
    make -j4
}

Clear() {
  if [ -d _build ]
    then
    rm -rf ./_build
  fi
}

Clear
Build
