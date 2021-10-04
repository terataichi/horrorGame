#include "GameScene.h"
#include <DxLib.h>

#include "../Common/Vector3.h"
#include "../_debug/_DebugConOut.h"
#include "../TMXLoader/TmxLoader.h"
#include "../Object/Stage/Stage.h"

GameScene::GameScene()
{
	TRACE("GameSceneê∂ê¨\n");
	Init();
}

GameScene::~GameScene()
{
	TRACE("GameSceneîjä¸\n");
}

void GameScene::Init(void)
{
	//TmxLoader tmx;
	//tmx.LoadTmx("Resource/Tmx/SerializeAllData.xml");

	stage_ = std::make_unique<Stage>(Vector3{}, Vector3{}, Vector3{});
}

UniqueBase GameScene::Update(UniqueBase scene)
{
	return scene;
}

void GameScene::Draw(void)
{
	stage_->Draw();
}

void GameScene::DrawOwnScene(void)
{
}
