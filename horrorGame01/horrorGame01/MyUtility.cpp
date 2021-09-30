#include "MyUtility.h"

VECTOR MyUtility::VGet(const Vector3f& vec)
{
    return DxLib::VGet(vec.x_, vec.y_, vec.z_);
}
