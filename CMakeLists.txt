cmake_minimum_required(VERSION 3.22)
project(julia_synth C CXX)
set(CMAKE_C_STANDARD 23)

find_library(SDL2 REQUIRE NAMES SDL2)
find_library(SDL2_mixer REQUIRED NAMES SDL2_mixer)
find_library(pthread REQUIRED NAMES libpthread.so)
find_library(sfml-audio REQUIRED NAMES sfml-audio)

add_library(julia_synth SHARED playback.hpp)
target_include_directories(julia_synth PUBLIC "${CMAKE_SOURCE_DIR}/..")

set_target_properties(julia_synth PROPERTIES
    LINKER_LANGUAGE CXX
)
target_link_libraries(julia_synth PUBLIC ${SDL2_mixer} ${SDL2} ${sfml-audio} ${pthread})

add_executable(test main.cpp)
target_link_libraries(test julia_synth)
