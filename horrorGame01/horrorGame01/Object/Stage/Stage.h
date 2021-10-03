#pragma once
#include <memory>

#include "../BaseObject.h"
#include "../../Model/Model.h"

class Stage :
    public BaseObject
{
public:
    Stage(Vector3f&& pos, Vector3f&& angle, Vector3f&& scale);
    ~Stage();

private:

    std::unique_ptr<Model>model_;
};

