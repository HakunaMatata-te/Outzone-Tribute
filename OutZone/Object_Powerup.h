#ifndef _OBJECT_POWERUP_
#define _OBJECT_POWERUP_

#include "Object.h"

class Powerup : public Object
{
private:

	Animation powerup;

public:

	Powerup(int x, int y);
	~Powerup(){};

};

#endif