#include "Application.h"
#include "Enemy_Solider_Purple.h"
#include "ModuleCollider.h"
#include "ModuleParticles.h"

#include "SDL\include\SDL.h"


Enemy_Solider_Purple::Enemy_Solider_Purple(int x, int y, uint typemove) : Enemy(x, y, typemove)
{
	Idle_1.PushBack({ 272, 667, 28, 35 });
	Idle_2.PushBack({ 276, 705, 28, 36 });
	Idle_3.PushBack({ 244, 706, 25, 35 });
	Idle_4.PushBack({ 215, 706, 22, 36 });
	Idle_5.PushBack({ 182, 707, 24, 35 });
	Idle_6.PushBack({ 145, 706, 26, 35 });
	Idle_7.PushBack({ 111, 706, 27, 35 });
	Idle_8.PushBack({ 75, 707, 29, 34 });
	Idle_9.PushBack({ 40, 707, 28, 35 });
	Idle_10.PushBack({ 40, 665, 27, 35 });
	Idle_11.PushBack({ 75, 665, 27, 36 });
	Idle_12.PushBack({ 110, 666, 26, 35 });
	Idle_13.PushBack({ 144, 668, 23, 33 });
	Idle_14.PushBack({ 179, 668, 24, 35 });
	Idle_15.PushBack({ 210, 667, 27, 35 });
	Idle_16.PushBack({ 243, 668, 26, 35 });


	animation = &Idle_9;

	collider = App->collision->AddCollider({ 0, 0, 27, 31 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

}

void Enemy_Solider_Purple::death(){
	App->particles->AddParticle(App->particles->normal_explosion, position.x, position.y, COLLIDER_NONE);
	App->ui->personal_score += 3000;
}

void Enemy_Solider_Purple::Move()
{
	SDL_Rect anim = animation->GetCurrentFrame();

	pos_idle = SeePlayer(SDL_Rect{position.x,position.y,anim.w,anim.h });

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
