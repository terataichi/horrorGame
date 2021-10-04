#include "Stage.h"
#include "../../Model/Model.h"

Stage::Stage(Vector3f&& pos, Vector3f&& angle, Vector3f&& scale) 
	:BaseObject(pos, angle, scale)
{
	Init();
}

Stage::~Stage()
{
}

bool Stage::Init(void)
{
	model_ = std::make_unique<Model>(pos_, angle_, scale_, angle_);
	model_->LoadModel("Resource/Model/untitled.mv1");
	return true;
}

bool Stage::Update(void)
{
	return false;
}

void Stage::Draw(void)
{
	model_->Draw();
}
