#pragma once
#include <memory>
#include "../BaseObject.h"

class Camera :
    public BaseObject
{
public:
    Camera(Vector3f pos, Vector3f angle, Vector3f scale, Vector3f offset = {});
    ~Camera();

    bool Init(void)override;
    bool Update(void)override;
    void Draw(void)override;

    void SetTarget(std::weak_ptr<BaseObject> target);

private:
    static constexpr float MAX_HEIGHT = 100.0f;

    // カメラが追従するオブジェクトのポインタ
    std::weak_ptr<BaseObject> targetObj_;

    Vector3f offset_;
    float height_;
    float speedY_;
};

