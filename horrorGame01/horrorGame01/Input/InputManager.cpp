#include "InputManager.h"
#include "BaseInput.h"
#include "Keyboard.h"
#include "Mouse.h"

InputManager::InputManager()
{
    Init();
}

InputManager::~InputManager()
{
}

void InputManager::Update(void)
{
    mouseInput_->Update();
    baseInput_->Update();
}

std::weak_ptr<BaseInput> InputManager::GetBaseInput(void) const
{
    return baseInput_;
}

std::weak_ptr<Mouse> InputManager::GetMouseInput(void) const
{
    return mouseInput_;
}

void InputManager::Init(void)
{
    mouseInput_ = std::make_shared<Mouse>();
    baseInput_ = std::make_shared<Keyboard>();
}
