#ifndef _OBJECT_ENERGY_
#define _OBJECT_ENERGY_

#include "Object.h"

class Energy : public Object
{
private:

	Animation energy;

public:

	Energy(int x, int y);
	~Energy(){};
	void pick();
};

#endif