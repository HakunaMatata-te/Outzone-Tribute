#include "Application.h"
#include "ModuleLevel_3.h"
#include "Enemy_Boss_LeftCable.h"
#include "ModuleCollider.h"
#include "ModuleEnemies.h"

#include "SDL\include\SDL.h"

Enemy_Boss_LCable::Enemy_Boss_LCable(int x, int y, uint typemove, ENEMY_TYPES type) : Enemy(x, y, typemove, type)
{
	idle.PushBack({641, 702, 11, 45});
	animation = &idle;
	Timer_state = true;
	collider = App->collision->AddCollider({ 0, 0, 11, 45 }, COLLIDER_NONE, (Module*)App->enemies);
	life = 10;
	stage = START;
}


void Enemy_Boss_LCable::Move(){
	if (Timer_state)
		Timer = SDL_GetTicks();

	if (App->level_3->boss_start){
		Timer_state = false;

		if (stage == LMOVEMENT::START){ //Using start as a delay to avoid using a secondary timer (doesn't stand for the same START as the one from the laser machine)
			if (SDL_GetTicks() - Timer > 1000){
				stage = LMOVEMENT::TURN_RIGHT;
				Timer = SDL_GetTicks();
			}
		}

		if (stage == LMOVEMENT::TURN_RIGHT){ // Same as start
			position.y += 2;
			if (SDL_GetTicks() - Timer > 600){
				stage = LMOVEMENT::LASER_CREATION;
				Timer = SDL_GetTicks();
			}
		}

		if (stage == LMOVEMENT::LASER_CREATION){
			if (SDL_GetTicks() - Timer > 1700){
				stage = LMOVEMENT::LASER_MOVE;
				Timer = SDL_GetTicks();
			}
		}

		if (stage == LMOVEMENT::LASER_MOVE){
			position.y +=2;
			if (SDL_GetTicks() - Timer > 1420){
				stage = LMOVEMENT::TURN_IDLE;
				Timer = SDL_GetTicks();
			}
		}

		if (stage == LMOVEMENT::TURN_IDLE){
			if (SDL_GetTicks() - Timer > 150){
				stage = LMOVEMENT::RETREAT;
				Timer = SDL_GetTicks();
			}
		}

		if (stage == LMOVEMENT::RETREAT){
			position.y -= 4;
		}
	}
	
	

}


void Enemy_Boss_LCable::death(){

}