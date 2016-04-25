#include "Application.h"
#include "ModuleEnemies.h"
#include "Enemy_Truck.h"
#include "ModuleCollider.h"



Enemy_Truck::Enemy_Truck(int x, int y) : Enemy(x, y)
{
	move.PushBack({ 19, 317, 80, 124 });
	move.PushBack({ 113, 318, 80, 123 });
	move.PushBack({ 212, 318, 80, 124 });
	move.PushBack({ 311, 318, 80, 125 });
	move.speed = 0.1f;

	animation = &move;

	collider = App->collision->AddCollider({ 0, 0, 80, 125 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	count_add = 0;
	count_max_spawn = 0;
	stop = false;
}

void Enemy_Truck::Move()
{
	animation_count = animation->GetCurrentFrame();

	if (animation_count.x == 19 && count_add == 10 && count_max_spawn < 5)
	{
		App->enemies->AddEnemy(FOOT_SOLIDER_GREEN, position.x + 20, position.y - 5);
		count_add = 0;
		++count_max_spawn;
	}

	if (animation_count.x == 311)
	{
		++count_add;
	}

	if (count_max_spawn == 5)
	{
		stop = true;
		move.loop = false;
	}

	if (stop == false)
		position.y += 1;
}
