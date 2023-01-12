cmake_minimum_required(VERSION 3.22)
project(Sample)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_C_STANDARD 11)

file(GLOB SRC "*.h" "*.hpp" "*.cpp" "*.c", "parser/*.cpp" "parser/*.hpp" "company/*.cpp" "company/*.hpp", "csd/*.cpp" "csd/*.hpp", "csd/*.c" "csd/*.h" "game/*.hpp" "game/*.cpp")

add_compile_definitions(_CRT_SECURE_NO_WARNINGS)

add_executable(sample ${SRC})


