#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Globals.h"
#include "p2Point.h"
#include "Animation.h"
#include "VectorDynamic.h"

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
	int player_dir;


public:
	
	int height = 0;
	int width = 0;
	int screenlowheight;
	uint lvl;
	Weapon current_weapon;
	SDL_Texture* character = nullptr;
	SDL_Rect idle;
	Animation* current_animation = nullptr;
	Animation upward;
	Animation upward_right;
	Animation upward_left;
	Animation downward;
	Animation downward_right;
	Animation downward_left;
	Animation leftward;
	Animation rightward;
	Animation upward_triple_gun;
	Animation downward_triple_gun;
	Animation rightward_triple_gun;
	Animation leftward_triple_gun;
	iPoint position;

	Collider* playercollider = nullptr;
	//Vector<Collider*>* lvl_collision;
};

#endif // !__ModulePlayer_H__
