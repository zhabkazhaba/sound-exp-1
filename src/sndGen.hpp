#ifndef SOUND_EXP_0_SNDGEN_HPP
#define SOUND_EXP_0_SNDGEN_HPP


#include <SFML/Config.hpp>
#include <cmath>

const float SAMPLE_RATE = 44100.0f;
const float TWO_PI = 6.28318530718f;

namespace sndGen {
    void sineWave(sf::Int16* samples, float frequency, float duration, float volume = 1.0f) {
        for (int i = 0; i < SAMPLE_RATE * duration; ++i) {
            float time = i / SAMPLE_RATE;
            float value = sin(frequency * TWO_PI * time) * volume;
            samples[i] = static_cast<sf::Int16>(value * 32767);
        }
    }

    void sawTooth(sf::Int16* samples, float frequency, float duration, float volume = 1.0f) {
        for (int i = 0; i < SAMPLE_RATE * duration; ++i) {
            float time = i / SAMPLE_RATE;
            float value = (2 * fmod(time, 1.0f / frequency) * frequency - 1) * volume;
            samples[i] = static_cast<sf::Int16>(value * 32767);
        }
    }

    void squareWave(sf::Int16* samples, float frequency, float duration, float volume = 1.0f) {
        for (int i = 0; i < SAMPLE_RATE * duration; ++i) {
            float time = i / SAMPLE_RATE;
            float value = sin(frequency * TWO_PI * time) * volume;
            samples[i] = static_cast<sf::Int16>(value > 0 ? 32767 : -32767);
        }
    }
}


#endif //SOUND_EXP_0_SNDGEN_HPP
