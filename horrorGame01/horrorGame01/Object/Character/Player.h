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

	// 現在のマウスの位置を可動域内にクランプして返す
	// カメラでも使ってね
	Vector2f GetMouseRangeMotion(void);

	const float& GetGazeHeight(void)const;

private:
	// 移動
	bool Move(float& delta);
	// 視点回転
	bool Rotate(float& delta);

	static constexpr float MOVESPEED = 200.0f;
	static constexpr float GAZEPOINT_SPEED = 10.0f;
	static constexpr float GAZEPOINT_MAX_HEIGHT = 100.0f;

	// マウスの可動域を変更するための倍率
	static constexpr float MOUSE_RANGE_MIN = 0.25f;
	static constexpr float MOUSE_RANGE_MAX = 0.75f;
	static constexpr float MOUSE_RANGE_MIDDLE = 0.5f;

	// 回転速度
	float rotateSpeedX_;
	// 当たり判定用にステージのモデルハンドルをもらっておく
	const int stageModel_;
	// ライトハンドル保持用
	int pointLight_;
	// 注視点の高さ
	float gazeHeight_;
	// マウスの座標保持
	Vector2 mPos_;

	// 動いた瞬間、動いてる時を調べるために
	Vector3f velocity_;
	Vector3f oldVelocity_;
	
};

