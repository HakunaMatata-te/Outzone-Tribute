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
	

	App->collision->AddCollider({ 1, App->collision->returny(4247, background.h), 95, 240}, COLLIDER_WALL); 
	
	App->enemies->AddEnemy(TRUCK, 150, App->collision->returny(4420, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 60, App->collision->returny(4570, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_RED, 100, App->collision->returny(4570, background.h));
	App->enemies->AddEnemy(MINOR_TURRET, 34, App->collision->returny(4692, background.h));

	App->enemies->AddEnemy(TRUCK, 34, App->collision->returny(4000, background.h));
	
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

	return UPDATE_CONTINUE;
}