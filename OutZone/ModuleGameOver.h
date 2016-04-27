#ifndef __GAMEOVER__
#define __GAMEOVER__

#include "Module.h"
#include "Globals.h"
#include "Animation.h"

#include "SDL_mixer/include/SDL_mixer.h"
struct SDL_Texture;

class ModuleGameOver : public Module
{
public:
	ModuleGameOver();
	~ModuleGameOver();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* lvl_texture = nullptr;
	SDL_Rect background;
	Mix_Music* lvl_music = nullptr;

};

#endif