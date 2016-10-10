cmake_minimum_required(VERSION 3.6)
project(advcpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES assignment3/task2/spell_check.cpp)
add_executable(advcpp ${SOURCE_FILES})