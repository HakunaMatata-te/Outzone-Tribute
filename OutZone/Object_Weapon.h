#ifndef _OBJECT_WEAPON_
#define _OBJECT_WEAPON_

#include "Object.h"

class ChangeWeapon : public Object
{
private:

	Animation weapon;

public:

	ChangeWeapon(int x, int y);
	~ChangeWeapon(){};
	void pick();
};

#endif