#include "GameScene.h"
#include <DxLib.h>

#include "../Common/Vector3.h"
#include "../_debug/_DebugConOut.h"
#include "../TMXLoader/TmxLoader.h"
#include "../Object/BaseObject.h"
#include "../Object/Stage/Stage.h"
#include "../Object/Character/Player.h"
#include "../Object/Camera/Camera.h"


GameScene::GameScene()
{
	TRACE("GameScene����\n");
	Init();
}

GameScene::~GameScene()
{
	TRACE("GameScene�j��\n");
}

void GameScene::Init(void)
{
	//TmxLoader tmx;
	//tmx.LoadTmx("Resource/Tmx/SerializeAllData.xml");

	stage_ = std::make_shared<Stage>(Vector3f{0.0f,0.0f,0.0f}, Vector3f{}, Vector3f{});
	player_ = std::make_shared<Player>(Vector3f{ 0.0f,0.0f,0.0f }, Vector3f{}, Vector3f{});
	camera_->SetTarget(player_);

	bright_ = 255;
}

UniqueBase GameScene::Update(UniqueBase scene)
{
	stage_->Update();
	player_->Update();
	return scene;
}

void GameScene::DrawOwnScene(void)
{
	SetDrawScreen(screenID_);
	// �J�����̃N���b�v�����̐ݒ�
	SetCameraNearFar(1.0f, 1000.0f);
	SetDrawBright(bright_, bright_, bright_);

	ClsDrawScreen();

	camera_->Draw();
	stage_->Draw();
}
