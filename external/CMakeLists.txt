cmake_minimum_required(VERSION 3.10)

set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "Suppressing benchmark's tests" FORCE)

add_subdirectory(googletest)
add_subdirectory(benchmark)
