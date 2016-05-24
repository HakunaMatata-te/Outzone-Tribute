#include "BossRightplatform.h"
#include "ModuleTerrainmods.h"
#include "Globals.h"


ModuleTerrainmods::ModuleTerrainmods(){

}

ModuleTerrainmods::~ModuleTerrainmods(){}


bool ModuleTerrainmods::Start(){
	terrainSprite = App->textures->Load("Maps/TerrainMods.png");

	return true;
}

update_status ModuleTerrainmods::PreUpdate(){
	return UPDATE_CONTINUE;
};
update_status ModuleTerrainmods::Update(){
	for (uint i = 0; i < MAX_TERRAIN; ++i)
		if (terrains[i] != nullptr)
			terrains[i]->action();

	for (uint i = 0; i < MAX_TERRAIN; ++i)
		if (terrains[i] != nullptr)
			terrains[i]->Draw(terrainSprite);

	return UPDATE_CONTINUE;
};
update_status ModuleTerrainmods::PostUpdate(){
	return UPDATE_CONTINUE;
};



bool ModuleTerrainmods::CleanUp(){
	return true;
};


void ModuleTerrainmods::AddTerrain(int x, int y, TERRAIN_TYPE type){
	for (uint i = 0; i < MAX_TERRAIN; ++i){
		if (terrains[i] != nullptr){	
			switch (type)
			{
			case TERRAIN_TYPE::BOSS_RPLAT:
				terrains[i] = new BossRPlat(x, y);
				break;

			default:
				break;
			}
			
		}
	}

};