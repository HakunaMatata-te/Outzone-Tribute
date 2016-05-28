#include "Application.h"
#include "Enemy_Right_Laser_Turret.h"
#include "ModuleCollider.h"
#include "ModuleParticles.h"

#include "SDL\include\SDL.h"


Enemy_Right_Laser_Turret::Enemy_Right_Laser_Turret(int x, int y, uint typemove, ENEMY_TYPES type, bool boss) : Enemy(x, y, typemove, type, boss)
{

	move.PushBack({ 0, 0, 0, 0 });
	collider = App->collision->AddCollider({ 0, 0, 16, 36 }, COLLIDER_TYPE::COLLIDER_NONE, (Module*)App->enemies);
	animation = &move;
	life = 10000;
}

void Enemy_Right_Laser_Turret::death(){
}

void Enemy_Right_Laser_Turret::Move()
{
	if (SDL_GetTicks() - shotDelay > 4500)
	{
		App->particles->AddParticle(App->particles->right_laser_turret_light, position.x, position.y, COLLIDER_NONE);
	
		shotDelay = SDL_GetTicks();
	}

	if ((SDL_GetTicks() - lastShot) > 25 && (SDL_GetTicks() - shotDelay) < 400){
		//shoot
		App->particles->AddParticle(App->particles->right_laser_turret_shot, position.x, position.y + 19, COLLIDER_ENEMY_SHOT);

		lastShot = SDL_GetTicks();
	}


}
