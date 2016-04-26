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
	App->particles->Enable();

	App->render->camera.y = 0;

	//Colliders
	//First two colliders, left and right
	App->collision->AddCollider({ 0, App->collision->returny(4247, background.h), 95, 240}, COLLIDER_WALL); 
	App->collision->AddCollider({ 161, App->collision->returny(4284, background.h), 85, 98 }, COLLIDER_WALL);
	App->collision->AddCollider({ 180, App->collision->returny(4382, background.h), 77, 32 }, COLLIDER_WALL);

	//Columns
	App->collision->AddCollider({ 130, App->collision->returny(3706, background.h), 32, 64 }, COLLIDER_WALL);
	App->collision->AddCollider({ 193, App->collision->returny(3642, background.h), 32, 64 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0, App->collision->returny(3514, background.h), 32, 64 }, COLLIDER_WALL);
	App->collision->AddCollider({ 161, App->collision->returny(3355, background.h), 32, 64 }, COLLIDER_WALL);

	//Big stone blocks
	App->collision->AddCollider({ 0, App->collision->returny(3220, background.h), 32, 37 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0, App->collision->returny(3075, background.h), 127, 146 }, COLLIDER_WALL);
	App->collision->AddCollider({ 200, App->collision->returny(3075, background.h), 58, 147 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0, App->collision->returny(2790, background.h), 62, 147 }, COLLIDER_WALL);
	App->collision->AddCollider({ 135, App->collision->returny(2790, background.h), 122, 147 }, COLLIDER_WALL);

	//More columns
	App->collision->AddCollider({ 65, App->collision->returny(2682, background.h), 32, 64 }, COLLIDER_WALL);
	App->collision->AddCollider({ 194, App->collision->returny(2650, background.h), 32, 64 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0, App->collision->returny(2618, background.h), 32, 64 }, COLLIDER_WALL);
	App->collision->AddCollider({ 97, App->collision->returny(2522, background.h), 32, 64 }, COLLIDER_WALL);

	//End walls
	App->collision->AddCollider({ 0, App->collision->returny(1301, background.h), 32, 82 }, COLLIDER_WALL);
	App->collision->AddCollider({ 32, App->collision->returny(1313, background.h), 63, 65 }, COLLIDER_WALL);
	App->collision->AddCollider({ 161, App->collision->returny(1313, background.h), 63, 65 }, COLLIDER_WALL);
	App->collision->AddCollider({ 220, App->collision->returny(1301, background.h), 32, 82 }, COLLIDER_WALL);
	
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 137, App->collision->returny(4000, background.h));
	
	return true;
}

bool ModuleLevel_1::CleanUp()
{
	LOG("Unloading lvl1 scene");

	App->textures->Unload(lvl_texture);
	App->player->Disable();
	App->enemies->Disable();
	App->particles->Disable();
	App->collision->Disable();

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