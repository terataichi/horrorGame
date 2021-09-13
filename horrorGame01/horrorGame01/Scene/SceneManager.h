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
	/// ƒVƒXƒeƒ€‚Ì‰Šú‰»
	/// </summary>
	/// <returns>false : ¸”s</returns>
	bool SystemInit(void);
	bool initFlag_;							 // ‰Šú‰»‚ª¬Œ÷‚µ‚½‚©‚Ç‚¤‚©
	SceneManager();
	~SceneManager();
};
