#include "Application.h"
#include "Boss_L_Platform.h"
#include "ModuleCollider.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleLevel_3.h"

#include "SDL\include\SDL.h"

Boss_LPlat::Boss_LPlat(int x, int y, uint typemove, ENEMY_TYPES type, bool boss) : Enemy(x, y, typemove, type, boss)
{
	idle.PushBack({ 614, 841, 124, 164 });

	animation = &idle;

	collider = App->collision->AddCollider({ 0, 0, 240, 103 }, COLLIDER_TYPE::COLLIDER_NONE, (Module*)App->enemies);

	life = 30000;
	Timer_state = true;
}

void Boss_LPlat::Move()
{
	if (Timer_state)
		Timer = SDL_GetTicks();

	if (App->level_3->boss_start){
		Timer_state = false;
		if (SDL_GetTicks() - Timer > 14340){
			position.y += 0.5f;
		}
	}

}


void Boss_LPlat::death()
{

}

