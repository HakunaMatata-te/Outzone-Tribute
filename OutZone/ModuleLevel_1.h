#ifndef __ModuleLevel_1_H__
#define __ModuleLevel_1_H__

#include "Module.h"
#include "Globals.h"

#include "SDL_mixer/include/SDL_mixer.h"
struct SDL_Texture;

class ModuleLevel_1 : public Module
{
public:
	ModuleLevel_1();
	~ModuleLevel_1();

	bool Start();
	update_status Update();

public:
	
	SDL_Texture* lvl_texture = nullptr;
	SDL_Rect background;
	Mix_Music* lvl_music = nullptr;

};

#endif