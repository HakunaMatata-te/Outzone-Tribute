#ifndef __MODULE_OBJECTS_H__
#define __MODULE_OBJECTS_H__

#include "Module.h"

#define MAX_OBJECTS 50

//Type of enemies.h
/*
#include "Enemy_Solider_Green.h"
#include "Enemy_Solider_Red.h"
#include "Enemy_Truck.h"
#include "Enemy_Minor_Turret.h"
#include "Enemy_First_Boss.h"
*/

enum OBJECTS_TYPES
{
	NO_TYPE,
	ENERGY,
	POWER_UP,
	WEAPON,
	SPECIAL
};

class Objects;

struct ObjectsInfo
{
	OBJECTS_TYPES type = OBJECTS_TYPES::NO_TYPE;
	int x, y;
};

class ModuleObjects : public Module
{
public:
	ModuleObjects();
	~ModuleObjects();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

	//bool AddEnemy(ENEMY_TYPES type, int x, int y);

private:

	//void SpawnEnemy(const EnemyInfo& info);

private:

	ObjectsInfo object[MAX_OBJECTS];
	Objects* Items[MAX_OBJECTS];
	SDL_Texture* sprites;
};

#endif