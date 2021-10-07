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
    if (lpSceneMng.GetInputManager().expired())
    {
        TRACE("Player : InputManagerが期限切れです");
        return;
    }
    auto mouse = lpSceneMng.GetInputManager().lock()->GetMouseInput();
    if (mouse.expired())
    {
        TRACE("Player : GetしたMouseInputが期限切れです");
        return;
    }
    auto mPos = mouse.lock()->GetPotision();

    auto player = std::dynamic_pointer_cast<Player>(targetObj_.lock());
    auto clampPos = player->GetMouseRangeMotion();
    auto height = player->GetGazeHeight();

    // 差分を求める
    auto diff = Vector2(clampPos) - mPos;
 

    // 注視点作成(プレイヤーの周りを円状に)
    float radius = 100;
    auto pos = pos_ + offset_;
    auto target = MyUtility::VGet(pos + Vector3f{
        std::sinf(angle_.y_) * radius,
        height,
        std::cosf(angle_.y_) * radius });

    SetCameraPositionAndTargetAndUpVec(MyUtility::VGet(pos),
        target,
        VECTOR{ 0.0f,1.0f,0.0f });

    // ライトの位置変更
    //auto dir = std::atan2f(pos.x_ - target.x, pos.z_ - target.z);

    //Vector3f lightPos = {
    //    pos.x_ - sinf(dir) * 5.0f,
    //    pos.y_,
    //    pos.z_ - sinf(dir) * 5.0f
    //};

    //SetLightPositionHandle(spotLight_,MyUtility::VGet(lightPos));
    //SetLightDirectionHandle(spotLight_, VSub(target, MyUtility::VGet(pos)));

}

void Camera::SetTarget(std::weak_ptr<BaseObject> target)
{
    targetObj_ = target;
}

void Camera::SetOffset(Vector3f offset)
{
    offset_ = offset;
}
