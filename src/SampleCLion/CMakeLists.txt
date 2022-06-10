cmake_minimum_required(VERSION 3.22)
project(Sample)

set(CMAKE_CXX_STANDARD 23)

file(GLOB SRC "*.h" "*.hpp" "*.cpp" "*.c")

add_executable(sample ${SRC} csd/errorutil.h csd/util.h)


