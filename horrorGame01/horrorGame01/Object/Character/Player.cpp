#include <DxLib.h>

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

Player::Player(Vector3f pos, Vector3f angle, Vector3f scale)
	:BaseObject(pos, angle, scale)
{
	Init();
}

Player::~Player()
{
}

bool Player::Init(void)
{
	return false;
}

bool Player::Update(void)
{
	float delta = lpTimeManager.GetDeltaTimeF();

	// ˆÚ“®
	Move(delta);
	Rotate(delta);

	return true;
}

void Player::Draw(void)
{
}

bool Player::Move(float& delta)
{
	if (lpSceneMng.GetInputManager().expired())
	{
		TRACE("Player : InputManager‚ªŠúŒÀØ‚ê‚Å‚·");
		return false;
	}

	auto baseInput = lpSceneMng.GetInputManager().lock()->GetBaseInput();

	if (baseInput.expired())
	{
		TRACE("Player : Get‚µ‚½BaseInput‚ªŠúŒÀØ‚ê‚Å‚·");
		return false;
	}

	int count = 0;
	Vector3f velocity{};
	auto move = [&](InputID&& id, float&& rad)
	{
		if (baseInput.lock()->GetPushingTrigger(id))
		{
			Vector3f dir{ std::sinf(angle_.y_ + rad),0.0f,std::cosf(angle_.y_ + rad) };
			velocity += dir * (MOVESPEED * delta);
			count++;
		}
	};

	move(InputID::Up, MyUtility::DegToRad(0.0f));
	move(InputID::Left, MyUtility::DegToRad(-90.0f));
	move(InputID::Down, MyUtility::DegToRad(180.0f));
	move(InputID::Right, MyUtility::DegToRad(90.0f));

	// Î‚ßˆÚ“®‚Ì§Œä
	if (count > 1)
	{
		velocity = { std::sinf(DX_PI_F / 4.0f) * velocity.x_,0.0f,std::cosf(DX_PI_F / 4.0f) * velocity.z_ };
	}

	pos_ += velocity;

	return true;
}

bool Player::Rotate(float& delta)
{
	if (lpSceneMng.GetInputManager().expired())
	{
		TRACE("Player : InputManager‚ªŠúŒÀØ‚ê‚Å‚·");
		return false;
	}

	auto mouse = lpSceneMng.GetInputManager().lock()->GetMouseInput();

	if (mouse.expired())
	{
		TRACE("Player : Get‚µ‚½MouseInput‚ªŠúŒÀØ‚ê‚Å‚·");
		return false;
	}

	auto mPos = mouse.lock()->GetPotision();

	// ·•ª‚ğ‹‚ß‚é
	auto diff = lpSceneMng.ScreenSize() / 2 - mPos;

	if (diff != Vector2{0,0})
	{
		angle_.x_ -= MyUtility::DegToRad(diff.y_ * 40 * delta);
		angle_.y_ -= MyUtility::DegToRad(diff.x_ * 40 * delta);
	}

	auto p = lpSceneMng.ScreenSize() / 2;
	SetMousePoint(p.x_, p.y_);
	return true;
}
