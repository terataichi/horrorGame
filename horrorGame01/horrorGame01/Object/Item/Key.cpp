#include "Key.h"
#include "../../Model/Model.h"

Key::Key(Vector3f pos, Vector3f angle, Vector3f scale)
	:Actor(pos, angle, scale, ObjectType::Item)
{
	Init();
}

Key::~Key()
{
}

bool Key::Init(void)
{
	ModelInit("Key.mv1");
	return false;
}

bool Key::Update(void)
{
	return false;
}

void Key::Draw(void)
{
	model_->Draw();
}
