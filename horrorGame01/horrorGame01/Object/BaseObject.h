#pragma once
#include <memory>
#include <vector>

#include "../Common/Vector3.h"

// 識別用
enum class ObjectType
{
	Non,
	Item,
	Camera,
	Stage,
	Player,
	Enemy,
	Max
};


class BaseObject
{
public:
	BaseObject(const Vector3f& pos,const Vector3f& angle,const Vector3f& scale,ObjectType type);
	virtual ~BaseObject();

	virtual bool Init(void) = 0;
	virtual bool Update(void) = 0;
	virtual void Draw(void) = 0;

	// 当たったオブジェクトから呼ばれます
	virtual void Hit(std::shared_ptr<BaseObject> hitObj_);

	/// <summary>
	/// ここに当たり判定を書く
	/// </summary>
	/// <param name="target">判定するオブジェクト</param>
	/// <returns>true 当たった</returns>
	virtual bool IsHit(std::shared_ptr<BaseObject> target);

	/// <summary>
	/// ----- GetSet
	/// </summary>
	const Vector3f& Potision(void)const;
	const Vector3f& Angle(void)const;
	const Vector3f& Scale(void)const;
	bool Active(void)const;

	void Potision(Vector3f& pos);
	void Angle(Vector3f& angle);
	void Scale(Vector3f& scale);
	void Active(bool active);
protected:
	Vector3f pos_;
	// ラジアン
	Vector3f angle_;
	Vector3f scale_;

	const ObjectType objType_;

	// falseにしたら消える
	bool active_;
};

