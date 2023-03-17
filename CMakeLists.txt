cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(Scattering VERSION 0.1)

add_executable(Scattering src/simulation.cpp)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})

configure_file(Config.h.in Config.h)

include_directories(include)

target_include_directories(Scattering PUBLIC ${PROJECT_BINARY_DIR})

add_subdirectory(src/tools)
target_link_libraries(Scattering PUBLIC Input)

add_subdirectory(src/classes)
target_link_libraries(Scattering PUBLIC Classes)
