#pragma once
#include <string>
#include <vector>

#include "../Common/Vector3.h"
#include "../Object/BaseObject.h"

// モデル情報保持クラス
// ロードは関数呼んで
class Model :
	public BaseObject
{
public:
	Model(Vector3f pos, Vector3f angle, Vector3f scale, Vector3f localAngle);
	~Model();

	bool Init(void)override;
	bool Update(void)override;
	void Draw(void)override;

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
	/// ---- Get,Set
	/// </summary>
	const Vector3f& LocalAngle(void)const;
	void LocalAngle(Vector3f& angle);

private:

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

