#include "Camera.h"
#include <DxLib.h>
#include <algorithm>

#include "../../MyUtility.h"
#include "../../Scene/SceneManager.h"
#include "../../Input/InputManager.h"
#include "../../Common/TimeManager.h"
#include "../../Input/Mouse.h"
#include "../Character/Player.h"
#include "../../_debug/_DebugConOut.h"

Camera::Camera(Vector3f pos, Vector3f angle, Vector3f scale)
    :BaseObject(pos, angle, scale,ObjectType::Camera)
{
    Init();
}

Camera::~Camera()
{
    targetObj_ = nullptr;
}

bool Camera::Init(void)
{
    SetCameraPositionAndAngle(
        MyUtility::VGet(pos_), angle_.x_, angle_.y_, angle_.z_
    );
    offset_ = {};
    return true;
}

bool Camera::Update(void)
{
    if (targetObj_ == nullptr)
    {
        return false;
    }

    pos_ = targetObj_->Potision();
    angle_ = targetObj_->Angle();
    return true;
}

void Camera::Draw(void)
{
    auto player = dynamic_cast<Player*>(targetObj_);
    // 一応ガード
    if (!player)
    {
        return;
    }
    auto height = player->GetGazeHeight();
 
    // 注視点作成(プレイヤーの周りを円状に)
    float radius = player->GAZE_POINT_RADIUS;
    auto pos = pos_ + offset_;
    auto target = MyUtility::VGet(pos + Vector3f{
        std::sinf(angle_.y_) * radius,
        height,
        std::cosf(angle_.y_) * radius });

    SetCameraPositionAndTargetAndUpVec(MyUtility::VGet(pos),
        target,
        VECTOR{ 0.0f,1.0f,0.0f });

    //DrawSphere3D(target, 5.0f, 32, GetColor(255, 0, 0), GetColor(255, 255, 255), TRUE);
}

void Camera::SetTarget(BaseObject* target)
{
    targetObj_ = target;
}

void Camera::SetOffset(Vector3f offset)
{
    offset_ = offset;
}
