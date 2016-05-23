#include "Application.h"
#include "Enemy_Boss_LvL3_Files.h"
#include "ModuleCollider.h"
#include "ModuleParticles.h"

#include "SDL\include\SDL.h"


Enemy_Boss_LvL3_Files::Enemy_Boss_LvL3_Files(int x, int y, uint typemove) : Enemy(x, y, typemove)
{
	Idle.PushBack({ 339, 792, 28, 30 });
	Idle.PushBack({ 339, 827, 28, 30 });
	Idle.speed = 0.1f;

	animation = &Idle;

	collider = App->collision->AddCollider({ 0, 0, 27, 31 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

}

void Enemy_Boss_LvL3_Files::death(){
	App->particles->AddParticle(App->particles->normal_explosion, position.x, position.y, COLLIDER_NONE);
	App->ui->personal_score += 3000;
}

void Enemy_Boss_LvL3_Files::Move()
{
	if (SDL_GetTicks() - lastShot > 2000)
	{
		if (SDL_GetTicks() - lasttimelapseShot > 50)
		{
			App->particles->AddParticle_Bullet_Enemy(App->particles->test, position.x + 14, position.y + 15, COLLIDER_ENEMY_SHOT);
			lasttimelapseShot = SDL_GetTicks();
		}
		lastShot = SDL_GetTicks();
	}
}
