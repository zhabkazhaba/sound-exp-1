#ifndef SOUND_EXP_0_SOUND_HPP
#define SOUND_EXP_0_SOUND_HPP

#include <SFML/Config.hpp>
#include <vector>
#include "filters/filter.hpp"
#include "sndgen.h"

enum class SoundType {
    SineWave,
    SawTooth,
    SquareWave,
    TriangleWave // TODO(zhabkazhaba): Add more types
};

class Sound {
 private:
    float frequency;
    float duration;
    float volume;
    SoundType type;
    std::vector<Filter*> filters;

    sf::Int16* samples;
 public:
    Sound() {
        frequency = 0.0f;
        duration = 0.0f;
        volume = 1.0f;
        type = SoundType::SineWave;
        samples = new sf::Int16[static_cast<int>(SAMPLE_RATE * duration)];
    }
    Sound(float frequency, float duration, float volume, SoundType type) {
        this->frequency = frequency;
        this->duration = duration;
        this->volume = volume;
        this->type = type;
        samples = new sf::Int16[static_cast<int>(SAMPLE_RATE * duration)];
    }
    template <typename... Filters>
    Sound(float frequency, float duration, float volume, SoundType type, Filters... filters) {
        this->frequency = frequency;
        this->duration = duration;
        this->volume = volume;
        this->type = type;
        this->filters = {filters...};
        samples = new sf::Int16[static_cast<int>(SAMPLE_RATE * duration)];
    }
    Sound(const Sound& o) {
        this->frequency = o.frequency;
        this->duration = o.duration;
        this->volume = o.volume;
        this->type = o.type;
        this->filters = o.filters;
        if (o.samples != nullptr) {
            samples = new sf::Int16[static_cast<int>(SAMPLE_RATE * duration)];
            for (int i = 0; i < static_cast<int>(SAMPLE_RATE * duration); ++i) {
                samples[i] = o.samples[i];
            }
        }
    }
    Sound operator=(const Sound& o) {
        this->frequency = o.frequency;
        this->duration = o.duration;
        this->volume = o.volume;
        this->type = o.type;
        this->filters = o.filters;
        if (o.samples != nullptr) {
            samples = new sf::Int16[static_cast<int>(SAMPLE_RATE * duration)];
            for (int i = 0; i < static_cast<int>(SAMPLE_RATE * duration); ++i) {
                samples[i] = o.samples[i];
            }
        }
        return *this;
    }
    ~Sound() {
        delete[] samples;
    }

    float getDuration() const { return duration; }
    sf::Int16* getSamples() {
        generateSamples();
        return samples;
    }

    void generateSamples() {
        switch (type) {
            case SoundType::SineWave:
                sndGen::sineWave(samples, frequency, duration, volume);
                break;
            case SoundType::SawTooth:
                sndGen::sawTooth(samples, frequency, duration, volume);
                break;
            case SoundType::SquareWave:
                sndGen::squareWave(samples, frequency, duration, volume);
                break;
            case SoundType::TriangleWave:
                sndGen::triangleWave(samples, frequency, duration, volume);
                break;
        }
        for (auto &filter : filters) {
            for (int i = 0; i < static_cast<int>(SAMPLE_RATE * duration); ++i) {
                samples[i] = filter->apply(samples[i], i, frequency, duration, volume);
            }
        }
    }
};


#endif //SOUND_EXP_0_SOUND_HPP
