cmake_minimum_required(VERSION 3.10)

find_package(GTest REQUIRED)


add_executable(StrasbourgRulesTest StrasbourgRulesTest.cpp)
target_link_libraries(StrasbourgRulesTest GTest::Main Rules)
add_test(NAME StrasbourgRules COMMAND StrasbourgRulesTest)



add_executable(GroupTest 
  Group_hasLiberty_Test.cpp
  Group_positionHasLiberty_Test.cpp
  Group_remove_Test.cpp
)
target_link_libraries(GroupTest GTest::Main Rules)
add_test(NAME Group COMMAND GroupTest)
