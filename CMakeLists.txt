cmake_minimum_required(VERSION 3.20)
project(dsa LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Primary CP workflow: single driver (main.cpp) includes one solution header
# exposing void solution(). Only main.cpp is compiled; solution headers are
# pulled in via #include, so switching problems = changing one #include line.
add_executable(cp_main main.cpp)
target_include_directories(cp_main PRIVATE ${CMAKE_SOURCE_DIR})

# Legacy C demo (Gauss-Jordan), preserved from the original main.c build.
add_executable(legacy_main main.c)
