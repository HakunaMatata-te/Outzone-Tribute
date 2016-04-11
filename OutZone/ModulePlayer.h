#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Globals.h"
#include "p2Point.h"
#include "Animation.h"

struct SDL_Texture;

class ModulePlayer : public Module
{

public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	update_status Update();

public:
	
	int height = 0;
	int width = 0;
	int screenlowheight = 320;
	SDL_Texture* character = nullptr;
	SDL_Rect stand;
	Animation upward;
	Animation downward;
	Animation leftward;
	Animation rightward;
	iPoint position;

};

#endif // !__ModulePlayer_H__
