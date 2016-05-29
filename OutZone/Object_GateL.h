#ifndef _OBJECT_GATEL_
#define _OBJECT_GATEL_

#include "Object.h"

class GateL : public Object
{
private:

	Animation gate_left;

//	int count;

public:

	GateL(int x, int y);
	~GateL(){};
	
//	void Draw(SDL_Texture* itemsprites);
};

#endif