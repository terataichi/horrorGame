#pragma once
#include <string>

class Model
{
public:
	Model();
	~Model();

	/// <summary>
	/// ���f���ǂݍ���
	/// </summary>
	/// <param name="str">Resource/Model/ �ȍ~�̃p�X</param>
	/// <returns>false : ���s</returns>
	bool LoadModel(std::string& str);


private:
	int modelHandle_;

	int animHandle_;
	float animAllTime_;
};

