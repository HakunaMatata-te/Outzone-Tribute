
#include "ModuleObjects.h"
#include "Object_Box_Energy.h"

Energy_Box::Energy_Box(int x, int y) : Object(x, y)
{
	energy_box.PushBack({ 504, 195, 33, 30 });

	animation = &energy_box;

	collider = App->collision->AddCollider({ -2, 0, 33, 30 }, COLLIDER_TYPE::COLLIDER_BOX, (Module*)App->objects);
};

void Energy_Box::drop()
{
		App->objects->AddObject(ENERGY, position.x + 6, position.y + 6);
}

