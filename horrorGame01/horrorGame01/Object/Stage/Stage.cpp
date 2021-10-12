
#include "Stage.h"
#include "../../Model/Model.h"

Stage::Stage(Vector3f&& pos, Vector3f&& angle, Vector3f&& scale) 
	:Actor(pos, angle, scale,ObjectType::Stage)
{
	Init();
}

Stage::~Stage()
{
}

bool Stage::Init(void)
{
	model_ = std::make_unique<Model>(pos_, angle_, scale_, angle_);
	if(model_->LoadModel("Stage01.mv1"))
	{
		model_->SetUpCollision(-1, { 8,8,8 });
	}
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

void Stage::Hit(std::shared_ptr<BaseObject> hitObj_)
{
}

bool Stage::IsHit(std::shared_ptr<BaseObject> target)
{

	return false;
}
