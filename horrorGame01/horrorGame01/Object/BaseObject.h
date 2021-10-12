#pragma once
#include <memory>
#include <vector>

#include "../Common/Vector3.h"

// ���ʗp
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

	// ���������I�u�W�F�N�g����Ă΂�܂�
	virtual void Hit(std::shared_ptr<BaseObject> hitObj_);

	/// <summary>
	/// �����ɓ����蔻�������
	/// </summary>
	/// <param name="target">���肷��I�u�W�F�N�g</param>
	/// <returns>true ��������</returns>
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
	// ���W�A��
	Vector3f angle_;
	Vector3f scale_;

	const ObjectType objType_;

	// false�ɂ����������
	bool active_;
};

