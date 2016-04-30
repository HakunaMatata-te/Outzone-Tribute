#ifndef _OBJECT_BOX_
#define _OBJECT_BOX_

#include "Object.h"

class Box : public Object
{
private:
	
	Animation box;

public:

	Box(int x, int y);
	~Box(){};

	void drop();
};

#endif