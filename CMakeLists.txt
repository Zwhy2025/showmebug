cmake_minimum_required(VERSION 3.16)
project(showmebug LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(leetcode_lib INTERFACE)

add_executable(showmebug
    src/main.cpp
)

target_link_libraries(showmebug PRIVATE leetcode_lib)

target_include_directories(leetcode_lib INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
