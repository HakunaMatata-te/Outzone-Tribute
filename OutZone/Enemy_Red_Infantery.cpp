#include "Application.h"
#include "Enemy_Red_Infantery.h"
#include "ModuleCollider.h"
#include "ModuleParticles.h"

#include "SDL\include\SDL.h"


Enemy_Red_Infantery::Enemy_Red_Infantery(int x, int y, uint typemove, ENEMY_TYPES type, bool boss) : Enemy(x, y, typemove, type, boss)
{
	Idle_1.PushBack({ 135, 477, 25, 32 });
	Idle_2.PushBack({ 191, 472, 29, 30 });
	Idle_3.PushBack({ 21, 597, 24, 31 });
	Idle_4.PushBack({ 290, 517, 23, 31 });
	Idle_5.PushBack({ 137, 517, 23, 32 });
	Idle_6.PushBack({ 188, 603, 27, 32 });
	Idle_7.PushBack({ 134, 557, 29, 31 });
	Idle_8.PushBack({ 188, 560, 25, 31 });

	life = 1;
	animation = &Idle_5;

	collider = App->collision->AddCollider({ 0, 0, 23, 32 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

}

void Enemy_Red_Infantery::death(){
	App->particles->AddParticle(App->particles->normal_explosion, position.x, position.y, COLLIDER_NONE);
	App->ui->personal_score += 3000;
}

void Enemy_Red_Infantery::Move()
{
	SDL_Rect anim = animation->GetCurrentFrame();
	float angle;
	pos_idle = SeePlayer(SDL_Rect{position.x,position.y,anim.w,anim.h }, angle);

	if (pos_idle == 1 || pos_idle == 2)
		animation = &Idle_1;
	else if (pos_idle == 3 || pos_idle == 4)
		animation = &Idle_2;
	else if (pos_idle == 5 || pos_idle == 6)
		animation = &Idle_3;
	else if (pos_idle == 7 || pos_idle == 8)
		animation = &Idle_4;
	else if (pos_idle == 9 || pos_idle == 10)
		animation = &Idle_5;
	else if (pos_idle == 11 || pos_idle == 12)
		animation = &Idle_6;
	else if (pos_idle == 13 || pos_idle == 14)
		animation = &Idle_7;
	else if (pos_idle == 15 || pos_idle == 16)
		animation = &Idle_8;

	if (SDL_GetTicks() - lastShot > 2000)
	{
		if (SDL_GetTicks() - lasttimelapseShot > 50)
		{
			App->particles->AddParticle_Bullet_Enemy(App->particles->test, position.x + (anim.w / 2), position.y + (anim.h / 2), COLLIDER_ENEMY_SHOT, angle);
			lasttimelapseShot = SDL_GetTicks();
		}
		lastShot = SDL_GetTicks();
	}
}
