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
	/// 更新処理
	/// </summary>
	/// <returns>基本的に自分自身を返すが、シーン移動する場合は新しいシーンを返す</returns>
	virtual UniqueBase Update(UniqueBase scene) = 0;
	virtual void Draw(void);
	/// <summary>
	/// シーンの描画
	/// </summary>
	virtual void DrawOwnScene(void) = 0;
	/// <summary>
	/// カメラの更新
	/// </summary>
	bool UpdateCamera(void);
	/// <summary>
	/// カメラの描画
	/// </summary>
	bool DrawCamera(void);
protected:
	int screenID_;
	Size screenSize_;

	// どこで持つか迷ったけどマネージャーだと違和感あるから一旦各シーンで持つ
	std::shared_ptr<Camera> camera_;
private:
};

