cmake_minimum_required(VERSION 3.0.0)
project(square VERSION 0.1.0)

add_library(interface STATIC interface.cpp)
add_executable(main main.cpp)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/test.txt
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(main interface)	

set(CMAKE_CXX_FLAGS "-O0 -std=c++17 -Wall")
include(CPack)
