#ifndef __ModuleLevel_3_H__
#define __ModuleLevel_3_H__

#include "Module.h"
#include "Globals.h"

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
	SDL_Rect background;

};

#endif