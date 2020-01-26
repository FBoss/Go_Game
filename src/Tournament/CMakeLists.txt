cmake_minimum_required(VERSION 3.10)

add_executable(Tournament Tournament.cpp)
target_link_libraries(Tournament PRIVATE GameEngine)
