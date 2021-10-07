#pragma once
#include <memory>

#include "../BaseObject.h"
#include "../../Common/Vector3.h"
#include "../../Common/Vector2.h"

class InputManager;

class Player
	:public BaseObject
{
public:
	Player(Vector3f pos,Vector3f angle,Vector3f scale,const int& stageModel);
	~Player();

	bool Init(void)override;
	bool Update(void)override;
	void Draw(void)override;

	void Hit(std::shared_ptr<BaseObject> hitObj_);

	// ���݂̃}�E�X�̈ʒu��������ɃN�����v���ĕԂ�
	// �J�����ł��g���Ă�
	Vector2f GetMouseRangeMotion(void);

	const float& GetGazeHeight(void)const;

private:
	// �ړ�
	bool Move(float& delta);
	// ���_��]
	bool Rotate(float& delta);

	static constexpr float MOVESPEED = 200.0f;
	static constexpr float GAZEPOINT_SPEED = 10.0f;
	static constexpr float GAZEPOINT_MAX_HEIGHT = 100.0f;

	// �}�E�X�̉����ύX���邽�߂̔{��
	static constexpr float MOUSE_RANGE_MIN = 0.25f;
	static constexpr float MOUSE_RANGE_MAX = 0.75f;
	static constexpr float MOUSE_RANGE_MIDDLE = 0.5f;

	// ��]���x
	float rotateSpeedX_;
	// �����蔻��p�ɃX�e�[�W�̃��f���n���h����������Ă���
	const int stageModel_;
	// ���C�g�n���h���ێ��p
	int pointLight_;
	// �����_�̍���
	float gazeHeight_;
	// �}�E�X�̍��W�ێ�
	Vector2 mPos_;

	// �������u�ԁA�����Ă鎞�𒲂ׂ邽�߂�
	Vector3f velocity_;
	Vector3f oldVelocity_;
	
};

