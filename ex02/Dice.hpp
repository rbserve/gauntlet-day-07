#pragma once
#include "RandomSource.hpp"

// Dice.hpp: before the refactor, untestable
class Dice {
public:
    Dice(RandomSource& rng) : m_rng(rng){};
    int roll(){ return m_rng.next(6) + 1; }   // randomness baked in, so an exact CHECK is impossible
private:
    RandomSource& m_rng;
};