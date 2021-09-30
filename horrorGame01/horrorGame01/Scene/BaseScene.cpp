#include "BaseScene.h"
#include <DxLib.h>

#include "SceneManager.h"
#include "../_debug/_DebugConOut.h"

BaseScene::BaseScene()
{
	TRACE("BaseScene\n");
	SetDrawScreen(DX_SCREEN_BACK);
	GetDrawScreenSize(&screenSize_.x_, &screenSize_.y_);
	screenID_ = MakeScreen(screenSize_.x_, screenSize_.y_, true);
}

BaseScene::~BaseScene()
{
	TRACE("BaseScene\n");
}

void BaseScene::Draw()
{
	DrawGraph(0, 0, screenID_, true);
}
