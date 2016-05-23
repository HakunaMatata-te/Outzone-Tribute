#ifndef __ModuleEnemies_H__
#define __ModuleEnemies_H__

#include "Module.h"

#define MAX_ENEMIES 100

//Type of enemies.h
#include "Enemy_Solider_Green.h"
#include "Enemy_Solider_Purple.h"
#include "Enemy_Right_Laser_Turret.h"
#include "Enemy_Left_Laser_Turret.h"
#include "Enemy_Shield_Tank.h"
#include "Enemy_HMM.h"
#include "Enemy_Yellow_Infantery.h"
#include "Enemy_Red_Infantery.h"

enum ENEMY_TYPES
{
	NO_TYPE,
	FOOT_SOLIDER_GREEN,
	FOOT_SOLIDER_PURPLE,
	RIGHT_LASER_TURRET,
	LEFT_LASER_TURRET,
	SHIELD_TANK,
	HORITZONTAL_MOVING_MACHINE,
	YELLOW_INFANTERY,
	RED_INFANTERY
};

class Enemy;

struct EnemyInfo
{
	ENEMY_TYPES type = ENEMY_TYPES::NO_TYPE;
	int x, y;
	uint typemove = 0;
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

	bool AddEnemy(ENEMY_TYPES type, int x, int y, uint typemove = 0);

private:

	void SpawnEnemy(const EnemyInfo& info);

private:

	EnemyInfo queue[MAX_ENEMIES];
	Enemy* enemies[MAX_ENEMIES];
	SDL_Texture* sprites;
};

#endif // __ModuleEnemies_H__