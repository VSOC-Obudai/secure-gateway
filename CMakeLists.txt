cmake_minimum_required(VERSION 3.23)
project(secure-gateway)

include(${CMAKE_CURRENT_LIST_DIR}/cmake/ProjectInit.cmake)

add_subdirectory(third-party)
add_subdirectory(src)
