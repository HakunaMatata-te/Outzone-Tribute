#ifndef __ModuleEnemies_H__
#define __ModuleEnemies_H__

#include "Module.h"

#define MAX_ENEMIES 100

//Type of enemies.h
#include "Enemy_Solider_Green.h"
#include "Enemy_Solider_Red.h"
#include "Enemy_Truck.h"
#include "Enemy_Minor_Turret.h"


enum ENEMY_TYPES
{
	NO_TYPE,
	FOOT_SOLIDER_GREEN,
	FOOT_SOLIDER_RED,
	TRUCK,
	MINOR_TURRET,
	BIGGER_TURRET,
};

class Enemy;

struct EnemyInfo
{
	ENEMY_TYPES type = ENEMY_TYPES::NO_TYPE;
	int x, y;
};

class ModuleEnemies : public Module
{
public:

	ModuleEnemies();
	~ModuleEnemies();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

	bool AddEnemy(ENEMY_TYPES type, int x, int y);

	void ShotPlayer(int x, int y,int shot = 0);

private:

	void SpawnEnemy(const EnemyInfo& info);

private:

	EnemyInfo queue[MAX_ENEMIES];
	Enemy* enemies[MAX_ENEMIES];
	SDL_Texture* sprites;
};

#endif // __ModuleEnemies_H__