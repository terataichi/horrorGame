#pragma once
#include <memory>

#include "../Actor.h"

class Model;

class Stage :
    public Actor
{
public:
    Stage(Vector3f&& pos, Vector3f&& angle, Vector3f&& scale);
    ~Stage();

    bool Init(void)override;
    bool Update(void)override;
    void Draw(void)override;

    void Hit(std::shared_ptr<BaseObject> hitObj_)override;
    bool IsHit(std::shared_ptr<BaseObject> target)override;
private:
};

