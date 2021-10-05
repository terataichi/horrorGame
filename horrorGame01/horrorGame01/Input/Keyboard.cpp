#include <DxLib.h>

#include "Keyboard.h"

Keyboard::Keyboard()
{
	// Old情報とNow情報の更新
	for (auto id : InputID())
	{
		triggerMap_[id].second = false;
		triggerMap_[id].first = false;
	}

	// 登録
	config_ =
	{
		{InputID::Left,KEY_INPUT_A},
		{InputID::Up,KEY_INPUT_W},
		{InputID::Right,KEY_INPUT_D},
		{InputID::Down,KEY_INPUT_S},
		{InputID::Action,KEY_INPUT_F},
		{InputID::Menu,KEY_INPUT_ESCAPE},
		{InputID::Button_3,KEY_INPUT_C},
		{InputID::Button_4,KEY_INPUT_V},
	};
}

Keyboard::~Keyboard()
{
}

void Keyboard::Update(void)
{
	// キーボードの入力情報を取得
	GetHitKeyStateAll(buf_.data());

	// Old情報とNow情報の更新
	for (auto id : InputID())
	{
		triggerMap_[id].second = triggerMap_[id].first;
		triggerMap_[id].first = buf_[config_[id]];
	}
}
