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
	idle_energybar.PushBack({ 54, 244, 4, 16 });

	position.x = 10;
	position.y = 10;

	uitextures = App->textures->Load("Animation/particles.png");


	return true;
};

bool ModuleUi::CleanUp()
{
	LOG("Unloading UI");

	App->textures->Unload(uitextures);

	return true;
}

update_status ModuleUi::Update(){

	current_time = SDL_GetTicks();
	if ((current_time - last_deplation) > 1000 && infinite_energy == false){
		last_deplation = SDL_GetTicks();
		if (energy > 0){
			energy-=2;
		}
	}
	if (energy > 10){
		for (int i = 0; i <= energy - 10; i++){
			position.x += 5;
			print_energy();
		}
	}
	//Testing e_bars
	
	return UPDATE_CONTINUE;
}

update_status ModuleUi::PostUpdate()
{
	position.x = 10;

	return UPDATE_CONTINUE;
}

//Just for testing should be moved to ui module
void ModuleUi::print_energy(){
	App->render->Blit(uitextures, position.x, position.y, &(idle_energybar.GetCurrentFrame()), false);
};