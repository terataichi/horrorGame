#pragma once
#include <list>
#include <memory>

class BaseTask;

/// <summary>
/// タスクの管理用クラス
/// </summary>
class TaskManager
{
public:
	TaskManager();
	~TaskManager() = default;

	/// <summary>
	/// 更新
	/// </summary>
	/// <returns>true : タスク終了</returns>
	bool TaskUpdate(void);

	void TaskDraw(void);

	bool AddTask(std::shared_ptr<BaseTask> task);
private:
	std::list<std::shared_ptr<BaseTask>> taskList_;			// 管理するタスクをリストで保持

};

