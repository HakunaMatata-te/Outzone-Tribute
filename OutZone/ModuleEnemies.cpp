#include <stdlib.h>
#include <time.h>

#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleEnemies.h"
#include "ModuleParticles.h"
#include "ModuleTextures.h"
#include "Enemy.h"
#include "ModuleCollider.h"
#include "ModulePlayer.h"

#define SPAWN_MARGIN 50

ModuleEnemies::ModuleEnemies()
{
	for(uint i = 0; i < MAX_ENEMIES; ++i)
		enemies[i] = nullptr;
}

// Destructor
ModuleEnemies::~ModuleEnemies()
{
}

bool ModuleEnemies::Start()
{
	// Create a prototype for each enemy available so we can copy them around
	sprites = App->textures->Load("Animation/sprites_enemies.png");

	return true;
}

update_status ModuleEnemies::PreUpdate()
{
	// check camera position to decide what to spawn
	for(uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if(queue[i].type != ENEMY_TYPES::NO_TYPE)
		{
			if(queue[i].y * SCREEN_SIZE < App->render->camera.y + SPAWN_MARGIN)
			{
				SpawnEnemy(queue[i]);
				queue[i].type = ENEMY_TYPES::NO_TYPE;
				LOG("Spawning enemy at %d", queue[i].y * SCREEN_SIZE);
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before render is available
update_status ModuleEnemies::Update()
{
	for(uint i = 0; i < MAX_ENEMIES; ++i)
		if(enemies[i] != nullptr) enemies[i]->Move();

	for(uint i = 0; i < MAX_ENEMIES; ++i)
		if(enemies[i] != nullptr) enemies[i]->Draw(sprites);

	return UPDATE_CONTINUE;
}

update_status ModuleEnemies::PostUpdate()
{
	// check camera position to decide what to spawn
	for(uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if(enemies[i] != nullptr)
		{
			if (enemies[i]->position.y * SCREEN_SIZE > (App->render->camera.y) + (App->render->camera.h * SCREEN_SIZE) + SPAWN_MARGIN)
			{
				LOG("DeSpawning enemy at %d", enemies[i]->position.y * SCREEN_SIZE);
				delete enemies[i];
				enemies[i] = nullptr;
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleEnemies::CleanUp()
{
	LOG("Freeing all enemies");

	App->textures->Unload(sprites);

	for(uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if(enemies[i] != nullptr)
		{
			delete enemies[i];
			enemies[i] = nullptr;
		}
	}

	return true;
}

bool ModuleEnemies::AddEnemy(ENEMY_TYPES type, int x, int y)
{
	bool ret = false;

	for(uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if(queue[i].type == ENEMY_TYPES::NO_TYPE)
		{
			queue[i].type = type;
			queue[i].x = x;
			queue[i].y = y;
			ret = true;
			break;
		}
	}

	return ret;
}

void ModuleEnemies::SpawnEnemy(const EnemyInfo& info)
{
	// find room for the new enemy
	uint i = 0;
	for(; enemies[i] != nullptr && i < MAX_ENEMIES; ++i);

	if(i != MAX_ENEMIES)
	{
		switch(info.type)
		{
		case ENEMY_TYPES::FOOT_SOLIDER_GREEN:
			enemies[i] = new Enemy_Solider_Green(info.x,info.y);
			break;
		case ENEMY_TYPES::FOOT_SOLIDER_RED:
			enemies[i] = new Enemy_Solider_Red(info.x, info.y);
			break;
		case ENEMY_TYPES::TRUCK:
			enemies[i] = new Enemy_Truck(info.x, info.y);
			break;
		case ENEMY_TYPES::MINOR_TURRET:
			enemies[i] = new Enemy_Minor_Turret(info.x, info.y);
			break;
		}
	}
}

void ModuleEnemies::OnCollision(Collider* c1, Collider* c2)
{
	for(uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr && enemies[i]->GetCollider() == c1 && (c2->type == COLLIDER_PLAYER_SHOT || c2->type == COLLIDER_PLAYER || c2->type == COLLIDER_SCREEN_BOMB) && enemies[i]->death == false)
		{
			App->particles->AddParticle(App->particles->normal_explosion, enemies[i]->position.x, enemies[i]->position.y, COLLIDER_NONE);
			delete enemies[i];
			enemies[i] = nullptr;
			break;
		} 
		else if (enemies[i] != nullptr && enemies[i]->GetCollider() == c1 && (c2->type == COLLIDER_PLAYER_SHOT || c2->type == COLLIDER_PLAYER || c2->type == COLLIDER_SCREEN_BOMB) && enemies[i]->death == true)
		{
			App->particles->AddParticle(App->particles->normal_explosion, enemies[i]->position.x, enemies[i]->position.y, COLLIDER_NONE);
			enemies[i]->ChangeDeath();
			break;
		}
	}
}

void ShotPlayer(int x, int y, int shot = 0)
{
	srand(time(NULL));

	//in the range: center player -  (center player + 50)
	int dir_x = rand() % 50 + ((App->player->width / 2) + App->player->position.x);

	int dir_y = rand() % 50 + ((App->player->height / 2) + App->player->position.y);

	App->particles->AddParticle(App->particles->minigun_shot_lv1_right, x, y, COLLIDER_ENEMY_SHOT);
}