
#include "ModuleObjects.h"
#include "Object_Box.h"

Box::Box(int x, int y) : Object(x,y)
{
	box.PushBack({ 504, 138, 28, 28 });

	animation = &box;

	collider = App->collision->AddCollider({ -2, 0, 36, 39 }, COLLIDER_TYPE::COLLIDER_BOX, (Module*)App->objects);
};

void Box::drop()
{
		if (SDL_GetTicks() % 3 == 0)
			App->objects->AddObject(POWER_UP, position.x +1, position.y +1);
			else if (SDL_GetTicks() % 3 == 1)
			App->objects->AddObject(SPECIAL, position.x +5, position.y +5);
			else App->objects->AddObject(WEAPON, position.x +1, position.y + 1);
}

