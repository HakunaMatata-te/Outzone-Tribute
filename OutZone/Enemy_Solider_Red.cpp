#include "Application.h"
#include "Enemy_Solider_Red.h"
#include "ModuleCollider.h"
#include "ModuleParticles.h"
#include "ModuleObjects.h"


#include "SDL\include\SDL.h"


Enemy_Solider_Red::Enemy_Solider_Red(int x, int y) : Enemy(x, y)
{
	Idle_1.PushBack({ 641, 20, 28, 35 });
	Idle_2.PushBack({ 643, 63, 28, 36 });
	Idle_3.PushBack({ 606, 63, 25, 35 });
	Idle_4.PushBack({ 572, 62, 22, 36 });
	Idle_5.PushBack({ 536, 62, 24, 35 });
	Idle_6.PushBack({ 475, 61, 26, 35 });
	Idle_7.PushBack({ 436, 61, 27, 35 });
	Idle_8.PushBack({ 395, 62, 29, 34 });
	Idle_9.PushBack({ 355, 62, 28, 35 });
	Idle_10.PushBack({ 356, 20, 27, 35 });
	Idle_11.PushBack({ 395, 18, 27, 36 });
	Idle_12.PushBack({ 436, 20, 26, 35 });
	Idle_13.PushBack({ 475, 22, 23, 33 });
	Idle_14.PushBack({ 532, 20, 24, 35 });
	Idle_15.PushBack({ 567, 20, 27, 35 });
	Idle_16.PushBack({ 605, 20, 26, 35 });


	animation = &Idle_9;

	collider = App->collision->AddCollider({ 0, 0, 27, 31 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

}

void Enemy_Solider_Red::Move()
{
	SDL_Rect anim = animation->GetCurrentFrame();

	pos_idle = SeePlayer(SDL_Rect{ position.x, position.y, anim.w, anim.h });

	if (pos_idle == 1)
		animation = &Idle_1;
	else if (pos_idle == 2)
		animation = &Idle_2;
	else if (pos_idle == 3)
		animation = &Idle_3;
	else if (pos_idle == 4)
		animation = &Idle_4;
	else if (pos_idle == 5)
		animation = &Idle_5;
	else if (pos_idle == 6)
		animation = &Idle_6;
	else if (pos_idle == 7)
		animation = &Idle_7;
	else if (pos_idle == 8)
		animation = &Idle_8;
	else if (pos_idle == 9)
		animation = &Idle_9;
	else if (pos_idle == 10)
		animation = &Idle_10;
	else if (pos_idle == 11)
		animation = &Idle_11;
	else if (pos_idle == 12)
		animation = &Idle_12;
	else if (pos_idle == 13)
		animation = &Idle_13;
	else if (pos_idle == 14)
		animation = &Idle_14;
	else if (pos_idle == 15)
		animation = &Idle_15;
	else if (pos_idle == 16)
		animation = &Idle_16;

	if (SDL_GetTicks() - lastShot > 2000)
	{
		if (SDL_GetTicks() - lasttimelapseShot > 50)
		{
			App->particles->AddParticle_Bullet_Enemy(App->particles->test, position.x + (anim.w / 2), position.y + (anim.h / 2), COLLIDER_ENEMY_SHOT);
			lasttimelapseShot = SDL_GetTicks();
		}
		lastShot = SDL_GetTicks();
	}
}

void Enemy_Solider_Red::droping()
{
	if (SDL_GetTicks() % 2 == 0)
	App->objects->AddObject(SPECIAL, position.x + 2, position.y + 2);
}