get_filename_component(DIR_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)

set(MODULE      "${DIR_NAME}")
set(APP         "app_${MODULE}")
set(LIBRARY     "lib_${MODULE}")


file(GLOB hrcs "AVL*.hpp")

set(target ${APP})
file(GLOB main main.cpp)

add_executable(${target} ${main})
