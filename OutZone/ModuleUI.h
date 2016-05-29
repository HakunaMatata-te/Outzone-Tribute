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


public:

	uint energy;
	uint position_bomb;
	uint last_deplation;
	uint current_time;
	bool infinite_energy;
	bool curren_deplation;
	iPoint position_test;

	//puntuació
	uint highscore;
	uint personal_score;
	uint digit;
	uint go_aheadtimer;


	SDL_Texture* uitextures = nullptr;
	SDL_Texture* uppermaptexture = nullptr;

	Animation idle_energybar;
	Animation idle_energy;
	Animation idle_spbomb;
	
	Animation idle_score0;
	Animation idle_score1;
	Animation idle_score2;
	Animation idle_score3;
	Animation idle_score4;
	Animation idle_score5;
	Animation idle_score6;
	Animation idle_score7;
	Animation idle_score8;
	Animation idle_score9;
	Animation idle_playername;
	Animation idle_playerlive;
	Animation idle_top;
	Animation idle_numlives;
	Animation go_ahead;
	Animation outofenergy;
	
	SDL_Rect upper;

	Animation* digit_score = nullptr;
	iPoint position;
	
	void print_score(uint score, int score_postion_x, int score_position_y, bool high);
	int digit_x(int num, int k);
	int number_digits(int num);
};

#endif
