cmake_minimum_required(VERSION 3.10)


include(CTest)

find_package(GTest REQUIRED)


add_executable(StoneTest StoneTest.cpp)
target_link_libraries(StoneTest GTest::Main Stone)
add_test(NAME Stone COMMAND StoneTest)
