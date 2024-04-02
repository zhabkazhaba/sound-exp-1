#include "sndgen.h"

#include <cmath>

namespace sndGen {
    void sineWave(sf::Int16* samples, float frequency, float duration, float volume) {
        for (int i = 0; i < SAMPLE_RATE * duration; ++i) {
            float time = i / SAMPLE_RATE;
            float value = std::sin(frequency * TWO_PI * time) * volume;
            samples[i] = static_cast<sf::Int16>(value * 32767);
        }
    }

    void sawTooth(sf::Int16* samples, float frequency, float duration, float volume) {
        for (int i = 0; i < SAMPLE_RATE * duration; ++i) {
            float time = i / SAMPLE_RATE;
            float value = (2 * std::fmod(time, 1.0f / frequency) * frequency - 1) * volume;
            samples[i] = static_cast<sf::Int16>(value * 32767);
        }
    }

    void squareWave(sf::Int16* samples, float frequency, float duration, float volume) {
        for (int i = 0; i < SAMPLE_RATE * duration; ++i) {
            float time = i / SAMPLE_RATE;
            //TODO(zhabkazhaba): fix volume
            float value = std::sin(frequency * TWO_PI * time) * volume;
            samples[i] = static_cast<sf::Int16>(value > 0 ? 32767 : -32767);
        }
    }

    void triangleWave(sf::Int16* samples, float frequency, float duration, float volume) {
        for (int i = 0; i < SAMPLE_RATE * duration; ++i) {
            float time = i / SAMPLE_RATE;
            float value = (2 * volume / M_PI) * std::asin(std::sin(frequency * TWO_PI * time));
            samples[i] = static_cast<sf::Int16>(value * 32767);
        }
    }
}
