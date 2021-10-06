#pragma once
#include <memory>

#include "../BaseObject.h"
#include "../../Common/Vector3.h"

class InputManager;

class Player
	:public BaseObject
{
public:
	Player(Vector3f pos,Vector3f angle,Vector3f scale);
	~Player();

	bool Init(void)override;
	bool Update(void)override;
	void Draw(void)override;

private:
	// ˆÚ“®
	bool Move(float& delta);
	// Ž‹“_‰ñ“]
	bool Rotate(float& delta);

	// ‰ñ“]‘¬“x
	float rotateSpeedX_;

	static constexpr float MOVESPEED = 200.0f;

};

