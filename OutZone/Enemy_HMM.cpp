#include "Application.h"
#include "Enemy_HMM.h"
#include "ModuleCollider.h"
#include "ModuleParticles.h"

#include "SDL\include\SDL.h"

Enemy_HMM::Enemy_HMM(int x, int y, uint typemove) : Enemy(x, y, typemove)
{
	Horitzontal.PushBack({ 757, 535, 50, 38 });
	Horitzontal.PushBack({ 808, 535, 52, 38 });
	Horitzontal.PushBack({ 866, 536, 54, 38 });
	Horitzontal.speed = 0.1f;

	animation = &Horitzontal;

	collider = App->collision->AddCollider({ 0, 0, 64, 56 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	life = 5;
	
}

void Enemy_HMM::death(){
	App->particles->AddParticle(App->particles->normal_explosion, position.x, position.y, COLLIDER_NONE);
	App->ui->personal_score += 3000;
}

void Enemy_HMM::Move()
{
	SDL_Rect anim = animation->GetCurrentFrame();

	if (anim.x == 866)
	{
		if (SDL_GetTicks() - lastShot > 200)
		{
			App->particles->AddParticle(App->particles->blue_shot_center, position.x + 8, position.y + 15, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->blue_shot_center, position.x + 41, position.y + 15, COLLIDER_ENEMY_SHOT);

			lastShot = SDL_GetTicks();
		}
	}
	if (typemove == 1)
	{
		if (position.x >= 190)
		{
			right = false;
			left = true;
		}
		if (position.x <= 0)
		{
			right = true;
			left = false;
		}

		if (right == true)
			position.x += 2;
		if (left == true)
			position.x -= 2;
	}

	if (typemove == 2)
	{
		if (position.x >= 190)
		{
			right = false;
			left = true;
		}
		if (position.x <= 0)
		{
			right = true;
			left = false;
		}
		if (position.x >= 95 && right == true)
		{
			up = true;
			down = false;
		}
		if (position.x <= 208 && left == true)
		{
			down= true;
			up = false;
		}

		if (position.x <= 95 && left == true)
		{
			down = false;
			up = false;
		}

		if (up == true)
			position.y -= 1;
		if (down == true)
			position.y += 1;
		if (right == true)
			position.x += 2;
		if (left == true)
			position.x -= 2;
	}

}
