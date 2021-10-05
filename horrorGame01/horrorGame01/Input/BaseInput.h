#pragma once
#include <map>

#include "InputID.h"

/// <summary>
/// 入力装置の種類定義
/// </summary>
enum class ControllType
{
	Keybord,
	GamePad,
	Max
};


/// <summary>
/// IDに対応するtrigger情報を格納する
/// first : 現座フレームの情報
/// Second : １フレーム前の情報
/// </summary>
using TriggerMap = std::map<InputID, std::pair<bool, bool>>;

/// <summary>
/// 入力管理クラス
/// </summary>
class BaseInput
{
public:
	BaseInput();
	virtual ~BaseInput();

	/// <summary>
	/// 更新
	/// </summary>
	virtual void Update(void) = 0;
	/// <summary>
	/// 押された瞬間かどうか
	/// </summary>
	/// <param name="id">取得したいID</param>
	const bool GetPushTrigger(InputID id)const;
	/// <summary>
	/// 押され続けているかどうか
	/// </summary>
	/// <param name="id">取得したいID</param>
	const bool GetPushingTrigger(InputID id)const;
	/// <summary>
	/// 離された瞬間かどうか
	/// </summary>
	/// <param name="id">取得したいID</param>
	const bool GetReleaseTrigger(InputID id)const;
	/// <summary>
	/// 離された瞬間かどうか
	/// </summary>
	/// <param name="id">取得したいID</param>
	const bool GetReleasingTrigger(InputID id)const;


protected:
	TriggerMap triggerMap_;
	// IDに対応したコンフィグ格納
	std::map<InputID, int> config_;
};

