cmake_minimum_required(VERSION 3.10)

#add_library(GTPCommands Commands/Base/Command.cpp)
#target_include_directories(GTPCommands INTERFACE 
#  Commands/Base
#  Commands/Administration
#  Commands/Debug
#  Commands/Play
#  Commands/Regression
#  Commands/Setup
#  Commands/Tournament
#)
#target_link_libraries(GTPCommands INTERFACE Stone)

#add_library(GTPUtil INTERFACE)
#target_include_directories(GTPUtil INTERFACE Util)
#target_link_libraries(GTPUtil INTERFACE GTPCommands)


#add_subdirectory(Engine)


add_library(GTPEngine INTERFACE)
target_include_directories(GTPEngine INTERFACE include)
