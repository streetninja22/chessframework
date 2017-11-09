cmake_minimum_required(VERSION 3.0)

project(Chess)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

include_directories(${PROJECT_SOURCE_DIR})

file(GLOB HEADERS "${PROJECT_SOURCE_DIR}/*.h")
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/*.cpp")

add_executable(chess ${SOURCES}; ${HEADERS})