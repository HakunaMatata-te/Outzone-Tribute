#include "Application.h"
#include "Enemy_Boss_lvl3_Left_laser.h"
#include "ModuleCollider.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"

#include "SDL\include\SDL.h"

Enemy_Boss_L_Laser::Enemy_Boss_L_Laser(int x, int y, uint typemove) : Enemy(x, y, typemove)
{
	idle.PushBack({ 716, 708, 16, 40 });
	animation = &idle;
	
	shooting.PushBack({ 658, 710, 33, 35 });

	turn_right.PushBack({692, 708, 19, 37});
	turn_right.PushBack({ 658, 710, 33, 35 });
	turn_right.speed = 0.1f;

	turn_idle.PushBack({ 658, 710, 33, 35 });
	turn_idle.PushBack({ 692, 708, 19, 37 });
	turn_idle.speed = 0.1f;

	life = 10000;
	collider = App->collision->AddCollider({ 0, 0, 16, 40 }, COLLIDER_ENEMY, (Module*)App->enemies);
	Timer = SDL_GetTicks();
	stage = START;
	sTimer_state = true;
}


void Enemy_Boss_L_Laser::Move(){

	if (stage == LMOVEMENT::START){
		if (SDL_GetTicks() - Timer > 1000){
			position.y += 2;
			if (sTimer_state){
				sTimer = SDL_GetTicks();
				sTimer_state = false;
			}
	
			if (SDL_GetTicks() - sTimer > 600){
				stage = LMOVEMENT::TURN_RIGHT;
				animation = &turn_right;
				Timer = SDL_GetTicks();
			}
		}
	}

	if (stage == LMOVEMENT::TURN_RIGHT){
		if (SDL_GetTicks() - Timer > 100){
			stage = LASER_CREATION;
			animation = &shooting;
			Timer = SDL_GetTicks();
		}
	}

	if (stage == LASER_CREATION){
		if (SDL_GetTicks() - sTimer > 25){
			App->particles->AddParticle(App->particles->left_laser_turret_shot, position.x + 25, position.y + 29, COLLIDER_NONE);
			sTimer = SDL_GetTicks();
		}

	}

}

void Enemy_Boss_L_Laser::death(){

}