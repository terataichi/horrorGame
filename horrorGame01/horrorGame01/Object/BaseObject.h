#pragma once

#include "../Common/Vector3.h"

class BaseObject
{
public:
	BaseObject(const Vector3f& pos,const Vector3f& angle,const Vector3f& scale);
	virtual ~BaseObject();


	const Vector3f& Potision(void)const;
	const Vector3f& Angle(void)const;
	const Vector3f& Scale(void)const;


protected:
	Vector3f pos_;
	Vector3f angle_;
	Vector3f scale_;
};

