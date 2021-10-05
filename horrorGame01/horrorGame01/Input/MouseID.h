#pragma once
#include <DxLib.h>

enum class MouseID
{
    Left,
    Right,
    Middle,
    Max
};

MouseID begin(MouseID);
MouseID end(MouseID);
MouseID operator++(MouseID& key);
MouseID operator* (MouseID key);