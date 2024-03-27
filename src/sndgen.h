#ifndef SOUND_EXP_0_SNDGEN_H
#define SOUND_EXP_0_SNDGEN_H


#include <SFML/Config.hpp>
#include <cmath>

const float SAMPLE_RATE = 44100.0f;
const float TWO_PI = 6.28318530718f;

namespace sndGen {
    void sineWave(sf::Int16* samples, float frequency, float duration, float volume = 1.0f);
    void sawTooth(sf::Int16* samples, float frequency, float duration, float volume = 1.0f);
    void squareWave(sf::Int16* samples, float frequency, float duration, float volume = 1.0f);
    void triangleWave(sf::Int16* samples, float frequency, float duration, float volume = 1.0f);
}


#endif //SOUND_EXP_0_SNDGEN_H
