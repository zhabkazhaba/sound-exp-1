#ifndef SOUND_EXP_0_PULSEVOLCHANGE_H
#define SOUND_EXP_0_PULSEVOLCHANGE_H

#include "filter.hpp"

class PulseVolChange : public Filter {
 private:
    float range;
    int iterations;
 public:
    PulseVolChange(float range, int iterations) {
        this->range = range;
        this->iterations = iterations;
    }
    sf::Int16 apply(sf::Int16 sample, int i, float frequency = 220.0f, float duration = 1.0f, float volume = 1.0f) override {
        int tmp = static_cast<int>(SAMPLE_RATE * duration) / iterations;
        return static_cast<sf::Int16>((sample/volume) * (volume + ((i % tmp) / tmp) * range));
    }
};


#endif //SOUND_EXP_0_PULSEVOLCHANGE_H
