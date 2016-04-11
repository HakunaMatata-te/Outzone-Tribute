#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"


ModulePlayer::ModulePlayer(){
	position.x = SCREEN_WIDTH/2-20;
	position.y = SCREEN_HEIGHT-60;

	//Idle
	idle.x = 517;
	idle.y = 151;
	idle.h = 37;
	idle.w = 28;

}

ModulePlayer::~ModulePlayer(){};

bool ModulePlayer::Start(){
	LOG("Loading player-----------");
	bool ret = true;

	character = App->textures->Load("playermove.png");
	return ret;
};

update_status ModulePlayer::Update(){

	App->render->Blit(character, position.x, position.y, &idle);

	return UPDATE_CONTINUE;
}