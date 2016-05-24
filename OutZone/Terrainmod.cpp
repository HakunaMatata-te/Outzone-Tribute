#include "ModuleTerrainmods.h"
#include "Terrainmod.h"


Terrainmod::Terrainmod(int x, int y) : position(x, y){}

Terrainmod::~Terrainmod(){}

void Terrainmod::Draw(SDL_Texture* terrainSprites){
	App->render->Blit(terrainSprites, position.x, position.y, &(animation->GetCurrentFrame()));
}