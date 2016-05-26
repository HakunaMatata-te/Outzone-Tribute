#include "Application.h"
#include "ModuleLevel_3.h"
#include "Enemy_Boss_LeftCable.h"
#include "ModuleCollider.h"
#include "ModuleEnemies.h"

#include "SDL\include\SDL.h"

Enemy_Boss_LCable::Enemy_Boss_LCable(int x, int y, uint typemove) : Enemy(x, y, typemove)
{
	idle.PushBack({641, 702, 100, 45});
	animation = &idle;
	Timer_state = false;
	collider = App->collision->AddCollider({ 0, 0, 11, 45 }, COLLIDER_WALL, (Module*)App->enemies);
}


void Enemy_Boss_LCable::Move(){
	if (Timer_state)
		Timer = SDL_GetTicks();

	if (App->level_3->boss_start){
		Timer_state = false;


	}

}

void Enemy_Boss_LCable::death(){

}