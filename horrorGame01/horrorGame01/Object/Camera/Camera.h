#pragma once
#include <memory>
#include "../BaseObject.h"

class Camera :
    public BaseObject
{
public:
    Camera(Vector3f pos, Vector3f angle, Vector3f scale = { 1.0f,1.0f,1.0f });
    ~Camera();

    bool Init(void)override;
    bool Update(void)override;
    void Draw(void)override;

    void SetTarget(std::weak_ptr<BaseObject> target);
private:

    // カメラが追従するオブジェクトのポインタ
    std::weak_ptr<BaseObject> targetObj_;
};

