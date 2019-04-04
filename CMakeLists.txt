cmake_minimum_required(VERSION 3.13)
project(RayTracing)

set(CMAKE_CXX_STANDARD 14)

add_executable(RayTracing
        camera.cpp
        camera.h
        diffuse.cpp
        diffuse.h
        entity.h
        entity_list.cpp
        entity_list.h
        hit_record.h
        main.cpp
        material.h
        metal.cpp
        metal.h
        ppm.cpp
        ppm.h
        ray.cpp
        ray.h
        sphere.cpp
        sphere.h
        util.cpp
        util.h
        vec3.cpp
        vec3.h)
