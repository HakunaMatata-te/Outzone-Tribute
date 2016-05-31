
#include "Object_Powerup.h"

Powerup::Powerup(int x, int y) : Object(x, y)
{
	powerup.PushBack({ 363, 398, 19, 19 });
	powerup.PushBack({ 390, 398, 19, 19 });
	powerup.speed = 0.1f;

	animation = &powerup;

	collider = App->collision->AddCollider({ 0, 0, 20, 20 }, COLLIDER_TYPE::COLLIDER_ITEMS, (Module*)App->objects);
};

void Powerup::pick()
{
	if(App->player->lvl < 3)
		App->player->lvl++;
}