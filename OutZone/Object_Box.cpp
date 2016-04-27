#include "Application.h"
#include "ModuleCollider.h"
#include "ModuleParticles.h"
#include "Object_Box.h"

#include "SDL\include\SDL.h"

Box::Box(int x, int y) : Object(x,y)
{
	box.PushBack({ 316, 71, 28, 28 });

	collider = App->collision->AddCollider({ 0, 0, 28, 28 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
};