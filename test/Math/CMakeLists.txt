cmake_minimum_required(VERSION 3.10)

find_package(GTest REQUIRED)


add_executable(RandomTest 
  RandomTest.cpp
  ChiSquaredTest.cpp
)
target_link_libraries(RandomTest GTest::Main Math)
add_test(NAME Random COMMAND RandomTest)
