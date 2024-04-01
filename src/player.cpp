#include <iostream>
#include "./player.h"
#include <vector>

Player::Player() {
    beep_channel = std::vector<Sound>();
}

Player::~Player() {
    beep_channel.clear();
}

void Player::addSound(const Sound &o) {
    beep_channel.push_back(o);
}

void Player::removeLast() {
    beep_channel.pop_back();
}

void Player::clear() {
    beep_channel.clear();
}

void Player::setBeepChannel(std::vector<Sound> &o) {
    beep_channel = o;
}

std::vector<Sound> Player::getBeepChannel() {
    return beep_channel;
}

void Player::play() {
    if (beep_channel.empty()) {
        std::cerr << "Error: Queue is empty" << std::endl;
        return;
    }
    sf::Sound sound;
    sf::SoundBuffer buffer;
    for (auto &i : beep_channel) {
        if (!buffer.loadFromSamples(i.getSamples(), static_cast<int>(SAMPLE_RATE * i.getDuration()), 1, static_cast<int>(SAMPLE_RATE))) {
            std::cerr << "Error: Failed to load samples into sound buffer" << std::endl;
            return;
        }
        sound.setBuffer(buffer);
        sound.play();
        while (sound.getStatus() == sf::Sound::Playing) {}
    }
}

void Player::addSample(const Sample &o) {
    sample_channel.push_back(o);
}