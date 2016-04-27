#include "Application.h"
#include "ModuleEnemies.h"
#include "Enemy_First_Boss.h"
#include "ModuleCollider.h"
#include "ModuleFadeToBlack.h"

First_Boss::First_Boss(int x, int y) : Enemy(x, y)
{
	move.PushBack({ 19, 317, 80, 124 });

	animation = &move;

	collider = App->collision->AddCollider({ 0, 0, 80, 125 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	death = true;
}

void First_Boss::ChangeDeath()
{
	App->fade->FadeToBlack((Module*)App->level_1, (Module*)App->end);
}