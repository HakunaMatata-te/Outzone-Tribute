#ifndef __ModuleLevel_2_H__
#define __ModuleLevel_2_H__

#include "Module.h"
#include "Globals.h"

#include "SDL_mixer/include/SDL_mixer.h"
struct SDL_Texture;

class ModuleLevel_2 : public Module
{
public:
	ModuleLevel_2 ();
	~ModuleLevel_2();

	bool Start();
	update_status Update();

public:
	SDL_Texture* lvl_texture = nullptr;
	SDL_Rect background;
	Mix_Music* lvl_music = nullptr;

};


#endif // !__ModuleLevel_2_H__
