cmake_minimum_required(VERSION 3.13)
project(RayTracing)

set(CMAKE_CXX_STANDARD 14)

add_executable(RayTracing
        camera.cpp
        camera.h
        entity.h
        entity_list.cpp
        entity_list.h
        main.cpp
        ppm.cpp
        ppm.h
        ray.cpp
        ray.h
        sphere.cpp
        sphere.h
        vec3.cpp
        vec3.h)
