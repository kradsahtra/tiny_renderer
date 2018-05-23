cmake_minimum_required(VERSION 3.10)
project(tiny_renderer)

set(CMAKE_CXX_STANDARD 11)

add_executable(tiny_renderer main.cpp tga_image.h tag_image.cpp geometry.h model.h model.cpp)