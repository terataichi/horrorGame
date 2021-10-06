#pragma once

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

	/// <summary>
	/// ----- GetSet
	/// </summary>
	const Vector3f& Potision(void)const;
	const Vector3f& Angle(void)const;
	const Vector3f& Scale(void)const;

	void Potision(Vector3f& pos);
	void Angle(Vector3f& angle);
	void Scale(Vector3f& scale);
protected:
	Vector3f pos_;
	// ラジアン
	Vector3f angle_;
	Vector3f scale_;

	const ObjectType objType_;
};

