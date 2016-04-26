#ifndef __ModuleEndlevel_H__
#define __ModuleEndlevel_H__

#include "Module.h"
#include "Globals.h"

#include "SDL_mixer/include/SDL_mixer.h"
struct SDL_Texture;

class ModuleEndlevel : public Module
{
public:
	ModuleEndlevel();
	~ModuleEndlevel();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* endlvl_texture = nullptr;
	SDL_Rect endlevel;
	//Mix_Music* endlvl_music = nullptr;

};

#endif