get_filename_component(DIR_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)

set(INCLUDE_DIR "${INCLUDE_DIRS} ${CMAKE_CURRENT_LIST_DIR}" CACHE INTERNAL "DIRS")

set(MODULE      "${DIR_NAME}")
set(APP         "app_${MODULE}")
set(LIBRARY     "lib_${MODULE}")


file(GLOB hrcs "Treap*.hpp")

set(target ${APP})
file(GLOB main main.cpp)

add_executable(${target} ${main})
