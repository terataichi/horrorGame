#include "BaseTask.h"

BaseTask::BaseTask()
{
}

BaseTask::~BaseTask()
{
}

bool BaseTask::NextUpdate(void)
{
	return nextUpdate_;
}

bool BaseTask::NextDraw(void)
{
	return nextDraw_;
}
