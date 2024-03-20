//
// Created by zhabkazhaba on 3/19/24.
//

#ifndef SOUND_EXP_0_SOUND_H
#define SOUND_EXP_0_SOUND_H

#include <SFML/Config.hpp>

enum class SoundType {
    SineWave,
    SawTooth,
    SquareWave //TODO: Add more types
};

class Sound {
private:
    float frequency;
    float duration;
    float volume;
    SoundType type;
public:
    Sound();
    Sound(float frequency, float duration, float volume, SoundType type);
    Sound(const Sound& o);
    ~Sound() = default;
    float getFrequency() const { return frequency; }
    float getDuration() const { return duration; }
    float getVolume() const { return volume; }
    SoundType getType() const { return type; }
};


#endif //SOUND_EXP_0_SOUND_H
