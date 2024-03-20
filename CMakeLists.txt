cmake_minimum_required(VERSION 3.26)
project(sound_exp_0)

set(CMAKE_CXX_STANDARD 17)

add_executable(sound_exp_0 src/main.cpp
        src/sound.h
        src/sound.cpp
        src/player.h
        src/player.cpp
        src/sndGen.hpp)

target_link_libraries(sound_exp_0 sfml-system sfml-window sfml-audio)