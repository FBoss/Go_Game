cmake_minimum_required(VERSION 3.10)

find_package(GTest REQUIRED)

add_executable(BitFieldBoardTest BitFieldBoardTest.cpp)
target_link_libraries(BitFieldBoardTest GTest::Main Board)
add_test(NAME BitFieldBoard COMMAND BitFieldBoardTest)

add_executable(TwoDimensionArrayBoardTest TwoDimensionArrayBoardTest.cpp)
target_link_libraries(TwoDimensionArrayBoardTest GTest::Main Board)
add_test(NAME TwoDimensionArrayBoard COMMAND TwoDimensionArrayBoardTest)

add_executable(ArrayBoardTest ArrayBoardTest.cpp)
target_link_libraries(ArrayBoardTest GTest::Main Board)
add_test(NAME ArrayBoard COMMAND ArrayBoardTest)

add_executable(MapBoardTest MapBoardTest.cpp)
target_link_libraries(MapBoardTest GTest::Main Board)
add_test(NAME MapBoard COMMAND MapBoardTest)

add_executable(UnorderedMapBoardTest UnorderedMapBoardTest.cpp)
target_link_libraries(UnorderedMapBoardTest GTest::Main Board)
add_test(NAME UnorderedMapBoard COMMAND UnorderedMapBoardTest)

