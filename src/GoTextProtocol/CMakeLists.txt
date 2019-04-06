cmake_minimum_required(VERSION 3.10)

add_library(GTPCommands INTERFACE)
target_include_directories(GTPCommands INTERFACE 
  Commands/Base
  Commands/Administration
  Commands/Debug
  Commands/Play
  Commands/Regression
  Commands/Setup
  Commands/Tournament
)
target_link_libraries(GTPCommands INTERFACE Stone)
