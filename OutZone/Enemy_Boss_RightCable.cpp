#include "Application.h"
#include "ModuleLevel_3.h"
#include "Enemy_Boss_RightCable.h"
#include "ModuleCollider.h"
#include "ModuleEnemies.h"

#include "SDL\include\SDL.h"

Enemy_Boss_RCable::Enemy_Boss_RCable(int x, int y, uint typemove, ENEMY_TYPES type, bool boss) : Enemy(x, y, typemove, type, boss)
{
	idle.PushBack({ 860, 703, 11, 45 });
	animation = &idle;
	Timer_state = true;
	collider = App->collision->AddCollider({ 0, 0, 11, 45 }, COLLIDER_NONE, (Module*)App->enemies);
	life = 100;
	stage = START;
}


void Enemy_Boss_RCable::Move(){
	if (Timer_state)
		Timer = SDL_GetTicks();

	if (App->level_3->boss_start){
		Timer_state = false;

		if (stage == LMOVEMENT::START){ //Using start as a delay to avoid using a secondary timer (doesn't stand for the same START as the one from the laser machine)
			if (SDL_GetTicks() - Timer > 9900){
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
			if (SDL_GetTicks() - Timer > 1100){
				stage = LMOVEMENT::LASER_MOVE;
				Timer = SDL_GetTicks();
			}
		}

		if (stage == LMOVEMENT::LASER_MOVE){
			position.y += 1.25f;
			if (SDL_GetTicks() - Timer > 2300){
				stage = LMOVEMENT::TURN_IDLE;
				Timer = SDL_GetTicks();
			}
		}

		if (stage == LMOVEMENT::TURN_IDLE){
			if (SDL_GetTicks() - Timer > 175){
				stage = LMOVEMENT::RETREAT;
				Timer = SDL_GetTicks();
			}
		}

		if (stage == LMOVEMENT::RETREAT){
			position.y -= 4;
		}
	}



}


void Enemy_Boss_RCable::death(){

}