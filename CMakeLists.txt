cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(Simulation VERSION 0.1)

add_executable(Simulation src/simulation.cpp)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})

configure_file(Config.h.in Config.h)

include_directories(include)

target_include_directories(Simulation PUBLIC ${PROJECT_BINARY_DIR})

add_subdirectory(src/classes)
target_link_libraries(Simulation PUBLIC Classes)
