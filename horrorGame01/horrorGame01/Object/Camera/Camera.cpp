#include "Camera.h"
#include <DxLib.h>
#include <algorithm>

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

    speedY_ = 10;

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
        return;
    };

    auto mng = lpSceneMng.GetInputManager();
    auto mouse = mng.lock()->GetMouseInput();

    // プレイヤーイの向いている方向
    // XZで円を作る
    auto diff = Vector2f{ lpSceneMng.ScreenSize() / 2 - mouse.lock()->GetPotision() };
    float radius = 100;
    // Yは高さを変えるだけなので
    // 下限上限の設定
    height_ = min(max(height_, -MAX_HEIGHT), MAX_HEIGHT);
    height_ += diff.y_ * lpTimeManager.GetDeltaTimeF() * speedY_;


    auto pos = pos_ + offset_;
    auto target = MyUtility::VGet(pos + Vector3f{
        std::sinf(angle_.y_) * radius,
        height_,
        std::cosf(angle_.y_) * radius });

    SetCameraPositionAndTargetAndUpVec(MyUtility::VGet(pos),
        target,
        VECTOR{ 0.0f,1.0f,0.0f });

    ChangeLightTypePoint(MyUtility::VGet(pos), 700.0f, 1.0f, 0.01f, 0.0f);

    //ChangeLightTypeSpot(MyUtility::VGet(pos),
    //    MyUtility::VGet({ angle_.x_,angle_.y_,MyUtility::DegToRad(0) }),
    //    MyUtility::DegToRad(90.0f),
    //    MyUtility::DegToRad(45.0f),
    //    1000.0f,
    //    0.0f,0.01f,0.0f);
}

void Camera::SetTarget(std::weak_ptr<BaseObject> target)
{
    targetObj_ = target;
    height_ = targetObj_.lock()->Potision().y_;
}
