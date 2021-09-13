#pragma once
#include <memory>
#include "../Common/Vector2.h"

class BaseScene;
using UniqueBase = std::unique_ptr<BaseScene>;

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
	virtual UniqueBase Update(void) = 0;
	virtual void Draw(void);
	/// <summary>
	/// �V�[���̕`��
	/// </summary>
	virtual void DrawOwnScene(void) = 0;
protected:
	int screenID_;
	Size screenSize_;
private:
};

