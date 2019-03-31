cmake_minimum_required(VERSION 3.13)
project(RayTracing)

set(CMAKE_CXX_STANDARD 14)

add_executable(RayTracing main.cpp ppm.cpp ppm.h ray.cpp ray.h vec3.cpp vec3.h)
