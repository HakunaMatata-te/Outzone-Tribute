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
#include "ModuleUI.h"

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
	App->ui->Enable();
	App->render->camera.y = 0;

	//Colliders
	//first holes colliders;
	App->collision->AddCollider({ 0, App->collision->returny(5600, background.h), 46, 320 }, COLLIDER_HOLE);
	App->collision->AddCollider({ 46, App->collision->returny(5700, background.h), 35, 120}, COLLIDER_HOLE);
	App->collision->AddCollider({ 0, App->collision->returny(5200, background.h), 80, 157}, COLLIDER_HOLE);
	App->collision->AddCollider({ 50, App->collision->returny(5271, background.h), 60, 182}, COLLIDER_HOLE);
	App->collision->AddCollider({ 110, App->collision->returny(5327, background.h), 35, 93}, COLLIDER_HOLE);
	App->collision->AddCollider({ 145, App->collision->returny(5360, background.h), 35, 60}, COLLIDER_HOLE);
	App->collision->AddCollider({ 207, App->collision->returny(5136, background.h), 34, 164}, COLLIDER_HOLE);
	App->collision->AddCollider({ 175, App->collision->returny(5170, background.h), 32, 63 }, COLLIDER_HOLE);

	//Last holes colliders (before boss)
	App->collision->AddCollider({ 0, App->collision->returny(640, background.h), 32, 480 }, COLLIDER_HOLE);
	App->collision->AddCollider({ 32, App->collision->returny(704, background.h), 32, 288 }, COLLIDER_HOLE);
	App->collision->AddCollider({ 64, App->collision->returny(704, background.h), 32, 64 }, COLLIDER_HOLE);
	App->collision->AddCollider({ 64, App->collision->returny(866, background.h), 32, 126 }, COLLIDER_HOLE);
	App->collision->AddCollider({ 96, App->collision->returny(930, background.h), 32, 62 }, COLLIDER_HOLE);
	App->collision->AddCollider({ 0, App->collision->returny(1185, background.h), 64, 127 }, COLLIDER_HOLE);
	App->collision->AddCollider({ 144, App->collision->returny(705, background.h), 32, 63 }, COLLIDER_HOLE);
	App->collision->AddCollider({ 175, App->collision->returny(706, background.h), 32, 191 }, COLLIDER_HOLE);
	App->collision->AddCollider({ 208, App->collision->returny(640, background.h), 32, 288 }, COLLIDER_HOLE);
	App->collision->AddCollider({ 112, App->collision->returny(1057, background.h), 64, 63 }, COLLIDER_HOLE);
	App->collision->AddCollider({ 176, App->collision->returny(1057, background.h), 32, 256 }, COLLIDER_HOLE);
	App->collision->AddCollider({ 208, App->collision->returny(991, background.h), 32, 321 }, COLLIDER_HOLE); 

	//Walls colliders first yellow
	App->collision->AddCollider({ 0, App->collision->returny(4224, background.h), 16, 576 }, COLLIDER_WALL);
	App->collision->AddCollider({ 224, App->collision->returny(4224, background.h), 16, 576 }, COLLIDER_WALL);
	App->collision->AddCollider({ 16, App->collision->returny(4224, background.h), 48, 96 }, COLLIDER_WALL);
	App->collision->AddCollider({ 192, App->collision->returny(4224, background.h), 32, 96 }, COLLIDER_WALL);
	App->collision->AddCollider({ 16, App->collision->returny(4705, background.h), 48, 95 }, COLLIDER_WALL);
	App->collision->AddCollider({ 192, App->collision->returny(4705, background.h), 32, 95 }, COLLIDER_WALL);
	
	//Walls colliders second
	App->collision->AddCollider({ 32, App->collision->returny(3873, background.h), 96, 63 }, COLLIDER_WALL);
	App->collision->AddCollider({ 128, App->collision->returny(3905, background.h), 64, 62 }, COLLIDER_WALL);
	App->collision->AddCollider({ 65, App->collision->returny(3936, background.h), 31, 31 }, COLLIDER_WALL);
	App->collision->AddCollider({ 96, App->collision->returny(3936, background.h), 32, 64 }, COLLIDER_WALL);

	App->collision->AddCollider({ 0, App->collision->returny(3744, background.h), 64, 64 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0, App->collision->returny(3808, background.h), 32, 31 }, COLLIDER_WALL);

	App->collision->AddCollider({ 160, App->collision->returny(3744, background.h), 32, 63 }, COLLIDER_WALL);
	App->collision->AddCollider({ 128, App->collision->returny(3744, background.h), 32, 95 }, COLLIDER_WALL);
	App->collision->AddCollider({ 192, App->collision->returny(3712, background.h), 48, 127 }, COLLIDER_WALL);
	App->collision->AddCollider({ 224, App->collision->returny(3839, background.h), 16, 32}, COLLIDER_WALL);
	
	App->collision->AddCollider({ 0, App->collision->returny(3649, background.h), 32, 62 }, COLLIDER_WALL);

	App->collision->AddCollider({ 64, App->collision->returny(3585, background.h), 64, 62 }, COLLIDER_WALL);
	App->collision->AddCollider({ 96, App->collision->returny(3647, background.h), 32, 64 }, COLLIDER_WALL);
	App->collision->AddCollider({ 128, App->collision->returny(3553, background.h), 32, 94 }, COLLIDER_WALL);

	App->collision->AddCollider({ 192, App->collision->returny(3585, background.h), 48, 62 }, COLLIDER_WALL);
	App->collision->AddCollider({ 224, App->collision->returny(3647, background.h), 16, 32 }, COLLIDER_WALL);

	App->collision->AddCollider({ 0, App->collision->returny(3425, background.h), 32, 158 }, COLLIDER_WALL);
	App->collision->AddCollider({ 32, App->collision->returny(3457, background.h), 32, 32 }, COLLIDER_WALL);
	App->collision->AddCollider({ 32, App->collision->returny(3489, background.h), 64, 63 }, COLLIDER_WALL);

	App->collision->AddCollider({ 160, App->collision->returny(3457, background.h), 64, 63}, COLLIDER_WALL);
	App->collision->AddCollider({ 224, App->collision->returny(3424, background.h), 16, 127 }, COLLIDER_WALL);

	App->collision->AddCollider({ 64, App->collision->returny(3361, background.h), 96, 63 }, COLLIDER_WALL);
	App->collision->AddCollider({ 96, App->collision->returny(3424, background.h), 32, 32 }, COLLIDER_WALL);

	App->collision->AddCollider({ 192, App->collision->returny(3329, background.h), 48, 63 }, COLLIDER_WALL);

	//Walls colliders third
	App->collision->AddCollider({ 0, App->collision->returny(2432, background.h), 32, 64 }, COLLIDER_WALL);
	App->collision->AddCollider({ 224, App->collision->returny(2464, background.h), 16, 64 }, COLLIDER_WALL);
	App->collision->AddCollider({ 64, App->collision->returny(2368, background.h), 40, 64 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0, App->collision->returny(2272, background.h), 32, 96 }, COLLIDER_WALL);
	App->collision->AddCollider({ 32, App->collision->returny(2272, background.h), 32, 64 }, COLLIDER_WALL);

	App->collision->AddCollider({ 128, App->collision->returny(2272, background.h), 32, 64 }, COLLIDER_WALL);
	App->collision->AddCollider({ 192, App->collision->returny(2240, background.h), 48, 64 }, COLLIDER_WALL);
	App->collision->AddCollider({ 64, App->collision->returny(2080, background.h), 64, 64 }, COLLIDER_WALL);
	App->collision->AddCollider({ 192, App->collision->returny(2080, background.h), 64, 64 }, COLLIDER_WALL);
	App->collision->AddCollider({ 224, App->collision->returny(2048, background.h), 16, 32 }, COLLIDER_WALL);

	App->collision->AddCollider({ 0, App->collision->returny(2016, background.h), 32, 64 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0, App->collision->returny(1920, background.h), 64, 64 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0, App->collision->returny(1888, background.h), 32, 32 }, COLLIDER_WALL);
	App->collision->AddCollider({ 224, App->collision->returny(1920, background.h), 32, 64 }, COLLIDER_WALL);
	App->collision->AddCollider({ 96, App->collision->returny(1824, background.h), 32, 64 }, COLLIDER_WALL);

	App->collision->AddCollider({ 32, App->collision->returny(1760, background.h), 32, 96 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0, App->collision->returny(1728, background.h), 32, 96 }, COLLIDER_WALL);
	App->collision->AddCollider({ 64, App->collision->returny(1760, background.h), 64, 32 }, COLLIDER_WALL);
	App->collision->AddCollider({ 192, App->collision->returny(1696, background.h), 48, 65 }, COLLIDER_WALL);

	// Gate 
	App->collision->AddCollider({ 0, App->collision->returny(1312, background.h), 24, 32 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0, App->collision->returny(1344, background.h), 64, 64 }, COLLIDER_WALL);
	
	App->collision->AddCollider({ 216, App->collision->returny(1312, background.h), 24, 32 }, COLLIDER_WALL);
	App->collision->AddCollider({ 176, App->collision->returny(1344, background.h), 64, 64 }, COLLIDER_WALL);

	//Enemies
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, App->collision->returny(5350, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 100, App->collision->returny(5550, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 110, App->collision->returny(5850, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 90, App->collision->returny(5050, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, App->collision->returny(5250, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 190, App->collision->returny(5950, background.h));


	App->objects->AddObject(ENERGYBOX, 30, App->collision->returny(6300, background.h));

	boss_start = false;
	first_lava = false;
	second_lava = false;
	return true;
}

bool ModuleLevel_3::CleanUp()
{
	LOG("Unloading lvl3 scene");

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
	App->render->Blit(lvl_texture, 0, -6436 + SCREEN_HEIGHT, &background, 1); //Negative value to start rendering from the bottom of the image

	//Boss lava
	//Pick the time when entering boss
	if (boss_start == false && App->render->camera.y >= 5925*SCREEN_SIZE){
		boss_start = true;
		lava_timer = SDL_GetTicks();
	}

	if (App->render->camera.y >= 5925 && boss_start == true){
		//Right lava (1st to appear)
		if ((SDL_GetTicks() - lava_timer) > 4000 && first_lava == false){
			App->collision->AddCollider({ 130, App->collision->returny(480, background.h), 100, 50 }, COLLIDER_HOLE);
			App->collision->AddCollider({ 140, App->collision->returny(473, background.h), 100, 50 }, COLLIDER_HOLE);
			App->collision->AddCollider({ 150, App->collision->returny(469, background.h), 100, 50 }, COLLIDER_HOLE);
			App->collision->AddCollider({ 160, App->collision->returny(464, background.h), 100, 50 }, COLLIDER_HOLE);
			App->collision->AddCollider({ 170, App->collision->returny(458, background.h), 100, 50 }, COLLIDER_HOLE);
			App->collision->AddCollider({ 180, App->collision->returny(452, background.h), 100, 50 }, COLLIDER_HOLE);
			App->collision->AddCollider({ 190, App->collision->returny(449, background.h), 100, 50 }, COLLIDER_HOLE);
			App->collision->AddCollider({ 200, App->collision->returny(442, background.h), 100, 50 }, COLLIDER_HOLE);
			App->collision->AddCollider({ 210, App->collision->returny(437, background.h), 100, 50 }, COLLIDER_HOLE);
			App->collision->AddCollider({ 220, App->collision->returny(434, background.h), 100, 50 }, COLLIDER_HOLE);
			App->collision->AddCollider({ 230, App->collision->returny(427, background.h), 100, 50 }, COLLIDER_HOLE);
			App->collision->AddCollider({ 240, App->collision->returny(421, background.h), 100, 50 }, COLLIDER_HOLE);
			App->collision->AddCollider({ 250, App->collision->returny(417, background.h), 100, 50 }, COLLIDER_HOLE);
			first_lava = true;
			lava_timer = SDL_GetTicks();
		}

		if ((SDL_GetTicks() - lava_timer) > 4000 && first_lava == true && second_lava == false){
			App->collision->AddCollider({ 0, App->collision->returny(300, background.h), 84, 100 }, COLLIDER_HOLE);
			second_lava = true;
		}
	}
	
	return UPDATE_CONTINUE;
}