cmake_minimum_required(VERSION 3.14)
project(Cursach)

set(CMAKE_CXX_STANDARD 14)

add_executable(Cursach main.cpp header.h lib.cpp)

target_link_libraries(Cursach sfml-graphics sfml-window sfml-system)