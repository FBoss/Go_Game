cmake_minimum_required(VERSION 3.10)

add_library(Stone INTERFACE)
target_include_directories(Stone INTERFACE Stone)


add_library(Board INTERFACE)
target_include_directories(Board INTERFACE Board)
target_link_libraries(Board INTERFACE Stone)

add_library(Rules INTERFACE)
target_include_directories(Rules INTERFACE Rules)
target_link_libraries(Rules INTERFACE Board)

add_library(Math INTERFACE)
target_include_directories(Math INTERFACE Math)

add_subdirectory(GoTextProtocol)

add_subdirectory(GameEngine)
