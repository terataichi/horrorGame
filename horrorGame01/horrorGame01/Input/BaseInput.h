#pragma once
#include <map>

#include "InputID.h"

/// <summary>
/// ���͑��u�̎�ޒ�`
/// </summary>
enum class ControllType
{
	Keybord,
	GamePad,
	Max
};


/// <summary>
/// ID�ɑΉ�����trigger�����i�[����
/// first : �����t���[���̏��
/// Second : �P�t���[���O�̏��
/// </summary>
using TriggerMap = std::map<InputID, std::pair<bool, bool>>;

/// <summary>
/// ���͊Ǘ��N���X
/// </summary>
class BaseInput
{
public:
	BaseInput();
	virtual ~BaseInput();

	/// <summary>
	/// �X�V
	/// </summary>
	virtual void Update(void) = 0;
	/// <summary>
	/// �����ꂽ�u�Ԃ��ǂ���
	/// </summary>
	/// <param name="id">�擾������ID</param>
	const bool GetPushTrigger(InputID id)const;
	/// <summary>
	/// �����ꑱ���Ă��邩�ǂ���
	/// </summary>
	/// <param name="id">�擾������ID</param>
	const bool GetPushingTrigger(InputID id)const;
	/// <summary>
	/// �����ꂽ�u�Ԃ��ǂ���
	/// </summary>
	/// <param name="id">�擾������ID</param>
	const bool GetReleaseTrigger(InputID id)const;
	/// <summary>
	/// �����ꂽ�u�Ԃ��ǂ���
	/// </summary>
	/// <param name="id">�擾������ID</param>
	const bool GetReleasingTrigger(InputID id)const;


protected:
	TriggerMap triggerMap_;
	// ID�ɑΉ������R���t�B�O�i�[
	std::map<InputID, int> config_;
};

