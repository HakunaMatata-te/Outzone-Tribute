#ifndef _OBJECT_SPECIAL_BOMB_
#define _OBJECT_SPECIAL_BOMB_

#include "Object.h"

class Bomb : public Object
{
private:

	Animation bomb;

public:

	Bomb(int x, int y);
	~Bomb(){};
	void pick();
};

#endif