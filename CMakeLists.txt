cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER clang++)

project(HelloWorld)

file(GLOB_RECURSE SOURCES src/*.cpp)

message(STATUS "SOURCES: ${SOURCES}")

add_executable(ZenithVM ${SOURCES})

target_include_directories(ZenithVM PUBLIC include/)