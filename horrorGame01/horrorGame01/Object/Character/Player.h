#pragma once
#include <memory>

#include "../BaseObject.h"
#include "../../Common/Vector3.h"
#include "../../Common/Vector2.h"

class Camera;

class Player
	:public BaseObject
{
public:
	// �����_�Ŏg�����a
	static constexpr float GAZE_POINT_RADIUS = 100.0f;

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

	std::shared_ptr<Camera> GetCamera(void)const;
private:

	// �ړ�
	bool Move(float& delta);
	// ���_��]
	bool Rotate(float& delta);

	void LightMove(float& delta);

	static constexpr float MOVESPEED = 200.0f;
	static constexpr float GAZEPOINT_SPEED = 10.0f;
	static constexpr float GAZEPOINT_MAX_HEIGHT = 100.0f;

	// �}�E�X�̉����ύX���邽�߂̔{��
	static constexpr float MOUSE_RANGE_MIN = 0.25f;
	static constexpr float MOUSE_RANGE_MAX = 0.75f;
	static constexpr float MOUSE_RANGE_MIDDLE = 0.5f;

	// �}�E�X�̔������銴�x
	static constexpr float MOUSE_THRESHOLD = 3.0;

	// ��]���x
	float rotateSpeedX_;
	Vector3f rotateVel_;
	// �����蔻��p�ɃX�e�[�W�̃��f���n���h����������Ă���
	const int stageModel_;
	// ���C�g�n���h���ێ��p
	int spotLight_;
	Vector3f lightPos_;
	// ����
	Vector3f lightPosCenter_;
	Vector3f lightPosMin_;
	Vector3f lightPosMax_;

	// �����_�̍���
	float gazeHeight_;
	// �}�E�X�̍��W�ێ�
	Vector2 mPos_;

	// �������u�ԁA�����Ă鎞�𒲂ׂ邽�߂�
	Vector3f velocity_;
	Vector3f oldVelocity_;

	// ---- �J����

	bool chackMove_;
	std::shared_ptr<Camera> camera_;
	Vector3f cameraOffset_;
};

