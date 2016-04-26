#include "Application.h"
#include "Enemy_Solider_Red.h"
#include "ModuleCollider.h"


Enemy_Solider_Red::Enemy_Solider_Red(int x, int y) : Enemy(x, y)
{
	move.PushBack({ 474, 254, 27, 31 });
	move.speed = 0.0f;

	animation = &move;

	collider = App->collision->AddCollider({ 0, 0, 27, 31 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

}

void Enemy_Solider_Red::Move()
{

}
