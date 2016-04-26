#include "Application.h"
#include "Enemy_Solider_Green.h"
#include "ModuleCollider.h"
#include "ModuleParticles.h"

#include "SDL\include\SDL.h"


Enemy_Solider_Green::Enemy_Solider_Green(int x, int y) : Enemy(x, y)
{
	move.PushBack({ 133, 255, 27, 31 });
	move.speed = 0.0f;

	animation = &move;

	collider = App->collision->AddCollider({ 0, 0, 27, 31 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

}

void Enemy_Solider_Green::Move()
{

	if (SDL_GetTicks() - lastShot > 1000 && shot == true)
	{
		App->particles->AddParticle_Bullet_Enemy(App->particles->test, position.x, position.y, COLLIDER_ENEMY_SHOT);
		lastShot = SDL_GetTicks();
	}
}
