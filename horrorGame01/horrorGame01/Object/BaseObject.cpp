#include "BaseObject.h"

BaseObject::BaseObject(const Vector3f& pos, const Vector3f& angle, const Vector3f& scale, ObjectType type)
    :pos_(pos),angle_(angle),scale_(scale),objType_(type)
{
}

BaseObject::~BaseObject()
{
}

void BaseObject::Hit(std::shared_ptr<BaseObject> hitObj_)
{
}

void BaseObject::CheckHitCollision(std::shared_ptr<BaseObject> mySelf, std::vector<std::shared_ptr<BaseObject>> list)
{
    for (auto& obj : list)
    {
        // 自分自身ははじく
        if (mySelf == obj)
        {
            continue;
        }

        // 当たり判定
        if (mySelf->IsHit(obj))
        {
            // 当たったら当たった処理を呼び出す
            obj->Hit(obj);
        }
    }
}

bool BaseObject::IsHit(std::shared_ptr<BaseObject> target)
{
    // 当たり判定しなくていい奴はオーバーライドさせなくていい
    return false;
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
