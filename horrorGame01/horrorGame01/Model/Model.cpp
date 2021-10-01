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
		TRACE("ƒ‚ƒfƒ‹‚Ì“Ç‚İ‚İ¸”s : %s \n", str.c_str());
		return false;
	}
	return true;
}
