#include "Application.h"
#include "ModuleLevel_3.h"
#include "Enemy_Boss_lvl3_Right_laser.h"
#include "ModuleCollider.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"

#include "SDL\include\SDL.h"

Enemy_Boss_R_Laser::Enemy_Boss_R_Laser(int x, int y, uint typemove, ENEMY_TYPES type) : Enemy(x, y, typemove, type)
{
	idle.PushBack({ 731, 709, 30, 40 });
	animation = &idle;

	shooting.PushBack({ 789, 711, 30, 35 });

	turn_left.PushBack({ 755, 709, 30, 37 });
	turn_left.PushBack({ 789, 711, 30, 35 });
	turn_left.speed = 0.07f;


	turn_idle.PushBack({ 755, 709, 30, 37 });
	turn_idle.PushBack({ 731, 709, 30, 40 });
	turn_idle.speed = 0.07f;

	life = 10000;
	collider = App->collision->AddCollider({ 0, 0, 16, 40 }, COLLIDER_ENEMY, (Module*)App->enemies);
	Timer = SDL_GetTicks();
	stage = START;
	sTimer_state = true;
	Timer_state = true;
}


void Enemy_Boss_R_Laser::Move(){
	if (Timer_state)
		Timer = SDL_GetTicks();


	if (App->level_3->boss_start){
		Timer_state = false;
		if (stage == LMOVEMENT::START){
			if (SDL_GetTicks() - Timer > 5000){
				position.y += 2;
				if (sTimer_state){
					sTimer = SDL_GetTicks();
					sTimer_state = false;
				}

				if (SDL_GetTicks() - sTimer > 600){
					stage = LMOVEMENT::TURN_RIGHT;
					animation = &turn_left;
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
				App->particles->AddParticle(App->particles->right_laser_turret_shot, position.x, position.y + 29, COLLIDER_ENEMY_SHOT);
				sTimer = SDL_GetTicks();
			}
			if (SDL_GetTicks() - Timer > 1000){
				Timer = SDL_GetTicks();
				stage = LASER_MOVE;
			}
		}

		if (stage == LMOVEMENT::LASER_MOVE){
			for (uint i = 0; i < MAX_ACTIVE_PARTICLES; i++){
				if (App->particles->active[i] != nullptr){
					if (App->particles->active[i]->life == 1325){ //only long shot particles should have this life.
						//replaces all particles for another ones that use the same sprite but have doferent movement
						App->particles->AddParticle(App->particles->boss_right_long_shot, App->particles->active[i]->position.x, App->particles->active[i]->position.y, COLLIDER_ENEMY_SHOT);

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

void Enemy_Boss_R_Laser::death(){

}