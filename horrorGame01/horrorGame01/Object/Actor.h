#pragma once
#include <memory>
#include <string>

#include "BaseObject.h"

class Model;

// ƒ‚ƒfƒ‹‚ª‚ ‚é‚â‚Â
class Actor
	: public BaseObject
{
public:
    // modelPath‚ÍResource/Model/ˆÈ~‚ÌƒpƒX
    Actor(Vector3f& pos, Vector3f& angle, Vector3f& scale,ObjectType type);
    ~Actor();

    const int& GetModelHandle(void);
protected:
    bool ModelInit(std::string modelPath);
    std::unique_ptr<Model>model_;
private:

};

