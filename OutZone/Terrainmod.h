#ifndef __TERRAINMOD_H__
#define __TERRAINMOD_H__


#include "Application.h"
#include "ModuleRender.h"

#include "SDL\include\SDL.h"

#include "p2Point.h"
#include "Animation.h"

struct SDL_Texture;

class Terrainmod
{
protected:
	Animation* animation;

public:
	iPoint position;

public:

	Terrainmod(int x, int y);
	virtual ~Terrainmod();

	virtual void Draw(SDL_Texture* terrainSprites);
	virtual void action() {};
};

#endif