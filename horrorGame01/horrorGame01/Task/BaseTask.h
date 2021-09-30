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
	/// �Q�b�g�n
	/// </summary>
	bool NextUpdate(void);
	bool NextDraw(void);
protected:
	bool nextUpdate_;							// ���̃^�X�N�̃A�b�v�f�[�g���񂷂�
	bool nextDraw_;								// ���̃^�X�N�̕`������邩
};

