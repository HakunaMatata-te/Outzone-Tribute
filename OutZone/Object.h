#ifndef _OBJECT_
#define _OBJECT_


#include "Application.h"
#include "ModuleCollider.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleRender.h"
#include "SDL\include\SDL.h"

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
	virtual void drop(){};
	virtual void pick(){};
};

#endif