#include <iostream>
#include "sound.hpp"
#include "player.h"
#include "filters/linvolchange.hpp"

int main() {
    LinVolChange lvc(0.1f);
    Sound s1(440.0f, 1.0f, 1.0f, SoundType::TriangleWave);
    Sound s2(220.0f, 1.0f, 1.0f, SoundType::SineWave);
    Sound s3(330.0f, 5.0f, 2.0f, SoundType::SawTooth, &lvc);
    Player p;
    p.addSound(s1);
    p.addSound(s2);
    p.addSound(s1);
    p.addSound(s3);
    p.play(Channel::BEEP_CH1);
    return 0;
}
