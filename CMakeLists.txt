cmake_minimum_required(VERSION 3.5)
#
# find_program(ICC_PATH icc)
# find_program(ICPC_PATH icpc)
#
# set(CMAKE_CXX_COMPILER ${ICPC_PATH})
# set(CMAKE_C_COMPILER ${ICC_PATH})

project(Search-Trees CXX)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++11")

if("${CMAKE_BUILD_TYPE}" STREQUAL "")
    message(STATUS "CMAKE_BUILD_TYPE not defined, 'Release' will be used")
    set(CMAKE_BUILD_TYPE "Release")
endif()

message(STATUS "BUILD_CONFIGURATION: ${CMAKE_BUILD_TYPE}")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin/${CMAKE_BUILD_TYPE}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin/${CMAKE_BUILD_TYPE}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin/${CMAKE_BUILD_TYPE}/)

add_subdirectory(thirdparty)

add_subdirectory(src)

add_subdirectory(perf-tests)
add_subdirectory(functional-tests)
