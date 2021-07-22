cmake_minimum_required(VERSION 2.8)

project(raytracer-reloaded)

file(GLOB_RECURSE SOURCES "trace/*.cpp")

file(GLOB_RECURSE HEADERS "trace/*.h")

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES} ${HEADERS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -Wall -pedantic")

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)