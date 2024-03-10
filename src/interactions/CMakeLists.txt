add_library(Interactions constraints.cpp scattering.cpp)

target_include_directories(Interactions INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})