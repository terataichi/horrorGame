#include "SceneManager.h"
#include <DxLib.h>

#include "../_debug/_DebugConOut.h"
#include "../_debug/_DebugDispOut.h"
#include "../Common/TimeManager.h"
#include "BaseScene.h"
#include "GameScene.h"

void SceneManager::Run(void)
{

	scene_ = std::make_unique<GameScene>();

	while (DxLib::ProcessMessage() == 0 && !DxLib::CheckHitKey(KEY_INPUT_ESCAPE))
	{
		_dbgStartDraw();
		lpTimeManager.Update();
		// ���g��n���Ă�����
		scene_ = scene_->Update(std::move(scene_));

		DxLib::SetDrawScreen(DX_SCREEN_BACK);
		DxLib::ClsDrawScreen();

		scene_->Draw();

		_dbgAddDraw();
		DxLib::ScreenFlip();
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
		TRACE("DxLib���������s���܂���");
		return false;
	}

	// 3D�n������
	Init3D();

	// �f�o�b�O
	_dbgSetup(screenSize_.x_, screenSize_.y_, 255);
    return true;
}

bool SceneManager::Init3D(void)
{
	// Z�o�b�t�@�[��L���ɂ���
	SetUseZBuffer3D(true);

	// Z�o�b�t�@�[�̏������݂�L��
	SetWriteZBuffer3D(true);

	// �o�b�N�J�����O��L���ɂ���
	// ���ʂȂƂ����`�悵�Ȃ��H�I�ȓz
	SetUseBackCulling(true);

	// �J�����̃N���b�v�����̐ݒ�
	SetCameraNearFar(0.0f, 1500.0f);

	// ���C�g�̐ݒ�
	ChangeLightTypeDir({ 0.3f,-3.7f,-0.8f });

	// 3D�̔w�i�F
	SetBackgroundColor(0, 139, 50);
	return true;
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
