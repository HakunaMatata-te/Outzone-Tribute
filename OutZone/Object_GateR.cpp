
#include "ModuleObjects.h"
#include "Object_GateR.h"

GateR::GateR(int x, int y) : Object(x, y)
{

	gate_right.PushBack({ 587, 840, 57, 47 });

	animation = &gate_right;

	collider = App->collision->AddCollider({ 0, 0, 57, 55 }, COLLIDER_TYPE::COLLIDER_WALL, (Module*)App->objects);
};