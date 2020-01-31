cmake_minimum_required(VERSION 3.10)


add_library(ComputerPlayer INTERFACE)
target_include_directories(ComputerPlayer INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(ComputerPlayer INTERFACE Board)
