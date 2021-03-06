#pragma once
#include <string>
#include <vector>

#include "../Common/Vector3.h"

// モデル情報保持クラス
// ロードは関数呼んで
class Model
{
public:
	Model(Vector3f pos, Vector3f angle, Vector3f scale, Vector3f localAngle = {});
	~Model();

	bool Init(void);
	bool Update(void);
	void Draw(void);

	/// <summary>
	/// モデル読み込み
	/// </summary>
	/// <param name="str">Resource/Model/ 以降のパス</param>
	/// <returns>false : 失敗</returns>
	bool LoadModel(std::string str);
	/// <summary>
	/// アニメーションがある場合
	/// </summary>
	/// <returns>false : 失敗</returns>
	bool LoadModelAndAnimation(std::string str);

	/// <summary>
	/// コリジョン情報構築	
	/// </summary>
	/// <returns></returns>
	int SetUpCollision(int flameIndex, Vector3 div);

	/// <summary>
	/// ---- Get,Set
	/// </summary>
	const Vector3f& LocalAngle(void)const;
	void LocalAngle(Vector3f& angle);
	const int& GetModelHandle(void)const;
private:

	Vector3f pos_;
	Vector3f angle_;
	Vector3f scale_;

	// モデル読み込み用
	int modelHandle_;
	// アニメーション読み込み用
	std::vector<int>animHandleVec_;
	// アニメーションの再生時間記録用
	float animToralTime_;
	// 一回のアニメーションの時間
	float animStepTime_;
	// アニメーションの速度
	float animSpeed_;

	Vector3f localAngle_;

};

