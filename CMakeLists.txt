cmake_minimum_required(VERSION 3.13)
project(T1)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(T1
        assets/file_example.txt
        src/decoding_lib.h
        src/printing_lib.h
        src/reading_lib.h
        CMakeLists.txt
        main.cpp
        README.md src/decoding_lib.cpp src/printing_lib.cpp src/reading_lib.cpp)
