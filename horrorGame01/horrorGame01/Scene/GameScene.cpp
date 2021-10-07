#include "GameScene.h"
#include <DxLib.h>

#include "../Common/Vector3.h"
#include "../_debug/_DebugConOut.h"
#include "../TMXLoader/TmxLoader.h"
#include "../Object/BaseObject.h"
#include "../Object/Actor.h"
#include "../Object/Stage/Stage.h"
#include "../Object/Character/Player.h"
#include "../Object/Camera/Camera.h"
#include "../Object/Item/Key.h"

GameScene::GameScene()
{
	TRACE("GameScene生成\n");
	Init();
}

GameScene::~GameScene()
{
	TRACE("GameScene破棄\n");
}

void GameScene::Init(void)
{
	TmxLoader tmx;
	tmx.LoadTmx("Resource/Tmx/SerializeAllData.xml");

	auto typeData = tmx.GetTypeData()[DataType::Item];
	for (auto data : typeData)
	{
		objVec_.push_back(std::make_shared<Key>(data.pos, data.angle, data.scale));
	}
	
	stage_ = std::make_shared<Stage>(Vector3f{ 0.0f,0.0f,0.0f }, Vector3f{}, Vector3f{});

	player_ = std::make_shared<Player>(Vector3f{ 0.0f,0.0f,0.0f }, Vector3f{}, Vector3f{}, stage_->GetModelHandle());
	camera_->SetTarget(player_);

	bright_ = 255;
}

UniqueBase GameScene::Update(UniqueBase scene)
{
	player_->Update();

	for (auto obj : objVec_)
	{
		obj->Update();
	}
	return scene;
}

void GameScene::DrawOwnScene(void)
{
	SetDrawScreen(screenID_);
	// カメラのクリップ距離の設定
	SetCameraNearFar(1.0f, 1000.0f);
	//SetDrawBright(bright_, bright_, bright_);

	ClsDrawScreen();
	// カメラの描画が先
	camera_->Draw();
	stage_->Draw();
	for (auto obj : objVec_)
	{
		obj->Draw();
	}
}
