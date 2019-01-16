cmake_minimum_required(VERSION 3.12)
project(T1)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g")
set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_BUILD_TYPE Debug)
file(GLOB T1_SRC
    main.cpp
    "./src/*.h"
    "./src/*.cpp"
)


add_executable(T1 ${T1_SRC})
