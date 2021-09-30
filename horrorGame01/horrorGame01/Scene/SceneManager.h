#pragma once
#include <memory>
#include "../Common/Vector2.h"

class BaseScene;

#define lpSceneMng SceneManager::GetInstance()

class SceneManager
{
public:
	static SceneManager& GetInstance()
	{
		static SceneManager s_Instance;
		return s_Instance;
	}

	void Run(void);
	void Update(void);
	void Draw(void);

	/// <summary>
	/// �V�X�e���̏�����
	/// </summary>
	/// <returns>false : ���s</returns>
	bool SystemInit(void);
	// 3DInit�ɂ��悤�Ǝv�������Ǔ��ɐ����t������G���[�ł�
	bool Init3D(void);

	const Size& ScreenSize(void);

private:
	std::unique_ptr<BaseScene> scene_;
	const Size screenSize_;
	SceneManager();
	~SceneManager();
};
