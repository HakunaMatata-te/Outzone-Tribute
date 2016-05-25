#include "Application.h"
#include "Enemy_Boss_LvL3.h"
#include "ModuleCollider.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"

#include "SDL\include\SDL.h"

Enemy_Boss_LvL3::Enemy_Boss_LvL3(int x, int y, uint typemove) : Enemy(x, y, typemove)
{
	Structure.PushBack({ 339, 655, 240, 103 });

	animation = &Structure;

	collider = App->collision->AddCollider({ 0, 0, 240, 103 }, COLLIDER_TYPE::COLLIDER_NONE, (Module*)App->enemies);

	life = 30000;
	
}

void Enemy_Boss_LvL3::death()
{
	App->particles->AddParticle(App->particles->normal_explosion, position.x, position.y, COLLIDER_NONE);
	App->ui->personal_score += 3000;
	App->player->win = true;
}

void Enemy_Boss_LvL3::Move()
{
}
