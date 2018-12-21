

set(target FunctionalTests)

file(GLOB srcs "*.cpp")

add_executable(${target} ${srcs})
target_include_directories(${target}
                        PUBLIC
                    ../src/avl
                    ../src/treap
                    ../src/splay)
target_link_libraries(${target} gtest gtest_main)
