cmake_minimum_required(VERSION 3.10)

include(CTest)

find_package(GTest REQUIRED)


add_executable(BitFieldBoardTest BitFieldBoardTest.cpp)
target_link_libraries(BitFieldBoardTest GTest::Main Board)
add_test(NAME BitFieldBoard COMMAND BitFieldBoardTest)

add_executable(TwoDimensionArrayBoardTest TwoDimensionArrayBoardTest.cpp)
target_link_libraries(TwoDimensionArrayBoardTest GTest::Main Board)
add_test(NAME TwoDimensionArrayBoard COMMAND TwoDimensionArrayBoardTest)
