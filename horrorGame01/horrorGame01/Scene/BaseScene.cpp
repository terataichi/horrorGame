#include "BaseScene.h"
#include <DxLib.h>

#include "SceneManager.h"
#include "../Object/Camera/Camera.h"
#include "../_debug/_DebugConOut.h"

BaseScene::BaseScene()
{
	TRACE("BaseScene\n");
	SetDrawScreen(DX_SCREEN_BACK);
	GetDrawScreenSize(&screenSize_.x_, &screenSize_.y_);
	screenID_ = MakeScreen(screenSize_.x_, screenSize_.y_, true);

	camera_ = std::make_shared<Camera>(Vector3f{}, Vector3f{}, Vector3f{}, Vector3f{ 0.0f,150.0f,0.0f });
}

BaseScene::~BaseScene()
{
	TRACE("BaseScene\n");
}

void BaseScene::Draw()
{
	DrawGraph(0, 0, screenID_, true);
}

bool BaseScene::UpdateCamera(void)
{
	if (camera_)
	{
		camera_->Update();
		return true;
	}
	return false;
}

bool BaseScene::DrawCamera(void)
{
	if (camera_)
	{
		camera_->Draw();
		return true;
	}
	return false;
}
