#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleEnemies.h"
#include "ModuleParticles.h"
#include "ModuleTextures.h"
#include "Enemy.h"
#include "ModuleCollider.h"
#include "ModulePlayer.h"
#include "ModuleObjects.h"



#define SPAWN_MARGIN 150  


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
		bool spawned = false;
		if(queue[i].type != ENEMY_TYPES::NO_TYPE)
		{

			for (uint j = 0; j < i; ++j)
			{
				if (queue[i].y == queue[j].y && queue[i].x == queue[j].x)
					spawned = true;
			}
			
			//Making boss always spawned to avoid graphical issues
			if (queue[i].boss_enemy){
				SpawnEnemy(queue[i]);
				queue[i].type = ENEMY_TYPES::NO_TYPE;
				LOG("Spawning boss enemy at %d", queue[i].y * SCREEN_SIZE);
			}

			
			if ((queue[i].y) * SCREEN_SIZE > -1 * (App->render->camera.y + SPAWN_MARGIN) && spawned == false && !queue[i].boss_enemy)
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

	for (uint i = 0; i < MAX_ENEMIES; ++i){
		//Needed for the boss cables to work
		if (enemies[i] != nullptr && (enemies[i]->type == ENEMY_TYPES::BOSS_LVL3_L_CABLE || enemies[i]->type == ENEMY_TYPES::BOSS_LVL3_R_CABLE || enemies[i]->type == ENEMY_TYPES::BOSS_L_PLAT || enemies[i]->type == ENEMY_TYPES::BOSS_R_PLAT))
			enemies[i]->Move();

		else if (enemies[i] != nullptr && enemies[i]->position.y + enemies[i]->GetCollider()->rect.h > App->player->screenlowheight - 300 && enemies[i]->position.y + (enemies[i]->GetCollider()->rect.h / 2) < App->player->screenlowheight && !(enemies[i]->type == ENEMY_TYPES::BOSS_LVL3_L_CABLE || enemies[i]->type == ENEMY_TYPES::BOSS_LVL3_R_CABLE))
			enemies[i]->Move();
	}

	for(uint i = 0; i < MAX_ENEMIES; ++i)
		if(enemies[i] != nullptr) 
			enemies[i]->Draw(sprites);

	return UPDATE_CONTINUE;
}

update_status ModuleEnemies::PostUpdate()
{
	// check camera position to decide what to despawn
	for(uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if(enemies[i] != nullptr)
		{ 

			enemies[i]->CollisionDown = false;
			enemies[i]->CollisionUp = false;
			enemies[i]->CollisionRight = false;
			enemies[i]->CollisionLeft = false;

			if (enemies[i]->position.y * SCREEN_SIZE > -1*(App->render->camera.y - (App->render->camera.h * SCREEN_SIZE) - SPAWN_MARGIN)&&enemies[i]->boss_enemy == false)
			{
				LOG("DeSpawning enemy at %d", enemies[i]->position.y * SCREEN_SIZE);
				delete enemies[i];
				enemies[i] = nullptr;
			} 

			else if (enemies[i]->life <= 0){
				enemies[i]->droping();
				enemies[i]->death();
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

		if (queue[i].type != ENEMY_TYPES::NO_TYPE)
		{
			queue[i].type = ENEMY_TYPES::NO_TYPE;
		}
	}

	return true;
}

bool ModuleEnemies::AddEnemy(ENEMY_TYPES type, int x, int y, uint typemove)
{
	bool ret = false;

	for(uint i = 0; i < MAX_ENEMIES; ++i)
	{ 
		
			if (queue[i].type == ENEMY_TYPES::NO_TYPE)
			{
				queue[i].type = type;
				queue[i].x = x;
				queue[i].y = y;
				queue[i].typemove = typemove;
				queue[i].boss_enemy = false;
				ret = true;
				break;
			}
		
	}

	return ret;
}

//Add enemy to detect the boss enemies
bool ModuleEnemies::AddEnemy(ENEMY_TYPES type, int x, int y, uint typemove, bool boss_type)
{
	bool ret = false;

	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{

		if (queue[i].type == ENEMY_TYPES::NO_TYPE)
		{
			queue[i].type = type;
			queue[i].x = x;
			queue[i].y = y;
			queue[i].typemove = typemove;
			queue[i].boss_enemy = true;
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
	for (; enemies[i] != nullptr && i < MAX_ENEMIES; ++i);
	{
		if (i != MAX_ENEMIES)
		{
			switch (info.type)
			{
			case ENEMY_TYPES::FOOT_SOLIDER_GREEN:
				enemies[i] = new Enemy_Solider_Green(info.x, info.y, info.typemove, info.type, info.boss_enemy);
				break;
			case ENEMY_TYPES::FOOT_SOLIDER_PURPLE:
				enemies[i] = new Enemy_Solider_Purple(info.x, info.y, info.typemove, info.type, info.boss_enemy);
				break;
			case ENEMY_TYPES::RIGHT_LASER_TURRET:
				enemies[i] = new Enemy_Right_Laser_Turret(info.x, info.y, info.typemove, info.type, info.boss_enemy);
				break;
			case ENEMY_TYPES::LEFT_LASER_TURRET:
				enemies[i] = new Enemy_Left_Laser_Turret(info.x, info.y, info.typemove, info.type, info.boss_enemy);
				break;
			case ENEMY_TYPES::SHIELD_TANK:
				enemies[i] = new Enemy_Shield_Tank(info.x, info.y, info.typemove, info.type, info.boss_enemy);
				break;
			case ENEMY_TYPES::HORITZONTAL_MOVING_MACHINE:
				enemies[i] = new Enemy_HMM(info.x, info.y, info.typemove, info.type, info.boss_enemy);
				break;
			case ENEMY_TYPES::YELLOW_INFANTERY:
				enemies[i] = new Enemy_Yellow_Infantery(info.x, info.y, info.typemove, info.type, info.boss_enemy);
				break;
			case ENEMY_TYPES::RED_INFANTERY:
				enemies[i] = new Enemy_Red_Infantery(info.x, info.y, info.typemove, info.type, info.boss_enemy);
				break;
			case ENEMY_TYPES::BOSS_LVL3_FILES:
				enemies[i] = new Enemy_Boss_LvL3_Files(info.x, info.y, info.typemove, info.type, info.boss_enemy);
				break;
			case ENEMY_TYPES::BOSS_LVL3:
				enemies[i] = new Enemy_Boss_LvL3(info.x, info.y, info.typemove, info.type, info.boss_enemy);
				break;
			case ENEMY_TYPES::BOSS_LVL3_EYE:
				enemies[i] = new Enemy_Boss_Eye(info.x, info.y, info.typemove, info.type, info.boss_enemy);
				break;
			case ENEMY_TYPES::BOSS_LVL3_L_LASER:
				enemies[i] = new Enemy_Boss_L_Laser(info.x, info.y, info.typemove, info.type, info.boss_enemy);
				break;
			case ENEMY_TYPES::BOSS_LVL3_L_CABLE:
				enemies[i] = new Enemy_Boss_LCable(info.x, info.y, info.typemove, info.type, info.boss_enemy);
				break;
			case ENEMY_TYPES::BOSS_LVL3_L_DOOR:
				enemies[i] = new Enemy_Boss_LDoor(info.x, info.y, info.typemove, info.type, info.boss_enemy);
				break;
			case ENEMY_TYPES::BOSS_LVL3_R_LASER:
				enemies[i] = new Enemy_Boss_R_Laser(info.x, info.y, info.typemove, info.type, info.boss_enemy);
				break;
			case ENEMY_TYPES::BOSS_LVL3_R_CABLE:
				enemies[i] = new Enemy_Boss_RCable(info.x, info.y, info.typemove, info.type, info.boss_enemy);
				break;
			case ENEMY_TYPES::BOSS_LVL3_R_DOOR:
				enemies[i] = new Enemy_Boss_RDoor(info.x, info.y, info.typemove, info.type, info.boss_enemy);
				break;
			case ENEMY_TYPES::BOSS_L_PLAT:
				enemies[i] = new Boss_LPlat(info.x, info.y, info.typemove, info.type, info.boss_enemy);
				break;
			case ENEMY_TYPES::BOSS_R_PLAT:
				enemies[i] = new Boss_RPlat(info.x, info.y, info.typemove, info.type, info.boss_enemy);
				break;
			}
		}
	}
}

void ModuleEnemies::OnCollision(Collider* c1, Collider* c2)
{
	for(uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr && enemies[i]->GetCollider() == c1 && (c2->type == COLLIDER_PLAYER_SHOT || c2->type == COLLIDER_PLAYER || c2->type == COLLIDER_SCREEN_BOMB || c2->type == COLLIDER_HOLE || c2->type == COLLIDER_BOX || c2->type == COLLIDER_WALL))
		{
			if (enemies[i]->GetCollider() == c1 && c2->type == COLLIDER_PLAYER_SHOT){
				if (App->player->lvl == 1)
					enemies[i]->life--;
				if (App->player->lvl == 2)
					enemies[i]->life -= 2;
				if (App->player->lvl == 3)
					enemies[i]->life -= 3;
			}
			
			if (enemies[i]->GetCollider() == c1 && c2->type == COLLIDER_PLAYER){
				enemies[i]->life -= 3;
			}

			if (enemies[i]->GetCollider() == c1 && c2->type == COLLIDER_SCREEN_BOMB){
				enemies[i]->life --;
				//Don't add more, the bomb stays for a few seconds at screen doing 1 dmg per game tick, which makes adds up quite fast
			}

			if (enemies[i]->GetCollider() == c1 && (enemies[i]->type == FOOT_SOLIDER_GREEN || enemies[i]->type == SHIELD_TANK || enemies[i]->type == RED_INFANTERY || enemies[i]->type == YELLOW_INFANTERY) && (c2->type == COLLIDER_HOLE || c2->type == COLLIDER_BOX || c2->type == COLLIDER_WALL || c2->type == COLLIDER_ENEMY)){
				
				if (enemies[i]->CollisionUp == false)
					enemies[i]->CollisionUp = c1->CheckCollisionUp(c2->rect);
				if (enemies[i]->CollisionDown == false)
					enemies[i]->CollisionDown = c1->CheckCollisionDown(c2->rect);
				if (enemies[i]->CollisionRight == false)
					enemies[i]->CollisionRight = c1->CheckCollisionRight(c2->rect);
				if (enemies[i]->CollisionLeft == false)
					enemies[i]->CollisionLeft = c1->CheckCollisionLeft(c2->rect);
			}
			break;
		} 
		
	}
}