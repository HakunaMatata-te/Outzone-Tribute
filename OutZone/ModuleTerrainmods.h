#ifndef __MODULE_TERRAINMODS_H__
#define __MODULE_TERRAINMODS_H__

#include "Application.h"
#include "Module.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"

#include "Terrainmod.h"

#define MAX_TERRAIN 50

enum TERRAIN_TYPE
{
	NO_TERRAIN_TYPE,
	BOSS_RPLAT

};

class ModuleTerrainmods : public Module
{
public:
	ModuleTerrainmods();
	~ModuleTerrainmods();

	

	bool Start();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();

	void AddTerrain(int x, int y, TERRAIN_TYPE);


private:
	SDL_Texture* terrainSprite;
	Terrainmod* terrains[MAX_TERRAIN];
};

#endif