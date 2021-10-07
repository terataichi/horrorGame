#pragma once
#include "BaseScene.h"
#include <memory>
#include <vector>

class BaseObject;
class Stage;
class Actor;
class Camera;

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
	/// <summary>
	/// �V�[���̕`��
	/// </summary>
	void DrawOwnScene(void);

private:
	std::shared_ptr<Stage> stage_;
	std::shared_ptr<BaseObject> player_;
	std::vector<std::shared_ptr<Actor>> objVec_;

	int bright_;								// ���邳
};

