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
#include "ModuleEnemies.h"

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

	lvl_texture = App->textures->Load("Maps/lvl_1.png");
	App->audios->PlayMusic("Sounds/lvl_1.wav", -1.0f);

	//Enable modules
	App->player->Enable();
	App->collision->Enable();
	App->enemies->Enable();

	App->render->camera.y = 0;

	//App->player->lvl_collision = &lvl_collider;
	//Colliders

	
	lvl_collider.push_back(App->collision->AddCollider({ 1, App->collision->returny(4247, background.h), 95, 240}, COLLIDER_WALL)); 
	

	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 100 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 200 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 300 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 400 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 500 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 600 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 700 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 800 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 900 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 1000 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 1100 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 1200 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 1300 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 1400 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 1500 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 1600 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 1700 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 1800 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 1900 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 2000 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 2100 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 2200 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 2300 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 2400 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 2500 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 2600 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 2700 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 2800 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 2900 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 3000 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 3100 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 3200 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 3300 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 3400 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 3500 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 3600 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 3700 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 3800 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 3900 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 4000 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 4100 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 4200 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 4300 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 4400 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 4500 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 4600 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 4700 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 4800 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 4900 - 4760);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, 5000 - 4760);
	
	return true;
}

bool ModuleLevel_1::CleanUp()
{
	LOG("Unloading lvl1 scene");

	App->textures->Unload(lvl_texture);
	App->player->Disable();
	App->collision->Disable();
	App->enemies->Disable();

	return true;
}

// Update: draw background
update_status ModuleLevel_1::Update()
{
	App->render->Blit(lvl_texture, 0, -4760 + SCREEN_HEIGHT, &background, 1); //Negative value to start rendering from the bottom og the image

	if (App->input->keyboard[SDL_SCANCODE_SPACE]){
		App->fade->FadeToBlack(App->level_1, App->level_2, 3);
	}

	int num_colliders = lvl_collider.size();

	/*
	for (uint i = 0; i < num_colliders; i++)
		lvl_collider[i]->SetPos(lvl_collider[i]->rect.x, lvl_collider[i]->rect.y -= App->render->camera.y);
	
	if (App->player->playercollider->CheckCollision(lvl_collider[0]->rect))
		exit(0);
	*/

	return UPDATE_CONTINUE;
}