//
// Created by zhabkazhaba on 3/19/24.
//

#include "sound.h"

Sound::Sound() {
    frequency = 0.0f;
    duration = 0.0f;
    volume = 1.0f;
    type = SoundType::SineWave;
}

Sound::Sound(float frequency, float duration, float volume, SoundType type) {
    this->frequency = frequency;
    this->duration = duration;
    this->volume = volume;
    this->type = type;
}

Sound::Sound(const Sound &o) {
    this->frequency = o.frequency;
    this->duration = o.duration;
    this->volume = o.volume;
    this->type = o.type;
}