cmake_minimum_required(VERSION 3.0)

project(Chess)

set (CMAKE_CXX_STANDARD 14) #set C++ version to C++14

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

include_directories(${PROJECT_SOURCE_DIR}/src/)

file(GLOB HEADERS "${PROJECT_SOURCE_DIR}/src/*.h")
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(chess ${SOURCES}; ${HEADERS})


#include libraries

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(Boost REQUIRED COMPONENTS filesystem)

include_directories(${SDL_INCLUDE_DIR})
include_directories(${SD2_IMAGE_INCLUDE_DIR})
include_directories(${Boost_INCLUDE_DIRS})

target_link_libraries(chess ${Boost_LIBRARIES}; ${SDL2_LIBRARY}; ${SDL2_IMAGE_LIBRARY})