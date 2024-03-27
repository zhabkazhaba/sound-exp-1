#include <iostream>
#include "./player.h"
#include <vector>

Player::Player() {
    queue = std::vector<Sound>();
}

Player::~Player() {
    queue.clear();
}

void Player::addSound(const Sound &o) {
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
    for (auto &i : queue) {
        if (!buffer.loadFromSamples(i.getSamples(), static_cast<int>(SAMPLE_RATE * i.getDuration()), 1, static_cast<int>(SAMPLE_RATE))) {
            std::cerr << "Error: Failed to load samples into sound buffer" << std::endl;
            return;
        }
        sound.setBuffer(buffer);
        sound.play();
        while (sound.getStatus() == sf::Sound::Playing) {}
    }
}