#include "Model.h"
#include <DxLib.h>

#include "../_debug/_DebugConOut.h"

Model::Model()
{
}

Model::~Model()
{
}

bool Model::LoadModel(std::string& str)
{
	modelHandle_ = MV1LoadModel(str.c_str());

	if (modelHandle_ == -1)
	{
		TRACE("モデルの読み込み失敗 : %s \n", str.c_str());
		return false;
	}
	return true;
}
