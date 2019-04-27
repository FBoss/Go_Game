cmake_minimum_required(VERSION 3.10)

add_library(StrasbourgEngine StrasbourgEngine.cpp)
target_link_libraries(StrasbourgEngine GTPUtil)
target_include_directories(StrasbourgEngine PUBLIC include)
