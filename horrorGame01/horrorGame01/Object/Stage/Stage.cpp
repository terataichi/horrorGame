
#include "Stage.h"
#include "../../Model/Model.h"

Stage::Stage(Vector3f&& pos, Vector3f&& angle, Vector3f&& scale) 
	:BaseObject(pos, angle, scale,ObjectType::Stage)
{
	Init();
}

Stage::~Stage()
{
}

bool Stage::Init(void)
{
	model_ = std::make_unique<Model>(pos_, angle_, scale_, angle_);
	model_->LoadModel("untitled.mv1");
	return true;
}

bool Stage::Update(void)
{
	//pos_.x_ += 1.0f;
	//model_->Potision(pos_);
	return true;
}

void Stage::Draw(void)
{
	model_->Draw();
}
