#pragma once


class BaseTask
{
public:
	BaseTask();
	virtual ~BaseTask();

	virtual void Init(void) = 0;
	virtual bool Update(void) = 0;
	virtual void Draw(void) = 0;

	/// <summary>
	/// ゲット系
	/// </summary>
	bool NextUpdate(void);
	bool NextDraw(void);
protected:
	bool nextUpdate_;							// 次のタスクのアップデートを回すか
	bool nextDraw_;								// 次のタスクの描画をするか
};

