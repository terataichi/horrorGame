#include "Actor.h"
#include "../Model/Model.h"

Actor::Actor(Vector3f& pos, Vector3f& angle, Vector3f& scale, ObjectType type)
	:BaseObject(pos, angle, scale, type)
{
}

Actor::~Actor()
{
}

bool Actor::ModelInit(std::string modelPath)
{

	model_ = std::make_unique<Model>(pos_, angle_, scale_);
	model_->LoadModelAndAnimation(modelPath);


	return true;
}
