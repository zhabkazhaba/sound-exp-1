cmake_minimum_required(VERSION 3.26)
project(sound_exp_0)

set(CMAKE_CXX_STANDARD 17)

add_executable(sound_exp_0 src/main.cpp
        src/sound.hpp
        src/player.h
        src/player.cpp
        src/sndgen.h
        src/filters/filter.hpp
        src/sndgen.cpp
        src/filters/linvolchange.hpp
        src/filters/pulsevolchange.hpp
        src/sample.hpp
)

target_link_libraries(sound_exp_0 sfml-system sfml-window sfml-audio sfml-graphics sfml-network)