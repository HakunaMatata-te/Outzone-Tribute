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
#include "ModuleObjects.h"

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
	App->audios->PlayMusic("Sounds/lvl_1.ogg", -1.0f);

	//Enable modules
	App->player->Enable();
	App->collision->Enable();
	App->enemies->Enable();
	App->particles->Enable();
	App->objects->Enable();

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
	
	//Enemies
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 130, App->collision->returny(4350, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 100, App->collision->returny(4300, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 130, App->collision->returny(4250, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 130, App->collision->returny(4200, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 100, App->collision->returny(4180, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 85, App->collision->returny(4120, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 100, App->collision->returny(4000, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 127, App->collision->returny(4020, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 154, App->collision->returny(4000, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 25, App->collision->returny(4090, background.h));//
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 60, App->collision->returny(3940, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 90, App->collision->returny(3924, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 115, App->collision->returny(3950, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_RED, 146, App->collision->returny(3890, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 176, App->collision->returny(3900, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 206, App->collision->returny(3920, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 30, App->collision->returny(3835, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 60, App->collision->returny(3850, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 80, App->collision->returny(3837, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 120, App->collision->returny(3770, background.h));//
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 147, App->collision->returny(3790, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 174, App->collision->returny(3770, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 10, App->collision->returny(3685, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 60, App->collision->returny(3715, background.h));//
	App->enemies->AddEnemy(TRUCK, 40, App->collision->returny(3380, background.h));//
	App->enemies->AddEnemy(TRUCK, 20, App->collision->returny(1745, background.h));//
	App->enemies->AddEnemy(TRUCK, 166, App->collision->returny(2010, background.h));//
	App->enemies->AddEnemy(TRUCK, 166, App->collision->returny(1480, background.h));//
	App->enemies->AddEnemy(MINOR_TURRET, 10, App->collision->returny(2415, background.h));
	App->enemies->AddEnemy(MINOR_TURRET, 75, App->collision->returny(2409, background.h));
	App->enemies->AddEnemy(MINOR_TURRET, 145, App->collision->returny(2400, background.h));
	App->enemies->AddEnemy(MINOR_TURRET, 200, App->collision->returny(2424, background.h));
	App->enemies->AddEnemy(MINOR_TURRET, 178, App->collision->returny(2378, background.h));
	App->enemies->AddEnemy(MINOR_TURRET, 108, App->collision->returny(2370, background.h));
	App->enemies->AddEnemy(MINOR_TURRET, 43, App->collision->returny(2370, background.h));
	App->enemies->AddEnemy(MINOR_TURRET, 20, App->collision->returny(2330, background.h));
	App->enemies->AddEnemy(MINOR_TURRET, 100, App->collision->returny(2320, background.h));
	App->enemies->AddEnemy(MINOR_TURRET, 155, App->collision->returny(2330, background.h));
	App->enemies->AddEnemy(MINOR_TURRET, 200, App->collision->returny(2300, background.h));
	App->enemies->AddEnemy(MINOR_TURRET, 140, App->collision->returny(2274, background.h));
	App->enemies->AddEnemy(MINOR_TURRET, 73, App->collision->returny(2280, background.h));
	App->enemies->AddEnemy(MINOR_TURRET, 5, App->collision->returny(2290, background.h));
	App->enemies->AddEnemy(MINOR_TURRET, 4, App->collision->returny(3860, background.h));
	App->enemies->AddEnemy(MINOR_TURRET, 130, App->collision->returny(3824, background.h));
	App->enemies->AddEnemy(MINOR_TURRET, 196, App->collision->returny(3760, background.h));//
	App->enemies->AddEnemy(MINOR_TURRET, 131, App->collision->returny(3444, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 75, App->collision->returny(3300, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 95, App->collision->returny(3285, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_RED, 115, App->collision->returny(3270, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 188, App->collision->returny(3290, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 180, App->collision->returny(3260, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 202, App->collision->returny(3228, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 133, App->collision->returny(3188, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 155, App->collision->returny(3168, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 176, App->collision->returny(3145, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 134, App->collision->returny(3126, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 131, App->collision->returny(3085, background.h));//
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 142, App->collision->returny(2935, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 76, App->collision->returny(2970, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 109, App->collision->returny(2970, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 142, App->collision->returny(2970, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 175, App->collision->returny(2970, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 208, App->collision->returny(2970, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 10, App->collision->returny(3005, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 43, App->collision->returny(3005, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_RED, 76, App->collision->returny(3005, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 109, App->collision->returny(3005, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 142, App->collision->returny(3005, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 10, App->collision->returny(3040, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 43, App->collision->returny(3040, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 76, App->collision->returny(3040, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 109, App->collision->returny(3040, background.h));
	//App->objects->AddObject(BOX, 130, App->collision->returny(4350, background.h));


	//BOSS
	App->enemies->AddEnemy(FIRST_BOSS, 80, App->collision->returny(1090, background.h));

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
	App->objects->Disable();

	return true;
}

// Update: draw background
update_status ModuleLevel_1::Update()
{
	App->render->Blit(lvl_texture, 0, -4760 + SCREEN_HEIGHT, &background, 1); //Negative value to start rendering from the bottom og the image

	return UPDATE_CONTINUE;
}