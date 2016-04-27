#ifndef _OBJECT_
#define _OBJECT_

#include "p2Point.h"
#include "Animation.h"

struct SDL_Texture;
struct Collider;
struct SDL_Rect;

class Object
{
protected:
	Animation* animation;
	Collider* collider;

public:
	iPoint position;

public:
	Object(int x, int y);
	virtual ~Object();

	const Collider* GetCollider() const;

	virtual void Draw(SDL_Texture* itemsprites);
};

#endif