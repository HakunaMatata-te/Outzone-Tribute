#ifndef _OBJECT_BOX_ENERGY_
#define _OBJECT_BOX_ENERGY_

#include "Object.h"

class Energy_Box : public Object
{
private:

	Animation energy_box;

public:

	Energy_Box(int x, int y);
	~Energy_Box(){};

	void drop();
};

#endif