#include "Application.h"
#include "ModuleCollider.h"
#include "ModuleParticles.h"
#include "ModuleObjects.h"
#include "Object_Box.h"

#include "SDL\include\SDL.h"

Box::Box(int x, int y) : Object(x,y)
{
	box.PushBack({ 316, 71, 28, 28 });

	animation = &box;

	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_BOX, (Module*)App->objects);
};

void Box::drop()
{
	App->objects->AddObject(POWER_UP, position.x, position.y);
}

