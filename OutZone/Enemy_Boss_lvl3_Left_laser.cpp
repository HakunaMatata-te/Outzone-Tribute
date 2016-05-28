#include "Application.h"
#include "ModuleLevel_3.h"
#include "Enemy_Boss_lvl3_Left_laser.h"
#include "ModuleCollider.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"

#include "SDL\include\SDL.h"

Enemy_Boss_L_Laser::Enemy_Boss_L_Laser(int x, int y, uint typemove, ENEMY_TYPES type, bool boss) : Enemy(x, y, typemove, type, boss)
{
	idle.PushBack({ 716, 708, 16, 40 });
	animation = &idle;
	
	shooting.PushBack({ 658, 710, 33, 35 });

	turn_right.PushBack({692, 708, 19, 37});
	turn_right.PushBack({ 658, 710, 33, 35 });
	turn_right.speed = 0.1f;


	turn_idle.PushBack({ 692, 708, 19, 37 });
	turn_idle.PushBack({ 716, 706, 16, 40 });
	turn_idle.speed = 0.07f;

	life = 10000;
	collider = App->collision->AddCollider({ 0, 0, 16, 40 }, COLLIDER_ENEMY, (Module*)App->enemies);
	Timer = SDL_GetTicks();
	stage = START;
	sTimer_state = true;
	Timer_state = true;
}


void Enemy_Boss_L_Laser::Move(){
	if (Timer_state)
		Timer = SDL_GetTicks();
		

	if (App->level_3->boss_start){
		Timer_state = false;
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

		if (stage == LMOVEMENT::LASER_CREATION){
			if (SDL_GetTicks() - sTimer > 25){
				App->particles->AddParticle(App->particles->boss_left_shot_apear, position.x + 25, position.y + 29, COLLIDER_ENEMY_SHOT);
				sTimer = SDL_GetTicks();
			}
			if (SDL_GetTicks() - Timer > 1620){
				App->particles->AddParticle(App->particles->boss_left_sparkle, 226, App->collision->returny(416, App->level_3->background.h), COLLIDER_ENEMY_SHOT);
				Timer = SDL_GetTicks();
				stage = LASER_MOVE;
			}
		}

		if (stage == LMOVEMENT::LASER_MOVE){
			for (uint i = 0; i < MAX_ACTIVE_PARTICLES; i++){
				if (App->particles->active[i] != nullptr){
					if (App->particles->active[i]->life == 13026){ //only long shot particles should have this life.
						//replaces all particles for another ones that use the same sprite but have doferent movement
						App->particles->AddParticle(App->particles->boss_left_long_shot, App->particles->active[i]->position.x, App->particles->active[i]->position.y, COLLIDER_ENEMY_SHOT);

						delete App->particles->active[i];
						App->particles->active[i] = nullptr;
					}
				}
			}
			position.y += 2;
			if (SDL_GetTicks() - Timer > 1420){
				stage = LMOVEMENT::TURN_IDLE;
				Timer = SDL_GetTicks();
				animation = &turn_idle;
			}
		}

		if (stage == LMOVEMENT::TURN_IDLE){
			for (uint i = 0; i < MAX_ACTIVE_PARTICLES; i++){
				if (App->particles->active[i] != nullptr){
					if (App->particles->active[i]->life == 20021 || App->particles->active[i]->life == 20022){
						delete App->particles->active[i];
						App->particles->active[i] = nullptr;
					}
				}
			}
			if (SDL_GetTicks() - Timer > 100){
				stage = LMOVEMENT::RETREAT;
				animation = &idle;
				Timer = SDL_GetTicks();
			}
		}

		if (stage == RETREAT){
			position.y -= 4;
			if (SDL_GetTicks() - Timer > 1000){
				stage = FINISHED;
			}
		}


	}
}

void Enemy_Boss_L_Laser::death(){

}