#ifndef SOUND_EXP_0_LINVOLCHANGE_HPP
#define SOUND_EXP_0_LINVOLCHANGE_HPP
#include "filter.hpp"
#include "../sndgen.h"

class LinVolChange : public Filter {
 private:
    float new_volume;
 public:
    LinVolChange(float new_volume) {
        this->new_volume = new_volume;
    }
    sf::Int16 apply(sf::Int16 sample, int i, float frequency = 220.0f, float duration = 1.0f, float volume = 1.0f) override {
        // Gradually change the volume of the sound
        return static_cast<sf::Int16>((sample / volume) * (volume + (new_volume - volume) * (i / (SAMPLE_RATE * duration))));
    }
};

#endif //SOUND_EXP_0_LINVOLCHANGE_HPP
