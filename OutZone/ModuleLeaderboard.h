#ifndef __ModuleLeaderboard_H__
#define __ModuleLeaderboard_H__

#include "Module.h"
#include "Globals.h"

#include "SDL_mixer/include/SDL_mixer.h"
struct SDL_Texture;

class ModuleLeaderboard : public Module
{
public:
	ModuleLeaderboard();
	~ModuleLeaderboard();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* lvl_texture = nullptr;
	SDL_Rect leaderboard;

};

#endif