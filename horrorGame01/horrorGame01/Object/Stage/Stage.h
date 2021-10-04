#pragma once
#include <memory>

#include "../BaseObject.h"

class Model;

class Stage :
    public BaseObject
{
public:
    Stage(Vector3f&& pos, Vector3f&& angle, Vector3f&& scale);
    ~Stage();

    bool Init(void)override;
    bool Update(void)override;
    void Draw(void)override;

private:

    std::unique_ptr<Model>model_;
};

