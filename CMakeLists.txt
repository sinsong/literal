cmake_minimum_required(VERSION 3.14)

project(literal C CXX)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)

#https://stackoverflow.com/questions/33062728/cmake-link-shared-library-on-windows
if(MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
    #set(BUILD_SHARED_LIBS TRUE)
endif()

include_directories(include)
add_subdirectory(lib)

# test
# https://www.jianshu.com/p/07acea4e86a3

include(CTest)
enable_testing()
set(gtest_force_shared_crt ON  CACHE BOOL "" FORCE)
set(INSTALL_GTEST          OFF CACHE BOOL "" FORCE)
set(gtest_build_tests      OFF CACHE BOOL "" FORCE)
set(gtest_build_samples    OFF CACHE BOOL "" FORCE)
set(gmock_build_tests      OFF CACHE BOOL "" FORCE)
add_subdirectory(thirdparty/googletest EXCLUDE_FROM_ALL)
add_subdirectory(test)

set(BENCHMARK_ENABLE_TESTING     OFF CACHE BOOL "" FORCE)
set(BENCHMARK_ENABLE_INSTALL     OFF CACHE BOOL "" FORCE)
set(BENCHMARK_ENABLE_GTEST_TESTS OFF CACHE BOOL "" FORCE)
add_subdirectory(thirdparty/benchmark EXCLUDE_FROM_ALL)
