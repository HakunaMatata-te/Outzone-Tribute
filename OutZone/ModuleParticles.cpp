#include <math.h>
#include <stdlib.h>
#include <time.h>

#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"

#include "SDL/include/SDL_timer.h"

#define PI 3.14159265f

ModuleParticles::ModuleParticles()
{

	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		active[i] = nullptr;
		active_b[i] = nullptr;
	}	

	//LVL 1 particles --------------------------------------------------------------
	// Minigun particle
	minigun_shot_lv1_up.anim.PushBack({ 55, 244, 4, 16 });
	minigun_shot_lv1_up.speed.y = -8;
	minigun_shot_lv1_up.life = life_shots;

	//upper rigth
	minigun_shot_lv1_upper_right.anim.PushBack({ 163, 296, 7, 15 });
	minigun_shot_lv1_upper_right.speed.x = +4;
	minigun_shot_lv1_upper_right.speed.y = -8;
	minigun_shot_lv1_upper_right.life = 1000;
	//upper left
	minigun_shot_lv1_upper_left.anim.PushBack({ 134, 297, 7, 15 });
	minigun_shot_lv1_upper_left.speed.x = -4;
	minigun_shot_lv1_upper_left.speed.y = -8;
	minigun_shot_lv1_upper_left.life = life_shots;
	//up rigth
	minigun_shot_lv1_up_right.anim.PushBack({ 186, 306, 12, 12 });
	minigun_shot_lv1_up_right.speed.x = +8;
	minigun_shot_lv1_up_right.speed.y = -8;
	minigun_shot_lv1_up_right.life = life_shots;
	//up left
	minigun_shot_lv1_up_left.anim.PushBack({ 100, 296, 12, 12 });
	minigun_shot_lv1_up_left.speed.x = -8;
	minigun_shot_lv1_up_left.speed.y = -8;
	minigun_shot_lv1_up_left.life = life_shots;
	//up rigther
	minigun_shot_lv1_up_righter.anim.PushBack({ 217, 311, 16, 10 });
	minigun_shot_lv1_up_righter.speed.x = +8;
	minigun_shot_lv1_up_righter.speed.y = -4;
	minigun_shot_lv1_up_righter.life = life_shots;
	//up lefter
	minigun_shot_lv1_up_lefter.anim.PushBack({ 73, 311, 16, 10 });
	minigun_shot_lv1_up_lefter.speed.x = -8;
	minigun_shot_lv1_up_lefter.speed.y = -4;
	minigun_shot_lv1_up_lefter.life = life_shots;
	//rigth
	minigun_shot_lv1_right.anim.PushBack({ 221, 342, 16, 4 });
	minigun_shot_lv1_right.speed.x = +8;
	minigun_shot_lv1_right.life = life_shots;
	//left
	minigun_shot_lv1_left.anim.PushBack({ 70, 342, 16, 4 });
	minigun_shot_lv1_left.speed.x = -8;
	minigun_shot_lv1_left.life = life_shots;
	//Down righter
	minigun_shot_lv1_down_righter.anim.PushBack({ 223, 364, 16, 8 });
	minigun_shot_lv1_down_righter.speed.x = +8;
	minigun_shot_lv1_down_righter.speed.y = +4;
	minigun_shot_lv1_down_righter.life = life_shots;
	//Down lefter
	minigun_shot_lv1_down_lefter.anim.PushBack({ 70, 364, 16, 8 });
	minigun_shot_lv1_down_lefter.speed.x = -8;
	minigun_shot_lv1_down_lefter.speed.y = +4;
	minigun_shot_lv1_down_lefter.life = life_shots;
	//Down right
	minigun_shot_lv1_down_right.anim.PushBack({ 204, 374, 12, 13 });
	minigun_shot_lv1_down_right.speed.x = +8;
	minigun_shot_lv1_down_right.speed.y = +8;
	minigun_shot_lv1_down_right.life = life_shots;
	//Down left
	minigun_shot_lv1_down_left.anim.PushBack({ 98, 377, 12, 13 });
	minigun_shot_lv1_down_left.speed.x = -8;
	minigun_shot_lv1_down_left.speed.y = +8;
	minigun_shot_lv1_down_left.life = life_shots;
	//Downer right
	minigun_shot_lv1_downer_right.anim.PushBack({ 181, 384, 9, 15 });
	minigun_shot_lv1_downer_right.speed.x = +4;
	minigun_shot_lv1_downer_right.speed.y = +8;
	minigun_shot_lv1_downer_right.life = life_shots;
	//Downer left
	minigun_shot_lv1_downer_left.anim.PushBack({ 127, 385, 9, 15 });
	minigun_shot_lv1_downer_left.speed.x = -4;
	minigun_shot_lv1_downer_left.speed.y = +8;
	minigun_shot_lv1_downer_left.life = life_shots;
	//Down
	minigun_shot_lv1_down.anim.PushBack({ 154, 384, 4, 16 });
	minigun_shot_lv1_down.speed.y = +8;
	minigun_shot_lv1_down.life = life_shots;



	// Triple shot particle
	triple_shot_lv1_center.anim.PushBack({ 137, 246, 6, 14 });
	triple_shot_lv1_center.speed.y = -8;
	triple_shot_lv1_center.life = life_shots;
	
	//Triple right
	triple_shot_lv1_right.anim.PushBack({ 155, 247, 9, 13 });
	triple_shot_lv1_right.speed.y = -8;
	triple_shot_lv1_right.speed.x = +2;
	triple_shot_lv1_right.life = life_shots;
	//Triple left
	triple_shot_lv1_left.anim.PushBack({ 116, 247, 9, 13 });
	triple_shot_lv1_left.speed.y = -8;
	triple_shot_lv1_left.speed.x = -2;
	triple_shot_lv1_left.life = life_shots;


	//LVL 2 particles

	//Minigun
	minigun_shot_lv2_up.anim.PushBack({ 52, 219, 10, 16 });
	minigun_shot_lv2_up.speed.y = -8;
	minigun_shot_lv2_up.life = life_shots;
	
	//upper rigth
	minigun_shot_lv2_upper_right.anim.PushBack({ 169, 272, 13, 17 });
	minigun_shot_lv2_upper_right.speed.x = +4;
	minigun_shot_lv2_upper_right.speed.y = -8;
	minigun_shot_lv2_upper_right.life = 1000;
	//upper left
	minigun_shot_lv2_upper_left.anim.PushBack({ 122, 273, 13, 17 });
	minigun_shot_lv2_upper_left.speed.x = -4;
	minigun_shot_lv2_upper_left.speed.y = -8;
	minigun_shot_lv2_upper_left.life = life_shots;
	//up rigth
	minigun_shot_lv2_up_right.anim.PushBack({ 202, 287, 15, 16 });
	minigun_shot_lv2_up_right.speed.x = +8;
	minigun_shot_lv2_up_right.speed.y = -8;
	minigun_shot_lv2_up_right.life = life_shots;
	//up left
	minigun_shot_lv2_up_left.anim.PushBack({ 81, 277, 15, 16 });
	minigun_shot_lv2_up_left.speed.x = -8;
	minigun_shot_lv2_up_left.speed.y = -8;
	minigun_shot_lv2_up_left.life = life_shots;
	//up rigther
	minigun_shot_lv2_up_righter.anim.PushBack({ 240, 299, 16, 10 });
	minigun_shot_lv2_up_righter.speed.x = +8;
	minigun_shot_lv2_up_righter.speed.y = -4;
	minigun_shot_lv2_up_righter.life = life_shots;
	//up lefter
	minigun_shot_lv2_up_lefter.anim.PushBack({ 50, 299, 16, 13 });
	minigun_shot_lv2_up_lefter.speed.x = -8;
	minigun_shot_lv2_up_lefter.speed.y = -4;
	minigun_shot_lv2_up_lefter.life = life_shots;
	//rigth
	minigun_shot_lv2_right.anim.PushBack({ 246, 339, 16, 10 });
	minigun_shot_lv2_right.speed.x = +8;
	minigun_shot_lv2_right.life = life_shots;
	//left
	minigun_shot_lv2_left.anim.PushBack({ 45, 339, 16, 10 });
	minigun_shot_lv2_left.speed.x = -8;
	minigun_shot_lv2_left.life = life_shots;
	//Down righter
	minigun_shot_lv2_down_righter.anim.PushBack({ 246, 371, 17, 13 });
	minigun_shot_lv2_down_righter.speed.x = +8;
	minigun_shot_lv2_down_righter.speed.y = +4;
	minigun_shot_lv2_down_righter.life = life_shots;
	//Down lefter
	minigun_shot_lv2_down_lefter.anim.PushBack({ 47, 371, 17, 13 });
	minigun_shot_lv2_down_lefter.speed.x = -8;
	minigun_shot_lv2_down_lefter.speed.y = +4;
	minigun_shot_lv2_down_lefter.life = life_shots;
	//Down right
	minigun_shot_lv2_down_right.anim.PushBack({ 220, 391, 15, 16 });
	minigun_shot_lv2_down_right.speed.x = +8;
	minigun_shot_lv2_down_right.speed.y = +8;
	minigun_shot_lv2_down_right.life = life_shots;
	//Down left
	minigun_shot_lv2_down_left.anim.PushBack({ 79, 393, 15, 16 });
	minigun_shot_lv2_down_left.speed.x = -8;
	minigun_shot_lv2_down_left.speed.y = +8;
	minigun_shot_lv2_down_left.life = life_shots;
	//Downer right
	minigun_shot_lv2_downer_right.anim.PushBack({ 189, 406, 13, 17 });
	minigun_shot_lv2_downer_right.speed.x = +4;
	minigun_shot_lv2_downer_right.speed.y = +8;
	minigun_shot_lv2_downer_right.life = life_shots;
	//Downer left
	minigun_shot_lv2_downer_left.anim.PushBack({ 115, 407, 13, 17 });
	minigun_shot_lv2_downer_left.speed.x = -4;
	minigun_shot_lv2_downer_left.speed.y = +8;
	minigun_shot_lv2_downer_left.life = life_shots;
	//Down
	minigun_shot_lv2_down.anim.PushBack({ 151, 409, 10, 16 });
	minigun_shot_lv2_down.speed.y = +8;
	minigun_shot_lv2_down.life = life_shots;

	// Triple shot particle
	triple_shot_lv2_center.anim.PushBack({ 135, 221, 10, 18 });
	triple_shot_lv2_center.speed.y = -8;
	triple_shot_lv2_center.life = life_shots;
	
	//Triple right
	triple_shot_lv2_right.anim.PushBack({ 165, 224, 12, 17 });
	triple_shot_lv2_right.speed.y = -8;
	triple_shot_lv2_right.speed.x = +2;
	triple_shot_lv2_right.life = life_shots;
	//Triple left
	triple_shot_lv2_left.anim.PushBack({ 103, 224, 12, 17 });
	triple_shot_lv2_left.speed.y = -8;
	triple_shot_lv2_left.speed.x = -2;
	triple_shot_lv2_left.life = life_shots;


	//LVL 3 particles

	//Minigun
	minigun_shot_lv3.anim.PushBack({ 45, 128, 24, 24 });
	minigun_shot_lv3.speed.y = -8;
	minigun_shot_lv3.life = life_shots;
	

	// Triple shot particle
	triple_shot_lv3_center.anim.PushBack({ 133, 130, 14, 23 });
	triple_shot_lv3_center.speed.y = -8;
	triple_shot_lv3_center.life = life_shots;
	
	//Triple right
	triple_shot_lv3_right.anim.PushBack({ 155, 130, 17, 22 });
	triple_shot_lv3_right.speed.y = -8;
	triple_shot_lv3_right.speed.x = +2;
	triple_shot_lv3_right.life = life_shots;
	//Triple left
	triple_shot_lv3_left.anim.PushBack({ 108, 130, 17, 22 });
	triple_shot_lv3_left.speed.y = -8;
	triple_shot_lv3_left.speed.x = -2;
	triple_shot_lv3_left.life = life_shots;

	//Normal explosion
	normal_explosion.anim.PushBack({ 71, 537, 38, 38 });
	normal_explosion.anim.PushBack({ 124, 537, 39, 38 });
	normal_explosion.anim.PushBack({ 182, 534, 44, 43 });
	normal_explosion.anim.PushBack({ 245, 536, 39, 37 });
	normal_explosion.anim.PushBack({ 303, 539, 30, 36 });
	normal_explosion.anim.PushBack({ 352, 536, 24, 29 });
	normal_explosion.anim.PushBack({ 395, 536, 16, 19 });
	normal_explosion.anim.PushBack({ 436, 534, 9, 11 });
	normal_explosion.anim.loop = false;
	normal_explosion.anim.speed = 0.3f;
	

	//Player explosion
	player_explosion.anim.PushBack({ 127, 625, 16, 16 });
	player_explosion.anim.PushBack({ 228, 617, 32, 31 });
	player_explosion.anim.PushBack({ 313, 605, 64, 69 });
	player_explosion.anim.PushBack({ 68, 696, 86, 90 });
	player_explosion.anim.PushBack({ 185, 690, 117, 115 });
	player_explosion.anim.PushBack({ 320, 696, 113, 113 });
	player_explosion.anim.PushBack({ 48, 820, 112, 113 });
	player_explosion.anim.PushBack({ 118, 829, 114, 104 });
	player_explosion.anim.PushBack({ 328, 845, 113, 91 });
	player_explosion.anim.loop = false;
	player_explosion.anim.speed = 0.3f;
	

	//special bomb animation
	screen_bomb.anim.PushBack({ 47, 957, 240, 320 });
	screen_bomb.anim.PushBack({ 287, 957, 240, 320 });
	screen_bomb.anim.PushBack({ 527, 957, 240, 320 });
	screen_bomb.anim.PushBack({ 767, 957, 240, 320 });
	screen_bomb.anim.PushBack({ 1007, 957, 240, 320 });
	screen_bomb.anim.PushBack({ 47, 957, 240, 320 });
	screen_bomb.anim.PushBack({ 1247, 957, 240, 320 });
	screen_bomb.anim.PushBack({ 1487, 957, 240, 320 });
	screen_bomb.anim.PushBack({ 1527, 957, 240, 320 });
	screen_bomb.anim.PushBack({ 1767, 957, 240, 320 });
	screen_bomb.anim.PushBack({ 47, 957, 240, 320 });
	screen_bomb.anim.PushBack({ 2007, 957, 240, 320 });
	screen_bomb.anim.PushBack({ 2247, 957, 240, 320 });
	screen_bomb.anim.PushBack({ 2487, 957, 240, 320 });
	screen_bomb.anim.PushBack({ 2727, 957, 240, 320 });
	screen_bomb.anim.PushBack({ 47, 957, 240, 320 });
	screen_bomb.anim.PushBack({ 2967, 957, 240, 320 });
	screen_bomb.anim.PushBack({ 3207, 957, 240, 320 });
	screen_bomb.anim.PushBack({ 3447, 957, 240, 320 });
	screen_bomb.anim.PushBack({ 3687, 957, 240, 320 });
	screen_bomb.anim.PushBack({ 47, 957, 240, 320 });
	screen_bomb.anim.speed = 0.5f;
	
	//Player Falling
	player_fall.anim.PushBack({ 598, 56, 38, 38});
	player_fall.anim.PushBack({ 600, 104, 38, 38 });
	player_fall.anim.PushBack({ 602, 144, 38, 38 });
	player_fall.anim.PushBack({ 602, 184, 38, 38 });
	player_fall.anim.PushBack({ 602, 224, 38, 38 });
	player_fall.anim.speed = 0.1f;
//	player_fall.anim.loop = false;


	//Laser Turret
	right_laser_turret_light.anim.PushBack({ 569, 406, 16, 36 });
	right_laser_turret_light.anim.PushBack({ 549, 406, 16, 36 });
	right_laser_turret_light.anim.PushBack({ 569, 406, 16, 36 });
	right_laser_turret_light.anim.PushBack({ 549, 406, 16, 36 });
	right_laser_turret_light.anim.PushBack({ 569, 406, 16, 36 });
	right_laser_turret_light.anim.PushBack({ 549, 406, 16, 36 });
	right_laser_turret_light.anim.PushBack({ 569, 406, 16, 36 });
	right_laser_turret_light.anim.PushBack({ 549, 406, 16, 36 });
	right_laser_turret_light.anim.speed = 0.2f;
	right_laser_turret_light.anim.loop = false;

	right_laser_turret_shot.anim.PushBack({ 586, 337, 8, 8 });
	right_laser_turret_shot.speed.y = +2;
	right_laser_turret_shot.speed.x = -2;
	right_laser_turret_shot.life = 1000; //acts as an ID

	left_laser_turret_light.anim.PushBack({ 633, 425, 16, 36 });
	left_laser_turret_light.anim.PushBack({ 613, 425, 16, 36 });
	left_laser_turret_light.anim.PushBack({ 633, 425, 16, 36 });
	left_laser_turret_light.anim.PushBack({ 613, 425, 16, 36 });
	left_laser_turret_light.anim.PushBack({ 633, 425, 16, 36 });
	left_laser_turret_light.anim.PushBack({ 613, 425, 16, 36 });
	left_laser_turret_light.anim.PushBack({ 633, 425, 16, 36 });
	left_laser_turret_light.anim.PushBack({ 613, 425, 16, 36 });
	left_laser_turret_light.anim.speed = 0.1f;
	left_laser_turret_light.anim.loop = false;

	left_laser_turret_shot.anim.PushBack({ 569, 337, 8, 8 });
	left_laser_turret_shot.speed.y = +2;
	left_laser_turret_shot.speed.x = +2;
	left_laser_turret_shot.life = 1326;

	//Shield Tank
	left_Shield_Tank_Case.anim.PushBack({ 582, 541, 31, 48});
	left_Shield_Tank_Case.speed.y = -3;
	left_Shield_Tank_Case.speed.x = -2;
	left_Shield_Tank_Case.life = 500;

	right_Shield_Tank_Case.anim.PushBack({ 619, 541, 31, 48 });
	right_Shield_Tank_Case.speed.y = -3;
	right_Shield_Tank_Case.speed.x = +2;
	right_Shield_Tank_Case.life = 500;

	//Blue Shot
	blue_shot_left.anim.PushBack({ 587, 499, 8, 8 });
	blue_shot_left.speed.y = +2;
	blue_shot_left.speed.x = -2;
	blue_shot_left.life = 4000;
	
	blue_shot_center.anim.PushBack({ 611, 509, 6, 8 });
	blue_shot_center.speed.y = +2;
	blue_shot_center.life = 4000;

	blue_shot_right.anim.PushBack({ 632, 499, 8, 8 });
	blue_shot_right.speed.y = +2;
	blue_shot_right.speed.x = +2;
	blue_shot_right.life = 4000;

	shot_explosion.PushBack({49, 160, 16 , 12});

	triple_gun_shot_explosion.PushBack({ 121, 160, 38, 15 });

	//Boss particles
	boss_left_long_shot.anim.PushBack({ 569, 337, 8, 8 });
	boss_left_long_shot.speed.x--;
	boss_left_long_shot.speed.y++;
	boss_left_long_shot.life = 20000;

	awesome_shot.anim.PushBack({ 532, 590, 31, 31 });
	awesome_shot.anim.PushBack({ 568, 590, 31, 31 });
	awesome_shot.anim.PushBack({ 598, 590, 31, 31 });
	awesome_shot.anim.PushBack({ 636, 590, 31, 31 });
	awesome_shot.anim.PushBack({ 680, 590, 31, 31 });
	awesome_shot.anim.PushBack({ 724, 590, 31, 31 });
	awesome_shot.anim.PushBack({ 636, 590, 31, 31 });
	awesome_shot.anim.PushBack({ 680, 590, 31, 31 });
	awesome_shot.anim.PushBack({ 724, 590, 31, 31 });
	awesome_shot.anim.PushBack({ 636, 590, 31, 31 });
	awesome_shot.anim.PushBack({ 680, 590, 31, 31 });
	awesome_shot.anim.PushBack({ 724, 590, 31, 31 });
	awesome_shot.anim.speed = 0.2f;
	awesome_shot.speed.y = 3;
	awesome_shot.life = 9000;


	//Test bullet
	test.anim.PushBack({ 436, 536, 9, 8});
	test.life = 4000;
	test.speed = 4.5f;

}

ModuleParticles::~ModuleParticles()
{}

// Load assets
bool ModuleParticles::Start()
{
	LOG("Loading particles");
	particles_texture = App->textures->Load("Animation/particles.png");

	minigun_shot_lv1_up.fx = App->audios->LoadFX("Sounds/minigun_shot.ogg");
	triple_shot_lv1_center.fx = App->audios->LoadFX("Sounds/triple_shot.ogg");
	minigun_shot_lv2_up.fx = minigun_shot_lv1_up.fx;
	minigun_shot_lv3.fx = minigun_shot_lv1_up.fx;
	normal_explosion.fx = App->audios->LoadFX("Sounds/death_small_enemies.ogg");
	normal_explosion.fx = App->audios->LoadFX("Sounds/player_die.ogg");
	triple_shot_lv3_center.fx = triple_shot_lv1_center.fx;
	triple_shot_lv2_center.fx = triple_shot_lv1_center.fx;


	return true;
}

// Unload assets
bool ModuleParticles::CleanUp()
{
	LOG("Unloading particles");
	App->textures->Unload(particles_texture);

	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (active[i] != nullptr)
		{
			delete active[i];
			active[i] = nullptr;
		}
	}

	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (active_b[i] != nullptr)
		{
			delete active_b[i];
			active_b[i] = nullptr;
		}
	}

	return true;
}

// Update: draw background
update_status ModuleParticles::Update()
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		Particle* p = active[i];

		if (p == nullptr)
			continue;

		if (p->Update() == false)
		{
			delete p;
			active[i] = nullptr;
		}
		else if (SDL_GetTicks() >= p->born)
		{
			App->render->Blit(particles_texture, p->position.x, p->position.y, &(p->anim.GetCurrentFrame()));
			if (p->fx_played == false)
			{
				p->fx_played = true;
				App->audios->PlayFx(p->fx);
			}
		}
	}
	
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		Particle_Bullet* b = active_b[i];

		if (b == nullptr)
			continue;

		if (b->Update() == false)
		{
			delete b;
			active_b[i] = nullptr;
		}
		else if (SDL_GetTicks() >= b->born)
		{
			App->render->Blit(particles_texture, b->position.x, b->position.y, &(b->anim.GetCurrentFrame()));
			if (b->fx_played == false)
			{
				b->fx_played = true;
				App->audios->PlayFx(b->fx);
			}
		}
	}

	if (App->player->position.y < ((App->player->screenlowheight - SCREEN_HEIGHT) + App->player->screenlowheight) / 2){
		screen_bomb.speed.y = - SCREEN_SPEED;
	}
	else screen_bomb.speed.y = 0;

	return UPDATE_CONTINUE;
}

void ModuleParticles::AddParticle(const Particle& particle, int x, int y, COLLIDER_TYPE collider_type, Uint32 delay)
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (active[i] == nullptr)
		{
			Particle* p = new Particle(particle);
			p->born = SDL_GetTicks() + delay;
			p->position.x = x;
			p->position.y = y;
			if (collider_type != COLLIDER_NONE)
				p->collider = App->collision->AddCollider(p->anim.GetCurrentFrame(), collider_type, this);

			active[i] = p;
			break;
		}
	}
}

void ModuleParticles::AddParticle_Bullet_Enemy(const Particle_Bullet& particle, int x, int y, COLLIDER_TYPE collider_type, uint angle, Uint32 delay)
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (active_b[i] == nullptr)
		{
			Particle_Bullet* p = new Particle_Bullet(particle);
			p->born = SDL_GetTicks() + delay;
			p->position.x = x;
			p->position.y = y;
			p->angle = angle;
			
			if (collider_type != COLLIDER_NONE)
				p->collider = App->collision->AddCollider(p->anim.GetCurrentFrame(), collider_type, this);

			active_b[i] = p;
			break;
		}
	}
}

void ModuleParticles::OnCollision(Collider* c1, Collider* c2)
{
	if (c2->type != COLLIDER_NONE)
	{
		for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
		{
			/*if (c1->type == COLLIDER_PLAYER_SHOT)
			{
				if (App->player->current_weapon == MINIGUN)
					AddParticle(shot_explosion, active[i]->position.x, active[i]->position.y);
			}*/
			// Always destroy particles that collide
			if (active[i] != nullptr && active[i]->collider == c1)
			{
				//AddParticle(explosion, active[i]->position.x, active[i]->position.y);
				delete active[i];
				active[i] = nullptr;
				break;
			}


		}

		for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
		{
			if (active_b[i] != nullptr && active_b[i]->collider == c1)
			{
				//AddParticle(explosion, active[i]->position.x, active[i]->position.y);
				delete active_b[i];
				active_b[i] = nullptr;
				break;
			}
		}
	}
}

//shot explosion;
void ModuleParticles::Shots_explosion(int x, int y)
{
	if (App->player->current_weapon == MINIGUN)
	App->render->Blit(particles_texture, x, y, &shot_explosion.GetCurrentFrame());
	else if (App->player->current_weapon == TRIPLE_GUN)
		App->render->Blit(particles_texture, x, y, &triple_gun_shot_explosion.GetCurrentFrame());
}


// Particle sruct methods-------------------------------------------------------------

Particle::Particle()
{
	position.SetToZero();
	speed.SetToZero();
}

Particle::~Particle()
{
	if (collider != nullptr)
		App->collision->EraseCollider(collider);
}

Particle::Particle(const Particle& p) :
anim(p.anim), position(p.position), speed(p.speed),
fx(p.fx), born(p.born), life(p.life)
{}

bool Particle::Update()
{
	bool ret = true;

	if (life > 0)
	{
		if ((SDL_GetTicks() - born) > life)
			ret = false;
	}
	else
		if (anim.Finished())
			ret = false;

	position.x += speed.x;
	position.y += speed.y;

	if (collider != nullptr)
		collider->SetPos(position.x, position.y);

	return ret;
}

Particle_Bullet::Particle_Bullet()
{
	position.SetToZero();
}

Particle_Bullet::~Particle_Bullet()
{
	if (collider != nullptr)
		App->collision->EraseCollider(collider);
}

Particle_Bullet::Particle_Bullet(const Particle_Bullet& p) :
anim(p.anim), position(p.position),player(p.player),
speed(p.speed),angle(p.angle),fx(p.fx), born(p.born), life(p.life)
{}

bool Particle_Bullet::Update()
{
	bool ret = true;

	if (life > 0)
	{
		if ((SDL_GetTicks() - born) > life)
			ret = false;
	}
	else
		if (anim.Finished())
			ret = false;

	position.x -= speed*(cos(angle*PI / 180));
	position.y -= speed*(sin(angle*PI / 180));

	if (collider != nullptr)
		collider->SetPos(position.x, position.y);

	return ret;
}