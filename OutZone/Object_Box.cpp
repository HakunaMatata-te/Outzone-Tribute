
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
		
		App->objects->AddObject(WEAPON, position.x +5, position.y + 4);
}

