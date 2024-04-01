#ifndef SOUND_EXP_0_PLAYER_H
#define SOUND_EXP_0_PLAYER_H

#include <vector>
#include <SFML/Audio.hpp>
#include "sound.hpp"
#include "sndgen.h"
#include "sample.hpp"

class Player {
private:
    std::vector<Sound> beep_channel;
    std::vector<Sample> sample_channel;
public:
    Player();
    ~Player();
    void play();
    void addSound(const Sound &o);
    void removeLast();
    void clear();
    void setBeepChannel(std::vector<Sound> &o);
    std::vector<Sound> getBeepChannel();

    void addSample(const Sample &o);
};


#endif //SOUND_EXP_0_PLAYER_H
