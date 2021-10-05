#include "Camera.h"
#include <DxLib.h>

#include "../../MyUtility.h"
#include "../../Scene/SceneManager.h"
#include "../../Input/InputManager.h"
#include "../../Common/TimeManager.h"
#include "../../Input/Mouse.h"


Camera::Camera(Vector3f pos, Vector3f angle, Vector3f scale,Vector3f offset)
    :BaseObject(pos, angle, scale),offset_(offset)
{
    Init();
}

Camera::~Camera()
{
}

bool Camera::Init(void)
{
    SetCameraPositionAndAngle(
        MyUtility::VGet(pos_), angle_.x_, angle_.y_, angle_.z_
    );

    return true;
}

bool Camera::Update(void)
{
    if (targetObj_.expired())
    {
        return false;
    }

    pos_ = targetObj_.lock()->Potision();
    angle_ = targetObj_.lock()->Angle();
    return true;
}

void Camera::Draw(void)
{
    //SetCameraPositionAndAngle(
    //    MyUtility::VGet(pos_ + offset_), angle_.x_, angle_.y_, angle_.z_
    //);

    if (lpSceneMng.GetInputManager().expired())
    {
        return;
    };

    auto mng = lpSceneMng.GetInputManager();
    auto mouse = mng.lock()->GetMouseInput();

    auto diff = Vector2f{ lpSceneMng.ScreenSize() / 2 - mouse.lock()->GetPotision() };

    float radius = 100;

    height_ += diff.y_ * lpTimeManager.GetDeltaTimeF() * 40;

    auto pos = pos_ + offset_;

    SetCameraPositionAndTargetAndUpVec(MyUtility::VGet(pos),
        MyUtility::VGet(pos + Vector3f{
            std::sinf(angle_.y_) * radius,
            height_,
            std::cosf(angle_.y_) * radius }),
        VECTOR{ 0.0f,1.0f,0.0f });

    //SetCameraPositionAndTarget_UpVecY(MyUtility::VGet(pos_), MyUtility::VGet(pos_));
}

void Camera::SetTarget(std::weak_ptr<BaseObject> target)
{
    targetObj_ = target;
    height_ = targetObj_.lock()->Potision().y_;
}
