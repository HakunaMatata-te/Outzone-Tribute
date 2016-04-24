#include "Application.h"
#include "Enemy_Solider_Green.h"
#include "ModuleCollider.h"


Enemy_Solider_Green::Enemy_Solider_Green(int x, int y) : Enemy(x, y)
{
	move.PushBack({ 133, 255, 27, 31 });
	move.speed = 0.0f;

	animation = &move;

	collider = App->collision->AddCollider({ 0, 0, 27, 31 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

}

void Enemy_Solider_Green::Move()
{

}