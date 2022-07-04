cmake_minimum_required(VERSION 3.22)
project(Sample)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 11)

file(GLOB SRC "*.h" "*.hpp" "*.cpp" "*.c")

add_compile_definitions(_CRT_SECURE_NO_WARNINGS)

add_executable(sample ${SRC} csd/errorutil.h csd/util.h Sensor.cpp Sensor.hpp Point.cpp Point.hpp Complex.cpp Complex.hpp File.cpp File.hpp utility.cpp)


