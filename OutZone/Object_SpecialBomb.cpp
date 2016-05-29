
#include "Object_SpecialBomb.h"

Bomb::Bomb(int x, int y) : Object(x, y)
{
	bomb.PushBack({ 391, 488, 16, 21 });

	bomb.speed = 0.1f;

	animation = &bomb;

	collider = App->collision->AddCollider({ 0, 0, 16, 21 }, COLLIDER_TYPE::COLLIDER_ITEMS, (Module*)App->objects);
};

void Bomb::pick()
{
	if (App->player->spbombmunition < 10)
		App->player->spbombmunition++;
}