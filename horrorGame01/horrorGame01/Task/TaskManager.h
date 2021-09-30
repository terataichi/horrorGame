#pragma once
#include <list>
#include <memory>

class BaseTask;

/// <summary>
/// �^�X�N�̊Ǘ��p�N���X
/// </summary>
class TaskManager
{
public:
	TaskManager();
	~TaskManager() = default;

	/// <summary>
	/// �X�V
	/// </summary>
	/// <returns>true : �^�X�N�I��</returns>
	bool TaskUpdate(void);

	void TaskDraw(void);

	bool AddTask(std::shared_ptr<BaseTask> task);
private:
	std::list<std::shared_ptr<BaseTask>> taskList_;			// �Ǘ�����^�X�N�����X�g�ŕێ�

};

