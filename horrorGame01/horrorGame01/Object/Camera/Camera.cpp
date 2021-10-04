#include "Camera.h"
#include <DxLib.h>

#include "../../MyUtility.h"

Camera::Camera(Vector3f pos, Vector3f angle, Vector3f scale)
    :BaseObject(pos, angle, scale)
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
    return false;
}

void Camera::Draw(void)
{
    SetCameraPositionAndAngle(
        MyUtility::VGet(pos_), angle_.x_, angle_.y_, angle_.z_
    );
}

void Camera::SetTarget(std::weak_ptr<BaseObject> target)
{
    targetObj_ = target;
}
