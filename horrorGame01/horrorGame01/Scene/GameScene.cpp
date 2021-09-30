#include "GameScene.h"
#include <DxLib.h>

#include "../_debug/_DebugConOut.h"
#include "../TMXLoader/TmxLoader.h"

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
	TmxLoader tmx;
	tmx.LoadTmx("Resource/Tmx/SerializeAllData.xml");
}

UniqueBase GameScene::Update(UniqueBase scene)
{
	return scene;
}

void GameScene::Draw(void)
{
}

void GameScene::DrawOwnScene(void)
{
}
