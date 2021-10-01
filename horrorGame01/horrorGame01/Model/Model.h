#pragma once
#include <string>

class Model
{
public:
	Model();
	~Model();

	/// <summary>
	/// モデル読み込み
	/// </summary>
	/// <param name="str">Resource/Model/ 以降のパス</param>
	/// <returns>false : 失敗</returns>
	bool LoadModel(std::string& str);


private:
	int modelHandle_;

	int animHandle_;
	float animAllTime_;
};

