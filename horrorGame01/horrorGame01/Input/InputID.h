#pragma once
enum class InputID
{
	Up,					// 移動系
	Down,
	Left,
	Right,
	Action,				// アイテム取ったりドア、鍵開けたり
	Menu,				// メニューボタン
	Button_3,
	Button_4,
	Max,
};

InputID begin(InputID);
InputID end(InputID);
InputID operator++(InputID& key);
InputID operator* (InputID key);
