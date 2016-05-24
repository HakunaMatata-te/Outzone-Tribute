
#include "ModuleObjects.h"
#include "Object_Box_Energy.h"

Energy_Box::Energy_Box(int x, int y) : Object(x, y)
{
	energy_box.PushBack({ 504, 195, 56, 48 });

	animation = &energy_box;

	collider = App->collision->AddCollider({ -2, 0, 44, 50 }, COLLIDER_TYPE::COLLIDER_BOX, (Module*)App->objects);
};

void Energy_Box::drop()
{
		App->objects->AddObject(ENERGY, position.x + 16, position.y + 16);
}

