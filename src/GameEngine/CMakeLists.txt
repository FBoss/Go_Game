cmake_minimum_required(VERSION 3.10)


add_library(GameEngine INTERFACE)
target_include_directories(GameEngine INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(GameEngine INTERFACE Board)
