cmake_minimum_required(VERSION 3.0.0...3.5)
project(int_array VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(int_array main.cpp IntArray.cpp IntArray_exception.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)