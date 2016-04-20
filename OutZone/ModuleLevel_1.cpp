#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleLevel_1.h"
#include "ModuleLevel_2.h"
#include "ModulePlayer.h"
#include "ModuleCollider.h"
#include "ModuleParticles.h"

ModuleLevel_1::ModuleLevel_1()
{
	
	background.x = 1;
	background.y = 0;
	background.w = 240;
	background.h = 4760;
	
}

ModuleLevel_1::~ModuleLevel_1()
{}

// Load assets
bool ModuleLevel_1::Start()
{
	LOG("Loading background assets");

	lvl_texture = App->textures->Load("lvl_1.png");
	lvl_music = App->audios->LoadMusic("lvl_1.wav");
	Mix_PlayMusic(lvl_music, -1);

	//Enable modules
	App->player->Enable();
	App->collision->Enable();

	//App->player->lvl_collision = &lvl_collider;
	//Colliders

	
	lvl_collider.push_back(App->collision->AddCollider({ 100, -100, 100, 100 }, COLLIDER_WALL));
	/*
	lvl_collider.push_back(App->collision->AddCollider({ 100, 60, 10, 10 }, COLLIDER_WALL));
	lvl_collider.push_back(App->collision->AddCollider({ 100, -140, 10, 10 }, COLLIDER_WALL));
	lvl_collider.push_back(App->collision->AddCollider({ 100, SCREEN_HEIGHT - 300, 10, 10 }, COLLIDER_WALL));
	lvl_collider.push_back(App->collision->AddCollider({ 100, SCREEN_HEIGHT - 500, 10, 10 }, COLLIDER_WALL));
	*/
	
	/*
	App->collision->AddCollider({ 1, 4506, 25, 275}, COLLIDER_WALL);
	App->collision->AddCollider({ 26, 4496, 52, 250 }, COLLIDER_WALL);
	App->collision->AddCollider({ 77, 4491, 26, 232 }, COLLIDER_WALL);
	App->collision->AddCollider({ 160, 4415, 97, 136 }, COLLIDER_WALL);
	*/
	
	return true;
}

bool ModuleLevel_1::CleanUp()
{
	LOG("Unloading lvl1 scene");

	App->textures->Unload(lvl_texture);
	App->player->Disable();
	App->collision->Disable();

	return true;
}

// Update: draw background
update_status ModuleLevel_1::Update()
{
	App->render->Blit(lvl_texture, 0, -4760 + SCREEN_HEIGHT, &background, 0.75f); //Negative value to start rendering from the bottom og the image

	if (App->input->keyboard[SDL_SCANCODE_SPACE]){
		App->fade->FadeToBlack(App->level_1, App->level_2, 3);
	}
	/*
	if (App->player->playercollider->CheckCollision(lvl_collider[0]->rect))
		exit(0);
		*/

	return UPDATE_CONTINUE;
}