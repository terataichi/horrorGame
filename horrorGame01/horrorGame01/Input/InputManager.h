#pragma once
#include <memory>

class BaseInput;
class Mouse;

/// <summary>
/// 入力関係情報保持用
/// </summary>
class InputManager
{
public:
	InputManager();
	~InputManager();

	void Update(void);
	
	std::weak_ptr<BaseInput> GetBaseInput(void)const;
	std::weak_ptr<Mouse> GetMouseInput(void)const;
private:
	void Init(void);
	std::shared_ptr<BaseInput> baseInput_;
	std::shared_ptr<Mouse> mouseInput_;
};

