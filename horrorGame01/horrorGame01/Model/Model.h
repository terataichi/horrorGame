#pragma once
#include <string>

class Model
{
public:
	Model();
	~Model();

	/// <summary>
	/// ƒ‚ƒfƒ‹“Ç‚İ‚İ
	/// </summary>
	/// <param name="str">Resource/Model/ ˆÈ~‚ÌƒpƒX</param>
	/// <returns>false : ¸”s</returns>
	bool LoadModel(std::string& str);


private:
	int modelHandle_;

	int animHandle_;
	float animAllTime_;
};

