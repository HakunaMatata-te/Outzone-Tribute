#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Globals.h"
#include "p2Point.h"
#include "Animation.h"

#include "SDL_mixer/include/SDL_mixer.h"
struct SDL_Texture;
struct Collider;

class ModulePlayer : public Module
{

public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	
	int height = 0;
	int width = 0;
	int screenlowheight = 320;
	SDL_Texture* character = nullptr;
	SDL_Rect stand;
	Animation* current_animation = nullptr;
	Animation upward;
	Animation downward;
	Animation leftward;
	Animation rightward;
	Animation upward_big_gun;
	Animation downward_big_gun;
	Animation rightward_big_gun;
	Animation leftward_big_gun;
	iPoint position;
	Mix_Chunk* triple_shot;
	Mix_Chunk* minigun_shot;

	Collider* playercollider = nullptr;
};

#endif // !__ModulePlayer_H__
