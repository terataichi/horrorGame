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
	// �ړ�
	bool Move(float& delta);
	// ���_��]
	bool Rotate(float& delta);

	// ��]���x
	float rotateSpeedX_;

	static constexpr float MOVESPEED = 200.0f;

};

