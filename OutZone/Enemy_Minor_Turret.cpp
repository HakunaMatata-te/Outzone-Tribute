#include "Application.h"
#include "Enemy_Minor_Turret.h"
#include "ModuleCollider.h"
#include "ModuleParticles.h"

#include "SDL\include\SDL.h"


Enemy_Minor_Turret::Enemy_Minor_Turret(int x, int y) : Enemy(x, y)
{
	deathanim.PushBack({795,365,31,31});
	deathanim.loop = false;

	Idle_1.PushBack({ 755, 328, 27, 47 });
	Idle_2.PushBack({ 755, 384, 26, 46 });
	Idle_3.PushBack({ 710, 385, 27, 45 });
	Idle_4.PushBack({ 665, 387, 27, 43 });
	Idle_5.PushBack({ 619, 387, 28, 43 });
	Idle_6.PushBack({ 574, 387, 27, 44 });
	Idle_7.PushBack({ 528, 387, 28, 44 });
	Idle_8.PushBack({ 482, 387, 28, 45 });
	Idle_9.PushBack({ 435, 387, 29, 45 });
	Idle_10.PushBack({ 438, 331, 27, 45 });
	Idle_11.PushBack({ 484, 332, 26, 44 });
	Idle_12.PushBack({ 527, 331, 29, 44 });
	Idle_13.PushBack({ 570, 332, 30, 43 });
	Idle_14.PushBack({ 619, 332, 28, 43 });
	Idle_15.PushBack({ 667, 330, 24, 45 });
	Idle_16.PushBack({ 712, 329, 24, 46 });

	animation = &Idle_9;

	collider = App->collision->AddCollider({ 0, 0, 27, 31 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	death = true;

}

void Enemy_Minor_Turret::Move()
{
	if (shot == true)
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
			App->particles->AddParticle_Bullet_Enemy(App->particles->test, position.x + (anim.w / 2), position.y + (anim.h / 2), COLLIDER_ENEMY_SHOT);
			lastShot = SDL_GetTicks();
		}
	}
}


void Enemy_Minor_Turret::ChangeDeath()
{
	shot = false;
	animation = &deathanim;
	collider->type = COLLIDER_NONE;
}