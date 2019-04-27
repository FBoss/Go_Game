cmake_minimum_required(VERSION 3.10)

find_package(GTest REQUIRED)

add_executable(CommandToStringTest CommandGeneratorTest.cpp)
target_link_libraries(CommandToStringTest GTest::Main GTPCommands)
target_include_directories(CommandToStringTest PRIVATE
  Commands/Administration
  Commands/Base
  Commands/Debug
  Commands/Play
  Commands/Regression
  Commands/Setup
  Commands/Tournament
)
add_test(NAME CommandToString COMMAND CommandToStringTest)


add_executable(UtilTest
  Util/CommandExtractorTest.cpp
  Util/CommandParameterParserTest.cpp
  Util/IntegerTest.cpp
  Util/WordExtractorTest.cpp
)
target_link_libraries(UtilTest GTest::Main GTPUtil)
add_test(NAME Util COMMAND UtilTest)
