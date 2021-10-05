#include "BaseInput.h"

BaseInput::BaseInput()
{
}

BaseInput::~BaseInput()
{
}

void BaseInput::Update(void)
{
}

const bool BaseInput::GetPushTrigger(InputID id)const
{
	return triggerMap_.at(id).first && !triggerMap_.at(id).second;
}

const bool BaseInput::GetPushingTrigger(InputID id) const
{
	return triggerMap_.at(id).first;
}

const bool BaseInput::GetReleaseTrigger(InputID id) const
{
	return !triggerMap_.at(id).first && triggerMap_.at(id).second;
}

const bool BaseInput::GetReleasingTrigger(InputID id) const
{
	return !triggerMap_.at(id).first && !triggerMap_.at(id).second;
}
