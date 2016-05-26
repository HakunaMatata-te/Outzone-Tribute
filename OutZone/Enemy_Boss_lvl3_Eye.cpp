#include "Application.h"
#include "Enemy_boss_lvl3_Eye.h"
#include "ModuleCollider.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"

#include "SDL\include\SDL.h"


Enemy_Boss_Eye::Enemy_Boss_Eye(int x, int y, uint typemove, ENEMY_TYPES type) : Enemy(x, y, typemove, type)
{
	
	closed.PushBack({589, 655, 20, 31});
	animation = &closed;

	opened.PushBack({ 869, 655, 20, 31 });

	opening.PushBack({ 618, 655, 20, 31});
	opening.PushBack({ 655, 655, 20, 31 });
	opening.PushBack({ 692, 655, 20, 31 });
	opening.PushBack({ 727, 655, 20, 31 });
	opening.PushBack({ 764, 655, 20, 31 });
	opening.PushBack({ 799, 655, 20, 31 });
	opening.PushBack({ 834, 655, 20, 31 });
	opening.PushBack({ 869, 655, 20, 31 });
	opening.speed = 0.15f;


	closing.PushBack({ 869, 655, 20, 31 });
	closing.PushBack({ 834, 655, 20, 31 });
	closing.PushBack({ 799, 655, 20, 31 });
	closing.PushBack({ 764, 655, 20, 31 });
	closing.PushBack({ 727, 655, 20, 31 });
	closing.PushBack({ 692, 655, 20, 31 });
	closing.PushBack({ 655, 655, 20, 31 });
	closing.PushBack({ 618, 655, 20, 31 });
	closing.speed = 0.15f;

	collider = App->collision->AddCollider({ 0, 0, 20, 31 }, COLLIDER_NONE, (Module*)App->enemies);
	Timer = SDL_GetTicks();
	shotTimer = SDL_GetTicks();
	life = 100;
}

void Enemy_Boss_Eye::death(){
	for (uint i = 0; i < MAX_ENEMIES; ++i){
		if (App->enemies->enemies[i] != nullptr){
			App->enemies->enemies[i]->life = 0;
		}
	}
};

void Enemy_Boss_Eye::Move(){

	if (stage == PROGRESS::CLOSE){
		if (SDL_GetTicks() - Timer > 3000){
			stage = OPENING;
			collider->type = COLLIDER_ENEMY;
			Timer = SDL_GetTicks();
			animation = &opening;
			opening.Reset();
		}
	}
	
	if (stage == OPENING){
		if (SDL_GetTicks() - Timer > 750){
			stage = OPEN;
			Timer = SDL_GetTicks();
			animation = &opened;
		}
	}

	if (stage == OPEN){
		if (SDL_GetTicks() - shotTimer > 501){
			App->particles->AddParticle(App->particles->awesome_shot, position.x, position.y, COLLIDER_ENEMY_SHOT);
			shotTimer = SDL_GetTicks();
		}


		if (SDL_GetTicks() - Timer > 1000){
			stage = CLOSING;
			Timer = SDL_GetTicks();
			animation = &closing;
			closing.Reset();
		}
	}

	if (stage == CLOSING){
		if (SDL_GetTicks() - Timer > 750){
			stage = CLOSE;
			collider->type = COLLIDER_NONE;
			Timer = SDL_GetTicks();
			animation = &closed;
		}
	}


};