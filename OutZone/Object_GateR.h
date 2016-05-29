#ifndef _OBJECT_GATER_
#define _OBJECT_GATER_

#include "Object.h"

class GateR : public Object
{
private:

	Animation gate_right;

public:

	GateR(int x, int y);
	~GateR(){};
};

#endif