cmake_minimum_required(VERSION 3.22)
project(SampleCLionC C)

set(CMAKE_C_STANDARD 11)

file(GLOB SRC "*.h" "*.hpp" "*.cpp" "*.c")

add_compile_definitions(_CRT_SECURE_NO_WARNINGS)

add_executable(sample ${SRC})
