#include "Application.h"
#include "Enemy_Minor_Turret.h"
#include "ModuleCollider.h"


Enemy_Minor_Turret::Enemy_Minor_Turret(int x, int y) : Enemy(x, y)
{
	move.PushBack({ 435, 387, 29, 45 });
	move.speed = 0.0f;

	deathanim.PushBack({795,365,31,31});
	deathanim.loop = false;

	animation = &move;

	collider = App->collision->AddCollider({ 0, 0, 27, 31 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	death = true;

}

void Enemy_Minor_Turret::Move()
{
}


void Enemy_Minor_Turret::ChangeDeath()
{
	animation = &deathanim;
	collider->type = COLLIDER_NONE;
}