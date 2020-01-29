cmake_minimum_required(VERSION 3.10)

find_package (Threads)

add_executable(Tournament Tournament.cpp)
target_link_libraries(Tournament PRIVATE GameEngine ${CMAKE_THREAD_LIBS_INIT})
