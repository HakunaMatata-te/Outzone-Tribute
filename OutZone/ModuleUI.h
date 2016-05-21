#ifndef __ModuleUI_H__
#define __ModuleUI_H__

#include "Module.h"
#include "Globals.h"
#include "p2Point.h"
#include "Animation.h"

#include "SDL_mixer/include/SDL_mixer.h"
struct SDL_Texture;
struct Collider;

class ModuleUi : public Module
{

public:
	ModuleUi();
	~ModuleUi();

	bool Start();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();

	//Just for testing should be move to the ui module.
	void print_energy();

public:

	uint energy;
	
	uint last_deplation;
	uint current_time;
	bool infinite_energy;
	iPoint position_test;


	SDL_Texture* uitextures = nullptr;
	
	Animation idle_energybar;
	Animation idle_energy;
	iPoint position;

};

#endif
