#include "SceneManager.h"
#include <DxLib.h>

#include "../_debug/_DebugConOut.h"
#include "../_debug/_DebugDispOut.h"
#include "../Common/TimeManager.h"
#include "BaseScene.h"
#include "GameScene.h"
#include "../Object/Camera/Camera.h"
#include "../Input/InputManager.h"

void SceneManager::Run(void)
{

	scene_ = std::make_unique<GameScene>();
	input_ = std::make_shared<InputManager>();

	while (DxLib::ProcessMessage() == 0 && !DxLib::CheckHitKey(KEY_INPUT_ESCAPE))
	{
		_dbgStartDraw();
		lpTimeManager.Update();
		input_->Update();
		// 自身を渡してあげる
		scene_ = scene_->Update(std::move(scene_));
		scene_->UpdateCamera();
		scene_->DrawOwnScene();

		SetDrawScreen(DX_SCREEN_BACK);
		ClsDrawScreen();

		scene_->Draw();

		_dbgAddDraw();
		ScreenFlip();
	}
	DxLib_End();
}

void SceneManager::Update(void)
{
}

void SceneManager::Draw(void)
{
}

bool SceneManager::SystemInit(void)
{
	SetWindowText("horrorGame");
	SetGraphMode(screenSize_.x_, screenSize_.y_, 32);
	ChangeWindowMode(true);
	if (DxLib_Init() == -1)
	{
		TRACE("DxLib初期化失敗しました");
		return false;
	}
	// 3D系初期化
	Init3D();
	// デバッグ
	_dbgSetup(screenSize_.x_, screenSize_.y_, 255);
    return true;
}

bool SceneManager::Init3D(void)
{
	// Zバッファーを有効にする
	SetUseZBuffer3D(true);

	// Zバッファーの書き込みを有効
	SetWriteZBuffer3D(true);

	// バックカリングを有効にする
	// 無駄なところを描画しない？的な奴
	SetUseBackCulling(true);

	// カメラのクリップ距離の設定
	SetCameraNearFar(0.1f, 150.0f);

	// ライトの設定
	ChangeLightTypeDir({ 0.3f,-3.7f,-0.8f });

	SetFogEnable(true);
	SetFogColor(0, 0, 0);

	SetUseLighting(true);
	SetLightEnable(false);

	// 3Dの背景色
	SetBackgroundColor(0, 0, 0);
	return true;
}

std::weak_ptr<InputManager> SceneManager::GetInputManager(void)
{
	return input_;
}

const Size& SceneManager::ScreenSize(void)
{
	return screenSize_;
}

SceneManager::SceneManager() :screenSize_({ 1360,768 })
{
}

SceneManager::~SceneManager()
{
}
