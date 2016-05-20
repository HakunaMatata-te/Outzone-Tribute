#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleLevel_2.h"
#include "ModuleLevel_3.h"
#include "ModulePlayer.h"
#include "ModuleCollider.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModuleObjects.h"

ModuleLevel_3::ModuleLevel_3()
{

	background.x = 1;
	background.y = 0;
	background.w = 240;
	background.h = 6436;

}

ModuleLevel_3::~ModuleLevel_3()
{}

// Load assets
bool ModuleLevel_3::Start()
{
	LOG("Loading background assets");

	lvl_texture = App->textures->Load("Maps/lvl_3.png");
	//App->audios->PlayMusic("Sounds/lvl_1.ogg", -1.0f);

	//Enable modules
	App->player->Enable();
	App->collision->Enable();
	App->enemies->Enable();
	App->particles->Enable();
	App->objects->Enable();

	App->render->camera.y = 0;

	//Colliders
	//First two colliders, left and right
	App->collision->AddCollider({ 0, App->collision->returny(4247, background.h), 95, 240 }, COLLIDER_WALL);
	


	//Enemies
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 130, App->collision->returny(4350, background.h));

	return true;
}

bool ModuleLevel_3::CleanUp()
{
	LOG("Unloading lvl1 scene");

	App->textures->Unload(lvl_texture);
	App->player->Disable();
	App->enemies->Disable();
	App->particles->Disable();
	App->collision->Disable();
	App->objects->Disable();

	return true;
}

// Update: draw background
update_status ModuleLevel_3::Update()
{
	App->render->Blit(lvl_texture, 0, -6436 + SCREEN_HEIGHT, &background, 1); //Negative value to start rendering from the bottom og the image

	return UPDATE_CONTINUE;
}