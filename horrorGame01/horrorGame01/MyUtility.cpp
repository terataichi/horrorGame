#include "MyUtility.h"

VECTOR MyUtility::VGet(const Vector3f& vec)
{
    return DxLib::VGet(vec.x_, vec.y_, vec.z_);
}

float MyUtility::DegToRad(float deg)
{
    return deg * (DX_PI_F / 180.0f);
}

float MyUtility::RadToDeg(float rad)
{
    return rad * (180.0f / DX_PI_F);
}

double MyUtility::RadIn2PI(float rad)
{
    rad = std::fmodf(rad, DX_TWO_PI_F);
    if (rad < 0.0f)
    {
        rad += DX_TWO_PI_F;
    }
    return rad;
}
