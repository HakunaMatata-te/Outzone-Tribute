
#include "Object_SpecialBomb.h"

Bomb::Bomb(int x, int y) : Object(x, y)
{
	bomb.PushBack({ 363, 398, 19, 19 });
	bomb.PushBack({ 390, 398, 19, 19 });
	bomb.speed = 0.1f;

	animation = &bomb;

	collider = App->collision->AddCollider({ 0, 0, 18, 18 }, COLLIDER_TYPE::COLLIDER_ITEMS, (Module*)App->objects);
};

void Bomb::pick()
{
	if (App->player->spbombmunition < 10)
		App->player->spbombmunition++;
}