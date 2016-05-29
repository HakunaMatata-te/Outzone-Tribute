#include "Application.h"
#include "Enemy_Boss_LvL3.h"
#include "ModuleCollider.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleLevel_3.h"
#include "ModuleEnemies.h"


#include "SDL\include\SDL.h"

Enemy_Boss_LvL3::Enemy_Boss_LvL3(int x, int y, uint typemove, ENEMY_TYPES type, bool boss) : Enemy(x, y, typemove, type, boss)
{
	Structure.PushBack({ 339, 655, 240, 103 });

	animation = &Structure;

	collider = App->collision->AddCollider({ 0, 0, 240, 103 }, COLLIDER_TYPE::COLLIDER_NONE, (Module*)App->enemies);

	life = 30000;
	Timer_state = true;
}

void Enemy_Boss_LvL3::death()
{
	App->particles->AddParticle(App->particles->normal_explosion, position.x, position.y, COLLIDER_NONE);
	App->ui->personal_score += 3000;
	App->player->win = true;
}

void Enemy_Boss_LvL3::Move()
{
	if (Timer_state)
		Timer = SDL_GetTicks();

	if (App->level_3->boss_start){
		Timer_state = false;

		if (SDL_GetTicks() - Timer > 4000){
			App->enemies->AddEnemy(BOSS_LVL3_FILES, 120, App->collision->returny(250, App->level_3->background.h), 1);
			Timer = SDL_GetTicks();
		}

	}

}
