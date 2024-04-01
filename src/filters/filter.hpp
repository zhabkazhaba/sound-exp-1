#ifndef SOUND_EXP_0_FILTER_HPP
#define SOUND_EXP_0_FILTER_HPP

#include <SFML/Config.hpp>
#include "../sound.hpp"

class Filter {
public:
    virtual ~Filter() = default;
    virtual sf::Int16 apply(sf::Int16 sample, int i, float frequency, float duration, float volume) = 0;
};

#endif //SOUND_EXP_0_FILTER_HPP
