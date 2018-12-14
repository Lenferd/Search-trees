
set(target PerformanceTests)

include_directories(util)
file(GLOB srcs "*.cpp")

add_executable(${target} ${srcs})
target_link_libraries(${target})
