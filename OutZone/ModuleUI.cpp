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
	
	idle_energybar.PushBack({ 5, 152, 128, 10});
	idle_energy.PushBack({ 136, 153, 1, 7 });
	idle_spbomb.PushBack({ 10, 96, 13, 22});
	idle_score0.PushBack({ 7, 168, 20, 32 });
	idle_score1.PushBack({ 27, 168, 20, 32 });
	idle_score2.PushBack({ 47, 168, 20, 32 });
	idle_score3.PushBack({ 67, 168, 20, 32 });
	idle_score4.PushBack({ 87, 168, 20, 32 });
	idle_score5.PushBack({ 107, 168, 20, 32 });
	idle_score6.PushBack({ 127, 168, 20, 32 });
	idle_score7.PushBack({ 147, 168, 20, 32 });
	idle_score8.PushBack({ 167, 168, 20, 32 });
	idle_score9.PushBack({ 187, 168, 20, 32 });
	digit_score = &idle_score0;
	personal_score = 0;
	highscore = 0;

	position.x = 30;
	position.y = 20;
	position_bomb = 5;
	uitextures = App->textures->Load("Animation/UIs2.png");


	return true;
};

bool ModuleUi::CleanUp()
{
	LOG("Unloading UI");

	App->textures->Unload(uitextures);

	return true;
}

update_status ModuleUi::Update(){

	if (App->player->IsEnabled() == true){
		// Energy bar;
		App->render->Blit(uitextures, 10, 20, &(idle_energybar.GetCurrentFrame()), false);

		// Energy;
		current_time = SDL_GetTicks();
		if ((current_time - last_deplation) > 1000 && infinite_energy == false){
			last_deplation = SDL_GetTicks();
			if (energy > 0){
				energy -= 1;
			}
		}
		if (energy > 10){
			for (int i = 0; i <= energy - 10; i++){
				position.x += 2;
				App->render->Blit(uitextures, position.x, position.y + 1, &(idle_energy.GetCurrentFrame()), false);
			}
		}

		//bomb munition
		if (App->player->spbombmunition >= 0)
		{
			for (int i = 0; i <= App->player->spbombmunition; i++)
			{
				App->render->Blit(uitextures, position_bomb, 280, &(idle_spbomb.GetCurrentFrame()), false);
				position_bomb += 15;
			}
		}

		if (personal_score > highscore)
			highscore = personal_score;

		print_score(personal_score, 120, 40);
		print_score(highscore, 220, 10);
	}
	else personal_score = 0;


	return UPDATE_CONTINUE;
}

update_status ModuleUi::PostUpdate()
{
	position.x = 30;
	position_bomb = 5;
	
	return UPDATE_CONTINUE;
}

void ModuleUi::print_score(uint score, int score_postion_x, int score_position_y)
{
	
	uint numberofdigits = number_digits(score);
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
		score_postion_x -= 22;
		
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