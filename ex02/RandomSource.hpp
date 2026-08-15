#pragma once
#include <cstdlib>

struct RandomSource {                    
    virtual int next(int max){return std::rand() % max;};
    virtual ~RandomSource() = default;
};