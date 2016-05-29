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

	platform.x = 1;
	platform.y = 0;
	platform.y = 240;
	platform.h = 200;

	lava.PushBack({ 0, 0, 240, 830 });
	lava.PushBack({ 269, 0, 240, 830 });
	lava.PushBack({ 538, 0, 240, 830 });
	lava.speed = 0.01f;

	paralaxleft.PushBack({ 924, 8, 64, 815 });
	paralaxright.PushBack({ 822, 8, 46, 815 });


}

ModuleLevel_3::~ModuleLevel_3()
{}

// Load assets
bool ModuleLevel_3::Start()
{
	LOG("Loading background assets");

	lvl_texture = App->textures->Load("Maps/lvl_3.png");
	right_platform = App->textures->Load("Maps/Right_boss_platform_test.png");
	lava_texture = App->textures->Load("Maps/Lava_animation.png");
	//App->audios->PlayMusic("Sounds/lvl_1.ogg", -1.0f);

	//Enable modules
	App->player->Enable();
	App->collision->Enable();
	App->enemies->Enable();
	App->particles->Enable();
	App->objects->Enable();
	App->ui->Enable();
	App->render->camera.y = 0;


	//Colliders	---------------------------------------------------------------------------------------------------------
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
	App->collision->AddCollider({ 32, App->collision->returny(704, background.h), 33, 288 }, COLLIDER_HOLE);
	App->collision->AddCollider({ 65, App->collision->returny(704, background.h), 31, 64 }, COLLIDER_HOLE);
	App->collision->AddCollider({ 65, App->collision->returny(866, background.h), 31, 126 }, COLLIDER_HOLE);
	App->collision->AddCollider({ 96, App->collision->returny(930, background.h), 32, 62 }, COLLIDER_HOLE);
	App->collision->AddCollider({ 0, App->collision->returny(1185, background.h), 64, 128 }, COLLIDER_HOLE);
	App->collision->AddCollider({ 144, App->collision->returny(704, background.h), 31, 64 }, COLLIDER_HOLE);
	App->collision->AddCollider({ 175, App->collision->returny(704, background.h), 33, 192 }, COLLIDER_HOLE);
	App->collision->AddCollider({ 208, App->collision->returny(640, background.h), 32, 288 }, COLLIDER_HOLE);
	App->collision->AddCollider({ 112, App->collision->returny(1057, background.h), 64, 63 }, COLLIDER_HOLE);
	App->collision->AddCollider({ 176, App->collision->returny(1057, background.h), 32, 256 }, COLLIDER_HOLE);
	App->collision->AddCollider({ 208, App->collision->returny(991, background.h), 32, 322 }, COLLIDER_HOLE); 

	//Wall turret colliders
	//Left wall
	App->collision->AddCollider({ 0, App->collision->returny(4224, background.h), 64, 95 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0, App->collision->returny(4320, background.h), 16, 385 }, COLLIDER_TURRET_WALL);
	App->collision->AddCollider({ 0, App->collision->returny(4705, background.h), 64, 95 }, COLLIDER_WALL);
	//Rigth wall
	App->collision->AddCollider({ 193, App->collision->returny(4224, background.h), 64, 95 }, COLLIDER_WALL);
	App->collision->AddCollider({ 225, App->collision->returny(4320, background.h), 16, 385 }, COLLIDER_TURRET_WALL);
	App->collision->AddCollider({ 193, App->collision->returny(4705, background.h), 64, 95 }, COLLIDER_WALL);


	
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
	App->collision->AddCollider({ 64, App->collision->returny(2368, background.h), 32, 64 }, COLLIDER_WALL);
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

	//Enemys base
	App->collision->AddCollider({ 0, App->collision->returny(2576, background.h), 32, 143 }, COLLIDER_WALL);
	App->collision->AddCollider({ 32, App->collision->returny(2608, background.h), 32, 79 }, COLLIDER_WALL);
	
	App->collision->AddCollider({ 128, App->collision->returny(2608, background.h), 32, 79 }, COLLIDER_WALL);
	App->collision->AddCollider({ 224, App->collision->returny(2608, background.h), 32, 79 }, COLLIDER_WALL);
	App->collision->AddCollider({ 160, App->collision->returny(2592, background.h), 63, 127 }, COLLIDER_WALL);
	
	App->collision->AddCollider({ 64, App->collision->returny(2480, background.h), 128, 79 }, COLLIDER_WALL);
	App->collision->AddCollider({ 96, App->collision->returny(2447, background.h), 64, 33 }, COLLIDER_WALL);
	App->collision->AddCollider({ 96, App->collision->returny(2368, background.h), 56, 79 }, COLLIDER_WALL);
	
	App->collision->AddCollider({ 192, App->collision->returny(2352, background.h), 48, 79 }, COLLIDER_WALL);
	
	App->collision->AddCollider({ 96, App->collision->returny(1920, background.h), 64, 127 }, COLLIDER_WALL);
	App->collision->AddCollider({ 160, App->collision->returny(1968, background.h), 32, 79 }, COLLIDER_WALL);
	
	App->collision->AddCollider({ 160, App->collision->returny(1808, background.h), 80, 79 }, COLLIDER_WALL);
	
	App->collision->AddCollider({ 32, App->collision->returny(1712, background.h), 96, 47 }, COLLIDER_WALL);
	
	// Gate 
	App->collision->AddCollider({ 0, App->collision->returny(1312, background.h), 24, 32 }, COLLIDER_WALL);
	App->collision->AddCollider({ 0, App->collision->returny(1344, background.h), 64, 78 }, COLLIDER_WALL);
	
	App->collision->AddCollider({ 216, App->collision->returny(1312, background.h), 24, 32 }, COLLIDER_WALL);
	App->collision->AddCollider({ 176, App->collision->returny(1344, background.h), 64, 78 }, COLLIDER_WALL);

	//Enemies -----------------------------------------------------------------------------------------------------------------------

	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 180, App->collision->returny(5350, background.h), 1);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 100, App->collision->returny(5550, background.h), 1);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 110, App->collision->returny(5850, background.h), 1);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 90, App->collision->returny(5050, background.h), 1);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 150, App->collision->returny(5250, background.h), 1);
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 190, App->collision->returny(5950, background.h), 1);


	//Laser turrets
	App->enemies->AddEnemy(RIGHT_LASER_TURRET, 224, App->collision->returny(4639, background.h));
	App->enemies->AddEnemy(LEFT_LASER_TURRET, 0, App->collision->returny(4639, background.h));
	App->enemies->AddEnemy(RIGHT_LASER_TURRET, 224, App->collision->returny(4575, background.h));
	App->enemies->AddEnemy(LEFT_LASER_TURRET, 0, App->collision->returny(4575, background.h));
	App->enemies->AddEnemy(RIGHT_LASER_TURRET, 224, App->collision->returny(4511, background.h));
	App->enemies->AddEnemy(LEFT_LASER_TURRET, 0, App->collision->returny(4511, background.h));
	App->enemies->AddEnemy(RIGHT_LASER_TURRET, 224, App->collision->returny(4447, background.h));
	App->enemies->AddEnemy(LEFT_LASER_TURRET, 0, App->collision->returny(4447, background.h));
	App->enemies->AddEnemy(RIGHT_LASER_TURRET, 224, App->collision->returny(4383, background.h));
	App->enemies->AddEnemy(LEFT_LASER_TURRET, 0, App->collision->returny(4383, background.h));
	App->enemies->AddEnemy(RIGHT_LASER_TURRET, 224, App->collision->returny(4319, background.h));
	App->enemies->AddEnemy(LEFT_LASER_TURRET, 0, App->collision->returny(4319, background.h));

	//Tank shield
	App->enemies->AddEnemy(SHIELD_TANK, 144, App->collision->returny(5695, background.h), 1);

	//Horizontal moving machine
	App->enemies->AddEnemy(HORITZONTAL_MOVING_MACHINE, -64, App->collision->returny(2871, background.h), 1);
	App->enemies->AddEnemy(HORITZONTAL_MOVING_MACHINE, 240, App->collision->returny(2935, background.h), 1);
	App->enemies->AddEnemy(HORITZONTAL_MOVING_MACHINE, 240, App->collision->returny(2231, background.h), 1);
	App->enemies->AddEnemy(HORITZONTAL_MOVING_MACHINE, -64, App->collision->returny(2167, background.h), 2);


	//Infantary
	App->enemies->AddEnemy(YELLOW_INFANTERY, 150, App->collision->returny(5950, background.h), 1);
	
	App->enemies->AddEnemy(RED_INFANTERY, 100, App->collision->returny(5950, background.h), 1);


	//boss
	App->enemies->AddEnemy(BOSS_LVL3_L_CABLE, 0, App->collision->returny(212 - 45 * 5, background.h), 0, true);
	App->enemies->AddEnemy(BOSS_LVL3_L_CABLE, 0, App->collision->returny(212 - 45 * 4, background.h), 0, true);
	App->enemies->AddEnemy(BOSS_LVL3_L_CABLE, 0, App->collision->returny(212 - 45*3, background.h), 0, true);
	App->enemies->AddEnemy(BOSS_LVL3_L_CABLE, 0, App->collision->returny(212 - 45*2, background.h), 0, true);
	App->enemies->AddEnemy(BOSS_LVL3_L_CABLE, 0, App->collision->returny(212 - 45, background.h), 0, true);
	App->enemies->AddEnemy(BOSS_LVL3_R_CABLE, 227, App->collision->returny(212 - 45*5, background.h), 0, true);
	App->enemies->AddEnemy(BOSS_LVL3_R_CABLE, 227, App->collision->returny(212 - 45*4, background.h), 0, true);
	App->enemies->AddEnemy(BOSS_LVL3_R_CABLE, 227, App->collision->returny(212 - 45*3, background.h), 0, true);
	App->enemies->AddEnemy(BOSS_LVL3_R_CABLE, 227, App->collision->returny(212 - 45*2, background.h), 0, true);
	App->enemies->AddEnemy(BOSS_LVL3_R_CABLE, 227, App->collision->returny(212 - 45, background.h), 0, true);
	App->enemies->AddEnemy(BOSS_LVL3_L_LASER, 0, App->collision->returny(212, background.h),0, true);
	App->enemies->AddEnemy(BOSS_LVL3_R_LASER, 210, App->collision->returny(212, background.h),0 ,true);
	App->enemies->AddEnemy(BOSS_LVL3, 0, App->collision->returny(191, background.h), 0,true);
	App->enemies->AddEnemy(BOSS_LVL3_EYE, 110, App->collision->returny(236, background.h), 0,true);
	App->enemies->AddEnemy(BOSS_LVL3_L_DOOR, 0, App->collision->returny(243, background.h),0, true);
	App->enemies->AddEnemy(BOSS_LVL3_R_DOOR, 224, App->collision->returny(243, background.h),0, true);

	App->enemies->AddEnemy(BOSS_LVL3_FILES, 200, App->collision->returny(360, background.h), 1);
	

	//Test 
	App->enemies->AddEnemy(YELLOW_INFANTERY, 25, App->collision->returny(4671, background.h));
	App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, 200, App->collision->returny(4671, background.h));
	
	//Objects
	App->objects->AddObject(BOX, 212, App->collision->returny(6040, background.h));
	App->objects->AddObject(BOX, 10, App->collision->returny(5560, background.h));
	App->objects->AddObject(BOX, 162, App->collision->returny(3810, background.h));
	App->objects->AddObject(ENERGYBOX, 5, App->collision->returny(5380, background.h));
	App->objects->AddObject(ENERGYBOX, 206, App->collision->returny(4975, background.h));
	App->objects->AddObject(BOX, 209, App->collision->returny(5010, background.h));
	App->objects->AddObject(BOX, 70, App->collision->returny(4480, background.h));
	App->objects->AddObject(BOX, 137, App->collision->returny(4480, background.h));
	App->objects->AddObject(BOX, 70, App->collision->returny(4610, background.h));
	App->objects->AddObject(BOX, 137, App->collision->returny(4610, background.h));
	App->objects->AddObject(ENERGYBOX, 206, App->collision->returny(4185, background.h));
	App->objects->AddObject(BOX, 209, App->collision->returny(4130, background.h));
	App->objects->AddObject(ENERGYBOX, 206, App->collision->returny(3550, background.h));
	App->objects->AddObject(ENERGYBOX, 100, App->collision->returny(3330, background.h));
	App->objects->AddObject(BOX, 209, App->collision->returny(3300, background.h));
	App->objects->AddObject(BOX, 6, App->collision->returny(2990, background.h));
	App->objects->AddObject(BOX, 206, App->collision->returny(2990, background.h));
	App->objects->AddObject(ENERGYBOX, 15, App->collision->returny(2780, background.h));
	App->objects->AddObject(BOX, 206, App->collision->returny(2310, background.h));
	App->objects->AddObject(ENERGYBOX, 206, App->collision->returny(2195, background.h));
	App->objects->AddObject(ENERGYBOX, 206, App->collision->returny(1655, background.h));
	App->objects->AddObject(BOX, 209, App->collision->returny(1475, background.h));
	App->objects->AddObject(ENERGYBOX, 206, App->collision->returny(955, background.h));
	App->objects->AddObject(ENERGYBOX, 10, App->collision->returny(550, background.h));
	App->objects->AddObject(BOX, 196, App->collision->returny(550, background.h));

	//GatePrototype
	App->objects->AddObject(GATEL, 63, App->collision->returny(1356, background.h));
	App->objects->AddObject(GATER, 121, App->collision->returny(1356, background.h));


	//Terrain mods

	boss_start = false;
	first_lava = false;
	second_lava = false;
	return true;
}

bool ModuleLevel_3::CleanUp()
{
	LOG("Unloading lvl3 scene");
	App->textures->Unload(lava_texture);
	App->textures->Unload(right_platform);
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
	App->render->Blit(lava_texture, 0, -1000, &lava.GetCurrentFrame(), 1);
	App->render->Blit(lava_texture, 0, -3000, &lava.GetCurrentFrame(), 1);
	App->render->Blit(lava_texture, 0, -5500, &lava.GetCurrentFrame(), 1);
	App->render->Blit(lava_texture, 0, -6000, &lava.GetCurrentFrame(), 1);
		
	if (App->player->position.y >= -6000 && App->player->position.y <= -4500){
		App->render->Blit(lava_texture, -1, -5000, &paralaxleft.GetCurrentFrame(), 0.9);
		App->render->Blit(lava_texture, 194, -5000, &paralaxright.GetCurrentFrame(), 0.9);
	}
	App->render->Blit(lvl_texture, 0, -6436 + SCREEN_HEIGHT, &background, 1); //Negative value to start rendering from the bottom of the image

	//Boss lava
	//Pick the time when entering boss
	if (boss_start == false && App->render->camera.y >= 5925*SCREEN_SIZE){
		boss_start = true;
		lava_timer = SDL_GetTicks();
	}

	if (App->render->camera.y >= 5925 && boss_start == true){


		//Right lava colliders (1st to appear)
		if ((SDL_GetTicks() - lava_timer) > 4840 && first_lava == false){
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

		//Left lava collider (Second)
		if ((SDL_GetTicks() - lava_timer) > 9230 && first_lava == true && second_lava == false){
			App->collision->AddCollider({ 0, App->collision->returny(480, background.h), 200, 50 }, COLLIDER_HOLE);
			App->collision->AddCollider({ 0, App->collision->returny(469, background.h), 120, 50 }, COLLIDER_HOLE);
			App->collision->AddCollider({ 0, App->collision->returny(456, background.h), 110, 50 }, COLLIDER_HOLE);
			App->collision->AddCollider({ 0, App->collision->returny(449, background.h), 100, 50 }, COLLIDER_HOLE);
			App->collision->AddCollider({ 0, App->collision->returny(438, background.h), 90, 50 }, COLLIDER_HOLE);
			App->collision->AddCollider({ 0, App->collision->returny(426, background.h), 80, 50 }, COLLIDER_HOLE);
			App->collision->AddCollider({ 0, App->collision->returny(419, background.h), 70, 50 }, COLLIDER_HOLE);
			App->collision->AddCollider({ 0, App->collision->returny(408, background.h), 60, 50 }, COLLIDER_HOLE);
			App->collision->AddCollider({ 0, App->collision->returny(397, background.h), 50, 50 }, COLLIDER_HOLE);
			App->collision->AddCollider({ 0, App->collision->returny(388, background.h), 40, 50 }, COLLIDER_HOLE);
			App->collision->AddCollider({ 0, App->collision->returny(377, background.h), 30, 50 }, COLLIDER_HOLE);
			App->collision->AddCollider({ 0, App->collision->returny(366, background.h), 20, 50 }, COLLIDER_HOLE);
			App->collision->AddCollider({ 0, App->collision->returny(357, background.h), 10, 50 }, COLLIDER_HOLE);

			second_lava = true;


			//Spawning cables
			//Left

		}
	}


	//App->render->Blit(right_platform, 0, 300 + SCREEN_HEIGHT, &platform, 1, true);

	
	return UPDATE_CONTINUE;
}