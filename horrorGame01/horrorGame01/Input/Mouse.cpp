#include "Mouse.h"
#include "../Scene/SceneManager.h"

Mouse::Mouse()
{
	IDMap_.try_emplace(MouseID::Left, MOUSE_INPUT_LEFT);
	IDMap_.try_emplace(MouseID::Middle, MOUSE_INPUT_MIDDLE);
	IDMap_.try_emplace(MouseID::Right, MOUSE_INPUT_RIGHT);

	for (auto id : MouseID())
	{
		mouseMap_[id].first = false;
		mouseMap_[id].second = false;
	}
}

Mouse::~Mouse()
{
}

void Mouse::Update(void)
{
	for (auto id : MouseID())
	{
		mouseMap_[id].second = mouseMap_[id].first;
		mouseMap_[id].first = IDMap_[id] & GetMouseInput();
	}


	GetMousePoint(&pos_.x_, &pos_.y_);

}

bool Mouse::GetClick(MouseID&& id)
{
	return mouseMap_[id].first;
}

bool Mouse::GetClickPush(MouseID&& id)
{
	return mouseMap_[id].first && !mouseMap_[id].second;
}

bool Mouse::GetClickRelease(MouseID&& id)
{
	return !mouseMap_[id].first && mouseMap_[id].second;
}

const Vector2& Mouse::GetPotision(void)
{
	return pos_;
}
