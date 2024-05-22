cmake_minimum_required(VERSION 3.10)

project(frame)

include_directories(${PROJECT_SOURCE_DIR}/library/device/inc)
include_directories(${PROJECT_SOURCE_DIR}/library/Periph_lib/inc)
include_directories(${PROJECT_SOURCE_DIR}/library/borad/driver/inc)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

file(GLOB_RECURSE SRC_LIST ${PROJECT_SOURCE_DIR}/library/*.c)

add_executable(app __test__/main.c ${SRC_LIST})