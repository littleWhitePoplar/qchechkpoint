cmake_minimum_required(VERSION 3.10)

project(qcheckpoint)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES src/QCheckpoint.cpp)

add_library(qcheckpoint SHARED ${SOURCES})

target_include_directories(qcheckpoint PRIVATE include)
