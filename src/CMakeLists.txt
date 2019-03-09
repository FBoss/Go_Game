cmake_minimum_required(VERSION 3.10)

add_library(Stone INTERFACE)
target_include_directories(Stone INTERFACE Stone)


add_library(Board INTERFACE)
target_include_directories(Board INTERFACE Board)
target_link_libraries(Board INTERFACE Stone)
