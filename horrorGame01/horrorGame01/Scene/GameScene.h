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
	/// 更新処理
	/// </summary>
	/// <returns>基本的に自分自身を返すが、シーン移動する場合は新しいシーンを返す</returns>
	UniqueBase Update(UniqueBase scene);
	/// <summary>
	/// シーンの描画
	/// </summary>
	void DrawOwnScene(void);

private:
	std::shared_ptr<Stage> stage_;
	std::shared_ptr<BaseObject> player_;
	std::vector<std::shared_ptr<BaseObject>> objVec_;

	int bright_;								// 明るさ
};

