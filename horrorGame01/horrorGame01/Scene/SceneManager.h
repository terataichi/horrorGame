#pragma once
#include <memory>
#include "../Common/Vector2.h"

class BaseScene;
class InputManager;

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
	/// システムの初期化
	/// </summary>
	/// <returns>false : 失敗</returns>
	bool SystemInit(void);
	// 3DInitにしようと思ったけど頭に数字付けたらエラーでた
	bool Init3D(void);
	// 入力情報管理クラス取得
	std::weak_ptr<InputManager>GetInputManager(void);

	const Size& ScreenSize(void);

private:
	std::unique_ptr<BaseScene> scene_;
	std::shared_ptr<InputManager> input_;
	const Size screenSize_;
	SceneManager();
	~SceneManager();
};
