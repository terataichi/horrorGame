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
	// 可動域と注視点で使う半径
	static constexpr float GAZE_POINT_RADIUS = 5.0f;

	Player(Vector3f pos,Vector3f angle,Vector3f scale,const int& stageModel);
	~Player();

	bool Init(void)override;
	bool Update(void)override;
	void Draw(void)override;

	void Hit(std::shared_ptr<BaseObject> hitObj_);

	// 現在のマウスの位置を可動域内にクランプして返す
	// カメラでも使ってね
	//Vector2f GetMouseRangeMotion(void);
	const float& GetGazeHeight(void)const;

	std::shared_ptr<Camera> GetCamera(void)const;
private:

	// 移動
	bool Move(float& delta);
	// 視点回転
	bool Rotate(float& delta);

	void LightMove(float& delta);

	// 移動スピード
	static constexpr float MOVESPEED = 200.0f;
	// 高さ制限
	static constexpr float GAZEPOINT_MAX_HEIGHT = 20.0f;
	// マウスの反応する感度
	static constexpr float MOUSE_THRESHOLD = 4.0;

	// ライトの可動域
	static constexpr float RANGE_MOTION_HEIGHT = GAZE_POINT_RADIUS * 0.4f;
	// 動いてないときの可動域
	static constexpr float RANGE_MOTION_RADIAN = 45.0f * (DX_PI_F / 180.0f);

	// 当たり判定用にステージのモデルハンドルをもらっておく
	const int stageModel_;
	// ライトハンドル保持用
	int spotLight_;
	Vector3f lightPos_;
	// 可動域
	float lightAngleY_;
	float lightHeight_;
	float rangeMotionRadian_;
	float rangeMotionHeight_;

	// 注視点の高さ
	float gazeHeight_;
	// マウスの座標保持
	Vector2 mPos_;

	// 動いた瞬間、動いてる時を調べるために
	Vector3f velocity_;
	Vector3f oldVelocity_;

	// 移動の入力キーが押されているか
	bool isHitMoveKey_;

	// ---- カメラ
	bool chackMove_;
	std::shared_ptr<Camera> camera_;
	Vector3f cameraOffset_;
};

