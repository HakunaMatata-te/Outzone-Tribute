
#include "ModuleObjects.h"
#include "Object_Box.h"

Box::Box(int x, int y) : Object(x,y)
{
	box.PushBack({ 316, 71, 28, 28 });

	animation = &box;

	collider = App->collision->AddCollider({ 0, 0, 24, 35 }, COLLIDER_TYPE::COLLIDER_BOX, (Module*)App->objects);
};

void Box::drop()
{
	if (SDL_GetTicks() % 3 == 0)
		App->objects->AddObject(POWER_UP, position.x + 2, position.y + 2);
	else if (SDL_GetTicks() % 3 == 1)
		App->objects->AddObject(SPECIAL, position.x + 2, position.y + 2);
	else App->objects->AddObject(WEAPON, position.x + 2, position.y + 2);
}

