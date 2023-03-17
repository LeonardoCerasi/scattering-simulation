cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(Scattering VERSION 0.1)

add_executable(Scattering src/simulation.cpp)

target_include_directories(Scattering PUBLIC ${PROJECT_BINARY_DIR})

configure_file(Config.h.in Config.h)