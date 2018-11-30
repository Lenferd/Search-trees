

set(target FunctionalTests)

file(GLOB srcs "*.cpp")

add_executable(${target} ${srcs})
target_link_libraries(${target} gtest gtest_main)
