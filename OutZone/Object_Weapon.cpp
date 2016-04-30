#include "ModuleObjects.h"
#include "Object_SpecialBomb.h"


ChangeWeapon::ChangeWeapon(int x, int y) : Object(x, y)
{
	weapon.PushBack({ 363, 430, 19, 19 });
	weapon.PushBack({ 390, 430, 19, 19 });
	weapon.speed = 0.1f;

	animation = &weapon;

	collider = App->collision->AddCollider({ 0, 0, 18, 18 }, COLLIDER_TYPE::COLLIDER_ITEMS, (Module*)App->objects);
};

void ChangeWeapon::pick()
{
	if (App->player->current_weapon == MINIGUN)
		App->player->current_weapon = TRIPLE_GUN;
	else if (App->player->current_weapon == TRIPLE_GUN)
		App->player->current_weapon = MINIGUN;
}