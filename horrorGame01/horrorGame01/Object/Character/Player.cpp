#include <DxLib.h>
#include <algorithm>

#include "Player.h"
#include "../../MyUtility.h"
#include "../../_debug/_DebugConOut.h"
#include "../../_debug/_DebugDispOut.h"

#include "../../Common/TimeManager.h"
#include "../../Scene/SceneManager.h"

#include "../../Input/InputManager.h"
#include "../../Input/InputID.h"
#include "../../Input/MouseID.h"
#include "../../Input/Mouse.h"
#include "../../Input/BaseInput.h"

#include "../Camera/Camera.h"

Player::Player(Vector3f pos, Vector3f angle, Vector3f scale,const int& stageModel)
	:BaseObject(pos, angle, scale, ObjectType::Player),stageModel_(stageModel)
{
	Init();
}

Player::~Player()
{
}

bool Player::Init(void)
{
	oldVelocity_ = {};
	velocity_ = {};
	gazeHeight_ = 0;
	chackMove_ = false;
	lightHeight_ = 0.0f;
	lightAngleY_ = 0.0f;

	rangeMotionRadian_ = RANGE_MOTION_RADIAN;
	rangeMotionHeight_ = RANGE_MOTION_HEIGHT;

	camera_ = std::make_shared<Camera>(Vector3f{}, Vector3f{}, Vector3f{});
	cameraOffset_ = { 0.0f,150.0f,0.0f };
	camera_->SetTarget(this);
	camera_->SetOffset(cameraOffset_);

	auto pos = pos_ + cameraOffset_;
	lightPos_ = Vector3f{ std::sinf(angle_.y_),0.0f,std::cosf(angle_.y_) }*(GAZE_POINT_RADIUS / 2);
	spotLight_ = CreateSpotLightHandle(
		MyUtility::VGet(pos + lightPos_),
		VSub(MyUtility::VGet(pos + lightPos_), MyUtility::VGet(pos)),
		DX_PI_F / 2.0f,
		DX_PI_F / 4.0f,
		5000.0f,
		0.0f,
		0.01f,
		0.0f);
	//SetLightPositionHandle(spotLight_, MyUtility::VGet(pos + mouse3DPos_));
	//SetLightDirectionHandle(spotLight_, VSub(MyUtility::VGet(pos + mouse3DPos_), MyUtility::VGet(pos)));
	return false;
}

bool Player::Update(void)
{

	if (lpSceneMng.GetInputManager().expired())
	{
		TRACE("Player : InputManagerが期限切れです");
		return false;
	}
	auto mouse = lpSceneMng.GetInputManager().lock()->GetMouseInput();
	if (mouse.expired())
	{
		TRACE("Player : GetしたMouseInputが期限切れです");
		return false;
	}

	float delta = lpTimeManager.GetDeltaTimeF();
	mPos_ = mouse.lock()->GetPotision();

	// 移動
	Move(delta);
	// 可動域セット
	LightMove(delta);

	// 最後にマウスの座標更新
	SetMousePoint((lpSceneMng.ScreenSize() / 2).x_,(lpSceneMng.ScreenSize() / 2).y_);

	auto pos = pos_ + cameraOffset_;
	SetLightPositionHandle(spotLight_, MyUtility::VGet(pos + lightPos_));
	SetLightDirectionHandle(spotLight_, VSub(MyUtility::VGet(pos + lightPos_), MyUtility::VGet(pos)));
	return true;
}

void Player::Draw(void)
{

#ifdef _DEBUG
	float radius = GAZE_POINT_RADIUS;
	auto p1 = pos_ + cameraOffset_;
	auto p2 = p1 + Vector3f{
		std::sinf(angle_.y_) * radius,
		gazeHeight_,
		std::cosf(angle_.y_) * radius };

	auto lightp = p1 + lightPos_;
	DrawSphere3D(MyUtility::VGet(p2), 1.0f, 32, GetColor(0, 250, 0), GetColor(0, 250, 0), TRUE);
	//DrawSphere3D(MyUtility::VGet(lightp), 1.0f, 32, GetColor(255, 0, 0), GetColor(255, 0, 0), TRUE);
#endif // _DEBUG
}

void Player::Hit(std::shared_ptr<BaseObject> hitObj_)
{
}

const float& Player::GetGazeHeight(void) const
{
	return gazeHeight_;
}

std::shared_ptr<Camera> Player::GetCamera(void) const
{
	return camera_;
}

void Player::CheckHItObject(std::shared_ptr<BaseObject> baseObj)
{
	
	float radius = 10.0f;
	auto p1 = pos_ + cameraOffset_;
	auto p2 = p1 + Vector3f{
		std::sinf(angle_.y_) * radius,
		gazeHeight_,
		std::cosf(angle_.y_) * radius };

	//// レイの方向ベクトル
	//Vector3f vec = p2 - p1;

	//auto p3 = baseObj->Potision() - vec;

	//float a = Dot(vec, vec);
	//float b = Dot(vec, p3);
	//float c = Dot(p3, p3) - radius * radius;

	//float s = b * b - a * c;
	//if (s < 0.0f)
	//{
	//	return;
	//}
	//s = sqrtf(s);
	//float a1 = (b - s) / a;
	//float a2 = (b + s) / a;

	//if (a1 < 0.0f || a2 < 0.0f)
	//{
	//	return;
	//}

	//int u = 0;
	auto check = HitCheck_Line_Sphere(MyUtility::VGet(p1),
		MyUtility::VGet(p2),
		MyUtility::VGet(baseObj->Potision()),
		100.0f);

	if (check)
	{
		baseObj->Active(false);
	}
}

bool Player::Move(float& delta)
{
	isHitMoveKey_ = false;

	if (lpSceneMng.GetInputManager().expired())
	{
		TRACE("Player : InputManagerが期限切れです");
		return false;
	}
	auto baseInput = lpSceneMng.GetInputManager().lock()->GetBaseInput();
	if (baseInput.expired())
	{
		TRACE("Player : GetしたBaseInputが期限切れです");
		return false;
	}
	// 入力されるたびに++
	int count = 0;
	// 前フレームの情報を保持
	oldVelocity_ = velocity_;
	velocity_ = {};
	auto move = [&](InputID&& id, float&& rad)
	{
		if (baseInput.lock()->GetPushingTrigger(id))
		{
			Vector3f dir{
				std::sinf(angle_.y_ + rad),
				0.0f,
				std::cosf(angle_.y_ + rad) };
			velocity_ += dir;
			isHitMoveKey_ = true;
			count++;
		}
	};

	move(InputID::Up, MyUtility::DegToRad(0.0f));
	move(InputID::Left, MyUtility::DegToRad(-90.0f));
	move(InputID::Down, MyUtility::DegToRad(180.0f));
	move(InputID::Right, MyUtility::DegToRad(90.0f));

	// 斜め移動の制御
	if (count > 1)
	{
		velocity_ = { std::sinf(DX_PI_F / 4.0f) * velocity_.x_,0.0f,std::cosf(DX_PI_F / 4.0f) * velocity_.z_ };
	}

	// ステージの当たり判定
	//auto hit = MV1CollCheck_Line(stageModel_, 0, MyUtility::VGet(pos_), MyUtility::VGet(pos_ + velocity_));
	

	// 床判定
	auto planeHit = MV1CollCheck_Line(
		stageModel_,
		-1, MyUtility::VGet(pos_ + cameraOffset_),
		MyUtility::VGet(pos_ - Vector3f{0.0f,(MOVESPEED * delta),0.0f}));

	if (!planeHit.HitFlag)
	{
		pos_.y_ -= (MOVESPEED * delta);
	}
	else
	{
		if (planeHit.HitPosition.y > pos_.y_)
		{
			pos_.y_ = planeHit.HitPosition.y;
		}
	}

	// 壁判定
	auto wallHit = MV1CollCheck_Capsule(stageModel_,
		-1,
		MyUtility::VGet(pos_ + cameraOffset_ + velocity_ * 2.0f),
		MyUtility::VGet(pos_ + (cameraOffset_ * 0.3f) + velocity_ * 2.0f),
		10.0f);

	if (wallHit.HitNum < 1)
	{
		pos_ += velocity_ * (MOVESPEED * delta);
	}
	return true;
}

void Player::LightMove(float& delta)
{
	rangeMotionRadian_ = RANGE_MOTION_RADIAN;
	rangeMotionHeight_ = RANGE_MOTION_HEIGHT;
	if (isHitMoveKey_)
	{
		// 可動域を０度にする
		rangeMotionRadian_ = 0.0f;
		rangeMotionHeight_ = 0.0f;
		lightAngleY_ *= 0.95f;
		lightPos_.y_ = gazeHeight_;
	}

	auto vec = static_cast<Vector2f>((lpSceneMng.ScreenSize() / 2) - mPos_);
	float angleVel = 0.0f;
	auto mMove = [&](bool check, float rad)
	{
		if (check)
		{
			angleVel = rad * delta;
		}
	};
	mMove(vec.x_ > MOUSE_THRESHOLD, MyUtility::DegToRad(-90.0f));
	mMove(vec.x_ < -MOUSE_THRESHOLD, MyUtility::DegToRad(90.0f));

	float heightSpeed = GAZE_POINT_RADIUS;
	float heightVel = 0;
	if (vec.y_ < -MOUSE_THRESHOLD)
	{
		heightVel = (-heightSpeed * delta);
	}
	else if (vec.y_ > MOUSE_THRESHOLD)
	{
		heightVel = (heightSpeed * delta);
	}
	
	// 高さの判定
	float nextHeight = lightHeight_ + heightVel;
	if (nextHeight <= -rangeMotionHeight_ || nextHeight >= rangeMotionHeight_)
	{
		lightHeight_ = -rangeMotionHeight_;
		if (nextHeight >= rangeMotionHeight_)
		{
			lightHeight_ = rangeMotionHeight_;
		}
		gazeHeight_ += heightVel;
		gazeHeight_ = std::clamp(gazeHeight_, -GAZEPOINT_MAX_HEIGHT, GAZEPOINT_MAX_HEIGHT);
	}
	else
	{
		lightHeight_ += heightVel;
		lightPos_.y_ = lightHeight_;
	}

	// 回転の制限
	float nextRad = angle_.y_ + lightAngleY_ + angleVel;

	// 仮座標変換
	Vector3f nextPos = {
		std::sinf(nextRad) * GAZE_POINT_RADIUS,
		0,
		std::cosf(nextRad) * GAZE_POINT_RADIUS };

	if (std::abs(lightAngleY_ + angleVel) > rangeMotionRadian_)
	{
		angle_.y_ += angleVel;
	}
	else
	{
		lightAngleY_ += angleVel;
	}
	lightPos_.x_ = nextPos.x_;
	lightPos_.z_ = nextPos.z_;
};
