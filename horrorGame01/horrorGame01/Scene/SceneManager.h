#pragma once
#include <memory>
#include "../Common/Vector2.h"

class BaseScene;

#define lpSceneMng SceneManager::GetInstance();

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

	const Size screenSize_;
private:
	std::unique_ptr<BaseScene> scene_;

	/// <summary>
	/// システムの初期化
	/// </summary>
	/// <returns>false : 失敗</returns>
	bool SystemInit(void);
	bool initFlag_;							 // 初期化が成功したかどうか
	SceneManager();
	~SceneManager();
};
