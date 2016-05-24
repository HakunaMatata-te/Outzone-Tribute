#ifndef __BOSSRIGHTPLATFROM_H__
#define __BOSSRIGHTPLATFROM_H__

#include "Terrainmod.h"
#include "ModuleTerrainmods.h"
#include "ModuleLevel_3.h"

class BossRPlat : public Terrainmod
{
private:

	Animation plat;
	

public:

	BossRPlat(int x, int y);
	~BossRPlat(){};
//	void action();
};

#endif