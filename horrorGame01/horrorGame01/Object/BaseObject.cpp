#include "BaseObject.h"

BaseObject::BaseObject(const Vector3f& pos, const Vector3f& angle, const Vector3f& scale, ObjectType type)
    :pos_(pos),angle_(angle),scale_(scale),objType_(type)
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

void BaseObject::Potision(Vector3f& pos)
{
    pos_ = pos;
}

void BaseObject::Angle(Vector3f& ang)
{
    angle_ = ang;
}

void BaseObject::Scale(Vector3f& scale)
{
    scale_ = scale;
}
