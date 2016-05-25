#include "Application.h"
#include "Enemy_Left_Laser_Turret.h"
#include "ModuleCollider.h"
#include "ModuleParticles.h"

#include "SDL\include\SDL.h"


Enemy_Left_Laser_Turret::Enemy_Left_Laser_Turret(int x, int y, uint typemove) : Enemy(x, y, typemove)
{

	move.PushBack({ 0, 0, 0, 0 });
	collider = App->collision->AddCollider({ 0, 0, 16, 36 }, COLLIDER_TYPE::COLLIDER_NONE, (Module*)App->enemies);
	animation = &move;
	life = 1000;
}

void Enemy_Left_Laser_Turret::death(){
}

void Enemy_Left_Laser_Turret::Move()
{
	if (SDL_GetTicks() - lastShot > 4500)
	{
		
		App->particles->AddParticle(App->particles->left_laser_turret_light, position.x, position.y, COLLIDER_NONE);
		
		//App->particles->AddParticle(App->particles->right_laser_turret_shot, position.x + 2, position.y + 17, COLLIDER_ENEMY_SHOT);
		
		lastShot = SDL_GetTicks();
	}
}
