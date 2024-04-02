#ifndef SOUND_EXP_0_SAMPLE_HPP
#define SOUND_EXP_0_SAMPLE_HPP

#include <string>
#include <utility>
#include "SFML/Audio.hpp"


class Sample {
 private:
    std::string filename;
 public:
    Sample() : filename("default") {};
    Sample (std::string filename) : filename(std::move(filename)) {}; //NOLINT
    sf::SoundBuffer loadBuffer() {
        sf::SoundBuffer tmp;
        if (!tmp.loadFromFile(filename))
            throw std::runtime_error("Error: Couldn't load buffer.");
        return tmp;
    }
    std::string getFilename() const {
        return filename;
    }
};

#endif //SOUND_EXP_0_SAMPLE_HPP
