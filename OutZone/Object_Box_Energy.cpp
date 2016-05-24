
#include "ModuleObjects.h"
#include "Object_Box_Energy.h"

Energy_Box::Energy_Box(int x, int y) : Object(x, y)
{
	energy_box.PushBack({ 494, 185, 28, 31 });

	animation = &energy_box;

	collider = App->collision->AddCollider({ 0, 0, 33, 45 }, COLLIDER_TYPE::COLLIDER_BOX, (Module*)App->objects);
};

void Energy_Box::drop()
{
		App->objects->AddObject(ENERGY, position.x + 3, position.y + 3);
}

