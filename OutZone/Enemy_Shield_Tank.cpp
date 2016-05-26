#include "Application.h"
#include "Enemy_Shield_Tank.h"
#include "ModuleCollider.h"
#include "ModuleParticles.h"

#include "SDL\include\SDL.h"


Enemy_Shield_Tank::Enemy_Shield_Tank(int x, int y, uint typemove, ENEMY_TYPES type) : Enemy(x, y, typemove, type)
{
	Shield.PushBack({ 828, 67, 64, 56 });
	Shield.PushBack({ 760, 67, 64, 56 });
	Shield.speed = 0.05f;

	Nude.PushBack({ 828, 191, 61, 55 });
	Nude.PushBack({ 759, 191, 61, 55 });
	Nude.speed = 0.05f;

	animation = &Shield;

	collider = App->collision->AddCollider({ 0, 0, 64, 56 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	life = 13;
}

void Enemy_Shield_Tank::death(){
	App->particles->AddParticle(App->particles->normal_explosion, position.x, position.y, COLLIDER_NONE);
	App->ui->personal_score += 3000;
}

void Enemy_Shield_Tank::Move()
{
	SDL_Rect anim = animation->GetCurrentFrame();

	if (anim.x == 828 && nude == true)
	{
		if (SDL_GetTicks() - lastShot > 200)
		{
			App->particles->AddParticle(App->particles->blue_shot_left, position.x + (anim.w / 2) - 2, position.y + (anim.h / 2) + 4, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->blue_shot_center, position.x + (anim.w / 2) - 2, position.y + (anim.h / 2) + 4, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->blue_shot_right, position.x + (anim.w / 2) - 2, position.y + (anim.h / 2) + 4, COLLIDER_ENEMY_SHOT);
			lastShot = SDL_GetTicks();
		}
	}
	float angle = 270;
	if (anim.x == 828 && nude == false)
	{
		if (SDL_GetTicks() - lastShot > 1000)
		{

			if (SDL_GetTicks() - lasttimelapseShot > 50)
			{
				App->particles->AddParticle_Bullet_Enemy(App->particles->test, position.x + (anim.w / 2), position.y + (anim.h / 2), COLLIDER_ENEMY_SHOT, angle);
				lasttimelapseShot = SDL_GetTicks();
			}
				
			lastShot = SDL_GetTicks();
		}
	}
	

	if (life == 5 && nude == true)
	{
		App->particles->AddParticle(App->particles->normal_explosion, position.x + 64/4, position.y + 56/4, COLLIDER_NONE);
		App->particles->AddParticle(App->particles->left_Shield_Tank_Case, position.x, position.y, COLLIDER_NONE);
		App->particles->AddParticle(App->particles->right_Shield_Tank_Case, position.x + 32, position.y, COLLIDER_NONE);
		animation = &Nude;
		nude = false;
	}
}
