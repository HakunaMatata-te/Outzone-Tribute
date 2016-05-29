
#include "ModuleObjects.h"
#include "Object_GateL.h"

GateL::GateL(int x, int y) : Object(x, y)
{

	gate_left.PushBack({ 526, 840, 57, 47 });
	
	animation = &gate_left;

	collider = App->collision->AddCollider({ 0, 0, 57, 55 }, COLLIDER_TYPE::COLLIDER_WALL, (Module*)App->objects);
};
