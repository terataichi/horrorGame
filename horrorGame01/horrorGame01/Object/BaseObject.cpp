#include "BaseObject.h"

BaseObject::BaseObject(const Vector3f& pos, const Vector3f& rad, const Vector3f& scale)
{
}

BaseObject::~BaseObject()
{
}

const Vector3f& BaseObject::Potision(void) const
{
    return pos_;
}

const Vector3f& BaseObject::Radian(void) const
{
    return rad_;
}

const Vector3f& BaseObject::Scale(void) const
{
    return scale_;
}
