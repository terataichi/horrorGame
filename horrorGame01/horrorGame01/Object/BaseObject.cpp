#include "BaseObject.h"

BaseObject::BaseObject(const Vector3f& pos, const Vector3f& angle, const Vector3f& scale)
    :pos_(pos),angle_(angle),scale_(scale)
{
}

BaseObject::~BaseObject()
{
}

const Vector3f& BaseObject::Potision(void) const
{
    return pos_;
}

const Vector3f& BaseObject::Angle(void) const
{
    return angle_;
}

const Vector3f& BaseObject::Scale(void) const
{
    return scale_;
}
