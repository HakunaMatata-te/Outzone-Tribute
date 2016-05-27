#ifndef __ModuleLevel_3_H__
#define __ModuleLevel_3_H__

#include "Module.h"
#include "Globals.h"
#include "Animation.h"

#include "SDL_mixer/include/SDL_mixer.h"
struct SDL_Texture;
struct Collider;

class ModuleLevel_3 : public Module
{
public:
	ModuleLevel_3();
	~ModuleLevel_3();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* lvl_texture = nullptr;
	SDL_Texture* right_platform = nullptr;
	SDL_Texture* lava_texture = nullptr;
	SDL_Rect background;
	SDL_Rect platform;
	Animation lava;
	Animation paralaxleft;
	Animation paralaxright;
	uint lava_timer;
	bool boss_start;
	bool first_lava;
	bool second_lava;
};

#endif