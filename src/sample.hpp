#ifndef SOUND_EXP_0_SAMPLE_HPP
#define SOUND_EXP_0_SAMPLE_HPP

#include <string>
#include "SFML/Audio.hpp"

enum class SampleType {
    WAV,
    OGG,
    FLAC
};

class Sample {
 private:
    std::string filename;
    SampleType type;
 public:
    Sample() : filename("default"), type(SampleType::WAV) {};
    Sample (std::string filename, SampleType type) : filename(filename), type(type) {};
    int checkValidity() {
        sf::SoundBuffer tmp;
        if (!tmp.loadFromFile(filename))
            return -1;
        return 0;
    }
};

#endif //SOUND_EXP_0_SAMPLE_HPP
