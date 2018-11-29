get_filename_component(DIR_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)

set(MODULE      "${DIR_NAME}")
set(APP         "app_${MODULE}")
set(LIBRARY     "lib_${MODULE}")


# Lib
set(target ${LIBRARY})
file(GLOB hrcs "Treap.h")
file(GLOB srcs "Treap.cpp")

add_library(${target} STATIC ${hrcs} ${srcs})

message(STATUS ${CMAKE_BINARY_DIR}/${target})

# Application for debug ?
set(target ${APP})
file(GLOB main main.cpp)

add_executable(${target} ${main})
target_link_libraries(${target} ${LIBRARY})
