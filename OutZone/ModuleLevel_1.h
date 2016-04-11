#ifndef __ModuleLevel_1_H__
#define __ModuleLevel_1_H__

#include "Module.h"
#include "Globals.h"

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

};

#endif