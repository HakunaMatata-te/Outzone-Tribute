#include "Application.h"
#include "Boss_R_Platform.h"
#include "ModuleCollider.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleLevel_3.h"

#include "SDL\include\SDL.h"

Boss_RPlat::Boss_RPlat(int x, int y, uint typemove, ENEMY_TYPES type, bool boss) : Enemy(x, y, typemove, type, boss)
{
	idle.PushBack({ 791, 900, 204, 102 });

	animation = &idle;

	collider = App->collision->AddCollider({ 0, 0, 240, 103 }, COLLIDER_TYPE::COLLIDER_NONE, (Module*)App->enemies);

	life = 30000;
	Timer_state = true;
}

void Boss_RPlat::Move()
{
	if (Timer_state)
		Timer = SDL_GetTicks();
	
	if (App->level_3->boss_start){
		Timer_state = false;
		if (SDL_GetTicks() - Timer > 5000){
			position.y += 0.5f;
		}
	}

}


void Boss_RPlat::death()
{

}