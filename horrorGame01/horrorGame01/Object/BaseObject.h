#pragma once

#include "../Common/Vector3.h"

class BaseObject
{
public:
	BaseObject(const Vector3f& pos,const Vector3f& rad,const Vector3f& scale);
	virtual ~BaseObject();
private:
};

