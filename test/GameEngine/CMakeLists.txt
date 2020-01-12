cmake_minimum_required(VERSION 3.10)

find_package(GTest REQUIRED)


add_executable(GameEngineTest
 02_Play.cpp
 03_Point_of_play.cpp
 05_Capture.cpp
 06_Ko.cpp
)
target_link_libraries(GameEngineTest GTest::Main GameEngine)
target_include_directories(GameEngineTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
add_test(NAME GameEngine COMMAND GameEngineTest)
