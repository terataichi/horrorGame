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
	rotateSpeedX_ = 10;
	oldVelocity_ = {};
	velocity_ = {};
	gazeHeight_ = 0;
	chackMove_ = false;

	camera_ = std::make_shared<Camera>(Vector3f{}, Vector3f{}, Vector3f{});
	cameraOffset_ = { 0.0f,150.0f,0.0f };
	camera_->SetTarget(this);
	camera_->SetOffset(cameraOffset_);

	auto pos = pos_ + cameraOffset_;

	lightPosCenter_ = Vector3f{ std::sinf(angle_.y_),0.0f,std::cosf(angle_.y_) }*(GAZE_POINT_RADIUS / 2);
	lightPos_ = lightPosCenter_;
	spotLight_ = CreateSpotLightHandle(
		MyUtility::VGet(pos + lightPos_),
		VSub(MyUtility::VGet(pos + lightPos_), MyUtility::VGet(pos)),
		DX_PI_F / 2.0,
		DX_PI_F / 4.0f,
		1000.0f,
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

	rotateVel_ = {};
	float delta = lpTimeManager.GetDeltaTimeF();
	mPos_ = mouse.lock()->GetPotision();

	// 中心と、可動域の設定
	lightPosCenter_ = Vector3f{ std::sinf(angle_.y_),0.0f,std::cosf(angle_.y_) } *(GAZE_POINT_RADIUS / 2);
	// Max
	Vector3f vel =
		Vector3f{ std::sinf(angle_.y_ + MyUtility::DegToRad(90)),
		0.0f,
		std::cosf(angle_.y_ + MyUtility::DegToRad(90)) };
	lightPosMax_ = lightPosCenter_ + vel * 40.0f;
	lightPosMax_.y_ = 20;
	// Min
	vel = Vector3f{ std::sinf(angle_.y_ + MyUtility::DegToRad(-90)),
		0.0f,
		std::cosf(angle_.y_ + MyUtility::DegToRad(-90)) };
	lightPosMin_ = lightPosCenter_ + vel * 40.0f;
	lightPosMin_.y_ = -20;

	// 移動
	Move(delta);
	LightMove(delta);
	Rotate(delta);

	//auto pos = pos_ + cameraOffset_;
	_dbgDrawBox(0, 0, 500, 100, 0xffffff, true);
	_dbgDrawFormatString(10, 20, 0xff, "Light : %f:%f:%f", (lightPos_).x_, (lightPos_).y_, (lightPos_).z_);
	_dbgDrawFormatString(10, 40, 0xff, "Min   : %f:%f:%f", (lightPosMin_).x_, (lightPosMin_).y_, (lightPosMin_).z_);
	_dbgDrawFormatString(10, 60, 0xff, "Max   : %f:%f:%f", (lightPosMax_).x_, (lightPosMax_).y_, (lightPosMax_).z_);
	_dbgDrawFormatString(10, 80, 0xff, "angle   : %f:%f:%f", (angle_).x_, MyUtility::RadToDeg(angle_.y_), (angle_).z_);

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
	auto pos = pos_ + cameraOffset_;

	DrawSphere3D(MyUtility::VGet(pos + lightPos_), 1.0f, 32, GetColor(255, 0, 0), GetColor(255, 0, 0), TRUE);
	DrawSphere3D(MyUtility::VGet(pos + lightPosCenter_), 1.0f, 32, GetColor(255, 0, 0), GetColor(255, 0, 0), TRUE);
	DrawSphere3D(MyUtility::VGet(pos + lightPosMax_), 1.0f, 32, GetColor(255, 0, 0), GetColor(255, 0, 0), TRUE);
	DrawSphere3D(MyUtility::VGet(pos + lightPosMin_), 1.0f, 32, GetColor(255, 0, 0), GetColor(255, 0, 0), TRUE);

	Vector3f line1 = (pos + lightPosMin_);
	line1.z_ += lightPosMax_.z_;
	DrawLine3D(MyUtility::VGet(pos + lightPosMin_), MyUtility::VGet(line1), 0xff);
	Vector3f line2 = (pos + lightPosMin_);
	line2.y_ += lightPosMax_.y_;
	DrawLine3D(MyUtility::VGet(pos + lightPosMin_), MyUtility::VGet(line2), 0xff);
	Vector3f line3 = (pos + lightPosMin_);
	line3.x_ += lightPosMax_.x_;
	DrawLine3D(MyUtility::VGet(pos + lightPosMin_), MyUtility::VGet(line3), 0xff);

	Vector3f line4 = (pos + lightPosMax_);
	line4.z_ += lightPosMin_.z_;
	DrawLine3D(MyUtility::VGet(pos + lightPosMax_), MyUtility::VGet(line4), 0xff);
	Vector3f line5 = (pos + lightPosMax_);
	line5.y_ += lightPosMin_.y_;
	DrawLine3D(MyUtility::VGet(pos + lightPosMax_), MyUtility::VGet(line5), 0xff);
	Vector3f line6 = (pos + lightPosMax_);
	line6.x_ += lightPosMin_.x_;
	DrawLine3D(MyUtility::VGet(pos + lightPosMax_), MyUtility::VGet(line6), 0xff);

	// なんかおかしい
	//auto pos = pos_ + cameraOffset_;
	//_dbgDrawFormatString(100, 100, 0xff, "%f:%f:%f", (pos + lightPos_).x_, (pos + lightPos_).y_, (pos + lightPos_).z_);
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

bool Player::Move(float& delta)
{
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
	auto hit = MV1CollCheck_Line(stageModel_, 0, MyUtility::VGet(pos_), MyUtility::VGet(pos_ + velocity_));

	if (!hit.HitFlag)
	{
		pos_ += velocity_ * (MOVESPEED * delta);
	}
	return true;
}

bool Player::Rotate(float& delta)
{
	auto clampMPos = GetMouseRangeMotion();
	
	// 差分を求める
	//auto diff = Vector2(clampMPos) - mPos_;

	if (rotateVel_ != Vector3f{})
	{
		// Yは高さを変えるだけなので
		// 下限上限の設定
		gazeHeight_ += rotateVel_.y_;
		gazeHeight_ = std::clamp(gazeHeight_, -GAZEPOINT_MAX_HEIGHT, GAZEPOINT_MAX_HEIGHT);
		//angle_.x_ -= MyUtility::DegToRad(diff.y_ * rotateSpeedX_ * delta);
		angle_.y_ -= MyUtility::DegToRad(rotateVel_.x_) + MyUtility::DegToRad(rotateVel_.z_);
		//angle_.y_ += MyUtility::DegToRad(10.0f * delta);
		//angle_.y_ -= std::atan2f(rotateVel_.x_, rotateVel_.z_);
	}

	return true;
}

void Player::LightMove(float& delta)
{
	auto vec = static_cast<Vector2f>((lpSceneMng.ScreenSize() / 2) - mPos_);
	Vector3f vel = {};
	float testSpeed = 100.0f;
	auto mMove = [&](bool check, float rad)
	{
		if (check)
		{
			Vector3f dir{
			std::sinf(angle_.y_ + rad),
			0.0f,
			std::cosf(angle_.y_ + rad)};
			vel += dir;
		}
	};

	mMove(vec.x_ > MOUSE_THRESHOLD, MyUtility::DegToRad(-90.0f));
	mMove(vec.x_ < -MOUSE_THRESHOLD, MyUtility::DegToRad(90.0f));
	if (vec.y_ < -MOUSE_THRESHOLD)
	{
		vel.y_ += (-testSpeed * delta);
	}
	else if (vec.y_ > MOUSE_THRESHOLD)
	{
		vel.y_ += (testSpeed * delta);
	}


	// 制限
	auto tmp = lightPos_ + vel;
	if (tmp.y_ < lightPosMin_.y_ || tmp.y_ > lightPosMax_.y_)
	{
		rotateVel_.y_ = vel.y_;
		vel.y_ = 0;
	}
	// 回転すると制限が逆転する場合があるから
	// MinとMax入れ替え
	if (lightPosMin_.x_ > lightPosMax_.x_)
	{
		std::swap(lightPosMin_.x_, lightPosMax_.x_);
	}
	if (lightPosMin_.z_ > lightPosMax_.z_)
	{
		std::swap(lightPosMin_.z_, lightPosMax_.z_);
	}
	if (tmp.x_ < lightPosMin_.x_ || tmp.x_ > lightPosMax_.x_)
	{
		rotateVel_.x_ = vel.x_;
		vel.x_ = 0;
	}
	if (tmp.z_ < lightPosMin_.z_ || tmp.z_ > lightPosMax_.z_)
	{
		rotateVel_.z_ = vel.z_;
		vel.z_ = 0;
	}

	lightPos_ += vel;

	if (velocity_ != Vector3f{})
	{
		lightPos_ = lightPosCenter_;
	}
}

Vector2f Player::GetMouseRangeMotion()
{
	if (lpSceneMng.GetInputManager().expired())
	{
		TRACE("Player : InputManagerが期限切れです");
		return {};
	}
	auto mouse = lpSceneMng.GetInputManager().lock()->GetMouseInput();
	if (mouse.expired())
	{
		TRACE("Player : GetしたMouseInputが期限切れです");
		return {};
	}

	// 押した瞬間だけは中心におく
	if (oldVelocity_ == Vector3f{} && velocity_ != Vector3f{})
	{
		mPos_ = lpSceneMng.ScreenSize() / 2;
	}
	// マウスの可動域
	// 可動域の倍率
	float minVolume = MOUSE_RANGE_MIN;
	float maxVolume = MOUSE_RANGE_MAX;

	// 動いてるときは可動域を中心にする
	if (velocity_ != Vector3f{})
	{
		minVolume = MOUSE_RANGE_MIDDLE;
		maxVolume = MOUSE_RANGE_MIDDLE;
	}

	Vector2f min = { static_cast<float>(lpSceneMng.ScreenSize().x_) * minVolume ,
	static_cast<float>(lpSceneMng.ScreenSize().y_) * minVolume };
	Vector2f max = { static_cast<float>(lpSceneMng.ScreenSize().x_) * maxVolume ,
	static_cast<float>(lpSceneMng.ScreenSize().y_) * maxVolume };

	Vector2f clampPos;
	clampPos.x_ = std::clamp(static_cast<float>(mPos_.x_), min.x_, max.x_);
	clampPos.y_ = std::clamp(static_cast<float>(mPos_.y_), min.y_, max.y_);

	return clampPos;
}
