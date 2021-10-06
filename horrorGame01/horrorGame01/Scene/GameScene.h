#pragma once
#include "BaseScene.h"
#include <memory>

class BaseObject;
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
	std::shared_ptr<BaseObject> stage_;
	std::shared_ptr<BaseObject> player_;
	int bright_;								// 明るさ
};

