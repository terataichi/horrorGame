#include "TaskManager.h"
#include "BaseTask.h"

TaskManager::TaskManager()
{
}

bool TaskManager::TaskUpdate(void)
{
    int cnt = 0;
    bool endTask = false;
    for (auto& task : taskList_)
    {
        endTask = task->Update();

        // ���̃A�b�v�f�[�g���񂷂��ǂ���
        if (!task->NextUpdate())
        {
            break;
        }
        cnt++;
    }
    //if (endTask)
    //{
    //    taskList_.
    //}

    return false;
}

void TaskManager::TaskDraw(void)
{
}

bool TaskManager::AddTask(std::shared_ptr<BaseTask> task)
{
    taskList_.push_front(task);
    return true;
}
