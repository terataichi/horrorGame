#pragma once
#include "../Actor.h"


class Key :
    public Actor
{
public:
	Key(Vector3f pos, Vector3f angle, Vector3f scale);
	~Key();

	bool Init(void);
	bool Update(void);
	void Draw(void);

private:

};

