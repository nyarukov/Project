cmake_minimum_required(VERSION 3.10)

project(demo)

include_directories(${PROJECT_SOURCE_DIR}/lib/inc)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

file(GLOB_RECURSE SRC_LIST ${PROJECT_SOURCE_DIR}/lib/src/*.c)

add_executable(app __test__/main.c ${SRC_LIST})