cmake_minimum_required(VERSION 3.30)
project(Demo_Project VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


set(SRC_FILES
    src/main.cpp 
    src/Logging.cpp
)

set(INCLUDE_DIRS
    ./include
)

add_executable(Demo ${SRC_FILES})

target_include_directories(Demo PRIVATE ${INCLUDE_DIRS})