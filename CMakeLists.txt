cmake_minimum_required(VERSION 3.10)

option(BUILD_TESTING "Build Test" ON)

include(CTest)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


#external dependencies
if(USE_EXTERNAL_DEPENDENCIES)
  add_subdirectory(external)
endif()

add_subdirectory(src)

if(BUILD_TESTING)
  add_subdirectory(test)
endif()


#if(BUILD_TESTING)


#include(CTest)

#find_package(benchmark)

#add_executable(benchmark_example benchmark_example.cpp)
#target_link_libraries(benchmark_example benchmark)
#add_test(NAME benchmark_example COMMAND benchmark_example)


#endif()
