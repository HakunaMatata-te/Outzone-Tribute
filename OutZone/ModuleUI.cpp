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


	uitextures = App->textures->Load("Animation/playermove.png");


	return true;
};

bool ModuleUi::CleanUp()
{
	LOG("Unloading UI");

	App->textures->Unload(uitextures);

	return true;
}

update_status ModuleUi::Update(){

	

	return UPDATE_CONTINUE;
}

update_status ModuleUi::PostUpdate()
{


	return UPDATE_CONTINUE;
}
/*
//Just for testing should be moved to ui module
void ModulePlayer::print_energy(){
	App->particles->AddParticle(App->particles->test_ui, position_test.x, position_test.y, COLLIDER_NONE);
};*/