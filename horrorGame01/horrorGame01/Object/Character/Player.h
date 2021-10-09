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
	// 注視点で使う半径
	static constexpr float GAZE_POINT_RADIUS = 100.0f;

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

	std::shared_ptr<Camera> GetCamera(void)const;
private:

	// 移動
	bool Move(float& delta);
	// 視点回転
	bool Rotate(float& delta);

	void LightMove(float& delta);

	static constexpr float MOVESPEED = 200.0f;
	static constexpr float GAZEPOINT_SPEED = 10.0f;
	static constexpr float GAZEPOINT_MAX_HEIGHT = 100.0f;

	// マウスの可動域を変更するための倍率
	static constexpr float MOUSE_RANGE_MIN = 0.25f;
	static constexpr float MOUSE_RANGE_MAX = 0.75f;
	static constexpr float MOUSE_RANGE_MIDDLE = 0.5f;

	// マウスの反応する感度
	static constexpr float MOUSE_THRESHOLD = 3.0;

	// 回転速度
	float rotateSpeedX_;
	Vector3f rotateVel_;
	// 当たり判定用にステージのモデルハンドルをもらっておく
	const int stageModel_;
	// ライトハンドル保持用
	int spotLight_;
	Vector3f lightPos_;
	// 可動域
	Vector3f lightPosCenter_;
	Vector3f lightPosMin_;
	Vector3f lightPosMax_;

	// 注視点の高さ
	float gazeHeight_;
	// マウスの座標保持
	Vector2 mPos_;

	// 動いた瞬間、動いてる時を調べるために
	Vector3f velocity_;
	Vector3f oldVelocity_;

	// ---- カメラ

	bool chackMove_;
	std::shared_ptr<Camera> camera_;
	Vector3f cameraOffset_;
};

