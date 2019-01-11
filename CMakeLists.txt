cmake_minimum_required(VERSION 3.13)
project(T1)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(T1
        src/decodeSteps.cpp
        src/decoding_lib.h
        src/printing_lib.h
        src/prnt.cpp
        src/rdn.cpp
        src/reading_lib.h
        CMakeLists.txt
        main.cpp)
