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
	// ����ƒ����_�Ŏg�����a
	static constexpr float GAZE_POINT_RADIUS = 30.0f;

	Player(Vector3f pos,Vector3f angle,Vector3f scale,const int& stageModel);
	~Player();

	bool Init(void)override;
	bool Update(void)override;
	void Draw(void)override;

	void Hit(std::shared_ptr<BaseObject> hitObj);

	// �J�����Ŏg��
	const float& GetGazeHeight(void)const;

	std::shared_ptr<Camera> GetCamera(void)const;

	/// <summary>
	/// �v���C���[�Ɣz�u���ꂽ�I�u�W�F�N�g
	/// </summary>
	void CheckHItObject(std::shared_ptr<BaseObject> baseObj);
private:

	// �ړ�
	bool Move(float& delta);

	void LightMove(float& delta);

	// �ړ��X�s�[�h
	static constexpr float MOVESPEED = 200.0f;
	// ��������
	static constexpr float GAZEPOINT_MAX_HEIGHT = 20.0f;
	// �}�E�X�̔������銴�x
	static constexpr float MOUSE_THRESHOLD = 6.0;

	// ���C�g�̉���
	static constexpr float RANGE_MOTION_HEIGHT = GAZE_POINT_RADIUS * 0.4f;
	// �����ĂȂ��Ƃ��̉���
	static constexpr float RANGE_MOTION_RADIAN = 45.0f * (DX_PI_F / 180.0f);

	// �����蔻��p�ɃX�e�[�W�̃��f���n���h����������Ă���
	const int stageModel_;
	// ���C�g�n���h���ێ��p
	int spotLight_;
	Vector3f lightPos_;
	// ����
	float lightAngleY_;
	float lightHeight_;
	float rangeMotionRadian_;
	float rangeMotionHeight_;

	// �����_�̍���
	float gazeHeight_;
	// �}�E�X�̍��W�ێ�
	Vector2 mPos_;

	// �������u�ԁA�����Ă鎞�𒲂ׂ邽�߂�
	Vector3f velocity_;
	Vector3f oldVelocity_;

	// �ړ��̓��̓L�[��������Ă��邩
	bool isHitMoveKey_;

	// ---- �J����
	bool chackMove_;
	std::shared_ptr<Camera> camera_;
	Vector3f cameraOffset_;
};

