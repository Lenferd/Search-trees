
set(target PerformanceTests)

include_directories(util)
file(GLOB srcs "*.cpp")

add_executable(${target} ${srcs})
target_include_directories(${target}
                        PUBLIC
                        ../src/avl
                        ../src/treap)
target_link_libraries(${target})
