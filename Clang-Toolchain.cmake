set(CMAKE_CXX_COMPILER clang++-7)
set(CMAKE_C_COMPILER clang-7)

set(CMAKE_CXX_FLAGS_INIT "${CMAKE_CXX_FLAGS_INIT} -fprofile-instr-generate -fcoverage-mapping -Weverything -Wno-c++98-compat")


set (CLANG_TIDY_CONFIG "-checks=*")
set (CLANG_TIDY_CONFIG "${CLANG_TIDY_CONFIG},-abseil-*")
set (CLANG_TIDY_CONFIG "${CLANG_TIDY_CONFIG},-android-*")
set (CLANG_TIDY_CONFIG "${CLANG_TIDY_CONFIG},-boost-*")
set (CLANG_TIDY_CONFIG "${CLANG_TIDY_CONFIG},-fuchsia-*")
set (CLANG_TIDY_CONFIG "${CLANG_TIDY_CONFIG},-google-*")
set (CLANG_TIDY_CONFIG "${CLANG_TIDY_CONFIG},-llvm-*")
set (CLANG_TIDY_CONFIG "${CLANG_TIDY_CONFIG},-mpi-*")
set (CLANG_TIDY_CONFIG "${CLANG_TIDY_CONFIG},-objc-*")
set (CLANG_TIDY_CONFIG "${CLANG_TIDY_CONFIG},-zircon-*")


set(CMAKE_CXX_CLANG_TIDY "clang-tidy;${CLANG_TIDY_CONFIG}")

