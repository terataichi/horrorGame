#pragma once
#include "BaseScene.h"

class GameScene
	:public BaseScene
{
public:
	GameScene();
	~GameScene();

	void Init(void);
	/// <summary>
	/// �X�V����
	/// </summary>
	/// <returns>��{�I�Ɏ������g��Ԃ����A�V�[���ړ�����ꍇ�͐V�����V�[����Ԃ�</returns>
	UniqueBase Update(UniqueBase scene);
	void Draw(void);
	/// <summary>
	/// �V�[���̕`��
	/// </summary>
	void DrawOwnScene(void);

private:

};

