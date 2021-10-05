#pragma once
#include <array>

#include "BaseInput.h"
class Keyboard :
    public BaseInput
{
public:
    Keyboard();
    ~Keyboard();

    void Update(void)override;
private:
    std::array<char, 256U> buf_;

};

