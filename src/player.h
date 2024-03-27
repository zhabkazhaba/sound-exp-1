#ifndef SOUND_EXP_0_PLAYER_H
#define SOUND_EXP_0_PLAYER_H

#include <vector>
#include <SFML/Audio.hpp>
#include "sound.hpp"
#include "sndgen.h"

class Player {
private:
    std::vector<Sound> queue;
public:
    Player();
    ~Player();
    void play();
    void addSound(const Sound &o);
    void removeLast();
    void clear();
    void setQueue(std::vector<Sound> &o);
    std::vector<Sound> get_queue();
};


#endif //SOUND_EXP_0_PLAYER_H
