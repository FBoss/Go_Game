cmake_minimum_required(VERSION 3.10)

find_package(GTest REQUIRED)

add_executable(StrasbourgEngineTest StrasbourgEngineTest.cpp)
target_link_libraries(StrasbourgEngineTest GTest::Main StrasbourgEngine)
add_test(NAME StrasbourgEngine COMMAND StrasbourgEngineTest)

