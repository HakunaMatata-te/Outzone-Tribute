#include "Application.h"
#include "Enemy_boss_lvl3_Eye.h"
#include "ModuleCollider.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"

#include "SDL\include\SDL.h"


Enemy_Boss_Eye::Enemy_Boss_Eye(int x, int y, uint typemove) : Enemy(x, y, typemove)
{
	open = false;
	closed.PushBack({589, 655, 20, 31});
	animation = &closed;

	shoot.PushBack({619, 655, 20, 31});

	collider = App->collision->AddCollider({ 0, 0, 20, 31 }, COLLIDER_NONE, (Module*)App->enemies);
	closeTimer = SDL_GetTicks();
	openTimer = SDL_GetTicks();
	life = 100;
}

void Enemy_Boss_Eye::death(){};

void Enemy_Boss_Eye::Move(){

	if (!open){
		if (SDL_GetTicks() - closeTimer > 3000){
			open = true;
			collider->type = COLLIDER_ENEMY;
			openTimer = SDL_GetTicks();
			animation = &shoot;
		}
	}
	
	if (open){
		if (SDL_GetTicks() - openTimer > 3000){
			open = false;
			collider->type = COLLIDER_NONE;
			closeTimer = SDL_GetTicks();
			animation = &closed;
		}
	}

};