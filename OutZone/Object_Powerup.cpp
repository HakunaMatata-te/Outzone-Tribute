#include "Application.h"
#include "ModuleCollider.h"
#include "ModuleParticles.h"
#include "ModuleObjects.h"
#include "Object_Powerup.h"

#include "SDL\include\SDL.h"

Powerup::Powerup(int x, int y) : Object(x, y)
{
	powerup.PushBack({ 363, 398, 19, 19 });

	animation = &powerup;

	collider = App->collision->AddCollider({ 0, 0, 18, 18 }, COLLIDER_TYPE::COLLIDER_ITEMS, (Module*)App->objects);
};