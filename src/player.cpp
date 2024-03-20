#include <iostream>
#include "player.h"

#include "sndGen.hpp"

Player::Player() {
    queue = std::vector<Sound>();
}

Player::~Player() {
    queue.clear();
}

void Player::addSound(Sound &o) {
    queue.push_back(o);
}

void Player::removeLast() {
    queue.pop_back();
}

void Player::clear() {
    queue.clear();
}

void Player::setQueue(std::vector<Sound> &o) {
    queue = o;
}

std::vector<Sound> Player::get_queue() {
    return queue;
}

void Player::play() {
    if (queue.empty()) {
        std::cerr << "Error: Queue is empty" << std::endl;
        return;
    }
    sf::Sound sound;
    sf::SoundBuffer buffer;
    sound.setBuffer(buffer);
    for (auto &i: queue) {
        sf::Int16 samples[static_cast<int>(SAMPLE_RATE * i.getDuration())];
        switch (i.getType()) {
            case SoundType::SineWave:
                sndGen::sineWave(samples, i.getFrequency(), i.getDuration(), i.getVolume());
                break;
            case SoundType::SawTooth:
                sndGen::sawTooth(samples, i.getFrequency(), i.getDuration(), i.getVolume());
                break;
            case SoundType::SquareWave:
                sndGen::squareWave(samples, i.getFrequency(), i.getDuration(), i.getVolume());
                break;
        }
        while (sound.getStatus() == sf::Sound::Playing) {}
        if (!buffer.loadFromSamples(samples, static_cast<int>(SAMPLE_RATE * i.getDuration()), 1, static_cast<int>(SAMPLE_RATE))) {
            std::cerr << "Error: Failed to load samples into sound buffer" << std::endl;
            return;
        }

        sound.play();
    }
}