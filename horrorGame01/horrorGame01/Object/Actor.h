#pragma once
#include <memory>
#include <string>

#include "BaseObject.h"

class Model;

// モデルがあるやつ
class Actor
	: public BaseObject
{
public:
    // modelPathはResource/Model/以降のパス
    Actor(Vector3f& pos, Vector3f& angle, Vector3f& scale,ObjectType type);
    ~Actor();

    const int& GetModelHandle(void);
protected:
    bool ModelInit(std::string modelPath);
    std::unique_ptr<Model>model_;
private:

};

