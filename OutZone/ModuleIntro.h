#ifndef __ModuleIntro_1_H__
#define __ModuleIntro_1_H__

#include "Module.h"
#include "Globals.h"
#include "Animation.h"

#include "SDL_mixer/include/SDL_mixer.h"
struct SDL_Texture;

class ModuleIntro : public Module
{
public:
	ModuleIntro();
	~ModuleIntro();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	
	SDL_Texture* lvl_texture = nullptr;
	SDL_Texture* lvl_texture2 = nullptr;
	SDL_Texture* lvl_title = nullptr;
	Animation title;
	SDL_Rect background;
	Mix_Music* lvl_music = nullptr;

};

#endif