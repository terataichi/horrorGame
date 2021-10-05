#pragma once
#include <memory>
#include "../Common/Vector2.h"

class BaseScene;
using UniqueBase = std::unique_ptr<BaseScene>;
class Camera;

class BaseScene
{
public:
	BaseScene();
	virtual ~BaseScene();

	virtual void Init(void) = 0;
	/// <summary>
	/// �X�V����
	/// </summary>
	/// <returns>��{�I�Ɏ������g��Ԃ����A�V�[���ړ�����ꍇ�͐V�����V�[����Ԃ�</returns>
	virtual UniqueBase Update(UniqueBase scene) = 0;
	virtual void Draw(void);
	/// <summary>
	/// �V�[���̕`��
	/// </summary>
	virtual void DrawOwnScene(void) = 0;
	/// <summary>
	/// �J�����̍X�V
	/// </summary>
	bool UpdateCamera(void);
	/// <summary>
	/// �J�����̕`��
	/// </summary>
	bool DrawCamera(void);
protected:
	int screenID_;
	Size screenSize_;

	// �ǂ��Ŏ������������ǃ}�l�[�W���[���ƈ�a�����邩���U�e�V�[���Ŏ���
	std::shared_ptr<Camera> camera_;
private:
};

