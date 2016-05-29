#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"
#include "ModuleEnemies.h"
#include "ModuleUI.h"

#include "SDL\include\SDL.h"



ModuleUi::ModuleUi(){


}

ModuleUi::~ModuleUi(){};

bool ModuleUi::Start(){
	LOG("Loading UI-----------");

	last_deplation = SDL_GetTicks();
	current_time = SDL_GetTicks();
	energy = MAX_N_ENERGY;
	infinite_energy = false;
	
	idle_energybar.PushBack({ 26, 40, 96, 9});
	idle_energy.PushBack({ 125, 41, 1, 7 });
	idle_spbomb.PushBack({ 92, 17, 8, 15});
	idle_score0.PushBack({ 111, 21, 7, 7 });
	idle_score1.PushBack({ 121, 21, 7, 7 });
	idle_score2.PushBack({ 132, 21, 7, 7 });
	idle_score3.PushBack({ 144, 21, 7, 7 });
	idle_score4.PushBack({ 156, 21, 7, 7 });
	idle_score5.PushBack({ 168, 21, 7, 7});
	idle_score6.PushBack({ 180, 21, 7, 7 });
	idle_score7.PushBack({ 192, 21, 7, 7 });
	idle_score8.PushBack({ 204, 21, 7, 7 });
	idle_score9.PushBack({ 216, 21, 7, 7 });

	idle_playername.PushBack({ 28, 21, 56, 8});
	idle_playerlive.PushBack({262, 13, 10, 17});
	idle_top.PushBack({ 232, 20, 22, 8});
	idle_numlives.PushBack({ 300, 16, 6, 16 });
	go_ahead.PushBack({ 211, 66, 51, 49 });
	go_ahead.PushBack({ 328, 66, 51, 49 });
	go_ahead.speed = 0.05f;
	outofenergy.PushBack({ 285, 83, 41, 23 });
//	outofenergy.PushBack({ 286, 86, 39, 17 });
	outofenergy.PushBack({ 286, 56, 39, 17 });
	outofenergy.speed = 0.05f;

	upper.x = 0;
	upper.y = 0;
	upper.h = 6436;
	upper.w = 240;

	digit_score = &idle_score0;
	personal_score = 0;
	highscore = 0;

	position.x = 15;
	position.y = 17;
	position_bomb = 0;
	go_aheadtimer = current_time;
	uitextures = App->textures->Load("Animation/UIs.png");
	uppermaptexture = App->textures->Load("Maps/lvl_3_upper.png");

	return true;
};

bool ModuleUi::CleanUp()
{
	LOG("Unloading UI");
	App->textures->Unload(uppermaptexture);
	App->textures->Unload(uitextures);
	
	return true;
}

update_status ModuleUi::Update(){

	//upper map
	App->render->Blit(uppermaptexture, 0, -6436 + SCREEN_HEIGHT, &upper, 1);

	if (App->player->IsEnabled() == true){
		// Energy bar;
		App->render->Blit(uitextures, 0, 17, &(idle_energybar.GetCurrentFrame()), false);
		//player name
		App->render->Blit(uitextures, 28, 0, &(idle_playername.GetCurrentFrame()), false);
		//player live
		App->render->Blit(uitextures, 0, 0, &(idle_playerlive.GetCurrentFrame()), false);
		App->render->Blit(uitextures, 11, 1, &(idle_numlives.GetCurrentFrame()), false);
		//top score;
		App->render->Blit(uitextures, 108, 0, &(idle_top.GetCurrentFrame()), false);
		//go_ahead;
		if (App->player->position.y > ((App->player->screenlowheight - SCREEN_HEIGHT) + App->player->screenlowheight) / 2 && curren_deplation == false && App->player->position.y <= -5400 * SCREEN_SIZE)
		{
			curren_deplation = true;
			go_aheadtimer = current_time;
		}
		else if (App->player->position.y < ((App->player->screenlowheight - SCREEN_HEIGHT) + App->player->screenlowheight) / 2) 
		{
			go_aheadtimer = current_time;
			curren_deplation = false;
		}
		if (go_aheadtimer + 6000 <= current_time && curren_deplation == true)
			App->render->Blit(uitextures, 95, 50, &(go_ahead.GetCurrentFrame()), false);
		// Energy;
		current_time = SDL_GetTicks();
		if ((current_time - last_deplation) > 1000 && infinite_energy == false){
			last_deplation = SDL_GetTicks();
			if (energy > 0){
				energy -= 1;
			}
		}
		if (energy > 11){
			for (int i = 0; i <= energy - 11; i++){
				position.x += 2;
				App->render->Blit(uitextures, position.x, position.y + 1, &(idle_energy.GetCurrentFrame()), false);
			}
		}
		else App->render->Blit(uitextures, 20, 30, &(outofenergy.GetCurrentFrame()), false);

		//bomb munition
		if (App->player->spbombmunition >= 0)
		{
			for (int i = 0; i <= App->player->spbombmunition; i++)
			{
				App->render->Blit(uitextures, position_bomb, 304, &(idle_spbomb.GetCurrentFrame()), false);
				position_bomb += 8;
			}
		}

		if (personal_score > highscore)
			highscore = personal_score;

		print_score(personal_score, 78, 9, false);
		print_score(highscore, 120, 9, true);
	}
	else personal_score = 0;


	return UPDATE_CONTINUE;
}

update_status ModuleUi::PostUpdate()
{
	position.x = 15;
	position_bomb = 0;
	
	return UPDATE_CONTINUE;
}

void ModuleUi::print_score(uint score, int score_postion_x, int score_position_y, bool high)
{
	
	uint numberofdigits = number_digits(score);
	if (high == true){
		score_postion_x += (numberofdigits - 1) * 5;
	}
	int i = 0;
	while (i <= numberofdigits)
	{
		i++;
		digit = digit_x(score, i);
		switch (digit)
		{
		case 0: digit_score = &idle_score0;
			break;
		case 1: digit_score = &idle_score1;
			break;
		case 2: digit_score = &idle_score2;
			break;
		case 3: digit_score = &idle_score3;
			break;
		case 4: digit_score = &idle_score4;
			break;
		case 5: digit_score = &idle_score5;
			break;
		case 6: digit_score = &idle_score6;
			break;
		case 7: digit_score = &idle_score7;
			break;
		case 8: digit_score = &idle_score8;
			break;
		case 9: digit_score = &idle_score9;
			break;
		}
		
		App->render->Blit(uitextures, score_postion_x, score_position_y, &digit_score->GetCurrentFrame(), false);
		score_postion_x -= 8;
		
	}
}

int ModuleUi::digit_x(int num, int k) {
	int flag, j;
	j = 0;
	flag = num;
	while (j != k) {
		num = flag % 10;
		flag = flag / 10;
		j++;
	}
	return num;
}

int ModuleUi::number_digits(int num) {
	int flag;
	int l = 0;
	flag = num;
	while (flag != 0) {
		num = flag % 10;
		flag = flag / 10;
		l++;
	}
	return l;
}