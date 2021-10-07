#include <DxLib.h>
#include <algorithm>

#include "Player.h"
#include "../../MyUtility.h"
#include "../../_debug/_DebugConOut.h"
#include "../../_debug/_DebugDispOut.h"

#include "../../Common/TimeManager.h"

#include "../../Input/InputManager.h"
#include "../../Input/InputID.h"
#include "../../Input/MouseID.h"
#include "../../Input/Mouse.h"
#include "../../Input/BaseInput.h"

#include "../../Scene/SceneManager.h"

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
	pointLight_ = CreatePointLightHandle(MyUtility::VGet(pos_), 1000.0f, 0.5f, 0.01f, 0.0f);
	return false;
}

bool Player::Update(void)
{

	if (lpSceneMng.GetInputManager().expired())
	{
		TRACE("Player : InputManager�������؂�ł�");
		return false;
	}
	auto mouse = lpSceneMng.GetInputManager().lock()->GetMouseInput();
	if (mouse.expired())
	{
		TRACE("Player : Get����MouseInput�������؂�ł�");
		return false;
	}

	float delta = lpTimeManager.GetDeltaTimeF();
	mPos_ = mouse.lock()->GetPotision();

	// �ړ�
	Move(delta);
	Rotate(delta);


	SetLightPositionHandle(pointLight_, MyUtility::VGet(pos_));

	return true;
}

void Player::Draw(void)
{
}

void Player::Hit(std::shared_ptr<BaseObject> hitObj_)
{
}


const float& Player::GetGazeHeight(void) const
{
	return gazeHeight_;
}

bool Player::Move(float& delta)
{
	if (lpSceneMng.GetInputManager().expired())
	{
		TRACE("Player : InputManager�������؂�ł�");
		return false;
	}
	auto baseInput = lpSceneMng.GetInputManager().lock()->GetBaseInput();
	if (baseInput.expired())
	{
		TRACE("Player : Get����BaseInput�������؂�ł�");
		return false;
	}
	// ���͂���邽�т�++
	int count = 0;
	// �O�t���[���̏���ێ�
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
			velocity_ += dir * (MOVESPEED * delta);
			count++;
		}
	};

	move(InputID::Up, MyUtility::DegToRad(0.0f));
	move(InputID::Left, MyUtility::DegToRad(-90.0f));
	move(InputID::Down, MyUtility::DegToRad(180.0f));
	move(InputID::Right, MyUtility::DegToRad(90.0f));

	// �΂߈ړ��̐���
	if (count > 1)
	{
		velocity_ = { std::sinf(DX_PI_F / 4.0f) * velocity_.x_,0.0f,std::cosf(DX_PI_F / 4.0f) * velocity_.z_ };
	}

	// �X�e�[�W�̓����蔻��
	auto hit = MV1CollCheck_Line(stageModel_, 0, MyUtility::VGet(pos_), MyUtility::VGet(pos_ + velocity_));

	if (!hit.HitFlag)
	{
		pos_ += velocity_;
	}
	_dbgDrawFormatString(100, 100, 0xff, "%f:%f:%f", pos_.x_, pos_.y_, pos_.z_);
	return true;
}

bool Player::Rotate(float& delta)
{
	auto clampPos = GetMouseRangeMotion();
	
	// ���������߂�
	auto diff = Vector2(clampPos) - mPos_;

	// Y�͍�����ς��邾���Ȃ̂�
	// ��������̐ݒ�
	gazeHeight_ += diff.y_ * lpTimeManager.GetDeltaTimeF() * GAZEPOINT_SPEED;
	gazeHeight_ = std::clamp(gazeHeight_, -GAZEPOINT_MAX_HEIGHT, GAZEPOINT_MAX_HEIGHT);

	if (diff != Vector2{0,0})
	{
		angle_.x_ -= MyUtility::DegToRad(diff.y_ * rotateSpeedX_ * delta);
		angle_.y_ -= MyUtility::DegToRad(diff.x_ * rotateSpeedX_ * delta);
	}

	SetMousePoint(static_cast<int>(clampPos.x_), static_cast<int>(clampPos.y_));
	return true;
}

Vector2f Player::GetMouseRangeMotion()
{
	if (lpSceneMng.GetInputManager().expired())
	{
		TRACE("Player : InputManager�������؂�ł�");
		return {};
	}
	auto mouse = lpSceneMng.GetInputManager().lock()->GetMouseInput();
	if (mouse.expired())
	{
		TRACE("Player : Get����MouseInput�������؂�ł�");
		return {};
	}

	// �������u�Ԃ����͒��S�ɂ���
	if (oldVelocity_ == Vector3f{} && velocity_ != Vector3f{})
	{
		mPos_ = lpSceneMng.ScreenSize() / 2;
	}
	// �}�E�X�̉���
	// ����̔{��
	float minVolume = MOUSE_RANGE_MIN;
	float maxVolume = MOUSE_RANGE_MAX;

	// �����Ă�Ƃ��͉���𒆐S�ɂ���
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
