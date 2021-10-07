#pragma once
#include <memory>
#include "../BaseObject.h"

class Camera :
    public BaseObject
{
public:
    Camera(Vector3f pos, Vector3f angle, Vector3f scale);
    ~Camera();

    bool Init(void)override;
    bool Update(void)override;
    void Draw(void)override;

    void SetTarget(std::weak_ptr<BaseObject> target);
    void SetOffset(Vector3f offset);
private:

    // カメラが追従するオブジェクトのポインタ
    std::weak_ptr<BaseObject> targetObj_;

    Vector3f offset_;
    float speedY_;
    // ライトのハンドル保持用
    //int spotLight_;
};

