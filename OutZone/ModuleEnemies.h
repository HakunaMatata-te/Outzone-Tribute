#ifndef __ModuleEnemies_H__
#define __ModuleEnemies_H__

#include "Module.h"

#define MAX_ENEMIES 200

//Type of enemies.h
#include "Enemy_Solider_Green.h"
#include "Enemy_Solider_Purple.h"
#include "Enemy_Right_Laser_Turret.h"
#include "Enemy_Left_Laser_Turret.h"
#include "Enemy_Shield_Tank.h"
#include "Enemy_HMM.h"
#include "Enemy_Yellow_Infantery.h"
#include "Enemy_Red_Infantery.h"
#include "Enemy_Boss_LvL3.h"
#include "Enemy_Boss_LvL3_Files.h"
#include "Enemy_boss_lvl3_Eye.h"
#include "Enemy_Boss_lvl3_Left_laser.h"
#include "Enemy_Boss_LeftCable.h"
#include "Enemy_Boss_Left_Door.h"
#include "Enemy_Boss_lvl3_Right_laser.h"
#include "Enemy_Boss_Right_Door.h"
#include "Enemy_Boss_RightCable.h"
#include "Boss_L_Platform.h"
#include "Boss_R_Platform.h"


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
	RED_INFANTERY,
	BOSS_LVL3,
	BOSS_LVL3_EYE,
	BOSS_LVL3_L_LASER,
	BOSS_LVL3_L_CABLE,
	BOSS_LVL3_L_DOOR,
	BOSS_LVL3_R_LASER,
	BOSS_LVL3_R_CABLE,
	BOSS_LVL3_R_DOOR,
	BOSS_LVL3_FILES,
	BOSS_L_PLAT,
	BOSS_R_PLAT
};

class Enemy;

struct EnemyInfo
{
	bool boss_enemy;
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
	bool AddEnemy(ENEMY_TYPES type, int x, int y, uint typemove, bool boss_type);

private:

	void SpawnEnemy(const EnemyInfo& info);

private:
	EnemyInfo queue[MAX_ENEMIES];
	SDL_Texture* sprites;

public:
	Enemy* enemies[MAX_ENEMIES];

};

#endif // __ModuleEnemies_H__