
#include "ModuleObjects.h"
#include "Object_Energy.h"

Energy::Energy(int x, int y) : Object(x, y)
{
	energy.PushBack({ 362, 463, 20, 19 });
	energy.PushBack({ 389, 463, 20, 19 });
	energy.speed = 0.1f;

	animation = &energy;

	collider = App->collision->AddCollider({ 0, 0, 18, 18 }, COLLIDER_TYPE::COLLIDER_ITEMS, (Module*)App->objects);
};

void Energy::pick()
{
	for (int i = 0; i < 30; i++)
	{
		if (App->ui->energy < MAX_N_ENERGY)
		{
			App->ui->energy++;
		}
	}
}