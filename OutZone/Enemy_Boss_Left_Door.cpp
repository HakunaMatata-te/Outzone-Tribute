#include "Application.h"
#include "ModuleLevel_3.h"
#include "ModuleCollider.h"
#include "ModuleEnemies.h"
#include "Enemy_Boss_Left_Door.h"

#include "SDL\include\SDL.h"

Enemy_Boss_LDoor::Enemy_Boss_LDoor(int x, int y, uint typemove, ENEMY_TYPES type) : Enemy(x, y, typemove, type)
{
	closed.PushBack({ 586, 701, 16, 12 });
	animation = &closed;

	opened.PushBack({ 590, 760, 16, 12 });

	opening.PushBack({ 611, 715, 16, 12 });
	opening.PushBack({ 611, 727, 16, 12 });
	opening.speed = 0.1f;

	closing.PushBack({ 611, 727, 16, 12 });
	closing.PushBack({ 611, 715, 16, 12 });
	closing.speed = 0.1f;

	Timer_state = true;
	collider = App->collision->AddCollider({ 0, 0, 11, 45 }, COLLIDER_NONE, (Module*)App->enemies);
	life = 10;
	stage = START;
}


void Enemy_Boss_LDoor::Move(){
	if (Timer_state)
		Timer = SDL_GetTicks();

	if (App->level_3->boss_start){
		Timer_state = false;
		if (stage == LMOVEMENT::START){
			if (SDL_GetTicks() - Timer > 820){
				animation = &opening;
			}
			if (SDL_GetTicks() - Timer > 1000){
				animation = &opened;
				stage = LMOVEMENT::RETREAT;
				Timer = SDL_GetTicks();
			}
		}

		if (stage == LMOVEMENT::RETREAT){
			if (SDL_GetTicks() - Timer > 4220){
				animation = &closing;
			}
			if (SDL_GetTicks() - Timer > 4400){
				animation = &closed;
				stage = LMOVEMENT::FINISHED;
			}
		}
		

		
	}



}


void Enemy_Boss_LDoor::death(){

}